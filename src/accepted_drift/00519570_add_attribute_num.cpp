// TRIBE_Player::add_attribute_num
// VA: 00519570
// tplayer.cpp:4873-4884
// 86 bytes, 9 diff bytes (10.47%).
// FPU scheduling quirk: original does fld param_2; fadd attr[49]
// rebuilt does fld attr[49]; fadd param_2. Both compute same result.
// Invariant across 4+ source forms (direct +=, param+attr, temp vars,
// pointer indirection). 2 relocations masked (base call + update call).

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
        float addend = param_2;
        float dest = this->attributes[49];
        this->attributes[49] = addend + dest;
    }
    if (param_1 == 0x32) {
        this->allied_LOS_Enable = 1;
        this->world->update_mutual_allies();
    }
    RGE_Player::add_attribute_num(param_1, param_2, param_3);
}
