#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Game {
public:
    char gap_0[0x18C];
    int field_18C;
    char gap_190[0x1B0 - 0x190];
    int field_1B0;

    void disconnect_multiplayer_game();
    virtual int action_close();
};
#endif

int TRIBE_Game::action_close() {
    if (this->comm_handler) {
        this->disconnect_multiplayer_game();
        this->prog_mode = 0;
    }
    return 1;
}
