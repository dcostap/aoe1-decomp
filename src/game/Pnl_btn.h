#pragma once
#include "../common.h"

typedef enum ActionType : unsigned int {
    ActionSelect = 1,
    ActionDown = 2,
    ActionUp = 3,
    ActionRightSelect = 4,
    ActionRightDown = 5,
    ActionRightUp = 6,
};

typedef enum ButtonType : unsigned int {
    Normal = 1,
    Radio = 2,
    State = 3,
};

typedef enum DrawType : unsigned int {
    DrawClear = 1,
    DrawPicture = 2,
    DrawTextA = 3,
    DrawPictureAndText = 4,
    DrawFillAndText = 5,
    DrawBevelPicture = 6,
};

typedef enum NotifyType : unsigned int {
    NotifyAction = 1,
    NotifyCommand = 2,
};

typedef enum BevelType : unsigned int {
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

    TButtonPanel();
    virtual ~TButtonPanel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, DrawType param_7, TDigital* param_8, NotifyType param_9, long param_10);
    virtual ButtonType buttonType();
    virtual DrawType drawType();
    virtual NotifyType notifyType();
    virtual void setDrawType(DrawType param_1);
    virtual void setButtonType(ButtonType param_1);
    virtual void set_picture_info(TShape* param_1, short param_2, long param_3, long param_4, int param_5, int param_6);
    virtual void set_text_info(char* param_1, void* param_2, long param_3, long param_4, long param_5, long param_6);
    virtual void set_text_info(long param_1, void* param_2, long param_3, long param_4, long param_5, long param_6);
    virtual void set_text_pos(long param_1, long param_2);
    virtual void set_radio_info(TButtonPanel** param_1, short param_2);
    virtual void set_state_info(short param_1);
    virtual void set_id(short param_1, long param_2, long param_3);
    virtual void set_picture(short param_1, TShape* param_2, short param_3);
    virtual void set_text(short param_1, char* param_2);
    virtual void set_text(short param_1, char* param_2, char* param_3);
    virtual void set_text(short param_1, long param_2);
    virtual void set_text(short param_1, long param_2, long param_3);
    virtual void set_font(void* param_1, long param_2, long param_3);
    virtual void set_text_color(int param_1, ulong param_2, ulong param_3);
    virtual void set_highlight_text_color(int param_1, ulong param_2, ulong param_3);
    virtual void set_sound(TDigital* param_1);
    virtual void set_radio_button();
    virtual void set_state(short param_1);
    virtual void set_state_by_id(long param_1);
    virtual void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    virtual void set_disabled(int param_1);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    virtual int get_state();
    virtual long get_id();
    virtual long get_id2();
    virtual int get_text(short param_1, char** param_2, char** param_3);
    virtual void get_text_color(short param_1, ulong* param_2, ulong* param_3);
    virtual void draw();
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_left_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_down_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_move_action(long param_1, long param_2, int param_3, int param_4);
    virtual long mouse_right_up_action(long param_1, long param_2, int param_3, int param_4);
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
    virtual long char_action(long param_1, short param_2);
    virtual int hit_button(long param_1, long param_2);
    virtual void do_action();
    virtual void do_right_action(int param_1);
    virtual void reset();
    virtual void set_sound_number(int param_1);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
};

static_assert(sizeof(TButtonPanel) == 0x2B8, "TButtonPanel Size Mismatch");
static_assert(offsetof(TButtonPanel, sound_number) == 0x2B4, "TButtonPanel Offset Mismatch");

