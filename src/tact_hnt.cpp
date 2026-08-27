// Authentic source module for the PDB compiland tact_hnt.cpp.
//
// PDB source path: C:\msdev\work\age1_x1\tact_hnt.cpp
// Source order and line bands:
// 004CF090 (70-73), 004CF130 (81-105), 004CF1C0 (113-124),
// 004CF210 (130-133), 004CF240 (139-171), 004CF300 (177-378),
// 004CF860 (384-794), 004CFF20 (800-807), 004CFF50 (813-820),
// 004CFF90 (826-833), 004CFFD0 (840-883), and 004D0080 (890-948).
//
// The PDB source path, source-line bands, ascending address sequence, class
// owner, and exact anchors establish this as one authentic translation unit.
// Exact anchors are 004CF090, 004CF130, 004CF1C0, 004CF240, 004CF300,
// 004CFF20, 004CFF90, and 004D0080. The 004CF210 and 004CFF50 bodies use
// their canonical inherited owners in this module.
// The scalar deleting destructor at 004CF100 is compiler-generated from the
// virtual class surface. It has no handwritten owner.

#include "../include/m_co_obj.h"
#include "../include/tact_hnt.h"
#include "../include/act_atak.h"
#include "../include/act_move.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/move_obj.h"
#include "../include/obj_list.h"
#include "../include/world.h"
#include "../include/player.h"
#include "../include/task.h"
#include "../include/sound.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"

extern float DAT_00575150;
extern double DAT_00575168;

// PDB lines 70-73; VA 004CF090.
TRIBE_Action_Hunt::TRIBE_Action_Hunt(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    this->action_type = 0x6E;
    rge_read(param_1, &targetType, 4);
}

// PDB lines 81-105; VA 004CF130.
TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object* obj, RGE_Task* tsk, RGE_Static_Object* target)
    : RGE_Action(obj, 1)
{
    this->task = tsk;
    this->action_type = 0x6E;
    this->set_target_obj(target);
    if (target && target->object_state < 7) {
        this->target_x = (float)target->world_x;
        this->target_y = (float)target->world_y;
        this->target_z = (float)target->world_z;
        this->targetType = target->master_obj->id;
    }
}

// PDB lines 113-124; VA 004CF1C0.
TRIBE_Action_Hunt::TRIBE_Action_Hunt(RGE_Action_Object* obj, RGE_Task* task,
                                     float x, float y, float z)
    : RGE_Action(obj, 1) {
    this->task = task;
    this->action_type = 0x6E;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->targetType = -1;
}

// PDB lines 130-133; VA 004CF210.
void TRIBE_Action_Hunt::save(int outfile) {
    this->RGE_Action::save(outfile);
    rge_write(outfile, &this->targetType, 4);
}

// PDB lines 139-171; VA 004CF240.
float _zero_val = 0.0f;

void TRIBE_Action_Hunt::first_in_stack(unsigned char param_1)
{
    RGE_Task* tsk = (RGE_Task*)this->task;

    short attr_val = tsk->attribute_type;
    if (this->obj->attribute_type_held != attr_val) {
        this->obj->set_attribute(attr_val, 0.0f);
    }

    if (param_1) {
        RGE_Static_Object* target = this->target_obj;
        if (target) {
            RGE_Static_Object* unit = this->obj;
            // Compare target->owner with unit->owner (order matters for register choice)
            if (target->owner == unit->owner) {
                RGE_Master_Static_Object* target_master = target->master_obj;
                RGE_Master_Action_Object* unit_master =
                    (RGE_Master_Action_Object*)unit->master_obj;
                short target_id = target_master->id;
                if (target_id == unit_master->drop_site || target_id == unit_master->backup_drop_site) {
                    if (unit->attribute_amount_held > _zero_val) {
                        this->set_target_obj2(target);
                        this->set_target_obj(0);
                        this->target_x = -1.0f;
                        this->target_y = -1.0f;
                        this->target_z = -1.0f;
                        this->set_state(8);
                        return;
                    }
                }
            }
            this->set_state(4);
        } else {
            this->set_state(3);
        }
    } else {
        this->set_state(3);
    }
}

// PDB lines 177-378; VA 004CF300.
void TRIBE_Action_Hunt::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x265,
                          this->targetType, 0);
        this->obj->new_sprite(this->get_wait_sprite());
        this->timer = -10.0f;
        return;

    case 2:
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->timer = 0.0f;
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11:
    case 15: {
        this->timer = 0.0f;
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj, this->target_x, this->target_y, this->target_z,
            this->task->work_range, this->get_move_sprite());
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        this->timer = 0.0f;
        if (this->target_obj == 0) {
            this->set_state(0x0D);
            return;
        }
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        if (this->target_obj->object_state <= 2) {
            this->set_state(0x0C);
            return;
        }
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj, this->target_obj, this->task->work_range,
            this->get_move_sprite());
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 12: {
        this->timer = 0.0f;
        // BINARY NOTE: The action master is stored as a static-master pointer.
        // These three reads prove the combat-master fields at +0x124, +0x12A,
        // and +0x138.
        RGE_Action_Attack* action = new RGE_Action_Attack(
            this->obj, this->target_obj, this->get_move_sprite(),
            this->task->work_sprite, 0, this->task->work_range,
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)->minimum_weapon_range,
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)->missile_id,
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)->fire_missile_at_frame);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 6:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_move_sprite());
        return;

    case 7:
        this->timer = 0.0f;
        // BINARY NOTE: State 7 reads attribute_type_held (+0x4C), then calls
        // the inherited set_attribute virtual at slot +0x80.
        if (this->obj->attribute_type_held != this->task->attribute_type) {
            this->obj->set_attribute(this->task->attribute_type, 0);
        }
        this->obj->new_sprite(this->task->work_sprite2);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
        }
        return;

    case 8:
        if (this->obj->attribute_amount_held > DAT_00575150) {
            if (this->target_obj2 == 0) {
                if (static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->drop_site != -1) {
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->drop_site,
                        static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->backup_drop_site,
                        this->obj->world_x, this->obj->world_y, 1, 2,
                        (RGE_Static_Object*)this->obj));
                } else {
                    this->set_target_obj2(0);
                }
            }
            if (this->target_obj2 != 0) {
                RGE_Action_Move_To* action = new RGE_Action_Move_To(
                    this->obj, this->target_obj2, this->task->work_range,
                    this->get_move_sprite());
                if (action == 0) {
                    this->set_state(0x0D);
                    return;
                }
                this->sub_actions->add_action(action);
                action->setSubAction(1);
                return;
            }
            this->obj->notify(this->obj->id, this->obj->id, 0x203, 0x265, 0, 0);
            if (this->obj->owner->computerPlayer() == 0) {
                this->set_state(2);
            } else {
                this->set_state(1);
            }
            return;
        }
        // BINARY NOTE: The shipped check reads target_obj (+0x10), not
        // target_obj2 (+0x14), before clearing target_obj.
        // LIKELY INTENT: Clear the current target before state 3.
        if (this->target_obj != 0 &&
            this->target_obj->attribute_amount_held <= DAT_00575150) {
            this->set_target_obj(0);
        }
        this->set_state(3);
        return;

    case 1:
    case 13:
    case 14:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_wait_sprite());
        return;

    default:
        return;
    }
}

// PDB lines 384-794; VA 004CF860.
unsigned char TRIBE_Action_Hunt::update()
{
    float give_amount;
    volatile float modifier;
    float max_hold;
    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0)
        this->set_target_obj(0);
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0)
        this->set_target_obj2(0);

    RGE_Static_Object* p = this->target_obj;
    if (p != 0 && p->object_state >= 7)
        this->set_target_obj(0);
    p = this->target_obj2;
    if (p != 0 && p->object_state >= 7)
        this->set_target_obj2(0);

    switch (this->state) {
    case 3:
        if (this->timer < 0.0) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > 0.0) {
                this->timer = -10.0f;
                this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x265, this->targetType, 0);
                return 0;
            }
        }
        break;
    case 11:
    case 15:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            this->set_target_obj(0);
            if (this->state == 11) { this->set_state(11); return 0; }
            this->set_state(15); return 0;
        case 4:
            if (this->state == 11) { this->set_state(3); return 0; }
            goto computer_fallback;
        case 3:
            if (this->obj->owner->computerPlayer() == 1) { this->set_state(13); return 0; }
            goto state_default;
        }
        break;
state_default:
        this->set_state(3); return 0;
    case 4:
        switch (this->sub_actions->update()) {
        case 3:
            if (this->obj->owner->computerPlayer() != 0) {
                this->set_state(13); return 0;
            }
            goto state_default;
        case 1:
        case 2:
            this->set_state(6); return 0;
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        }
        break;
    case 12:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            this->set_state(11); return 0;
        case 1:
        case 2:
        case 5:
            if (this->target_obj != 0) { this->set_state(4); return 0; }
        case 3:
            this->set_state(3); return 0;
        }
        break;
    case 6:
        if (this->target_obj == 0) { this->set_state(3); return 0; }
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            if (this->target_obj->attribute_amount_held <= DAT_00575150) {
                this->set_target_obj(0); this->set_state(3); return 0;
            }
            this->set_state(7); return 0;
        }
        goto state_default;
    case 7: {
        RGE_Static_Object* holder = this->target_obj;
        if (holder == 0) {
            holder = (RGE_Static_Object*)this->obj;
            if (holder->attribute_amount_held <= DAT_00575150)
                goto state_default;
            this->set_state(8);
            return 0;
        }
        if (rge_base_game->quick_build != 0)
            give_amount = holder->attribute_amount_held;
        else {
            give_amount = this->task->work_val1 *
                static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->work_rate *
                this->obj->owner->world->world_time_delta_seconds;
        }
        if (holder->attribute_amount_held < give_amount)
            give_amount = holder->attribute_amount_held;
        short attr = this->task->attribute_type2;
        if (attr == -1) modifier = 1.0f;
        else modifier = this->obj->owner->attributes[attr];
        max_hold = (float)static_cast<RGE_Master_Static_Object*>(this->obj->master_obj)->attribute_max_amount * modifier - this->obj->attribute_amount_held;
        if (max_hold < modifier * give_amount)
            give_amount = give_amount - (modifier * give_amount - max_hold) / modifier;
        holder->set_attribute_amount(-give_amount, 1, 1);
        this->obj->set_attribute_amount(give_amount, 1, 0);
        if (this->obj->attribute_amount_held <= give_amount || this->obj->attribute_amount_held <= DAT_00575150)
            this->set_state(8);
        break;
    }
    case 8:
        if (this->timer < 0.0) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > 0.0) {
                this->timer = 0.0;
                this->set_target_obj2(0);
                this->set_state(8);
                return 0;
            }
        } else {
            switch (this->sub_actions->update()) {
            case 1:
            case 2:
                if (this->target_obj2 == 0) { this->set_state(8); return 0; }
                if (this->obj->distance_to_object(this->target_obj2) > DAT_00575168) {
                    this->timer = -1.5f;
                    this->obj->stop_moving();
                    return 0;
                }
                if (this->task->work_sound2 != 0) this->task->work_sound2->play(1);
                { short attr = this->task->attribute_type3; if (attr == -1) attr = this->obj->attribute_type_held;
                  this->obj->owner->add_attribute_num(attr, this->obj->attribute_amount_held, 0); }
                this->obj->owner->trackUnitGather(this->obj->id, this->obj->id, (int)this->obj->attribute_amount_held);
                this->obj->set_attribute(-1, 0.0f);
                if (this->target_obj != 0) { this->set_target_obj2(0); this->set_state(4); return 0; }
                if (this->target_x != -1.0f && this->target_y != -1.0f) { this->set_state(11); return 0; }
                goto computer_fallback;
            case 3:
            case 4:
            case 5:
                this->timer = -1.5f; this->obj->stop_moving(); return 0;
            }
        }
        break;
computer_fallback:
        if (this->obj->owner->computerPlayer() == 0) {
        this->set_state(2);
        return 0;
    }
    this->set_state(1);
state_default2:
    return 0;
    case 1:
        if (this->obj->owner->computerPlayer() == 0)
            this->set_state(2);
        return 1;
    case 13:
        this->obj->notify(this->obj->id, this->obj->id, 0x1f9, 0x265, 0, 0);
        return 3;
    }
    return 0;
}

// PDB lines 800-807; VA 004CFF20.
RGE_Sprite* TRIBE_Action_Hunt::get_move_sprite(void) {
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;
    if (task_facet != -1 && task_facet == this->obj->attribute_type_held &&
        (int)this->obj->attribute_amount_held > 0 && task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return task->move_sprite;
}

// PDB lines 813-820; VA 004CFF50.
RGE_Sprite* TRIBE_Action_Hunt::get_wait_sprite(void) {
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;
    if (task_facet != -1 && task_facet == this->obj->attribute_type_held &&
        (int)this->obj->attribute_amount_held > 0 && task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return this->obj->master_obj->sprite;
}

// PDB lines 826-833; VA 004CFF90.
int TRIBE_Action_Hunt::stop(void) {
    if (this->obj->owner->computerPlayer() == 0) {
        this->set_state(2);
        return 1;
    }
    this->set_state(1);
    return 1;
}

// PDB lines 840-883; VA 004CFFD0.
int TRIBE_Action_Hunt::move_to(RGE_Static_Object* target, float x, float y, float z) {
    if (target != 0 && target->owner == this->obj->owner) {
        RGE_Master_Action_Object* master =
            static_cast<RGE_Master_Action_Object*>(this->obj->master_obj);
        short id = target->master_obj->id;
        if ((id == master->drop_site || id == master->backup_drop_site) &&
            this->obj->attribute_amount_held > DAT_00575150) {
            if (target == this->target_obj2 && this->state == 8) {
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
    this->target_z = z;
    this->target_x = x;
    this->target_y = y;
    this->set_target_obj(0);
    this->set_state(0x0F);
    return 1;
}

// PDB lines 890-948; VA 004D0080.
int TRIBE_Action_Hunt::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4)
{
    if (param_1 != 0) {
        if (param_1->owner == this->obj->owner) {
            RGE_Master_Action_Object* master =
                static_cast<RGE_Master_Action_Object*>(this->obj->master_obj);
            short obj_id = param_1->master_obj->id;
            if ((obj_id == master->drop_site || obj_id == master->backup_drop_site) &&
                this->obj->attribute_amount_held > DAT_00575150) {
                this->set_target_obj(0);
                this->timer = 0.0f;
                this->target_x = -1.0f;
                this->target_y = -1.0f;
                this->target_z = -1.0f;
                this->set_target_obj2(param_1);
                this->set_state(8);
                return 1;
            }
        }
        this->set_target_obj(param_1);
        this->set_target_obj2(0);
        this->set_state(4);
        return 1;
    }
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = param_4;
    this->set_target_obj(0);
    this->set_state(0x0F);
    return 1;
}
