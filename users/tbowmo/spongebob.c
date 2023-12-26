#include QMK_KEYBOARD_H
#include "spongebob.h"

/** sponge bob writing **/
uint16_t repeat_mode;
uint8_t prev_upper;
uint8_t prev_lower;
bool uppercase;
bool spongeBob = false;

bool process_record_spongebob(uint16_t keycode, keyrecord_t *record) {
    if (!spongeBob) {
        return true;
    }

    if (keycode == KC_ENTER && record->event.pressed) {
        uppercase = false;
        return true;
    }

    if (uppercase == false && record->event.pressed )  {
        uppercase = true;
        return true;
    }

    if((KC_A <= keycode) && (keycode <= KC_Z)) {
        if ( record->event.pressed ) {
            bool press = rand() % 2;

            if (prev_upper > 2) {           // if more than 3 lower's in a row print upper
                prev_upper = 0;
                press = false;
            } else if (prev_lower > 2) {    // if more than 3 upper's in a row print lower
                prev_lower = 0;

                press = true;
            }
            if (press) {
                prev_upper++;
                tap_code16(S(keycode));
                clear_mods();
            } else {
                prev_lower++;
                tap_code16(keycode);
            }
        }
        return false;
    }
    return true;
}

void spongebob_state(bool enable) {
    spongeBob = enable;
}
