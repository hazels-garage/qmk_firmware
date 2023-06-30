#include "quantum.h"
#include "cut_slope.h"
#include "display.h"

#include "qp.h"
#include "fonts/roboto14.qff.h"
#include "fonts/urbanist36.qff.h"
// #include "qp_lvgl.h"
// #include "fonts/rb_24.c"

kb_runtime_config kb_state;

static painter_device_t display;
static painter_font_handle_t roboto14;
static painter_font_handle_t urbanist36;
// roboto14 = qp_load_font_mem(font_roboto14);


void keyboard_post_init_user(void) {
  display = qp_st7735_make_spi_device(240, 320, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 8, 3);
  urbanist36 = qp_load_font_mem(font_urbanist36);
  roboto14 = qp_load_font_mem(font_roboto14);
  
  qp_init(display, QP_ROTATION_180);
  qp_power(display, true);

  qp_rect(display, 0, 0, 240, 320, 99, 64, 255, true);
  
  // draw name
  static const char *text = " Cut Slope ";
  int16_t width = qp_textwidth(urbanist36, text);
  qp_drawtext_recolor(display, (240 - width) / 2, (319 - urbanist36->line_height - 10), urbanist36, text, 99, 64, 255, 0, 0, 0);

  static const char *row1 = "Cut Slope v0.0";
  static const char *row2 = "Jason Hazel";
  static const char *row3 = "shop.hazel.cc";
  // static const char *keys4 = "ctl sym sft   spc num ent";
  int16_t row1_width = qp_textwidth(roboto14, row1);
  int16_t row2_width = qp_textwidth(roboto14, row2);
  int16_t row3_width = qp_textwidth(roboto14, row3);

  qp_drawtext_recolor(display, (240 - row1_width)/2,roboto14->line_height, roboto14, row1, 0,0,0, 99, 64, 255);
  qp_drawtext_recolor(display, (240 - row2_width)/2, 2 * roboto14->line_height, roboto14, row2, 0,0,0, 99, 64, 255);
  qp_drawtext_recolor(display, (240 - row3_width)/2, 3 * roboto14->line_height, roboto14, row3, 0, 0, 0, 99, 64, 255);
  // qp_drawtext_recolor(display, (240 - keys1_width)/2, 5 * roboto14->line_height, roboto14, keys4, 0, 0, 0, 99, 64, 255);
}

void housekeeping_task_user(void) {
    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 500) { // Throttle to 30fps
        last_draw = timer_read32();
        // Draw 8px-wide rainbow down the left side of the display
        // oled_write(get_u8_str(n, ' '), false);

        static const char *wpmLabel = "WPM";
        int16_t wpmLabel_width = qp_textwidth(urbanist36, wpmLabel);
        qp_drawtext_recolor(display, (240 - wpmLabel_width)/2, (320 - urbanist36->line_height)/3, urbanist36, wpmLabel, 0,0,0, 99,64,255);

        char wpm[64] = {0};
        snprintf(wpm, sizeof(wpm), "  %d  ", (int)get_current_wpm());
        int16_t wpm_width = qp_textwidth(urbanist36, wpm);

        qp_drawtext_recolor(display, (240 - wpm_width)/2, (320 - urbanist36->line_height)/3 + urbanist36->line_height, urbanist36, wpm, 0,0,0, 99,64,255);


        qp_flush(display);
    }
}

void board_init(void) {}