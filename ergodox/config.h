/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#define FORCE_NKRO /* Enables NKRO. */

// overrides
#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2 /* Defines number of times key needs to be pressed to continuously switch to given layer.*/

#pragma once

#define AUTO_SHIFT_TIMEOUT 130
