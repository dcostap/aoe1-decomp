#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void build_mode(int mode, int value);
    int get_paused(void);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x5E2];
    short last_item;

    void setup_buttons(void);
    void command_build(void);
};
#endif

void TRIBE_Screen_Game::command_build(void) {
    if (rge_base_game->get_paused() == 0) {
        rge_base_game->build_mode(6, 1);
        this->last_item = 0;
        this->setup_buttons();
    }
}
