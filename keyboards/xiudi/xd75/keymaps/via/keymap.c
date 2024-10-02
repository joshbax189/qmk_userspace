/* Copyright 2017 Wunder
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

enum layer_names {
    _QW,
    _FN,
    _SYN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | DEL    | WIN+Z  | WIN+K  | WIN+C  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+--------|
     * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | '      | WIN+E  | WIN+S  | WIN+O  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------|
     * | LCTL   | A      | S      | D      | F      | G      | H      | J      | K      | L      | ;      | ENTER  | HOME   | INS    | PG UP  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------+--------+--------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | /      | RSHIFT | END    | UP     | PG DN  |
     * |--------+--------+--------+--------+--------+-----------------+--------+-----------------+--------+--------+--------+--------+--------|
     * | LCTRL  | LGUI   |        | LALT   | FN     | SPACE  | BACKSP | SYN    | RALT   | FN     | RGUI   | RCTRL  | LEFT   | DOWN   | RIGHT  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,     KC_0,    KC_DEL,  LGUI(KC_Z), LGUI(KC_K), LGUI(KC_C),
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,     KC_P,    KC_QUOT, LGUI(KC_E), LGUI(KC_S), LGUI(KC_O),
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,     KC_SCLN, KC_ENT,  KC_HOME,    KC_INS,     KC_PGUP,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, KC_END,     KC_UP,      KC_PGDN,
        KC_LCTL, KC_LGUI, KC_NO,   KC_LALT, MO(_FN), KC_SPC,  KC_BSPC, MO(_SYN), KC_RALT, MO(_FN),  KC_RGUI, KC_RCTL, KC_LEFT,    KC_DOWN,    KC_RGHT
    ),

    /* FUNCTION
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     | F10    | F11    |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | RGB TG | STOP   |        |        |        |        |        | PG UP  |        |        | F12    |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | CAPS   | PREV   | NEXT   | VOL+   | VOL-   | MUTE   |        | HOME   | PG DN  | END    |        |        |        | RESET  |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______,
        _______, RGB_TOG, KC_MSTP, _______, _______, _______, _______, _______, KC_PGUP, _______, _______, KC_F12,  _______, _______, _______,
        KC_CAPS, KC_MPRV, KC_MNXT, KC_VOLU, KC_VOLD, KC_MUTE, _______, KC_HOME, KC_PGDN, KC_END,  _______, _______, _______, QK_RBT,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* SYNTAX
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | \      | +      | -      | *      | =      | `      |        |        | UP     |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | {      | }      | (      | )      | '      |        | LEFT   | DOWN   | RIGHT  |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        | [      | ]      | <      | >      | "      |        |        |        |        |        |        |        |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_SYN] = LAYOUT_ortho_5x15( /* SYNTAX */
        _______, _______,    _______,    _______,    _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_BSLS, KC_PLUS,    KC_MINS,    S(KC_8),    KC_EQL,    KC_GRV,     _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______,
        _______, S(KC_LBRC), S(KC_RBRC), S(KC_9),    S(KC_0),   KC_QUOT,    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______,
        _______, KC_LBRC,    KC_RBRC,    S(KC_COMM), S(KC_DOT), S(KC_QUOT), _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,    _______,    _______,    _______,   _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

// 6 leds
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,
    my_layer2_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// enable/disable when changing state
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(2, layer_state_cmp(state, _SYN));
    return state;
}
