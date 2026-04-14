class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x19];
    unsigned char field_1D;
    unsigned char get_game_state();
};

unsigned char RGE_Game_World::get_game_state() { return this->field_1D; }
