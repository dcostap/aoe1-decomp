#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::stop(void) {
    RGE_Combat_Object::stop();
    while (this->production_queue_count > 0) {
        this->remove_from_production_queue(this->production_queue->master_id, 1);
    }
}
