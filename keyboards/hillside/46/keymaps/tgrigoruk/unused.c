

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
#define L1(key) LT(_NUM_SYM_FUN, key)
#define L2(key) LT(_NAV, key)
#define L3(key) LT(_MOUSE_MEDIA, key)

// Tap Dance declarations, definitions, and aliases
enum {
    TD_LSFT_CAPSWORD = 0,
    TD_NUM_NAV_LAYERS,
};


tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Shift, twice for Caps Word Toggle
    [TD_LSFT_CAPSWORD] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, CW_TOGG),
    // Tap once for GUI, twice for NAV layer
    // NOT WORKING
    [TD_NUM_NAV_LAYERS] = ACTION_TAP_DANCE_DOUBLE(TG(_NUM_SYM_FUN), TG(_NAV)),
};

#define TD_SFT_CW TD(TD_LSFT_CAPSWORD)
#define TD_NUM_NAV TD(TD_NUM_NAV_LAYERS)
