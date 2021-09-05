#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_french.h"
#include "keymap_jp.h"
#include "keymap_steno.h"



// #define KC_MAC_UNDO LGUI(KC_Z)
// #define KC_MAC_CUT LGUI(KC_X)
// #define KC_MAC_COPY LGUI(KC_C)
// #define KC_MAC_PASTE LGUI(KC_V)
// #define KC_PC_UNDO LCTL(KC_Z)
// #define KC_PC_CUT LCTL(KC_X)
// #define KC_PC_COPY LCTL(KC_C)
// #define KC_PC_PASTE LCTL(KC_V)
// #define ES_LESS_MAC KC_GRAVE
// #define ES_GRTR_MAC LSFT(KC_GRAVE)
// #define ES_BSLS_MAC ALGR(KC_6)
// #define NO_PIPE_ALT KC_GRAVE
// #define NO_BSLS_ALT KC_EQUAL

#define WM_PREV LCAG(KC_LEFT)
#define WM_FULL LCA(KC_ENTER)
#define WM_NEXT LCAG(KC_RIGHT)
#define WM_NW LCA(KC_U)
#define WM_N LCA(KC_UP)
#define WM_NE LCA(KC_I)
#define WM_W LCA(KC_LEFT)
#define WM_CNTR LCA(KC_C)
#define WM_E LCA(KC_RIGHT)
#define WM_SW LCA(KC_J)
#define WM_S LCA(KC_DOWN)
#define WM_SE LCA(KC_K)
#define WM_RSTR LCA(KC_BSPC)
#define WM_LRG LCA(KC_EQUAL)
#define WM_SMLL LCA(KC_MINS)

#define BASE_COLEMAK_LAYER 0
#define QWERTY_LAYER 1
#define STENO_LAYER 2
#define LOWER_LAYER 3
#define RAISE_LAYER 4
#define NAVIGATION_LAYER 5
#define GUI_LAYER 6
#define KEYBOARD_LAYER 7


enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  QWERTY = SAFE_RANGE,
  QWRTOFF,
  COLEMAK,
  ENT_PLV,
  EXT_PLV,
  // BACKLIT
};

// enum planck_layers {
//   _BASE,
//   _LOWER,
//   _RAISE,
//   _ADJUST,
//   _PLOVER,
// };

#define LOWER MO(LOWER_LAYER)
#define RAISE MO(RAISE_LAYER)

#define ST_GEM  QK_STENO_GEMINI

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Colemak-dh
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |Esc/Ctl|   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  | Shift|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | [/L6 |Hyp/{ |Alt/< | GUI  |Lower |    Space    |Raise | Enter|Sgui/>| }/L5 | ]/L6 |
   * `-----------------------------------------------------------------------------------'
   */
   [BASE_COLEMAK_LAYER] = LAYOUT_planck_grid(
     KC_TAB,            KC_Q,           KC_W,           KC_F,          KC_P,   KC_B,     KC_J,   KC_L,      KC_U,     KC_Y,           KC_SCOLON,            KC_BSPC,
     LCTL_T(KC_ESC),    KC_A,           KC_R,           KC_S,          KC_T,   KC_G,     KC_K,   KC_N,      KC_E,     KC_I,           KC_O,                 KC_QUOTE,
     KC_LSPO,           KC_Z,           KC_X,           KC_C,          KC_D,   KC_V,     KC_M,   KC_H,      KC_COMMA, KC_DOT,         KC_SLASH,             KC_RSPC,
     LT(6, KC_LBRC),    ALL_T(KC_LCBR), ALT_T(KC_LT),  OSM(MOD_LGUI),  TT(3),  KC_SPACE, KC_NO,  TT(4),     KC_ENT,   SGUI(KC_GT),    LT(5, KC_RCBR),       LT(6, KC_RBRC)),

  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |Esc/Ctl|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | [/L6 |Hyp/{ |Alt/< | GUI  |Lower |    Space    |Raise | Enter|QWRTOf| }/L5 | ]/L6 |
   * `-----------------------------------------------------------------------------------'
   */
   [QWERTY_LAYER] = LAYOUT_planck_grid(
     KC_TAB,          KC_Q,           KC_W,           KC_E,           KC_R,     KC_T,     KC_Y,   KC_U,   KC_I,     KC_O,           KC_P,           _______,
     LCTL_T(KC_ESC),  KC_A,           KC_S,           KC_D,           KC_F,     KC_G,     KC_H,   KC_J,   KC_K,     KC_L,           KC_SCOLON,      KC_QUOTE,
     KC_LSPO,         KC_Z,           KC_X,           KC_C,           KC_V,     KC_B,     KC_N,   KC_M,   KC_COMMA, KC_DOT,         KC_SLASH,       KC_RSPC,
     LT(6, KC_LBRC),  ALL_T(KC_LCBR), ALT_T(KC_LT),   OSM(MOD_LGUI),  TT(3),    KC_SPACE, KC_NO,  TT(4),  KC_ENT,   QWRTOFF,   LT(5, KC_RCBR), LT(6, KC_RBRC)),

  /* Plover layer (http://opensteno.org)
   * ,-----------------------------------------------------------------------------------.
   * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * |   S  |   T  |   P  |   H  |   *  |  FN  |   *  |   F  |   P  |   L  |   T  |   D  |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * |   S  |   K  |   W  |   R  |   *  |      |   *  |   R  |   B  |   G  |   S  |   Z  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Exit |      |      |   A  |   O  |          E  |   U  | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [STENO_LAYER] = LAYOUT_planck_grid(
    STN_N1,   STN_N2,   STN_N3,   STN_N4, STN_N5,  STN_N6,   STN_N7,   STN_N8, STN_N9, STN_NA,   STN_NB,   _______,
    STN_S1,   STN_TL,   STN_PL,   STN_HL, STN_ST1, STN_FN,   STN_ST3,  STN_FR, STN_PR, STN_LR,   STN_TR,   STN_DR,
    STN_S2,   STN_KL,   STN_WL,   STN_RL, STN_ST2, KC_NO,    STN_ST4,  STN_RR, STN_BR, STN_GR,   STN_SR,   STN_ZR,
    EXT_PLV,  KC_NO,    KC_NO,    STN_A,  STN_O,   STN_E,    KC_NO,    STN_U,  KC_LEFT,KC_DOWN,  KC_UP,    KC_RIGHT),

   /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |  ~   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Pg Up|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | NP 4 | NP 5 | NP 6 |   +  |  *   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Pg Dn|  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | NP 1 | NP 2 | NP 3 |   -  |   \  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | End  | Home |      |      |      |    Lead     | NP 0 | NP . | NP , |  Tab | Enter|
    * `-----------------------------------------------------------------------------------'
    */
  [LOWER_LAYER] = LAYOUT_planck_grid(
    KC_TILD,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,       KC_6,     KC_7,  KC_8,      KC_9,      KC_0,       _______,
    KC_PGUP,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,      KC_F6,    KC_P4, KC_P5,     KC_P6,     KC_PPLS,    KC_PAST,
    KC_PGDN,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_P1, KC_P2,     KC_P3,     KC_PMNS,    KC_PSLS,
    KC_END,     KC_HOME,  _______,  _______,  _______,  KC_LEAD,    KC_NO,    KC_P0, KC_PDOT,   KC_COMMA,  KC_ENT,     KC_TAB),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |      |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   '  |   "  |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |   -  |   =  |   `  |   \  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |  Del |    XXXXX    |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
  [RAISE_LAYER] = LAYOUT_planck_grid(
    _______,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,    _______,    _______,   _______,
    _______,   KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,   KC_QUOT,    KC_DQUO,    _______,
    _______,   KC_MINS,  KC_EQL,   KC_GRV,   KC_BSLS,  _______,  _______,  _______,  _______,   _______,    _______,    _______,
    _______,   _______,  _______,  _______,  _______,  KC_DEL,   KC_NO,    _______,  _______,   _______,    _______,    _______),

/* Navigation
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |  Up  |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      | Home | Pg Up| Pg Dn|  End |      | Left | Down | Right|      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |    XXXXX    |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
  [NAVIGATION_LAYER] = LAYOUT_planck_grid(
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_UP,    _______,  _______,  _______,
    _______,    _______,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   _______,  KC_LEFT,  KC_DOWN,  KC_RIGHT, _______,  _______,
    _______,    _______,  _______,  _______,  _______,  _______,  KC_NO,    _______,  _______,  _______,  _______,  _______),

  /* GUI & Mouse
     * ,-----------------------------------------------------------------------------------.
     * |      |Whl Up|RClick|Ms Up |LClick|      |      | PREV |WM NW | WM N |WM NE |RESTOR|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |Whl Dn|Ms Le |Ms Dn |Ms Rg |      |      | FULL | WM W |CENTRE| WM E |LARGE |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |Whl Le|Md Btn|Whl Rg|      |      | NEXT |WM SW | WM S |WM SE |SMALL |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      | Prev | Play | Next |Bri Up|    Sleep    |Bri Dn| Mute |Vol Dn|Vol Up|      |
     * `-----------------------------------------------------------------------------------'
     */
  [GUI_LAYER] = LAYOUT_planck_grid(
    _______,    KC_WH_U,  KC_BTN2,  KC_MS_U,  KC_BTN1,  _______,  _______,  WM_PREV,  WM_NW,    WM_N,     WM_NE,    WM_RSTR,
    _______,    KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_R,  _______,  _______,  WM_FULL,  WM_W,     WM_CNTR,  WM_E,     WM_LRG,
    _______,    _______,  KC_WH_L,  KC_BTN3,  KC_WH_R,  _______,  _______,  WM_NEXT,  WM_SW,    WM_S,     WM_SE,    WM_SMLL,
    _______,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_BRID,  KC_SLEP,  KC_NO,    KC_BRIU,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______),

    /* Keyboard adjustment
     * ,-----------------------------------------------------------------------------------.
     * |      | Reset|      |AutSft|      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      | CLMK | QWRT |  PLV |AU Tgl|      |      |RGBTgl|Val + |Val - |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |Mus On|MusOff|MusTgl|      |      |RGBMod|Hue + |Hue - |LED Lv|BL Bri|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |    XXXXX    |      |RGBPln| Down |RGB Kn|      |
     * `-----------------------------------------------------------------------------------'
     */
  [KEYBOARD_LAYER] = LAYOUT_planck_grid(
    _______,    RESET,    _______,  KC_ASTG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,
    _______,    COLEMAK,  QWERTY,   ENT_PLV,  AU_TOG,   _______,  _______,  RGB_TOG,  RGB_VAI,  RGB_VAD,  _______,    _______,
    _______,    _______,  MU_ON,    MU_OFF,   MU_TOG,   _______,  _______,  RGB_MOD,  RGB_HUI,  RGB_HUD,  LED_LEVEL,  BL_BRTG,
    _______,    _______,  _______,  _______,  _______,  _______,  KC_NO,    _______,  RGB_M_P,  RGB_M_B,  RGB_M_K,    _______),



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
    // Colemak
    [0] = { {132,102,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {128,255,255}, {128,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {132,102,255},
            {132,102,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255},{170,255,255}, {128,255,255}, {170,255,255},  {170,255,255}, {170,255,255}, {170,255,255}, {132,102,255},
            {132,102,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {128,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {132,102,255},
            {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255},               {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255} },

    // Qwerty
    [1] = { {132,102,255}, {85,255,255}, {0,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {85,255,255}, {132,102,255},
            {132,102,255}, {0,255,255}, {0,255,255}, {0,255,255}, {170,255,255},{170,255,255}, {170,255,255}, {170,255,255},  {170,255,255}, {170,255,255}, {170,255,255}, {132,102,255},
            {132,102,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {28,255,255}, {132,102,255},
            {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255},               {132,102,255}, {132,102,255}, {128,255,255}, {132,102,255}, {132,102,255} },

    // Steno
    [2] = { {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128}, {128, 255, 128},
    {85, 255, 255}, {85, 255, 255}, {85, 255, 255}, {85, 255, 255}, {128, 255, 128}, {0, 0, 0}, {128, 255, 128}, {85, 255, 255}, {85, 255, 255}, {85, 255, 255}, {85, 255, 255}, {85, 255, 255},
    {28, 255, 255}, {28, 255, 255}, {28, 255, 255}, {28, 255, 255}, {128, 255, 128}, {0, 0, 0}, {128, 255, 128}, {28, 255, 255}, {28, 255, 255}, {28, 255, 255}, {28, 255, 255}, {28, 255, 255},
    {0,0,0}, {0,0,0}, {0,0,0}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {170, 255, 255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255} },

    // Lower
    [3] = { {170,255,255},  {170,255,255},  {170,255,255},  {170,255,255},  {170,255,255},  {170,255,255},    {170,255,255},    {0,255,255}, {0,255,255},   {0,255,255},    {170,255,255}, {132,102, 255},
            {128,255,255},    {132,102,255},  {132,102,255},  {132,102,255},  {132,102,255},  {132,102,255}, {132,102,255}, {0,255,255}, {0,255,255},   {0,255,255},    {32,255,234}, {32,255,234},
            {128,255,255},    {132,102,255},  {132,102,255},  {132,102,255},  {132,102,255},  {132,102,255}, {132,102,255}, {0,255,255}, {0,255,255},   {0,255,255},    {32,255,234}, {32,255,234},
            {128,255,255},    {128,255,255},    {0,0,0},    {0,0,0},    {132,102,255},    {85,255,255},                    {0,255,255}, {32,255,234},  {32,255,234},  {132,102,255}, {132,102,255} },

    // Raise
    [4] = { {0,0,0}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {132,102,255}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,0},
            {0,0,0}, {170,255,255}, {170,255,255}, {170,255,255}, {170,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {132,102,255},                             {132,102,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    // Navigation
    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
    {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0, 0, 0}, {0,0,0}, {0,0,0}, {85, 255, 255}, {0,0,0}, {0,0,0}, {0,0,0},
    {0,0,0}, {0,0,0}, {128,255,255}, {32,255,234}, {32,255,234}, {128,255,255}, {0,0,0}, {85,255,255}, {85,255,255}, {85,255,255}, {0,0,0}, {0,0,0},
    {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {132,102,255}, {0,0,0} },

    // GUI
    [6] = { {0,0,0},  {32,255,234},  {170,255,255},  {85,255,255},  {170,255,255},  {0,0,0}, {0,0,0}, {28,255,255},    {85,255,255}, {85,255,255}, {85,255,255}, {28,255,255},
            {0,0,0},        {32,255,234},   {85,255,255},  {85,255,255},  {85,255,255},  {0,0,0}, {0,0,0}, {28,255,255},    {85,255,255}, {85,255,255}, {85,255,255}, {28,255,255},
            {0,0,0},        {0,0,0},   {32,255,234},  {170,255,255},  {32,255,234},  {0,0,0}, {0,0,0}, {28,255,255},    {85,255,255}, {85,255,255}, {85,255,255}, {28,255,255},
            {132,102,255},        {128,255,255},        {85,255,255},        {128,255,255},        {132,102,255},        {0,255,255},                      {132,102,255}, {128,255,255}, {128,255,255}, {128,255,255}, {132,102,255} },

    // Keyboard
    [7] = { {0,0,0}, {0, 255, 255}, {0,0,0}, {132,102,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
    {0,0,0}, {85, 255, 255}, {128,255,255}, {191, 255, 255}, {0,0,0}, {0, 0, 0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
    {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0, 0, 0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
    {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },
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
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;
float plover_song[][2]     = SONG(PLOVER_SOUND);
float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(RAISE_LAYER)) {
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

LEADER_EXTERNS();

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

  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

		// Vim: write.
    SEQ_ONE_KEY(KC_W) {
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      SEND_STRING(":w");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
		// Vim: quit.
    SEQ_ONE_KEY(KC_Q) {
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      SEND_STRING(":q");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
		// Tmux: split pane vertically.
		SEQ_ONE_KEY(KC_V) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_V);
			unregister_code(KC_V);
		}
		// Tmux: split pane horizontally.
		SEQ_ONE_KEY(KC_H) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_H);
			unregister_code(KC_H);
		}
		// Tmux: zoom into/out of current pane.
		SEQ_ONE_KEY(KC_Z) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_Z);
			unregister_code(KC_Z);
		}
		// Tmux: create new window.
		SEQ_ONE_KEY(KC_C) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_C);
			unregister_code(KC_C);
		}
		// Tmux: move to previous window.
		SEQ_ONE_KEY(KC_P) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_P);
			unregister_code(KC_P);
		}
		// Tmux: move to next window.
		SEQ_ONE_KEY(KC_N) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_N);
			unregister_code(KC_N);
		}
		// Tmux: kill current window.
		SEQ_ONE_KEY(KC_K) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_LSFT);
			register_code(KC_7);
			unregister_code(KC_7);
			unregister_code(KC_LSFT);
		}
		// Tmux: disconnect current session.
		SEQ_ONE_KEY(KC_D) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_D);
			unregister_code(KC_D);
		}
		// Tmux: show session list.
		SEQ_ONE_KEY(KC_S) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_S);
			unregister_code(KC_S);
		}
		// Tmux: move to left pane.
		SEQ_ONE_KEY(KC_LEFT) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_LEFT);
			unregister_code(KC_LEFT);
		}
		// Tmux: move to right pane.
		SEQ_ONE_KEY(KC_RGHT) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_RGHT);
			unregister_code(KC_RGHT);
		}
		// Tmux: move to lower pane.
		SEQ_ONE_KEY(KC_DOWN) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_DOWN);
			unregister_code(KC_DOWN);
		}
		// Tmux: move to upper pane.
		SEQ_ONE_KEY(KC_UP) {
			register_code(KC_LCTL);
			register_code(KC_B);
			unregister_code(KC_B);
			unregister_code(KC_LCTL);
			register_code(KC_UP);
			unregister_code(KC_UP);
		}
		// Vim: search and replace all.
    SEQ_TWO_KEYS(KC_S, KC_R) {
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      SEND_STRING(":%s/old/new/g");
    }
		// Vim: write and quit.
    SEQ_TWO_KEYS(KC_W, KC_Q) {
      register_code(KC_ESC);
      unregister_code(KC_ESC);
      SEND_STRING(":wq");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    }
		// VSCode: close all tabs.
    SEQ_TWO_KEYS(KC_K, KC_W) {
      register_code(KC_LGUI);
      register_code(KC_K);
      unregister_code(KC_K);
      unregister_code(KC_LGUI);
      register_code(KC_W);
      unregister_code(KC_W);
    }
  }
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
    return update_tri_layer_state(state, LOWER_LAYER, RAISE_LAYER, KEYBOARD_LAYER);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case RGB_SLD:
    //   if (record->event.pressed) {
    //     rgblight_mode(1);
    //   }
    //   return false;
    //   break;
    case QWERTY:
      if (!record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(QWERTY_LAYER);
      }
      return false;
      break;
    case QWRTOFF:
      if (record ->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(QWERTY_LAYER);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        default_layer_set(BASE_COLEMAK_LAYER);
      }
      return false;
      break;
    // case BACKLIT:
    //   if (record->event.pressed) {
    //     register_code(KC_RSFT);
    //     #ifdef BACKLIGHT_ENABLE
    //       backlight_step();
    //     #endif
    //   } else {
    //     unregister_code(KC_RSFT);
    //   }
    //   return false;
    //   break;
    case ENT_PLV:
      if (!record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
        #endif
        layer_on(STENO_LAYER);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(STENO_LAYER);
      }
      return false;
      break;
  }
  return true;
}
