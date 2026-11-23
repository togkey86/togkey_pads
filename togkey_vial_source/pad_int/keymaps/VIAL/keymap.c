// Copyright 2026 TogKey
// SPDX-License-Identifier: GPL-2.0-or-later6

#include QMK_KEYBOARD_H
#include "pad_int.h"    

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(LAYER_DOWN, LAYER_UP)  },
    [1] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [2] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [3] =   { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    //                  Encoder 1                                     Encoder 2
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    bool num_on = host_keyboard_led_state().num_lock;

    for (uint8_t i = led_min; i < led_max; i++) {
        if (g_led_config.flags[i] & LED_FLAG_MODIFIER) {
            if (num_on) {
                rgb_matrix_set_color(i, RGB_WHITE);
            } else {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
        }
    }

    // Clear layer indicator LEDs
    rgb_matrix_set_color(19, 0, 0, 0);
    rgb_matrix_set_color(20, 0, 0, 0);
    rgb_matrix_set_color(21, 0, 0, 0);
    rgb_matrix_set_color(22, 0, 0, 0);

    // Get current active layer
    uint8_t layer = get_highest_layer(layer_state);

    switch (layer) {
        case 0:
            rgb_matrix_set_color(22, RGB_WHITE);
            break;

        case 1:
            rgb_matrix_set_color(22, RGB_WHITE);
            rgb_matrix_set_color(21, RGB_WHITE);
            break;

        case 2:
            rgb_matrix_set_color(22, RGB_WHITE);
            rgb_matrix_set_color(21, RGB_WHITE);
            rgb_matrix_set_color(20, RGB_WHITE);
            break;

        case 3:
            rgb_matrix_set_color(22, RGB_WHITE);
            rgb_matrix_set_color(21, RGB_WHITE);
            rgb_matrix_set_color(20, RGB_WHITE);
            rgb_matrix_set_color(19, RGB_WHITE);
            break;
    }

    return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NUM, KC_KP_SLASH, KC_KP_ASTERISK, KC_EQUAL, KC_MUTE,
        KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, MODE_NEXT,
        KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,
        KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ENTER,
        NUM_00, KC_KP_0, KC_KP_DOT
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [2] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [3] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
    )
};
