#include "../include/act_tran.h"
#include "../include/act_obj.h"
#include "../include/act_list.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/task.h"
#include "../include/world.h"

//
// Direct dependency closure:
// - act_tran.h owns RGE_Action_Transport and consumes RGE_Action_Move_To.
// - action.h owns the RGE_Action base and its fields and virtual slots.
// - act_obj.h owns the complete action-object inheritance chain.
// - act_list.h owns action-list fields and methods.
// - map.h, player.h, task.h, and world.h own the accessed map, player, task,
//   and world fields and methods.
// - m_s_obj.h and stat_obj.h arrive through the canonical owner-header chain.
//

extern float DAT_0056e6c8;
extern float DAT_0056e6cc;

RGE_Action_Transport::RGE_Action_Transport(int id, RGE_Action_Object* object)
    : RGE_Action(id, object, 1)
{
    this->action_type = 0x0C;
}

RGE_Action_Transport::RGE_Action_Transport(RGE_Action_Object* object,
                                           RGE_Task* task,
                                           float x, float y, float z)
    : RGE_Action(object, 1)
{
    this->task = task;
    this->action_type = 0x0C;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
}

// member. The original uses callee cleanup with ret 4. The FPU comparisons
// use a relocated zero constant instead of the original hardcoded address.
void RGE_Action_Transport::first_in_stack(unsigned char param_1)
{
    if (param_1 != 0 && this->target_x >= 0.0f && this->target_y >= 0.0f) {
        this->set_state(0x0B);
        return;
    }
    this->set_state(2);
}

void RGE_Action_Transport::set_state(unsigned char param_1)
{
    RGE_Action_Move_To* move_to;

    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 4:
    case 0x0B:
        if (this->task != 0) {
            move_to = new RGE_Action_Move_To(
                this->obj,
                this->target_x,
                this->target_y,
                this->target_z,
                0.3f,
                this->task->move_sprite
            );
        } else {
            move_to = new RGE_Action_Move_To(
                this->obj,
                this->target_x,
                this->target_y,
                this->target_z,
                0.3f,
                this->obj->master_obj->sprite
            );
        }

        if (move_to == 0) {
            this->set_state(2);
            return;
        }

        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;

    case 2:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    default:
        return;
    }
}

unsigned char RGE_Action_Transport::update(void)
{
    switch (this->state) {
    case 4: {
        unsigned char result = this->sub_actions->update();
        if (result > 0 && result <= 5) {
            this->set_state(2);
            return 0;
        }
        return 0;
    }

    case 0x0B: {
        unsigned char result = this->sub_actions->update();
        if (result > 0 && result <= 5) {
            this->set_state(6);
            return 0;
        }
        return 0;
    }

    case 6: {
        int zone = this->targetZone();
        if (zone != -1 &&
            this->obj->withinRangeOfZone((unsigned char)zone, 2.0f) == 0) {
            RGE_Action_Object* object = this->obj;
            RGE_Player* owner = object->owner;
            int id = object->id;
            owner->notify(id, id, 0x207, 0x266, 0, 0);
            break;
        }

        if (this->obj->objects->number_of_objects > 0) {
            if (this->next_to_drop_off_terrain() != 0) {
                zone = this->targetZone();
                if (this->obj->drop_held_objects(zone) == 0) {
                    this->obj->owner->notify(
                        this->obj->id, this->obj->id, 0x207, 0x266, 0, 0
                    );
                    break;
                }
                if (this->obj->objects->number_of_objects > 0) {
                    this->obj->owner->notify(
                        this->obj->id, this->obj->id, 0x206, 0x266, 0, 0
                    );
                }
                break;
            } else {
                RGE_Action_Object* object = this->obj;
                RGE_Player* owner = object->owner;
                RGE_Map* map = owner->world->map;
                if (this->target_x != -1.0f) {
                    if (map->get_terrain((short)this->target_x,
                                         (short)this->target_y) == 1 ||
                        map->get_terrain((short)this->target_x,
                                         (short)this->target_y) == 0x16) {
                        break;
                    }
                }
            }
            RGE_Player* owner = this->obj->owner;
            int id = this->obj->id;
            owner->notify(id, id, 0x207, 0x266, 0, 0);
        }
        break;
    }

    case 1:
        return 1;

    case 0x0D:
        // Typed casts select the virtual notify overload here.
        this->obj->notify(
            (int)this->obj->id, (int)this->obj->id, 0x1F9, (long)0x266,
            (long)0, (long)0
        );
        this->set_state(2);
        return 3;

    default:
        return 0;
    }

    this->set_state(2);
    return 0;
}

int RGE_Action_Transport::stop()
{
    this->set_state(2);
    return 1;
}

int RGE_Action_Transport::move_to(RGE_Static_Object* object,
                                  float x, float y, float z)
{
    this->target_x = x;
    this->target_y = y;
    this->target2ID = 0;
    this->target_z = z;
    this->set_state(0x0B);
    return 1;
}

int RGE_Action_Transport::work(RGE_Static_Object* object,
                               float x, float y, float z)
{
    this->target2ID = 1;

    int zone = (int)this->obj->lookupZone((int)x, (int)y);
    float distance = this->obj->distance_to_position(
        x, y, this->obj->world_z
    );

    if (zone != -1) {
        if (this->obj->withinRangeOfZone((unsigned char)zone, 2.0f) == 1 &&
            distance <= 2.0f) {
            this->target_x = x;
            this->target_y = y;
            this->target_z = z;
            this->set_state(6);
            return 1;
        }
    }

    if (x >= 0.0 && y >= 0.0) {
        this->target_x = x;
        this->target_y = y;
        this->target_z = z;
        if (object != this->obj) {
            this->set_state(0x0B);
            return 1;
        }
        this->set_state(4);
    }
    return 1;
}

int RGE_Action_Transport::next_to_drop_off_terrain(void)
{
    if (this->task != 0 && this->task->terrain_id == -1) {
        return 1;
    }

    int x1 = (int)(this->obj->world_x -
                   this->obj->master_obj->radius_x - DAT_0056e6c8);
    int y1 = (int)(this->obj->world_y -
                   this->obj->master_obj->radius_y - DAT_0056e6c8);
    int x2 = (int)(this->obj->master_obj->radius_x +
                   this->obj->world_x - DAT_0056e6cc);
    int y2 = (int)(this->obj->master_obj->radius_y +
                   this->obj->world_y - DAT_0056e6cc);

    RGE_Map* map = this->obj->owner->world->map;

    if (x1 < 0) {
        x1 = 0;
    }
    if (x2 >= map->map_width) {
        x2 = map->map_width - 1;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (y2 >= map->map_height) {
        y2 = map->map_height - 1;
    }

    int target_zone = this->targetZone();
    if (*(int*)&this->target_x != 0xBF800000) {
        target_zone = (int)this->obj->lookupZone(
            (int)this->target_x,
            (int)this->target_y
        );
    }

    for (int y = y1; y <= y2; ++y) {
        for (int x = x1; x <= x2; ++x) {
            if (target_zone == -1 ||
                this->obj->lookupZone(x, y) == target_zone) {
                if (map->get_terrain((short)x, (short)y) == 2 ||
                    map->get_terrain((short)x, (short)y) == 4) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int RGE_Action_Transport::targetZone(void)
{
    if (*(int*)&this->target_x != 0xBF800000) {
        return (int)this->obj->lookupZone(
                   (int)this->target_x,
                   (int)this->target_y
               ) & 0xFF;
    }
    return -1;
}
