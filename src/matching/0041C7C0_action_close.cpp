#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_close();
};
#endif

int RGE_Base_Game::action_close() {
    return 1;
}
