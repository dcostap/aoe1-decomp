// VA: 00403590 RGE_Action_Gather::update
// PDB source: ACT_GATH.cpp.
//
// BINARY NOTE: both state-8 stop paths store -3.0f before the stop call.
// Keep the natural typed action, object, player, and task surfaces here.

#ifndef ACT_GATH_CONTEXT_H
#include "../../include/act_gath_context.h"
#endif

unsigned char RGE_Action_Gather::update() {
    float give_amount;
    RGE_Player* check_player;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
    }
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj(0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->object_state >= 7) {
        this->set_target_obj2(0);
    }

    RGE_Static_Object* check_obj = this->target_obj;
    if (check_obj != 0 && check_obj->owner->id != 0 &&
        check_obj->owner->id != this->obj->owner->id) {
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x261, 0, 0);
        return 4;
    }

    switch ((int)this->state) {
    case 3:
        if (this->timer < DAT_0056e280) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_0056e280) {
                this->timer = -10.0f;
                this->obj->notify(this->obj->id, this->obj->id,
                                  0x202, 0x261, this->targetType, 0);
                return 0;
            }
        }
        break;

    case 11:
    case 15:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            if (this->state == 11) {
                this->set_state(11);
                return 0;
            }
            this->set_state(15);
            return 0;
        case 3:
            check_player = this->obj->owner;
            goto computer_check;
        case 1:
        case 2:
        case 5:
            if (this->state == 11) {
                this->set_state(3);
                return 0;
            }
            goto computer_fallback;
        }
        break;

    case 4: {
        unsigned char result = this->sub_actions->update();
        switch (result) {
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        case 3:
            check_player = this->obj->owner;
            goto computer_check;
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        }
        break;
    }

    case 6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            if (this->target_obj->attribute_amount_held <= DAT_0056e278 &&
                this->obj->keepGatheringWhenObjectIsOut((short)this->target_obj->master_obj->id) == 0) {
                this->set_target_obj(0);
                this->set_state(3);
                return 0;
            }
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        float modifier;
        float max_hold;
        if (this->target_obj == 0) {
            if (this->obj->attribute_amount_held > DAT_0056e278) {
                this->set_state(8);
                return 0;
            }
            this->set_state(3);
            return 0;
        }
        if (rge_base_game->quick_build != 0) {
            give_amount = this->target_obj->attribute_amount_held;
        } else {
            give_amount = this->task->gather_amount *
                          this->obj->object_data->gather_multiplier *
                          this->obj->owner->world->world_time_delta_seconds;
        }
        if (give_amount > this->target_obj->attribute_amount_held) {
            give_amount = this->target_obj->attribute_amount_held;
        }
        short attr = this->task->attribute_type2;
        if (attr == -1) {
            modifier = 1.0f;
        } else {
            modifier = this->obj->owner->attribute_table[attr];
        }
        max_hold = modifier * (float)this->obj->object_data->attribute_type -
                   this->obj->attribute_amount_held;
        if (max_hold < modifier * give_amount) {
            give_amount = give_amount -
                          (modifier * give_amount - max_hold) / modifier;
        }
        this->target_obj->set_attribute_amount(-give_amount, 1, 1);
        this->obj->set_attribute_amount(give_amount, 1, 0);
        if (this->obj->attribute_amount_held < give_amount) {
            if (this->obj->attribute_amount_held > DAT_0056e278) {
                return 0;
            }
            if (this->obj->keepGatheringWhenObjectIsOut((short)this->obj->object_data->attribute_type) != 0) {
                return 0;
            }
            this->set_state(8);
        }
        break;
    }

    case 8:
        if (this->timer < DAT_0056e280) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_0056e280) {
                this->timer = 0.0f;
                this->set_state(8);
                return 0;
            }
        } else {
            switch (this->sub_actions->update()) {
            case 3:
            case 4:
            case 5:
                this->timer = -3.0f;
                this->obj->stop_moving();
                return 0;
            case 1:
            case 2:
                if (this->target_obj2 == 0) {
                    this->set_state(8);
                    return 0;
                }
                if (this->obj->distance_to_object(this->target_obj2) > DAT_0056e290) {
                    this->timer = -3.0f;
                    this->obj->stop_moving();
                    return 0;
                }
                if (this->task->work_sound2 != 0) {
                    this->task->work_sound2->play(1);
                }
                {
                    short attr = this->task->attribute_type3;
                    if (attr == -1) {
                        attr = this->obj->owner->fallback_attribute;
                    }
                    this->obj->owner->add_attribute_num(
                        attr, this->obj->attribute_amount_held, 0);
                }
                this->obj->owner->trackUnitGather(
                    this->obj->id, this->obj->id,
                    (int)this->obj->attribute_amount_held);
                this->obj->set_attribute(-1, 0.0f);
                if (this->target_obj != 0) {
                    this->set_target_obj2(0);
                    this->set_state(4);
                    return 0;
                }
                if (this->target_x != -1.0f && this->target_y != -1.0f) {
                    this->set_state(11);
                    return 0;
                }
                goto computer_fallback;
            }
        }
        break;

computer_fallback:
        if (this->obj->owner->computerPlayer() == 1) {
            this->set_state(1);
        } else {
            this->set_state(2);
        }
        return 0;

computer_check:
        if (check_player->computerPlayer() == 1) {
            this->set_state(13);
            return 0;
        }
        this->set_state(3);
        return 0;

    case 1:
        return 1;

    case 13:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x261, 0, 0);
        if (this->obj->owner->computerPlayer() == 1) {
            this->set_state(1);
        } else {
            this->set_state(2);
        }
        return 3;
    }

    return 0;
}
