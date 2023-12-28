#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

enum layers{
    _BASE,
    _FN1,
    _FN2,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define ZOOM_IN RCTL(KC_MINS)
#define ZOOM_OUT RCTL(KC_SLSH)
#define ZOOM_RESET RCTL(KC_0)

#endif // USERSPACE
