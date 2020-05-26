#include QMK_KEYBOARD_H

extern rgblight_config_t rgblight_config;
extern keymap_config_t keymap_config;

// Key aliases for legibility
#define _______ KC_TRNS
#define ___x___ KC_NO

// Default layer
#define _BASE 0
// Lower layer
#define _LOWER 1
// Raise layer
#define _RAISE 2
// Utility layer
#define _UTIL 3
// Gaming layer
#define _GAME 4
// Gaming extra
#define _GAMEX 5

enum custom_keycodes {
  PSTORM_COL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PSTORM_COL:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_INSERT))));
      }
      break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_5x15( \
    KC_ESC,  KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY,    KC_MPRV, KC_MNXT, ___x___,    ___x___, ___x___, KC_PSCREEN, KC_DEL,  DF(_GAME), ___x___, RGB_TOG, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,     KC_U,       KC_I,    KC_O,    KC_P,       KC_BSPC, ___x___,   ___x___, ___x___, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,       KC_G,   KC_H,     KC_J,       KC_K,    KC_L,    KC_SCLN,    KC_ENT,  ___x___,   ___x___, ___x___, \
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,   KC_N,     KC_M,       KC_COMM, KC_DOT,  KC_SLSH,    KC_RSPC, ___x___,   ___x___, ___x___, \
    KC_LCTL, KC_LGUI, KC_GRV,  KC_LALT, MO(_LOWER), KC_SPC, KC_SPC,   MO(_RAISE), KC_RALT, KC_QUOT, KC_BSLS,    KC_RCTL, PSTORM_COL,   ___x___, ___x___),
  [_RAISE] = LAYOUT_ortho_5x15( \
    ___x___, ___x___, ___x___, ___x___, ___x___,   ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
    KC_TILD, ___x___, ___x___, ___x___, ___x___,   ___x___, ___x___, KC_INSERT, KC_HOME, KC_PGUP, ___x___, _______, ___x___, ___x___, ___x___, \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, ___x___, ___x___, ___x___, \
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,    KC_F11,  KC_F12,  KC_DELETE, KC_END,  KC_PGDN, ___x___, _______, ___x___, ___x___, ___x___, \
    _______, ___x___, ___x___, _______, MO(_UTIL), _______, _______, _______, _______, _______, _______, _______, ___x___, ___x___, ___x___),
  [_LOWER] = LAYOUT_ortho_5x15( \
    ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, ___x___, ___x___, ___x___, \
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, ___x___, ___x___, ___x___, \
    _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, ___x___, ___x___, KC_MINS,  KC_UNDS, KC_EQL, KC_PLUS, _______, ___x___, ___x___, ___x___, \
    _______, ___x___, ___x___, _______, _______, _______, _______, _______, _______, ___x___, ___x___, _______,  ___x___, ___x___, ___x___),
  [_UTIL] = LAYOUT_ortho_5x15( \
    RESET,   ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
    RGB_HUD, RGB_TOG, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, RGB_HUI, ___x___, ___x___, ___x___, \
    RGB_SAD, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, RGB_SAI, ___x___, ___x___, ___x___, \
    RGB_VAD, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, RGB_VAI, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, _______, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___),
  [_GAME] = LAYOUT_ortho_5x15( \
    KC_ESC,  KC_1,    KC_2,   KC_3,          KC_4,    KC_5,   KC_6,   KC_7,    KC_8,       KC_9,    KC_0,    KC_DEL,  DF(_BASE), ___x___, ___x___, \
    KC_TAB,  KC_Q,    KC_W,   KC_E,          KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,       KC_O,    KC_P,    KC_BSPC, ___x___,   ___x___, ___x___, \
    KC_CAPS, KC_A,    KC_S,   KC_D,          KC_F,    KC_G,   KC_H,   KC_J,    KC_K,       KC_L,    KC_SCLN, KC_ENT,  ___x___,   ___x___, ___x___, \
    KC_LSPO, KC_Z,    KC_X,   KC_C,          KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM,    KC_DOT,  KC_SLSH, KC_RSPC, ___x___,   KC_UP,   ___x___, \
    KC_LCTL, KC_LGUI, KC_GRV, LALT(KC_LCTL), KC_LALT, KC_SPC, KC_SPC, KC_RALT, MO(_GAMEX), KC_QUOT, KC_BSLS, KC_RCTL, KC_LEFT,   KC_DOWN, KC_RIGHT),
  [_GAMEX] = LAYOUT_ortho_5x15( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  ___x___, ___x___, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___x___, ___x___, ___x___, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___x___, ___x___, ___x___, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ___x___, KC_UP,   ___x___, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};

/*
[_TEMPLATE] = LAYOUT_ortho_5x15( \
___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, \
___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___, ___x___)
*/
__attribute__((weak)) layer_state_t default_layer_state_set_user(layer_state_t state) { 
  switch (biton16(state)){
    case _BASE:
      rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
      rgblight_sethsv(255, 255, 255);
      break;
    case _GAME:
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv(141, 51, 151);
      break;
  }
  return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (biton16(state)) {
    case _LOWER:
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv(78, 255, 178);
      break;
    case _RAISE:
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv(1, 255, 178);
      break;
    case _UTIL:
      rgblight_mode(RGBLIGHT_MODE_CHRISTMAS);
      rgblight_sethsv(255, 255, 255);
      break;
    case _GAMEX:
      rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv(141, 51, 255);
      break;
    default:
      switch (biton16(default_layer_state)) {
        case _BASE:
          rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
          rgblight_sethsv(255, 255, 255);
        break;
        case _GAME:
          rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
          rgblight_sethsv(141, 51, 151);
        break;
      }
      break;
  }
  return state;
}
