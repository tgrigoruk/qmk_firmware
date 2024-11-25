

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


    [_NAV] = LAYOUT(
        xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx, xxxxxxxxxx,                             REDO,       PASTE,      COPY,       CUT,        UNDO,       xxxxxxxxxx,
        __________, LCTL,       LALT,       LGUI,       LSFT,       xxxxxxxxxx,                             KC_CAPS,    KC_LEFT,    KC_UP,      KC_DOWN,    KC_RGHT,    xxxxxxxxxx,
        __________, LAG(KC_1),  LAG(KC_2),  LAG(KC_3),  LAG(KC_4),  LAG(KC_5),  xxxxxxxxxx,     xxxxxxxxxx, KC_INS,     KC_HOME,    KC_PGUP,    KC_PGDN,    KC_END,     xxxxxxxxxx,
                                            __________, __________, __________, xxxxxxxxxx,     KC_ENT,     KC_SPC,     KC_BSPC,    KC_DEL
        ),
