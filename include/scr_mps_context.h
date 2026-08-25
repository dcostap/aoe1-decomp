#ifndef AOE1_SCR_MPS_CONTEXT_H
#define AOE1_SCR_MPS_CONTEXT_H

// Authentic shared declaration surface for C:\\msdev\\work\\age1_x1\\scr_mps.cpp.
// Owner bodies keep their isolated declarations for standalone checks.  The
// wrapper defines SCR_MPS_TU_CONTEXT so this surface joins them in PDB order.

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <io.h>

#ifndef CSTR
#define CSTR(address) ((char*)(address))
#endif

struct tagRECT;
class TDrawArea;
class TTextPanel;
class TButtonPanel;
class TDropDownPanel;
class TEditPanel;
class TScrollBarPanel;
class TInputPanel;
class TListPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class RGE_Prog_Info;
class RGE_Scenario;
class RGE_Scenario_Header;
class RGE_Static_Object;

class RGE_Prog_Info {
public:
    char gap_00[0xC17];
    char scenario_dir[1];
};

enum FormatType {
    FORMAT_TYPE_DEFAULT = 0
};

enum PLAYERHUMANITY {
    ME_ABSENT = 0,
    ME_HUMAN = 2,
    ME_COMPUTER = 4
};

class TPanel {
public:
    enum PositionMode {
        POSITION_MODE_DEFAULT = 0
    };
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_rect(tagRECT);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual void set_tab_order(TPanel**, short);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_04[0xD4];
    union {
        int field_D8;
        int setup_failed;
    };
    char gap_DC[0x18];

    void delete_panel(TPanel** panel_ptr);
    void delete_panel(void* panel_ptr);
    void set_curr_child(TPanel* child);
    void set_help_info(long help_id, long page_id);
    char* panelName();
    void update();
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void set_text(char*);
    virtual void set_text(long);
    virtual void set_text(char**, short);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    virtual char* currentLine();
    int numberLines();
    int delete_line(long index);
    int word_wrap_append(char* msg);
    void scroll(unsigned char, int, int);
    void set_alignment(int vertical, int horizontal);
    void empty_list();
    void set_text_color(unsigned long, unsigned long);
    void set_text_color(int, unsigned long, unsigned long);
    void set_enabled(int);

    void* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
    void* font;
    long font_wid;
    long font_hgt;
    long vert_align;
    long horz_align;
    int word_wrap;
    long text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlight_text_color1;
    unsigned long highlight_text_color2;
};

class TButtonPanel : public TPanel {
public:
    virtual void set_state(short state);
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;
    void set_text(short state, char* text);
    void set_text(short state, long string_id);
    void set_id(short state, long id, long id2);
    long get_id();
    int get_state();
    void set_state_by_id(long id);
    int get_text(short, char**, char**);
    void get_text_color(short, unsigned long*, unsigned long*);
    void set_text_color(unsigned long, unsigned long);
    void set_text_color(int, unsigned long, unsigned long);
    void set_state_info(short state_count);
    void set_disabled(int disabled);
    void set_active(int active);
};

class TDropDownPanel : public TPanel {
public:
    char gap_F4[0x10];
    int mode;
    TTextPanel* list_panel;
    void set_draw_style(int style);
    void set_draw_val_rect(int enabled);
    void empty_list();
    int append_line(long string_id, long value);
    int append_line(char* text, long value);
    long get_id();
    long get_id(int index);
    long get_line(long index);
    long get_line();
    long set_line(long line);
    int delete_line(long line);
    int insert_line(long line, char* text, long value);
    char* get_text();
    void set_val_text_color(unsigned long, unsigned long);
};

class TEditPanel : public TTextPanel {
public:
    int active;
};

class TScrollBarPanel : public TPanel {
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x228];
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char gap_326[0x152];

    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long, int);
    long setup(void*, char*, long, int);
    void setup_shadow_area(int force_rebuild);
    void set_ideal_size(long width, long height);
    int create_text(TPanel*, TTextPanel**, long, long, long, long, long, long, long, long, long);
    int create_text(TPanel*, TTextPanel**, char*, long, long, long, long, long, long, long, long);
    int create_button(TPanel*, TButtonPanel**, long, long, long, long, long, long, long, long, long);
    int create_button(TPanel*, TButtonPanel**, char*, char*, long, long, long, long, long, long, long);
    int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    int create_edit(TPanel*, TEditPanel**, char*, short, FormatType, long, long, long, long, long, int, int);
    int create_drop_down(TPanel*, TDropDownPanel**, long, long, long, long, long, long, long);
    int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    long action(TPanel*, long, unsigned long, unsigned long);
    char* get_string(int id);
    void popupYesNoDialog(char*, char*, int, int);
    void popupOKDialog(int, char*, int, int);
    void popupOKDialog(char*, int, int, int);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(void*, char*, long, int);
    char* get_string(int id);
    char* get_string(int id, char* buffer, int length);
};

class TChat {
public:
    void ClearChat();
    void setInChatGroup(int group, int enabled);
    void setWindowHandle(void* hwnd);
    char* GetChatMsg(int n);
};

class TDebuggingLog {
public:
    void Log(const char* format, ...);
    static void __cdecl Log(TDebuggingLog*, const char*, ...);
};

class TCommunications_Handler {
public:
    int IsHost();
    int WhoAmI();
    int AllPlayersReady();
    int GetPlayerHumanity(int player);
    char* GetPlayerName(int player);
    void SetPlayerHumanity(int player, int humanity);
    void SetMyReadiness(int, int, int, int, int, int, int, int);
    int SetMyReadiness(int, unsigned long, unsigned long, unsigned long,
                       unsigned long, unsigned long, unsigned long, unsigned long);
    int GetClientReadiness(unsigned int, int*, unsigned long*, unsigned long*,
                           unsigned long*, unsigned long*, unsigned long*,
                           unsigned long*, unsigned long*);
    int IsPlayerReady(unsigned int player);
    void LaunchMultiplayerGame();
    void SetWindowHandle(void* hwnd);
    int IsLobbyLaunched();
    long SendSharedData(int send_mode);
    void SendChatMsgAll(char* text);
    void Kick(int player);
    int IsPlayerHuman(int player);
    void UnlinkToLevel(int service);
};

class RGE_Communications : public TCommunications_Handler {
};

class RGE_Communications_Addresses {
public:
    RGE_Communications_Addresses(RGE_Communications*);
    ~RGE_Communications_Addresses();
    char* GetHostName();
    char* GetAddress(unsigned int);
    char* GetAlias(unsigned int);
    char gap_0[0x220];
    unsigned int num_addr;
};

class TPanelSystem {
public:
    int destroyPanel(char* name);
    int setCurrentPanel(char* name, int value);
    TPanel* panel(char* name);
    TEasy_Panel* currentPanel();
};

class TribeSelectScenarioScreen {
public:
    char gap[0x4D8];
    TribeSelectScenarioScreen();
};

class TribeSPMenuScreen {
public:
    char gap[0x49C];
    TribeSPMenuScreen();
};

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    char gap_478[0xC];
    TRIBE_Screen_Main_Error();
    void set_text(int string_id);
};

class TribeJoinScreen {
public:
    char gap[0x4B0];
    TribeJoinScreen();
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
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();

    char gap_04[8];
    RGE_Prog_Info* prog_info;
    char gap_10[0x3C];
    TDrawArea* draw_area;
    char gap_50[0x188];
    int input_enabled;

    int run_game();
    char* get_string(int, char*, int);
    int multiplayerGame();
    int singlePlayerGame();
    int scenarioGame();
    int randomGame();
    int allowCheatCodes();
    int fullVisibility();
    unsigned char pathFinding();
    unsigned char mpPathFinding();
    int difficulty();
    int mapSize();
    int mapType();
    int victoryType();
    int victoryAmount();
    int startingAge();
    int resourceLevel();
    unsigned char deathMatch();
    unsigned char popLimit();
    int numberPlayers();
    unsigned char playerVersion(int player);
    char* playerVersionString(int player);
    int check_for_cd(int player);
    int playerHasCD(int player);
    void setPlayerHasCD(int player, int value);
    int playerTeam(int player);
    void setPlayerTeam(int player, int team);
    char* scenarioName();
    void setScenarioName(char* name);
    void setCampaignGame(int value);
    void setSavedGame(int value);
    int setScenarioGame(int value);
    void setNumberPlayers(int value);
    void setFullVisibility(int value);
    void setFogOfWar(int value);
    void setAllowCheatCodes(int value);
    void enable_input();
    void disable_input();
    void close();
    void beginStartGame();
    int get_single_player_difficulty();
    void setDifficulty(int value);
    void setDeathMatch(unsigned char value);
    void setQuickStartGame(unsigned char value);
    RGE_Scenario* get_scenario_info(char* name, int campaign);
    long get_scenario_checksum(char* name);
    void setLongCombat(int value);
    void setAllowTrading(int value);
    void setFullTechTree(int value);
    void setResourceLevel(int value);
    void setStartingAge(int value);
    void setStartingUnits(int value);
    void setPlayerVersion(int player, unsigned char version);
    void setComputerName(int player, char* name);
    void setMapSize(int value);
    void setMapType(int value);
    void setVictoryType(int value);
    void setAnimals(int value);
    void setPredators(int value);
    void setRandomizePositions(int value);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    int playerColor(int player);
    void setPlayerColor(int player, int color);
    int civilization(int player);
    void setCivilization(int player, int civilization);
    int scenarioPlayer(int player);
    void setScenarioPlayer(int player, int scenario_player);
    int randomizePositions();
    int start_game(int param);
    int fullTechTree();
    void quit_game();
    void setVictoryType(int type, int amount);
};

class TribeGameSettingsScreen : public TScreenPanel {
public:
    char gap_478[0xE8];
    TribeGameSettingsScreen();
};

class T_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~T_Scenario();
    virtual void rehook();
    virtual void save(int file);
    int any_sp_victory();
};

class RGE_Scenario : public T_Scenario {
public:
    int Get_player_Active(int index);
    int Get_player_Civ(int index);
    int Get_player_Type(int index);
};

class TribeMPSetupScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* playerTitle;
    TTextPanel* civTitle;
    TTextPanel* settingsTitle;
    TTextPanel* colorTitle;
    TTextPanel* teamTitle;
    TTextPanel* playerNameText[8];
    TTextPanel* playerCivText[8];
    TTextPanel* scenarioPlayerText[8];
    TTextPanel* playerCDText[8];
    TTextPanel* playerVersionText[8];
    TTextPanel* playerColorText[8];
    TTextPanel* playerTeamText[8];
    TButtonPanel* playerColor[8];
    TButtonPanel* playerTeam[8];
    TDropDownPanel* playerNameDrop[8];
    TDropDownPanel* playerCivDrop[8];
    TDropDownPanel* scenarioPlayerDrop[8];
    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    TTextPanel* chatBox;
    TScrollBarPanel* chatScrollbar;
    TButtonPanel* gameSettingsButton;
    TTextPanel* scenarioName;
    TTextPanel* victoryFixedText;
    TTextPanel* settingText[20];
    TTextPanel* settingValue[20];
    TTextPanel* mapSizeLabel;
    TDropDownPanel* mapSizeDrop;
    TTextPanel* mapTypeLabel;
    TDropDownPanel* mapTypeDrop;
    TTextPanel* numberPlayersTitle;
    TDropDownPanel* numberPlayersDrop;
    TTextPanel* numberPlayersText;
    TButtonPanel* hiddenMapButton;
    TTextPanel* hiddenMapText;
    TTextPanel* victoryTypeLabel;
    TDropDownPanel* victoryTypeDrop;
    TTextPanel* victoryAmountLabel;
    TEditPanel* victoryAmountInput;
    TButtonPanel* startButton;
    TButtonPanel* readyButtons[2];
    TButtonPanel* cancelButton;
    TButtonPanel* help_button;
    TButtonPanel* ready_button;
    TButtonPanel* close_button;
    TTextPanel* ready_button_label;
    int cancelMode;
    int playerToKick;
    int scenarioPlayerCount;
    int myCivilization;
    int myScenarioPlayer;
    int myPlayerColor;
    int myPlayerTeam;
    long myScenarioChecksum;
    char saveScenarioName[256];
    int saveRandomGame;
    long saveScenarioChecksum;
    RGE_Scenario* scenarioInfo;
    int settingsFixed;
    int numberAnyPlayers;
    int sent_cd_status;
    TButtonPanel* netInfoButton;
    int i_am_ready;
    unsigned char defaultColor[8];
    int scenarioCheckSum[8];
    union {
        unsigned long last_send_shared;
        int pad_888;
    };
    int resend_game_options;

    virtual ~TribeMPSetupScreen();
    TribeMPSetupScreen();

protected:
    void init_vars();
    int startGame();
    void calcRandomPositions();
    void showNetInfo();
    void cancelScreen(int);
    void fillChat(int);
    void kickPlayer(int);
    void handleKickedPlayer(int);
    void activateVictoryPanels();
    void setupTabOrder();
    void setupSinglePlayerPlayers();
    void fillNumberPlayers();
    void fillPlayerColors();

public:
    long handle_idle();
    long key_down_action(long, short, int, int, int);
    long action(TPanel*, long, unsigned long, unsigned long);
    long handle_user_command(unsigned int, long);
    long handle_timer_command(unsigned int, long);
    void fillPlayers();
    void updateSummary();
    char* get_string(int);
    char* get_string(int, char*, int);
    void setup_popup_help();
    void OKDialog(char*, int, int, int);
    void ErrorDialog(int, int, int, int);
    void popupOKDialog(int, int, int, int);
    void popupOKDialog(char*, int, int, int);
};

class TRIBE_Screen_Wait : public TScreenPanel {
public:
    union {
        TTextPanel* message;
        TTextPanel* member_478;
    };
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;
    TTextPanel* scenarioName;
    TTextPanel* settingText[20];
    virtual ~TRIBE_Screen_Wait();
    TRIBE_Screen_Wait();
    void set_text(char*);
    void set_text(long);
    long action(TPanel*, long, unsigned long, unsigned long);
    long handle_idle();
};

class TRIBE_Screen_Disconnect : public TScreenPanel {
public:
    int mode;
    union {
        TTextPanel* message;
        TTextPanel* member_47C;
    };
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;
    virtual ~TRIBE_Screen_Disconnect();
    virtual long handle_idle();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    TRIBE_Screen_Disconnect(int);
    void set_text(char*);
    void set_text(long);
};

extern TChat* chat;
extern TDebuggingLog* L;
extern RGE_Communications* comm;
extern TRIBE_Game* rge_base_game;
extern TPanelSystem panel_system;
extern void* AppWnd;
extern char s_Multiplayer_Disconnect_Screen[];
extern char s_scr3[];
extern char s_Status_Screen[];
extern const char s_C__msdev_work_age1_x1_scr_mps_cp[];

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" char* __cdecl strcat(char*, const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" unsigned long __cdecl debug_timeGetTime(const char*, int);
extern "C" void __cdecl debug_srand(char*, int, unsigned long);
extern "C" int __cdecl debug_rand(char*, int);
extern "C" void __cdecl Log(TDebuggingLog*, const char*, ...);

#endif
