// TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech ctor
// VA: 004D21B0
// PDB: tact_tek.cpp:29-34
// attempt 1: original scratch used broad local class surface; /GX emitted only 96 bytes and missed EH/vtable shape
// attempt 2: reduced to tact_rep-style natural ctor surface with virtual base dtor; testing against EH-framed target
// FLAGS: config/flags/004D21B0_TRIBE_Action_Make_Tech.rsp uses /GX for the original EH frame

#include "../../include/game_globals.h"
#include "../../include/tact_tek_context.h"

#ifndef AOE1_TACT_TEK_CONTEXT_H
class RGE_Action_Object;

void rge_read(int handle, void* buffer, int size);

class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;
    char gap_06[0x40 - 0x06];

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
};

class TRIBE_Action_Make_Tech : public RGE_Action {
public:
    short tech_id;
    char pad_42[2];
    int unique_id;

    TRIBE_Action_Make_Tech(int param_1, RGE_Action_Object* param_2);
};
#endif

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1)
{
    this->action_type = 0x67;
    rge_read(param_1, &this->tech_id, 2);
    rge_read(param_1, &this->unique_id, 4);
}
