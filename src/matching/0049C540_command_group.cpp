class RGE_Player {
public:
    void group_objects(int group);
};

class RGE_Base_Game {
public:
    int get_paused(void);
    RGE_Player* get_player(void);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    void command_group(void);
};

void TRIBE_Screen_Game::command_group(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->get_player()->group_objects(-1);
    }
}
