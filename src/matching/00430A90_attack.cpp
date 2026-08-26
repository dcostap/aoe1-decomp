// VA: 00430A90 RGE_Combat_Object::attack(float,float,float,int)
// PDB source: com_obj.cpp lines 827-869
// attempt 1: natural new RGE_Action_Attack with repeated current-action checks and EH new frame.
// attempt 2: action type virtual lives at +0x18 and attack ctor wants master short +0x12A, not +0x13E.
// attempt 3: set_only_action uses the canonical virtual slot at +0x208.

#include "../com_obj_phase2_context.h"

int RGE_Combat_Object::attack(float x, float y, float z, int force)
{
    if (force == 0) {
        if (this->action_list->have_action() == 1) {
            if (this->action_list->get_action()->targetX() == x) {
                if (this->action_list->get_action()->targetX() == y) {
                    if (this->action_list->get_action()->targetX() == z) {
                        if (this->action_list->get_action()->type() == 9) {
                            return 1;
                        }
                        if (this->action_list->get_action()->type() == 7) {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    RGE_Action_Attack* action = new RGE_Action_Attack(this, x, y, z, 0, 0, 0,
        this->master->field_114, this->master->field_138, this->master->field_124, this->master->field_12A);
    if (action == 0) {
        return 0;
    }
    this->action_list->delete_list();
    this->set_only_action(action);
    return 1;
}
