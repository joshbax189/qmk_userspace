// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "encoder.c"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Ent  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  '   | LGUI | LALT |LOWER | / SPC   /       \ BSpc \  |RAISE | RCTR | RAlt | DEL  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_QUOT,KC_LGUI,KC_LALT, MO(1), KC_SPC,            KC_BSPC,  MO(2), KC_RCTL, KC_RALT, KC_DEL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | / SPC   /       \ BSpc \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[1] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
  _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
  _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,       _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      |      |                    | PGUP |      |  Up  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAt  | LCtl |LShift|      | Caps |-------.    ,-------| PGDN | Left | Down | Right|  Del |      |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______, KC_INS,   KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, _______,   KC_UP, _______,_______, _______,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, _______,
  _______, KC_UNDO,  KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, _______, XXXXXXX, _______,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
)
};

// TODO light layers not tested, might need to tweak config.h too
/* // Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore! */
/* const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {0, 4, HSV_CYAN}, */
/*     {36, 2, HSV_CYAN} */
/* ); */
/* // Default to underglow */
/* const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {0, 8, HSV_WHITE}, */
/*     {8, 29, 0, 0, 0}, */
/*     {37, 8, HSV_WHITE}, */
/*     {45, 29, 0, 0, 0} */
/* ); */
/* // Light LEDs 11 & 12 in purple when keyboard layer 2 is active */
/* const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {12, 2, HSV_PURPLE} */
/* ); */
/* // Light LEDs 13 & 14 in green when keyboard layer 3 is active */
/* const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*     {49, 2, HSV_RED} */
/* ); */

/* const rgblight_segment_t PROGMEM lh_top_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*    {13, 2, HSV_BLUE}, */
/*    {23, 2, HSV_BLUE}, */
/*    {32, 2, HSV_BLUE} */
/*    // {32, 5, HSV_BLUE} // outer col */
/* ); */

/* const rgblight_segment_t PROGMEM rh_top_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*    {50, 2, HSV_GREEN}, */
/*    {60, 2, HSV_GREEN}, */
/*    {69, 2, HSV_GREEN} */
/* ); */

/* const rgblight_segment_t PROGMEM both_top_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*    {13, 2, HSV_CYAN}, */
/*    {23, 2, HSV_CYAN}, */
/*    {32, 2, HSV_CYAN}, */
/*    {50, 2, HSV_CYAN}, */
/*    {60, 2, HSV_CYAN}, */
/*    {69, 2, HSV_CYAN} */
/* ); */

/* // Now define the array of layers. Later layers take precedence */
/* const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST( */
/*     my_capslock_layer, */
/*     my_layer1_layer,    // Overrides caps lock layer */
/*     my_layer2_layer,    // Overrides other layers */
/*     my_layer3_layer, */
/*     lh_top_layer, */
/*     rh_top_layer, */
/*     both_top_layer */
/* ); */

/* void keyboard_post_init_user(void) { */
/*     // Enable the LED layers */
/*     rgblight_layers = my_rgb_layers; */
/* } */

/* // enable/disable when changing state */
/* bool led_update_user(led_t led_state) { */
/*     rgblight_set_layer_state(0, led_state.caps_lock); */
/*     return true; */
/* } */

/* layer_state_t default_layer_state_set_user(layer_state_t state) { */
/*     rgblight_set_layer_state(1, layer_state_cmp(state, 0)); */
/*     return state; */
/* } */

/* layer_state_t layer_state_set_user(layer_state_t state) { */
/*     rgblight_set_layer_state(2, layer_state_cmp(state, 1)); */
/*     rgblight_set_layer_state(3, layer_state_cmp(state, 2)); */
/*     return state; */
/* } */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */

/*     case KC_LCTL: */
/*     case KC_RCTL: */
/*         rgblight_set_layer_state(4, record->event.pressed); */
/*         return true; */
/*     case KC_LALT: */
/*     case KC_RALT: */
/*         rgblight_set_layer_state(5, record->event.pressed); */
/*         return true; */
/*     case KC_LGUI: */
/*     case KC_RGUI: */
/*         rgblight_set_layer_state(6, record->event.pressed); */
/*         return true; */

/*     } */
/*     return true; */
/* }; */
