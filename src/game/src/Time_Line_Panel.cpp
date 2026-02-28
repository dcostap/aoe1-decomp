#include "../include/Time_Line_Panel.h"

#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Font.h"
#include "../include/RGE_Game_World.h"
#include "../include/Special_Events.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_History_Info.h"
#include "../include/TShape.h"
#include "../include/TDrawArea.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051E650
Time_Line_Panel::Time_Line_Panel()
    : TEasy_Panel() {
    this->text_style = ChiseledStyle;

    this->axis_font = nullptr;
    this->axis_font_wid = 0;
    this->axis_font_hgt = 0;
    this->body_font = nullptr;
    this->body_font_wid = 0;
    this->body_font_hgt = 0;

    this->text_color1 = 0xFFFFFF;
    this->text_color2 = 0;
    this->highlightTextColor1 = 0xFFFF;
    this->highlightTextColor2 = 0;
    this->text_wid = 0;
    this->text_hgt = 0;

    this->background_pic = nullptr;
    this->background_pic_wid = 0;
    this->background_pic_hgt = 0;

    this->fill_back = 0;
    this->back_color = 0xFF;

    this->outline = 0;
    this->outline_color = 0;
    this->sorted = 0;

    this->bevel_type = 0;
    this->bevel_color1 = 0;
    this->bevel_color2 = 0;
    this->bevel_color3 = 0;
    this->bevel_color4 = 0;
    this->bevel_color5 = 0;
    this->bevel_color6 = 0;

    this->special_events_pic = nullptr;
    this->special_events_pic_wid = 0;
    this->special_events_pic_hgt = 0;

    this->total_slices_to_drop = 0;
    this->time_slice_events = nullptr;

    this->timeline_flag = 1;
    this->drop_flag = 0;
    this->pop_reading_rate = 0x0C;

    this->legend_entry_text[0] = nullptr;
    this->legend_entry_text[1] = nullptr;
    this->legend_entry_text[2] = nullptr;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051E790
Time_Line_Panel::~Time_Line_Panel() {
    Special_Events* e = this->time_slice_events;
    while (e != nullptr) {
        Special_Events* next = e->next;
        free(e);
        e = next;
    }
    this->time_slice_events = nullptr;

    if (this->background_pic != nullptr) {
        delete this->background_pic;
        this->background_pic = nullptr;
    }
    if (this->special_events_pic != nullptr) {
        delete this->special_events_pic;
        this->special_events_pic = nullptr;
    }

    for (int i = 0; i < 3; ++i) {
        this->delete_panel((TPanel**)&this->legend_entry_text[i]);
    }
}

// Base virtuals: forward to TEasy_Panel.
long Time_Line_Panel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TEasy_Panel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
void Time_Line_Panel::set_rect(tagRECT param_1) { TEasy_Panel::set_rect(param_1); }
void Time_Line_Panel::set_rect(long param_1, long param_2, long param_3, long param_4) { TEasy_Panel::set_rect(param_1, param_2, param_3, param_4); }
void Time_Line_Panel::set_color(uchar param_1) { TEasy_Panel::set_color(param_1); }
void Time_Line_Panel::set_active(int param_1) { TEasy_Panel::set_active(param_1); }
void Time_Line_Panel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    TEasy_Panel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13);
}
void Time_Line_Panel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TEasy_Panel::set_fixed_position(param_1, param_2, param_3, param_4); }
void Time_Line_Panel::set_redraw(RedrawMode param_1) { TEasy_Panel::set_redraw(param_1); }
void Time_Line_Panel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TEasy_Panel::set_overlapped_redraw(param_1, param_2, param_3); }
void Time_Line_Panel::draw_setup(int param_1) { TEasy_Panel::draw_setup(param_1); }
void Time_Line_Panel::draw_finish() { TEasy_Panel::draw_finish(); }
void Time_Line_Panel::draw() {
    // TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x0051FA30
    TPanel::draw();
    this->need_redraw = TPanel::NoRedraw;
    if (this->render_area != nullptr && this->active != 0 && this->visible != 0) {
        this->draw_setup(0);
        this->draw_background();
        this->draw_border();
        this->draw_axis();
        this->draw_timeline();
        this->draw_special_events();
        this->draw_civilization_names();
        this->draw_finish();
    }
}
void Time_Line_Panel::draw_rect(tagRECT* param_1) { TEasy_Panel::draw_rect(param_1); }
void Time_Line_Panel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TEasy_Panel::draw_offset(param_1, param_2, param_3); }
void Time_Line_Panel::draw_rect2(tagRECT* param_1) { TEasy_Panel::draw_rect2(param_1); }
void Time_Line_Panel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TEasy_Panel::draw_offset2(param_1, param_2, param_3); }
void Time_Line_Panel::paint() { TEasy_Panel::paint(); }
long Time_Line_Panel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TEasy_Panel::wnd_proc(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::handle_idle() { return TEasy_Panel::handle_idle(); }
long Time_Line_Panel::handle_size(long param_1, long param_2) { return TEasy_Panel::handle_size(param_1, param_2); }
long Time_Line_Panel::handle_paint() { return TEasy_Panel::handle_paint(); }
long Time_Line_Panel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TEasy_Panel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long Time_Line_Panel::handle_char(long param_1, short param_2) { return TEasy_Panel::handle_char(param_1, param_2); }
long Time_Line_Panel::handle_command(uint param_1, long param_2) { return TEasy_Panel::handle_command(param_1, param_2); }
long Time_Line_Panel::handle_user_command(uint param_1, long param_2) { return TEasy_Panel::handle_user_command(param_1, param_2); }
long Time_Line_Panel::handle_timer_command(uint param_1, long param_2) { return TEasy_Panel::handle_timer_command(param_1, param_2); }
long Time_Line_Panel::handle_scroll(long param_1, long param_2) { return TEasy_Panel::handle_scroll(param_1, param_2); }
long Time_Line_Panel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long Time_Line_Panel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long Time_Line_Panel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TEasy_Panel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long Time_Line_Panel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_move_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TEasy_Panel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long Time_Line_Panel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TEasy_Panel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long Time_Line_Panel::char_action(long param_1, short param_2) { return TEasy_Panel::char_action(param_1, param_2); }
long Time_Line_Panel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return TEasy_Panel::action(param_1, param_2, param_3, param_4); }
void Time_Line_Panel::get_true_render_rect(tagRECT* param_1) { TEasy_Panel::get_true_render_rect(param_1); }
int Time_Line_Panel::is_inside(long param_1, long param_2) { return TEasy_Panel::is_inside(param_1, param_2); }
void Time_Line_Panel::set_focus(int param_1) { TEasy_Panel::set_focus(param_1); }
void Time_Line_Panel::set_tab_order(TPanel* param_1, TPanel* param_2) { TEasy_Panel::set_tab_order(param_1, param_2); }
void Time_Line_Panel::set_tab_order(TPanel** param_1, short param_2) { TEasy_Panel::set_tab_order(param_1, param_2); }
uchar Time_Line_Panel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TEasy_Panel::get_help_info(param_1, param_2, param_3, param_4); }
void Time_Line_Panel::stop_sound_system() { TEasy_Panel::stop_sound_system(); }
int Time_Line_Panel::restart_sound_system() { return TEasy_Panel::restart_sound_system(); }
void Time_Line_Panel::take_snapshot() { TEasy_Panel::take_snapshot(); }
void Time_Line_Panel::handle_reactivate() { TEasy_Panel::handle_reactivate(); }
void Time_Line_Panel::draw_background(int param_1) { TEasy_Panel::draw_background(param_1); }
void Time_Line_Panel::set_ideal_size(long param_1, long param_2) { TEasy_Panel::set_ideal_size(param_1, param_2); }
int Time_Line_Panel::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TEasy_Panel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int Time_Line_Panel::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    return TEasy_Panel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int Time_Line_Panel::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TEasy_Panel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int Time_Line_Panel::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TEasy_Panel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int Time_Line_Panel::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int Time_Line_Panel::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) {
    return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int Time_Line_Panel::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    return TEasy_Panel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}
int Time_Line_Panel::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) {
    return TEasy_Panel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10);
}
int Time_Line_Panel::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) {
    return TEasy_Panel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12);
}
int Time_Line_Panel::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TEasy_Panel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
int Time_Line_Panel::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) {
    return TEasy_Panel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}
int Time_Line_Panel::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    return TEasy_Panel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8);
}
int Time_Line_Panel::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TEasy_Panel::create_auto_scrollbar(param_1, param_2, param_3); }
int Time_Line_Panel::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TEasy_Panel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
int Time_Line_Panel::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    return TEasy_Panel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
void Time_Line_Panel::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TEasy_Panel::position_panel(param_1, param_2, param_3, param_4, param_5); }

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051E860
long Time_Line_Panel::create_timeline(TPanel* parent, Time_Line_Panel** out, long x, long y, long wid, long hgt, long axis_font_id, long body_font_id, long base_w, long base_h) {
    if (out == nullptr || parent == nullptr) {
        return 0;
    }

    long scaled_x = (parent->width() * x) / base_w;
    long scaled_y = (parent->height() * y) / base_h;
    long scaled_w = (parent->width() * wid) / base_w;
    long scaled_h = (parent->height() * hgt) / base_h;

    Time_Line_Panel* pnl = new Time_Line_Panel();
    *out = pnl;
    if (pnl == nullptr) {
        return 0;
    }

    if (axis_font_id < 0) axis_font_id = 0x0B;
    if (body_font_id < 0) body_font_id = 0x0B;
    RGE_Font* axis_font = (rge_base_game != nullptr) ? rge_base_game->get_font((int)axis_font_id) : nullptr;
    RGE_Font* body_font = (rge_base_game != nullptr) ? rge_base_game->get_font((int)body_font_id) : nullptr;

    void* axis_handle = axis_font ? axis_font->font : nullptr;
    long axis_wid = axis_font ? axis_font->font_wid : 0;
    long axis_hgt = axis_font ? axis_font->font_hgt : 0;

    void* body_handle = body_font ? body_font->font : nullptr;
    long body_wid = body_font ? body_font->font_wid : 0;
    long body_hgt = body_font ? body_font->font_hgt : 0;

    TDrawArea* draw_area = parent->render_area;
    if (pnl->setup(draw_area, parent, scaled_x, scaled_y, scaled_w, scaled_h,
                   axis_handle, axis_wid, axis_hgt,
                   body_handle, body_wid, body_hgt,
                   (char*)nullptr, (char*)nullptr,
                   0, 0, 0, 0) == 0) {
        return 0;
    }

    pnl->init_timeline();
    return 1;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051E9E0
long Time_Line_Panel::setup(TDrawArea* draw_area, TPanel* parent, long x, long y, long wid, long hgt,
                            void* axis_font, long axis_font_wid, long axis_font_hgt,
                            void* body_font, long body_font_wid, long body_font_hgt,
                            char* background_file, char* special_events_file,
                            int fill_back, uchar back_color, int outline, uchar outline_color) {
    this->TPanel::setup(draw_area, parent, x, y, wid, hgt, '\0');

    this->fill_back = fill_back;
    this->back_color = back_color;
    this->outline = outline;
    this->outline_color = outline_color;
    if (outline != 0) {
        this->bevel_type = 1;
    }

    this->set_axis_font(axis_font, axis_font_wid, axis_font_hgt);
    this->set_body_font(body_font, body_font_wid, body_font_hgt);
    this->set_background(background_file);
    this->set_special_events(special_events_file);

    // Decomp uses GetNearestPaletteIndex(..., 0). If we don't have palette context, default to 0.
    this->set_back_color(1, 0);
    return 1;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051EAB0
void Time_Line_Panel::set_bevel_info(int bevel_type, int c1, int c2, int c3, int c4, int c5, int c6) {
    this->bevel_type = bevel_type;
    this->bevel_color1 = (uchar)c1;
    this->bevel_color2 = (uchar)c2;
    this->bevel_color3 = (uchar)c3;
    this->bevel_color4 = (uchar)c4;
    this->bevel_color5 = (uchar)c5;
    this->bevel_color6 = (uchar)c6;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051EB00
int Time_Line_Panel::set_background(char* file) {
    if (this->background_pic != nullptr) {
        delete this->background_pic;
        this->background_pic = nullptr;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (file != nullptr && *file != '\0') {
        this->background_pic = new TShape(file, -1);
        if (this->background_pic != nullptr) {
            long x_min = 0, y_min = 0, x_max = 0, y_max = 0;
            this->background_pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
            this->background_pic_wid = (short)((x_max - x_min) + 1);
            this->background_pic_hgt = (short)((y_max - y_min) + 1);
            return 1;
        }
    }
    return 0;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051EC10
int Time_Line_Panel::set_background(char* file, long id) {
    if (this->background_pic != nullptr) {
        delete this->background_pic;
        this->background_pic = nullptr;
        this->background_pic_wid = 0;
        this->background_pic_hgt = 0;
    }

    if (id == -1) {
        return 0;
    }

    char name_buf[260];
    name_buf[0] = '\0';

    const char* use = file;
    if (use == nullptr || *use == '\0' || _stricmp(use, "none") == 0) {
        use = "";
    }

    if (strchr(use, '.') == nullptr) {
        sprintf(name_buf, "%s.shp", use);
        use = name_buf;
    }

    this->background_pic = new TShape((char*)use, (int)id);
    if (this->background_pic != nullptr && this->background_pic->is_loaded() == 0) {
        delete this->background_pic;
        this->background_pic = nullptr;
    }

    if (this->background_pic != nullptr) {
        long x_min = 0, y_min = 0, x_max = 0, y_max = 0;
        this->background_pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
        this->background_pic_wid = (short)((x_max - x_min) + 1);
        this->background_pic_hgt = (short)((y_max - y_min) + 1);
    }

    return (this->background_pic != nullptr) ? 1 : 0;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051EDD0
int Time_Line_Panel::set_special_events(char* file) {
    if (this->special_events_pic != nullptr) {
        delete this->special_events_pic;
        this->special_events_pic = nullptr;
        this->special_events_pic_wid = 0;
        this->special_events_pic_hgt = 0;
    }

    if (file != nullptr && *file != '\0') {
        this->special_events_pic = new TShape(file, -1);
        if (this->special_events_pic != nullptr) {
            long x_min = 0, y_min = 0, x_max = 0, y_max = 0;
            this->special_events_pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
            this->special_events_pic_wid = (short)((x_max - x_min) + 1);
            this->special_events_pic_hgt = (short)((y_max - y_min) + 1);
            return 1;
        }
    }
    return 0;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051EEE0
int Time_Line_Panel::set_special_events(char* file, long id) {
    if (this->special_events_pic != nullptr) {
        delete this->special_events_pic;
        this->special_events_pic = nullptr;
        this->special_events_pic_wid = 0;
        this->special_events_pic_hgt = 0;
    }

    if (id == -1) {
        return 0;
    }

    char name_buf[260];
    name_buf[0] = '\0';

    const char* use = file;
    if (use == nullptr || *use == '\0' || _stricmp(use, "none") == 0) {
        use = "";
    }

    if (strchr(use, '.') == nullptr) {
        sprintf(name_buf, "%s.shp", use);
        use = name_buf;
    }

    this->special_events_pic = new TShape((char*)use, (int)id);
    if (this->special_events_pic != nullptr && this->special_events_pic->is_loaded() == 0) {
        delete this->special_events_pic;
        this->special_events_pic = nullptr;
    }

    if (this->special_events_pic != nullptr) {
        long x_min = 0, y_min = 0, x_max = 0, y_max = 0;
        this->special_events_pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
        this->special_events_pic_wid = (short)((x_max - x_min) + 1);
        this->special_events_pic_hgt = (short)((y_max - y_min) + 1);
    }

    return (this->special_events_pic != nullptr) ? 1 : 0;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051F0A0
void Time_Line_Panel::set_axis_font(void* font, long wid, long hgt) {
    this->axis_font = font;
    this->axis_font_wid = wid;
    this->axis_font_hgt = hgt;
    this->set_redraw(TPanel::Redraw);
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051F0D0
void Time_Line_Panel::set_body_font(void* font, long wid, long hgt) {
    this->body_font = font;
    this->body_font_wid = wid;
    this->body_font_hgt = hgt;
    this->set_redraw(TPanel::Redraw);
}

// Fully verified. Source of truth: tpnl_tml.cpp.decomp @ 0x0051F100
void Time_Line_Panel::set_back_color(int fill_back, uchar back_color) {
    this->fill_back = fill_back;
    this->back_color = back_color;
}

// Source of truth: tpnl_tml.cpp.decomp @ 0x0051F310
void Time_Line_Panel::init_timeline() {
    this->num_history_entries = 0;

    // ASM uses `rge_base_game->world` directly (no null checks).
    RGE_Game_World* w = rge_base_game->world;
    if (w->player_num != 1 && -1 < (w->player_num - 1)) {
        for (int i = 0; i < (w->player_num - 1); ++i) {
            TRIBE_Player* p = (TRIBE_Player*)w->players[i + 1];
            long entry_num = p->history->get_history_entry_num();
            if (this->num_history_entries < entry_num) {
                this->num_history_entries = entry_num;
            }
        }
    }

    long usable_x = this->width() - 0x31;
    if (this->num_history_entries == 0) {
        this->num_history_entries = 1;
        this->timeline_flag = 0;
    }

    long total = this->num_history_entries;
    this->time_slice_drop_rate = 0.0f;
    float thickness = (float)usable_x / (float)total;
    this->bar_thickness = thickness;

    if (1.0f <= thickness) {
        this->num_entries_page = total;
    } else {
        this->bar_thickness = 1.0f;
        this->num_entries_page = usable_x;
        this->drop_flag = 1;
        this->total_slices_to_drop = total - usable_x;
        this->time_slice_drop_rate = (float)usable_x / (float)(total - usable_x);
    }

    long axis_len = (long)(this->bar_thickness * (float)this->num_entries_page);
    this->X_axis_length = axis_len + 4;

    this->Y_axis_length = this->height() - (this->axis_font_hgt * 4) - 0x1A;

    this->X_start_line_pos = this->xPosition() + 0x1B;
    this->X_line_pos = this->X_start_line_pos;

    long y_start = this->yPosition() + 0x0F + (this->axis_font_hgt * 2);
    this->Y_start_line_pos = y_start;
    this->Y_line_pos = y_start;

    this->X_line_max_width = this->X_axis_length - 2;
    this->Y_line_max_length = this->Y_axis_length - 3;

    if (this->num_entries_page < 0x0C) {
        this->pop_reading_rate = 1;
        return;
    }
    // ASM decrements num_entries_page before scaling (DEC EAX before FILD/FMUL/CALL __ftol).
    this->pop_reading_rate = (long)((float)(this->num_entries_page - 1) / 12.0f);
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x0051F120
void Time_Line_Panel::draw_border() {
    if (this->bevel_type == 0 || this->render_area == nullptr) {
        return;
    }

    if (this->render_area->Lock((char*)"tpnl_tml::draw_border", 1) == nullptr) {
        this->render_area->Unlock((char*)"tpnl_tml::draw_border");
        return;
    }

    const long l = this->pnl_x;
    const long t = this->pnl_y;
    const long r = this->pnl_x + this->pnl_wid - 1;
    const long b = this->pnl_y + this->pnl_hgt - 1;

    switch (this->bevel_type) {
    case 1:
        this->render_area->DrawRect(l, t, r, b, this->outline_color);
        break;
    case 2:
        this->render_area->DrawBevel(l, t, r, b, this->bevel_color6, this->bevel_color1);
        break;
    case 3:
        this->render_area->DrawBevel2(l, t, r, b, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
        break;
    case 4:
        this->render_area->DrawBevel3(l, t, r, b, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        break;
    case 5:
        this->render_area->DrawBevel(l, t, r, b, this->bevel_color1, this->bevel_color6);
        break;
    case 6:
        this->render_area->DrawBevel2(l, t, r, b, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
        break;
    case 7:
        this->render_area->DrawBevel3(l, t, r, b, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
        break;
    default:
        break;
    }

    this->render_area->Unlock((char*)"tpnl_tml::draw_border");
}

// Fully verified. Source of truth: tpnl_tml.cpp.decomp @ 0x0051F4E0
void Time_Line_Panel::add_pop_total_special_event(long param_1, long param_2, long param_3, int param_4) {
    Special_Events* e = (Special_Events*)calloc(1, sizeof(Special_Events));
    if (e == nullptr) {
        return;
    }
    e->time_slice = param_1;
    e->X_line_pos = param_3;
    e->Y_line_pos = 0;
    e->intermediate_y_line_segment = 0;
    e->player_id = 0;
    e->player_color = 0;
    e->interger_value_1 = 0;
    e->interger_value_2 = 0;
    e->start_x = 0;
    e->start_y = 0;
    e->start_txt_x1 = 0;
    e->start_txt_y1 = 0;
    e->start_txt_x2 = 0;
    e->start_txt_y2 = 0;
    e->text_length1 = 0;
    e->text1[0] = '\0';
    e->text_length2 = 0;
    e->text2[0] = '\0';
    e->event = 3;
    e->pop_total = param_2;
    e->icon_flag = param_4;
    e->next = this->time_slice_events;
    this->time_slice_events = e;
}

// Fully verified. Source of truth: tpnl_tml.cpp.decomp @ 0x0051F560
void Time_Line_Panel::record_special_event(uchar param_1, TRIBE_History_Info* param_2, uchar param_3, long param_4, long param_5, long param_6, long param_7) {
    uchar event = 0;
    const long time_slice = param_4;
    if (param_2->get_history_event(param_4, &event) != 0) {
        Special_Events* e = (Special_Events*)calloc(1, sizeof(Special_Events));
        if (e == nullptr) {
            return;
        }

        e->X_line_pos = param_5;
        e->Y_line_pos = param_6;
        e->intermediate_y_line_segment = param_7;
        e->time_slice = time_slice;
        e->player_id = param_1;
        e->player_color = param_3;
        e->event = event;
        e->pop_total = 0;
        e->interger_value_1 = 0;
        e->interger_value_2 = 0;
        e->start_x = 0;
        e->start_y = 0;
        e->start_txt_x1 = 0;
        e->start_txt_y1 = 0;
        e->start_txt_x2 = 0;
        e->start_txt_y2 = 0;
        e->text_length1 = 0;
        e->text1[0] = '\0';
        e->text_length2 = 0;
        e->text2[0] = '\0';
        e->icon_flag = 0;
        e->next = this->time_slice_events;
        this->time_slice_events = e;
    }
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x0051F600
int Time_Line_Panel::calculate_icon_location(Special_Events* param_1, short param_2, uchar param_3) {
    (void)param_3;
    int use_icon = 0;
    param_1->icon_flag = 0;

    if (this->special_events_pic != nullptr && this->special_events_pic->shape_count() != 0 && this->special_events_pic->shape_count() >= param_2) {
        if (param_1->intermediate_y_line_segment >= this->special_events_pic_hgt) {
            const int half = this->special_events_pic_wid / 2;
            const long icon_x = param_1->X_line_pos - half;
            const long icon_y = (param_1->intermediate_y_line_segment / 2 + param_1->Y_line_pos * 2) - (int)this->special_events_pic_hgt / 2;
            if (icon_x >= this->X_start_line_pos && (param_1->X_line_pos + half) <= (this->X_line_max_width + this->X_start_line_pos)) {
                param_1->start_x = icon_x;
                param_1->start_y = icon_y;
                use_icon = 1;
            }
        }
    }

    const int text_w = this->body_font_wid * (int)strlen(param_1->text1);
    long text_x = param_1->X_line_pos + 2;
    if (text_x + text_w >= this->X_start_line_pos + this->X_line_max_width) {
        text_x = (this->X_line_max_width - text_w) - 3 + this->X_start_line_pos;
    }
    long text_y = (param_1->Y_line_pos + param_1->intermediate_y_line_segment) - this->body_font_hgt - 2;
    if (text_y < this->Y_start_line_pos) {
        text_y = this->Y_start_line_pos + 2;
    }

    param_1->start_txt_x1 = text_x;
    param_1->start_txt_y1 = text_y;
    if (use_icon != 0) {
        param_1->icon_flag = 1;
    }
    return use_icon;
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x0051FA90
void Time_Line_Panel::draw_axis() {
    if (this->render_area == nullptr) {
        return;
    }
    uchar white = 0xFF;
    if (this->render_area->Lock((char*)"tpnl_tml::draw_axis", 1) != nullptr) {
        const long x = this->xPosition();
        const long y = this->yPosition();
        this->render_area->FillRect(x + 0x19, y + 0x0D + this->axis_font_hgt * 2 + this->Y_axis_length, x + 0x18 + this->X_axis_length, y + 0x0D + this->axis_font_hgt * 2 + this->Y_axis_length + 1, white);
        this->render_area->FillRect(x + 0x19, y + 0x0D + this->axis_font_hgt * 2, x + 0x18 + this->X_axis_length, y + 0x0E + this->axis_font_hgt * 2, white);
        this->render_area->FillRect(x + 0x19, y + 0x0D + this->axis_font_hgt * 2, x + 0x1A, y + 0x0D + this->axis_font_hgt * 2 + this->Y_axis_length, white);
        this->render_area->FillRect(x + 0x17 + this->X_axis_length, y + 0x0D + this->axis_font_hgt * 2, x + 0x18 + this->X_axis_length, y + 0x0D + this->axis_font_hgt * 2 + this->Y_axis_length, white);
    }
    this->render_area->Unlock((char*)"tpnl_tml::draw_axis");

    HDC dc = (HDC)this->render_area->GetDc((char*)"tpnl_tml::draw_axis");
    if (dc == nullptr) {
        return;
    }
    SetBkMode(dc, 1);
    HGDIOBJ old_font = SelectObject(dc, this->axis_font);
    SetTextColor(dc, 0xFFFFFF);
    char temp_str[100];
    if (this->get_string(0x2C57, temp_str, 100) != 0) {
        TextOutA(dc, this->xPosition() + 8, this->yPosition() + 5, temp_str, (int)strlen(temp_str));
    }
    if (this->get_string(0x2C56, temp_str, 100) != 0) {
        const int len = (int)strlen(temp_str);
        TextOutA(dc, (this->X_start_line_pos - ((len * this->axis_font_wid) >> 1)) + this->X_axis_length / 2, this->height() + this->yPosition() - 5 - this->axis_font_hgt, temp_str, len);
    }
    SelectObject(dc, old_font);
    this->render_area->ReleaseDc((char*)"tpnl_tml::draw_axis");
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x0051FD90
void Time_Line_Panel::draw_special_events() {
    if (this->timeline_flag == 0 || this->render_area == nullptr) {
        return;
    }

    if (this->render_area->Lock((char*)"tpnl_tml::draw_special_events", 1) != nullptr) {
        for (Special_Events* e = this->time_slice_events; e != nullptr; e = e->next) {
            short icon = -1;
            switch (e->event) {
            case 0: icon = -1; break;
            case 1: icon = -1; break;
            case 2: icon = -1; break;
            case 3: icon = -1; break;
            case 4: icon = 0; break;
            case 5: icon = 1; break;
            case 6: icon = 2; break;
            case 7: icon = 3; break;
            case 8: icon = 4; break;
            default: break;
            }
            this->draw_icon(e, icon, e->event);
        }
    }
    this->render_area->Unlock((char*)"tpnl_tml::draw_special_events");

    HDC dc = (HDC)this->render_area->GetDc((char*)"tpnl_tml::draw_special_events");
    if (dc == nullptr) {
        return;
    }
    SetBkMode(dc, 1);
    HGDIOBJ old_font = SelectObject(dc, this->body_font);
    for (Special_Events* e = this->time_slice_events; e != nullptr; e = e->next) {
        if ((e->event == 6 || e->event == 8) && e->icon_flag == 0) {
            continue;
        }
        SetTextColor(dc, 0);
        if (e->text_length1 <= 0) {
            e->text_length1 = (int)strlen(e->text1);
        }
        TextOutA(dc, e->start_txt_x1, e->start_txt_y1, e->text1, e->text_length1);
        if (e->event == 3) {
            SetTextColor(dc, 0xFFFFFF);
            const int len2 = (int)strlen(e->text2);
            TextOutA(dc, e->start_txt_x2, e->start_txt_y2, e->text2, len2);
        }
    }
    SelectObject(dc, old_font);
    this->render_area->ReleaseDc((char*)"tpnl_tml::draw_special_events");
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x00520080
void Time_Line_Panel::draw_background() {
    if (this->background_pic == nullptr) {
        if (this->fill_back == 0) {
            if (this->bevel_type > 1 && this->bevel_type < 8) {
                this->parent_panel->draw_offset(this->pnl_x, this->pnl_y, &this->clip_rect);
            } else if (this->parent_panel != nullptr) {
                this->parent_panel->draw_rect(&this->clip_rect);
            }
            return;
        }

        if (this->render_area->Lock((char*)"tpnl_tml::draw_background2", 1) != nullptr) {
            this->render_area->FillRect(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->back_color);
            this->render_area->Unlock((char*)"tpnl_tml::draw_background2");
        }
        return;
    }

    if (this->render_area->Lock((char*)"tpnl_tml::draw_background", 1) == nullptr) {
        return;
    }

    short cols = 1;
    if (this->background_pic_wid < this->pnl_wid) {
        cols = (short)(this->pnl_wid / this->background_pic_wid);
        if ((cols * this->background_pic_wid) < this->pnl_wid) {
            cols = cols + 1;
        }
    }
    short rows = 1;
    if (this->background_pic_hgt < this->pnl_hgt) {
        rows = (short)(this->pnl_hgt / this->background_pic_hgt);
        if ((rows * this->background_pic_hgt) < this->pnl_hgt) {
            rows = rows + 1;
        }
    }

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            this->background_pic->shape_draw(this->render_area, x * this->background_pic_wid + this->pnl_x, y * this->background_pic_hgt + this->pnl_y, 0, 0, nullptr);
        }
    }

    this->render_area->Unlock((char*)"tpnl_tml::draw_background");
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x00520220
void Time_Line_Panel::draw_civilization_names() {
    if (this->timeline_flag == 0 || this->render_area == nullptr) {
        return;
    }
    HDC dc = (HDC)this->render_area->GetDc((char*)"tpnl_tml::draw_civilization_name");
    if (dc == nullptr) {
        return;
    }

    SetBkMode(dc, 1);
    SetTextColor(dc, 0);
    HGDIOBJ old_font = SelectObject(dc, this->body_font);

    float total = 0.0f;
    RGE_Game_World* w = rge_base_game->world;
    for (int i = 1; i < w->player_num; ++i) {
        TRIBE_Player* player = (TRIBE_Player*)w->players[i];
        total += (float)player->history->get_history_entry(0, 0);
    }

    if (total != 0.0f) {
        long x = this->X_start_line_pos;
        long y = this->Y_start_line_pos;
        for (int i = 1; i < w->player_num; ++i) {
            TRIBE_Player* player = (TRIBE_Player*)w->players[i];
            const int seg = (int)((player->history->get_history_entry(0, 0) / total) * this->Y_line_max_length);
            char civ[100];
            char tmp[100];
            char name[100];
            rge_base_game->get_string2(0x69, player->master_player_id, 0, civ, 100);
            sprintf(name, "%s", player->name);
            sprintf(tmp, "%s - %s", name, civ);
            TextOutA(dc, x + 3, (seg / 2 - this->body_font_hgt / 2) + y, tmp, (int)strlen(tmp));
            y += seg;
        }
    }

    SelectObject(dc, old_font);
    this->render_area->ReleaseDc((char*)"tpnl_tml::draw_civilization_name");
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x005204A0
void Time_Line_Panel::draw_timeline() {
    if (this->timeline_flag == 0 || this->render_area == nullptr) {
        return;
    }
    if (this->render_area->Lock((char*)"tpnl_tml::draw_timeline", 1) == nullptr) {
        return;
    }

    this->X_line_pos = this->X_start_line_pos;
    long pop_sample_counter = 0;
    long sample_counter = 0;
    float time_slice = 0.0f;

    while ((int)time_slice < this->num_history_entries && sample_counter < this->num_entries_page) {
        float total_pop = 0.0f;
        RGE_Game_World* w = rge_base_game->world;
        for (int i = 1; i < w->player_num; ++i) {
            TRIBE_Player* p = (TRIBE_Player*)w->players[i];
            total_pop += (float)p->history->get_history_entry(0, (long)time_slice);
        }
        if (total_pop == 0.0f) {
            break;
        }

        if (pop_sample_counter == this->pop_reading_rate - 1 || time_slice == 0.0f) {
            this->add_pop_total_special_event((long)time_slice, (long)total_pop, this->X_line_pos, 1);
            pop_sample_counter = 0;
        } else {
            pop_sample_counter++;
        }

        long y = this->Y_start_line_pos;
        for (int i = 1; i < w->player_num; ++i) {
            TRIBE_Player* p = (TRIBE_Player*)w->players[i];
            const float value = (float)p->history->get_history_entry(0, (long)time_slice);
            const long seg = (long)((value / total_pop) * this->Y_line_max_length);
            uchar color = 0xFF;
            this->render_area->DrawVertLine(this->X_line_pos, y, seg, color);
            this->record_special_event((uchar)i, p->history, color, (long)time_slice, this->X_line_pos, y, seg);
            y += seg;
        }

        this->X_line_pos += 1;
        sample_counter += 1;
        time_slice += 1.0f;
    }

    this->render_area->Unlock((char*)"tpnl_tml::draw_timeline");
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x00520AE0
void Time_Line_Panel::draw_icon(Special_Events* param_1, short param_2, uchar param_3) {
    (void)param_3;
    uchar black = 0;
    switch (param_1->event) {
    case 0:
        if (this->get_string(0x106A, param_1->text1, 50) == 0) {
            param_1->text1[0] = '\0';
        }
        break;
    case 1:
        if (this->get_string(0x106B, param_1->text1, 50) == 0) {
            param_1->text1[0] = '\0';
        }
        break;
    case 2:
        if (this->get_string(0x106C, param_1->text1, 50) == 0) {
            param_1->text1[0] = '\0';
        }
        break;
    case 3: {
        sprintf(param_1->text1, "%ld", param_1->pop_total);
        int h = 0;
        int m = 0;
        const int sec = (int)param_1->time_slice * 15;
        if (sec > 0x3B) {
            m = sec / 0x3C;
            if (m > 0x3B) {
                h = m / 0x3C;
                m = m % 0x3C;
            }
        }
        sprintf(param_1->text2, "%1d:%02d", h, m);
        param_1->text_length2 = (int)strlen(param_1->text2);
        break;
    }
    default:
        break;
    }

    param_1->text_length1 = (int)strlen(param_1->text1);
    const int draw_icon_flag = this->calculate_icon_location(param_1, param_2, param_3);
    if (param_1->event == 0 || param_1->event == 1 || param_1->event == 2) {
        this->render_area->DrawVertLine(param_1->X_line_pos, param_1->Y_line_pos, param_1->intermediate_y_line_segment, black);
        return;
    }

    if (draw_icon_flag != 0 && this->special_events_pic != nullptr) {
        this->special_events_pic->shape_draw(this->render_area, param_1->start_x, param_1->start_y, (int)param_2, 0, nullptr);
    }
}

// TODO: Partial transliteration. Source of truth: tpnl_tml.cpp.decomp @ 0x00520D50
void Time_Line_Panel::draw_legend() {
    if (this->special_events_pic != nullptr && this->special_events_pic->shape_count() != 0) {
        (void)this->width();
    }
}

