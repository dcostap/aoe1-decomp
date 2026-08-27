// Authentic source module for C:\\msdev\\work\\age1_x1\\tact_lst.cpp.
// Definitions follow the original PDB source and address order.
//
// The four normal owners are all retained in this module. The scalar
// deleting destructor for TRIBE_Action_List is compiler generated and has no
// handwritten source owner.

#include "../include/tact_lst.h"

// Factory targets are owned by their own tactical-action modules. Keep their
// declarations in those canonical owner headers. Do not copy a foreign base,
// vtable, or field surface into this module.
#include "../include/act_entr.h"
#include "../include/act_tran.h"
#include "../include/tact_bld.h"
#include "../include/tact_mob.h"
#include "../include/tact_tek.h"
#include "../include/tact_cnv.h"
#include "../include/tact_hea.h"
#include "../include/tact_art.h"
#include "../include/tact_wnd.h"
#include "../include/tact_dar.h"
#include "../include/tact_hnt.h"
#include "../include/tact_rep.h"
#include "../include/tact_trd.h"

#include <string.h>

// PDB lines 37-38; VA 004D0150.
TRIBE_Action_List::TRIBE_Action_List(RGE_Action_Object* object)
    : RGE_Action_List(object)
{
}

// PDB lines 43-88; VA 004D0170.
// BINARY NOTE: The shipped ABI takes (int, short). Each case keeps its
// original allocation size through the canonical action owner constructor.
RGE_Action* TRIBE_Action_List::create_action(int param, short type)
{
    switch (type) {
    case 0x65:
        return new TRIBE_Action_Build(param, this->obj);
    case 0x66:
        return new TRIBE_Action_Make_Obj(param, this->obj);
    case 0x67:
        return new TRIBE_Action_Make_Tech(param, this->obj);
    case 0x68:
        return new TRIBE_Action_Convert(param, this->obj);
    case 0x69:
        return new TRIBE_Action_Heal(param, this->obj);
    case 0x6B:
        return new TRIBE_Action_Artifact(param, this->obj);
    case 0x78:
        return new TRIBE_Action_Wonder(param, this->obj);
    case 0x6C:
        return new TRIBE_Action_Discovery_Artifact(param, this->obj);
    case 0x6E:
        return new TRIBE_Action_Hunt(param, this->obj);
    case 0x6A:
        return new TRIBE_Action_Repair(param, this->obj, 1);
    case 0x6F:
        return new TRIBE_Action_Trade(param, this->obj);
    case 0x0C:
        return new RGE_Action_Transport(param, this->obj);
    case 3:
        return new RGE_Action_Enter(param, this->obj);
    default:
        return RGE_Action_List::create_action(param, type);
    }
}

// PDB lines 93-156; VA 004D05D0.
// BINARY NOTE: Selection reads RGE_Task::action_type at +0x06 and retains
// separate target and coordinate constructor paths.
RGE_Action* TRIBE_Action_List::create_task_action(
    RGE_Task* task,
    RGE_Static_Object* target,
    float x,
    float y,
    float z)
{
    switch (task->action_type) {
    case 0x65:
        if (target != 0)
            return new TRIBE_Action_Build(this->obj, task, target);
        return new TRIBE_Action_Build(this->obj, task, x, y, z);
    case 0x68:
        if (target != 0)
            return new TRIBE_Action_Convert(this->obj, task, target);
        return new TRIBE_Action_Convert(this->obj, task, x, y, z);
    case 0x69:
        if (target != 0)
            return new TRIBE_Action_Heal(this->obj, task, target);
        return new TRIBE_Action_Heal(this->obj, task, x, y, z);
    case 0x6B:
        if (target != 0)
            return new TRIBE_Action_Artifact(this->obj, task, target);
        return new TRIBE_Action_Artifact(this->obj, task, x, y, z);
    case 0x78:
        return new TRIBE_Action_Wonder(this->obj);
    case 0x6C:
        if (target != 0)
            return new TRIBE_Action_Discovery_Artifact(this->obj, task, target);
        return new TRIBE_Action_Discovery_Artifact(this->obj, task, x, y, z);
    case 0x6E:
        if (target != 0)
            return new TRIBE_Action_Hunt(this->obj, task, target);
        return new TRIBE_Action_Hunt(this->obj, task, x, y, z);
    case 0x6A:
        if (target != 0)
            return new TRIBE_Action_Repair(this->obj, task, target);
        return new TRIBE_Action_Repair(this->obj, task, x, y, z);
    case 0x6F:
        if (target != 0)
            return new TRIBE_Action_Trade(this->obj, task, target);
        return new TRIBE_Action_Trade(this->obj, task, x, y, z);
    case 3:
        return new RGE_Action_Enter(this->obj, task, target);
    case 0x0C:
        return new RGE_Action_Transport(this->obj, task, x, y, z);
    default:
        return RGE_Action_List::create_task_action(task, target, x, y, z);
    }
}

// PDB lines 160-183; VA 004D0C50.
// BINARY NOTE: The action type is read through the canonical node and action
// owners before the inherited fallback handles unknown types.
void TRIBE_Action_List::get_action_name(char* dest)
{
    const char* name;
    if (this->list == 0) {
        name = "None";
        strcpy(dest, name);
        return;
    }

    switch (this->list->action->action_type) {
    case 3:
        name = "Enter";
        strcpy(dest, name);
        return;
    case 0x0C:
        name = "Transport";
        strcpy(dest, name);
        return;
    case 0x65:
        name = "Build";
        strcpy(dest, name);
        return;
    case 0x66:
        name = "MakeObject";
        strcpy(dest, name);
        return;
    case 0x67:
        name = "MakeTech";
        strcpy(dest, name);
        return;
    case 0x68:
        name = "Convert";
        strcpy(dest, name);
        return;
    case 0x69:
        name = "Heal";
        strcpy(dest, name);
        return;
    case 0x6A:
        name = "Repair";
        strcpy(dest, name);
        return;
    case 0x6B:
        name = "Artifact";
        strcpy(dest, name);
        return;
    case 0x6C:
        name = "DiscoveryArtifact";
        strcpy(dest, name);
        return;
    case 0x6E:
        name = "Hunt";
        strcpy(dest, name);
        return;
    case 0x6F:
        name = "Trade";
        strcpy(dest, name);
        return;
    default:
        RGE_Action_List::get_action_name(dest);
        return;
    }
}
