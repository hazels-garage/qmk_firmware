// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
  _ALPHA,
  _NUMBERS,
  _NAVIGATION,
  LAYER_LENGTH
};

enum tapdances {
  TD_QESC,
  TAPDANCE_LENGTH
};

enum combos {
  COMBO_NAVIGATION,
  COMBO_ENTER,
  COMBO_LENGTH
};

#define KC_QQ TD(TD_QESC)

tap_dance_action_t tap_dance_actions[] = {
    [TD_QESC]   = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM combo_navigation[] = { KC_D, KC_F, COMBO_END };
const uint16_t PROGMEM combo_enter[] = { KC_L, KC_QUOTE, COMBO_END };

combo_t key_combos[] = {
  [COMBO_NAVIGATION]        = COMBO(combo_navigation, MO(_NAVIGATION)),
  [COMBO_ENTER]             = COMBO(combo_enter, KC_ENT)
};

// begin layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHA] = LAYOUT_stance(
        KC_QQ, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I, KC_O, KC_P, \
      KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_H, KC_J, KC_K, KC_L, KC_QUOT,\
    KC_Z, KC_X, KC_C,KC_V, LCTL_T(KC_B),              KC_N, KC_M, KC_COMM,KC_DOT, KC_SLSH,\
                                      LSFT_T(KC_SPC)
  ),
  [_NUMBERS] = LAYOUT_stance(
        KC_QQ, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I, KC_O, KC_P, \
      KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_H, KC_J, KC_K, KC_L, KC_QUOT,\
    KC_Z, KC_X, KC_C,KC_V, LCTL_T(KC_B),              KC_N, KC_M, KC_COMM,KC_DOT, KC_SLSH,\
                                      LSFT_T(KC_SPC)
  ),
  [_NAVIGATION] = LAYOUT_stance(
        KC_QQ, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I, KC_O, KC_P, \
      KC_A, KC_S, KC_D, KC_F, KC_G,                  KC_H, KC_J, KC_K, KC_L, KC_QUOT,\
    KC_Z, KC_X, KC_C,KC_V, LCTL_T(KC_B),              KC_N, KC_M, KC_COMM,KC_DOT, KC_SLSH,\
                                      LSFT_T(KC_SPC)
  ),  
};