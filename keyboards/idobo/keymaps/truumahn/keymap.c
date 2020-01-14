#include QMK_KEYBOARD_H

extern rgblight_config_t rgblight_config;
extern keymap_config_t keymap_config;

#define DEFAULT_LAYER 0
#define LOWER_LAYER 1
#define RAISE_LAYER 2
#define UTIL_LAYER 3

bool NUMLAY_STATUS = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEFAULT_LAYER] = LAYOUT_ortho_5x15( \
    KC_ESC, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, KC_NO, KC_NO, KC_NO, RGB_TOG, KC_DEL, KC_NO, KC_NO, KC_NO, \
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_NO, KC_NO, KC_NO, \
    KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_NO, KC_NO, KC_NO, \
    KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_NO, KC_NO, KC_NO, \
    KC_LCTL, KC_LGUI, KC_GRV, KC_LALT, MO(2), KC_SPC, KC_NO, MO(1), KC_RALT, KC_QUOT, KC_BSLS, KC_RCTL, KC_NO, KC_NO, KC_NO),
  [LOWER_LAYER] = LAYOUT_ortho_5x15( \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_NO, KC_NO, KC_NO, \
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_NO, KC_NO, KC_NO, \
    KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_TRNS, KC_NO, KC_NO, KC_NO, \
    KC_TRNS, KC_NO, KC_NO, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_PGDN, KC_TRNS, KC_NO, KC_NO, KC_NO),
  [RAISE_LAYER] = LAYOUT_ortho_5x15( \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_NO, KC_NO, KC_NO, \
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_TRNS, KC_NO, KC_NO, KC_NO, \
    KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS, KC_NO, KC_NO, KC_NO, \
    KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(4), KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO),
  [UTIL_LAYER] = LAYOUT_ortho_5x15( \
    RESET, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
    RGB_HUD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_HUI, KC_NO, KC_NO, KC_NO, \
    RGB_SAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_SAI, KC_NO, KC_NO, KC_NO, \
    RGB_VAD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_VAI, KC_NO, KC_NO, KC_NO, \
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MO(1):
      if (record->event.pressed) {
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv(78, 255, 178);
      } else {
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
      }
      return true;
    case MO(2):
      if (record->event.pressed) {
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_sethsv(1, 255, 178);
      } else {
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
      }
      return true;
    case MO(3):
      if (record->event.pressed) {
        rgblight_mode(RGBLIGHT_MODE_CHRISTMAS);
      } else {
        rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
      }
      return true;
    default:
      return true;
  }
}
