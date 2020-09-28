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
  UNICODE
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#include "keycodes.h"
#include "tap-dance.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x5_3( \
  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,     KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,\
  CTL_A, ALT_S, CMD_D, SHT_F, KC_G,     KC_H,  SHT_J, CMD_K,   ALT_L,  CTL_CLN,\
  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,     KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,\
                L_UC,  L_NUM, KC_BSPC,  SPC_3, L_SYM, KC_ENT\
  ),

  [_COLEMAK] = LAYOUT_split_3x5_3( \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                               L_UC,    L_NUM,   KC_BSPC, SPC_3, L_SYM,  KC_ENT \
  ),

  [_NUMBER] = LAYOUT_split_3x5_3( \
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                 XXXXXXX,  KC_7,  KC_8,  KC_9, XXXXXXX,\
    CMD_1,   CMD_2,   CMD_3,   CMD_4,   XXXXXXX,               XXXXXXX,  KC_4,  KC_5,  KC_6, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX,  KC_1,  KC_2,  KC_3, XXXXXXX,\
                               L_UC,    L_NUM, KC_BSPC, SPC_3, KC_0,     KC_ENT \
  ),

  [_SYMBOL] = LAYOUT_split_3x5_3( \
    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,\
    XXXXXXX, XXXXXXX,  KC_GRV, KC_QUOT, KC_COLN,                      KC_BSLS, KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,\
    XXXXXXX, XXXXXXX, KC_TILD, KC_DQUO, KC_SCLN,                      KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,\
                                 L_UC,   L_NUM, KC_BSPC,      SPC_3,   L_SYM,  KC_ENT \
  ),

  [_MOVE] = LAYOUT_split_3x5_3( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LINEDEL,                    LINEUP,   START,   KC_UP,     END, ZOOM_IN,\
       Ctrl,     Alt,     Cmd,   Shift, LINEDUP,                    LINEDWN, KC_LEFT, KC_DOWN,KC_RIGHT,  TD_IOS,\
       Ctrl,     Alt,     Cmd,   Shift,RUNSCRIPT,                   RUNAGAIN, SHT_SCR, SHT_ARE, SHT_OPT,ZOOM_OUT,\
                              L_UC,   L_NUM, KC_BSPC,      SPC_3,   L_SYM, KC_PENT \
  ),

  [_UNICODE] = LAYOUT_split_3x5_3( \
    UCX_AU,  XXXXXXX, UCX_EU,  XXXXXXX, XXXXXXX,                    UCX_NU,  UCX_UU,  UCX_IU,  UCX_OU, XXXXXXX,\
    UCX_A,   XXXXXXX, UCX_E,   XXXXXXX, XXXXXXX,                    UCX_N,   UCX_U,   UCX_I,   UCX_O, XXXXXXX,\
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                               L_UC,   L_NUM, KC_BSPC,      SPC_3,  L_SYM, KC_PENT \
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TD_ESC:
    case CTL_A:
    case SPC_3:
      return TAPPING_TERM + 100;
    case SHT_J:
      return TAPPING_TERM - 100;
    default:
      return TAPPING_TERM;
  }
}
