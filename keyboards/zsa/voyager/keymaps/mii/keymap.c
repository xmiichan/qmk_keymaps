// mii's Voyager keymap
//
// Use at your own risk. :)

#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "quantum_keycodes.h"
#include "layout.h"
#include "catppuccin.h"

// layers
enum layer {
    BASE,
    NAV,
    SYM,
};

// custom keycodes
enum custom_keycodes {
    KM_MOUSE_JIGGLE = SAFE_RANGE,
    OS_TAB,
    OS_LINUX_TOGGLE,
};

#define KM_JIGG KM_MOUSE_JIGGLE
#define OS_LTOG OS_LINUX_TOGGLE

#define MK_TAB ALGR_T(KC_TAB)
#define MK_ENT LT(NAV, KC_ENTER)

#define MK_A LCTL_T(KC_A)
#define MK_S ALT_T(KC_S)
#define MK_D LSFT_T(KC_D)
#define MK_F LGUI_T(KC_F)

#define MK_J RGUI_T(KC_J)
#define MK_K RSFT_T(KC_K)
#define MK_L ALT_T(KC_L)
#define MK_SCLN RCTL_T(KC_SEMICOLON)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR(
        KC_NO  , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
        KC_BSLS, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,
        QK_GESC, MK_A   , MK_S   , MK_D   , MK_F   , KC_G   ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,
                                                     KC_BSPC, MK_TAB ,


                 KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_EQL ,
                 KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
                 KC_H   , MK_J   , MK_K   , MK_L   , MK_SCLN, KC_QUOT,
                 KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
        MK_ENT , KC_SPC
    ),
    [NAV] = LAYOUT_LR(
        QK_LLCK, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
        _______, _______, _______, _______, OS_LTOG, KM_JIGG,
        KC_ESC , KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, _______,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,
                                                     _______, _______,

                 KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
                 KC_HOME, KC_PGUP, _______, _______, KC_DEL , KC_F12 ,
                 KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, OS_TAB , _______,
                 KC_END , KC_PGDN, _______, _______, _______, _______,
        _______, _______
    ),
    [SYM] = LAYOUT_LR(
        QK_LLCK, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,
        _______, _______, _______, _______, _______, _______,
                                                     _______, _______,

                 _______, _______, _______, _______, _______, _______,
                 _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______,
                 KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
                 _______, KC_PIPE, KC_LT  , KC_GT  , KC_BSLS, _______,
        _______, _______
    ),
};

#ifdef COMBO_ENABLE
// first row, left
const uint16_t PROGMEM hash[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM dollar[] = {KC_E, KC_R, COMBO_END};
// right
const uint16_t PROGMEM left_bracket[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM right_bracket[] = {KC_I, KC_O, COMBO_END};

// second row, left
const uint16_t PROGMEM exclaim[] = {MK_S, MK_D, COMBO_END};
const uint16_t PROGMEM asterisk[] = {MK_D, MK_F, COMBO_END};
const uint16_t PROGMEM at[] = {MK_F, KC_G, COMBO_END};
// right
const uint16_t PROGMEM ampersand[] = {KC_H, MK_J, COMBO_END};
const uint16_t PROGMEM left_paren[] = {MK_J, MK_K, COMBO_END};
const uint16_t PROGMEM right_paren[] = {MK_K, MK_L, COMBO_END};

// third row, left
const uint16_t PROGMEM percent[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM circumflex[] = {KC_C, KC_V, COMBO_END};
// right
const uint16_t PROGMEM pipe[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM backtick[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM backslash[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(hash, KC_HASH),
    COMBO(dollar, KC_DOLLAR),
    COMBO(left_bracket, KC_LEFT_BRACKET),
    COMBO(right_bracket, KC_RIGHT_BRACKET),
    COMBO(exclaim, KC_EXCLAIM),
    COMBO(asterisk, KC_ASTERISK),
    COMBO(at, KC_AT),
    COMBO(ampersand, KC_AMPERSAND),
    COMBO(left_paren, KC_LEFT_PAREN),
    COMBO(right_paren, KC_RIGHT_PAREN),
    COMBO(percent, KC_PERCENT),
    COMBO(circumflex, KC_CIRCUMFLEX),
    COMBO(pipe, KC_PIPE),
    COMBO(backtick, KC_GRAVE),
    COMBO(backslash, KC_BACKSLASH),
};
#endif

#ifdef COMBO_MUST_TAP_PER_COMBO
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo) {
    uint16_t key;
    uint8_t i = 0;

    // check if all the keys in the combo are mod-taps or layer-taps. if so,
    // return the combined hold action, otherwise execute combo
    while ((key = pgm_read_word(&combo->keys[i])) != COMBO_END) {
        if (!IS_QK_MOD_TAP(key) && !IS_QK_LAYER_TAP(key)) {
            return false;
        }
        i++;
    }
    return true;
}
#endif


#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // trigger hold action immediately when another key is pressed
        case MK_ENT:
        case MK_TAB:
            return true;
        default:
            return false;
    }
}
#endif

#ifdef CHORDAL_HOLD
// exclude thumb keys and mods from chordal hold
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', 'R',
    'R', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', 'R',
    '*', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', 'R',
    '*', 'L', 'L', 'L', 'L', 'L',   'R', 'R', 'R', 'R', 'R', '*',
                        '*', '*',   '*', '*'
);
#endif

bool mouse_jiggle_mode = false;
bool layer_mod_held = false;
uint8_t layer_mod_added = 0;
bool is_linux = false;
uint8_t mod_state;

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_user(os_variant_t detected_os) {
    switch (detected_os) {
        case OS_LINUX:
            is_linux = true;
            break;
        case OS_MACOS:
        case OS_IOS:
        case OS_WINDOWS:
            is_linux = false;
            break;
        case OS_UNSURE:
        default:
            // no autodetect on anything not on the list
            break;
    }
    return true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    if (mouse_jiggle_mode && record->event.pressed) {
        mouse_jiggle_mode = false;
    }

    switch (keycode) {
        // switch between linux and mac os modifier layouts
        case OS_LINUX_TOGGLE:
            if (record->event.pressed) {
                is_linux = !is_linux;
            }
            return false;

        // os window switching
        case OS_TAB:
            if (record->event.pressed) {
                if (!layer_mod_held) {
                    layer_mod_held = true;
                    uint8_t mod = is_linux ? MOD_BIT(KC_LALT) : MOD_BIT(KC_LGUI);
                    if (!(get_mods() & mod)) {
                        layer_mod_added = mod;
                        add_mods(mod);
                    }
                }
                tap_code(KC_TAB);
            }
            return false;

        // release modifiers when active on nav layer on esc
        case KC_ESCAPE:
        case QK_GRAVE_ESCAPE:
            if (layer_mod_held) {
                layer_mod_held = false;
                if (layer_mod_added) {
                    del_mods(layer_mod_added);
                    layer_mod_added = 0;
                    send_keyboard_report();
                }
            }
            break;

        // mouse jiggle toggle
        case KM_JIGG:
            if (record->event.pressed) {
                mouse_jiggle_mode = !mouse_jiggle_mode;
            }
            break;

        case KC_BACKSPACE:
            if (record->event.pressed && mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_DELETE);
                set_mods(mod_state);
                return false;
            }
            break;

        // shift + caps word = caps lock
        case QK_CAPS_WORD_TOGGLE:
            if (record->event.pressed && get_mods() & MOD_MASK_SHIFT) {
                tap_code(KC_CAPS_LOCK);
                return false;
            }
            break;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return;

    static bool rsft_tabbed = false;
    static uint16_t rsft_deadline = 0;
    uint16_t now = record->event.time;

    if (keycode == KC_RIGHT_SHIFT) {
        if (rsft_tabbed && !timer_expired(now, rsft_deadline)) {
            caps_word_on();
        }
        rsft_tabbed  = true;
        rsft_deadline = now + GET_TAPPING_TERM(keycode, record);
    } else {
        rsft_tabbed = false;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_mod_held && !layer_state_cmp(state, NAV)) {
        layer_mod_held = false;
        if (layer_mod_added) {
            del_mods(layer_mod_added);
            layer_mod_added = 0;
            send_keyboard_report();
        }
    }
    return state;
}

void matrix_scan_user(void) {
    if (mouse_jiggle_mode) {
        tap_code(QK_MOUSE_CURSOR_UP);
        tap_code(QK_MOUSE_CURSOR_DOWN);
        tap_code(QK_MOUSE_CURSOR_LEFT);
        tap_code(QK_MOUSE_CURSOR_RIGHT);
    }
}

void housekeeping_task_user(void) {
    STATUS_LED_4(is_caps_word_on());
}

bool led_update_user(led_t led_state) {
    STATUS_LED_3(led_state.caps_lock);
    return true;
}

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    enum layer current_layer = get_highest_layer(layer_state);
    int len;

    switch (current_layer) {
    case BASE:
        break;
    case NAV: {
        // arrow keys / HJKL
        int arrow_keys[] = {38, 39, 40, 41};
        len = sizeof(arrow_keys) / sizeof(arrow_keys[0]);
        for (int i = 0; i < len; ++i) {
            rgb_matrix_set_color(arrow_keys[i], CAT_PEACH);
        }
        break;
    }
    case SYM: {
        int sym_keys[] = {
            0,
            7, 8, 9, 10, 11,
            13, 14, 15, 16, 17,
            19, 20, 21, 22, 23,
            32, 33, 34, 35, 36,
            38, 39, 40, 41, 42,
            44, 45, 46, 47, 48
        };
        len = sizeof(sym_keys) / sizeof(sym_keys[0]);
        for (int i = 0; i < len; ++i) {
            rgb_matrix_set_color(sym_keys[i], CAT_SKY);
        }
        break;
    }
    default:
        break;
    }

    // pink thumb keys
    int thumb_keys[] = {24, 25, 50, 51};
    for (int i = 0; i < 4; ++i) {
        rgb_matrix_set_color(thumb_keys[i], CAT_PINK);
    }

    if (is_linux) {
        rgb_matrix_set_color(0, CAT_TEAL);
    } else {
        rgb_matrix_set_color(0, CAT_FLAMINGO);
    }

    return false;
}

void suspend_power_down_user(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
}
#endif
