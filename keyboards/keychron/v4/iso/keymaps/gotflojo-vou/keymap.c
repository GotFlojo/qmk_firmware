/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keymap_neo2.h"

#include "features/custom_shift_keys.h"
// clang-format off


enum layers {
    WIN_BASE,
    VOU_BASE,
    SYMBOL,
    _FN1,
    _FN2,
    _FN3
};

const custom_shift_key_t custom_shift_keys[] = {
  {KC_1 , DE_DEG}, // Shift 1 is °
  {KC_2 , DE_SECT}, // Shift 2 is §
  {KC_6, DE_DLR}, // Shift 6 is $
  {KC_7, DE_EURO}, // Shift 7 is €
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_60_iso(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    DE_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,
        KC_LSFT, KC_NUBS,  DE_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL, KC_LWIN,  KC_LALT,                            KC_SPC,                             KC_RALT,  MO(_FN2), MO(_FN3), KC_RCTL),

    [VOU_BASE] = LAYOUT_60_iso(
        KC_ESC,     KC_1,     KC_2,    KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     DE_MINS,    NE_GRV,   KC_BSPC,
        KC_TAB,     DE_V,     DE_DOT,  DE_O,    DE_U,     DE_ADIA,  DE_Q,     DE_G,    DE_L,    DE_H,    DE_F,     DE_J,        NE_ACUT,
        MO(SYMBOL), DE_C,     DE_A,    DE_E,    DE_I,     DE_Y,     DE_B,     DE_T,    DE_R,    DE_N,    DE_S,     MO(SYMBOL),  DE_SS,    KC_ENT,
        KC_LSFT,    KC_NUBS,  DE_Z,    DE_X,    DE_COMM,  DE_UDIA,  DE_ODIA,  DE_P,    DE_D,    DE_W,    DE_M,     DE_K,            KC_RSFT,
        KC_LCTL,    KC_LOPT,  KC_LCMD,                            KC_SPC,                               KC_RCMD,   MO(_FN1),    MO(_FN3), KC_RCTL),

    [SYMBOL] = LAYOUT_60_iso(
        KC_ESC,     _______,     DE_SUP2,    DE_SUP3,    _______,     _______,     _______,     _______,    _______,    _______,    _______,     _______,    _______,   KC_BSPC,
        KC_TAB,     DE_AT,     DE_PERC,  DE_LCBR,    DE_RCBR,     DE_CIRC,  DE_EXLM,     DE_LABK,    DE_RABK,    DE_EQL,    DE_AMPR,     DE_EURO,     _______,
        MO(SYMBOL), DE_PIPE,     DE_GRV,    DE_LPRN,     DE_RPRN,     DE_ASTR,   DE_QUES,  DE_SLSH,    DE_COLN,    DE_MINS,    DE_UNDS,     MO(SYMBOL), _______,    KC_ENT,
        KC_LSFT,    KC_NUBS,  DE_HASH,    DE_LBRC,    DE_RBRC,  DE_TILD,  DE_DLR,  DE_PLUS,    DE_DQUO,    DE_QUOT,    DE_BSLS,     DE_SCLN,            KC_RSFT,
        KC_LCTL,    KC_LOPT,  KC_LCMD,                            KC_SPC,                               KC_RCMD,   MO(_FN1),    MO(_FN3), KC_RCTL),

    [_FN1] = LAYOUT_60_iso(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, KC_INS,   KC_PGUP,  KC_HOME,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP,   _______, KC_PGDN,  KC_END,   _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,   _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN2] = LAYOUT_60_iso(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, KC_APP,  KC_SCRL, KC_INS,   KC_PGUP,  KC_HOME,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, KC_UP,   KC_PSCR, KC_PGDN,  KC_END,   _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, NK_TOGG, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,             _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______),

    [_FN3] = LAYOUT_60_iso(
        KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,  _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______,  _______,  _______,  _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,  _______)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    return true;
}
