// 0049C770 TRIBE_Screen_Game::command_menu
// 135 bytes, __thiscall, scr_game.cpp lines 5270-5280
// Attempt log:
// - Previous scratch was incomplete/raw and used wrong dialog size (0x2C8), producing an 80-byte too-short text window.
// - 2026-05-10 StarryZephyr pass: rewrote with natural typed /GX source, following the same command_save_game EH pattern.

#if !defined(SCR_GAME_TU_CONTEXT)
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
    int singlePlayerGame();
    void set_paused(int paused, int unk);
};

class TribeMenuDialog {
public:
    char gap_00[0x4BC];
    TribeMenuDialog(void* screen);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x5B4];
    RGE_Game_World* world;

    void command_menu();
};
#endif

void TRIBE_Screen_Game::command_menu() {
    if (rge_base_game->prog_mode == 6) {
        this->world->command->do_commands();
    }
    if (rge_base_game->singlePlayerGame() == 1) {
        rge_base_game->set_paused(1, 1);
    }
    new TribeMenuDialog(this);
}
