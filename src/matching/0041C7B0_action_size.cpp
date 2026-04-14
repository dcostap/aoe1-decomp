class RGE_Base_Game {
protected:
    virtual int action_size();
};

int RGE_Base_Game::action_size() {
    return 1;
}
