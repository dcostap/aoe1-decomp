#ifndef SCR_SAVE_CONTEXT_H
#define SCR_SAVE_CONTEXT_H

#include <stdio.h>

// Shared class surface for the PDB-owned scr_save.cpp translation unit.
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TButtonPanel;
class TTextPanel;
class TEditPanel;
class TInputPanel;
class TListPanel;
class TDropDownPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class TSound_Driver;
class TCommunications_Handler;
class RGE_Player;
class RGE_Sound;
class RGE_Scenario;
struct RGE_Player_Info;

enum FormatType {
    FormatSingleLine = 0,
    FormatFileName = 5,
    FormatMultiLine = 7
};

class TPanel {
public:
    enum PositionMode { PositionFixed = 0 };
    enum RedrawMode { RedrawNormal = 0 };

    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
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

    char gap_04[0xD4];
    int setup_error;
    char gap_DC[0x18];

    char* panelName();
    int get_string(int id, char* dest, int size);
    void set_curr_child(TPanel* child);
    void set_help_info(long id, long param);
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long,
                              long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long,
                              long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long,
                                 long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long,
                                    long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long,
                            long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long,
                            long, long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, FormatType,
                             long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, FormatType,
                            long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long,
                                 long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long,
                            long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);

    char gap_F4[0x384];

    char* get_popup_info_file();
    long get_popup_info_id();
    void setup_shadow_area(int);
    void popupOKDialog(long, char*, long, long);
    void popupYesNoDialog(long, char*, long, long);
    void popupYesNoDialog(char*, char*, long, long);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    int setup(TDrawArea*, char*, long, int);
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x68];
    union {
        int sorted;
        int flag_15c;
    };

    char* currentLine();
    long get_line();
    int delete_line(long);
    void empty_list();
    int append_line(char*, long);
};

class TEditPanel : public TTextPanel {
public:
    void set_text(char*);
    char* get_trimmed_str(char*, int);
};

class TListPanel : public TTextPanel {};
class TScrollBarPanel : public TPanel {};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;
    void set_disabled(int);
};

class TPanelSystem {
public:
    TEasy_Panel* currentPanel();
    TPanel* panel(char* name);
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class RGE_Prog_Info {
public:
    char gap_0000[0xB12];
    char save_dir[0x105];
    char scenario_dir[1];
};

class RGE_Scenario {
public:
    void Set_scenario_name(char* name);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual unsigned char new_random_game(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(char*, RGE_Player_Info*);
    virtual unsigned char load_scenario(RGE_Player_Info&);
    virtual void load_scenario1(int, RGE_Player_Info&);
    virtual void load_scenario2(int, RGE_Player_Info&);
    virtual void load_scenario3(int, RGE_Player_Info&);
    virtual void load_scenario4(int, RGE_Player_Info&);
    virtual void load_scenario5(int, RGE_Player_Info&);
    virtual void load_scenario6(int, RGE_Player_Info&);
    virtual void load_scenario7(int, RGE_Player_Info&);
    virtual void load_scenario8(int, RGE_Player_Info&);
    virtual void logStatus(FILE*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual void setup_player_colors();
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*,
                               TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info*, int);
    virtual unsigned char new_scenario(RGE_Player_Info&, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char* name);

    char gap_004[0x58];
    RGE_Scenario* scenario;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_004[0x08];
    RGE_Prog_Info* prog_info;
    char gap_010[0x3C];
    TDrawArea* draw_area;
    char gap_050[0x198];
    char work_dir[0x20C];
    RGE_Game_World* world;
    char gap_3F8[0x608];
    int save_paused;

    int singlePlayerGame();
    void set_paused(int, int);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char* get_save_game_name();
    int save_game(char* name);
    int save_scenario(char* name);
    void show_status_message(long, long, long);
    int start_menu();
    void close();
    int start_scenario_editor(int, int);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed_Open {
public:
    char gap_000[0x490];
    TRIBE_Screen_Sed_Open();
};

class TribeSaveGameScreen : public TScreenPanel {
public:
    enum Mode {
        SaveGame = 0,
        SaveScenario = 1,
        SaveScenarioEdit = 2
    };

    TribeSaveGameScreen(Mode mode, char* name, int quit_after_save);
    virtual ~TribeSaveGameScreen();

protected:
    TTextPanel* title;
    TEditPanel* input;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* deleteButton;
    char fileName[260];
    char fileNameNoExt[260];
    Mode modeValue;
    int quit_after_save;

    void fillList();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void save_for_scenario_editor();
};

void* operator new(unsigned int size);

typedef char scr_save_tpanel_size[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char scr_save_teasy_size[(sizeof(TEasy_Panel) == 0x478) ? 1 : -1];
typedef char scr_save_screen_size[(sizeof(TribeSaveGameScreen) == 0x6A4) ? 1 : -1];

#endif
