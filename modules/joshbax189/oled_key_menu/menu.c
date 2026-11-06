#include "menu.h"

menu_t* current_menu = &top_menu;
/* true if current_menu changed since last oled render */
bool menu_oled_change = true;
uint8_t current_menu_depth = 1;

const menu_entry_t* menu_get_entry(uint8_t index) {
    return &current_menu->entries[index];
}

void menu_up() {
    /* dprintf("up"); */
    if (current_menu->index > 0) {
        --current_menu->index;
    }
    return;
}

void menu_down() {
    /* dprintf("down"); */
    if (menu_get_entry((current_menu->index)+1)->text != NULL) {
        ++current_menu->index;
    }
    return;
}

void menu_back() {
    /* dprintf("left"); */
    if (current_menu->parent != NULL) {
        current_menu = current_menu->parent;
        menu_oled_change = true;
        current_menu_depth--;
    }
    return;
}

void menu_act(keyrecord_t* record) {
    const menu_entry_t* entry = menu_get_entry(current_menu->index);
    menu_data_t data = entry->data;
    switch (entry->action_type) {
    case MENU_SUB:
        menu_t* last = current_menu;
        // go to menu in entry
        current_menu = data.sub_menu;
        current_menu->parent = last;
        menu_oled_change = true;
        current_menu_depth++;
        break;
    case MENU_KC:
        record->keycode = data.keycode;
        process_record_quantum(record);
        break;
    case MENU_FN:
        data.callback();
        break;
    }
    return;
}

/* Back to root */
void menu_reset() {
    current_menu = &top_menu;
    menu_oled_change = true;
    return;
}

#ifdef OLED_ENABLE
void menu_render_oled() {
    // TODO still may be junk after close/open cycle
    if (menu_oled_change) {
        oled_clear();
        menu_oled_change = false;
    }
    uint8_t start = current_menu->index >= MENU_MAX_DISPLAY_LINES ? (current_menu->index - MENU_MAX_DISPLAY_LINES + 1) : 0;
    uint8_t end = start + MENU_MAX_DISPLAY_LINES;

    // header
    if (start != 0) {
        // print some arrows
        for (int j=0; j<3; j++) {
            oled_write_char(0x1E, false);
        }
    } else {
        // print some dots, one per level
        for (int j=0; j<current_menu_depth; j++) {
            oled_write_char(0x07, false);
        }
    }
    oled_write_ln("", false);

    uint8_t i = start;
    const menu_entry_t* e = menu_get_entry(i);
    for (; e->text != NULL && i < end; i++, e = menu_get_entry(i)) {
        oled_write_ln(e->text, i == current_menu->index);
    }

    // footer
    // there is more
    if (i == end && e->text != NULL) {
        // print some arrows
        for (int j=0; j<3; j++) {
            oled_write_char(0x1F, false);
        }
    }

    return;
}
#endif
