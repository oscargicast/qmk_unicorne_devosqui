#include QMK_KEYBOARD_H
#include "unicorne.h"

#ifdef OLED_ENABLE
#    include "animations/utils/animation-utils.h"
#    include "animations/crab/crab.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TAB, KC_LGUI, MO(1), KC_SPC, KC_ENT, MO(2), KC_RALT),
                                                              [1] = LAYOUT_split_3x6_3(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3), KC_TRNS),
                                                              [2] = LAYOUT_split_3x6_3(KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PMNS, KC_PPLS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PEQL, KC_UNDS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS, KC_TRNS, MO(3), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
                                                              [3] = LAYOUT_split_3x6_3(UG_TOGG, UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU, KC_NO, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE, QK_RBT, UG_PREV, UG_HUED, UG_SATD, UG_VALD, UG_SPDD, KC_NO, KC_NO, KC_NO, KC_NO, KC_MSTP, KC_MPLY, RM_TOGG, RM_NEXT, RM_HUEU, RM_SATU, RM_VALU, RM_SPDU, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MFFD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_raw_P(layer_zero, sizeof(layer_zero));
                break;
            case 1:
                oled_write_raw_P(layer_one, sizeof(layer_one));
                break;
            case 2:
                oled_write_raw_P(layer_two, sizeof(layer_two));
                break;
            case 3:
                oled_write_raw_P(layer_three, sizeof(layer_three));
                break;
        }
    } else {
        oled_render_anim();
    }
    return false;
}

#endif
