class TRIBE_Screen_Game;

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    void* base_game_world;

    void set_player(short player_id);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_3F8[0x2C];
    TRIBE_Screen_Game* game_screen;

    void set_player(short player_id);
};

class TRIBE_Screen_Game {
public:
    void player_changed(short old_player, short new_player);
};

void TRIBE_Game::set_player(short player_id) {
    short old_player;

    if (*(void**)((char*)this + 0x3F4) != 0) {
        old_player = *(short*)(*(char**)((char*)this + 0x3F4) + 0x7C);
    } else {
        old_player = 0;
    }
    RGE_Base_Game::set_player(player_id);
    if (*(void**)((char*)this + 0x3F4) != 0 && this->game_screen != 0) {
        this->game_screen->player_changed(old_player, *(short*)(*(char**)((char*)this + 0x3F4) + 0x7C));
    }
}
