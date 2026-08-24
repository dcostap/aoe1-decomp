// STATUS: READY_FOR_MATCHING_MOVE
// NOTE: moved from matching after the 2026-08-16 inline-assembly policy audit.
// Attempt log:
// - Replaced the prior naked implementation with the natural typed state
//   predicates: world game state, object state, and master object group.
// - The baseline natural reconstruction is an exact 54-byte match. It has the
//   original direct reposition call, qualified base call, frame, and CFG.
// NEXT: move to src/matching and validate after the move.

// set_object_state (004CA740) - TRIBE_Combat_Object::set_object_state
// t_c_obj.cpp:289-303

#ifndef T_C_OBJ_CONTEXT_H
typedef unsigned char uchar;

class RGE_Game_World {
public:
    char gap_00[0x1D];
    uchar game_state;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
};

class RGE_Static_Object {
public:
    virtual void set_object_state(uchar);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x38];
    uchar object_state;
};

class RGE_Combat_Object : public RGE_Static_Object {
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    virtual void set_object_state(uchar);
    void reposition_artifact();
};
#endif

void TRIBE_Combat_Object::set_object_state(uchar state)
{
    if (this->owner->world->game_state == 0 && state >= 3 &&
        this->object_state <= 2 &&
        this->master_obj->object_group == 1) {
        this->reposition_artifact();
    } else {
        RGE_Static_Object::set_object_state(state);
    }
}
