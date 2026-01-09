#pragma once
#include "common.h"



enum ActionType : unsigned int {
    ActionSelect = 1,
    ActionDown = 2,
    ActionUp = 3,
    ActionRightSelect = 4,
    ActionRightDown = 5,
    ActionRightUp = 6,
};

enum ButtonType : unsigned int {
    Normal = 1,
    Radio = 2,
    State = 3,
};

enum DrawType : unsigned int {
    DrawClear = 1,
    DrawPicture = 2,
    DrawTextA = 3,
    DrawPictureAndText = 4,
    DrawFillAndText = 5,
    DrawBevelPicture = 6,
};

enum NotifyType : unsigned int {
    NotifyAction = 1,
    NotifyCommand = 2,
};

enum BevelType : unsigned int {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};


class TButtonPanel : public TPanel {
public:
    long id[9];                              // 0xF4
    long id2[9];                             // 0x118
    ButtonType buttonTypeValue;              // 0x13C
    DrawType drawTypeValue;                  // 0x140
    NotifyType notifyTypeValue;              // 0x144
    TDigital* sound;                         // 0x148
    TShape* pic[9];                          // 0x14C
    short pic_index[9];                      // 0x170
    int auto_pic_pos;                        // 0x184
    long pic_x;                              // 0x188
    long pic_y;                              // 0x18C
    int all_hot;                             // 0x190
    int draw_reverse;                        // 0x194
    char* text1[9];                          // 0x198
    char* text2[9];                          // 0x1BC
    long text_x;                             // 0x1E0
    long text_y;                             // 0x1E4
    void* font;                              // 0x1E8
    long font_wid;                           // 0x1EC
    long font_hgt;                           // 0x1F0
    short num_states;                        // 0x1F4
    short cur_state;                         // 0x1F6
    int is_down;                             // 0x1F8
    TButtonPanel** radio_buttons;            // 0x1FC
    short num_radio_buttons;                 // 0x200
    ulong button_down_time;                  // 0x204
    ulong text_color1[9];                    // 0x208
    ulong text_color2[9];                    // 0x22C
    ulong highlight_text_color1[9];          // 0x250
    ulong highlight_text_color2[9];          // 0x274
    long hotkey;                             // 0x298
    int hotkey_shift;                        // 0x29C
    int bevel_type;                          // 0x2A0
    uchar bevel_color1;                      // 0x2A4
    uchar bevel_color2;                      // 0x2A5
    uchar bevel_color3;                      // 0x2A6
    uchar bevel_color4;                      // 0x2A7
    uchar bevel_color5;                      // 0x2A8
    uchar bevel_color6;                      // 0x2A9
    long key_down;                           // 0x2AC
    int disabled;                            // 0x2B0
    int sound_number;                        // 0x2B4

    virtual void set_rect(long param_1, long param_2, long param_3, long param_4); // vt0[3]+0xC=0x4727F0 | vt0[193]+0x304=0x4727F0
    virtual void draw();                                    // vt0[12]+0x30=0x4728C0 | vt0[202]+0x328=0x4728C0
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4); // vt0[18]+0x48=0x473890 | vt0[208]+0x340=0x473890
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[22]+0x58=0x4735B0 | vt0[212]+0x350=0x4735B0
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5); // vt0[28]+0x70=0x473120 | vt0[218]+0x368=0x473120
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[33]+0x84=0x473190 | vt0[223]+0x37C=0x473190
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[35]+0x8C=0x473240 | vt0[225]+0x384=0x473240
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[36]+0x90=0x473310 | vt0[226]+0x388=0x473310
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt0[37]+0x94=0x473180 | vt0[227]+0x38C=0x473180
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4); // vt0[38]+0x98=0x4733A0 | vt0[228]+0x390=0x4733A0
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4); // vt0[40]+0xA0=0x473450 | vt0[230]+0x398=0x473450
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4); // vt0[41]+0xA4=0x473520 | vt0[231]+0x39C=0x473520
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4); // vt0[42]+0xA8=0x473390 | vt0[232]+0x3A0=0x473390
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x4736F0 | vt0[233]+0x3A4=0x4736F0
    virtual long char_action(long param_1, short param_2);  // vt0[44]+0xB0=0x473920 | vt0[234]+0x3A8=0x473920
    virtual void stop_sound_system();                       // vt0[52]+0xD0=0x473BC0 | vt0[242]+0x3C8=0x473BC0
    virtual int restart_sound_system();                     // vt0[53]+0xD4=0x473BE0 | vt0[243]+0x3CC=0x473BE0
    virtual void set_state(short param_1);                  // vt0[56]+0xE0=0x472700 | vt0[246]+0x3D8=0x472700
    virtual int hit_button(long param_1, long param_2);     // vt0[57]+0xE4=0x473930 | vt0[247]+0x3DC=0x473930
    TButtonPanel();
    ~TButtonPanel();
    long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, DrawType param_7, TDigital* param_8, NotifyType param_9, long param_10);
    ButtonType buttonType();
    DrawType drawType();
    NotifyType notifyType();
    void setDrawType(DrawType param_1);
    void setButtonType(ButtonType param_1);
    void set_picture_info(TShape* param_1, short param_2, long param_3, long param_4, int param_5, int param_6);
    void set_text_info(char* param_1, void* param_2, long param_3, long param_4, long param_5, long param_6);
    void set_text_info(long param_1, void* param_2, long param_3, long param_4, long param_5, long param_6);
    void set_text_pos(long param_1, long param_2);
    void set_radio_info(TButtonPanel** param_1, short param_2);
    void set_state_info(short param_1);
    void set_id(short param_1, long param_2, long param_3);
    void set_picture(short param_1, TShape* param_2, short param_3);
    void set_text(short param_1, char* param_2);
    void set_text(short param_1, char* param_2, char* param_3);
    void set_text(short param_1, long param_2);
    void set_text(short param_1, long param_2, long param_3);
    void set_font(void* param_1, long param_2, long param_3);
    void set_text_color(int param_1, ulong param_2, ulong param_3);
    void set_highlight_text_color(int param_1, ulong param_2, ulong param_3);
    void set_sound(TDigital* param_1);
    void set_radio_button();
    void set_state_by_id(long param_1);
    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    void set_disabled(int param_1);
    int get_state();
    long get_id();
    long get_id2();
    int get_text(short param_1, char** param_2, char** param_3);
    void get_text_color(short param_1, ulong* param_2, ulong* param_3);
    void do_action();
    void do_right_action(int param_1);
    void reset();
    void set_sound_number(int param_1);
};

static_assert(sizeof(TButtonPanel) == 0x2B8, "TButtonPanel Size Mismatch");

