void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // First encoder
        if (get_mods() & MOD_MASK_CTRL) {  // If a CTRL is being held
            uint8_t mod_state = get_mods();// Store which mods are held
            del_mods(MOD_MASK_CTRL);       // Ignore all CTRL keys
            if (clockwise) {
                tap_code(KC_PGDN);         // PGDN on clockwise turn
            } else {
                tap_code(KC_PGUP);         // PGUP on counter-clockwise
            }
            set_mods(mod_state);           // Add back CTRL key(s)

        } else {                     // If no CTRL is held
            if (clockwise) {
                tap_code(KC_VOLU);   // VOLUMEUP on clockwise turn
            } else {
                tap_code(KC_VOLD);   // VOLUMEDOWN on counterclockwise
            }
        }
    } else if (index == 1) {  // If you have a second encoder
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}




void encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // not _LOWER and not _ASCII so only QWERTY is active
    if (!IS_LAYER_ON(_LOWER) && !IS_LAYER_ON(_RAISE)) { if (clockwise) { tap_code(KC_VOLU); } else { tap_code(KC_VOLD); } }
    // If _LOWER (only one we really care about here) else if (IS_LAYER_ON(_LOWER)) { if (clockwise) { tap_code(KC_RIGHT); } else { tap_code(KC_LEFT); } } // If _RAISE (only one we really care about here) else if (IS_LAYER_ON(_RAISE)) { if (clockwise) { tap_code(KC_VOLU); } else { tap_code(KC_VOLD); } } } }
