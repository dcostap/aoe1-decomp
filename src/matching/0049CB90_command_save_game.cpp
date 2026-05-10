// 0049CB90 TRIBE_Screen_Game::command_save_game
// 132 bytes, __thiscall, scr_game.cpp lines 5453-5459
// Attempt log:
// - Previous scratch was incomplete (only lazy new), producing a 64-byte too-short text window.
// - 2026-05-10 StarryZephyr pass: rewrote with natural typed /GX new-expression and setCurrentPanel call.

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

class TribeSaveGameScreen {
public:
    char gap_00[0x6A4];
    TribeSaveGameScreen(int type, char* file, int flags);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int flags);
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern char Save_Game_Screen[];

class TRIBE_Screen_Game {
public:
    char gap_00[0x5B4];
    RGE_Game_World* world;

    void command_save_game();
};

void TRIBE_Screen_Game::command_save_game() {
    if (rge_base_game->prog_mode == 6) {
        this->world->command->do_commands();
    }
    new TribeSaveGameScreen(0, 0, 0);
    panel_system.setCurrentPanel(Save_Game_Screen, 0);
}
