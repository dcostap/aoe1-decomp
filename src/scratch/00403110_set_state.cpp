// VA: 00403110 RGE_Action_Gather::set_state
// PDB source: ACT_GATH.cpp.
//
// BINARY NOTE: state 8 uses the two proven lookup arms and one shared
// Move_To tail.  The natural source keeps those owners and call targets.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

void RGE_Action_Gather::set_state(uchar param_1) {
    RGE_Action* move_to;

    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x202, 0x261, this->targetType, 0);
        this->timer = -10.0f;
        break;

    case 2:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11:
    case 15:
        this->timer = 0.0f;
        move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            this->task->work_range,
            this->get_move_sprite());
        if (move_to == 0) {
            this->set_state(13);
            return;
        }
        this->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;

    case 4:
        this->timer = 0.0f;
        if (this->target_obj == 0) {
            this->set_state(13);
            return;
        }
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            this->task->work_range,
            this->get_move_sprite());
        goto gather_action_tail;

    case 6:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_move_sprite());
        return;

    case 7: {
        short facet;
        this->timer = 0.0f;
        facet = this->task->facet;
        if (this->obj->attribute_type_held != facet) {
            this->obj->set_attribute(facet, 0);
        }
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
        }
        return;
    }

    case 8:
        if (this->obj->attribute_amount_held > DAT_0056e278) {
            if (this->target_obj2 == 0) {
                if (this->obj->master_obj->drop_site == -1) {
                    this->set_target_obj2(0);
                } else {
                    if (this->obj->useSameZoneDropsite() == 1) {
                        this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                            this->obj->master_obj->drop_site,
                            this->obj->master_obj->backup_drop_site,
                            this->obj->world_x,
                            this->obj->world_y,
                            1,
                            2,
                            (RGE_Static_Object*)this->obj));
                        goto gather_lookup_done;
                    }
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        this->obj->master_obj->drop_site,
                        this->obj->master_obj->backup_drop_site,
                        this->obj->world_x,
                        this->obj->world_y,
                        1,
                        2,
                        0));
                }
            }

gather_lookup_done:
            if (this->target_obj2 != 0) {
                move_to = new RGE_Action_Move_To(
                    this->obj,
                    this->target_obj2,
                    this->task->work_range,
                    this->get_move_sprite());
                goto gather_action_tail;
            }
            goto gather_no_target;
        }

        goto gather_depleted;

gather_action_tail:
        if (move_to == 0) {
            this->set_state(13);
            return;
        }
        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;

gather_no_target:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x203, 0x261, 0, 0);
        this->set_state(13);
        return;

gather_depleted:
        if (this->target_obj != 0 &&
            this->target_obj->attribute_amount_held <= DAT_0056e278 &&
            this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) == 0) {
            this->set_target_obj(0);
        }
        this->set_state(3);
        return;

    case 1:
    case 13:
    case 14:
        this->timer = 0.0f;
        break;

    default:
        return;
    }

    this->obj->new_sprite(this->get_wait_sprite());
}
