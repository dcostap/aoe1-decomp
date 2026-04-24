class RGE_Game_World;

extern int* unified_map_offsets[];

class RGE_Animated_Object {
public:
    virtual int setup(int, RGE_Game_World*);
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    char gap_00[0x34];
    float field_38;
    float field_3c;
    char gap_40[0x0E];
    unsigned char field_4e;
    char gap_4f[0x4D];
    int* MapAddress;
    int LastMapValue;
    int CantSeeBits;

    virtual int setup(int, RGE_Game_World*);
};

int RGE_Doppleganger_Object::setup(int param_1, RGE_Game_World* param_2) {
    RGE_Animated_Object::setup(param_1, param_2);
    int x = (int)(long)(field_3c);
    field_4e = 0x19;
    int y = (int)(long)(field_38);
    MapAddress = (int*)unified_map_offsets[x] + y;
    LastMapValue = 0;
    CantSeeBits = 0;
    return 1;
}
