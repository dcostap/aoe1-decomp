#ifndef SCR_CAMS_CONTEXT_H
#define SCR_CAMS_CONTEXT_H

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef int PositionMode;
typedef int RedrawMode;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

class TDrawArea;
class RGE_Static_Object;

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
    virtual void set_string(long);
    virtual void set_string(char*);

    char gap_004[0xF0];

    void delete_panel(TPanel** panel);
    void set_tab_order(TPanel** list, int count);
    void set_curr_child(TPanel* panel);
};

class TTextPanel : public TPanel {
public:
    char gap_0F4[0x68];
    long sort_flag;

    void empty_list();
    int append_line(char* text, long value);
    long get_line(long value);
    void set_line(long line);
    long get_line();
    long get_id();
    void scroll_cur_line(uchar direction, short line, int update_scrollbar);
};

class TDropDownPanel : public TPanel {
public:
    void empty_list();
    int append_line(long string_id, long value);
    long get_line(long value);
    void set_line(long line);
    long get_id();
};

class TButtonPanel : public TPanel {
public:
    char gap_0F4[0x1A4];
    int hotkey;
    int hotkey_shift;
};

class TEasy_Panel : public TPanel {
public:
    char gap_0F4[0x384];

    virtual ~TEasy_Panel();
    virtual long action(TPanel*, long, ulong, ulong);

    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel*, TPanel**, long, long, long, long, long, long, long,
                    long, long);
    int create_list(TPanel*, TPanel**, long, long, long, long, long);
    int create_auto_scrollbar(TPanel**, TTextPanel*, long);
    int create_drop_down(TPanel*, TPanel**, long, long, long, long, long, long,
                         long);
    int create_button(TPanel*, TButtonPanel**, long, long, long, long, long,
                      long, long, long, long);
    void popupOKDialog(long, char*, int, int);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    virtual long handle_idle();
    long setup(TDrawArea* area, char* prefix, int id, int flag);
};

class RGE_Game_Info {
public:
    long get_campaign_list(char*** list, long& current);
    long get_scenario_list(char*** list, long& current);
    uchar set_current_campaign(long id);
    uchar set_current_scenario(int id);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Game_Info* game_info;
    char gap_008[0x44];
    TDrawArea* draw_area;
    char gap_050[0x188];
    int input_enabled;

    int difficulty();
    int get_single_player_difficulty();
    void setDifficulty(int value);
    void disable_input();
    void enable_input();
    void close();
};

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~RGE_Scenario();
    int Get_player_Type(int player);
    int Get_player_Active(int player);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void setScenarioGame(int);
    void setCampaignGame(int);
    void setSavedGame(int);
    void setDifficulty(int);
    void set_single_player_difficulty(int);
    void setFullVisibility(int);
    void setFogOfWar(int);
    void setAllowCheatCodes(int);
    void setNumberPlayers(int);
    RGE_Scenario* get_scenario_info(int, int);
    void setPlayerTeam(int, int);
    void setVictoryType(int, int);
    void setDeathMatch(uchar);
    void setQuickStartGame(uchar);
    void setAnimals(int);
    void setPredators(int);
    void setScenarioPlayer(int, int);
    int scenarioPlayer(int);
    void setPlayerColor(int, int);
    int playerColor(int);
    void setAllowTrading(int);
    void setLongCombat(int);
    void setRandomizePositions(int);
    void setFullTechTree(int);
    void setResourceLevel(int);
    void setStartingAge(int);
    void setStartingUnits(int);
    int start_game(int);
};

class TCommunications_Handler {
public:
    void setPlayerHumanity(int player, int type);
};

class TPanelSystem {
public:
    int setCurrentPanel(const char* name, int modal);
    int destroyPanel(const char* name);
};

class TRIBE_Screen_Name {
public:
    char data[0x4A0];
    TRIBE_Screen_Name();
};

class TRIBE_Screen_Campaign_Selection : public TScreenPanel {
public:
    TPanel* title;
    int campaignListX;
    int campaignListY;
    int campaignListWidth;
    int campaignListHeight;
    TPanel* campaignTitle;
    TTextPanel* campaignList;
    TPanel* campaignScrollbar;
    int scenarioListX;
    int scenarioListY;
    int scenarioListWidth;
    int scenarioListHeight;
    TPanel* scenarioTitle;
    TTextPanel* scenarioList;
    TPanel* scenarioScrollbar;
    TPanel* difficultyTitle;
    TDropDownPanel* difficultyDrop;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* close_button;
    int campaignsLoaded;

    TRIBE_Screen_Campaign_Selection();
    virtual ~TRIBE_Screen_Campaign_Selection();
    virtual long handle_idle();

protected:
    virtual long action(TPanel*, long, ulong, ulong);

    void init_vars();
    void fillCampaigns();
    void fillScenarios();
    void startGame();
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TPanelSystem panel_system;

#endif
