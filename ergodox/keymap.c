#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_french.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_jp.h"
#include "keymap_steno.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL


enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: Basic layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  | Caps |           |StenoL|   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   F  |   P  |   B  | SymL |           |QwertL|   J  |   L  |   U  |   Y  |   ;  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   R  |   S  |   T  |   G  |------|           |------|   K  |   N  |   E  |   I  |   O  |   '"   |
   * |--------+------+------+------+------+------|LANG 1|           |LANG 2|------+------+------+------+------+--------|
   * |(/LShift|   Z  |   X  |   C  |   D  |   V  |      |           |      |   M  |   H  |   ,  |   .  |  / ? |)/RShift|
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | Esc  |  ` ~ |CS/Cap| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~MedL |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Tog AS|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | PgUp |       | Home |        |      |
   *                                 | Space|Back  |------|       |------|  Tab   |Enter |
   *                                 |      |space | PgDn |       | End  |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  // left hand
  [0] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,             KC_3,           KC_4,           KC_5,                 KC_CAPS,
    KC_DELETE,      KC_Q,           KC_W,             KC_F,           KC_P,           KC_B,                 LT(1, TG(1)),
    KC_BSPACE,      KC_A,           KC_R,             KC_S,           KC_T,           KC_G,
    KC_LSPO,        KC_Z,           KC_X,             KC_C,           KC_D,           KC_V,                 KC_LANG1,
    KC_ESC,         KC_GRV,         SGUI_T(KC_CAPS),  KC_LEFT,        KC_RIGHT,
                                                                                      OSM(MOD_LCTL),        KC_LGUI,
                                                                                                            KC_PGUP,
                                                                      KC_SPACE,       KC_BSPACE,            KC_PGDOWN,

  // right hand
    TG(5),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,
    TG(3),          KC_J,           KC_L,           KC_U,           KC_Y,           KC_SCOLON,      KC_BSLASH,
                    KC_K,           KC_N,           KC_E,           KC_I,           KC_O,           KC_QUOTE,
    KC_LANG2,       KC_M,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSPC,
                                    KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,    TT(2),
    KC_LALT,        KC_ASTG,
    KC_HOME,
    KC_END,         KC_TAB,         KC_ENTER
  ),

  /* Keymap 1: Symbol Layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |  ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   {  |   }  |   |  |   &  |   /  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   (  |   )  |   '  |   _  |   "  |------|           |------| Down |   4  |   5  |   6  |   +  |   -    |
   * |--------+------+------+------+------+------|      |           |  L4  |------+------+------+------+------+--------|
   * |        |   [  |   ]  |   !  |   @  |   #  |      |           |      |      |   1  |   2  |   3  |   \  |  Enter |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |   %  |   <  |   >  |   =  |                                       |   0  |    . |      |   =  |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // SYMBOLS
  [1] = LAYOUT_ergodox_pretty(
    //left hand
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRNS,
    KC_TRNS,        KC_LCBR,        KC_RCBR,        KC_PIPE,        KC_AMPR,        KC_SLASH,       KC_TRNS,
    KC_TRNS,        KC_LPRN,        KC_RPRN,        KC_QUOTE,       KC_UNDS,        KC_DQUO,
    KC_TRNS,        KC_LBRACKET,    KC_RBRACKET,    KC_EXLM,        KC_AT,          KC_HASH,        KC_TRNS,
    KC_TRNS,        KC_PERC,        KC_LABK,        KC_RABK,        KC_EQUAL,
                                                                                                    RGB_MOD,        KC_TRNS,
                                                                                                                    KC_TRNS,
                                                                                    RGB_VAD,        RGB_VAI,        KC_TRNS,

    //right hand
    KC_TRNS,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRNS,        KC_UP,          KC_7,           KC_8,           KC_9,           KC_ASTR,        KC_F12,
                    KC_DOWN,        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_MINUS,
    TG(4),          KC_TRNS,        KC_1,           KC_2,           KC_3,           KC_BSLASH,      KC_ENTER,
                                    KC_0,        KC_DOT,         KC_TRNS,        KC_EQUAL,       KC_TRNS,
    KC_TRNS,                        KC_TRNS,
    KC_TRNS,
    KC_TRNS,        KC_TRNS,        KC_TRNS
  ),

  /* Keymap 3: Media and mouse keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |  BrUp  |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |  BrDn  |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      | Mclk |      |      |                                       |VolUp |VolDn | Mute |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |Brwser|Brwser|
   *                                 | WhDn | WhUp |------|       |------|Fwd   |Back  |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // MEDIA AND MOUSE
  [2] = LAYOUT_ergodox_pretty(
    //right hand
    KC_TRNS, KC_TRNS,         KC_TRNS,          KC_TRNS,              KC_TRNS,              KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,         KC_MS_BTN1,       KC_MS_UP,             KC_MS_BTN2,           KC_TRNS, KC_TRNS,
    KC_BRIU, KC_TRNS,         KC_MS_LEFT,       KC_MS_DOWN,           KC_MS_RIGHT,          KC_TRNS,
    KC_BRID, KC_TRNS,         KC_TRNS,          KC_TRNS,              KC_TRNS,              KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,         KC_MS_BTN3,       KC_TRNS,              KC_TRNS,
                                                                      KC_TRNS,              KC_TRNS,
                                                                                            KC_TRNS,
                                                KC_MS_WH_DOWN,        KC_MS_WH_UP,          KC_TRNS,

    //left hand
    KC_TRNS, KC_TRNS,         KC_TRNS,          KC_TRNS,              KC_TRNS,              KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,         KC_TRNS,          KC_TRNS,              KC_TRNS,              KC_TRNS, KC_TRNS,
             KC_TRNS,         KC_TRNS,          KC_TRNS,              KC_TRNS,              KC_TRNS, KC_MEDIA_PLAY_PAUSE,
    KC_TRNS, KC_TRNS,         KC_TRNS,          KC_MEDIA_PREV_TRACK,  KC_MEDIA_NEXT_TRACK,  KC_TRNS, KC_TRNS,
                              KC_AUDIO_VOL_UP,  KC_AUDIO_VOL_DOWN,    KC_AUDIO_MUTE,        KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_WWW_FORWARD,  KC_WWW_BACK
  ),

  /* Keymap 2: QWERTY layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   =    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|  LGui  |
   * |--------+------+------+------+------+------|LANG 1|           |LANG 2|------+------+------+------+------+--------|
   * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | PgUp |       | Home |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   | PgDn |       | End  |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [3] = LAYOUT_ergodox_pretty(
    //left hand
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                   KC_TRNS,
    KC_DELETE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                   KC_TRNS,
    KC_BSPACE,      KC_A,           KC_S,           KC_D,           KC_F,           KC_G,
    KC_LSPO,        CTL_T(KC_Z),    KC_X,           KC_C,           KC_V,           KC_B,                   KC_LANG1,
    KC_GRAVE,       KC_QUOTE,       KC_LSHIFT,      KC_LEFT,        KC_RIGHT,
                                                                                    ALT_T(KC_APPLICATION),  KC_LGUI,
                                                                                                            KC_PGUP,
                                                                    KC_SPACE,       KC_BSPACE,              KC_PGDOWN,

    //right hand
    KC_TRNS,        KC_6,           KC_7,           KC_8,           KC_9,           KC_0,                   KC_MINUS,
    KC_TRNS,        KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,                   KC_BSLASH,
                    KC_H,           KC_J,           KC_K,           KC_L,           LT(3,KC_SCOLON),        GUI_T(KC_QUOTE),
    KC_LANG2,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         RCTL_T(KC_SLASH),       KC_RSPC,
                                    KC_UP,          KC_DOWN,        KC_LBRACKET,    KC_RBRACKET,            MO(3),
    KC_LALT,        CTL_T(KC_ESCAPE),
    KC_HOME,
    KC_END,         KC_TAB,         KC_ENTER
  ),

  /* Keymap 4: Factorio
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   Esc  |      |      |      |      |   X  |  `   |           | BaseL|      |      |      |      |      | Tog AS |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |   Tab  | Space|   T  |  W   |  M   |   B  |      |           |      |      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Num +  |  E   |   A  |  S   |  D   |      |------|           |------|      |      |      |      |      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Num -  |Enter |      |      | LCtrl| Space|      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   | LAlt |      | Mclk |   C  |LShift|                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |   Z  |       |      |      |      |
   *                                 |   Q  |   R  |------|       |------|      |      |
   *                                 |      |      |   F  |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // FOR PLAYING FACTORIO
  [4] = LAYOUT_ergodox_pretty(
    //left hand
    KC_ESC,   KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,        KC_X,         KC_GRV,
    KC_TAB,   KC_SPC,   KC_T,       KC_W,     KC_M,           KC_B,         KC_TRNS,
    KC_PPLS,  KC_E,     KC_A,       KC_S,     KC_D,           KC_TRNS,
    KC_PMNS,  KC_ENTER, KC_TRNS,    KC_TRNS,  KC_LCTL,        KC_SPC,       KC_TRNS,
    KC_LALT,  KC_TRNS,  KC_MS_BTN3, KC_C,     KC_LSFT,
                                                            KC_TRNS,      KC_TRNS,
                                                                          KC_Z,
                                            KC_Q,           KC_R,         KC_F,

    //right hand
    TG(0),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTG,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /* Keymap 5: Gemini (Serial) Alternative
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |   #  |   #  |   #  |   #  |   #  |      |           | BaseL|   #  |   #  |   #  |   #  |   #  |   #    |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |   S  |   T  |   P  |   H  |   *  |      |           |      |   *  |   F  |   P  |   L  |   T  |   D    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |   S  |   K  |   W  |   R  |   *  |------|           |------|   *  |   R  |   B  |   G  |   S  |   Z    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |   A  |   O  |                                       |   E  |   U  |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      |      |      |
   *                                 |      |      |------|       |------|      |      |
   *                                 |      |      |      |       |      |      |      |
   *                                 `--------------------'       `--------------------'
   */
  // Gemini over Serial
  [5] = LAYOUT_ergodox(
         KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_NO,
         KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, KC_NO,
         KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
         KC_NO,   KC_NO,   KC_NO,   STN_A,   STN_O,
                                             KC_NO,   KC_NO,
                                                      KC_NO,
                                    KC_NO,   KC_NO,   KC_NO,
      // right hand
         TG(0),    STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
         KC_TRNS,  STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
                   STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
         KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                            STN_E,   STN_U,   KC_NO,   KC_NO,   KC_NO,
         KC_NO,   KC_NO,
         KC_NO,
         KC_NO,   KC_NO,   KC_NO
  ),
};

// Runs just one time when the keyboard initialises.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
};


bool suspended = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_led_all_set(15);
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
