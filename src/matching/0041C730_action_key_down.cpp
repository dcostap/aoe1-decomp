#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_key_down(unsigned long, int, int, int, int);
};
#endif

int RGE_Base_Game::action_key_down(unsigned long a, int b, int c, int d, int e) {
    return 1;
}
