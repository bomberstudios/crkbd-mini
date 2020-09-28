// Tap Dances
#define TD_ESC TD(TD_ESC_CAPS)
#define TD_IOS TD(TD_IOS_MEDIA)

enum tap_dance {
  TD_ESC_CAPS,
  TD_IOS_MEDIA,
};

void ios_media(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_MPLY);
    } else if (state->count == 2) {
        tap_code(KC_MNXT);
    } else if (state->count == 3) {
        tap_code(KC_MPRV);
    } else {
        reset_tap_dance(state);
    }
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // Tap once for Escape, twice for Caps Lock
  [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
  [TD_IOS_MEDIA] = ACTION_TAP_DANCE_FN(ios_media),
};
