class RGE_Game_World {
public:
    virtual void base_save(int value);
};

class TRIBE_Tech {
public:
    void save(int value);
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_04[0x100];
    TRIBE_Tech* tech;

    void base_save(int value);
};

void TRIBE_World::base_save(int value) {
    RGE_Game_World::base_save(value);
    this->tech->save(value);
}
