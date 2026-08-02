// 0044FC00 RGE_Master_Animated_Object::make_new_obj
// Source: m_an_obj.cpp lines 100-114
// Size: 201 bytes, EH-framed, /GX
//
// Attempt log:
// baseline: natural recycle/copy path and direct animated-object construction;
// fields and calls are modeled through the period class surfaces.
// layout: gave RGE_Animated_Object its proven 0x8C size; exact 201-byte match.

class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Player;
class RGE_Game_World;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* master, RGE_Player* player,
                          float x, float y, float z);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_04[0x88]; // sizeof(RGE_Animated_Object) = 0x8C
    RGE_Animated_Object(RGE_Master_Animated_Object* master, RGE_Player* player,
                        float x, float y, float z, int do_setup);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type; // +0x04
    char gap_05[0x9F];
    unsigned char recyclable; // +0xA4
    char gap_A5[0x13];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x04];
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
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

RGE_Static_Object* RGE_Master_Animated_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled = player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->copy_obj(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Animated_Object(this, player, x, y, z, 1);
}
