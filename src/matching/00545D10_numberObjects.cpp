class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x88];
    int field_8C;
    int numberObjects();
};

int RGE_Game_World::numberObjects() { return this->field_8C; }
