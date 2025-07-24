// Copyright 2025 TogKey
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

//VIAL Unlock
#define VIAL_KEYBOARD_UID {0x77, 0xF7, 0x14, 0xBB, 0x74, 0x32, 0x66, 0xE9}
#define VIAL_UNLOCK_COMBO_ROWS {1, 2}
#define VIAL_UNLOCK_COMBO_COLS {0, 0}

//Boot Magic Config
#define BOOTMAGIC_ROW 1
#define BOOTMAGIC_COLUMN 0

//OLED
#define OLED_DISPLAY_128X64
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP2
#define I2C1_SCL_PIN GP3

#define ENCODER_MAP_KEY_DELAY 10

//If Flipped
#define ENCODER_DIRECTION_FLIP

#define MIDI_ADVANCED