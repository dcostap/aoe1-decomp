#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_size();
};
#endif

int RGE_Base_Game::action_size() {
    return 1;
}
