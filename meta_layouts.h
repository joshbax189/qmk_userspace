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

#define BLANK_3 KC_TRNS, KC_TRNS, KC_TRNS
#define BLANK_5 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define BLANK_6 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS

#define VIM_ARROWS KC_LEFT, KC_DOWN, KC_UP, KC_RGHT

// easy to remember symbol layer from planck and crkbd
// sometimes ends with grave
// Minus Equal (Br)aces Backslash
#define MEBRB_SYM_5 KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS
#define SMEBRB_SYM_5 KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE

#define F_1_5 KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define F_6_0 KC_F6, KC_F7, KC_F8, KC_F9, KC_F10

#define LAYOUT_XD75_split_blank_3_raw(\
    k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12,\
    k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24,\
    k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36,\
    k37, k38, k39, k40, k41, k42, k43, k44, k45, k46, k47, k48,\
    k49, k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k60\
) LAYOUT_ortho_5x15(\
    k01, k02, k03, k04, k05, k06, _______, _______, _______, k07, k08, k09, k10, k11, k12,\
    k13, k14, k15, k16, k17, k18, _______, _______, _______, k19, k20, k21, k22, k23, k24,\
    k25, k26, k27, k28, k29, k30, _______, _______, _______, k31, k32, k33, k34, k35, k36,\
    k37, k38, k39, k40, k41, k42, _______, _______, _______, k43, k44, k45, k46, k47, k48,\
    k49, k50, k51, k52, k53, k54, _______, _______, _______, k55, k56, k57, k58, k59, k60\
)
#define LAYOUT_XD75_split_blank_3(...) LAYOUT_XD75_split_blank_3_raw(__VA_ARGS__)

#define LAYOUT_CRKBD(...) LAYOUT_split_3x6_3(__VA_ARGS__)
