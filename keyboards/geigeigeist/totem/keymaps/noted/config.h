// Copyright 2022 GEIST @geigeigeist
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

// If the USB cable is always connected to the left side flash both sides with this option
#define MASTER_LEFT
// #define MASTER_RIGHT
#undef EE_HANDS

// #define TAPPING_TERM 170
// Timeless homerow mods setup
// https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/urobs_zmk_timeless_home_row_mods_ported_to_native/
#define TAPPING_TERM 280
#define PERMISSIVE_HOLD
#define FLOW_TAP_TERM 200 //150
#define CHORDAL_HOLD
#define SPECULATIVE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT
