#include "version.h"
#include "menu.h"

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_270;
}

#define L_BASE 0
#define L_NO_MOD (1 << 1)
#define L_NUM (1 << 2)
#define L_SYM (1 << 3)
#define L_FUN (1 << 4)

void oled_render_layer_state(void) {
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case L_NUM:
            oled_write_ln_P(PSTR("NUM"), false);
            break;
        case L_SYM:
            oled_write_ln_P(PSTR("SYM"), false);
            break;
        case L_FUN:
            oled_write_ln_P(PSTR("FUNC"), false);
            break;
    }
}

void oled_render_mods(void) {
    const uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(PSTR("C"), mods & MOD_MASK_CTRL);
    oled_write_P(PSTR("M"), mods & MOD_MASK_ALT);
    oled_write_P(PSTR("S"), mods & MOD_MASK_GUI);
    oled_write_char(0x7F, mods & MOD_MASK_SHIFT);
    oled_write_P(PSTR("\n"), false);
}

void oled_render_version(void) {
    oled_write_ln_P(PSTR(QMK_VERSION), false);
    oled_write_ln_P(PSTR(QMK_USERSPACE_VERSION), false);
}

bool oled_task_user(void) {
    static bool is_menu_open = false;
    if (is_keyboard_master()) {
        if (get_highest_layer(layer_state) == 4) {
            if (!is_menu_open) {
                oled_clear();
                is_menu_open = true;
            }
            menu_render_oled();
        } else {
            if (is_menu_open) {
                oled_clear();
                is_menu_open = false;
            }
            oled_render_layer_state();
            oled_render_mods();
            /* oled_render_version(); */
        }
    }
    return false;
}

#endif // OLED_ENABLE
