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

// this is only used once EEPROM is reset
// if COMMAND is used, press both shifts and backspace
#define RGBLIGHT_DEFAULT_HUE 128
#define RGBLIGHT_DEFAULT_VAL 50

#undef RGB_MATRIX_LED_COUNT
#define RGB_MATRIX_LED_COUNT 74

#undef RGB_MATRIX_SPLIT
#define RGB_MATRIX_SPLIT { 37, 37 }
