#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define ONESHOT_TAP_TOGGLE 2

#define AUTO_SHIFT_TIMEOUT 130

#define FORCE_NKRO
#define RGBLIGHT_SLEEP

#define DRIVER_ADDR_1 0b1010000
#define DRIVER_ADDR_2 0b1010000 // this is here for compliancy reasons.

#define DRIVER_COUNT 1
#define DRIVER_1_LED_TOTAL 47
#define DRIVER_LED_TOTAL DRIVER_1_LED_TOTAL

#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_KEYREACTIVE_ENABLED
// #define RGB_MATRIX_CUSTOM_EFFECT_IMPLS
