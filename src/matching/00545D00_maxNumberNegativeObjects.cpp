class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x98];
    int field_9C;
    int maxNumberNegativeObjects();
};

int RGE_Game_World::maxNumberNegativeObjects() { return this->field_9C; }
