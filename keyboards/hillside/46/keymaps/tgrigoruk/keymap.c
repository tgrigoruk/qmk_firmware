// https://docs.qmk.fm/keycodes

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

enum layers {
    _QWERTY_A = 0,
    _QWERTY_B,
    _NUM,
    _NAV,
    _MOUSE,
    _NAV_B
};

#define xxxxxxxxxx KC_NO
#define __________ KC_TRNS

// https://docs.qmk.fm/feature_layers#switching-and-toggling-layers
#define LY_NUM MO(_NUM)
#define LY_NAV MO(_NAV)
#define LY_MM MO(_MOUSE)

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

#define ENT_NAV LT(_NAV, KC_ENT)
#define SPC_NAV LT(_NAV, KC_SPC)

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
#define L1(key) LT(_NUM, key)
#define L2(key) LT(_NAV, key)
#define L3(key) LT(_MOUSE, key)
#define L4(key) LT(_NAV_B, key)

// Layout
// clang-format off
// https://docs.qmk.fm/keycodes
// https://docs.qmk.fm/keycodes_us_ansi_shifted
// https://docs.qmk.fm/features/mouse_keys
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY_A] = LAYOUT(
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  `~       |  Q        |  W        |  E        |  R        |  T        |                           |  Y        |  U        |  I        |  O        |  P        | Backspace |
        KC_GRV,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Tab      |  A        |  S        |  D        |  F        |  G        |                           |  H        |  J        |  K        |  L        |  ;        |  Enter    |
        KC_TAB,     KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                                   KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_ENT,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Shift    |  Z        |  X        |  C        |  V        |  B        |                           |  N        |  M        |  ,<       |  .>       |  /?       |  '"       |
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       xxxxxxxxxx,     xxxxxxxxxx, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_QUOT,
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
//                                         |  Control  |  LAlt     |  Command  |  Nav      |   |  Num      |  Space    |  Mouse    |  CapsWord |
                                            KC_LCTL,    KC_LALT,    KC_LGUI,    LY_NAV,         LY_NUM,     SPC_NAV,    LY_MM,      CW_TOGG
    ),
    [_QWERTY_B] = LAYOUT(
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |          |  Q        |  W        |  E        |  R        |  T        |                            |  Y        |  U        |  I        |  O        |  P        |           |
        xxxxxxxxxx, KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                                   KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       xxxxxxxxxx,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |           |  A        |  S        |  D        |  F        |  G        |                           |  H        |  J        |  K        |  L        |  ;        |           |
        xxxxxxxxxx, HOME_A,     HOME_S,     HOME_D,     HOME_F,     KC_G,                                   KC_H,       HOME_J,     HOME_K,     HOME_L,     HOME_SCLN,  xxxxxxxxxx,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |           |  Z        |  X        |  C        |  V        |  B        |                           |  N        |  M        |  ,        |  .        |  /        |           |
        xxxxxxxxxx, KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       xxxxxxxxxx,     xxxxxxxxxx, KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    xxxxxxxxxx,
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
//                                         |  `~       |  Esc      |  Tab      |  Enter    |   |  Num      |  Space    |  Backspc  | Delete    |
                                            KC_GRV,     L3(KC_ESC), L4(KC_TAB), L1(KC_ENT),     LY_NUM,     L4(KC_SPC), L3(KC_BSPC), KC_DEL
    ),
    [_NUM] = LAYOUT(
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  `~       |  F1       |  F2       |  F3       |  F4       |           |                           |  =        |  7        |  8        |  9        |  +        | Backspace |
        __________, KC_F1,      KC_F2,      KC_F3,      KC_F4,      xxxxxxxxxx,                             KC_PEQL,    KC_7,       KC_8,       KC_9,       KC_PPLS,    __________,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Tab      |  F5       |  F6       |  F7       |  F8       |           |                           |  .        |  4        |  5        |  6        |  -_       |  Enter        |
        __________, KC_F5,      KC_F6,      KC_F7,      KC_F8,      xxxxxxxxxx,                             KC_PDOT,    KC_4,       KC_5,       KC_6,       KC_MINS,    __________,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Shift    |  F9       |  F10      |  F11      |  F12      |           |                           |  0        |  1        |  2        |  3        |  \|       |  '"        |
        __________, KC_F9,      KC_F10,     KC_F11,     KC_F12,     xxxxxxxxxx, xxxxxxxxxx,     xxxxxxxxxx, KC_0,       KC_1,       KC_2,       KC_3,       KC_BSLS,    __________,
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, KC_SPC,     xxxxxxxxxx, __________
    ),
    [_NAV] = LAYOUT(
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Esc      |           |  Home     |  ↑        |  End      |  PageUp   |                           |  PageUp   |  Home     |  ↑        |  End      |           |  Delete   |
        KC_ESC,     xxxxxxxxxx, KC_HOME,    KC_UP,      KC_END,     KC_PGUP,                                KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     xxxxxxxxxx, KC_DEL,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Tab      |  Alt      |  ←       |  ↓         |  →        |  PageDn   |                           |  PageDn   |  ←        |  ↓        |  →        |  Shift    |  Insert   |
        __________, KC_LALT,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,                                KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_RSFT,    KC_INS,
//     |-----------|-----------|-----------|-----------|-----------|-----------|                           |-----------|-----------|-----------|-----------|-----------|-----------|
//     |  Shift    |  AltGui 1 |  AltGui 12|  AltGui 3 |  AltGui 4 |  AltGui 5 |                           |           |  Alt ←    |           |  Alt →    |           |           |
        __________, LAG(KC_1),  LAG(KC_2),  LAG(KC_3),  LAG(KC_4),  LAG(KC_5),  xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, ALT_L,      xxxxxxxxxx, ALT_R,      xxxxxxxxxx, xxxxxxxxxx,
//                                         |-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, KC_SPC,     xxxxxxxxxx, __________
        ),
    [_MOUSE] = LAYOUT(
        xxxxxxxxxx, BR_UP,      xxxxxxxxxx, MISSION,    xxxxxxxxxx, VOL_UP,                                 KC_WH_U,    KC_WH_L,    KC_MS_U,    KC_WH_R,    PLY_PAU,    xxxxxxxxxx,
        xxxxxxxxxx, BR_DOWN,    PREV,       PLY_PAU,    NEXT,       VOL_DOWN,                               KC_WH_D,    KC_MS_L,    KC_MS_D,    KC_MS_R,    DF(0),      xxxxxxxxxx,
        __________, UNDO,       CUT,        COPY,       PASTE,      MUTE,       xxxxxxxxxx,     xxxxxxxxxx, xxxxxxxxxx, KC_BTN1,    KC_BTN2,    KC_BTN3,    DF(1),      xxxxxxxxxx,
                                            __________, __________, __________, xxxxxxxxxx,     xxxxxxxxxx, KC_SPC,     xxxxxxxxxx, __________
        ),
    [_NAV_B] = LAYOUT(
        xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx,                             REDO,       PASTE,      COPY,       CUT,        UNDO,       xxxxxxxxxx,
        __________, LCTL,       LALT,       LGUI,       LSFT,       xxxxxxxxxx,                             KC_CAPS,    KC_LEFT,    KC_UP,      KC_DOWN,    KC_RGHT,    xxxxxxxxxx,
        __________, LAG(KC_1),  LAG(KC_2),  LAG(KC_3),  LAG(KC_4),  LAG(KC_5),  xxxxxxxxxx,     xxxxxxxxxx, KC_INS,     KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     xxxxxxxxxx,
                                            __________, __________, __________, xxxxxxxxxx,     KC_ENT,     KC_SPC,     KC_BSPC,    KC_DEL
        ),
};

// Combo definitions

const uint16_t PROGMEM grvq_combo[] = {KC_GRV, KC_Q, COMBO_END};
const uint16_t PROGMEM yh_combo[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};

const uint16_t PROGMEM numnav_combo[] = {MO(_NUM), MO(_NAV), COMBO_END};

const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM wer_combo[] = {KC_W, KC_E, KC_R, COMBO_END};

const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM uio_combo[] = {KC_U, KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(grvq_combo, KC_ESC),
    COMBO(yh_combo, KC_PEQL),
    COMBO(yu_combo, KC_QUOT),
    COMBO(numnav_combo, MO(_MOUSE)),

    COMBO(er_combo, KC_LPRN),
    COMBO(we_combo, KC_LBRC),
    COMBO(wer_combo, KC_LCBR),

    COMBO(ui_combo, KC_RPRN),
    COMBO(io_combo, KC_RBRC),
    COMBO(uio_combo, KC_RCBR),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY_A] = { ENCODER_CCW_CW(LALT(KC_LEFT), LALT(KC_RIGHT)),  ENCODER_CCW_CW(KC_WH_D, KC_WH_U)  },
    [_QWERTY_B] = { ENCODER_CCW_CW(LALT(KC_LEFT), LALT(KC_RIGHT)),  ENCODER_CCW_CW(KC_WH_D, KC_WH_U)  },
    [_NUM] = { ENCODER_CCW_CW(LGUI(KC_LSFT), LGUI(KC_TAB)),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_NAV] = { ENCODER_CCW_CW(LGUI(KC_LSFT), LGUI(KC_TAB)),  ENCODER_CCW_CW(KC_DOWN, KC_UP)  },
    [_MOUSE] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R),  ENCODER_CCW_CW(VOL_DOWN, VOL_UP)  },
};
#endif
