#pragma once

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;
class RGE_Scenario_File_Info;
class RGE_Base_Game;
class TRIBE_Game;
class TPanelSystem;
class TPanelState;

extern char s_Select_Scenario_Screen[];
extern char s_scr2[];
extern char s_scr3[];
extern char s_592A40[];
extern TRIBE_Game* rge_base_game;
extern TPanelSystem panel_system;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* draw_area, TPanel* parent, long p3,
                       long p4, long p5, long p6, unsigned char p7);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);

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
    virtual long handle_key_down(long key, short repeat, int ctrl,
                                 int shift, int alt);
    virtual long handle_char(long key, short repeat);
    virtual long handle_command(unsigned int command, long param);
    virtual long handle_user_command(unsigned int command, long param);
    virtual long handle_timer_command(unsigned int command, long param);
    virtual long handle_scroll(long scroll, long param);
    virtual long handle_mouse_down(unsigned char button, long x, long y,
                                   int ctrl, int shift);
    virtual long handle_mouse_move(long x, long y, int ctrl, int shift);
    virtual long handle_mouse_up(unsigned char button, long x, long y,
                                 int ctrl, int shift);
    virtual long handle_mouse_dbl_click(unsigned char button, long x, long y,
                                        int ctrl, int shift);
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
    virtual long mouse_right_dbl_click_action(unsigned char button, long x, long y,
                                              int ctrl, int shift);
    virtual long key_down_action(long key, short repeat, int ctrl,
                                 int shift, int alt);
    virtual long char_action(long key, short repeat);
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);
    virtual void get_true_render_rect(tagRECT* rect);
    virtual int is_inside(long x, long y);
    virtual void set_focus(int focus);
    virtual void set_tab_order(TPanel* first, TPanel* second);
    virtual void set_tab_order(TPanel** panels, short count);
    virtual unsigned char get_help_info(char** text, long* page, long p3,
                                        long p4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    void set_help_info(long help_id, long page_id);
    void set_curr_child(TPanel* child);
    void delete_panel(TPanel** panel);
};

class TPanelState {
public:
    char gap_00[0x6C];
    TPanel* child;
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_text(char** texts, short count);
    virtual void set_text(long string_id);
    virtual void set_text(char* text);
    virtual void set_bevel_info(int mode, int c1, int c2, int c3, int c4,
                                int c5, int c6);
    char gap_F4[0x68];
    int field_15c;

    void set_second_column_pos(long position);
    void set_alignment(int vertical, int horizontal);
    void empty_list();
    long get_id(long index);
    char* get_text();
    char* get_text(long index);
    int append_line(char* text, long id);
    int change_line(long index, char* text, char* players, int mode);
    long get_line();
    long get_line(char* text);
};

class TListPanel : public TTextPanel {
public:
    void scroll_cur_line(unsigned char mode, long line, unsigned char center);
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;
};

class TEasy_Panel : public TPanel {
public:
    int ideal_width;
    char gap_F8[0x224];
    int field_31C;
    unsigned char desc[6];
    char gap_326[0x152];

    long setup(TDrawArea* draw_area, TPanel* parent, char* info_file,
               long info_id, int visible, long a, long b, long c,
               long d, int e);
    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
    int create_text(TPanel* parent, TTextPanel** output, char* text,
                    long x, long y, long width, long height,
                    long font, long align, long center, long wrap);
    int create_list(TPanel* parent, TListPanel** output,
                    long x, long y, long width, long height, long lines);
    int create_auto_scrollbar(TScrollBarPanel** output,
                              TTextPanel* text, long width);
    int create_button(TPanel* parent, TButtonPanel** output, long string_id,
                      long text2, long x, long y, long width, long height,
                      long p9, long p10, long p11);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
};

class RGE_Scenario_Header {
public:
    char gap_00[0x10];
    char* description;
    int fixed;
    int num_players;
};

class RGE_Scenario_File_Info {
public:
    void reload_scenarios();
    char* get_scenario_name(int index);
    RGE_Scenario_Header* get_scenario_info(long id);
};

class RGE_Base_Game {
public:
    char gap_00[8];
    RGE_Scenario_File_Info* scenario_info;
    char gap_0C[0x40];
    TDrawArea* draw_area;
    char gap_50[0x188];
    int input_enabled;

    int multiplayerGame();
    void close();
    void disable_input();
    void enable_input();
    char* scenarioName();
    void setScenarioGame(int value);
    void setScenarioName(char* name);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void setDeathMatch(unsigned char value);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int arg);
    int destroyPanel(char* name);
};

class TribeMPSetupScreen {
public:
    TribeMPSetupScreen();
    char pad[0x890];
};

class TribeSPMenuScreen {
public:
    TribeSPMenuScreen();
    char pad[0x49C];
};

class TribeSelectScenarioScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* scenarioTitle;
    TTextPanel* scenarioPlayersTitle;
    long scenarioListX;
    long scenarioListY;
    long scenarioListWidth;
    long scenarioListHeight;
    TListPanel* scenarioList;
    TScrollBarPanel* scenarioScrollbar;
    int scenarioCount;
    char** scenarioMission;
    int* scenarioFixed;
    int scenariosLoaded;
    TTextPanel* missionTitle;
    long missionTextX;
    long missionTextY;
    long missionTextWidth;
    long missionTextHeight;
    TTextPanel* missionText;
    TScrollBarPanel* missionScrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* close_button;
    int last_scenario_line;

    TribeSelectScenarioScreen();
    virtual ~TribeSelectScenarioScreen();
    virtual long handle_idle();

protected:
    virtual long action(TPanel* panel, long event, unsigned long p3,
                        unsigned long p4);
    void init_vars();
    void fillScenarios();
    void getSettings();
    void fillMissionText();
    void sendSettings();
    void activatePanels();
};
