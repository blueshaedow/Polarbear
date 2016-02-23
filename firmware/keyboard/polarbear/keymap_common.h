/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];


/* GH60 keymap definition macro
 * K2C, K31 and  K3C are extra keys for ISO
 */
#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, \
    K10, K11, K12, K13, K14, K15, K16, \
    K20, K21, K22, K23, K24, K25, K26, \
    K30, K31, K32, K33, K34, K35, K36, \
    K40, K41, K42,      K43, K44, K45, \
    K50 \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06 }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16 }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26 }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36 }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_NO,    KC_##K43, KC_##K44, KC_##K45 }, \
    { KC_##K50, KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
}

#define KEYMAP_POLARBEAR( \
    K00, K01, K02, K03, K04, K05, K06, \
    K10, K11, K12, K13, K14, K15, K16, \
    K20, K21, K22, K23, K24, K25, K26, \
    K30, K31, K32, K33, K34, K35, K36, \
    K40, K41, K42,      K43, K44, K45, \
    K50 \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, \
    K10, K11, K12, K13, K14, K15, K16, \
    K20, K21, K22, K23, K24, K25, K26, \
    K30, K31, K32, K33, K34, K35, K36, \
    K40, K41, K42,      K43, K44, K45, \
    K50 \
)

#endif