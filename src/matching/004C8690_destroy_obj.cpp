#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::destroy_obj() {
    this->take_building_attribute_from_owner();
    ((RGE_Action_Object*)this)->destroy_obj();
    this->master->creator->remove_doppleganger_check(this);
    this->DoppleInstalled = 0;
}
