// Copyright 2025 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "version.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("FUNC"), false);
            break;
    }
}

void oled_render_mods(void) {
    const uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(PSTR("C"), mods & MOD_MASK_CTRL);
    oled_write_P(PSTR("M"), mods & MOD_MASK_ALT);
    oled_write_P(PSTR("S"), mods & MOD_MASK_GUI);
    oled_write_char(0x7F, mods & MOD_MASK_SHIFT);
    oled_write_P(PSTR("\n"), false);
}

void oled_render_version(void) {
    oled_write_ln_P(PSTR(QMK_VERSION), false);
    oled_write_ln_P(PSTR(QMK_USERSPACE_VERSION), false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_mods();
        oled_write_ln_P(PSTR(" "), false);
        oled_write_ln_P(PSTR(" "), false);
        oled_render_version();
    }
    return false;
}

#endif // OLED_ENABLE
