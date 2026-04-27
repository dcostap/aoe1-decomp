// 0049C800 command_more
// 131 bytes, __thiscall, TRIBE_Screen_Game method
// probe 1: check paused, adjust last_item, setup_buttons

class RGE_Base_Game {
public:
    char gap_00[0x1B4];
    unsigned int game_mode;
    unsigned int sub_game_mode;
};
int RGE_Base_Game_get_paused(RGE_Base_Game* game);

extern RGE_Base_Game* rge_base_game;
void __cdecl setup_buttons(void* screen);

class TRIBE_Screen_Game {
public:
    char gap_00[0x7B8];
    short last_item;
    short field_7BA;
    short field_5E4;
    short start_item;

    void command_more();
};

void TRIBE_Screen_Game::command_more() {
    int paused = RGE_Base_Game_get_paused(rge_base_game);
    if (paused == 0) {
        if (rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1) {
            last_item = (last_item != 0) ? 0 : 10;
            setup_buttons(this);
            return;
        }
        if (field_5E4 < start_item + 1 - 1) {
            last_item = field_5E4 + 1;
            setup_buttons(this);
            return;
        }
        last_item = 0;
        setup_buttons(this);
    }
}
