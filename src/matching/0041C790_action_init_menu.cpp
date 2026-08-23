#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_init_menu();
};
#endif

int RGE_Base_Game::action_init_menu() {
    return 1;
}
