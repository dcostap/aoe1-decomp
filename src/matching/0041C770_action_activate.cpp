#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_activate();
};
#endif

int RGE_Base_Game::action_activate() {
    return 1;
}
