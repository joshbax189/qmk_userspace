 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H
#include "oled.c"
#include "encoder.c"


void keyboard_post_init_user(void) {
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  |   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | Ent  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  '   | LGUI | LALT | SPC  | / LOWER /       \RAISE \  | BSpc | RCTR | RAlt | DEL  |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[0] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_PIPE,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
               KC_QUOT,KC_LGUI,KC_LALT, KC_SPC, MO(2),            MO(1),  KC_BSPC, KC_RCTL, KC_RALT, KC_DEL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   +  |   -  |   *  |   =  |   _  |                    |   ^  |   &  |   *  |   (  |   )  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   {  |   }  |   (  |   )  |   '  |-------.    ,-------|   !  |   @  |   #  |   $  |   %  |   |  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  [   |  ]   |  <   |   >  |   "  |-------|    |-------|      |      |   ;  |   :  |   \  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      | LAlt | LCTR | SPC  | / LOWER /       \RAISE \  | BSpc | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[1] = LAYOUT(
  _______, KC_F1,      KC_F2,   KC_F3,      KC_F4,     KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_PLUS,    KC_MINS, KC_ASTR,    KC_EQL,    S(KC_MINS),                         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
  _______, S(KC_LBRC), S(KC_RBRC), KC_LPRN, KC_RPRN,   KC_QUOT,                            KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_PIPE,
  _______, KC_LBRC,    KC_RBRC, S(KC_COMM), S(KC_DOT), S(KC_QUOT), _______,       _______, _______, _______, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr | Menu |      | Vol+ |                    | PGUP | Home |  Up  | End  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps | LAt  | LCtl |LShift|      | Vol- |-------.    ,-------| PGDN | Left | Down | Right|  Del |      |
 * |------+------+------+------+------+------|  MUTE  |   |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste| Mute |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR | SPC  | / LOWER /       \RAISE \  | BSpc | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                        _______, _______, _______, _______ , _______, _______,
  _______, KC_INS,   KC_PSCR,  KC_APP,   XXXXXXX,  KC_VOLU,                        KC_PGUP, KC_HOME, KC_UP,   KC_END,   _______, _______,
  KC_CAPS, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX,  KC_VOLD,                        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,  _______,
  _______, KC_UNDO,  KC_CUT,   KC_COPY,  KC_PASTE, KC_MUTE,  _______,       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
)
};
