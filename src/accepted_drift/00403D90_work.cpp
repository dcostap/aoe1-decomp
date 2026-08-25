// VA: 00403D90 RGE_Action_Gather::work
// PDB source: ACT_GATH.cpp.
// ACCEPTED_DRIFT: six bytes differ in null-path register scheduling.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

int RGE_Action_Gather::work(RGE_Static_Object* target,
                            float x, float y, float z) {
    if (target != 0) {
        if (target == this->target_obj &&
            (this->state == 4 || this->state == 6 || this->state == 7)) {
            return 1;
        }

        if (target->owner == this->obj->owner) {
            short id = target->master_obj->id;
            if ((id == this->obj->master_obj->drop_site ||
                 id == this->obj->master_obj->backup_drop_site) &&
                this->obj->attribute_amount_held > 0.0f) {
                this->timer = 0.0f;
                this->set_target_obj(0);
                this->target_x = -1.0f;
                this->target_y = -1.0f;
                this->target_z = -1.0f;
                this->set_target_obj2(target);
                this->set_state(8);
                return 1;
            }
        }

        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->set_target_obj2(0);
        this->set_state(4);
    } else {
        this->target_z = z;
        this->target_x = x;
        this->target_y = y;
        this->set_target_obj(0);
        this->set_state(15);
    }
    return 1;
}
