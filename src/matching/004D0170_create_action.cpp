// 004D0170 TRIBE_Action_List::create_action
// PDB source: tact_lst.cpp:43-88
// BINARY NOTE: The shipped ABI takes (int, short), and the switch allocates
// the period action sizes before invoking the corresponding constructors.

#include "../../include/tact_lst_context.h"

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
