#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int action_command(unsigned long, unsigned long);
};
#endif

int RGE_Base_Game::action_command(unsigned long a, unsigned long b) {
    return 1;
}
