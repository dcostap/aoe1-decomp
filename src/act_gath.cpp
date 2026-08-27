// Authentic ACT_GATH.cpp source module.
//
// PDB source path: C:\\msdev\\work\\age1_x1\\ACT_GATH.cpp.
// The handwritten owners stay in PDB line and address order.  The vector
// deleting destructor at 00402F10 is compiler-generated.  The non-deleting
// destructor at 00402F30 is the small derived-to-base thunk emitted by the
// virtual destructor definition.
//
// Address and source-line bands:
// 00402EA0 (63-66), 00402F40 (74-90), 00402FD0 (98-110),
// 00403020 (116-119), 00403050 (125-159), 00403110 (165-377),
// 00403590 (383-752), 00403C60 (758-767), 00403C90 (773-780),
// 00403CD0 (786-789), 00403CE0 (796-831), and 00403D90 (837-887).
//
// Direct owner dependencies are included below.  The move-to constructor
// surface is declared locally because its owner module has no canonical public
// header yet.  Its complete ABI is RGE_Action plus the proven range float.
// RGE_Sound and RGE_Base_Game have the same narrow source-local declarations
// because no canonical owner header publishes those surfaces.

#include "../include/act_gath.h"
#include "../include/act_list.h"
#include "../include/act_obj.h"
#include "../include/m_ac_obj.h"
#include "../include/m_s_obj.h"
#include "../include/move_obj.h"
#include "../include/player.h"
#include "../include/stat_obj.h"
#include "../include/task.h"
#include "../include/world.h"
#include "../include/rge_base_game_global.h"

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float,
                       RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float,
                       RGE_Sprite*);

    float range;
};

typedef char rge_action_move_to_size_check[
    (sizeof(RGE_Action_Move_To) == 0x44) ? 1 : -1];

class RGE_Sound {
public:
    void play(int);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x9A4];
    int quick_build;
};

extern float DAT_0056e278;
extern double DAT_0056e280;
extern double DAT_0056e290;

// PDB lines 63-66; VA 00402EA0.
RGE_Action_Gather::RGE_Action_Gather(int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1) {
    this->action_type = 5;
    rge_read(file, &this->targetType, 4);
}

// The empty derived destructor emits the 00402F30 thunk.
RGE_Action_Gather::~RGE_Action_Gather() {
}

// PDB lines 74-90; VA 00402F40.
RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object* object,
                                     RGE_Task* task,
                                     RGE_Static_Object* target)
    : RGE_Action(object, 1) {
    this->task = task;
    this->action_type = 5;
    this->set_target_obj(target);
    if (target != 0) {
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->targetType = target->master_obj->id;
    }
}

// PDB lines 98-110; VA 00402FD0.
RGE_Action_Gather::RGE_Action_Gather(RGE_Action_Object* object,
                                     RGE_Task* task,
                                     float x, float y, float z)
    : RGE_Action(object, 1) {
    this->task = task;
    this->action_type = 5;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->targetType = -1;
}

// PDB lines 116-119; VA 00403020.
void RGE_Action_Gather::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->targetType, 4);
}

// PDB lines 125-159; VA 00403050.
void RGE_Action_Gather::first_in_stack(unsigned char param1) {
    short attr = this->task->attribute_type;
    if (this->obj->attribute_type_held != attr) {
        this->obj->set_attribute(attr, 0);
    }

    if (param1 != 0) {
        RGE_Static_Object* target = this->target_obj;
        if (target != 0) {
            if (target->owner == this->obj->owner) {
                RGE_Master_Static_Object* target_master = target->master_obj;
                RGE_Master_Action_Object* object_master =
                    (RGE_Master_Action_Object*)this->obj->master_obj;
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

// PDB lines 165-377; VA 00403110.
void RGE_Action_Gather::set_state(unsigned char param_1) {
    RGE_Action* move_to;

    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify((int)this->obj->id, (int)this->obj->id,
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
        facet = this->task->attribute_type;
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
                if (((RGE_Master_Action_Object*)this->obj->master_obj)->drop_site == -1) {
                    this->set_target_obj2(0);
                } else {
                    if (this->obj->useSameZoneDropsite() == 1) {
                        this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                            ((RGE_Master_Action_Object*)this->obj->master_obj)->drop_site,
                            ((RGE_Master_Action_Object*)this->obj->master_obj)->backup_drop_site,
                            this->obj->world_x,
                            this->obj->world_y,
                            1,
                            2,
                            (RGE_Static_Object*)this->obj));
                        goto gather_lookup_done;
                    }
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        ((RGE_Master_Action_Object*)this->obj->master_obj)->drop_site,
                        ((RGE_Master_Action_Object*)this->obj->master_obj)->backup_drop_site,
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
        this->obj->notify((int)this->obj->id, (int)this->obj->id,
                          0x203, 0x261, 0, 0);
        this->set_state(13);
        return;

gather_depleted:
        if (this->target_obj != 0 &&
            this->target_obj->attribute_amount_held <= DAT_0056e278 &&
            this->obj->keepGatheringWhenObjectIsOut(
                this->target_obj->master_obj->id) == 0) {
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

// PDB lines 383-752; VA 00403590.
unsigned char RGE_Action_Gather::update() {
    float give_amount;
    RGE_Player* check_player;

    if (this->targetID != -1 &&
        this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
    }
    if (this->target2ID != -1 &&
        this->obj->owner->world->object(this->target2ID) == 0) {
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
        this->obj->notify((int)this->obj->id, (int)this->obj->id,
                          0x1FB, 0x261, 0, 0);
        return 4;
    }

    switch ((int)this->state) {
    case 3:
        if (this->timer < DAT_0056e280) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_0056e280) {
                this->timer = -10.0f;
                this->obj->notify((int)this->obj->id, (int)this->obj->id,
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
                this->obj->keepGatheringWhenObjectIsOut(
                    (short)this->target_obj->master_obj->id) == 0) {
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
            give_amount = this->task->work_val1 *
                          ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate *
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
        max_hold = modifier * (float)this->obj->master_obj->attribute_max_amount -
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
            if (this->obj->keepGatheringWhenObjectIsOut(
                    (short)this->obj->master_obj->attribute_max_amount) != 0) {
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
                if (this->obj->distance_to_object(this->target_obj2) >
                    DAT_0056e290) {
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
                    (int)this->obj->id, (int)this->obj->id,
                    (int)this->obj->attribute_amount_held);
                this->obj->set_attribute(-1, 0.0f);
                if (this->target_obj != 0) {
                    this->set_target_obj2(0);
                    this->set_state(4);
                    return 0;
                }
                if (this->target_x != -1.0f &&
                    this->target_y != -1.0f) {
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
        this->obj->notify((int)this->obj->id, (int)this->obj->id,
                          0x1F9, 0x261, 0, 0);
        if (this->obj->owner->computerPlayer() == 1) {
            this->set_state(1);
        } else {
            this->set_state(2);
        }
        return 3;
    }

    return 0;
}

// PDB lines 758-767; VA 00403C60.
RGE_Sprite* RGE_Action_Gather::get_move_sprite() {
    RGE_Task* task = this->task;
    short task_facet = task->attribute_type;

    if (task_facet != -1) {
        if (this->obj->attribute_type_held == task_facet) {
            if ((int)this->obj->attribute_amount_held > 0) {
                if (task->carry_sprite != 0) {
                    return task->carry_sprite;
                }
            }
        }
    }
    return task->move_sprite;
}

// PDB lines 773-780; VA 00403C90.
RGE_Sprite* RGE_Action_Gather::get_wait_sprite() {
    RGE_Task* task = this->task;
    short value = task->attribute_type;
    if (value != (short)0xFFFF &&
        value == this->obj->attribute_type_held &&
        (int)this->obj->attribute_amount_held > 0 &&
        task->carry_sprite != 0) {
        return task->carry_sprite;
    }
    return this->obj->master_obj->sprite;
}

// PDB lines 786-789; VA 00403CD0.
int RGE_Action_Gather::stop() {
    this->set_state(2);
    return 1;
}

// PDB lines 796-831; VA 00403CE0.
int RGE_Action_Gather::move_to(RGE_Static_Object* target,
                               float x, float y, float z) {
    if (target != 0) {
        if (target->owner == this->obj->owner) {
            short id = target->master_obj->id;
            RGE_Master_Action_Object* object_master =
                (RGE_Master_Action_Object*)this->obj->master_obj;
            if (id == object_master->drop_site ||
                id == object_master->backup_drop_site) {
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

// PDB lines 837-887; VA 00403D90.
int RGE_Action_Gather::work(RGE_Static_Object* target,
                            float x, float y, float z) {
    if (target != 0) {
        if (target == this->target_obj &&
            (this->state == 4 || this->state == 6 || this->state == 7)) {
            return 1;
        }

        if (target->owner == this->obj->owner) {
            short id = target->master_obj->id;
            RGE_Master_Action_Object* object_master =
                (RGE_Master_Action_Object*)this->obj->master_obj;
            if ((id == object_master->drop_site ||
                 id == object_master->backup_drop_site) &&
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
