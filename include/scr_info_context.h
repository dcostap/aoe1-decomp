#ifndef AOE1_SCR_INFO_CONTEXT_H
#define AOE1_SCR_INFO_CONTEXT_H

// Canonical scr_info.cpp screen surface.
// PDB source: C:\\msdev\\work\\age1_x1\\scr_info.cpp
// The hierarchy and offsets follow the period TPanel/TEasy_Panel/
// TScreenPanel surface used by the neighboring screen donors.

typedef unsigned char uchar;

class TDrawArea;
class TPanel;
class TButtonPanel;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(struct tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(struct tagRECT*);
    virtual void draw_offset(long, long, struct tagRECT*);
    virtual void draw_rect2(struct tagRECT*);
    virtual void draw_offset2(long, long, struct tagRECT*);
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

    char gap_04[0x18];
    char* panel_name;                 // +0x1C
    char gap_20[0xD4];                 // TPanel size 0xF4
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];               // TEasy_Panel size 0x478
    virtual ~TEasy_Panel();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(void* draw_area, char* info, long id, long value);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    void* draw_area;                   // +0x4C
    void enable_input();
    void disable_input();
    void close();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int start_menu();
};

extern TRIBE_Game* rge_base_game;
extern unsigned long debug_timeGetTime(const char* file, int line);

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TribeSPMenuScreen {
public:
    char gap[0x49C];
    TribeSPMenuScreen();
};

class TRIBE_Screen_Main_Menu {
public:
    char gap[0x4B0];
    TRIBE_Screen_Main_Menu();
};

class TRIBE_Screen_Info : public TScreenPanel {
public:
    int auto_close;                    // +0x478
    unsigned long timer;               // +0x47C
    unsigned long last_time;           // +0x480

    TRIBE_Screen_Info(char* name, char* info, long id, unsigned long timer_value);
    virtual ~TRIBE_Screen_Info();
    virtual long handle_idle();
    virtual long key_down_action(long, short, int, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void close_screen();
};

#endif
