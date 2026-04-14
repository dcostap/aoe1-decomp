class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x8C];
    int field_90;
    int maxNumberObjects();
};

int RGE_Game_World::maxNumberObjects() { return this->field_90; }
