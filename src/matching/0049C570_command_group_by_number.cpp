#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    int get_paused(void);
    void* get_player(void);
};

class RGE_Player {
public:
    int group_objects(int group);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    void command_group_by_number(int group);
};
#endif

void TRIBE_Screen_Game::command_group_by_number(int group) {
    if (rge_base_game->get_paused() == 0) {
        if (group == 0) {
            group = 10;
        }
        ((RGE_Player*)rge_base_game->get_player())->group_objects(group);
    }
}
