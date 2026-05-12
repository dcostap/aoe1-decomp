// VA: 0049C800 TRIBE_Screen_Game::command_more
// PDB: scr_game.cpp lines 5286-5307 (131 bytes, 38 asm lines)
// Default flags. No inline asm/hacks.

class RGE_Base_Game {
public:
    char gap_00[0x1B4];
    unsigned int game_mode;
    unsigned int sub_game_mode;

    int get_paused();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x5E0];
    short start_item;            // +0x5E0
    short last_item;             // +0x5E2
    short field_5E4;             // +0x5E4
    char gap_5E6[0x7B8 - 0x5E6];

    void setup_buttons();
    void command_more();
};

void TRIBE_Screen_Game::command_more() {
    if (rge_base_game->get_paused())
        return;

    if (rge_base_game->game_mode == 6 && rge_base_game->sub_game_mode == 1) {
        this->last_item = (this->last_item != 0) ? 0 : 10;
        this->setup_buttons();
        return;
    }

    if (this->field_5E4 < this->start_item - 1) {
        this->last_item = this->field_5E4 + 1;
        this->setup_buttons();
        return;
    }

    this->last_item = 0;
    this->setup_buttons();
}
