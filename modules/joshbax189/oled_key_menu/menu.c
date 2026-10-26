#include "menu.h"

menu_t* current_menu = &top_menu;
/* true if current_menu changed since last oled render */
bool menu_oled_change = true;

menu_entry_t menu_get_entry(uint8_t index) {
    return current_menu->entries[index];
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
    if (menu_get_entry((current_menu->index)+1).text != NULL) {
        ++current_menu->index;
    }
    return;
}

// back
void menu_left() {
    /* dprintf("left"); */
    if (current_menu->parent != NULL) {
        current_menu = current_menu->parent;
        menu_oled_change = true;
    }
    return;
}

// enter/forward/send
// TODO may not need to return bool here
bool menu_right(keyrecord_t* record) {
    /* dprintf("right"); */
    menu_entry_t entry = menu_get_entry(current_menu->index);
    menu_data_t data = entry.data;
    switch (entry.action_type) {
    case MENU_SUB:
        menu_t* last = current_menu;
        // go to menu in entry
        current_menu = data.sub_menu;
        current_menu->parent = last;
        menu_oled_change = true;
        return false;
    case MENU_KC:
        record->keycode = data.keycode;
        process_record_quantum(record);
        return true;
    case MENU_FN:
        data.callback(record);
        return true;
    }
    return false;
}

// go back to start
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
    /* uprintf("menu=%d idx=%d\n", current_menu, current_index); */
    uint8_t i;
    menu_entry_t e;
    for (i = 0, e = menu_get_entry(i); e.text != NULL; i++, e = menu_get_entry(i)) {
        oled_write_ln(e.text, i == current_menu->index);
    }
    return;
}
#endif
