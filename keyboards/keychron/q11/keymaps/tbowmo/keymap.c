/* Copyright 2023 @ tbowmo
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
#include "tbowmo.h"
#include "spongebob.h"

#define KC_FN1 LT(_FN1, KC_PSCR)
#define KC_FN2 LT(_FN2, KC_APP)


enum custom_keycodes {
    SEL_WORD = QK_USER,
    SEL_LINE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_92_iso(
        ZOOM_RESET, KC_ESC, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        SEL_WORD, KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        SEL_LINE, KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        MC_4,     KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        MC_5,     KC_LCTL,  KC_LWIN,  KC_LALT,  KC_FN2,             KC_SPC,                        KC_SPC,             KC_RALT,  KC_FN1,     KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT
    ),

    [_FN1] = LAYOUT_92_iso(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        MC_6,     QK_BOOT,  _______,  _______,  _______,  _______,  _______,   _______,  QK_BOOT,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        MC_7,     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
        MC_8,     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            KC_END,
        MC_9,     _______,  _______,  _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              KC_WREF,  KC_VOLU,
        MC_10,    _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    KC_MPLY,  KC_MPRV,  KC_VOLD,  KC_MNXT
    ),

    [_FN2] = LAYOUT_92_iso(
        RGB_TOG,   EE_CLR,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,    KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,     KC_F24,   _______,  _______,  RGB_TOG,
        MC_6,     _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        MC_7,     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
        MC_8,     _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            KC_END,
        MC_9,     _______,  _______,  _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              KC_WREF,  KC_VOLU,
        MC_10,    _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    KC_MPLY,  KC_MPRV,  KC_VOLD,  KC_MNXT
    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(ZOOM_OUT, ZOOM_IN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN1]  = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [_FN2]  = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_MOD, RGB_RMOD) },
};
#endif // ENCODER_MAP_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case SEL_WORD:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_TAP(X_RGHT)) SS_LSFT(SS_LCTL(SS_TAP(X_LEFT))));
            }
            return false;
        case SEL_LINE:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
            }
            return false;
    }

    return process_record_spongebob(keycode, record);
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) { // macos/windows toggle switch
        spongebob_state(active);
        return false;
    }
    return true;
}
