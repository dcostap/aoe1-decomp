// quick-win attempt log:
// no existing work file for 00519570; source is a small override with two side effects
// first probe will keep the class surface minimal but preserve the exact field offsets
// needed for the attribute accumulator and the mutual-allies refresh

class RGE_Game_World {
public:
    void update_mutual_allies(void);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x10];
    float* attributes;
    char gap_54[0xAC];
    int allied_LOS_Enable;

    void add_attribute_num(short, float, unsigned char);
};

class TRIBE_Player : public RGE_Player {
public:
    void add_attribute_num(short, float, unsigned char);
};

void TRIBE_Player::add_attribute_num(short param_1, float param_2, unsigned char param_3) {
    if ((param_1 == 3) && (param_3 != 0)) {
        float new_value = param_2;
        new_value += this->attributes[49];
        this->attributes[49] = new_value;
    }
    if (param_1 == 0x32) {
        this->allied_LOS_Enable = 1;
        this->world->update_mutual_allies();
    }
    RGE_Player::add_attribute_num(param_1, param_2, param_3);
}
