#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Player {
public:
    virtual unsigned char command_add_attribute(int, float);
};

class RGE_Base_Game {
public:
    int get_paused();
    int allowCheatCodes();
    RGE_Player* get_player();
};

class TRIBE_Screen_Game {
protected:
    void command_add_attribute(int);
};

extern RGE_Base_Game* rge_base_game;
#endif

void TRIBE_Screen_Game::command_add_attribute(int value) {
    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->allowCheatCodes() != 0) {
            RGE_Player* player = rge_base_game->get_player();
            player->command_add_attribute(value, 1000.0f);
        }
    }
}
