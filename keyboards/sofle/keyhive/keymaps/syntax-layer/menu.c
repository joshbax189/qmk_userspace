#include QMK_KEYBOARD_H
#include "menu.h"

// use as a delimiter in menus
// a consequence of nested menu definition
const MenuEntry MENU_END = { NULL, MENU_SUB, { 0 } };

// this is limited to 2 level menus
// note max size is required, no jagged arrays
MenuEntry all_menus[][MENU_MAX_LENGTH] = {
    [_TOP] = {
        { "RGB", MENU_SUB, { .subMenu = _RGB }},
        { "UG", MENU_SUB,  { .subMenu = _UG }},
        { "BOOT", MENU_SUB, { .subMenu = _BOOT }},
        MENU_END,
    },
    [_RGB] = {
        { "SAT+", MENU_KC, { .keycode = RM_SATU } },
        { "SAT-", MENU_KC, { .keycode = RM_SATD } },
        { "NEXT", MENU_KC, { .keycode = RM_NEXT } },
        { "TOGG", MENU_KC, { .keycode = UG_TOGG } },
        MENU_END
    },
    [_UG] = { MENU_END },
    [_BOOT] = { MENU_END }
};

// currently active entry
MenuKeys menu_loc = _TOP;

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
        return menu_loc;
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
    if (menu_idx + 1 < MENU_MAX_LENGTH && (all_menus[menu_loc][menu_idx+1].menuText != NULL)) {
        ++menu_idx;
    }
    return;
}

void menu_left() {
    menu_loc = history_pop();
    return;
}

bool menu_right(keyrecord_t* record) {
    MenuData data = all_menus[menu_loc][menu_idx].menuData;
    MenuType ty = all_menus[menu_loc][menu_idx].menuType;
    switch (ty) {
    case MENU_SUB:
        // push current
        history_push(menu_loc);
        // go to menu in entry
        menu_loc = data.subMenu;
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
    menu_loc = _TOP;
    menu_loc_stack_top = -1;
    return;
}
