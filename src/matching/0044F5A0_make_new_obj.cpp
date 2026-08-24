// VA: 0044F5A0 RGE_Master_Action_Object::make_new_obj (201B)
// PDB source: m_ac_obj.cpp, lines 188-202
// Clean reconstruction: recycle through the player's world when enabled;
// otherwise construct the normal RGE_Action_Object allocation.
// FLAGS: config/flags/0044F5A0_make_new_obj.rsp adds /GX for the observed EH frame.
// Attempt log:
// - natural source under default flags emitted the right four calls and CFG but omitted the 75-byte EH setup.
// - adding /GX, as used by same-TU EH-framed factory donors, produced an exact 201-byte match.

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Player;
class RGE_Game_World;
#endif

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player,
                                    float x, float y, float z);
    char gap_04[0x84];
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_88[0xF8];
    RGE_Moving_Object(RGE_Master_Static_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    char gap_180[0x14];
    RGE_Action_Object(RGE_Master_Action_Object* master, RGE_Player* player,
                      float x, float y, float z, int do_setup);
};

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;  // +0x04
    char gap_05[0x9F];
    unsigned char recyclable;   // +0xA4
    char gap_A5[0x13];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x04];
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];
    RGE_Static_Object* make_new_obj(RGE_Player* player, float x, float y, float z);
};
#endif

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    RGE_Static_Object* recycle_object_in_to_game(unsigned char master_type);
};

RGE_Static_Object* RGE_Master_Action_Object::make_new_obj(RGE_Player* player,
                                                            float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled = player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Action_Object(this, player, x, y, z, 1);
}
