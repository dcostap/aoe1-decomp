class RGE_Base_Game {
public:
    int get_paused();
    void* get_player();
};

class TRIBE_Player {
public:
    void command_building_cancel();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    void command_cancel_building();
};

void TRIBE_Screen_Game::command_cancel_building() {
    if (rge_base_game->get_paused() == 0) {
        ((TRIBE_Player*)rge_base_game->get_player())->command_building_cancel();
    }
}
