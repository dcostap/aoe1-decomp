struct tagMSG;

class RGE_Base_Game {
protected:
    virtual int handle_message(tagMSG *);
};

int RGE_Base_Game::handle_message(tagMSG *a) {
    return 1;
}
