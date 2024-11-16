// https://docs.qmk.fm/keycodes

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum layers {
    _QWERTY = 0,
    _NUM_SYM_FUN,
    _NAV,
    _MOUSE_MEDIA
};

//----------------------------------------------------------------------
// Tap Dance declarations
enum {
    TD_LSFT_CAPSWORD = 0,
    TD_NUM_NAV_LAYERS,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, twice for Caps Word Toggle
    [TD_LSFT_CAPSWORD] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, CW_TOGG),
    // Tap once for GUI, twice for NAV layer
    [TD_NUM_NAV_LAYERS] = ACTION_TAP_DANCE_DOUBLE(TG(_NUM_SYM_FUN), TG(_NAV)),
};

// Tap Dance Aliases
#define TD_SFT_CW TD(TD_LSFT_CAPSWORD)
#define TD_NUM_NAV TD(TD_NUM_NAV_LAYERS)

//----------------------------------------------------------------------

#define xxxxxxxxxx KC_NO
#define __________ KC_TRNS

#define ALT_L RALT(KC_LEFT)
#define ALT_R RALT(KC_RGHT)

// https://docs.qmk.fm/feature_layers#switching-and-toggling-layers
#define LY_NUM MO(_NUM_SYM_FUN)
#define LY_NAV MO(_NAV)
#define LY_MM MO(_MOUSE_MEDIA)


// Media keys
#define NEXT KC_MEDIA_NEXT_TRACK
#define PREV KC_MEDIA_PREV_TRACK
#define BR_UP KC_BRIGHTNESS_UP
#define BR_DOWN KC_BRIGHTNESS_DOWN
// MacOS specific media keys
#define PLY_PAU  KC_MEDIA_PLAY_PAUSE
#define MUTE KC_KB_MUTE
#define VOL_UP KC_KB_VOLUME_UP
#define VOL_DOWN KC_KB_VOLUME_DOWN
#define MISSION KC_MISSION_CONTROL
#define LAUNCH KC_LAUNCHPAD

// Editing shortcuts https://docs.qmk.fm/feature_advanced_keycodes#modifier-keys
#define UNDO LGUI(KC_Z)
#define CUT  LGUI(KC_X)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define REDO LGUI(KC_Y)

//----------------------------------------------------------------------

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

// Layer Toggles
#define L1(key) LT(_NUM_SYM_FUN,key)
#define L2(key) LT(_NAV,key)
#define L3(key) LT(_MOUSE_MEDIA,key)


//----------------------------------------------------------------------

// Layout
// clang-format off
// https://docs.qmk.fm/keycodes
// https://docs.qmk.fm/keycodes_us_ansi_shifted
// https://docs.qmk.fm/features/mouse_keys
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(

//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        KC_ESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                   KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        TD_SFT_CW,  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       xxxxxxxxxx,     xxxxxxxxxx, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_QUOT,
//     |-----------|-----------|-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|-----------|-----------|
                                            KC_LCTL,    KC_LALT,    KC_LGUI,    TD_NUM_NAV,     LY_NAV,     KC_SPC,     LY_MM,      LY_NUM
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
    ),
    [_NUM_SYM_FUN] = LAYOUT(

//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                  KC_PEQL,    KC_7,       KC_8,       KC_9,       KC_PPLS,    KC_PMNS,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,                                 KC_PDOT,    KC_4,       KC_5,       KC_6,       KC_PAST,    KC_UNDS,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, LAG(KC_1),  LAG(KC_2),  LAG(KC_3),  LAG(KC_4), LAG(KC_5),   xxxxxxxxxx,     xxxxxxxxxx, KC_0,       KC_1,       KC_2,       KC_3,       KC_BSLS,    KC_PIPE,
//     |-----------|-----------|-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|-----------|-----------|
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, KC_SPC,     xxxxxxxxxx, xxxxxxxxxx
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
    ),
    [_NAV] = LAYOUT(

//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, KC_PGDN,    KC_HOME,    KC_UP,      KC_END,     KC_WH_U,                                KC_PGUP,    KC_HOME,    KC_UP,      KC_PGDN,    KC_END,     KC_DEL,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, KC_LALT,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_WH_D,                                KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_RSFT,    KC_INS,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, UNDO,       CUT,        COPY,       PASTE,      xxxxxxxxxx, xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, ALT_L,      xxxxxxxxxx, ALT_R,      xxxxxxxxxx, xxxxxxxxxx,
//     |-----------|-----------|-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|-----------|-----------|
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
        ),
    [_MOUSE_MEDIA] = LAYOUT(

//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        BR_UP,      xxxxxxxxxx, xxxxxxxxxx, MISSION,    xxxxxxxxxx, VOL_UP,                                 KC_WH_U,    KC_WH_L,    KC_MS_U,    KC_WH_R,    xxxxxxxxxx, PLY_PAU,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        BR_DOWN,    REDO,       PREV,       PLY_PAU,    NEXT,       VOL_DOWN,                               KC_WH_D,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_BTN1,    KC_BTN2,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, UNDO,       CUT,        COPY,       PASTE,      MUTE,       xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, KC_BTN3,    KC_BTN4,
//     |-----------|-----------|-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|-----------|-----------|
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
        )
};

// Combo definitions

const uint16_t PROGMEM escq_combo[] = {KC_ESC, KC_Q, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM pbspc_combo[] = {KC_P, KC_BSPC, COMBO_END};
const uint16_t PROGMEM sclnent_combo[] = {KC_SCLN, KC_ENT, COMBO_END};



const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wer_combo[] = {KC_W, KC_E, KC_R, COMBO_END};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(escq_combo, KC_GRV),
    COMBO(hj_combo, KC_PEQL),
    COMBO(pbspc_combo, KC_DEL),
    COMBO(sclnent_combo, KC_INS),

    COMBO(er_combo, KC_LPRN),
    COMBO(we_combo, KC_LBRC),
    COMBO(wer_combo, KC_LCBR),

    COMBO(ui_combo, KC_RPRN),
    COMBO(io_combo, KC_RBRC),
    COMBO(uio_combo, KC_RCBR),

    //COMBO(???, CW_TOGG),
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(LALT(KC_LEFT), LALT(KC_RIGHT)),  ENCODER_CCW_CW(KC_WH_D, KC_WH_U)  },
    [_NUM_SYM_FUN] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_NAV] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),  ENCODER_CCW_CW(KC_DOWN, KC_UP)  },
    [_MOUSE_MEDIA] = { ENCODER_CCW_CW(KC_MS_L, KC_MS_R),  ENCODER_CCW_CW(KC_MS_D, KC_MS_U)  },
};
#endif
