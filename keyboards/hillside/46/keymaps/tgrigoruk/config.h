// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Some boards have issues detecting handedness using the vbus voltage.
// Such as Elite-C v3, but not v3.1 on. Also apparently some ProMicro boards.
// For those boands, use usb detection instead.
#define SPLIT_USB_DETECT

// #define ENCODER_A_PINS { B12 }
// #define ENCODER_B_PINS { B13 }
// #define ENCODER_RESOLUTION 4

#define TAPPING_TERM 200

// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// https://docs.qmk.fm/features/mouse_keys#kinetic-mode
#define MK_KINETIC_SPEED
#define MOUSEKEY_MOVE_DELTA 24  // default 16
#define MOUSEKEY_INITIAL_SPEED 400  // default 100
#define MOUSEKEY_BASE_SPEED 3500  // default 5000
