// 004D2710 TRIBE_Action_Trade::TRIBE_Action_Trade
// Source: tact_trd.cpp lines 55-70
// Size: 131 bytes, EH-framed
// Calls RGE_Action::RGE_Action(RGE_Action_Object*, int) (different overload, 004074C0)
// Sets task in init list (before vtable write), copies target coords, set_target_obj
//
// Attempt log:
// Probe 1: /GX for EH prolog, task in init list for pre-vtable store

#include "..\..\include\game_globals.h"

class RGE_Action_Object;
class RGE_Task;

// Minimal RGE_Static_Object stub — world coords at +0x38,+0x3C,+0x40
class RGE_Static_Object {
public:
    char _gap_00[0x38];
    float world_x;          // +0x38
    float world_y;          // +0x3C
    float world_z;          // +0x40
};

// sizeof(RGE_Action) = 0x20
class RGE_Action {
public:
    // vptr at +0x00 (implicit)
    unsigned short action_type;         // +0x04
    char _gap_06[0x1A];                 // +0x06 to +0x1F

    virtual ~RGE_Action();
    RGE_Action(int param1, RGE_Action_Object* obj, int flag);
    RGE_Action(RGE_Action_Object* obj, int flag);
    void set_target_obj(RGE_Static_Object* obj);
};

// sizeof(TRIBE_Action_Trade) = 0x48
class TRIBE_Action_Trade : public RGE_Action {
public:
    float world_x;                      // +0x20
    float world_y;                      // +0x24
    float world_z;                      // +0x28
    char _gap_2C[0x04];                 // +0x2C to +0x2F
    RGE_Task* task;                     // +0x30
    char _gap_34[0x0C];                 // +0x34 to +0x3F
    float pick_up_x;                    // +0x40
    float pick_up_y;                    // +0x44

    virtual ~TRIBE_Action_Trade();
    TRIBE_Action_Trade(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
};

TRIBE_Action_Trade::TRIBE_Action_Trade(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(obj, 1), task(task)
{
    this->action_type = 0x6F;
    this->set_target_obj(target);
    this->world_x = target->world_x;
    this->world_y = target->world_y;
    this->world_z = target->world_z;
    this->pick_up_x = -1.0f;
    this->pick_up_y = -1.0f;
}
