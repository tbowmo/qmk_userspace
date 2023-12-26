#include QMK_KEYBOARD_H
#include "tbowmo.h"

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_LBRC: // nordic iso layout national key
        case KC_SCLN: // ^^
        case KC_QUOT: // ^^
        case KC_MINS:
        case KC_SLSH: // Nordic iso minus / underscore
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
            return true;
        default:
            return false;  // Deactivate Caps Word.
    }
}
