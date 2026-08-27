#include "../../include/tact_hea.h"

TRIBE_Action_Heal::TRIBE_Action_Heal(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->action_type = 0x69;
}
