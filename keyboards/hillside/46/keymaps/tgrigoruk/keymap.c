#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)

// Layout
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(   // row 1
                    KC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T,
                    KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL,
                    // row 2
                    KC_LBRC, HOME_A, HOME_S, HOME_D, HOME_F, KC_G,
                    KC_H, HOME_J, HOME_K, HOME_L, HOME_SCLN, KC_QUOT,
                    // row 3
                    KC_RBRC, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO,
                    KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_BSLS,
                    // thumbs
                    KC_ESC, CW_TOGG, LT(1,KC_TAB), LT(3,KC_ENT),
                    KC_BSPC, LT(2,KC_SPC), KC_DEL, KC_INS),
    [1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_PEQL, KC_7, KC_8, KC_9, KC_PPLS, KC_PMNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_PDOT, KC_4, KC_5, KC_6, KC_PAST, KC_PSLS, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_0, KC_1, KC_2, KC_3, KC_PERC, KC_PEQL, KC_NO, KC_NO, KC_TAB, KC_ENT, KC_BSPC, KC_NO, KC_DEL, KC_NO),
    [2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_BTN2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
    [3] = LAYOUT(KC_BRIU, KC_NO, KC_MRWD, KC_MSTP, KC_MFFD, KC_VOLU, KC_F12, KC_F7, KC_F8, KC_F9, KC_F15, KC_F18, KC_BRID, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD, KC_F11, KC_F4, KC_F5, KC_F6, KC_F14, KC_F17, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_F13, KC_F16, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)



