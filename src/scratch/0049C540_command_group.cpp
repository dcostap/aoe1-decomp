// VA: 0049C540 TRIBE_Screen_Game::command_group (36 B)
// PDB source: scr_game.cpp lines 5179-5183
// Calls rge_base_game->get_player(-1)->group_objects(-1)

extern "C" void* rge_base_game;  // 0x62C574

class RGE_Base_Game {
public:
    int get_paused();
    class RGE_Player* get_player(int index);
};

class RGE_Player {
public:
    int group_objects(int index);
};

class TRIBE_Screen_Game {
public:
    void command_group();
};

void TRIBE_Screen_Game::command_group() {
    int v = -1;
    if (((RGE_Base_Game*)rge_base_game)->get_paused() == 0) {
        ((RGE_Base_Game*)rge_base_game)->get_player(v)->group_objects(v);
    }
}
