#ifndef AOE1_SCR_SING_CONTEXT_H
#define AOE1_SCR_SING_CONTEXT_H

// Canonical panel declaration surface for C:\\msdev\\work\\age1_x1\\Scr_sing.cpp.
// Virtual methods use the reviewed panel slots.  The owner bodies add only
// the module-specific nonvirtual helper and ABI declarations that they call.

struct tagRECT;
class TDrawArea;
class TPanel;
class TTextPanel;
class TButtonPanel;
class RGE_Game_Info;
class TPanelState;

typedef unsigned char uchar;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* draw_area, TPanel* parent, long p3,
                       long p4, long p5, long p6, uchar p7);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(uchar color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);
    virtual void set_fixed_position(long x, long y, long width, long height);
    virtual void set_redraw(int mode);
    virtual void set_overlapped_redraw(TPanel* panel1, TPanel* panel2,
                                       int mode);
    virtual void draw_setup(int mode);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT* rect);
    virtual void draw_offset(long x, long y, tagRECT* rect);
    virtual void draw_rect2(tagRECT* rect);
    virtual void draw_offset2(long x, long y, tagRECT* rect);
    virtual void paint();
    virtual long wnd_proc(void* hwnd, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual long handle_idle();
    virtual long handle_size(long width, long height);
    virtual long handle_paint();
    virtual long handle_key_down(long key, short repeat, int ctrl, int shift,
                                 int alt);
    virtual long handle_char(long key, short repeat);
    virtual long handle_command(unsigned int command, long param);
    virtual long handle_user_command(unsigned int command, long param);
    virtual long handle_timer_command(unsigned int command, long param);
    virtual long handle_scroll(long scroll, long param);
    virtual long handle_mouse_down(uchar button, long x, long y, int ctrl,
                                   int shift);
    virtual long handle_mouse_move(long x, long y, int ctrl, int shift);
    virtual long handle_mouse_up(uchar button, long x, long y, int ctrl,
                                 int shift);
    virtual long handle_mouse_dbl_click(uchar button, long x, long y, int ctrl,
                                        int shift);
    virtual long mouse_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_down_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_hold_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_up_action(long x, long y, int ctrl, int shift);
    virtual long mouse_left_dbl_click_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_down_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_hold_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_move_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_up_action(long x, long y, int ctrl, int shift);
    virtual long mouse_right_dbl_click_action(uchar button, long x, long y,
                                              int ctrl, int shift);
    virtual long key_down_action(long key, short repeat, int ctrl, int shift,
                                 int alt);
    virtual long char_action(long key, short repeat);
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);
    virtual void get_true_render_rect(tagRECT* rect);
    virtual int is_inside(long x, long y);
    virtual void set_focus(int focus);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[0x20];
    TPanelState* field_3C;
    char gap_40[0x98];
    int setup_error;
    char gap_DC[0x18];

    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** panels, int count);
    void delete_panel(TPanel** panel);
};

typedef char scr_sing_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TTextPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;

    void set_text(short value, short lang_id);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    long create_text(TPanel* panel, TPanel** text_field, unsigned short lang_id,
                     int x, int y, int width, int height,
                     int a8, int a9, int a10, int a11);
    long create_button(TPanel* panel, TPanel** button_field, const char* name,
                       int a4, int a5, int a6, int a7, int a8, int a9,
                       int a10, int a11);
    void set_ideal_size(int width, int height);
    long action(TPanel* panel, long code, unsigned long p3, unsigned long p4);
};

typedef char scr_sing_teasy_size_check[(sizeof(TEasy_Panel) == 0x478) ? 1 : -1];

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(const char* name);
    virtual ~TScreenPanel();
    long setup(void* draw_area, const char* name, int p3, int p4);
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
};

class RGE_Base_Game {
public:
    char gap_00[0x04];
    RGE_Game_Info* player_game_info;
    char gap_08[0x44];
    void* draw_area;
    char gap_50[0x188];
    int input_enabled;

    void setSinglePlayerGame(int value);
    void setScenarioName(const char* name);
    void setCampaignGame(int value);
    void setSavedGame(int value);
    void setScenarioGame(int value);
    void setDeathMatch(unsigned char value);
    void setQuickStartGame(unsigned char value);
    void disable_input();
    void enable_input();
    void close();
};

class RGE_Game_Info {
public:
    long get_people_list(char*** list, long& count);
};

class TPanelSystem {
public:
    int setCurrentPanel(const char* name, int value);
    int destroyPanel(const char* name);
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;

class TribeSPMenuScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TButtonPanel* button[7];
    TButtonPanel* close_button;

    TribeSPMenuScreen();
    virtual ~TribeSPMenuScreen();
    virtual long handle_idle();
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);
};

typedef char scr_sing_screen_size_check[(sizeof(TribeSPMenuScreen) == 0x49C) ? 1 : -1];

class TribeMPSetupScreen : public TScreenPanel {
public:
    TribeMPSetupScreen();
    char gap[0x890 - 0x478];
};

class TribeSelectScenarioScreen : public TScreenPanel {
public:
    TribeSelectScenarioScreen();
    char gap[0x4D8 - 0x478];
};

class TribeLoadSavedGameScreen : public TScreenPanel {
public:
    TribeLoadSavedGameScreen();
    char gap[0x494 - 0x478];
};

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TRIBE_Screen_Name();
    char gap[0x4A0 - 0x478];
};

class TRIBE_Dialog_Name : public TDialogPanel {
public:
    TRIBE_Dialog_Name(TribeSPMenuScreen* parent);
    char gap[0x4A4 - 0x490];
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TRIBE_Screen_Main_Menu();
    char gap[0x4B0 - 0x478];
};

#endif
