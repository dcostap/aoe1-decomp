#ifndef SCR_END_CONTEXT_H
#define SCR_END_CONTEXT_H

// Shared scr_end.cpp recovery surface.  The declarations follow the period UI
// hierarchy and preserve the vtable slots used by all three owners.
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef int PositionMode;
typedef int RedrawMode;

#ifndef _WINDEF_
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif

class TDrawArea {
public:
    char gap_00[0x18];
    long width;
};

class TDigital;
class TButtonPanel;
class TTextPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;

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
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
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
    TDrawArea* render_area;
    char gap_24[0x1c];
    void* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x14];
    void* clip_rgn;
    tagRECT render_rect;
    char gap_9c[0x3c];
    int setup_error;
    char gap_dc[4];
    int display_changed_count;
    char gap_e4[0x10];

    char* get_string(int resource_id);
    int get_string(int resource_id, char* buffer, int length);
    void set_curr_child(TPanel* child);
};

class TEasy_Panel : public TPanel {
public:
    char gap_f4[0x384];

    virtual ~TEasy_Panel();
    long action(TPanel*, long, ulong, ulong);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw_area, char* info_file, long info_id, int param);
};

class TPicturePanel : public TPanel {
public:
    char gap_f4[0x28];

    virtual ~TPicturePanel();
    TPicturePanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, char* picture, long resource,
               int size_from_picture, int keep_loaded);
};

class TTextPanel : public TPanel {
public:
    char gap_f4[0x94];

    virtual void set_text(char**, short);
    TTextPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, void* font, long font_width,
               long font_height, char* back_picture, int fill,
               uchar back_color, int outline, uchar outline_color,
               short fixed_len, char* text);
    void set_alignment(int vertical, int horizontal);
    void scroll(uchar mode, short line, int update);
};

class TButtonPanel : public TPanel {
public:
    char gap_f4[0x1a4];
    long hotkey;
    long hotkey_shift;
    char gap_2a0[0x18];

    virtual ~TButtonPanel();
    TButtonPanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, long draw_type, TDigital* sound,
               long notify_type, long button_id);
    void set_text_info(char* text, void* font, long font_width,
                       long font_height, long text_x, long text_y);
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
    RGE_Font* get_font(int index);
    TDigital* get_sound(int index);
};

extern RGE_Base_Game* rge_base_game;

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int modal);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TShape;
class Time_Line_Panel;

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;
    int current_mode;
    int size;
    TTextPanel* title;
    TTextPanel* summary_text;
    TTextPanel* instruction;
    TTextPanel* win_loss_text;
    TTextPanel* time;
    TTextPanel* title_bar[7];
    TTextPanel* achievement_choice[5];
    TTextPanel* statistics[8][7];
    TTextPanel* player_names[8];
    TScrollBarPanel* summary_text_bar;
    TScrollBarPanel* instruction_bar;
    TScrollBarPanel* win_loss_text_bar;
    TButtonPanel* okButton;
    TButtonPanel* backButton;
    TButtonPanel* backButton2;
    TButtonPanel* timelineButton;
    TButtonPanel* aftermathButton;
    TButtonPanel* restartButton;
    TButtonPanel* close_button;
    TShape* win_decal;
    Time_Line_Panel* time_line;

    virtual ~TribeAchievementsScreen();
    TribeAchievementsScreen(char* summary_text, int end_game_flag);
};

class TribeEndScreen : public TScreenPanel {
public:
    TPicturePanel* background;
    TTextPanel* title;
    TTextPanel* text;
    TButtonPanel* okButton;

    virtual ~TribeEndScreen();
    TribeEndScreen(char* title_text, char** text_list, int text_count);
    virtual long action(TPanel*, long, ulong, ulong);
};

#endif
