#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    int get_paused(void);
    void* get_player(void);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Player {
public:
    unsigned char command_trade_attribute(long value);
};

class TRIBE_Screen_Game {
public:
    void command_trade_attribute(long value);
};
#endif

void TRIBE_Screen_Game::command_trade_attribute(long value) {
    if (rge_base_game->get_paused() == 0) {
        ((TRIBE_Player*)rge_base_game->get_player())->command_trade_attribute(value);
    }
}
