#ifndef SCR_CRED_CONTEXT_H
#define SCR_CRED_CONTEXT_H

// Canonical scr_cred.cpp screen surface.  The class order follows the PDB
// source order.  The virtual declarations preserve the period UI slots.
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawSystem;
class TDrawArea;
class TShape;
class TMusic_System;
class PanelNode;
class RGE_Color_Table;
class TPanel;
class TTextPanel;
class TScrollTextPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long,
                                 long, long, long, TPanel*, TPanel*, TPanel*,
                                 TPanel*);
    virtual void vslot_1c();
    virtual void set_redraw(int);
    virtual void vslot_24();
    virtual void vslot_28();
    virtual void vslot_2c();
    virtual void vslot_30();
    virtual void vslot_34();
    virtual void vslot_38();
    virtual void vslot_3c();
    virtual void vslot_40();
    virtual void vslot_44();
    virtual void vslot_48();
    virtual void vslot_4c();
    virtual void vslot_50();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, uint, uint, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(uint, long);
    virtual long handle_user_command(uint, long);
    virtual long handle_timer_command(uint, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, ulong, ulong);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0x10];
    long width;
    long height;
    char gap_1c[4];
    union {
        TDrawArea* render_area;
        int field_20;
    };
    long field_24;
    char gap_28[0xb0];
    int error_code;
    char gap_dc[0x18];

    char* get_string(int resource_id);
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_f4[0x110];
    union {
        TShape* background_pic;
        TShape* field_204;
    };
    TShape* background_pic2;
    void* palette_handle;
    char gap_210[0x268];

    virtual ~TEasy_Panel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual long action(TPanel*, long, ulong, ulong);
    void set_ideal_size(long width, long height);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    virtual void draw();
    long setup(TDrawArea* draw_area, char* name, long id, int value);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x34];
    void* DrawDc;

    void GetPalette(tagPALETTEENTRY* entries);
    void Clear(void* rect, long flags);
    void* GetDc(char* unused);
    void ReleaseDc(char* unused);
};

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
    unsigned char ScreenMode;

    void Paint(tagRECT* rect);
    void SetPalette(void* palette);
};

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x48];
    TDrawArea* draw_area;
    char gap_50[0x14];
    TMusic_System* music_system;
    char gap_68[0x998];
    int save_paused;

    RGE_Font* get_font(int font_id);
    int singlePlayerGame();
    void set_paused(int a, int b);
};

extern RGE_Base_Game* rge_base_game;

class TPanelSystem {
public:
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TTextPanel : public TPanel {
public:
    char gap_f4[0x2c];
    unsigned long text_color1;
    unsigned long text_color2;
    char gap_128[0x60];

    TTextPanel();
    virtual ~TTextPanel();
    virtual void set_text(char* text);
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, void* font, long font_wid,
               long font_hgt, char* back_pic, char* fill_back,
               int back_color, int outline, uchar outline_color,
               short fixed_len, char* text);
    void set_alignment(int vertical, int horizontal);
    void set_word_wrap(int value);
    void set_text_color(unsigned long color1, unsigned long color2);
};

class TScrollTextPanel : public TTextPanel {
public:
    int scroll;
    unsigned long last_time;
    int speed;
    int done;

    virtual ~TScrollTextPanel();
    virtual void set_text(char* text);
    virtual long handle_idle();
    virtual void draw();

    TScrollTextPanel(TPanel* parent, TDrawArea* draw_area, long x, long y,
                     long width, long height, int speed_value, void* font,
                     long font_wid, long font_hgt, char* text);
    void draw_scrolled_line(void* hdc, short draw_index, short line_index,
                            ulong color1, ulong color2);
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char* filename, long file_id);
    ~TShape();
};

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;
    char gap_105[0x143];
    int track_count;

    int play_tracks(int from, int to, int loop_value, int make_current,
                    unsigned long position);
};

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    TScrollTextPanel* text_panel;
    int text_set;
    int picture_set;
    unsigned long last_picture_time;
    unsigned long last_pause_time;
    int mode;
    tagPALETTEENTRY color_table[256];
    tagPALETTEENTRY color;
    TShape* back_pics[7];
    int first_draw;
    int text_done;

    virtual ~TRIBE_Credits_Screen();
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_idle();
    virtual void draw();
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, ulong, ulong);
    void close_screen();
    TRIBE_Credits_Screen();
};

class TRIBE_Screen_Main_Menu {
public:
    char gap[0x4b0];
    TRIBE_Screen_Main_Menu();
};

#endif
