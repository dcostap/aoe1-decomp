class RGE_Game_World;

extern "C" void rge_read(int handle, void* buffer, int size);
extern "C" float save_game_version;

class RGE_Action_Object {
public:
    virtual int setup(int handle, RGE_Game_World* world);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    int id;
    void* master_obj;
    unsigned char owner[0x42];
    unsigned char type;
    unsigned char gap_4F[0x145];
    void* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    unsigned char capture_flag;

    virtual int setup(int handle, RGE_Game_World* world);
};

int RGE_Combat_Object::setup(int handle, RGE_Game_World* world) {
    int i;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::setup(handle, world);
    type = 0x32;
    rge_read(handle, &attack_timer, 4);
    if (!(save_game_version < 2.01f)) {
        rge_read(handle, &capture_flag, 1);
    }
    return 1;
}
