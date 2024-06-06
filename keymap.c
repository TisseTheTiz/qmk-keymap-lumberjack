#include QMK_KEYBOARD_H

#include "./config.h"
#include "features/achordion.h"
#include "features/hrm.h"

/* #define _QWERTY 0 */
/* #define _ASHIFT 1 */
/* #define _RAISE 2 */

enum lumberjack_layers {
    _QWERTY,
    _SYM,
    _NUM,
    _NAV,
    _ADJ,
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    /* COLEMAK, */
    SYM,
    NUM,
    NAV,
    MACRO_PARENTHESES,
    MACRO_BRACKETS,
    MACRO_CURLYBRACES,
    MACRO_SINGLEQUOTES,
    MACRO_DOUBLEQUOTES,
};


// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// MOD-TAP KEYS ├──────────────────────────────────────────────┐

/* #define SFT_ENT LSFT_T(KC_ENT) */
/* #define SFT_SPC RSFT_T(KC_SPC) */
#define SFT_TAB LSFT_T(KC_TAB)
#define SFT_ESC RSFT_T(KC_ESC)
#define SFT_BSP RSFT_T(KC_BSPC)

// LAYER-TAP KEYS ├────────────────────────────────────────────┐

#define NUM_ENT LT(_NUM, KC_ENT)
#define NUM_TAB LT(_NUM, KC_TAB)
#define NAV_TAB LT(_NAV, KC_TAB)
#define SYM_SPC LT(_SYM, KC_SPC)
#define NAV_ESC LT(_NAV, KC_ESC)
#define NAV_BSP LT(_NAV, KC_BSPC)

// TAP-DANCE KEYS ├────────────────────────────────────────────┐
/* #define TD_AESC TD(A_ESC) */

// German characters - assuming 'setxkbmap de us' is set in linux
#define KC_EURO RALT(KC_E)
#define KC_AE RALT(KC_A)
#define KC_OE RALT(KC_O)
#define KC_UE RALT(KC_U)
#define KC_SZ RALT(KC_S)

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   c o m b o s                                 │
// └───────────────────────────────────────────────────────────┘
// MODS
const uint16_t PROGMEM esc_combo[] = {F_HRM, J_HRM, COMBO_END};
const uint16_t PROGMEM capslock_combo[] = {KC_Q, KC_P, COMBO_END};

// SYMBOLS
const uint16_t PROGMEM lparenthesis_combo[] = {J_HRM, K_HRM, COMBO_END};
const uint16_t PROGMEM rparenthesis_combo[] = {K_HRM, L_HRM, COMBO_END};
const uint16_t PROGMEM parentheses_combo[] = {J_HRM, L_HRM, COMBO_END};
const uint16_t PROGMEM lbracket_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM rbracket_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM brackets_combo[] = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM lcurlybrace_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM rcurlybrace_combo[] = {KC_COMMA, KC_DOT, COMBO_END};
const uint16_t PROGMEM curlybraces_combo[] = {KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM onesinglequote_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM grave_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM singlequotes_combo[] = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM onedoublequote_combo[] = {S_HRM, D_HRM, COMBO_END};
const uint16_t PROGMEM doublequotes_combo[] = {S_HRM, F_HRM, COMBO_END};
const uint16_t PROGMEM tilde_combo[] = {D_HRM, F_HRM, COMBO_END};

combo_t key_combos[] = {
    // MODS
    COMBO(esc_combo, KC_ESC),
    COMBO(capslock_combo, KC_CAPS),

    // SYMBOLS
    COMBO(lparenthesis_combo, KC_LEFT_PAREN),
    COMBO(rparenthesis_combo, KC_RIGHT_PAREN),
    COMBO(parentheses_combo, MACRO_PARENTHESES),
    COMBO(lbracket_combo, KC_LEFT_BRACKET),
    COMBO(rbracket_combo, KC_RIGHT_BRACKET),
    COMBO(brackets_combo, MACRO_BRACKETS),
    COMBO(lcurlybrace_combo, KC_LEFT_CURLY_BRACE),
    COMBO(rcurlybrace_combo, KC_RIGHT_CURLY_BRACE),
    COMBO(curlybraces_combo, MACRO_CURLYBRACES),
    COMBO(onesinglequote_combo, KC_QUOTE),
    COMBO(grave_combo, KC_GRAVE),
    COMBO(singlequotes_combo, MACRO_SINGLEQUOTES),
    COMBO(onedoublequote_combo, KC_DOUBLE_QUOTE),
    COMBO(doublequotes_combo, MACRO_DOUBLEQUOTES),
    COMBO(tilde_combo, KC_TILDE),
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y   o v e r r i d e s                   │
// └───────────────────────────────────────────────────────────┘

const key_override_t backspace_override = ko_make_basic(MOD_MASK_SHIFT, SYM_SPC, KC_BSPC);
const key_override_t delete_override = ko_make_basic(MOD_MASK_SHIFT, SFT_BSP, KC_DEL);
const key_override_t flipcolon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SEMICOLON);

// This globally defines all key overrides to be used ├────────┐
const key_override_t **key_overrides = (const key_override_t *[]){
  &backspace_override,
  &delete_override,
  &flipcolon_override,
  NULL // Null terminate the array of overrides!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_5x12(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    KC_Q   ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,   XXXXXXX,   XXXXXXX,   KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   ,   KC_P   ,
    A_HRM  ,   S_HRM  ,   D_HRM  ,   F_HRM  ,   KC_G   ,   XXXXXXX,   XXXXXXX,   KC_H   ,   J_HRM  ,   K_HRM  ,   L_HRM  ,   COLON_HRM,
    KC_Z   ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,   XXXXXXX,   XXXXXXX,   KC_N   ,   KC_M   ,   KC_COMM,   KC_DOT ,   KC_SLSH,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   TT(_NAV),  SFT_TAB,   NUM_ENT,   SYM_SPC,   SFT_BSP,   NAV_ESC,   XXXXXXX,   XXXXXXX,   XXXXXXX
),
[_SYM] = LAYOUT_ortho_5x12(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    KC_TILD,   _______,   _______,   _______,   _______,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,
    KC_EXLM,   KC_AT  ,   KC_HASH,   KC_DLR ,   KC_PERC,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,
    _______,   _______,   KC_PIPE,   KC_AMPR,   _______,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX
),
[_NUM] = LAYOUT_ortho_5x12(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    KC_F1  ,   KC_F2  ,   KC_F3  ,   KC_F4  ,   KC_F5  ,   XXXXXXX,   XXXXXXX,   KC_PLUS,   KC_7   ,   KC_8   ,   KC_9   ,   KC_CIRC,
    KC_F6  ,   KC_F7  ,   KC_F7  ,   KC_F9  ,   KC_F10 ,   XXXXXXX,   XXXXXXX,   KC_EQL ,   KC_4   ,   KC_5   ,   KC_6   ,   KC_MINS,
    _______,   _______,   _______,   KC_F11 ,   KC_F12 ,   XXXXXXX,   XXXXXXX,   KC_ASTR,   KC_1   ,   KC_2   ,   KC_3   ,   KC_UNDS,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   KC_0   ,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX
),
[_NAV] = LAYOUT_ortho_5x12(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    _______,   _______,   KC_EURO,   _______,   _______,   XXXXXXX,   XXXXXXX,   _______,   KC_UE  ,   _______,   KC_OE  ,   _______,
    KC_AE  ,   KC_SZ  ,   _______,   _______,   _______,   XXXXXXX,   XXXXXXX,   KC_LEFT,   KC_DOWN,   KC_UP  ,   KC_RGHT,   _______,
    _______,   _______,   _______,   _______,   _______,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX
),
[_ADJ] = LAYOUT_ortho_5x12(
    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
    QK_RBT ,   _______,   _______,   DT_UP  ,   _______,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,
    QK_BOOT,   _______,   _______,   DT_PRNT,   _______,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,
    QK_MAKE,   _______,   _______,   DT_DOWN,   _______,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,   _______,   _______,   _______,   _______,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX
)

};

void keyboard_pre_init_user() {
    writePin(LED1, true);
    writePin(LED2, true);
}

void keyboard_post_init_user() {
    writePin(LED1, false);
    writePin(LED2, false);
}

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
	  default:
	    return true;
  }
  return true;
}

void matrix_scan_user(void) {
    achordion_task();
  }
