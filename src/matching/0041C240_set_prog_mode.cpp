class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_0[0x1AC];
    int field_1B0;
    void set_prog_mode(int v);
};

void RGE_Base_Game::set_prog_mode(int v) { this->field_1B0 = v; }
