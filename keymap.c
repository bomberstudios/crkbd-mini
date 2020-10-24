#include QMK_KEYBOARD_H

extern uint8_t is_master;

#define _QWERTY    0
#define _COLEMAK   1
#define _NUMBER    2
#define _SYMBOL    3
#define _MOVE      4
#define _UNICODE   5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  NUMBER,
  SYMBOL,
  MOVE,
  UNICODE,
  QMKBEST,
  QMKURL,
  M_EMAIL,
};

#include "keycodes.h"

#ifdef TAP_DANCE_ENABLE
#include "tap-dance.h"
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case SHT_J:
    //   return TAPPING_TERM - 50;
    case CTL_A:
    // case TD_QCL:
    // case KC_Q:
    case SPC_3:
      return TAPPING_TERM + 100;
    // Colemak home row mods need a much higher tapping term
    // while I'm learning, otherwise they won't register
    // Alternatively, I could enable RETRO TAPPING on Colemak?
    // case CTL_A:
    case ALT_R:
    case CMD_S:
    case SHT_T:
    case SHT_N:
    case CMD_E:
    case ALT_I:
    case CTL_O:
      return TAPPING_TERM + 800; // Yes, this is quite extreme
    default:
      return TAPPING_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    CTL_A,   ALT_S,   CMD_D,   SHT_F,   KC_G,    KC_H,    SHT_J,   CMD_K,   ALT_L,   CTL_CLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                      _______, L_NUM,   KC_BSPC, SPC_3,   L_SYM,   _______
  ),

  [_COLEMAK] = LAYOUT_split_3x5_3(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
    CTL_A,   ALT_R,   CMD_S,   SHT_T,   KC_D,    KC_H,    SHT_N,   CMD_E,   ALT_I,   CTL_O,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    _______, _______, _______,
                      _______, _______, _______, _______, _______, _______
  ),

  [_NUMBER] = LAYOUT_split_3x5_3( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_7,    KC_8,    KC_9,    KC_VOLU,
    CMD_1,   CMD_2,   CMD_3,   CMD_4,   CMD_5,   _______, KC_4,    KC_5,    KC_6,    KC_MPLY,
    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, KC_1,    KC_2,    KC_3,    KC_VOLD,
                      _______, _______, _______, _______, KC_0,    _______
  ),

  [_SYMBOL] = LAYOUT_split_3x5_3( \
    KC_EXLM,   KC_AT, KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    M_EMAIL, _______, KC_GRV,  KC_QUOT, KC_COLN, KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    _______, _______, KC_TILD, KC_DQUO, KC_SCLN, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
                      _______, _______, KC_DEL,  _______, _______, _______
  ),
  // TODO: Window Switch and Tab Switch using proper code, assigned to a key here
  [_MOVE] = LAYOUT_split_3x5_3( \
    KC_ESC,  _______, _______, _______, LINEDEL, LINEUP,  START,   KC_UP,   END,     ZOOMIN,
    Ctrl,    Alt,     Cmd,     Shift,   LINEDUP, LINEDWN, KC_LEFT, KC_DOWN, KC_RIGHT,KC_MPLY,
    UNDO,    CUT,     COPY,    PASTE,   SKRUN,   SKRUNAG, SHT_SCR, SHT_ARE, SHT_OPT, ZOOMOUT,
                      _______, KC_ESC,  _______, _______, KC_PENT, _______
  ),

  [_UNICODE] = LAYOUT_split_3x5_3( \
    _______, _______, SPA_E,   _______, _______, _______, SPA_U,   SPA_I,   SPA_O,   _______,
    SPA_A,   _______, _______, Shift,   _______, QMKBEST, Shift,   _______, _______, _______,
    _______, _______, _______, _______, _______, SPA_N,   _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QMKBEST:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            // SEND_STRING(SS_LALT("n")"n");
            send_unicode_string("💩💩💩💩💩💩");
        } else {
            // when keycode QMKBEST is released
        }
        break;

    case QMKURL:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("https://qmk.fm/\n");
        } else {
            // when keycode QMKURL is released
        }
        break;

    case M_EMAIL:
        if (record->event.pressed) {
           SEND_STRING("bomberstudios@gmail.com");
        }
        break;
    }
    return true;
};

#ifdef COMBO_ENABLE
// remember to update COMBO_COUNT in config.h
enum combos {
  COMBO_TAB,
  COMBO_ESC,
  COMBO_CAPSLOCK,
};

const uint16_t PROGMEM combo_tab[] =      {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_esc[] =      {KC_Q, CTL_A, COMBO_END}; // we need to merge this PR for this to work: https://github.com/qmk/qmk_firmware/pull/8591/files
const uint16_t PROGMEM combo_capslock[] = {CTL_A, ALT_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc, KC_ESC),
  [COMBO_CAPSLOCK] = COMBO(combo_capslock, KC_CAPS),
};
#endif