// ACCEPTED_DRIFT: constructor tail store-order drift only; the same vptr/type/tech/player fields are written after the same base-constructor call and before the same this return.
#include "../../include/tact_tek_context.h"

TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(RGE_Action_Object* object, short tech_id, int unique_id)
    : RGE_Action(object, 1) {
    this->unique_id = unique_id;
    this->action_type = 0x67;
    this->tech_id = tech_id;
}
