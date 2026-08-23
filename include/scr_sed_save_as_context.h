#ifndef SCR_SED_SAVE_AS_CONTEXT_H
#define SCR_SED_SAVE_AS_CONTEXT_H

// Shared class surface for the ordered scr_sed.cpp owners in scr_sed_save_as_tu.cpp.
class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* render_area, TPanel* parent, long x, long y,
                       long width, long height, unsigned char flags);
    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xB4];
    int setup_error;
    char gap_DC[0x18];
};

class PanelNode;

class TPanelSystem {
public:
    TPanel* mouseOwnerValue;
    TPanel* keyboardOwnerValue;
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    PanelNode* panelListValue;
    int numberActivePanelsValue;
    TPanel* prevCurrentChildValue;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    long palette_id[10];
    unsigned long Imc;
    int ImeEnabled;
    int ImeOn;
    int InputEnabled;
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;
extern char s_Save_Game_Screen[];
extern char s_Scenario_Menu_Dialog[];

class RGE_Static_Object;
struct _iobuf;
typedef struct _iobuf FILE;

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int handle);

    char gap_04[0x198C];

    int active_player_count();
    int any_player_count();
};

class T_Scenario : public RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~T_Scenario();
    virtual void rehook();
    virtual void save(int handle);

    void Save_victory_conditions_into_players(int flag);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    virtual unsigned char data_load_terrain_tables(char* file);
    virtual unsigned char data_load_players(char* file);
    virtual unsigned char data_load_objects(char* file);
    char gap_04[0x58];
    RGE_Scenario* scenario;
    char gap_60[0xA4];
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[0x20];
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    char gap_F4[0x384];
    void popupOKDialog(long text_id, char* panel_name, int param_4, int param_5);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TribeSaveGameScreen : public TScreenPanel {
public:
    enum Mode {
        SaveGame = 0,
        SaveScenario,
        SaveScenarioEdit
    };
    virtual ~TribeSaveGameScreen();
    char gap_0478[0x6A4 - 0x478];
    TribeSaveGameScreen(Mode mode, char* name, int quit_after_save);
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    enum ScenarioMode {
        ScenarioModeNone = 0,
        ScenarioModeMap,
        ScenarioModeTerrain,
        ScenarioModePlayers,
        ScenarioModeUnits,
        ScenarioModeDiplomacy,
        ScenarioModeVictory,
        ScenarioModeVictoryMulti,
        ScenarioModeOptions,
        ScenarioModeMessages,
        ScenarioModeCinematics,
        ScenarioModeSave
    };
    char gap_0478[0x4B0];
    TRIBE_World* world;
    char gap_92C[0x1C];

    void set_scenario_mode(ScenarioMode mode);
    void command_player(int player);
    void command_save_as(unsigned char post_action);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void set_player(short player);
};

extern RGE_Base_Game* rge_base_game;

#endif
