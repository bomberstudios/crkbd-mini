#define L_COL TG(_COLEMAK)
#define L_NUM LT(_NUMBER,KC_TAB)
#define L_SYM LT(_SYMBOL,KC_ENT)
#define L_MOM MO(_MOVE)
#define L_UC LT(_UNICODE,KC_TAB)

// macOS Shortcuts
#define COPY  LWIN(KC_C)
#define PASTE LWIN(KC_V)
#define CUT LWIN(KC_X)
#define UNDO LWIN(KC_Z)
#define SHT_SCR LWIN(LSFT(KC_3))
#define SHT_ARE LWIN(LSFT(KC_4))
#define SHT_OPT LWIN(LSFT(KC_5))
#define START LWIN(KC_LEFT)
#define END LWIN(KC_RGHT)

// TextMate
#define LINEUP  LWIN(LCTL(KC_UP))
#define LINEDWN LWIN(LCTL(KC_DOWN))
#define LINEDUP LSFT(LCTL(KC_D))
#define LINEDEL LSFT(LCTL(KC_K))

// Sketch
#define SKRUN LSFT(LCTL(KC_K))
#define SKRUNAG  LSFT(LCTL(KC_R))
#define ZOOMIN   LWIN(KC_PLUS)
#define ZOOMOUT  LWIN(KC_MINUS)
#define ZENMODE   LWIN(KC_DOT)


// Nice names
#define Ctrl KC_LCTL
#define Alt KC_LALT
#define Cmd KC_LGUI
#define Shift KC_LSFT

// Mods in home row, using Mod Tap
#define CTL_A MT(MOD_LCTL,KC_A) // CTL_T(KC_A)
#define ALT_S MT(MOD_LALT,KC_S) // ALT_T(KC_S)
#define CMD_D MT(MOD_LGUI,KC_D) // CMD_T(KC_D)
#define SHT_F MT(MOD_LSFT,KC_F)
#define SHT_J MT(MOD_LSFT,KC_J)
#define CMD_K MT(MOD_LGUI,KC_K)
#define ALT_L MT(MOD_LALT,KC_L)
#define CTL_CLN MT(MOD_LCTL,KC_SCLN) // hypothesis: I will never need a semicolon. And when I need it, I can use a layer -> Bad luck!. From the docs: "Unfortunately, these keycodes cannot be used in Mod-Taps or Layer-Taps, since any modifiers specified in the keycode are ignored."

// Home row mods for Colemak
#define ALT_R MT(MOD_LALT,KC_R)
#define CMD_S MT(MOD_LGUI,KC_S)
#define SHT_T MT(MOD_LSFT,KC_T)
#define SHT_N MT(MOD_LSFT,KC_N)
#define CMD_E MT(MOD_LGUI,KC_E)
#define ALT_I MT(MOD_LALT,KC_I)
#define CTL_O MT(MOD_LCTL,KC_O)


#define SPC_1 LT(1,KC_SPC)
#define BSP_1 LT(1,KC_BSPC)
#define SPC_2 LT(2,KC_SPC)
#define BSP_2 LT(2,KC_BSPC)
#define SPC_3 LT(_MOVE,KC_SPC)
#define BSP_3 LT(3,KC_BSPC)
#define SPC_4 LT(4,KC_SPC)
#define BSP_4 LT(4,KC_BSPC)

#define CMD_1 LWIN(KC_1)
#define CMD_2 LWIN(KC_2)
#define CMD_3 LWIN(KC_3)
#define CMD_4 LWIN(KC_4)
#define CMD_5 LWIN(KC_5)

// to be used with Karabiner to launch apps, and other stuff
#define HYPRTAB HYPR_T(KC_TAB)
#define HYPRESC HYPR_T(KC_ESC)

// FN_MO13 - trilayer, layer 1 (3 when held with FN_MO23)
// FN_MO23 - trilayer, layer 2 (3 when held with FN_MO13)

enum unicode_names {
  N_TILDE_LC,
  N_TILDE_UC,
  A_ACUTE_LC,
  A_ACUTE_UC,
  E_ACUTE_LC,
  E_ACUTE_UC,
  I_ACUTE_LC,
  I_ACUTE_UC,
  O_ACUTE_LC,
  O_ACUTE_UC,
  U_ACUTE_LC,
  U_ACUTE_UC,
  U_COLON
};

const uint32_t PROGMEM unicode_map[] = {
  [N_TILDE_LC] = 0xF1,
  [N_TILDE_UC] = 0xD1,
  [A_ACUTE_LC] = 0xE1,
  [A_ACUTE_UC] = 0xC1,
  [E_ACUTE_LC] = 0xE9,
  [E_ACUTE_UC] = 0xC9,
  [I_ACUTE_LC] = 0xED,
  [I_ACUTE_UC] = 0xCD,
  [O_ACUTE_LC] = 0xF3,
  [O_ACUTE_UC] = 0xD3,
  [U_ACUTE_LC] = 0xFA,
  [U_ACUTE_UC] = 0xDA,
  [U_COLON] = 0x3A
};

// Spanish Unicode
#define SPA_N XP(N_TILDE_LC,N_TILDE_UC)
#define SPA_A XP(A_ACUTE_LC,A_ACUTE_UC)
#define SPA_E XP(E_ACUTE_LC,E_ACUTE_UC)
#define SPA_I XP(I_ACUTE_LC,I_ACUTE_UC)
#define SPA_O XP(O_ACUTE_LC,O_ACUTE_UC)
#define SPA_U XP(U_ACUTE_LC,U_ACUTE_UC)

// #define UCX_N UC(0xF1) // ñ
// #define UCX_NU UC(0xD1) // Ñ
//
// #define UCX_A UC(0xE1) // á
// #define UCX_E UC(0xE9) // é
// #define UCX_I UC(0xED) // í
// #define UCX_O UC(0xF3) // ó
// #define UCX_U UC(0xFA) // ú
// #define UCX_AU UC(0xC1) // Á
// #define UCX_EU UC(0xC9) // É
// #define UCX_IU UC(0xCD) // Í
// #define UCX_OU UC(0xD3) // Ó
// #define UCX_UU UC(0xDA) // Ú
