#ifndef AOE1_SCR_STMS_CONTEXT_H
#define AOE1_SCR_STMS_CONTEXT_H

// Canonical scr_stms.cpp surface. The member gaps preserve the reviewed
// TScreenPanel size (0x478) and the status message field at +0x478.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
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
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char pad_TPanel[0x40];
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    void set_ideal_size(int width, int height);
    long create_text(TPanel* panel, TPanel** text_field, const char* text,
                     int x, int y, int width, int height,
                     int a8, int a9, int a10, int a11);
    char* get_info_file();
    long get_info_id();
    char gap_44[0x94];
    int setup_failed;
    char gap_DC[0x39C];
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(const char* name);
    virtual ~TScreenPanel();
    virtual void draw();
    long setup(void* draw_area, char* info, long param, int zero);
};

// TTextPanel's method order is established by the panel-list context. The
// status helpers use the long overload at +0xE4 and char* overload at +0xE8.
class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char**, short);
    virtual void set_text(long text_id);
    virtual void set_text(char* text);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
};

typedef TTextPanel MemberType;

class TPanelSystem {
public:
    TPanel* currentPanel();
    TPanel* panel(const char* name);
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;
    int multiplayerGame();
};

extern void* rge_base_game;

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    union {
        TPanel* message;
        TTextPanel* member_478;
    };

    TRIBE_Screen_Status_Message(char* panel_name, char* text,
                                char* info_file, long info_id);
    TRIBE_Screen_Status_Message(char* panel_name, long text_id,
                                char* info_file, long info_id);
    virtual ~TRIBE_Screen_Status_Message();
    virtual void draw();
    void set_text(char* text);
    void set_text(long text_id);
};

#endif
