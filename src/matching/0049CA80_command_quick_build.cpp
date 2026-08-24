#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    int allowCheatCodes(void);
    char gap_00[0x9A8];
    int quick_build;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Command {
public:
    char gap_00[0x58];
    void command_quick_build(int value);
};

class WorldStub {
public:
    char gap_00[0x58];
    TRIBE_Command* command;
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x5B4];
    WorldStub* world;

    void command_quick_build(void);
};
#endif

void TRIBE_Screen_Game::command_quick_build(void) {
    if (rge_base_game->allowCheatCodes() != 0) {
        this->world->command->command_quick_build(rge_base_game->quick_build == 0);
    }
}
