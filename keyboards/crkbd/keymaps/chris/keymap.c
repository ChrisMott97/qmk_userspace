
#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FUNC,
  BACKLIT
};

enum combos {
  DF_DASH,
  JK_ESC
};

const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // Add commonly used dash to home row
  [DF_DASH]    = COMBO(df_combo, KC_MINS),
  // For Vim, put Escape on the home row
  [JK_ESC]    = COMBO(jk_combo, KC_ESC),
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _FUNC,
};

// For _QWERTY layer
#define LOW_ALT  LT(1,OSM(MOD_LSFT))
#define RSE_ENT  LT(2,CW_TOGG)


// For _RAISE layer
#define CTL_ESC  LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LALT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RCTL, KC_LGUI, MO(1), KC_ENT, KC_SPC, MO(2), OSM(MOD_LSFT)),
	[1] = LAYOUT_split_3x6_3(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_COMM, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PLUS, KC_4, KC_5, KC_6, KC_ASTR, KC_EQL, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_1, KC_2, KC_3, KC_SLSH, KC_DOT, KC_NO, KC_TRNS, KC_TRNS, KC_ENT, MO(3), KC_0),
	[2] = LAYOUT_split_3x6_3(KC_TRNS, KC_GRV, KC_LT, KC_GT, KC_DQUO, KC_DOT, KC_AMPR, KC_UNDS, KC_LBRC, KC_RBRC, KC_PERC, KC_NO, KC_TRNS, KC_EXLM, KC_MINS, KC_PLUS, KC_EQL, KC_HASH, KC_NUBS, KC_SCLN, KC_LPRN, KC_RPRN, KC_QUES, KC_NO, KC_TRNS, KC_CIRC, KC_SLSH, KC_ASTR, KC_NUBS, KC_NO, KC_PIPE, KC_DLR, KC_LCBR, KC_RCBR, KC_AT, KC_NO, KC_NO, MO(3), KC_ESC, KC_TRNS, KC_TRNS, KC_NO),
	[3] = LAYOUT_split_3x6_3(RGB_MOD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_F12, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_RALT)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case LT(_RAISE, KC_BSPC):
            return TAPPING_TERM_THUMB;
      case LT(_LOWER, KC_TAB):
            return TAPPING_TERM_THUMB;
      default:
            return TAPPING_TERM;
    }
}
