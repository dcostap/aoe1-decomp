// VA: 00403050 RGE_Action_Gather::first_in_stack
// PDB source: ACT_GATH.cpp.  The shared module context owns the class ABI.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

void RGE_Action_Gather::first_in_stack(uchar param1) {
    short attr = this->task->attribute_type;
    if (this->obj->attribute_type_held != attr) {
        this->obj->set_attribute(attr, 0);
    }

    if (param1 != 0) {
        RGE_Static_Object* target = this->target_obj;
        if (target != 0) {
            if (target->owner == this->obj->owner) {
                RGE_Master_Static_Object* target_master = target->master_obj;
                RGE_Master_Static_Object* object_master = this->obj->master_obj;
                short id = target_master->id;

                if ((id == object_master->drop_site ||
                     id == object_master->backup_drop_site) &&
                    this->obj->attribute_amount_held > DAT_0056e278) {
                    this->set_target_obj2(target);
                    this->set_target_obj(0);
                    this->target_x = -1.0f;
                    this->target_y = -1.0f;
                    this->target_z = -1.0f;
                    this->set_state(8);
                    return;
                }
            }
            this->set_state(4);
            return;
        } else {
            this->set_state(3);
            return;
        }
    }
    this->set_state(3);
}
