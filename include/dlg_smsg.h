#ifndef AOE1_DLG_SMSG_H
#define AOE1_DLG_SMSG_H

// Declarations used by C:\\msdev\\work\\age1_x1\\dlg_smsg.cpp.

typedef unsigned char uchar;
typedef unsigned long ulong;

typedef int PositionMode;
typedef int RedrawMode;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TPanel;
class TTextPanel;
class TEditPanel;
class TButtonPanel;
class TShape;
class TScreenPanel;
class TInputPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class RGE_Color_Table;
class RGE_Player;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Scenario_Header;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
                                  long, long, TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual void draw_background(int);

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long width;
    long height;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    PositionMode position_mode;
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
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    uchar mouse_action;
    uchar mouse_down_button;
    uchar panel_type;
    uchar color;
    uchar fill_in_background;
    uchar clip_to_parent;
    uchar draw_rect2_flag;
    uchar need_restore;

    TDrawArea* renderArea();
    void set_help_info(long, long);
    void set_curr_child(TPanel*);
    void delete_panel(TPanel**);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
};

class TEditPanel : public TTextPanel {
public:
    virtual ~TEditPanel();
    char* currentLine();
    void set_text(char*);
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;
    int get_state();
    void set_radio_info(TPanel*, int);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();
    long get_popup_info_id();
    char* get_popup_info_file();
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long,
                            long, int, int, int);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, long, long, long,
                            long, long, long, int, int);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long,
                                 long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long,
                                    long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long, long,
                              long, long, long, long);
    void setup_popup_help();
};

class TScreenPanel : public TEasy_Panel {
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    TDialogPanel(char*);
    virtual ~TDialogPanel();
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char*, int);
    ~TShape();
    uchar shape_draw(TDrawArea*, long, long, long, uchar, uchar*);
};

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
    uchar table[0x100];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);

    char gap_04[0x46];
    short id;
    char gap_4C[0x34];
    uchar game_status;
    char gap_81[0x84];
    uchar master_player_id;
    char gap_106[2];
    RGE_Color_Table* color_table;
};

class RGE_Game_World {
public:
    virtual uchar data_load_world(void*);
    unsigned int world_time;
    char gap_08[0x38];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual void language(int, int, int, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);

    char gap_04[0x1AC];
    int prog_mode;
    char gap_1B4[0x240];
    RGE_Game_World* world;

    int playerID(int);
    int multiplayerGame();
    int numberPlayers();
    int play_sound(int);
};

class TCommunications_Handler {
public:
    int GetPlayerHumanity(int);
    char* GetPlayerName(int);
    int WhoAmI();
    void SendGroupChatMsg(char*);
};

class TChat {
public:
    int inChatGroup(int);
    void setInChatGroup(int, int);
};

class TPanelSystem {
public:
    int setCurrentPanel(char*, int);
    int destroyPanel(char*);
};

class TDebuggingLog {
public:
    void Log(const char*, ...);
};

class TRIBE_Screen_Game {
public:
    void display_system_message(char*);
};

extern TPanelSystem panel_system;
extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TChat* chat;
extern TDebuggingLog* L;
extern void* operator new(unsigned int);
extern void __cdecl operator_delete(void*);
extern "C" void __cdecl _ASMSet_Color_Xform(int);

class TribeSendMessageDialog : public TDialogPanel {
public:
    TTextPanel* title;
    TTextPanel* playerName[8];
    TTextPanel* playerCivilization[8];
    TButtonPanel* checkButton[8];
    TTextPanel* radioTitle[4];
    TButtonPanel* radioButton[4];
    TShape* radioButtonShapes;
    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    TButtonPanel* okButton;
    TButtonPanel* help_button;
    TShape* backgroundPics;
    int commPlayers[8];

    TribeSendMessageDialog(TScreenPanel*);
    virtual ~TribeSendMessageDialog();

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void draw();
    void checkButtons();
};

class TribeSendQuickMessageDialog : public TDialogPanel {
public:
    enum Mode { AsChat = 0, AsTaunt = 1 };

    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    Mode modeValue;

    TribeSendQuickMessageDialog(TScreenPanel*, Mode);
    virtual ~TribeSendQuickMessageDialog();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_mouse_down(uchar, long, long, int, int);
};

typedef char dlg_smsg_panel_size[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char dlg_smsg_dialog_size[(sizeof(TDialogPanel) == 0x490) ? 1 : -1];
typedef char dlg_smsg_message_size[(sizeof(TribeSendMessageDialog) == 0x54C) ? 1 : -1];

typedef char dlg_smsg_quick_size[(sizeof(TribeSendQuickMessageDialog) == 0x49C) ? 1 : -1];

#endif
