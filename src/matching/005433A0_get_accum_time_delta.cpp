class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0xB0];
    int array_B4[1];
    int get_accum_time_delta(int idx);
};

int RGE_Game_World::get_accum_time_delta(int idx) { return this->array_B4[idx]; }
