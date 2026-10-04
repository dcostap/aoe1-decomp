
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
    case TRIBE_ACTION_TYPE_BUILD:
        return new TRIBE_Action_Build(infile, this->obj);
    case TRIBE_ACTION_TYPE_MAKE_OBJECT:
        return new TRIBE_Action_Make_Obj(infile, this->obj);
    case TRIBE_ACTION_TYPE_MAKE_TECH:
        return new TRIBE_Action_Make_Tech(infile, this->obj);
    case TRIBE_ACTION_TYPE_CONVERT:
        return new TRIBE_Action_Convert(infile, this->obj);
    case TRIBE_ACTION_TYPE_HEAL:
        return new TRIBE_Action_Heal(infile, this->obj);
    case TRIBE_ACTION_TYPE_ARTIFACT:
        return new TRIBE_Action_Artifact(infile, this->obj);
    case TRIBE_ACTION_TYPE_WONDER:
        return new TRIBE_Action_Wonder(infile, this->obj);
    case TRIBE_ACTION_TYPE_DISCOVERY_ARTIFACT:
        return new TRIBE_Action_Discovery_Artifact(infile, this->obj);
    case TRIBE_ACTION_TYPE_HUNT:
        return new TRIBE_Action_Hunt(infile, this->obj);
    case TRIBE_ACTION_TYPE_REPAIR:
        return new TRIBE_Action_Repair(infile, this->obj, 1);
    case TRIBE_ACTION_TYPE_TRADE:
        return new TRIBE_Action_Trade(infile, this->obj);
    case RGE_ACTION_TYPE_TRANSPORT:
        return new RGE_Action_Transport(infile, this->obj);
    case RGE_ACTION_TYPE_ENTER:
        return new RGE_Action_Enter(infile, this->obj);
    default:
        return RGE_Action_List::create_action(infile, action_type);
    }
}

// Selection reads RGE_Task::action_type at +0x06 and retains
// separate target and coordinate constructor paths.
RGE_Action* TRIBE_Action_List::create_task_action(RGE_Task* task, RGE_Static_Object* target_obj,
    float target_x, float target_y, float target_z) {
    switch (task->action_type) {
    case TRIBE_ACTION_TYPE_BUILD:
        if (target_obj != 0)
            return new TRIBE_Action_Build(this->obj, task, target_obj);
        return new TRIBE_Action_Build(this->obj, task, target_x, target_y, target_z);
    case TRIBE_ACTION_TYPE_CONVERT:
        if (target_obj != 0)
            return new TRIBE_Action_Convert(this->obj, task, target_obj);
        return new TRIBE_Action_Convert(this->obj, task, target_x, target_y, target_z);
    case TRIBE_ACTION_TYPE_HEAL:
        if (target_obj != 0)
            return new TRIBE_Action_Heal(this->obj, task, target_obj);
        return new TRIBE_Action_Heal(this->obj, task, target_x, target_y, target_z);
    case TRIBE_ACTION_TYPE_ARTIFACT:
        if (target_obj != 0)
            return new TRIBE_Action_Artifact(this->obj, task, target_obj);
        return new TRIBE_Action_Artifact(this->obj, task, target_x, target_y, target_z);
    case TRIBE_ACTION_TYPE_WONDER:
        return new TRIBE_Action_Wonder(this->obj);
    case TRIBE_ACTION_TYPE_DISCOVERY_ARTIFACT:
        if (target_obj != 0)
            return new TRIBE_Action_Discovery_Artifact(this->obj, task, target_obj);
        return new TRIBE_Action_Discovery_Artifact(this->obj, task, target_x, target_y, target_z);
    case TRIBE_ACTION_TYPE_HUNT:
        if (target_obj != 0)
            return new TRIBE_Action_Hunt(this->obj, task, target_obj);
        return new TRIBE_Action_Hunt(this->obj, task, target_x, target_y, target_z);
    case TRIBE_ACTION_TYPE_REPAIR:
        if (target_obj != 0)
            return new TRIBE_Action_Repair(this->obj, task, target_obj);
        return new TRIBE_Action_Repair(this->obj, task, target_x, target_y, target_z);
    case TRIBE_ACTION_TYPE_TRADE:
        if (target_obj != 0)
            return new TRIBE_Action_Trade(this->obj, task, target_obj);
        return new TRIBE_Action_Trade(this->obj, task, target_x, target_y, target_z);
    case RGE_ACTION_TYPE_ENTER:
        return new RGE_Action_Enter(this->obj, task, target_obj);
    case RGE_ACTION_TYPE_TRANSPORT:
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
    case RGE_ACTION_TYPE_ENTER:
        name = "Enter";
        strcpy(action_name, name);
        return;
    case RGE_ACTION_TYPE_TRANSPORT:
        name = "Transport";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_BUILD:
        name = "Build";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_MAKE_OBJECT:
        name = "MakeObject";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_MAKE_TECH:
        name = "MakeTech";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_CONVERT:
        name = "Convert";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_HEAL:
        name = "Heal";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_REPAIR:
        name = "Repair";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_ARTIFACT:
        name = "Artifact";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_DISCOVERY_ARTIFACT:
        name = "DiscoveryArtifact";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_HUNT:
        name = "Hunt";
        strcpy(action_name, name);
        return;
    case TRIBE_ACTION_TYPE_TRADE:
        name = "Trade";
        strcpy(action_name, name);
        return;
    default:
        RGE_Action_List::get_action_name(action_name);
        return;
    }
}
