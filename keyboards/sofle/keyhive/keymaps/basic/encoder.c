#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // rhs mod pressed
        if (layer_state_is(2)) {
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        } else {
            if (clockwise) {
                tap_code(KC_RIGHT);
            } else {
                tap_code(KC_LEFT);
            }
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
