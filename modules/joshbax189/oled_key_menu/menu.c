/* #define MENU_TEST */

#ifdef MENU_TEST
#include <stdint.h>
#include <stddef.h>

typedef struct { uint16_t keycode; } keyrecord_t;

enum keycodes { QK_RBT, QK_BOOT, UG_TOGG, UG_NEXT, UG_PREV, CL_TOGG, EC_TOGG, CG_TOGG, AG_TOGG, BS_TOGG, NK_ON, NK_OFF, NK_TOGG, EH_LEFT, EH_RGHT, GU_OFF, GU_ON, GU_TOGG };

void process_record_quantum(keyrecord_t* x) {
    return;
}

#else
#include QMK_KEYBOARD_H
#include "print.h"
#endif

#include "menu.h"

// use as a delimiter in menus -- avoid storing menu size
const MenuEntry MENU_END = { NULL, MENU_SUB, { 0 } };

MenuEntry top_menu[] = {
#ifdef RGB_MATRIX_ENABLE
    { "RGB", MENU_SUB, { .subMenu = _RGB }},
#endif
#ifdef RGBLIGHT_ENABLE
    { "UG", MENU_SUB,  { .subMenu = _UG }},
#endif
    { "BOOT", MENU_SUB, { .subMenu = _BOOT }},
    { "MAGIC", MENU_SUB, { .subMenu = _MAGIC }},
    MENU_END,
};

#ifdef RGB_MATRIX_ENABLE
MenuEntry rgb_menu[] = {
    // TODO only togg works -- but all work for UG?
    { "SAT+", MENU_KC, { .keycode = RM_SATU } },
    { "SAT-", MENU_KC, { .keycode = RM_SATD } },
    { "NEXT", MENU_KC, { .keycode = RM_NEXT } },
    { "PREV", MENU_KC, { .keycode = UG_PREV } },
    { "TOGG", MENU_KC, { .keycode = UG_TOGG } },
    { "HUE+", MENU_KC, { .keycode = RM_HUEU } },
    { "HUE-", MENU_KC, { .keycode = RM_HUED } },
    MENU_END
};
#endif

#ifdef RGBLIGHT_ENABLE
MenuEntry ug_menu[] = {
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
};
#endif

MenuEntry boot_menu[] = {
    { "RESET", MENU_KC, { .keycode = QK_RBT } },
    { "BOOT", MENU_KC, { .keycode = QK_BOOT } }, // TODO doesn't work
    MENU_END
};

// TODO other magic codes
/* { "CL_SWAP", MENU_KC, { .keycode = CL_SWAP } }, */
/* { "CL_NORM", MENU_KC, { .keycode = CL_NORM } }, */
/* { "CL_CTRL", MENU_KC, { .keycode = CL_CTRL } }, */
/* { "CL_CAPS", MENU_KC, { .keycode = CL_CAPS } }, */
/* { "EC_SWAP", MENU_KC, { .keycode = EC_SWAP } }, */
/* { "EC_NORM", MENU_KC, { .keycode = EC_NORM } }, */
/* { "CG_LSWP", MENU_KC, { .keycode = CG_LSWP } }, */
/* { "CG_LNRM", MENU_KC, { .keycode = CG_LNRM } }, */
/* { "CG_RSWP", MENU_KC, { .keycode = CG_RSWP } }, */
/* { "CG_RNRM", MENU_KC, { .keycode = CG_RNRM } }, */
/* { "CG_SWAP", MENU_KC, { .keycode = CG_SWAP } }, */
/* { "CG_NORM", MENU_KC, { .keycode = CG_NORM } }, */
/* { "AG_LSWP", MENU_KC, { .keycode = AG_LSWP } }, */
/* { "AG_LNRM", MENU_KC, { .keycode = AG_LNRM } }, */
/* { "AG_RSWP", MENU_KC, { .keycode = AG_RSWP } }, */
/* { "AG_RNRM", MENU_KC, { .keycode = AG_RNRM } }, */
/* { "AG_SWAP", MENU_KC, { .keycode = AG_SWAP } }, */
/* { "AG_NORM", MENU_KC, { .keycode = AG_NORM } }, */
/* { "GE_SWAP", MENU_KC, { .keycode = GE_SWAP } }, */
/* { "GE_NORM", MENU_KC, { .keycode = GE_NORM } }, */
/* { "BS_SWAP", MENU_KC, { .keycode = BS_SWAP } }, */
/* { "BS_NORM", MENU_KC, { .keycode = BS_NORM } }, */

MenuEntry magic_menu[] = {
    { "NKRO", MENU_SUB, { .subMenu = _NKRO }},
    { "SWAP", MENU_SUB, { .subMenu = _SWAP }},
    { "GKEYS", MENU_SUB, { .subMenu = _GUI }},
    { "SPLIT", MENU_SUB, { .subMenu = _SPLIT }},
    MENU_END
};

MenuEntry swap_menu[] = {
    // Caps/LCtrl
    { "CL", MENU_KC, { .keycode = CL_TOGG } },
    // Esc/Caps
    { "EC", MENU_KC, { .keycode = EC_TOGG } },
    // Ctrl/GUI both sides
    { "CG", MENU_KC, { .keycode = CG_TOGG } },
    // Alt/GUI both sides
    { "AG", MENU_KC, { .keycode = AG_TOGG } },
    // \/Bspc
    { "BS", MENU_KC, { .keycode = BS_TOGG } },
    MENU_END
};

MenuEntry nkro_menu[] = {
    { "ON"  , MENU_KC, { .keycode = NK_ON } },
    { "OFF" , MENU_KC, { .keycode = NK_OFF } },
    { "TOGG", MENU_KC, { .keycode = NK_TOGG } },
    MENU_END
};

MenuEntry split_menu[] = {
    { "EH_LEFT", MENU_KC, { .keycode = EH_LEFT } },
    { "EH_RGHT", MENU_KC, { .keycode = EH_RGHT } },
    MENU_END
};

MenuEntry gui_menu[] = {
    { "GU_OFF" , MENU_KC, { .keycode = GU_OFF } },
    { "GU_ON"  , MENU_KC, { .keycode = GU_ON } },
    { "GU_TOGG", MENU_KC, { .keycode = GU_TOGG } },
    MENU_END
};

/* indexes available menus using MenuKey */
MenuEntry* all_menus[] = {
    [_TOP] = top_menu,
    #ifdef RGB_MATRIX_ENABLE
    [_RGB] = rgb_menu,
    #endif
    #ifdef RGBLIGHT_ENABLE
    [_UG] = ug_menu,
    #endif
    [_BOOT] = boot_menu,
    [_MAGIC] = magic_menu,
    [_SWAP] = swap_menu,
    [_NKRO] = nkro_menu,
    [_SPLIT] = split_menu,
    [_GUI] = gui_menu,
};

MenuEntry get_entry(MenuKeys sub, uint8_t idx) {
    return all_menus[sub][idx];
}

MenuKeys current_menu = _TOP;
uint8_t current_index = 0;

/* Last active index for each sub menu */
uint8_t last_index[ARRAY_SIZE(all_menus)] = { 0 };
/* Sequence of sub menus between current and _TOP, as a stack */
MenuKeys menu_stack[ARRAY_SIZE(all_menus)] = {};
int8_t menu_stack_top = -1; // empty

static bool history_empty(void);
static bool history_empty() {
    return (menu_stack_top == -1);
}

static void history_push(MenuKeys value);
static void history_push(MenuKeys value) {
    menu_stack[++menu_stack_top] = value;
    return;
}

static MenuKeys history_pop(void);
static MenuKeys history_pop() {
    if (!history_empty()) {
        return menu_stack[menu_stack_top--];
    } else {
        return current_menu;
    }
}

void menu_up() {
    if (current_index > 0) {
        --current_index;
    }
    return;
}

void menu_down() {
    if (all_menus[current_menu][current_index+1].menuText != NULL) {
        ++current_index;
    }
    return;
}

// back
void menu_left() {
    // save old index
    last_index[current_menu] = current_index;
    // restore menu and index
    current_menu = history_pop();
    current_index = last_index[current_menu];
    return;
}

// enter/forward/send
bool menu_right(keyrecord_t* record) {
    MenuData data = all_menus[current_menu][current_index].menuData;
    MenuType ty = all_menus[current_menu][current_index].menuType;
    switch (ty) {
    case MENU_SUB:
        history_push(current_menu);
        last_index[current_menu] = current_index;
        // go to menu in entry
        current_menu = data.subMenu;
        current_index = last_index[current_menu];
        return false;
    case MENU_KC:
        record->keycode = data.keycode;
        process_record_quantum(record);
        return true;
    case MENU_FN:
        data.menuFn(record);
        return true;
    }
    return false;
}

// go back to start
void menu_reset() {
    current_menu = _TOP;
    current_index = 0;
    menu_stack_top = -1;
    return;
}

#ifdef OLED_ENABLE
void oled_print_menu() {
    oled_clear();
    uprintf("menu=%d idx=%d", current_menu, current_index);
    uint8_t i;
    MenuEntry e;
    for (i = 0, e = get_entry(current_menu, i); e.menuText != NULL; i++) {
        oled_write_ln(e.menuText, i == current_index);
    }
    return;
}
#endif
