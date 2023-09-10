// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  LAYER_LENGTH
};

enum tapdances {
  TAPDANCE_LENGTH
};

enum combos {
  COMBO_LENGTH
};

tap_dance_action_t tap_dance_actions[] = {
    // [TD_QESC]   = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// const uint16_t PROGMEM combo_navigation[] = { KC_OSYM, KC_ONUM, COMBO_END };
combo_t key_combos[] = {
//   [COMBO_NAVIGATION]        = COMBO(combo_navigation, OSL(_NAVIGATION)),
};

// begin layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT_stance(
        KC_Q, KC_W, KC_E,KC_R, KC_T,      KC_Y, KC_U, KC_I, KC_O, KC_P, \
      KC_A, KC_S, KC_D,KC_F, KC_G,          KC_H, KC_J, KC_K, KC_L, KC_QUOT,\
    KC_Z, KC_X, KC_C,KC_V, KC_B,              KC_N, KC_M, KC_COMM,KC_DOT, KC_SLSH,\
                                LSFT_T(KC_SPC)
  ),
};