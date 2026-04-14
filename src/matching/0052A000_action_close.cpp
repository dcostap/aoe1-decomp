class TRIBE_Game {
public:
    char gap_0[0x18C];
    int field_18C;
    char gap_190[0x1B0 - 0x190];
    int field_1B0;

    void disconnect_multiplayer_game();
    int action_close();
};

int TRIBE_Game::action_close() {
    if (this->field_18C) {
        this->disconnect_multiplayer_game();
        this->field_1B0 = 0;
    }
    return 1;
}
