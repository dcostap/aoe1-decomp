// 004D2660 TRIBE_Action_Trade::TRIBE_Action_Trade
// Source: tact_trd.cpp lines 42-47
// Size: 118 bytes, EH-framed
// Calls RGE_Action::RGE_Action(int, RGE_Action_Object*, 1)
//
// Attempt log:
// Probe 1: /GX + explicit void* vftable → double vptr, action_type at +0x08 (wrong)
// Probe 2: remove explicit vftable, fix RGE_Action size to 0x20

#include "..\..\include\game_globals.h"

class RGE_Action_Object;
class RGE_Task;

// sizeof(RGE_Action) = 0x20
class RGE_Action {
public:
    // vptr at +0x00 (implicit)
    unsigned short action_type;         // +0x04
    char _gap_06[0x1A];                 // +0x06 to +0x1F

    virtual ~RGE_Action();
    RGE_Action(int param1, RGE_Action_Object* obj, int flag);
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
    TRIBE_Action_Trade(int file, RGE_Action_Object* obj);
};

extern void __cdecl rge_read(int file, void* buf, int size);

TRIBE_Action_Trade::TRIBE_Action_Trade(int file, RGE_Action_Object* obj)
    : RGE_Action(file, obj, 1)
{
    rge_read(file, &this->pick_up_x, 4);
    rge_read(file, &this->pick_up_y, 4);
    this->action_type = 0x6F;
}
