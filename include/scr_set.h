#ifndef AOE1_SCR_SET_H
#define AOE1_SCR_SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int PositionMode;
typedef int RedrawMode;
typedef int FormatType;

struct tagRECT { long left; long top; long right; long bottom; };
class TPanel;
class TTextPanel;
class TButtonPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TInputPanel;
class TEditPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class TDrawArea;
class PanelNode;
class RGE_Scenario_File_Info;
class RGE_Scenario_Header;
class TCommunications_Handler;
class TribeMPSetupScreen;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void setVisible(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual void setTabList(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    void delete_panel(TPanel**);
    void set_curr_child(TPanel*);
    void set_help_info(long, long);
    int get_string(int, char*, int);
    char* get_string(int);
    char* panelName();

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    tagRECT clip_rect;
    PositionMode position_mode;
    RedrawMode need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
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
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};

typedef char scr_set_tpanel_size[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    // BINARY NOTE: VC5 emits this overload set at +0xE0, +0xE4, +0xE8 in
    // reverse declaration order. Keep this order for the original slots.
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    char gap_F4[0x68];
    union { int sorted; int flag_15c; };
    void empty_list();
    int append_line(char*, long);
    int append_line(char*, char*, long);
    int append_line(long, long);
    int append_line(long, long, long);
    void set_second_column_pos(long);
    void set_alignment(int, int);
    void set_spacer_size(int);
    long get_line();
    long get_line(char*);
    long get_line(long);
    int get_id();
    long get_id(long);
    char* get_text();
    char* get_text(long);
    int numberLines();
    void change_line(long, char*, char*, long);
};

class TListPanel : public TTextPanel {
public:
    int auto_track;
    unsigned long mouse_scroll_last_time;
    unsigned long mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;
    void setDrawHighlightBar(int);
    void scroll_cur_line(unsigned char, short, int);
    int insert_line(long, char*, char*, long);
};

class TScrollBarPanel : public TPanel {};

class TButtonPanel : public TPanel {
public:
    long id[9]; long id2[9];
    int buttonTypeValue; int drawTypeValue; int notifyTypeValue; void* sound;
    void* pic[9]; short pic_index[9]; unsigned char pad_182[2];
    int auto_pic_pos; long pic_x; long pic_y; int all_hot; int draw_reverse;
    char* text1[9]; char* text2[9]; long text_x; long text_y; void* font;
    long font_wid; long font_hgt; short num_states; short cur_state; int is_down;
    TButtonPanel** radio_buttons; short num_radio_buttons; unsigned char pad_202[2];
    unsigned long button_down_time; unsigned long text_color1[9];
    unsigned long text_color2[9]; unsigned long highlight_text_color1[9];
    unsigned long highlight_text_color2[9]; long hotkey; long hotkey_shift;
    int bevel_type; unsigned char bevel_color1; unsigned char bevel_color2;
    unsigned char bevel_color3; unsigned char bevel_color4; unsigned char bevel_color5;
    unsigned char bevel_color6; unsigned char pad_2AA[2]; long key_down;
    int disabled; int sound_number;
    virtual void set_state(int); int get_state();
};

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel; TButtonPanel* btn_panel; TListPanel* list_panel;
    TScrollBarPanel* scbar_panel; int mode; short val_num; unsigned char pad_10A[2];
    long val_wid; long val_hgt; long btn_wid; long btn_hgt; long list_wid;
    long list_hgt; long scbar_wid; long scbar_arrow_hgt; long scbar_tab_hgt;
    unsigned char list_is_above; unsigned char pad_131[3]; long font_hgt;
    int outline_color; int draw_style; int draw_val_rect;
    void empty_list();
    int append_line(char*, long);
    int append_line(long, long);
    void set_line(long); long get_line(long); long get_id();
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width; long ideal_height; char info_file_name[260]; long info_id;
    void* background_pic; void* background_pic2; void* palette;
    char cursor_file[260]; long cursor_id; int background_pos; int use_bevels;
    unsigned char bevel_color1, bevel_color2, bevel_color3, bevel_color4,
                  bevel_color5, bevel_color6; unsigned char pad_326[2];
    unsigned long text_color1, text_color2, focus_color1, focus_color2,
                  state_color1, state_color2;
    char popup_info_file_name[260]; long popup_info_id; void* button_pics;
    void* shadow_color_table; long shadow_amount; unsigned char background_color1;
    unsigned char background_color2; unsigned char pad_456[2]; int enable_ime;
    unsigned char help_mode; unsigned char pad_45D[3]; int stock_brush; void* brush;
    unsigned long brush_color; TDrawArea* shadow_area; int allow_shadow_area;
    int saved_mouse_mode;

    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long, int);
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, int, long, long, long, long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long, long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long, long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long, long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, FormatType, long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, FormatType, long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long, long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long, long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long, long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long, long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
    void setup_shadow_area(int);
    void setup_popup_help();
    void popupOKDialog(long, char*, long, long);
};

typedef char scr_set_teasy_size[(sizeof(TEasy_Panel) == 0x478) ? 1 : -1];

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char*);
    virtual ~TScreenPanel();
};

class TPanelSystem {
public:
    TPanel* panel(char*);
};
extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[4];
    RGE_Scenario_File_Info* scenario_info;
    char gap_0C[0x40];
    TDrawArea* draw_area;
    char gap_50[0x188];
    int input_enabled;
    int multiplayerGame();
    int scenarioGame();
    int randomGame();
    int singlePlayerGame();
    void enable_input();
    char* scenarioName();
    int allowCheatCodes(); int fullVisibility(); int difficulty();
    unsigned char mpPathFinding(); unsigned char pathFinding(); unsigned char popLimit();
    int resourceLevel(); int startingAge();
    void setScenarioGame(int); void setScenarioName(char*); void setAllowCheatCodes(int);
    void setFullVisibility(int); void setPathFinding(unsigned char); void setMpPathFinding(unsigned char);
    void setDifficulty(int); void set_single_player_difficulty(int);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    unsigned char deathMatch();
    int mapSize(); int mapType(); int victoryType(); int victoryAmount();
    int randomizePositions(); int fullTechTree(); void setMapSize(int);
    void setMapType(int); void setVictoryType(int, int); void setDeathMatch(unsigned char);
    void setRandomizePositions(unsigned char); void setFullTechTree(int); void setResourceLevel(int);
    void setStartingAge(int); void setPopLimit(unsigned char);
};
extern TRIBE_Game* rge_base_game;

class RGE_Scenario_Header {
public:
    char gap_00[0x10]; char* description; int fixed_players; int player_count;
};
class RGE_Scenario_File_Info {
public:
    void reload_scenarios(); char* get_scenario_name(int); RGE_Scenario_Header* get_scenario_info(int);
};

class TCommunications_Handler {
public:
    long SendSharedData(int);
};
extern TCommunications_Handler* comm;
extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);

class TribeMPSetupScreen : public TPanel {};

class TribeGameSettingsScreen : public TScreenPanel {
public:
    TTextPanel* title; int state; TTextPanel* mapSizeLabel; TDropDownPanel* mapSizeDrop;
    TTextPanel* mapTypeLabel; TDropDownPanel* mapTypeDrop; TTextPanel* victoryTypeLabel;
    TDropDownPanel* victoryTypeDrop; TTextPanel* victoryFixedText; TTextPanel* percentLabel;
    TTextPanel* scoreLabel; TDropDownPanel* scoreDrop; TTextPanel* timeLabel; TDropDownPanel* timeDrop;
    TTextPanel* difficultyLabel; TDropDownPanel* difficultyDrop; TTextPanel* ageLabel; TDropDownPanel* ageDrop;
    TTextPanel* resourcesLabel; TDropDownPanel* resourcesDrop; TTextPanel* pathingLabel; TDropDownPanel* pathingDrop;
    TTextPanel* limitLabel; TDropDownPanel* limitDrop; TTextPanel* scenarioTitle; TTextPanel* scenarioPlayersTitle;
    long scenarioListX, scenarioListY, scenarioListWidth, scenarioListHeight;
    TListPanel* scenarioList; TScrollBarPanel* scenarioScrollbar; int scenarioCount;
    char** scenarioMission; int* scenarioFixed; int scenariosLoaded; TTextPanel* missionTitle;
    long missionTextX, missionTextY, missionTextWidth, missionTextHeight;
    TTextPanel* missionText; TScrollBarPanel* missionScrollbar;
    union { TButtonPanel* optionButton[4]; struct { TButtonPanel* optionButton0; TButtonPanel* optionButton1; TButtonPanel* optionButton2; TButtonPanel* optionButton3; }; };
    union { TTextPanel* optionText[4]; struct { TTextPanel* optionText0; TTextPanel* optionText1; TTextPanel* optionText2; TTextPanel* optionText3; }; };
    TButtonPanel* okButton; TButtonPanel* cancelButton; TButtonPanel* help_button;
    TribeMPSetupScreen* chat_scr; int last_scenario_line; int scenario_line_offset;
    unsigned long last_send_shared;

    TribeGameSettingsScreen();
    virtual ~TribeGameSettingsScreen();
    virtual long handle_idle();
    virtual long handle_user_command(unsigned int, long);
protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void init_vars(); void fillScenarios(); void getSettings(); void fillMissionText();
    void sendSettings(); void activatePanels(); void activateVictoryPanels();
};

typedef char scr_set_screen_size[(sizeof(TribeGameSettingsScreen) == 0x560) ? 1 : -1];

#endif
