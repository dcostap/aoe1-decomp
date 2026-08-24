#ifndef AOE1_DLG_CONF_TU_CONTEXT_H
#define AOE1_DLG_CONF_TU_CONTEXT_H

// Source-module context for C:\\msdev\\work\\age1_x1\\dlg_conf.cpp.
// The three owners use one panel hierarchy.  This header joins their
// declarations without adding wrappers or changing an owner ABI.
#include <windows.h>

class TDrawSystem;
class TDrawArea;
class TPanel;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class TScreenPanel;
class TMusic_System;
class TSound_Driver;
class RGE_Prog_Info;
class RGE_Game_World;
class TCommunications_Handler;
class TRegistry;
class TPanelSystem;
class TRIBE_Command;

class TDrawArea {
public:
    TDrawSystem* draw_system;
    char gap_04[0x14];
    long Width;
    long Height;
};

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
                                 long, long, TPanel*, TPanel*, TPanel*,
                                 TPanel*);
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

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    void* first_child_node;
    void* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    long z_order;
    long display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    TDrawArea* renderArea();
    char* get_string(int);
    void set_curr_child(TPanel*);
    void set_tab_order(TPanel**, int);
    void delete_panel(TPanel**);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual ~TEasy_Panel();
    long get_popup_info_id();
    char* get_popup_info_file();
    int create_text(TPanel*, TTextPanel**, int, long, long, long, long,
                    long, int, int, int);
    int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long,
                            long, long);
    int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long, long,
                           long, long, long, long);
    int create_button(TPanel*, TButtonPanel**, int, long, long, long, long,
                      long, long, long, long);
    void prepare_for_close();
};

class TDialogPanel : public TEasy_Panel {
public:
    void* dlg_wnd;
    TPanel* save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;

    virtual ~TDialogPanel();
    TDialogPanel(char*);
    int setup(TDrawArea*, TPanel*, long, long, char*, long, int);
};

class TTextPanel : public TPanel {
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;

    int get_state();
    void set_radio_info(TPanel*, int);
    void set_disabled(int);
    void set_radio_button();
};

class TScrollBarPanel : public TPanel {
public:
    void set_tab_pos(int);
};

class TVerticalSliderPanel : public TScrollBarPanel {
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TDrawSystem {
public:
    char gap_00[0x2C];
    long width;

    int IsModeAvail(long, long, int);
};

class RGE_Prog_Info {
public:
    char gap_000[0x8A4];
    int use_music;
    char gap_8A8[0x20];
    long mouse_scroll_interval;
    long key_scroll_interval;
    char gap_8D4[8];
    short interface_style;
    char gap_8DE[0x12A];
    int rollover;
};

class RGE_Game_World {
public:
    char gap_00[0x18];
    float game_speed;
    char gap_1C[0x3C];
    TRIBE_Command* commands;
};

#define DLG_CONF_VPAD1(n) virtual void dlg_conf_vslot##n();
#define DLG_CONF_VPAD2(n) DLG_CONF_VPAD1(n) DLG_CONF_VPAD1(n##_1)
#define DLG_CONF_VPAD4(n) DLG_CONF_VPAD2(n) DLG_CONF_VPAD2(n##_2)
#define DLG_CONF_VPAD8(n) DLG_CONF_VPAD4(n) DLG_CONF_VPAD4(n##_4)
#define DLG_CONF_VPAD16(n) DLG_CONF_VPAD8(n) DLG_CONF_VPAD8(n##_8)
#define DLG_CONF_VPAD32(n) DLG_CONF_VPAD16(n) DLG_CONF_VPAD16(n##_16)

class RGE_Base_Game {
public:
    DLG_CONF_VPAD16(0)
    DLG_CONF_VPAD4(16)
    DLG_CONF_VPAD2(20)
    virtual void vf58();
    virtual void vf5C();
    DLG_CONF_VPAD32(24)
    DLG_CONF_VPAD16(56)
    DLG_CONF_VPAD8(72)
    virtual void vf140();

    char gap_04[8];
    RGE_Prog_Info* prog_info;
    char gap_10[0x50];
    TSound_Driver* sound_system;
    TMusic_System* music_system;
    char gap_68[0x148];
    int prog_mode;
    char gap_1B4[0x240];
    RGE_Game_World* world;
    char gap_3F8[0x608];
    int save_paused;
    char gap_A04[4];
    int rollover;

    int singlePlayerGame();
    int multiplayerGame();
    unsigned char mpPathFinding();
    unsigned char pathFinding();
    void set_paused(int, int);
    void setPathFinding(unsigned char);
    void set_game_speed(float);
    void set_screen_size(long, long);
};

#undef DLG_CONF_VPAD32
#undef DLG_CONF_VPAD16
#undef DLG_CONF_VPAD8
#undef DLG_CONF_VPAD4
#undef DLG_CONF_VPAD2
#undef DLG_CONF_VPAD1

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;
    char gap_105[3];
    char gap_108[0x140];
    int track_count;
    char gap_24C[8];
    long volume;

    void set_volume(long, int);
    int play_tracks(int, int, int, int, unsigned long);
};

class TSound_Driver {
public:
    long get_volume();
    void set_volume(long, int);
};

class TCommunications_Handler {
public:
    int WhoAmI();
    char* GetPlayerName(unsigned int);
    void SendChatMsgAll(const char*);
};

class TRegistry {
public:
    int RegSetInt(int, const char*, int);
};

class TRIBE_Command {
public:
    void command_game_speed(float);
};

class TPanelSystem {
public:
    int setCurrentPanel(char*, int);
    int destroyPanel(char*);
};

class TribeConfigDialog : public TDialogPanel {
public:
    enum Mode {
        InGame = 0
    };

    Mode modeValue;
    TTextPanel* title;
    TTextPanel* speedTitle[4];
    TButtonPanel* speedButton[3];
    TTextPanel* musicTitle[3];
    TVerticalSliderPanel* musicSlider;
    TTextPanel* soundTitle[3];
    TVerticalSliderPanel* soundSlider;
    TTextPanel* scrollSpeedTitle[3];
    TVerticalSliderPanel* scrollSpeedSlider;
    TTextPanel* sizeTitle[4];
    TButtonPanel* sizeButton[3];
    TTextPanel* mouseTitle[3];
    TButtonPanel* mouseButton[2];
    TTextPanel* rolloverTitle[3];
    TButtonPanel* rolloverButton[2];
    TTextPanel* pathFindingTitle[4];
    TButtonPanel* pathFindingButton[3];
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    long musicVolume;
    long soundVolume;
    float gameSpeed;
    long scrollSpeed;
    long newMusicVolume;
    long newSoundVolume;

    virtual ~TribeConfigDialog();
    TribeConfigDialog(Mode, TScreenPanel*);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TRegistry* Regs;
extern TPanelSystem panel_system;
extern int allow_user_commands;
extern unsigned char do_color_log;
extern "C" int numberPathingIterations;

extern float DAT_0056f740;
extern float DAT_0056f744;
extern float DAT_0056f748;

#endif
