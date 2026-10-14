#include QMK_KEYBOARD_H
#include "menu.h"

// use as a delimiter in menus
// a consequence of nested menu definition
const MenuEntry MENU_END = { NULL, MENU_SUB, { 0 } };

// this is limited to 2 level menus
// note max size is required, no jagged arrays
MenuEntry all_menus[][MENU_MAX_LENGTH] = {
    [_TOP] = {
        #ifdef RGB_MATRIX_ENABLE
        { "RGB", MENU_SUB, { .subMenu = _RGB }},
        #endif
        #ifdef RGBLIGHT_ENABLE
        { "UG", MENU_SUB,  { .subMenu = _UG }},
        #endif
        { "BOOT", MENU_SUB, { .subMenu = _BOOT }},
        MENU_END,
    },
    #ifdef RGB_MATRIX_ENABLE
    [_RGB] = {
        // TODO only togg works -- but all work for UG?
        { "SAT+", MENU_KC, { .keycode = RM_SATU } },
        { "SAT-", MENU_KC, { .keycode = RM_SATD } },
        { "NEXT", MENU_KC, { .keycode = RM_NEXT } },
        { "PREV", MENU_KC, { .keycode = UG_PREV } },
        { "TOGG", MENU_KC, { .keycode = UG_TOGG } },
        { "HUE+", MENU_KC, { .keycode = RM_HUEU } },
        { "HUE-", MENU_KC, { .keycode = RM_HUED } },
        MENU_END
    },
    #endif
    #ifdef RGBLIGHT_ENABLE
    [_UG] = {
        { "TOGG", MENU_KC, { .keycode = UG_TOGG } },
        { "NEXT", MENU_KC, { .keycode = UG_NEXT } },
        { "PREV", MENU_KC, { .keycode = UG_PREV } },
        { "HUE+", MENU_KC, { .keycode = UG_HUEU } },
        { "HUE-", MENU_KC, { .keycode = UG_HUED } },
        { "SAT+", MENU_KC, { .keycode = UG_SATU } },
        { "SAT-", MENU_KC, { .keycode = UG_SATD } },
        { "VAL+", MENU_KC, { .keycode = UG_VALU } },
        { "VAL-", MENU_KC, { .keycode = UG_VALD } },
        MENU_END
    },
    #endif
    [_BOOT] = {
        { "RESET", MENU_KC, { .keycode = QK_RBT } },
        { "BOOT", MENU_KC, { .keycode = QK_BOOT } }, // TODO doesn't work
        MENU_END
    }
    // TODO magic codes
    // TODO dispatch custom callbacks?
    // e.g. change encoder function
};

MenuKeys current_menu = _TOP;

// stack of historical pointers
// max size = number of menus
MenuKeys menu_loc_stack[ARRAY_SIZE(all_menus)] = {};
uint8_t menu_loc_stack_top = -1; // empty
uint8_t menu_idx = 0;

MenuEntry get_entry(MenuKeys sub, uint8_t idx) {
    return all_menus[sub][idx];
}

bool history_empty() {
    return (menu_loc_stack_top == -1);
}

void history_push(MenuKeys value) {
    menu_loc_stack[++menu_loc_stack_top] = value;
    return;
}

MenuKeys history_pop() {
    if (!history_empty()) {
        return menu_loc_stack[menu_loc_stack_top--];
    } else {
        return current_menu;
    }
}

void menu_up() {
    if (menu_idx > 0) {
        --menu_idx;
    }
    // TODO how to wrap?
    // no wrap: menu_loc = max(menu_start, menu_loc - 1)
    // wrap: menu_loc += (idx - 1) % menu_length
    return;
}

void menu_down() {
    if (menu_idx + 1 < MENU_MAX_LENGTH && (all_menus[current_menu][menu_idx+1].menuText != NULL)) {
        ++menu_idx;
    }
    return;
}

// back
void menu_left() {
    current_menu = history_pop();
    return;
}

// enter/forward/send
bool menu_right(keyrecord_t* record) {
    MenuData data = all_menus[current_menu][menu_idx].menuData;
    MenuType ty = all_menus[current_menu][menu_idx].menuType;
    switch (ty) {
    case MENU_SUB:
        // push current
        history_push(current_menu);
        // go to menu in entry
        current_menu = data.subMenu;
        menu_idx = 0;
        return false;
    case MENU_KC:
        record->keycode = data.keycode;
        process_record_quantum(record);
        return true;
    }
    return false;
}

// go back to start
void menu_reset() {
    current_menu = _TOP;
    menu_loc_stack_top = -1;
    menu_idx = 0;
    return;
}

#ifdef OLED_ENABLE
void oled_print_menu() {
    oled_clear();
    for (int i = 0; i < MENU_MAX_LENGTH; i++) {
        MenuEntry e = get_entry(current_menu, i);
        if (e.menuText != NULL) {
            oled_write_ln(e.menuText, i == menu_idx);
        }
    }
    return;
}
#endif
