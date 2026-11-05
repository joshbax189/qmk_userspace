// Copyright 2025 Dasky (@daskygit)
// SPDX-License-Identifier: GPL-2.0-or-later

// just the default crkbd keymap with rgb keys removed

#include QMK_KEYBOARD_H
#include "../oled.c"
#include "meta_layouts.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_CRKBD(
    KC_TAB,  QWERTY_1, KC_BSPC,
    KC_LCTL, QWERTY_2, KC_QUOT,
    KC_LSFT, QWERTY_3, KC_ESC,
    // L mods
    KC_LGUI, MO(1), KC_SPC,
    // R mods
    KC_ENT, MO(2), KC_RALT
),

  [1] = LAYOUT_CRKBD(
    _______,  NUM_1_5, NUM_6_0,             _______,
    BLANK_6,           _______, VIM_ARROWS, _______,
    BLANK_6,           BLANK_6,
    // L mods
    BLANK_3,
    // R mods
    _______,  MO(3), _______
),

  [2] = LAYOUT_CRKBD(
    _______,  SNUM_1_5, SNUM_6_0,     _______,
    BLANK_6,            MEBRB_SYM_5,  KC_GRV,
    BLANK_6,            SMEBRB_SYM_5, KC_TILD, // same as above shifted
    // L mods
    _______, MO(3), _______,
    // R mods
    BLANK_3
),

  [3] = LAYOUT_CRKBD(
    QK_BOOT, BLANK_5, BLANK_6,
    BLANK_6,          BLANK_6,
    BLANK_6,          BLANK_6,
    // L mods
    BLANK_3,
    // R mods
    BLANK_3
)
};

// clang-format on
