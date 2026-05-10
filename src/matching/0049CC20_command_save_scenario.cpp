// 0049CC20 command_save_scenario
// 132 bytes, __thiscall, TRIBE_Screen_Game method
// FLAGS: config/flags/0049CC20_command_save_scenario.rsp (/GX)
//
// Attempt log:
// - Initial scratch used fake cdecl wrappers and too-small TRIBE_Screen_Game layout, producing only 64 bytes.
// - SpruceGlow MATCH: model world at +0x5B4, use natural member calls for RGE_Command::do_commands,
//   TribeSaveGameScreen ctor, and TPanelSystem::setCurrentPanel. Let `new TribeSaveGameScreen(1,0,0)`
//   drive the /GX allocation/ctor state sequence.
// Result: MATCH locally with `python tools/check_function.py --va 0049CC20`.

class RGE_Command {
public:
    void do_commands();
};

class RGE_Game_World {
public:
    char gap_00[0x58];
    RGE_Command* command;
};

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    unsigned int prog_mode;
};

extern RGE_Base_Game* rge_base_game;

class TribeSaveGameScreen {
public:
    TribeSaveGameScreen(int mode, char* name, int flag);
    char gap_00[0x6A4];
};

class TPanelSystem {
public:
    int setCurrentPanel(const char* name, int flag);
};

extern TPanelSystem panel_system;
extern const char s_Save_Game_Screen[];

class TRIBE_Screen_Game {
public:
    char gap_00[0x5B4];
    RGE_Game_World* world;

    void command_save_scenario();
};

void TRIBE_Screen_Game::command_save_scenario() {
    if (rge_base_game->prog_mode == 6) {
        this->world->command->do_commands();
    }
    new TribeSaveGameScreen(1, 0, 0);
    panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
}
