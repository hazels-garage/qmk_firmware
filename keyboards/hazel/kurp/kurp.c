#include QMK_KEYBOARD_H
#include <stdio.h>



#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
  #ifdef OLED_DISPLAY_128X64
    return OLED_ROTATION_180;
  #else
    return rotation;
  #endif
}

#ifdef KEYCOUNT_ENABLE
  uint16_t keycount = 0;
  #define WPM_ROW 1
#else
  #define WPM_ROW 0
#endif

#ifdef KEYLOG_ENABLE
  char keylog_str[24] = {};
  char keylogs_str[21] = {};
  int keylogs_str_idx = 0;

  const char code_to_name[60] = {
      ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
      'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
      'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
      '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
      'R', 'E', 'B', 'T', 'X', '-', '=', 'X', 'X', '\\',
      'X', ';', '\'', '`', ',', '.', '/', 'X', 'X', 'X'};

  void set_keylog(uint16_t keycode, keyrecord_t *record) {
    char name = ' ';
    if (keycode < 60) {
      name = code_to_name[keycode];
    }

    // update keylog
    snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
            record->event.key.row, record->event.key.col,
            keycode, name);

    // update keylogs
    if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
      keylogs_str_idx = 0;
      for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
        keylogs_str[i] = ' ';
      }
    }

    keylogs_str[keylogs_str_idx] = name;
    keylogs_str_idx++;
  }

  const char *read_keylog(void) {
    return keylog_str;
  }

  const char *read_keylogs(void) {
    return keylogs_str;
  }
#endif

void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0, 0, 0,   0,   0,   0,   224, 224, 224, 224, 224, 224, 0,   0,   0,   0,   128, 224, 224, 224, 224, 224, 224, 96,  32,  224, 224, 224, 224, 224, 224, 0,   0,   0,   0,   0,   0,   224, 224, 224, 224, 224, 224, 0, 0, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 192, 128, 0, 0, 0, 0, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 224, 192, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0, 0, 0,   0,   0,   0,   255, 255, 255, 255, 255, 255, 224, 248, 252, 255, 255, 255, 63,  15, 7, 3, 0,   0,
        0,   255, 255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 255, 255, 255, 255, 255, 255, 129, 129, 129, 129, 195, 231, 255, 255, 255, 255, 255, 28,  0,   0,   255, 255, 255, 255, 255, 255, 129, 129, 129, 129, 131, 195, 255, 255, 255, 255, 255, 126, 0,   0,   0,   0, 0, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 255, 255, 255, 255, 255, 31, 15, 31, 127, 255, 255, 255, 252, 240, 224, 128, 0, 0, 63, 255, 255, 255, 255, 255, 224, 192, 128, 128, 192, 224, 255, 255, 255, 255, 255, 63, 0, 0, 255, 255, 255, 255, 255, 255, 7,   7,   7,   31,  255, 255, 255, 255, 251, 225, 128, 0,  0, 0, 255, 255,
        255, 255, 255, 255, 7,   7,   7,   7, 7, 7, 7, 7, 3, 3,   0,   0,   0,   0,   0,   0, 0, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 0, 0,   0,   0,   7,   7,   7,   7,   7,   7,   0,   0,   0,   0,   0,   3,   7,   7, 7, 7, 7, 6,   4,   0,   0,   1,   3,   3,   7,   7,   7,   7,   7,   7,   7,   7,   3,   3, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7,   7,   0,   0,   0,   0,   0,  3,  7,  7,   7,   7,   7,   6,   0,   0,   7,   7, 7, 7,  7,   7,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0, 0, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0, 0, 0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

bool oled_task_kb(void) {
  if (oled_task_user()) {


    uint8_t modifiers = get_mods() | get_oneshot_mods();

    // // mods
    oled_set_cursor(2, 7);
    oled_write_P(PSTR("SHIFT"), (modifiers & MOD_MASK_SHIFT) || is_caps_word_on());

    oled_set_cursor(8, 7);
    oled_write_P(PSTR("CTRL"), (modifiers & MOD_MASK_CTRL));

    oled_set_cursor(13, 7);
    oled_write_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));

    oled_set_cursor(17, 7);
    oled_write_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));

    #ifdef KEYLOG_ENABLE
      oled_set_cursor(0, 6);
      #ifdef KEYLOG_DEBUG
        oled_write(keylog_str, false);
      #else
        oled_write(keylogs_str, false);
      #endif
    #endif

    #ifdef WPM_ENABLE
      oled_set_cursor(18, WPM_ROW);
      uint8_t n = get_current_wpm();
      oled_write(get_u8_str(n, ' '), false);
    #endif

    #ifdef KEYCOUNT_ENABLE
      oled_set_cursor(16, 0);
      oled_write_P(get_u16_str(keycount, ' '), false);
    #endif

    oled_set_cursor(0, 2);
    render_logo();

  }
  return true;
}
#endif

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (process_record_user(keycode, record)) {
        if (record->event.pressed) {
            #ifdef KEYLOG_ENABLE
              set_keylog(keycode, record);
            #endif
            #ifdef KEYCOUNT_ENABLE
              if (keycount == 32768) keycount = 0;
              keycount++;
            #endif
        }
    }
    return true;
}