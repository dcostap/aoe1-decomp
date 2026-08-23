// VA: 00451DF0 RGE_Master_Moving_Object::make_new_obj
// PDB source: m_mo_obj.cpp
//
// Attempt log:
// - Baseline used raw fastcall wrappers and the default flags; it had the right broad
//   branches but no original EH frame and the direct call relocations were not the
//   owning C++ symbols.
// - Probe 2: use the natural recycled-object virtual copy path and a C++ new-expression
//   for the 0x180-byte moving object.  The original is an EH-framed factory, so keep the
//   narrow /GX response file for this target.

class RGE_Master_Moving_Object;
class RGE_Player;

#ifndef RGE_MO_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    char gap_04[0x84];
    virtual ~RGE_Static_Object();
    virtual void copy_obj(RGE_Master_Moving_Object* master, RGE_Player* player,
                          float x, float y, float z);
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_88[0xF8];
    RGE_Moving_Object(RGE_Master_Moving_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char master_type);
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Master_Moving_Object {
public:
    void* vtable;
    unsigned char master_type;
    char gap_05[0x9F];
    unsigned char recyclable;

    RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
};
#endif

RGE_Static_Object* RGE_Master_Moving_Object::make_new_obj(RGE_Player* player,
                                                           float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled = player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->copy_obj(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Moving_Object(this, player, x, y, z, 1);
}
