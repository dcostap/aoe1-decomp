// VA: 00452FE0 make_new_obj (201B)
// m_s_obj.cpp

class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;

#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    char gap_00[0x84];
    virtual ~RGE_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z);
    RGE_Static_Object(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z, int do_setup);
};

class RGE_Master_Static_Object {
public:
    void* vtable;
    unsigned char master_type;  // +0x4
    char gap_05[0x9F];
    unsigned char recyclable;   // +0xA4

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
#endif

RGE_Static_Object* RGE_Master_Static_Object::make_new_obj(RGE_Player* player, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled = player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->copy_obj(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Static_Object(this, player, x, y, z, 1);
}
