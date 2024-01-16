#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

// enum {
//     TD_CW_TOGG_CAPS,
// };
//
// // Tap Dance definitions
// tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for CW_TOGG, twice for Caps Lock
//     [TD_CW_TOGG_CAPS] = ACTION_TAP_DANCE_DOUBLE(CW_TOGG, KC_CAPS),
// };

// enum tap_dance_codes {
//   DANCE_0,
// };
//
// typedef struct {
//     bool is_press_action;
//     uint8_t step;
// } tap;
//
// enum {
//     SINGLE_TAP = 1,
//     SINGLE_HOLD,
//     DOUBLE_TAP,
//     DOUBLE_HOLD,
//     DOUBLE_SINGLE_TAP,
//     MORE_TAPS
// };
//
// static tap dance_state[23];
//
// uint8_t dance_step(qk_tap_dance_state_t *state);
//
// uint8_t dance_step(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return SINGLE_TAP;
//         else return SINGLE_HOLD;
//     } else if (state->count == 2) {
//         if (state->interrupted) return DOUBLE_SINGLE_TAP;
//         else if (state->pressed) return DOUBLE_HOLD;
//         else return DOUBLE_TAP;
//     }
//     return MORE_TAPS;
// }
//
//
// void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
// void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
// void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);
//
// void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
//     if(state->count == 2) {
//         tap_code16(KC_CAPS);
//         tap_code16(KC_CAPS);
//         tap_code16(KC_CAPS);
//     }
//     if(state->count > 2) {
//         tap_code16(KC_CAPS);
//     }
// }
//
// void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
//     dance_state[0].step = dance_step(state);
//     switch (dance_state[0].step) {
//         case SINGLE_TAP: register_code16(KC_CAPS); break;
//         case SINGLE_HOLD: register_code16(KC_CAPS); break;
//         case DOUBLE_TAP: register_code16(CW_TOGG); register_code16(CW_TOGG); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(CW_TOGG); register_code16(CW_TOGG);
//     }
// }
//
// void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[0].step) {
//         case SINGLE_TAP: unregister_code16(KC_EQUAL); break;
//         case SINGLE_HOLD: unregister_code16(KC_INSERT); break;
//         case DOUBLE_TAP: unregister_code16(KC_EQUAL); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(KC_EQUAL); break;
//     }
//     dance_state[0].step = 0;
// }


// enum combo_events {
//   CAPS_COMBO,
// };
//
// const uint16_t caps_combo[] PROGMEM = {CW_TOGG, KC_LSFT};
//
// combo_t key_combos[] = {
//   [CAPS_COMBO] = COMBO_ACTION(caps_combo),
//   // Other combos...
// };
//
// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case CAPS_COMBO:
//       if (pressed) {
//         register_code(KC_CAPS);
//       }
//       break;
//   }
// }

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[0] = LAYOUT_split_3x6_3(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT, KC_LCTL, MT(MOD_LGUI, KC_ENT), MO(1), MO(2), KC_SPC, KC_LALT),
                                                              [1] = LAYOUT_split_3x6_3(KC_CAPS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, KC_LCTL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TILD, KC_MINS, KC_EQL, KC_LCBR, KC_RCBR, KC_BSLS, KC_LSFT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, SC_SENT, KC_NO, KC_NO, KC_NO, CW_TOGG, KC_SPC, KC_LALT),
                                                              [2] = LAYOUT_split_3x6_3(KC_TAB, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_LALT, TG(3), KC_NO, KC_VOLD, KC_VOLU, KC_MUTE, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_F12, KC_LSFT, KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_MPLY, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_NO, SC_SENT, KC_LCTL, KC_ENT, KC_LGUI, KC_NO, KC_NO, KC_NO),
                                                              [3] = LAYOUT_split_3x6_3(KC_TAB, TG(3), KC_NO, KC_NO, KC_NO, QK_BOOT, KC_PLUS, KC_7, KC_8, KC_9, KC_MINS, KC_BSPC, KC_ESC, KC_NO, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, KC_ASTR, KC_4, KC_5, KC_6, KC_SLSH, KC_NO, KC_LSFT, KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD, KC_EQL, KC_1, KC_2, KC_3, KC_COMM, KC_NO, KC_LCTL, KC_ENT, KC_LALT, KC_NO, KC_SPC, KC_0)};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool    process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case KC_BSPC: {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }
    }
    return true;
};

// bool caps_word_press_user(uint16_t keycode) {
//     switch (keycode) {
//         // Tapdance keys are handled manually.
//         case TD(TD_CW_TOGG_CAPS):
//             return true;
//
//         default:
//             return false; // Deactivate Caps Word.
//     }
// }
//
// const uint16_t CAPS_COMBO[] PROGMEM = {KC_LSFT, CW_TOGG, COMBO_END};
//
// enum combo_events {
//     CAPS_COMBO,
// }

// void process_combo_event(uint16_t combo_index, bool pressed) {
//     switch (combo_index) {
//         case CAPS_COMBO:
//             if (pressed) {
//                 // caps_word_on(); // Activate Caps Word!
//                 caps_word_on()
//             }
//             break;
//     }
// }

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
