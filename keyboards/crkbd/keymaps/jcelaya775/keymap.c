#include QMK_KEYBOARD_H

// TODO:
//  - [ ] Consider cmd+escape for super key (need to enable COMBO_ENABLE)
//  - [ ] Fix shift+delete for mac (so that it doesn't register shift+delete, but just delete)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // default layer
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,              KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_BSPC,
        KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G,              KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B,              KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_SENT,
         MT(MOD_LCTL, MOD_LGUI), MT(MOD_LGUI, KC_ENT), MO(1),              MO(2), KC_SPC, KC_LALT
    ),
    // lower layer
    [1] = LAYOUT_split_3x6_3(
        KC_LGUI, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        KC_LCTL, KC_1,    KC_2,  KC_3,    KC_4,   KC_5,                 KC_TILD, KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS,
        KC_LSFT, KC_6,    KC_7,  KC_8,    KC_9,   KC_0,                 KC_GRV,  KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, SC_SENT,
                                   KC_NO, KC_NO, KC_LGUI,                 MT(MOD_LGUI, CW_TOGG), KC_SPC,  MT(MOD_LALT, MOD_LGUI)
    ),
    // higher layer
    [2] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_F1, KC_F2, KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
        KC_LALT, KC_BRID, KC_BRIU, KC_VOLD, KC_VOLU, KC_MUTE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  KC_F12,
        KC_LSFT, KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_MPLY,      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,  SC_SENT,
                  KC_LCTL, MT(MOD_LGUI, KC_ENT), MO(1),      KC_NO, KC_NO, KC_NO
    ),
    // number-pad layer (disabled for now)
    [3] = LAYOUT_split_3x6_3(
        KC_TAB,  TG(3), KC_NO,   KC_NO,   KC_NO,   QK_BOOT,         KC_ASTR, KC_7, KC_8, KC_9, KC_SLSH, KC_BSPC,
        KC_ESC,  KC_NO, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,         KC_PLUS, KC_4, KC_5, KC_6, KC_MINS, KC_ENT,
        KC_LSFT, KC_NO, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD,         KC_COMM, KC_1, KC_2, KC_3, KC_DOT,  KC_EQL,
                                  KC_LCTL, KC_ENT, KC_LALT,         KC_COMM, KC_SPC, KC_0
    )
};

uint8_t mod_state;
bool caps_lock_on = false;
bool is_mo2_held = false;  // Flag to track if MO(2) is held
bool is_layer1_active = false;  // Flag to track if layer 1 is active
bool is_mo_lgui_active = false;  // Flag to track if MO(2) + LGUI is active
bool is_lctl_lgui_active = false;  // Flag to track if LCTL + LGUI is active
bool is_lalt_lgui_active = false;  // Flag to track if LALT + LGUI is active

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case KC_BSPC: {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    // TODO: Maybe use unregister_mods instead?
                    del_mods(MOD_BIT(KC_LSFT)); // allow for right shift to be used with delete
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
            return true; // Let QMK process the KC_BSPC keycode as usual outside of shift
        }
        case MT(MOD_LGUI, CW_TOGG):
            if (record->event.pressed) {
                switch (record->tap.count) {
                    case 1:
                        if (caps_lock_on) {
                            tap_code16(KC_CAPS);
                            caps_lock_on = false;
                        } else {
                            caps_word_toggle();
                        }
                        return false;
                    case 2:
                        tap_code16(KC_CAPS);
                        caps_lock_on = true;
                        return false;
                }
            }
        case MO(2):
            if (record->event.pressed) {
                is_mo2_held = true;
            } else {
                is_mo2_held = false;
            }
           return true; // Allow normal MO(2) processing
        case MO(1):
            if (record->event.pressed) {
                is_layer1_active = true;
                layer_on(1);
                if (is_mo2_held) {
                    layer_off(2);
                    is_mo_lgui_active = true;
                    register_mods(MOD_LGUI);
                }
            } else {
                if (is_layer1_active) {
                    layer_off(1);
                    unregister_mods(MOD_LGUI); // Release LGUI modifier
                    is_layer1_active = false;
                    is_mo_lgui_active = false;
                }
            }
            return false; // Prevent normal MO(1) processing
        case MT(MOD_LCTL, MOD_LGUI):
            if (layer_state_is(0)) {
                if (record->event.pressed) {
                    register_mods(MOD_LCTL);
                    if (record->tap.count == 2) {
                        is_lctl_lgui_active = true;
                        register_mods(MOD_LGUI);
                    }
                } else {
                    unregister_mods(MOD_LCTL);
                    if (is_lctl_lgui_active) {
                        is_lctl_lgui_active = false;
                        unregister_mods(MOD_LGUI);
                    }
                }
                return false;
            } else {
                return true;
            }
        case MT(MOD_LALT, MOD_LGUI):
            if (layer_state_is(1)) {
                if (record->event.pressed) {
                    register_mods(MOD_LALT);
                    if (record->tap.count == 2) {
                        is_lalt_lgui_active = true;
                        register_mods(MOD_LGUI);
                    }
                } else {
                    unregister_mods(MOD_LALT);
                    if (is_lalt_lgui_active) {
                        is_lalt_lgui_active = false;
                        unregister_mods(MOD_LGUI);
                    }
                }
                return false;
            } else {
                if (!record->event.pressed) {
                    if (is_lalt_lgui_active) {
                        unregister_mods(MOD_LALT);
                        is_lalt_lgui_active = false;
                        unregister_mods(MOD_LGUI);
                    }
                }
                return true;
            }

            break;
    }
    return true;
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, CW_TOGG):
            return 1000;
        case MT(KC_LCTL, MOD_LGUI):
            return 200;
        case MT(MOD_LALT, MOD_LGUI):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
