// 0049CC20 command_save_scenario
// 132 bytes, __thiscall, TRIBE_Screen_Game method
// probe 2: /GX EH, check prog_mode, create TribeSaveGameScreen

class RGE_Command;
class RGE_Game_World;

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    unsigned int prog_mode;
};

extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int size);
void __cdecl RGE_Command_do_commands(RGE_Command* cmd);
void __cdecl TribeSaveGameScreen_ctor(void* self);

class TRIBE_Screen_Game {
public:
    char gap_00[0x8C];
    RGE_Game_World* world;

    void command_save_scenario();
};

void TRIBE_Screen_Game::command_save_scenario() {
    if (rge_base_game->prog_mode == 6) {
        RGE_Command* cmd = *(RGE_Command**)((int*)world + 0x16);
        RGE_Command_do_commands(cmd);
    }
    void* dialog = operator new(0x6A4);
    if (dialog != 0) {
        TribeSaveGameScreen_ctor(dialog);
    }
}
