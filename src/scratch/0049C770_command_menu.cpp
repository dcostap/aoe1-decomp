// 0049C770 command_menu
// 135 bytes, __thiscall, TRIBE_Screen_Game method
// probe 2: /GX EH, check prog_mode, create TribeMenuDialog

class RGE_Command;
class RGE_Game_World;

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    unsigned int prog_mode;
};

extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int size);
int RGE_Base_Game_singlePlayerGame(RGE_Base_Game* game);
void __cdecl RGE_Command_do_commands(RGE_Command* cmd);
void __cdecl TribeMenuDialog_ctor(void* self);

class TRIBE_Screen_Game {
public:
    char gap_00[0x8C];
    RGE_Game_World* world;

    void command_menu();
};

void TRIBE_Screen_Game::command_menu() {
    if (rge_base_game->prog_mode == 6) {
        RGE_Command* cmd = *(RGE_Command**)((int*)world + 0x16);
        RGE_Command_do_commands(cmd);
    }
    int single = RGE_Base_Game_singlePlayerGame(rge_base_game);
    void* dialog = operator new(0x2C8);
    if (dialog != 0) {
        TribeMenuDialog_ctor(dialog);
    }
}
