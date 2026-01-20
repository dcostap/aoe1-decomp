#pragma once
#include "common.h"
#include "TPanel.h"

class TMessagePanel : public TPanel {
public:
    // Virtuals (best-effort)
    virtual ~TMessagePanel(); // vt[0] (0x0)
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7); // vt[1] (0x4)
    virtual void set_rect(tagRECT param_1); // vt[2] (0x8)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt[3] (0xC)
    virtual void set_color(uchar param_1); // vt[4] (0x10)
    virtual void set_active(int param_1); // vt[5] (0x14)
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13); // vt[6] (0x18)
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4); // vt[7] (0x1C)
    virtual void set_redraw(RedrawMode param_1); // vt[8] (0x20)
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3); // vt[9] (0x24)
    virtual void draw_setup(int param_1); // vt[10] (0x28)
    virtual void draw_finish(); // vt[11] (0x2C)
    virtual void draw(); // vt[12] (0x30)
    virtual void draw_rect(tagRECT* param_1); // vt[13] (0x34)
    virtual void draw_offset(long param_1, long param_2, tagRECT* param_3); // vt[14] (0x38)
    virtual void draw_rect2(tagRECT* param_1); // vt[15] (0x3C)
    virtual void draw_offset2(long param_1, long param_2, tagRECT* param_3); // vt[16] (0x40)
    virtual void paint(); // vt[17] (0x44)
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // vt[18] (0x48)
    virtual long handle_idle(); // vt[19] (0x4C)
    virtual long handle_size(long param_1, long param_2); // vt[20] (0x50)
    virtual long handle_paint(); // vt[21] (0x54)
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // vt[22] (0x58)
    virtual long handle_char(long param_1, short param_2); // vt[23] (0x5C)
    virtual long handle_command(uint param_1, long param_2); // vt[24] (0x60)
    virtual long handle_user_command(uint param_1, long param_2); // vt[25] (0x64)
    virtual long handle_timer_command(uint param_1, long param_2); // vt[26] (0x68)
    virtual long handle_scroll(long param_1, long param_2); // vt[27] (0x6C)
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[28] (0x70)
    virtual long handle_mouse_move(long param_1, long param_2, int param_3, int param_4); // vt[29] (0x74)
    virtual long handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[30] (0x78)
    virtual long handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt[31] (0x7C)
    virtual long mouse_move_action(long param_1, long param_2, int param_3, int param_4); // vt[32] (0x80)
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt[33] (0x84)
    virtual long mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4); // vt[34] (0x88)
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // vt[35] (0x8C)
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt[36] (0x90)
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt[37] (0x94)
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // vt[38] (0x98)
    virtual long mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4); // vt[39] (0x9C)
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // vt[40] (0xA0)
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // vt[41] (0xA4)
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt[42] (0xA8)
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt[43] (0xAC)
    virtual long char_action(long param_1, short param_2); // vt[44] (0xB0)
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt[45] (0xB4)
    virtual void get_true_render_rect(tagRECT* param_1); // vt[46] (0xB8)
    virtual int is_inside(long param_1, long param_2); // vt[47] (0xBC)
    virtual void set_focus(int param_1); // vt[48] (0xC0)
    virtual void set_tab_order(TPanel* param_1, TPanel* param_2); // vt[49] (0xC4)
    virtual void set_tab_order(TPanel** param_1, short param_2); // vt[50] (0xC8)
    virtual uchar get_help_info(char** param_1, long* param_2, long param_3, long param_4); // vt[51] (0xCC)
    virtual void stop_sound_system(); // vt[52] (0xD0)
    virtual int restart_sound_system(); // vt[53] (0xD4)
    virtual void take_snapshot(); // vt[54] (0xD8)
    virtual void handle_reactivate(); // vt[55] (0xDC)
    virtual void set_font(void* param_1, long param_2, long param_3); // vt[56] (0xE0)

    TMessagePanel::MessageType message_type;
    char text[512];
    int showing_message;
    unsigned long start_time;
    long show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    int index_color;
    unsigned long font_color1;
    unsigned long font_color2;
    TMessagePanel::JustType horz_just;
    TMessagePanel::JustType vert_just;
    int word_wrap;
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int LastIBWidth;
    int LastIBHeight;
    int ImageTextActive;
    TShape* Icon1;
    TShape* Icon2;
    int IconFrame1;
    int IconFrame2;
};
static_assert(sizeof(TMessagePanel) == 0x380, "Size mismatch");
