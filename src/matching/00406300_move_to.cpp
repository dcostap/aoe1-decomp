// VA: 00406300 RGE_Action_Object::move_to
// PDB source: act_obj.cpp lines 218-247
// The module uses the reviewed action-object and action-list declarations.

#include "../../include/act_obj_context.h"

void RGE_Action_Object::move_to(RGE_Static_Object* target, float x, float y, float z)
{
    if ((RGE_Action_Object*)target != this) {
        if (this->actions->action_move_to(target, x, y, z) == 0) {
            RGE_Action_Move_To* action;

            if (target != 0) {
                action = new RGE_Action_Move_To(this, target, 0.4f, 0);
            } else {
                action = new RGE_Action_Move_To(this, x, y, z, 0.4f, 0);
            }

            if (this->unitAIValue != 0) {
                this->unitAIValue->setCurrentOrder(0x2C6);
                this->unitAIValue->setCurrentAction(0x262);
                if (target != 0) {
                    this->unitAIValue->setCurrentTarget(target->id,
                        ((RGE_Master_Static_Object*)target->master_obj)->object_group,
                        x, y, z);
                } else {
                    this->unitAIValue->setCurrentTarget(-1, -1, x, y, z);
                }
            }

            if (action != 0) {
                this->set_action(action);
            }
            this->command_flag = this->command_flag + 1;
        }
    }
}
