class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x14];
    int field_18;
    void set_game_speed(int v);
};

void RGE_Game_World::set_game_speed(int v) { this->field_18 = v; }
