// VA: 004D2020 TRIBE_Action_Repair::meet_target (388 B)
// PDB: tact_rep.cpp:501-557
// Baseline reconstruction uses the typed action/object/player ownership chain.
// The target's owner list supplies repair actions. The original source uses
// ordinary virtual calls for target/state/path queries and direct action helpers.
// Attempt log:
// - Baseline matched size/frame/calls and left six bytes from master-field and receiver offsets.
// - Split master id (+10) from object_group (+14); the candidate gate uses id.
// - Restored RGE_Static_Object size through +88; command_flag then landed at +188.
// - Corrected moveTo and command_flag receivers to target_obj; exact match followed.

#include "../../include/tact_rep_context.h"

void TRIBE_Action_Repair::meet_target() {
    XYPoint rVal;
    XYPoint start;
    XYPoint dest;
    short type = this->target_obj->master_obj->object_group;

    if (type == 2 || type == 0x14 || type == 0x15 || type == 0x16) {
        RGE_Object_Node* node = this->obj->owner->objects->list;
        while (node != 0) {
            RGE_Action_Object* action = node->object;
            if (action != this->obj && action->master_obj->id == 0x9C) {
                if (action->get_target_obj() == this->target_obj && action->actionState() != 2) {
                    if (this->target_obj->actionState() == 0x0B) {
                        this->target_x = this->target_obj->actions->get_action()->targetX();
                        this->target_y = this->target_obj->actions->get_action()->targetY();
                    } else {
                        this->target_x = this->target_obj->world_x;
                        this->target_y = this->target_obj->world_y;
                    }
                    return;
                }
            }
            node = node->next;
        }

        dest.x = (int)this->obj->world_x;
        dest.y = (int)this->obj->world_y;
        start.x = (int)this->target_obj->world_x;
        start.y = (int)this->target_obj->world_y;
        if (this->obj->firstTileAlongLine(&dest, &start, &rVal, 2, 2, 1) == 1) {
            this->target_x = (float)rVal.x + 0.5f;
            this->target_y = (float)rVal.y + 0.5f;
            this->target_obj->moveTo((float)rVal.x + 0.5f, (float)rVal.y + 0.5f,
                                     this->target_obj->world_z, 0.0f, 1);
            this->save_target_command_flag = this->target_obj->command_flag;
        }
    }
}
