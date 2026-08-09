// VA: 004AD960 TRIBE_Screen_Sed::command_save_as
// Attempt log:
// baseline: natural scr_sed.cpp reconstruction with the proven scenario world,
// validation gates, and Save Game Screen construction surface.
// probe: default flags omitted the original EH registration (224 bytes, frame 0xE0).
// probe: /GX restored the 0xE4 frame and all 10 ordered calls, but emitted 313 bytes.
// probe: nested/positive guards, returns, gotos, and a do/while were tested; the
// do/while and positive form merged the two popup call sites, while nested negative
// guards returned to the same 313-byte /GX basin.
// probe: pointer-overlay struct added 8 bytes; a union overlay was codegen-neutral.
// blocker: original popup failures jump at 004AD9BD/004AD9EA to one cleanup at
// 004ADA58; VC5 keeps separate /GX cleanup-and-return blocks for the natural source,
// leaving +41 bytes past the original boundary despite matching frame and calls.
// FLAGS: config/flags/004AD960_command_save_as.rsp (/GX; original EH frame and
// same-TU command_save donor both require the historical exception basin).
// Main-agent audit restored canonical world/panel destructor ownership; emitted
// code and the shared-cleanup blocker are unchanged.

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class T_Scenario {
public:
    void Save_victory_conditions_into_players(int flag);
};

class RGE_Scenario : public T_Scenario {
public:
    int active_player_count();
    int any_player_count();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x58];
    T_Scenario* scenario;
};

class TribeSaveGameScreen {
public:
    TribeSaveGameScreen(int mode, char* name, int quit_after_save);
    char gap_00[0x6A4];
};

class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_04[0x474];
    void popupOKDialog(long text_id, char* panel_name, long param_4, long param_5);
};

class TScreenPanel : public TEasy_Panel {
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_0478[0x4B0];
    RGE_Game_World* world;

    void set_scenario_mode(int mode);
    void command_save_as(unsigned char post_action);
};

void TRIBE_Screen_Sed::command_save_as(unsigned char post_action)
{
    char scenario_name[224];

    this->set_scenario_mode(11);
    this->world->scenario->Save_victory_conditions_into_players(1);
    if (((RGE_Scenario*)this->world->scenario)->active_player_count() < 1) {
        this->popupOKDialog(0x2742, (char*)0, 0x1C2, 100);
    } else {
        if (((RGE_Scenario*)this->world->scenario)->any_player_count() < 1) {
            this->popupOKDialog(0x2743, (char*)0, 0x1C2, 100);
        } else {
            scenario_name[4] = 0;
            new TribeSaveGameScreen(2, scenario_name + 4, post_action);
            panel_system.setCurrentPanel((char*)0x005843B8, 0);
            panel_system.destroyPanel((char*)0x005843CC);
        }
    }
}
