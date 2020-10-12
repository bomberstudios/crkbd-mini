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
  MY_OTHER_MACRO
};

#include "keycodes.h"
#include "tap-dance.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  //  -----------------------------------------------------------------------------------------------------------------------------------
  // | Q / CAPS |     W    |     E    |     R    |     T    |          |          |     Y    |     U    |     I    |     O    |     P    |
  //  -----------------------------------------------------------------------------------------------------------------------------------
  // | A / CTRL | S / ALT  | D / CMD  | F / SHIFT|     G    |          |          |     H    | J / SHIFT| K / CMD  | L / ALT  | ; / CTRL |
  //  -----------------------------------------------------------------------------------------------------------------------------------
  // |     Z    |     X    |     C    |     V    |     B    |          |          |     N    |     M    |     ,    |     .    |     /    |
  //  -----------------------------------------------------------------------------------------------------------------------------------
  //                       |  UNICODE |  NUMBER  | BACKSPACE|          |          |SPC / MOVE|  SYMBOL  |  ENTER   |
  //                        ---------------------------------------------------------------------------------------
  [_QWERTY] = LAYOUT_split_3x5_3(
  TD_QCL,KC_W,  KC_E,  KC_R,  KC_T,     KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,
  CTL_A, ALT_S, CMD_D, SHT_F, KC_G,     KC_H,  SHT_J, CMD_K,   ALT_L,  CTL_CLN,
  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,     KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,
                L_UC,  L_NUM, KC_BSPC,  SPC_3, L_SYM, KC_ENT
  ),

  [_COLEMAK] = LAYOUT_split_3x5_3(
    KC_Q,  KC_W,  KC_F,  KC_P,  KC_G,                KC_J,  KC_L, KC_U,    KC_Y,    KC_SCLN,
    CTL_A, ALT_R, CMD_S, SHT_T, KC_D,                KC_H,  SHT_N, CMD_E,   ALT_I,   CTL_O,
    // KC_A,  KC_R,  KC_S,  KC_T,  KC_D,                KC_H,  KC_N, KC_E,    KC_I,    KC_O,
    KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                KC_K,  KC_M, KC_TRNS, KC_TRNS, KC_TRNS,
                  L_UC,  L_NUM, KC_BSPC,      SPC_3, L_SYM, KC_ENT
  ),

  //  -----------------------------------------------------------------------------------------------------------------------------------
  // |    F1    |    F2    |    F3    |    F4    |    F5    |          |          | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS |
  //  -----------------------------------------------------------------------------------------------------------------------------------
  // | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS |          |          | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS |
  //  -----------------------------------------------------------------------------------------------------------------------------------
  // | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS |          |          | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS | KC_TRNS |
  //  -----------------------------------------------------------------------------------------------------------------------------------
  //                       | KC_TRNS | KC_TRNS | KC_TRNS |          |          | KC_TRNS | KC_TRNS | KC_TRNS |
  //                        ---------------------------------------------------------------------------------------
  [_NUMBER] = LAYOUT_split_3x5_3( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 XXXXXXX,  KC_7,  KC_8,  KC_9, KC_VOLU,
    CMD_1,   CMD_2,   CMD_3,   CMD_4,   CMD_5,                 XXXXXXX,  KC_4,  KC_5,  KC_6, KC_MEDIA_PLAY_PAUSE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,  KC_1,  KC_2,  KC_3, KC_VOLD,
                               L_UC,    L_NUM, KC_BSPC, SPC_3, KC_0,     KC_PENT
  ),

  [_SYMBOL] = LAYOUT_split_3x5_3( \
    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    XXXXXXX, XXXXXXX,  KC_GRV, KC_QUOT, KC_COLN,                      KC_BSLS, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,
    XXXXXXX, XXXXXXX, KC_TILD, KC_DQUO, KC_SCLN,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
                                 L_COL, L_NUM, KC_DEL,         SPC_3, L_SYM,  KC_PENT
  ),

  [_MOVE] = LAYOUT_split_3x5_3( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LINEDEL,                    LINEUP,   START,   KC_UP,   END,      ZOOM_IN,
       Ctrl,     Alt,     Cmd,   Shift, LINEDUP,                    LINEDWN,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_MPLY,
       UNDO,     CUT,    COPY,   PASTE, RUNSCRIPT,                  RUNAGAIN, SHT_SCR, SHT_ARE, SHT_OPT,  ZOOM_OUT,
                              L_UC,   L_NUM, KC_BSPC,      SPC_3,   L_SYM, KC_PENT
  ),

  [_UNICODE] = LAYOUT_split_3x5_3( \
    KC_TRNS, KC_TRNS, SPA_E,   KC_TRNS, KC_TRNS,                    KC_TRNS, SPA_U,   SPA_I,   SPA_O,   KC_TRNS,
    SPA_A,   KC_TRNS, KC_TRNS, Shift,   KC_TRNS,                    QMKBEST, Shift,   KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                    SPA_N,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               L_UC,   L_NUM, KC_BSPC,      SPC_3,  L_SYM,   KC_PENT
  )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case CTL_A:
    case SPC_3:
      return TAPPING_TERM + 100;
    // case SHT_J:
    //   return TAPPING_TERM - 50;
    case TD_QCL:
    case KC_Q:
      return TAPPING_TERM + 50;
    // Colemak home row mods need a much higher tapping term
    // while I'm learning, otherwise they won't register
    // Alternatively, I could enable RETRO TAPPING on Colemak?
    case CTL_A:
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

    case MY_OTHER_MACRO:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("ac")); // selects all and copies
        }
        break;
    }
    return true;
};