/* Copyright 2018 Patrick O'Leary
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
#include "contra.h"

#define PERMISSIVE_HOLD

// layers:
enum {
    LAYER_QWERTY,
    LAYER_FN,
    LAYER_NAV,
    LAYER_LOWER,
    LAYER_ADJUST,
};

// custom keycodes
#define Kc_CPFN LT(LAYER_FN, KC_CAPSLOCK)
#define Kc_SFSL MT(MOD_RSFT, KC_SLASH)
#define Kc_SFBS MT(MOD_RSFT, KC_BSLASH)
#define Kc_GUSP MT(MOD_LGUI, KC_LBRACKET)
#define Kc_LOWR MO(LAYER_LOWER)
#define Kc_RASE MO(LAYER_NAV)
#define Kc_TSK  LCTL(S(KC_ESC)) // Windows Task Manager

enum {
    Kc_CXL = SAFE_RANGE,
    Kc_CXR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = {
        {KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC},
        {Kc_CPFN ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT},
        {KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,Kc_SFSL ,Kc_SFBS},
        {KC_GRV  ,KC_LGUI ,KC_LCTL ,KC_LALT ,Kc_LOWR ,KC_ENT  ,KC_SPC  ,Kc_RASE ,KC_LALT ,KC_RCTL ,Kc_GUSP ,KC_DEL },
    },

    [LAYER_FN] = {
        {_______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,_______},
        {_______ ,KC_F11  ,KC_F12  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_RBRC ,KC_INS },
    },

    [LAYER_NAV] = {
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_HOME ,KC_UP   ,KC_END  ,KC_PGUP ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_PGDN ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
    },

    [LAYER_LOWER] = {
        {KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_EQL },
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
    },

    [LAYER_ADJUST] = {
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,Kc_CXL  ,_______ ,Kc_CXR  ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
    },

    /*
    [LAYER_name] = { // template
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
    },
    */
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case Kc_LOWR:
        if (record->event.pressed) {
            layer_on(LAYER_LOWER);
            update_tri_layer(LAYER_LOWER, LAYER_NAV, LAYER_ADJUST);
        } else {
            layer_off(LAYER_LOWER);
            update_tri_layer(LAYER_LOWER, LAYER_NAV, LAYER_ADJUST);
        }
        return false;
        break;
    case Kc_RASE:
        if (record->event.pressed) {
            layer_on(LAYER_NAV);
            update_tri_layer(LAYER_LOWER, LAYER_NAV, LAYER_ADJUST);
        } else {
            layer_off(LAYER_NAV);
            update_tri_layer(LAYER_LOWER, LAYER_NAV, LAYER_ADJUST);
        }
        return false;
        break;
    case Kc_CXL:
        SEND_STRING(SS_LCTRL("x")SS_TAP(X_LEFT));
        return false;
        break;
    case Kc_CXR:
        SEND_STRING(SS_LCTRL("x")SS_TAP(X_RIGHT));
        return false;
        break;
    }

    return true;
}
