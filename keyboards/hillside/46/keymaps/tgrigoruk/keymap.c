// https://docs.qmk.fm/keycodes

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum layers {
    _QWERTY = 0,
    _NUM_SYM,
    _NAV,
    _FUNC,
    _MOUSE
};

#define xxxxxxxxxx KC_NO
#define __________ KC_TRNS

// https://docs.qmk.fm/feature_layers#switching-and-toggling-layers
#define LY_NUM MO(_NUM_SYM)
#define LY_NAV MO(_NAV)
#define LY_FN MO(_FUNC)
#define LY_MS MO(_MOUSE)

// https://precondition.github.io/home-row-mods
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


// Media keys
#define KC_MEDIA_NEXT_TRACK NEXT
#define KC_MEDIA_PREV_TRACK PREV
#define KC_BRIGHTNESS_UP BR_UP
#define KC_BRIGHTNESS_DOWN BR_DOWN
// MacOS specific media keys
#define PLY_PAU  KC_MEDIA_PLAY_PAUSE
#define MUTE KC_KB_MUTE
#define KC_KB_VOLUME_UP VOL_UP
#define KC_KB_VOLUME_DOWN VOL_DOWN
#define KC_MISSION_CONTROL MISSION
#define KC_LAUNCHPAD LAUNCH

// Editing shortcuts https://docs.qmk.fm/feature_advanced_keycodes#modifier-keys
#define UNDO LGUI(KC_Z)
#define CUT  LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define REDO LGUI(KC_Y)

// Layer Toggles
#define L1(key) LT(1,key)
#define L2(key) LT(2,key)
#define L3(key) LT(3,key)
#define L4(key) LT(4,key)


// Layout
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GRV,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_EQL,
        KC_LBRC,    HOME_A,     HOME_S,     HOME_D,     HOME_F,     KC_G,                                   KC_H,       HOME_J,     HOME_K,     HOME_L,     HOME_SCLN,  KC_QUOT,
        KC_RBRC,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       xxxxxxxxxx,     xxxxxxxxxx, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_BSLS,
                                            KC_ESC,     L3(CW_TOGG),L2(KC_TAB), L1(KC_ENT),     L1(KC_BSPC),L2(KC_SPC), L3(KC_DEL), KC_INS
    ),
    // https://docs.qmk.fm/keycodes_us_ansi_shifted
    [_NUM_SYM] = LAYOUT(
        xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, KC_LPRN,    KC_RPRN,                                KC_PEQL,    KC_7,       KC_8,       KC_9,       KC_PPLS,    KC_PMNS,
        xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, KC_LBRC,    KC_RBRC,                                KC_PDOT,    KC_4,       KC_5,       KC_6,       KC_PAST,    KC_PSLS,
        xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, KC_LCBR,    KC_RCBR,    xxxxxxxxxx,     xxxxxxxxxx, KC_0,       KC_1,       KC_2,       KC_3,       KC_PERC,    KC_PEQL,
                                            L4(KC_ESC), L3(CW_TOGG),L2(KC_TAB), L1(KC_ENT),     L1(KC_BSPC),L2(KC_SPC), L3(KC_DEL), L4(KC_INS)
    ),
    [_NAV] = LAYOUT(
        xxxxxxxxxx, KC_BTN3,    KC_WH_L,    KC_MS_U,    KC_WH_R,    KC_WH_U,                                KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     xxxxxxxxxx, xxxxxxxxxx,
        xxxxxxxxxx, KC_LCTL,    KC_LALT,    KC_LGUI,    KC_LSFT,    KC_WH_D,                                KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    xxxxxxxxxx, xxxxxxxxxx,
        xxxxxxxxxx, KC_UNDO,    KC_CUT,     KC_COPY,    KC_PSTE,    KC_BTN1,    xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx,
                                            KC_ESC,     L3(CW_TOGG),L2(KC_TAB), L1(KC_ENT),     L1(KC_BSPC),L2(KC_SPC), L3(KC_DEL), KC_INS
        ),
    [_FUNC] = LAYOUT(
        KC_BRIU,    xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, KC_VOLU,                                KC_F12,     KC_F7,      KC_F8,      KC_F9,      KC_F15,     KC_F18,
        KC_BRID,    xxxxxxxxxx, KC_MRWD,    PLY_PAU,    KC_MFFD,    KC_VOLD,                                KC_F11,     KC_F4,      KC_F5,      KC_F6,      KC_F14,     KC_F17,
        REDO,       UNDO,       CUT,        COPY,       PASTE,      KC_MUTE,    xxxxxxxxxx,     xxxxxxxxxx, KC_F10,     KC_F1,      KC_F2,      KC_F3,      KC_F13,     KC_F16,
                                            KC_ESC,     L3(CW_TOGG),L2(KC_TAB), L1(KC_ENT),     L1(KC_BSPC),L2(KC_SPC), L3(KC_DEL), KC_INS
        ),
    // https://docs.qmk.fm/features/mouse_keys
    [_MOUSE] = LAYOUT(
        xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx,                             KC_WH_U,    KC_WH_L,    KC_MS_U,    KC_WH_R,    xxxxxxxxxx, xxxxxxxxxx,
        xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx,                             KC_WH_D,    KC_MS_L,    KC_MS_D,    KC_MS_R,    xxxxxxxxxx, xxxxxxxxxx,
        xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, KC_BTN1,    KC_BTN2,    KC_BTN3,    KC_BTN4,    KC_BTN5,
                                            KC_ESC,     L3(CW_TOGG),L2(KC_TAB), L1(KC_ENT),     L1(KC_BSPC),L2(KC_SPC), L3(KC_DEL), KC_INS
        )
};


const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wer_combo[] = {KC_W, KC_E, KC_R, COMBO_END};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(er_combo, KC_LPRN),
    COMBO(we_combo, KC_LBRC),
    COMBO(wer_combo, KC_LCBR),

    COMBO(ui_combo, KC_RPRN),
    COMBO(io_combo, KC_RBRC),
    COMBO(uio_combo, KC_RCBR),
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_WH_D, KC_WH_U)  },
    [_NUM_SYM] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_DOWN, KC_UP)  },
    [_NAV] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_DOWN, KC_UP)  },
    [_FUNC] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_MOUSE] = { ENCODER_CCW_CW(KC_MS_L, KC_MS_R),  ENCODER_CCW_CW(KC_MS_D, KC_MS_U)  },
};
#endif
