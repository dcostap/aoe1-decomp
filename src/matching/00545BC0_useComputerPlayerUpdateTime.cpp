class RGE_Game_World {
public:
    char gap_0[0xF8];
    unsigned int field_F8;
    void useComputerPlayerUpdateTime(unsigned int);
};

void RGE_Game_World::useComputerPlayerUpdateTime(unsigned int amount) {
    if (this->field_F8 < amount) {
        this->field_F8 = 0;
    } else {
        this->field_F8 -= amount;
    }
}
