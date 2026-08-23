#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_update();
};
#endif

int RGE_Base_Game::action_update() {
    return 1;
}
