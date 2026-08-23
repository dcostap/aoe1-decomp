#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_deactivate();
};
#endif

int RGE_Base_Game::action_deactivate() {
    return 1;
}
