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

#define xxxxxxxxxx KC_NO
#define __________ KC_TRNS

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

#define ALT_L RALT(KC_LEFT)
#define ALT_R RALT(KC_RGHT)
#define SPC_NAV LT(_NAV, KC_SPC)

// Layout
// clang-format off
// https://docs.qmk.fm/keycodes
// https://docs.qmk.fm/keycodes_us_ansi_shifted
// https://docs.qmk.fm/features/mouse_keys
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(

//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Esc      |  Q        |  W        |  E        |  R        |  T        |                           |  Y        |  U        |  I        |  O        |  P        |  Bksp     |
        KC_ESC,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Tab      |  A        |  S        |  D        |  F        |  G        |                           |  H        |  J        |  K        |  L        |  ;        |  Enter    |
        KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                   KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  LShift   |  Z        |  X        |  C        |  V        |  B        |                           |  N        |  M        |  ,        |  .        |  /        |  '        |
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       xxxxxxxxxx,     xxxxxxxxxx, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_QUOT,
//     |-----------|-----------|-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|-----------|-----------|
//                                         |  Control  |  LAlt     |  Command  |  Nav      |   |  Num      |  Space    |  Mouse    |  Hyper/CW |
                                            KC_LCTL,    KC_LALT,    KC_LGUI,    LY_NAV,         LY_NUM,     SPC_NAV,    LY_MM,      ALL_T(CW_TOGG)
    ),
    [_NUM_SYM_FUN] = LAYOUT(

//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  `~       |  F1       |  F2       |  F3       |  F4       |  F5       |                           |  =        |  7        |  8        |  9        |  +        |  -        |
        KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                                  KC_PEQL,    KC_7,       KC_8,       KC_9,       KC_PPLS,    KC_PMNS,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Tab      |  F6       |  F7       |  F8       |  F9       |  F10      |                           |  .        |  4        |  5        |  6        |  *        |  _        |
        __________, KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,                                 KC_PDOT,    KC_4,       KC_5,       KC_6,       KC_PAST,    KC_UNDS,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//    |  LShift   |  F11      |  F12      |  F13      |  F14      |  F15      |                           |  0        |  1        |  2        |  3        |  \        |  |        |
        __________, KC_F11,     KC_F12,     KC_F13,     KC_F14,     KC_F15,     xxxxxxxxxx,     xxxxxxxxxx, KC_0,       KC_1,       KC_2,       KC_3,       KC_BSLS,    KC_PIPE,
//     |-----------|-----------|-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|-----------|-----------|
//                                         |  Control  |  LAlt     |  Command  |           |   |           |  Space    |           |  Hyper/CW |
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, KC_SPC,     xxxxxxxxxx, __________
    ),
    [_NAV] = LAYOUT(

//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |           |           |  Home     |  Up       |  4        |  5        |                           |  6        |  7        |  8        |  9        |  0        |  Del      |
        __________, xxxxxxxxxx, KC_HOME,    KC_UP,      KC_END,     KC_WH_U,                                KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     xxxxxxxxxx, KC_DEL,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, KC_LALT,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_WH_D,                                KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_RSFT,    KC_INS,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, UNDO,       CUT,        COPY,       PASTE,      xxxxxxxxxx, xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, ALT_L,      xxxxxxxxxx, ALT_R,      xxxxxxxxxx, xxxxxxxxxx,
//     |-----------|-----------|-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|-----------|-----------|
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, __________
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
        ),
    [_MOUSE_MEDIA] = LAYOUT(

//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        BR_UP,      xxxxxxxxxx, xxxxxxxxxx, MISSION,    xxxxxxxxxx, VOL_UP,                                 KC_WH_U,    KC_WH_L,    KC_MS_U,    KC_WH_R,    KC_ACL0,    PLY_PAU,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        BR_DOWN,    xxxxxxxxxx, PREV,       PLY_PAU,    NEXT,       VOL_DOWN,                               KC_WH_D,    KC_MS_L,    KC_MS_D,    KC_MS_R,    KC_ACL1,    xxxxxxxxxx,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
        __________, UNDO,       CUT,        COPY,       PASTE,      MUTE,       xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, KC_BTN1,    KC_BTN2,    KC_BTN3,    KC_ACL2,    xxxxxxxxxx,
//     |-----------|-----------|-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|-----------|-----------|
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, __________
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
        )
};

// Combo definitions

// const uint16_t PROGMEM escq_combo[] = {KC_ESC, KC_Q, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
// const uint16_t PROGMEM pbspc_combo[] = {KC_P, KC_BSPC, COMBO_END};

const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wer_combo[] = {KC_W, KC_E, KC_R, COMBO_END};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    // COMBO(escq_combo, KC_GRV),
    COMBO(hj_combo, KC_PEQL),
    // COMBO(pbspc_combo, KC_DEL),

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
