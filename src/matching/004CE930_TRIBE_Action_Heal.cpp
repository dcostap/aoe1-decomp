#include "../../include/tact_hea_context.h"

TRIBE_Action_Heal::TRIBE_Action_Heal(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1) {
    this->field_04 = 0x69;
}
