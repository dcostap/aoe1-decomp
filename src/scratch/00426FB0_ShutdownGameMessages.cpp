struct Fwd_6FB0 {
    void target();
};

class RGE_Base_Game : public Fwd_6FB0 {
public:
    char gap_0[0x12A8];
    int field_12A8;
    void ShutdownGameMessages();
};

void RGE_Base_Game::ShutdownGameMessages() {
    this->field_12A8 = 1;
    this->target();
}
