#include "menu.h"

#ifdef RGB_MATRIX_ENABLE
// TODO only togg works -- but all work for UG?
MAKE_MENU(rgb_menu,
    { "SAT+", KEY_ACTION(RM_SATU) },
    { "SAT-", KEY_ACTION(RM_SATD) },
    { "NEXT", KEY_ACTION(RM_NEXT) },
    { "PREV", KEY_ACTION(UG_PREV) },
    { "TOGG", KEY_ACTION(UG_TOGG) },
    { "HUE+", KEY_ACTION(RM_HUEU) },
    { "HUE-", KEY_ACTION(RM_HUED) },
);
#endif

#ifdef RGBLIGHT_ENABLE
MAKE_MENU(ug_menu,
    { "TOGG", KEY_ACTION(UG_TOGG) },
    { "NEXT", KEY_ACTION(UG_NEXT) },
    { "PREV", KEY_ACTION(UG_PREV) },
    { "HUE+", KEY_ACTION(UG_HUEU) },
    { "HUE-", KEY_ACTION(UG_HUED) },
    { "SAT+", KEY_ACTION(UG_SATU) },
    { "SAT-", KEY_ACTION(UG_SATD) },
    { "VAL+", KEY_ACTION(UG_VALU) },
    { "VAL-", KEY_ACTION(UG_VALD) },
);
#endif

// TODO QK_BOOT doesn't work
MAKE_MENU(boot_menu,
     { "RESET", KEY_ACTION(QK_RBT) },
     { "BOOT", KEY_ACTION(QK_BOOT) },
);

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

MAKE_MENU(swap_menu,
     { "CL", KEY_ACTION(CL_TOGG) },
     { "EC", KEY_ACTION(EC_TOGG) },
     { "CG", KEY_ACTION(CG_TOGG) },
     // Alt/GUI both sides
     { "AG", KEY_ACTION(AG_TOGG) },
     // \/Bspc
     { "BS", KEY_ACTION(BS_TOGG) },
);

MAKE_MENU(nkro_menu,
     { "ON", KEY_ACTION(NK_ON)},
     { "OFF", KEY_ACTION(NK_OFF) },
     { "TOGG", KEY_ACTION(NK_TOGG) },
);

MAKE_MENU(split_menu,
     { "EH_LEFT", KEY_ACTION(EH_LEFT)},
     { "EH_RGHT", KEY_ACTION(EH_RGHT)},
);

MAKE_MENU(gui_menu,
    { "GU_OFF" , KEY_ACTION(GU_OFF) },
    { "GU_ON"  , KEY_ACTION(GU_ON) },
    { "GU_TOGG", KEY_ACTION(GU_TOGG) },
);

MAKE_MENU(magic_menu,
     { "NKRO", SUB_MENU(nkro_menu) },
     { "SWAP", SUB_MENU(swap_menu) },
     { "GKEYS", SUB_MENU(gui_menu) },
     { "SPLIT", SUB_MENU(split_menu) },
);

TOP_MENU(
#ifdef RGB_MATRIX_ENABLE
    { "RGB", SUB_MENU(rgb_menu) },
#endif
#ifdef RGBLIGHT_ENABLE
    { "UG", SUB_MENU(ug_menu) },
#endif
    { "BOOT", SUB_MENU(boot_menu)},
    { "MAGIC", SUB_MENU(magic_menu) },
);

menu_t* current_menu = &top_menu;

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
    return;
}

#ifdef OLED_ENABLE
void menu_render_oled() {
    oled_clear();
    /* uprintf("menu=%d idx=%d\n", current_menu, current_index); */
    uint8_t i;
    menu_entry_t e;
    for (i = 0, e = menu_get_entry(i); e.text != NULL; i++, e = menu_get_entry(i)) {
        oled_write_ln(e.text, i == current_menu->index);
    }
    return;
}
#endif
