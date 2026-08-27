// Source module: C:\\msdev\\work\\age1_x1\\tact_cnv.cpp
//
// The definitions follow the original PDB line and address order.

#include "../include/tact_cnv.h"

TRIBE_Action_Convert::TRIBE_Action_Convert(int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1), requiredRange(1.0f)
{
    this->action_type = 0x68;
    rge_read(file, &this->was_same_owner, 1);
    rge_read(file, &this->requiredRange, 4);
}

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* object,
                                           RGE_Task* task,
                                           RGE_Static_Object* target)
    : RGE_Action(object, 1), requiredRange(1.0f)
{
    this->task = task;
    this->action_type = 0x68;
    RGE_Action::set_target_obj(target);
    if (target != 0) {
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
    }
    this->was_same_owner = 0;
}

TRIBE_Action_Convert::TRIBE_Action_Convert(RGE_Action_Object* object,
                                           RGE_Task* task,
                                           float x, float y, float z)
    : RGE_Action(object, 1), requiredRange(1.0f)
{
    this->task = task;
    this->action_type = 0x68;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->was_same_owner = 0;
}

void TRIBE_Action_Convert::save(int file)
{
    RGE_Action::save(file);
    rge_write(file, &this->was_same_owner, 1);
    rge_write(file, &this->requiredRange, 4);
}

void TRIBE_Action_Convert::first_in_stack(uchar param_1)
{
    RGE_Static_Object* target = this->target_obj;
    if (target != 0) {
        int object_group = target->master_obj->object_group;
        RGE_Action_Object* object = this->obj;
        if (target->owner == this->obj->owner) {
            this->was_same_owner = 1;
        } else {
            this->was_same_owner = 0;
        }
        short target_id = target->master_obj->id;
        if (target_id == 0x6d || object_group == 0x1b || target_id == 0x9f ||
            target_id == 0x9e || target_id == 0xa3 || target_id == 0x114) {
            if (object->owner->computerPlayer() == 1) {
                this->set_state(0x0b);
            } else {
                this->set_state(0x0d);
            }
            target_id = this->target_obj->master_obj->id;
            if (target_id == 0x6d) {
                rge_base_game->notification(0x79,
                                            (int)this->obj->owner->id,
                                            0, 0, 0);
                return;
            }
            if (target_id == 0x114) {
                rge_base_game->notification(0x7a,
                                            (int)this->obj->owner->id,
                                            0, 0, 0);
                return;
            }
            return;
        }
        if (object->attribute_amount_held < 100.0) {
            this->set_state(0x0d);
            rge_base_game->notification(0x76,
                                        (int)this->obj->owner->id, 0, 0, 0);
            return;
        }
        if (object_group == 3) {
            this->requiredRange = 1.0f;
        } else {
            this->requiredRange = object->master_obj->weapon_range;
        }
        if (object_group == 0x1e) {
            this->set_state(0x0d);
            return;
        }
        if (object_group == 0x12 &&
            object->owner->attributes[0x1b] <= 0.0f) {
            if (object->owner->computerPlayer() == 1) {
                this->set_state(0x0b);
            } else {
                this->set_state(0x0d);
            }
            rge_base_game->notification(0x77,
                                        (int)this->obj->owner->id, 0, 0, 0);
            return;
        }
        if (object_group == 3 && object->owner->attributes[0x1c] <= 0.0f) {
            if (object->owner->computerPlayer() == 1) {
                this->set_state(0x0b);
            } else {
                this->set_state(0x0d);
            }
            rge_base_game->notification(0x78,
                                        (int)this->obj->owner->id, 0, 0, 0);
            return;
        }
    }
    if (param_1 != 0) {
        if (target != 0) {
            this->set_state(4);
            return;
        } else {
            this->set_state(3);
            return;
        }
    }
    this->set_state(3);
}

void TRIBE_Action_Convert::set_state(uchar param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;
    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x25C, 0, 0);
        goto master_sprite;

    case 11: {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            this->requiredRange,
            this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            this->requiredRange,
            this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 5:
        return;

    case 6:
        this->obj->new_sprite(this->task->move_sprite);
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0)
            this->task->work_sound->play(1);
        if (this->target_obj != 0 && this->target_obj->owner->id > 0) {
            this->target_obj->owner->make_new_object(
                0x70, this->obj->world_x, this->obj->world_y,
                this->obj->world_z, 0);
        }
        this->timer = this->task->work_val2;
        return;

    case 8:
    case 9:
    case 10:
    case 12:
    case 1:
    case 2:
    case 13:
    case 14:
    master_sprite:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    default:
        return;
    }
}

uchar TRIBE_Action_Convert::update()
{
    if (this->target_id != -1) {
        if (this->obj->owner->world->object(this->target_id) == 0) {
            this->set_target_obj(0);
            this->set_state(3);
            return 0;
        }
    }

    if (this->target2_id != -1) {
        if (this->obj->owner->world->object(this->target2_id) == 0) {
            this->set_target_obj2(0);
        }
    }

    if (this->target_obj != 0 && this->target_obj->object_state != 2) {
        this->set_target_obj(0);
        this->set_state(3);
        return 0;
    }

    if (this->target_obj != 0 &&
        this->obj->owner->isAlly(this->target_obj->owner->id) == 1) {
        if (this->state == 7 || this->state == 6 || this->state == 4) {
            this->obj->set_attribute(0x22, 0);
        }
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1fb, 0x25c, 0, 0);
        return 4;
    }

    switch (this->state) {
    case 4:
        switch (this->sub_actions->update()) {
        case 3:
            this->set_state(13);
            return 0;
        case 4:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        }
        break;

    case 11:
        switch (this->sub_actions->update()) {
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        case 3:
            this->set_state(13);
            return 0;
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        }
        break;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        this->target_obj->notify(
            this->obj->id, this->target_obj->id, 500, this->obj->id,
            this->target_obj->hp, this->target_obj->master_obj->hp);
        this->timer = this->timer -
                      this->obj->owner->world->world_time_delta_seconds;
        if (this->timer <= 0.0f) {
            if (this->target_obj != 0 && this->target_obj->owner->id > 0) {
                this->target_obj->owner->make_new_object(
                    0x70, this->obj->world_x, this->obj->world_y,
                    this->obj->world_z, 0);
            }
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\tact_cnv.cpp",
                               0x1d7);
            float chance = (float)r * DAT_00574ffc;
            RGE_Player* tplayer = this->target_obj->owner;
            if (tplayer->master_player_id == 0x10) {
                chance = chance * DAT_00575000;
            } else {
                short type = this->target_obj->master_obj->object_group;
                if (type == 0x15 || type == 2 || type == 0x14 ||
                    type == 0x16 || type == 0x12) {
                    chance = chance + chance;
                } else if (type == 0x23 || type == 0x17) {
                    chance = chance * DAT_00575004;
                }
            }
            // BINARY NOTE: Direct field ownership preserves the original x87 order.
            if (chance <= this->task->work_val1 *
                           this->obj->master_obj->work_rate) {
                rge_base_game->notification(0x7b, this->obj->owner->id,
                                             this->target_obj->owner->id, 0, 0);
                this->target_obj->change_ownership(this->obj->owner);
                this->obj->owner->add_attribute_num(0x29, 1.0f, 0);
                this->obj->set_attribute(0x22, 0);
                this->set_state(3);
            }
            this->set_state(4);
            return 0;
        }
        break;
    }

    case 1:
        return 1;

    case 13:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1f9, 0x25c, 0, 0);
        this->set_state(2);
        return 3;
    }

    return 0;
}

int TRIBE_Action_Convert::work(RGE_Static_Object* target,
                               float, float, float)
{
    if (target != 0) {
        if (target == this->target_obj) {
            uchar state = this->state;
            if (state == 4 || state == 6 || state == 7)
                return 1;
        }
        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->first_in_stack(1);
        return 1;
    }
    return 0;
}

void TRIBE_Action_Convert::martyrdom()
{
    if (this->state != 7) {
        return;
    }
    if (this->target_obj == 0) {
        return;
    }
    if (this->target_obj->master_obj->object_group == 0x12) {
        return;
    }

    int target_id = this->target_obj->owner->id;
    int source_id = this->obj->owner->id;

    rge_base_game->notification(0x7B, source_id, target_id, 0, 0);
    this->target_obj->change_ownership(this->obj->owner);
    this->obj->owner->add_attribute_num(0x29, 1.0f, 0);
    this->obj->set_attribute(0x22, 0);
    this->set_state(3);
}

TRIBE_Action_Convert::~TRIBE_Action_Convert()
{
}

static void tact_cnv_force_vector_delete(TRIBE_Action_Convert* value)
{
    delete [] value;
}
