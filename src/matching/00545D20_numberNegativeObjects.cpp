class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_0[0x94];
    int field_98;
    int numberNegativeObjects();
};

int RGE_Game_World::numberNegativeObjects() { return this->field_98; }
