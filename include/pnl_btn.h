#ifndef AOE1_PNL_BTN_H
#define AOE1_PNL_BTN_H

// PDB source: C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp.
// This header owns TButtonPanel.
#include "panel.h"

class TDrawArea;
class TShape;
class TDigital;

class TButtonPanel : public TPanel {
public:
    enum ButtonType { Normal = 1, Radio = 2, State = 3 };
    enum DrawType {
        DrawClear = 1,
        DrawText = 2,
        DrawPicture = 3,
        DrawPictureAndText = 4,
        DrawFillAndText = 5,
        DrawBevelPicture = 6
    };
    enum NotifyType { NotifyAction = 1, NotifyMessage = 2 };

    long id[9];
    long id2[9];
    ButtonType buttonTypeValue;
    DrawType drawTypeValue;
    NotifyType notifyTypeValue;
    TDigital* sound;
    TShape* pic[9];
    short pic_index[9];
    unsigned char gap_182[2];
    int auto_pic_pos;
    long pic_x;
    long pic_y;
    int all_hot;
    int draw_reverse;
    char* text1[9];
    char* text2[9];
    long text_x;
    long text_y;
    void* font;
    long font_wid;
    long font_hgt;
    short num_states;
    short cur_state;
    int is_down;
    TButtonPanel** radio_buttons;
    short num_radio_buttons;
    unsigned char gap_202[2];
    unsigned long button_down_time;
    unsigned long text_color1[9];
    unsigned long text_color2[9];
    unsigned long highlight_text_color1[9];
    unsigned long highlight_text_color2[9];
    long hotkey;
    int hotkey_shift;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char gap_2AA[2];
    long key_down;
    int disabled;
    int sound_number;

    virtual ~TButtonPanel();
    TButtonPanel();
    virtual void set_rect(long, long, long, long);
    long setup(TDrawArea*, TPanel*, long, long, long, long, DrawType,
               TDigital*, NotifyType, long);
    ButtonType buttonType() const;
    DrawType drawType() const;
    NotifyType notifyType() const;
    void setDrawType(DrawType);
    void setButtonType(ButtonType);
    void set_picture_info(TShape*, short, long, long, int, int);
    void set_text_info(char*, void*, long, long, long, long);
    void set_text_info(long, void*, long, long, long, long);
    void set_text_pos(long, long);
    void set_radio_info(TButtonPanel**, short);
    void set_state_info(short);
    void set_id(short, long, long);
    void set_picture(short, TShape*, short);
    void set_text(short, char*);
    void set_text(short, char*, char*);
    void set_text(short, long);
    void set_text(short, long, long);
    void set_font(void*, long, long);
    void set_text_color(int, unsigned long, unsigned long);
    void set_highlight_text_color(int, unsigned long, unsigned long);
    void set_sound(TDigital*);
    void set_radio_button();
    virtual void set_state(short);
    void set_state_by_id(long);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_disabled(int);
    int get_state();
    long get_id();
    long get_id2();
    int get_text(short, char**, char**);
    void get_text_color(short, unsigned long*, unsigned long*);
    virtual void draw();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long handle_key_down(long, short, int, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long char_action(long, short);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual int hit_button(long, long);
    void do_action();
    void do_right_action(int);
    void reset();
    void set_sound_number(int);
};

typedef char pnl_btn_tbutton_size_check[
    (sizeof(TButtonPanel) == 0x2B8) ? 1 : -1];

#endif
