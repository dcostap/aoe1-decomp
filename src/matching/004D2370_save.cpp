#include "../../include/tact_tek_context.h"

void TRIBE_Action_Make_Tech::save(int file) {
    RGE_Action::save(file);
    rge_write(file, &this->tech_id, 2);
    rge_write(file, &this->unique_id, 4);
}
