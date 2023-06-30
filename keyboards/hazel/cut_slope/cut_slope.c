#include "quantum.h"
#include "cut_slope.h"
#include "display.h"

#include "qp.h"
#include "fonts/urbanist24.qff.h"
#include "fonts/urbanist36.qff.h"
// #include "qp_lvgl.h"
// #include "fonts/rb_24.c"

kb_runtime_config kb_state;

static painter_device_t display;
// static painter_font_handle_t urbanist24;
static painter_font_handle_t urbanist36;
// urbanist24 = qp_load_font_mem(font_urbanist24);


void keyboard_post_init_user(void) {
  display = qp_st7735_make_spi_device(240, 320, DISPLAY_CS_PIN, DISPLAY_DC_PIN, DISPLAY_RST_PIN, 8, 3);
  urbanist36 = qp_load_font_mem(font_urbanist36);
  
  qp_init(display, QP_ROTATION_180);
  qp_power(display, true);

  qp_rect(display, 0, 0, 240, 320, 99, 64, 255, true);
  static const char *text = " Cut Slope ";
  int16_t width = qp_textwidth(urbanist36, text);
  // qp_drawtext(display, (240 - width)/2, 0, urbanist, text);
  qp_drawtext_recolor(display, (240 - width) / 2, (319 - urbanist36->line_height - 10), urbanist36, text, 99, 64, 255, 0, 0, 0);
  // if (qp_lvgl_attach(display)) { // Attach LVGL to the display
  //     wait_ms(50);
  //     display_init();
  // }
}

void housekeeping_task_user(void) {
    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 500) { // Throttle to 30fps
        last_draw = timer_read32();





        qp_flush(display);
    }
}
// 
void board_init(void) {}