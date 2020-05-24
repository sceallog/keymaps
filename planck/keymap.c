#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_french.h"
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

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _PLOVER,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define ST_GEM  QK_STENO_GEMINI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Colemak-dh
   * ,-----------------------------------------------------------------------------------.
   * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Tab  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Steno| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
   [_BASE] = LAYOUT_planck_grid(
     KC_ESCAPE, KC_Q,     KC_W,     KC_F,     KC_P,   KC_B,     KC_J,   KC_L,   KC_U,     KC_Y,     KC_SCOLON,  KC_BSPACE,
     KC_TAB,    KC_A,     KC_R,     KC_S,     KC_T,   KC_G,     KC_K,   KC_N,   KC_E,     KC_I,     KC_O,       KC_QUOTE,
     KC_LSHIFT, KC_Z,     KC_X,     KC_C,     KC_D,   KC_V,     KC_M,   KC_H,   KC_COMMA, KC_DOT,   KC_SLASH,   KC_ENTER,
     TG(4),     OSM(MOD_LCTL), KC_LALT,  OSM(MOD_LGUI),  TT(1),  KC_SPACE, KC_NO,  TT(2),  KC_LEFT,  KC_DOWN,  KC_UP,      KC_RIGHT),

   /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |      |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Tab  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Steno| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
  [_LOWER] = LAYOUT_planck_grid(
    KC_TILD,    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,    KC_CIRC,  KC_P7, KC_P8,       KC_P9,     KC_PAST,    KC_TRNS,
    KC_DELETE,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_KANA,    KC_F6,    KC_P4, KC_P5,       KC_P6,     KC_PPLS,    KC_PIPE,
    KC_TRNS,    KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_HENK,    KC_F7,    KC_P1, KC_P2,       KC_P3,     KC_PMNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_NO,    KC_P0, KC_PDOT,     KC_JYEN,   KC_PSLS,    KC_NLCK),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Steno| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
  [_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE,   KC_1,           KC_2,       KC_3,       KC_4,        KC_5,    KC_6,  KC_7,          KC_8,            KC_9,                KC_0,                KC_TRNS,
    KC_DELETE,  KC_MS_WH_UP,    KC_MS_BTN2, KC_MS_UP,   KC_MS_BTN1,  KC_PGUP, KC_HOME, KC_MINUS,      KC_EQUAL,        KC_LBRACKET,         KC_RBRACKET,         KC_BSLASH,
    KC_TRNS,    KC_MS_WH_DOWN,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_PGDN, KC_END, KC_NONUS_HASH, KC_NONUS_BSLASH, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRNS,
    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_NO, KC_TRNS,       KC_TRNS,         KC_AUDIO_VOL_DOWN,   KC_AUDIO_VOL_UP,     KC_MEDIA_PLAY_PAUSE),

    /* Colemak-dh
     * ,-----------------------------------------------------------------------------------.
     * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Tab  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Steno| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
  [_ADJUST] = LAYOUT_planck_grid(
    KC_TRNS,    KC_TRNS,  KC_BRIGHTNESS_DOWN,  KC_BRIGHTNESS_UP,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_DELETE,  KC_TRNS,  AU_ON,               AU_OFF,            AU_TOG,   KC_TRNS,  KC_TRNS,  RGB_TOG,  RGB_VAI,  RGB_VAD,  KC_TRNS,  RESET,
    KC_TRNS,    KC_TRNS,  MU_ON,               MU_OFF,            MU_TOG,   KC_TRNS,  KC_TRNS, RGB_MOD,  RGB_HUI,  RGB_HUD,  LED_LEVEL, BL_BRTG,
    KC_TRNS,    KC_TRNS,  KC_TRNS,             KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_NO,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_ASTG),

  /* Plover layer (http://opensteno.org)
   * ,-----------------------------------------------------------------------------------.
   * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | (FN) |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Exit |      |      |   A  |   O  |             |   E  |   U  | (PWR)|(RES1)|(RES2)|
   * `-----------------------------------------------------------------------------------'
   */
  [_PLOVER] = LAYOUT_planck_grid(
    STN_N1,   STN_N2,   STN_N3,   STN_N4, STN_N5, STN_N6,   STN_N7,   STN_N8, STN_N9, STN_NA,   STN_NB,   STN_NC,
    KC_TRNS,  STN_S1,   STN_TL,   STN_PL, STN_HL, STN_ST1,  STN_ST3,  STN_FR, STN_PR, STN_LR,   STN_TR,   STN_DR,
    KC_TRNS,  STN_S2,   STN_KL,   STN_WL, STN_RL, STN_ST2,  STN_ST4,  STN_RR, STN_BR, STN_GR,   STN_SR,   STN_ZR,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  STN_A,  STN_O,  KC_NO,    KC_NO,    STN_E,  STN_U,  KC_TRNS,  KC_TRNS,  KC_TRNS),

};

// Runs just one time when the keyboard initialises.
void matrix_init_user() {
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

       void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,255,255}, {11,176,255}, {28,255,255}, {43,255,255}, {64,255,255}, {85,255,255}, {85,255,255}, {128,255,128}, {128,255,255}, {132,102,255}, {170,255,255}, {191,255,255},
            {0,255,255}, {11,176,255}, {28,255,255}, {43,255,255}, {234,128,255},    {85,255,255}, {85,255,255}, {234,128,255},     {128,255,255}, {132,102,255}, {170,255,255}, {191,255,255},
            {0,255,255}, {11,176,255}, {28,255,255}, {43,255,255}, {64,255,255}, {85,255,255}, {85,255,255}, {128,255,128}, {128,255,255}, {132,102,255}, {170,255,255}, {191,255,255},
            {0,255,255}, {11,176,255}, {28,255,255}, {43,255,255}, {64,255,255}, {85,255,255},               {128,255,128}, {128,255,255}, {132,102,255}, {170,255,255}, {191,255,255} },

    [1] = { {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,255,255}, {0,255,255}, {0,255,255}, {32,255,234}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {43,255,255}, {14,222,242}, {0,255,255}, {0,255,255}, {0,255,255}, {32,255,234}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {43,255,255}, {14,222,242}, {0,255,255}, {0,255,255}, {0,255,255}, {32,255,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,255,255}, {32,255,234}, {170,255,255}, {32,255,234}, {0,255,255} },

    [2] = { {146,224,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {106,255,255}, {106,255,255}, {106,255,255}, {146,224,255}, {146,224,255}, {191,255,255}, {191,255,255}, {191,255,255}, {191,255,255}, {191,255,255}, {0,0,0}, {64,255,255}, {106,255,255}, {106,255,255}, {106,255,255}, {146,224,255}, {146,224,255}, {191,255,255}, {191,255,255}, {128,255,255}, {128,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {128,255,255}, {128,255,255}, {128,255,255} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {128,255,128}, {128,255,128}, {128,255,128}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,0}, {0,255,255}, {0,0,0}, {0,0,0}, {132,102,255}, {132,102,255}, {132,102,255}, {0,0,0}, {0,0,0}, {31,255,255}, {31,255,255}, {31,255,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {106,255,255} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0, 255, 255}, {28, 255, 255}, {43, 255, 255}, {85, 255, 255}, {128, 255, 128}, {128, 255, 128}, {106, 255, 255}, {85, 255, 255}, {43, 255, 255}, {28, 255, 255}, {0, 255, 255}, {0,0,0}, {0, 255, 255}, {28, 255, 255}, {43, 255, 255}, {85, 255, 255}, {128, 255, 128}, {128, 255, 128}, {106, 255, 255}, {85, 255, 255}, {43, 255, 255}, {28, 255, 255}, {0, 255, 255}, {0,0,0}, {0,0,0}, {0,0,0}, {170, 255, 255}, {170, 255, 255}, {0,0,0}, {170, 255, 255}, {170, 255, 255}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

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

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
