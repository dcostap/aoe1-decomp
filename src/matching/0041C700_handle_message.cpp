struct tagMSG;

#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
protected:
    virtual int handle_message(tagMSG *);
};
#endif

int RGE_Base_Game::handle_message(tagMSG *a) {
    return 1;
}
