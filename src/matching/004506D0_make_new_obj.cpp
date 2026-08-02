// VA: 004506D0 make_new_obj (201B)
// m_co_obj.cpp
// EH-framed factory with the natural recycle-or-allocate construction path.
// Attempt log:
// - Natural typed recycle_in_to_game path and direct RGE_Combat_Object new-expression matched.
// - Proven master/object base sizes and fields were restored without changing emitted bytes.

class RGE_Master_Combat_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;

class RGE_Static_Object {
public:
    char gap_00[0x84];
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player,
                                    float x, float y, float z);
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    char gap_04[0x190];
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    void* VUR_Ptrs[9];       // +0x194
    unsigned long map_value; // +0x1B8
    float attack_timer;      // +0x1BC
    unsigned char capture_flag; // +0x1C0
    unsigned char gap_end[3];
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(RGE_Master_Combat_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

class RGE_Master_Static_Object {
public:
    void* vtable;
    unsigned char master_type;  // +0x4
    char gap_05[0xA4 - 0x5];
    unsigned char recyclable;   // +0xA4
    char gap_A5[0xB8 - 0xA5];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x148 - 0xB8];

    RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char master_type);
};

RGE_Static_Object* RGE_Master_Combat_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled = player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, player, x, y, z);
            return recycled;
        }
    }

    return (RGE_Static_Object*)new RGE_Combat_Object(this, player, x, y, z, 1);
}
