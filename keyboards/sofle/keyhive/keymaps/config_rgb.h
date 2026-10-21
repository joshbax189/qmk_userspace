/*
 * Fixes buggy RGB settings from parent keyboard.
 */

#pragma once

// TODO possibly the wrong check? May not enable
#ifdef RGBLIGHT_ENABLE
// export of sofle/keyhive/keyboard.json
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT { 37, 37 }
#    undef RGBLIGHT_LED_COUNT
#    define RGBLIGHT_LED_COUNT 74
// TODO did not check, default seems not too bad, check with snake animation
#    undef RGBLIGHT_LED_MAP
// first 8 are L underglow
// 8-36 are L
// 37-44 are R underglow
// 45-73 are R
/* #    define RGBLIGHT_LED_MAP {\ */
/*     28, 16, 4, 1, 13, 25, 10, 36,\ */
/*     35, 34, 33, 32, 31, 30, 29, 27, 26, 24, 23, 22, 21, 20, 19, 18, 17, 15, 14, 12, 11, 9, 8, 7, 6, 5, 3, 2, 0,\ */
/*     45, 57, 69, 72, 60, 48, 63, 37,\ */
/*     38, 39, 40, 41, 42, 43, 44, 46, 47, 49, 50, 51, 52, 53, 54, 55, 56, 58, 59, 61, 62, 64, 65, 66, 67, 68, 70, 71, 73 } */
#    define RGBLIGHT_LIMIT_VAL 100
#endif

#ifdef RGB_MATRIX_ENABLE
#    undef RGB_MATRIX_LED_COUNT
#    define RGB_MATRIX_LED_COUNT 74

#    undef RGB_MATRIX_SPLIT
#    define RGB_MATRIX_SPLIT { 37, 37 }
#endif
