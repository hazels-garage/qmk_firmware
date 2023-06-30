#include "display.h"
#include "quantum.h"
#include "layers.h"
#include <ctype.h>

lv_obj_t* mbox1;
lv_obj_t* mbox1_title;
lv_obj_t* mbox1_text;
lv_obj_t* ui_Screen;



// lv_obj_t* ui_Screen_deflayer;
// lv_obj_t* ui_Screen_layout;
// lv_obj_t* ui_Screen_Label_ALTMOD;
// lv_obj_t* ui_Screen_Label_CMDMOD;
// lv_obj_t* ui_Screen_Label_SHIFTMOD;
// lv_obj_t* ui_Screen_Label_CTRLMOD;
// lv_obj_t* ui_Layer_Indicator;
// lv_obj_t* ui_Screen_deflayer_list;

// lv_obj_t* ui_Screen2;
// lv_obj_t* ui_Image1;

#define MODS_SHIFT ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT)
#define MODS_CTRL ((get_mods() | get_oneshot_mods()) & MOD_MASK_CTRL)
#define MODS_ALT ((get_mods() | get_oneshot_mods()) & MOD_MASK_ALT)
#define MODS_GUI ((get_mods() | get_oneshot_mods()) & MOD_MASK_GUI)

// uint8_t USER_EVENT_CPI_UPDATE           = 0;
// uint8_t USER_EVENT_ACTIVE_LAYER_CHANGE  = 1;
// uint8_t USER_EVENT_CAPS_WORD_UPDATE     = 2;
// // uint8_t USER_EVENT_POINTING_MODE_UPDATE = 5;
// // uint8_t USER_EVENT_RGBMODE_UPDATE       = 6;
// uint8_t USER_EVENT_ALTMOD               = 7;
// uint8_t USER_EVENT_CMDMOD               = 8;
// uint8_t USER_EVENT_SHIFTMOD             = 9;
// uint8_t USER_EVENT_CTRLMOD              = 10;





void ui_screen_init(void) {
    ui_Screen = lv_obj_create(NULL);

    // ui_Layer_Indicator = lv_img_create(ui_Screen);
    // lv_obj_add_event_cb(ui_Layer_Indicator, ui_active_layer_change, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);
    // lv_obj_set_width(ui_Layer_Indicator, LV_SIZE_CONTENT);  /// 81
    // lv_obj_set_height(ui_Layer_Indicator, LV_SIZE_CONTENT); /// 55
    // lv_obj_set_x(ui_Layer_Indicator, 25);
    // lv_obj_set_y(ui_Layer_Indicator, -25);
    // lv_obj_set_align(ui_Layer_Indicator, LV_ALIGN_LEFT_MID);
    // lv_obj_add_flag(ui_Layer_Indicator, LV_OBJ_FLAG_ADV_HITTEST); /// Flags
    // lv_obj_clear_flag(ui_Layer_Indicator, LV_OBJ_FLAG_SCROLLABLE);
    // lv_event_send(ui_Layer_Indicator, USER_EVENT_ACTIVE_LAYER_CHANGE, NULL);



    // ui_Screen_layout = lv_label_create(ui_Screen);
    // lv_obj_set_width(ui_Screen_layout, 100);
    // lv_obj_set_style_text_font(ui_Screen_layout, &rb_24, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_x(ui_Screen_layout, 40);
    // lv_obj_set_y(ui_Screen_layout, 95);
    // lv_obj_add_event_cb(ui_Screen_layout, ui_render_layout, USER_EVENT_LAYOUT_UPDATE, NULL);
    // lv_event_send(ui_Screen_layout, USER_EVENT_LAYOUT_UPDATE, NULL);

    // ui_Screen_Label_ALTMOD = lv_img_create(ui_Screen);
    // lv_obj_set_width(ui_Screen_Label_ALTMOD, LV_SIZE_CONTENT);  /// 81
    // lv_obj_set_height(ui_Screen_Label_ALTMOD, LV_SIZE_CONTENT); /// 55
    // lv_obj_set_x(ui_Screen_Label_ALTMOD, -20);
    // lv_obj_set_y(ui_Screen_Label_ALTMOD, -50);
    // lv_obj_set_align(ui_Screen_Label_ALTMOD, LV_ALIGN_RIGHT_MID);
    // // lv_img_set_src(ui_Screen_Label_ALTMOD, &alt);
    // lv_obj_add_event_cb(ui_Screen_Label_ALTMOD, ui_render_altmod, USER_EVENT_ALTMOD, NULL);
    // lv_event_send(ui_Screen_Label_ALTMOD, USER_EVENT_ALTMOD, NULL);

    // ui_Screen_Label_CMDMOD = lv_img_create(ui_Screen);
    // lv_obj_set_width(ui_Screen_Label_CMDMOD, LV_SIZE_CONTENT);  /// 81
    // lv_obj_set_height(ui_Screen_Label_CMDMOD, LV_SIZE_CONTENT); /// 55
    // lv_obj_set_x(ui_Screen_Label_CMDMOD, -20);
    // lv_obj_set_y(ui_Screen_Label_CMDMOD, -23);
    // lv_obj_set_align(ui_Screen_Label_CMDMOD, LV_ALIGN_RIGHT_MID);
    // // lv_img_set_src(ui_Screen_Label_CMDMOD, &cmd);
    // lv_obj_add_event_cb(ui_Screen_Label_CMDMOD, ui_render_cmdmod, USER_EVENT_CMDMOD, NULL);
    // lv_event_send(ui_Screen_Label_CMDMOD, USER_EVENT_CMDMOD, NULL);

    // ui_Screen_Label_SHIFTMOD = lv_img_create(ui_Screen);
    // lv_obj_set_width(ui_Screen_Label_SHIFTMOD, LV_SIZE_CONTENT);  /// 81
    // lv_obj_set_height(ui_Screen_Label_SHIFTMOD, LV_SIZE_CONTENT); /// 55
    // lv_obj_set_x(ui_Screen_Label_SHIFTMOD, -20);
    // lv_obj_set_y(ui_Screen_Label_SHIFTMOD, 4);
    // lv_obj_set_align(ui_Screen_Label_SHIFTMOD, LV_ALIGN_RIGHT_MID);
    // // lv_img_set_src(ui_Screen_Label_SHIFTMOD, &shift);
    // lv_obj_add_event_cb(ui_Screen_Label_SHIFTMOD, ui_render_shiftmod, USER_EVENT_SHIFTMOD, NULL);
    // lv_event_send(ui_Screen_Label_SHIFTMOD, USER_EVENT_SHIFTMOD, NULL);

    // ui_Screen_Label_CTRLMOD = lv_img_create(ui_Screen);
    // lv_obj_set_width(ui_Screen_Label_CTRLMOD, LV_SIZE_CONTENT);  /// 81
    // lv_obj_set_height(ui_Screen_Label_CTRLMOD, LV_SIZE_CONTENT); /// 55
    // lv_obj_set_x(ui_Screen_Label_CTRLMOD, -20);
    // lv_obj_set_y(ui_Screen_Label_CTRLMOD, 31);
    // lv_obj_set_align(ui_Screen_Label_CTRLMOD, LV_ALIGN_RIGHT_MID);
    // // lv_img_set_src(ui_Screen_Label_CTRLMOD, &caret);
    // lv_obj_add_event_cb(ui_Screen_Label_CTRLMOD, ui_render_ctrlmod, USER_EVENT_CTRLMOD, NULL);
    // lv_event_send(ui_Screen_Label_CTRLMOD, USER_EVENT_CTRLMOD, NULL);
}

void ui_Screen2_screen_init(void) {
    ui_Screen2 = lv_obj_create(NULL);
    ui_Image1  = lv_img_create(ui_Screen2);
    // lv_img_set_src(ui_Image1, &cowboy_bebop);      // set image on startup
    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);  /// 81
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT); /// 55
    lv_obj_set_x(ui_Image1, 25);
    lv_obj_set_align(ui_Image1, LV_ALIGN_LEFT_MID);
}

void display_init(void) {
    lv_disp_t*  dispp = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    ui_screen_init();
    lv_disp_load_scr(ui_Screen);
}