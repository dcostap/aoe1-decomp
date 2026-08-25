// VA: 00403CE0 RGE_Action_Gather::move_to
// PDB source: ACT_GATH.cpp.
// ACCEPTED_DRIFT: this function has a six-byte register-scheduling drift in
// the null path.  The field mapping and branch behavior stay unchanged.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

int RGE_Action_Gather::move_to(RGE_Static_Object* target,
                               float x, float y, float z) {
    if (target != 0) {
        if (target->owner == this->obj->owner) {
            short id = target->master_obj->id;
            if (id == this->obj->master_obj->drop_site ||
                id == this->obj->master_obj->backup_drop_site) {
                if (this->obj->attribute_amount_held > 0.0f) {
                    if (target == this->target_obj && this->state == 8) {
                        return 1;
                    }
                    this->set_target_obj(0);
                    this->target_x = -1.0f;
                    this->target_y = -1.0f;
                    this->target_z = -1.0f;
                    this->set_target_obj2(target);
                    this->set_state(8);
                    return 1;
                }
            }
        }
    }

    this->target_z = z;
    this->target_x = x;
    this->target_y = y;
    this->set_target_obj(0);
    this->set_state(15);
    return 1;
}
