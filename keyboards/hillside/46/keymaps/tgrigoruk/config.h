// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Some boards have issues detecting handedness using the vbus voltage.
// Such as Elite-C v3, but not v3.1 on. Also apparently some ProMicro boards.
// For those boands, use usb detection instead.
#define SPLIT_USB_DETECT

// #define ENCODER_A_PINS { B12 }
// #define ENCODER_B_PINS { B13 }

#define TAPPING_TERM 200
