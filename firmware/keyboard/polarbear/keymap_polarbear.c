#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// Default (Left hand)
    KEYMAP_POLARBEAR( 
        A,    1,    2,    3,    4,    5,   DEL, \
        B,   NO,   NO,    E,    R,    T,  BSLS, \
        C,   NO,   NO,    D,    F,    G,  QUOT, \
        D,   NO,    X,    C,    V,    B,     N, \
        E,   NO,    P,       BSPC,    M,   ENT \
    	)
};
const uint16_t PROGMEM fn_actions[] = {
};


// const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   // Default (Left hand)
//     KEYMAP_POLARBEAR( 
//       ESC,    1,    2,    3,    4,    5,   DEL, \
//       TAB,    Q,    W,    E,    R,    T,  BSLS, \
//       FN1,    A,    S,    D,    F,    G,  QUOT, \
//      LSFT,    Z,    X,    C,    V,    B,   FN2, \
//      LGUI, LALT,    P,       BSPC,  FN0,   ENT, \
//      LCTL \
//       ),
//     // Layer 1 (right hand)
//     KEYMAP_POLARBEAR( 
//      TRNS,    0,    9,    8,    7,    6,  TRNS, \
//      TRNS,    P,    O,    I,    U,    Y,  TRNS, \
//      TRNS, SCLN,    L,    K,    J,    H,  TRNS, \
//      TRNS, SLSH,  DOT, COMM,    M,    N,  TRNS, \
//      TRNS, TRNS, TRNS,       TRNS, TRNS,  TRNS, \
//      TRNS \
//       ),
//     // Layer 2 (Nav layer)
//     KEYMAP_POLARBEAR( 
//      BTLD,   NO,   NO,   NO,   NO,   NO,    NO, \
//        NO,   NO,   NO, PGDN, PGUP,   NO,    NO, \
//       FN1,   NO, RGHT,   UP, DOWN, LEFT,    NO, \
//      LSFT,   NO,   NO,  END, HOME,   NO,    NO, \
//      LGUI, LALT,   NO,         NO,   NO,    NO, \
//      LCTL \
//       ),
//     // Layer 3 (Symbol layer)
//     KEYMAP_POLARBEAR( 
//       GRV,  FN3,  FN4,  FN5,  FN6,  FN7,    NO, \
//        NO,  FN8,  FN9, FN10, FN11, FN12,  FN13, \
//        NO, MINS,  EQL, LBRC, RBRC,   NO,    NO, \
//        NO,   NO,   NO,   NO,   NO,   NO,   FN2, \
//        NO,   NO,   NO,         NO,   NO,    NO, \
//        NO \
//       )
// };
// const uint16_t PROGMEM fn_actions[] = {
//     [0] = ACTION_LAYER_TAP_KEY(1, KC_SPC),
//     [1] = ACTION_LAYER_TOGGLE(2),
//     [2] = ACTION_LAYER_TOGGLE(3),
//     [3] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
//     [4] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
//     [5] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
//     [6] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
//     [7] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
//     [8] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
//     [9] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
//     [10] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
//     [11] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
//     [12] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
//     [13] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOT),
// };
