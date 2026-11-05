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
#include "meta_layouts.h"

enum layers {
    _QWERTY_TD,
    _SYM,
    _MVMT,
    _FN
};

// Tap Dance declarations
enum {
    TD_MX,
    TD_CC, //TODO this breaks C-c C-c functions
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_MX] = ACTION_TAP_DANCE_DOUBLE(KC_X, LALT(KC_X)),
    [TD_CC] = ACTION_TAP_DANCE_DOUBLE(KC_C, LCTL(KC_C)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY_TD] = LAYOUT_CRKBD(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    QWERTY_1,                                                                                                    KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    QWERTY_2,                                                                                             LT(_MVMT, KC_ENT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z, TD(TD_MX), TD(TD_CC), KC_V,   KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 OS_LGUI,  KC_LALT, KC_SPC,     KC_BSPC,  MO(_SYM), RALT_T(KC_DEL)
                              //`--------------------------'  `--------------------------'
  ),

  [_MVMT] = LAYOUT_CRKBD(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, NUM_1_5,                                                          _______, _______, KC_PGUP,   KC_UP, KC_HOME, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, NUM_6_0,                                                          _______, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BLANK_6,                                                                   _______, _______, KC_PGDN, _______,  KC_END, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          BLANK_3,                      _______,   MO(_FN), _______
                                      //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_CRKBD(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, SNUM_1_5,                                                        SNUM_6_0,                                      KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BLANK_6,                                                                   MEBRB_SYM_5,                                 KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BLANK_6,                                                                   SMEBRB_SYM_5,                                KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(_FN),   _______,    BLANK_3
                                      //`--------------------------'  `--------------------------'
  ),

  [_FN] = LAYOUT_CRKBD(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, F_1_5,                                                            F_6_0,                                        KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BLANK_6,                                                                   BLANK_5,                                      KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BLANK_6,                                                                   BLANK_6,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          BLANK_3,                      BLANK_3
                                      //`--------------------------'  `--------------------------'
  )
};
// clang-format on
