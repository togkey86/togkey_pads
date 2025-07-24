// Copyright 2025 TogKey
// SPDX-License-Identifier: GPL-2.0-or-later6

#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {[0] = {ENCODER_CCW_CW(KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP)}};
#endif


enum custom_keycodes { LAYER_SCROLL = QK_KB_0 };

enum blender_keycode { TOG_LAY = QK_KB_0 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER_SCROLL:
            if (!record->event.pressed) {
                // Already handled the keycode, no further processing is needed
                return false;
            }

            uint8_t current_layer = get_highest_layer(layer_state);
            if (current_layer > 3 || current_layer < 0) {
                return false;
            }

            uint8_t next_layer = current_layer + 1;
            if (next_layer > 3) {
                next_layer = 0;
            }

            layer_move(next_layer);

            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        QK_KB_0,
        KC_VOLD, KC_MUTE, KC_VOLU,
        KC_MPRV, KC_MPLY, KC_MNXT
    )
};
