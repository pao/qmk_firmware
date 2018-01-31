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
#include "xd75.h"

#define PERMISSIVE_HOLD

// layers:
enum {
    LAYER_QWERTY,
    LAYER_FN,
    LAYER_NUMFN,
    LAYER_NAV,
};

enum {
    TD_ENTER_NUMLOCK = 0,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ENTER_NUMLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_KP_ENTER, KC_NUMLOCK),
};

// custom keycodes
#define Kc_CPFN LT(LAYER_FN, KC_CAPSLOCK)
#define Kc_NMFN LT(LAYER_NUMFN, TD(TD_ENTER_NUMLOCK))
#define Kc_SFSL MT(MOD_RSFT, KC_SLASH)
#define Kc_LOWR KC_NO
#define Kc_RASE MO(LAYER_NAV)
#define Kc_TSK  LCTL(S(KC_ESC)) // Windows Task Manager

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [LAYER_QWERTY] = {
        {KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,KC_EQL  ,KC_PAST ,KC_PMNS},
        {KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSPC ,KC_P7   ,KC_P8   ,KC_P9  },
        {Kc_CPFN ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,KC_P4   ,KC_P5   ,KC_P6  },
        {KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,Kc_SFSL ,KC_BSLS ,KC_P1   ,KC_P2   ,KC_P3  },
        {KC_GRV  ,KC_LGUI ,KC_LCTL ,KC_LALT ,Kc_LOWR ,KC_ENT  ,KC_SPC  ,Kc_RASE ,KC_RALT ,KC_RCTL ,KC_LBRC ,KC_DEL  ,KC_P0   ,Kc_NMFN ,KC_PDOT},
    },

    [LAYER_FN] = {
        {Kc_TSK  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_RBRC ,KC_INS  ,_______ ,_______ ,_______},
    },

    [LAYER_NUMFN] = {
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_CIRC ,KC_PSLS ,KC_PPLS},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
    },

    [LAYER_NAV] = {
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_HOME ,KC_UP   ,KC_END  ,KC_PGUP ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_PGDN ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
    },

    /*
    [LAYER_name] = { // template
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
        {_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______},
    },
    */
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    }

    return true;
}
