// tried the direct wrapper with member-call base set_player and screen notification; first mismatch moved to the base-call basin
// tried fixing the screen offset to 0xC24; that part matched, but the base call still fell into a wrong local-call basin
// tried free-function __thiscall declarations for the two helper calls; VC5 rejected that spelling with C4234, so I rolled it back
class RGE_Base_Game {
public:
    void set_player(short player_id);
};

class TRIBE_Screen_Game {
public:
    void player_changed(short old_player, short new_player);
};

class TRIBE_Game {
public:
    char gap_00[0x3F4];
    void* base_game_world;
    char gap_3F8[0x82C];
    TRIBE_Screen_Game* game_screen;

    void set_player(short player_id);
};

void TRIBE_Game::set_player(short player_id) {
    short old_player;
    void* world;

    world = *(void**)((char*)this + 0x3F4);
    if (world != 0) {
        old_player = *(short*)((char*)world + 0x7C);
    } else {
        old_player = 0;
    }
    ((RGE_Base_Game*)this)->RGE_Base_Game::set_player(player_id);
    world = *(void**)((char*)this + 0x3F4);
    if (world != 0 && this->game_screen != 0) {
        this->game_screen->player_changed(old_player, *(short*)((char*)world + 0x7C));
    }
}
