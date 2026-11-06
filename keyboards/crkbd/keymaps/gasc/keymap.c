/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "../oled.c"

// home row GASC
// TODO could use enum keycode_aliases
#define HR_A KC_A
#define HR_S LT(SYM, KC_S)
#define HR_D LALT_T(KC_D)
#define HR_F LCTL_T(KC_F)

#define HR_J RCTL_T(KC_J)
#define HR_K RALT_T(KC_K)
#define HR_L LT(SYM, KC_L)
#define HR_SC KC_SCLN

// super
// 1-5 impossible move to fun layer?
// zxc ok
// shft q sort of tricky
// ekj ok
// hl ok

// Mx ok
// ae fb np

// Cx, Cc,
// CMx, CMs

enum layers {
    BASE,
    NUM,
    SYM,
    FUN,
};

const uint16_t PROGMEM combo_dot_comma[] = {KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_dot_comma, KC_QUOT),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    HR_A,    HR_S,    HR_D,    HR_F,    KC_G,                        KC_H,    HR_J,    HR_K,    HR_L,   HR_SC,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+-------|  |--------+--------+--------+--------+--------+--------+--------|
                                 OS_LGUI,  KC_LALT, KC_SPC,     KC_BSPC, MO(NUM), RALT_T(KC_DEL)
                              //`--------------------------'  `--------------------------'
  ),

  [NUM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      _______, KC_PGUP,   KC_UP, KC_HOME, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, DB_TOGG,                      _______, KC_PGDN, _______,  KC_END, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(FUN), QK_LLCK,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  // ShelZuuz
  [SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,  KC_GRV, KC_TILD, KC_HASH, KC_AMPR, KC_PIPE,                      KC_CIRC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_EXLM, KC_UNDS, KC_COLN,  KC_EQL,  KC_DLR,                        KC_AT, KC_LPRN, KC_RPRN, KC_UNDS, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PERC, KC_QUES, KC_ASTR, KC_PLUS, KC_BSLS,                      KC_SLSH, KC_MINS,   KC_LT,   KC_GT, KC_QUOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(FUN), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

  [FUN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
};
// clang-format on
