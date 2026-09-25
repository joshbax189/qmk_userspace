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

#pragma once

// usb always connected to L side
#define MASTER_LEFT

#ifdef RGBLED_ENABLE
// export of sofle/keyhive/keyboard.json
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT { 37, 37 }
#    define RGBLIGHT_HUE_STEP 10
#    undef RGBLIGHT_LED_COUNT
#    define RGBLIGHT_LED_COUNT 74
#    define RGBLIGHT_LED_MAP { 28, 16, 4, 1, 13, 25, 10, 36, 35, 34, 33, 32, 31, 30, 29, 27, 26, 24, 23, 22, 21, 20, 19, 18, 17, 15, 14, 12, 11, 9, 8, 7, 6, 5, 3, 2, 0, 45, 57, 69, 72, 60, 48, 63, 37, 38, 39, 40, 41, 42, 43, 44, 46, 47, 49, 50, 51, 52, 53, 54, 55, 56, 58, 59, 61, 62, 64, 65, 66, 67, 68, 70, 71, 73 }
#    define RGBLIGHT_LIMIT_VAL 100
// this is only used once EEPROM is reset
// if COMMAND is used, press both shifts and backspace
#    define RGBLIGHT_DEFAULT_HUE 128
#    define RGBLIGHT_DEFAULT_VAL 50
#endif

#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL

#ifdef RGB_MATRIX_ENABLE
#    undef RGB_MATRIX_LED_COUNT
#    define RGB_MATRIX_LED_COUNT 74

#    undef RGB_MATRIX_SPLIT
#    define RGB_MATRIX_SPLIT { 37, 37 }
#endif
