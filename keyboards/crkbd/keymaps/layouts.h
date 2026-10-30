// macros to abbreviate layouts

// downside is this breaks all visualizers
// if you comment out the QMK includes, can use e.g. gcc -E keymap.c -o keymap_exp.c

// default qwerty rows up to semi colon and slash columns
#define QWERTY_1 KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P
#define QWERTY_2 KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN
#define QWERTY_3 KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH

#define NUM_1_5 KC_1, KC_2, KC_3, KC_4, KC_5
#define NUM_6_0 KC_6, KC_7, KC_8, KC_9, KC_0

// shifted num rows
#define SNUM_1_5 KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC
#define SNUM_6_0 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

#define BLANK_3 KC_NO, KC_NO, KC_NO
#define BLANK_5 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define BLANK_6 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO

#define VIM_ARROWS KC_LEFT, KC_DOWN, KC_UP, KC_RGHT

// easy to remember symbol layer from planck and crkbd
// sometimes ends with grave
// Minus Equal (Br)aces Backslash
#define MEBRB_SYM_5 KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS
#define SMEBRB_SYM_5 KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE

#define F_1_5 KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define F_6_0 KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define LAYOUT_CRKBD(...) LAYOUT_split_3x6_3(__VA_ARGS__)
