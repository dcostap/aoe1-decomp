
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

TRIBE_Action_List::TRIBE_Action_List(RGE_Action_Object* obj_in)
    : RGE_Action_List(obj_in) {
}

// The shipped ABI takes (int, short). Each case keeps its
// original allocation size through the canonical action owner constructor.
RGE_Action* TRIBE_Action_List::create_action(int infile, short action_type) {
    switch (action_type) {
    case 0x65:
        return new TRIBE_Action_Build(infile, this->obj);
    case 0x66:
        return new TRIBE_Action_Make_Obj(infile, this->obj);
    case 0x67:
        return new TRIBE_Action_Make_Tech(infile, this->obj);
    case 0x68:
        return new TRIBE_Action_Convert(infile, this->obj);
    case 0x69:
        return new TRIBE_Action_Heal(infile, this->obj);
    case 0x6B:
        return new TRIBE_Action_Artifact(infile, this->obj);
    case 0x78:
        return new TRIBE_Action_Wonder(infile, this->obj);
    case 0x6C:
        return new TRIBE_Action_Discovery_Artifact(infile, this->obj);
    case 0x6E:
        return new TRIBE_Action_Hunt(infile, this->obj);
    case 0x6A:
        return new TRIBE_Action_Repair(infile, this->obj, 1);
    case 0x6F:
        return new TRIBE_Action_Trade(infile, this->obj);
    case 0x0C:
        return new RGE_Action_Transport(infile, this->obj);
    case 3:
        return new RGE_Action_Enter(infile, this->obj);
    default:
        return RGE_Action_List::create_action(infile, action_type);
    }
}

// Selection reads RGE_Task::action_type at +0x06 and retains
// separate target and coordinate constructor paths.
RGE_Action* TRIBE_Action_List::create_task_action(
    RGE_Task* task,
    RGE_Static_Object* target_obj,
    float target_x,
    float target_y,
    float target_z) {
    switch (task->action_type) {
    case 0x65:
        if (target_obj != 0)
            return new TRIBE_Action_Build(this->obj, task, target_obj);
        return new TRIBE_Action_Build(this->obj, task, target_x, target_y, target_z);
    case 0x68:
        if (target_obj != 0)
            return new TRIBE_Action_Convert(this->obj, task, target_obj);
        return new TRIBE_Action_Convert(this->obj, task, target_x, target_y, target_z);
    case 0x69:
        if (target_obj != 0)
            return new TRIBE_Action_Heal(this->obj, task, target_obj);
        return new TRIBE_Action_Heal(this->obj, task, target_x, target_y, target_z);
    case 0x6B:
        if (target_obj != 0)
            return new TRIBE_Action_Artifact(this->obj, task, target_obj);
        return new TRIBE_Action_Artifact(this->obj, task, target_x, target_y, target_z);
    case 0x78:
        return new TRIBE_Action_Wonder(this->obj);
    case 0x6C:
        if (target_obj != 0)
            return new TRIBE_Action_Discovery_Artifact(this->obj, task, target_obj);
        return new TRIBE_Action_Discovery_Artifact(this->obj, task, target_x, target_y, target_z);
    case 0x6E:
        if (target_obj != 0)
            return new TRIBE_Action_Hunt(this->obj, task, target_obj);
        return new TRIBE_Action_Hunt(this->obj, task, target_x, target_y, target_z);
    case 0x6A:
        if (target_obj != 0)
            return new TRIBE_Action_Repair(this->obj, task, target_obj);
        return new TRIBE_Action_Repair(this->obj, task, target_x, target_y, target_z);
    case 0x6F:
        if (target_obj != 0)
            return new TRIBE_Action_Trade(this->obj, task, target_obj);
        return new TRIBE_Action_Trade(this->obj, task, target_x, target_y, target_z);
    case 3:
        return new RGE_Action_Enter(this->obj, task, target_obj);
    case 0x0C:
        return new RGE_Action_Transport(this->obj, task, target_x, target_y, target_z);
    default:
        return RGE_Action_List::create_task_action(task, target_obj, target_x, target_y, target_z);
    }
}

// The action type is read through the canonical node and action
// owners before the inherited fallback handles unknown types.
void TRIBE_Action_List::get_action_name(char* action_name) {
    const char* name;
    if (this->list == 0) {
        name = "None";
        strcpy(action_name, name);
        return;
    }

    switch (this->list->action->action_type) {
    case 3:
        name = "Enter";
        strcpy(action_name, name);
        return;
    case 0x0C:
        name = "Transport";
        strcpy(action_name, name);
        return;
    case 0x65:
        name = "Build";
        strcpy(action_name, name);
        return;
    case 0x66:
        name = "MakeObject";
        strcpy(action_name, name);
        return;
    case 0x67:
        name = "MakeTech";
        strcpy(action_name, name);
        return;
    case 0x68:
        name = "Convert";
        strcpy(action_name, name);
        return;
    case 0x69:
        name = "Heal";
        strcpy(action_name, name);
        return;
    case 0x6A:
        name = "Repair";
        strcpy(action_name, name);
        return;
    case 0x6B:
        name = "Artifact";
        strcpy(action_name, name);
        return;
    case 0x6C:
        name = "DiscoveryArtifact";
        strcpy(action_name, name);
        return;
    case 0x6E:
        name = "Hunt";
        strcpy(action_name, name);
        return;
    case 0x6F:
        name = "Trade";
        strcpy(action_name, name);
        return;
    default:
        RGE_Action_List::get_action_name(action_name);
        return;
    }
}
