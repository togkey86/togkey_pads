// Copyright 2025 TogKey
// SPDX-License-Identifier: GPL-2.0-or-later6

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT(
    KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_MUTE, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_BSPC, 
    KC_DEL, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_ENT, 
    KC_HOME, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_RSFT, KC_UP, 
    KC_LCTL, KC_LEFT_GUI, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RIGHT
)};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {[0] = {ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP)}};
#endif