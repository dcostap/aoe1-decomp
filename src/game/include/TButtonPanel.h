#pragma once
#include "common.h"
#include "TPanel.h"

class TButtonPanel : public TPanel {
public:
    enum ButtonType : int {};
    enum DrawType : int {};
    enum NotifyType : int {};
    
    TButtonPanel();

    // Virtuals (best-effort)
    virtual ~TButtonPanel(); // vt[0] (0x0)
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, TButtonPanel::DrawType param_7, TDigital* param_8, TButtonPanel::NotifyType param_9, long param_10); // vt[1] (0x4)
    
    // Non-virtuals found in ASM
    void set_text(short state, char* text);
    void set_text(short state, long resid);
    void set_text(long resid);
    void set_text(short state, long resid1, long resid2);
    void set_text(short state, char* text1, char* text2);
    void set_font(void* font, long wid = -1, long hgt = -1);
    void set_text_pos(long x, long y);
    void set_text_info(char* text, void* font, long p3, long p4, long p5, long p6);
    void set_text_info(long resid, void* font, long p3, long p4, long p5, long p6);
    void set_picture(short state, TShape* shape, short index);
    void set_radio_info(TButtonPanel** buttons, short num);
    void set_state_info(short num_states);
    int get_state();
    long get_id();
    long get_id2();
    int get_text(short state, char** text1, char** text2);
    void get_text_color(short state, ulong* color1, ulong* color2);
    void set_sound_number(int num);
    void set_id(long val);
    void set_sound(TDigital* s);
    virtual void set_rect(tagRECT param_1); // vt[2] (0x8)
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt[3] (0xC)
    virtual void set_color(uchar param_1); // vt[4] (0x10)
    virtual void set_active(int param_1); // vt[5] (0x14)
    virtual void set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13); // vt[6] (0x18)
    virtual void set_fixed_position(long param_1, long param_2, long param_3, long param_4); // vt[7] (0x1C)
    virtual void set_redraw(TPanel::RedrawMode param_1); // vt[8] (0x20)
    virtual void set_overlapped_redraw(TPanel* param_1, TPanel* param_2, TPanel::RedrawMode param_3); // vt[9] (0x24)
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
    virtual long action(long param_1, ulong param_2, ulong param_3); // vt[45] (0xB4)
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
    virtual void set_state(short param_1); // vt[56] (0xE0)
    virtual int hit_button(long param_1, long param_2); // vt[57] (0xE4)

    long id[9]; // +0xF4 (Size: 0x24)
    long id2[9]; // +0x118 (Size: 0x24)
    ButtonType buttonTypeValue; // +0x13C (Size: 0x4)
    DrawType drawTypeValue; // +0x140 (Size: 0x4)
    NotifyType notifyTypeValue; // +0x144 (Size: 0x4)
    TDigital* sound; // +0x148 (Size: 0x4)
    TShape* pic[9]; // +0x14C (Size: 0x24)
    short pic_index[9]; // +0x170 (Size: 0x12)
    unsigned char _pad_0[0x2]; // 0x0182 (Gap: 2)
    int auto_pic_pos; // +0x184 (Size: 0x4)
    long pic_x; // +0x188 (Size: 0x4)
    long pic_y; // +0x18C (Size: 0x4)
    int all_hot; // +0x190 (Size: 0x4)
    int draw_reverse; // +0x194 (Size: 0x4)
    char* text1[9]; // +0x198 (Size: 0x24)
    char* text2[9]; // +0x1BC (Size: 0x24)
    long text_x; // +0x1E0 (Size: 0x4)
    long text_y; // +0x1E4 (Size: 0x4)
    void* font; // +0x1E8 (Size: 0x4)
    long font_wid; // +0x1EC (Size: 0x4)
    long font_hgt; // +0x1F0 (Size: 0x4)
    short num_states; // +0x1F4 (Size: 0x2)
    short cur_state; // +0x1F6 (Size: 0x2)
    int is_down; // +0x1F8 (Size: 0x4)
    TButtonPanel** radio_buttons; // +0x1FC (Size: 0x4)
    short num_radio_buttons; // +0x200 (Size: 0x2)
    unsigned char _pad_1[0x2]; // 0x0202 (Gap: 2)
    unsigned long button_down_time; // +0x204 (Size: 0x4)
    unsigned long text_color1[9]; // +0x208 (Size: 0x24)
    unsigned long text_color2[9]; // +0x22C (Size: 0x24)
    unsigned long highlight_text_color1[9]; // +0x250 (Size: 0x24)
    unsigned long highlight_text_color2[9]; // +0x274 (Size: 0x24)
    long hotkey; // +0x298 (Size: 0x4)
    int hotkey_shift; // +0x29C (Size: 0x4)
    int bevel_type; // +0x2A0 (Size: 0x4)
    unsigned char bevel_color1; // +0x2A4 (Size: 0x1)
    unsigned char bevel_color2; // +0x2A5 (Size: 0x1)
    unsigned char bevel_color3; // +0x2A6 (Size: 0x1)
    unsigned char bevel_color4; // +0x2A7 (Size: 0x1)
    unsigned char bevel_color5; // +0x2A8 (Size: 0x1)
    unsigned char bevel_color6; // +0x2A9 (Size: 0x1)
    unsigned char _pad_2[0x2]; // 0x02aa (Gap: 2)
    long key_down; // +0x2AC (Size: 0x4)
    int disabled; // +0x2B0 (Size: 0x4)
    int sound_number; // +0x2B4 (Size: 0x4)
};
static_assert(sizeof(TButtonPanel) == 0x2B8, "Size mismatch");
