#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_exit_menu();
};
#endif

int RGE_Base_Game::action_exit_menu() {
    return 1;
}
