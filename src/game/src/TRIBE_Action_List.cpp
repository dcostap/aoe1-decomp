#include "../include/TRIBE_Action_List.h"

#include "../include/RGE_Action_Enter.h"
#include "../include/RGE_Action_Transport.h"
#include "../include/RGE_Action_Node.h"
#include "../include/RGE_Task.h"
#include "../include/TRIBE_Action_Artifact.h"
#include "../include/TRIBE_Action_Build.h"
#include "../include/TRIBE_Action_Convert.h"
#include "../include/TRIBE_Action_Discovery_Artifact.h"
#include "../include/TRIBE_Action_Heal.h"
#include "../include/TRIBE_Action_Hunt.h"
#include "../include/TRIBE_Action_Make_Obj.h"
#include "../include/TRIBE_Action_Make_Tech.h"
#include "../include/TRIBE_Action_Repair.h"
#include "../include/TRIBE_Action_Trade.h"
#include "../include/TRIBE_Action_Wonder.h"

#include <new>
#include <string.h>

// Fully verified. Source of truth: tact_lst.cpp.decomp @ 0x004D0150
TRIBE_Action_List::TRIBE_Action_List(RGE_Action_Object* param_1)
    : RGE_Action_List(param_1) {
}

// Fully verified. Source of truth: tact_lst.cpp.decomp @ 0x004D0170
RGE_Action* TRIBE_Action_List::create_action(int param_1, short param_2) {
    switch (param_2) {
    case 3:
        return new (std::nothrow) RGE_Action_Enter(param_1, this->obj);
    case 0x0c:
        return new (std::nothrow) RGE_Action_Transport(param_1, this->obj);
    case 0x65:
        return new (std::nothrow) TRIBE_Action_Build(param_1, this->obj);
    case 0x66:
        return new (std::nothrow) TRIBE_Action_Make_Obj(param_1, this->obj);
    case 0x67:
        return new (std::nothrow) TRIBE_Action_Make_Tech(param_1, this->obj);
    case 0x68:
        return new (std::nothrow) TRIBE_Action_Convert(param_1, this->obj);
    case 0x69:
        return new (std::nothrow) TRIBE_Action_Heal(param_1, this->obj);
    case 0x6a:
        return new (std::nothrow) TRIBE_Action_Repair(param_1, this->obj, 1);
    case 0x6b:
        return new (std::nothrow) TRIBE_Action_Artifact(param_1, this->obj);
    case 0x6c:
        return new (std::nothrow) TRIBE_Action_Discovery_Artifact(param_1, this->obj);
    case 0x6e:
        return new (std::nothrow) TRIBE_Action_Hunt(param_1, this->obj);
    case 0x6f:
        return new (std::nothrow) TRIBE_Action_Trade(param_1, this->obj);
    case 0x78:
        return new (std::nothrow) TRIBE_Action_Wonder(param_1, this->obj);
    default:
        return RGE_Action_List::create_action(param_1, param_2);
    }
}

// Fully verified. Source of truth: tact_lst.cpp.decomp @ 0x004D05D0
RGE_Action* TRIBE_Action_List::create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    switch (param_1->action_type) {
    case 3:
        return new (std::nothrow) RGE_Action_Enter(this->obj, param_1, param_2);
    case 0x0c:
        return new (std::nothrow) RGE_Action_Transport(this->obj, param_1, param_3, param_4, param_5);
    case 0x65:
        return (param_2 != nullptr)
            ? (RGE_Action*)new (std::nothrow) TRIBE_Action_Build(this->obj, param_1, param_2)
            : (RGE_Action*)new (std::nothrow) TRIBE_Action_Build(this->obj, param_1, param_3, param_4, param_5);
    case 0x68:
        return (param_2 != nullptr)
            ? (RGE_Action*)new (std::nothrow) TRIBE_Action_Convert(this->obj, param_1, param_2)
            : (RGE_Action*)new (std::nothrow) TRIBE_Action_Convert(this->obj, param_1, param_3, param_4, param_5);
    case 0x69:
        return (param_2 != nullptr)
            ? (RGE_Action*)new (std::nothrow) TRIBE_Action_Heal(this->obj, param_1, param_2)
            : (RGE_Action*)new (std::nothrow) TRIBE_Action_Heal(this->obj, param_1, param_3, param_4, param_5);
    case 0x6a:
        return (param_2 != nullptr)
            ? (RGE_Action*)new (std::nothrow) TRIBE_Action_Repair(this->obj, param_1, param_2)
            : (RGE_Action*)new (std::nothrow) TRIBE_Action_Repair(this->obj, param_1, param_3, param_4, param_5);
    case 0x6b:
        return (param_2 != nullptr)
            ? (RGE_Action*)new (std::nothrow) TRIBE_Action_Artifact(this->obj, param_1, param_2)
            : (RGE_Action*)new (std::nothrow) TRIBE_Action_Artifact(this->obj, param_1, param_3, param_4, param_5);
    case 0x6c:
        return (param_2 != nullptr)
            ? (RGE_Action*)new (std::nothrow) TRIBE_Action_Discovery_Artifact(this->obj, param_1, param_2)
            : (RGE_Action*)new (std::nothrow) TRIBE_Action_Discovery_Artifact(this->obj, param_1, param_3, param_4, param_5);
    case 0x6e:
        return (param_2 != nullptr)
            ? (RGE_Action*)new (std::nothrow) TRIBE_Action_Hunt(this->obj, param_1, param_2)
            : (RGE_Action*)new (std::nothrow) TRIBE_Action_Hunt(this->obj, param_1, param_3, param_4, param_5);
    case 0x6f:
        return (param_2 != nullptr)
            ? (RGE_Action*)new (std::nothrow) TRIBE_Action_Trade(this->obj, param_1, param_2)
            : (RGE_Action*)new (std::nothrow) TRIBE_Action_Trade(this->obj, param_1, param_3, param_4, param_5);
    case 0x78:
        return new (std::nothrow) TRIBE_Action_Wonder(this->obj);
    default:
        return RGE_Action_List::create_task_action(param_1, param_2, param_3, param_4, param_5);
    }
}

uchar TRIBE_Action_List::inside_obj_update() {
    return RGE_Action_List::inside_obj_update();
}

uchar TRIBE_Action_List::update() {
    return RGE_Action_List::update();
}

// Fully verified. Source of truth: tact_lst.cpp.decomp @ 0x004D0C50
void TRIBE_Action_List::get_action_name(char* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    if (this->list == nullptr || this->list->action == nullptr) {
        strncpy(param_1, "None", 5);
        return;
    }

    const char* name = nullptr;
    switch (this->list->action->type()) {
    case 3: name = "Enter"; break;
    case 0x0c: name = "Transport"; break;
    case 0x65: name = "Build"; break;
    case 0x66: name = "MakeObject"; break;
    case 0x67: name = "MakeTech"; break;
    case 0x68: name = "Convert"; break;
    case 0x69: name = "Heal"; break;
    case 0x6a: name = "Repair"; break;
    case 0x6b: name = "Artifact"; break;
    case 0x6c: name = "DiscoveryArtifact"; break;
    case 0x6e: name = "Hunt"; break;
    case 0x6f: name = "Trade"; break;
    default:
        RGE_Action_List::get_action_name(param_1);
        return;
    }

    strncpy(param_1, name, 0x7fffffff);
}

void TRIBE_Action_List::copy_obj(RGE_Master_Action_Object* param_1) {
    RGE_Action_List::copy_obj(param_1);
}

void TRIBE_Action_List::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) {
    RGE_Action_List::copy_obj_sprites(param_1, param_2, param_3);
}

