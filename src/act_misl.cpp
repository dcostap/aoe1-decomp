#include <math.h>

#include "../include/act_misl.h"
#include "../include/act_obj.h"
#include "../include/m_mi_obj.h"
#include "../include/misl_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/world.h"

extern float DAT_0056e380;
extern double DAT_0056e388;
extern float DAT_0056e390;
extern float DAT_0056e394;



RGE_Action_Missile::RGE_Action_Missile(int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1)
{
    this->action_type = 8;
    rge_read(file, &velocity_x, 4);
    rge_read(file, &velocity_y, 4);
    rge_read(file, &velocity_z, 4);
    rge_read(file, &ballistic_velocity, 4);
    rge_read(file, &ballistic_acceleration, 4);
}

RGE_Action_Missile::RGE_Action_Missile(
    RGE_Action_Object* object, RGE_Static_Object* target,
    RGE_Static_Object* target2, float x, float y, float z)
    : RGE_Action(object, 1)
{
    this->target_x = x;
    this->action_type = 8;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(target2);
    this->set_target_obj2(target);
}

void RGE_Action_Missile::first_in_stack(unsigned char value)
{
    if (value != 0) {
        if (this->target_obj == 0 &&
            (*(int*)&this->target_x == 0xBF800000 ||
             *(int*)&this->target_y == 0xBF800000)) {
            this->set_state(1);
        } else {
            this->set_state(3);
        }
    } else {
        this->set_state(4);
    }
}

void RGE_Action_Missile::intercept(float& x, float& y, float& z)
{
    if (!this->target_obj) {
        *(long*)&x = *(long*)&this->target_x;
        *(long*)&y = *(long*)&this->target_y;
        *(long*)&z = *(long*)&this->target_z;
    } else {
        *(long*)&x = *(long*)&this->target_obj->world_x;
        *(long*)&y = *(long*)&this->target_obj->world_y;
        z = (this->target_obj->master_obj->radius_z * 0.5f) +
            this->target_obj->world_z;
    }
}

void RGE_Action_Missile::set_state(unsigned char value)
{
    this->state = value;

    switch (value) {
    case 3: {
        float target_x;
        float target_y;
        float target_z;
        float dx;
        float dy;
        float dz;
        float distance;

        this->intercept(target_x, target_y, target_z);
        dx = target_x - this->obj->world_x;
        dy = target_y - this->obj->world_y;
        dz = target_z - this->obj->world_z;
        distance = (float)sqrt(dx * dx + dy * dy + dz * dz);

        if (((RGE_Master_Missile_Object*)this->obj->master_obj)
                    ->targetting_type == 1 &&
            this->target_obj != 0 &&
            this->target_obj->getSpeed() > DAT_0056e388) {
            float target_speed = this->target_obj->getSpeed();

            if (this->target_obj2 != 0 &&
                (this->target_obj2->master_obj->id == 0x23 ||
                 this->target_obj2->master_obj->id == 0x24 ||
                 this->target_obj2->master_obj->id == 0x118) &&
                target_speed > DAT_0056e390) {
                target_speed = 1.0f;
            }

            float target_velocity_x =
                (float)cos(this->target_obj->getAngle()) * target_speed;
            float target_velocity_y =
                (float)sin(this->target_obj->getAngle()) * target_speed;
            target_speed =
                distance -
                (float)sqrt((dx + target_velocity_x) *
                                (dx + target_velocity_x) +
                            (dy + target_velocity_y) *
                                (dy + target_velocity_y) +
                            dz * dz) +
                ((RGE_Master_Animated_Object*)this->obj->master_obj)->speed;

            if (target_speed >
                ((RGE_Master_Animated_Object*)this->obj->master_obj)->speed *
                    DAT_0056e380) {
                float adjustment = distance / target_speed;
                dx += target_velocity_x * adjustment;
                dy += target_velocity_y * adjustment;
                distance = (float)sqrt(dx * dx + dy * dy + dz * dz);
            }
        }

        switch (((RGE_Master_Missile_Object*)this->obj->master_obj)
                    ->missile_type) {
        case 0:
            this->velocity_x = dx / distance;
            this->velocity_y = dy / distance;
            this->velocity_z = dz / distance;
            this->obj->new_angle(
                (float)atan2(this->velocity_y, this->velocity_x));
            this->timer = 0.0f;
            break;

        case 1:
            this->set_state(4);
            break;

        case 2:
            this->set_state(4);
            break;

        case 3:
            this->velocity_x = dx;
            this->velocity_y = dy;
            this->velocity_z = dz;
            this->obj->new_angle(
                (float)atan2(this->velocity_y, this->velocity_x));
            break;
        }

        if (((RGE_Master_Missile_Object*)this->obj->master_obj)
                ->ballistics_ratio > DAT_0056e388) {
            float time;
            if (((RGE_Master_Animated_Object*)this->obj->master_obj)->speed >
                DAT_0056e394) {
                time = distance /
                       ((RGE_Master_Animated_Object*)this->obj->master_obj)
                           ->speed;
            } else {
                time = DAT_0056e394;
            }

            time *= DAT_0056e380;
            float acceleration =
                -(distance *
                  ((RGE_Master_Missile_Object*)this->obj->master_obj)
                      ->ballistics_ratio);
            this->ballistic_acceleration =
                (acceleration + acceleration) / (time * time);
            this->ballistic_velocity =
                -(time * this->ballistic_acceleration);
        } else {
            this->ballistic_velocity = 0.0f;
            this->ballistic_acceleration = 0.0f;
        }
        this->set_state(4);
        break;
    }

    case 1:
        this->obj->die_die_die();
        break;
    }
}

unsigned char RGE_Action_Missile::update() {
    float velocity_x = 0.0f;
    float velocity_y = 0.0f;
    float velocity_z = 0.0f;
    float time = this->obj->owner->world->world_time_delta_seconds;
    float distance =
        ((RGE_Master_Animated_Object*)this->obj->master_obj)->speed * time;
    unsigned char hit_ground;

    if (this->targetID != -1 &&
        this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
    }
    if (this->target2ID != -1 &&
        this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->is_dying()) {
        this->set_target_obj(0);
    }
    if (this->target_obj2 != 0 && this->target_obj2->is_dying()) {
        this->set_target_obj2(0);
    }

    switch (this->state) {
    case 1:
        return 1;
    case 4:
        if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type ==
            0) {
            this->timer += distance;
            velocity_x = this->velocity_x * distance;
            velocity_y = this->velocity_y * distance;
            velocity_z = this->velocity_z * distance;
            if (this->timer >= ((RGE_Missile_Object*)this->obj)->max_range) {
                this->set_state(1);
            }
        } else if (((RGE_Master_Missile_Object*)this->obj->master_obj)
                       ->missile_type == 3) {
            velocity_x = this->velocity_x;
            velocity_y = this->velocity_y;
            velocity_z = this->velocity_z;
        }

        if (((RGE_Master_Missile_Object*)this->obj->master_obj)
                ->ballistics_ratio > DAT_0056e388) {
            float change = this->ballistic_acceleration * time;
            float new_velocity = this->ballistic_velocity + change;
            float average_velocity =
                this->ballistic_velocity + change * DAT_0056e380;
            this->ballistic_velocity = new_velocity;
            velocity_z += average_velocity * time;
        }

        this->obj->set_velocity(velocity_x, velocity_y, velocity_z);
        hit_ground = ((RGE_Missile_Object*)this->obj)->missile_move();

        switch (
            ((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type) {
        case 0:
        case 1:
        case 2: {
            RGE_Check_List* bounds = ((RGE_Missile_Object*)this->obj)
                                         ->make_object_collision_list(distance);

            if (bounds != 0) {
                RGE_Check_Node* node = bounds->list;
                while (node != 0) {
                    RGE_Combat_Object* source;

                    switch (((RGE_Master_Missile_Object*)this->obj->master_obj)
                                ->missile_hit_info) {
                    case 0:
                        if (node->node != this->target_obj) {
                            break;
                        }
                        if (this->target_obj2 != 0) {
                            source = (RGE_Combat_Object*)this->target_obj2;
                        } else {
                            source = (RGE_Combat_Object*)this->obj;
                        }
                        source->do_attack(
                            node->node, source, this->obj->world_x,
                            this->obj->world_y, this->obj->world_z);
                        this->set_state(1);
                        break;

                    case 1:
                        if (node->node->owner == this->obj->owner ||
                            node->node->owner->id == 0) {
                            break;
                        }
                        if (this->target_obj2 != 0) {
                            source = (RGE_Combat_Object*)this->target_obj2;
                        } else {
                            source = (RGE_Combat_Object*)this->obj;
                        }
                        source->do_attack(
                            node->node, source, this->obj->world_x,
                            this->obj->world_y, this->obj->world_z);
                        this->set_state(1);
                        break;

                    case 2:
                        if (this->target_obj2 != 0) {
                            if (node->node == this->target_obj2) {
                                break;
                            }
                            source = (RGE_Combat_Object*)this->target_obj2;
                        } else {
                            source = (RGE_Combat_Object*)this->obj;
                        }

                        if (node->node->owner != this->obj->owner &&
                            node->node->owner->id != 0) {
                            source->do_attack(
                                node->node, source, this->obj->world_x,
                                this->obj->world_y, this->obj->world_z);
                        } else {
                            source->area_attack(this->obj->world_x,
                                                this->obj->world_y,
                                                this->obj->world_z, source, 0);
                        }
                        this->set_state(1);
                        break;
                    }
                    node = node->next;
                }
                delete bounds;
            }
            break;
        }

        case 3: {
            RGE_Combat_Object* source;
            if (this->target_obj2 != 0) {
                source = (RGE_Combat_Object*)this->target_obj2;
            } else {
                source = (RGE_Combat_Object*)this->obj;
            }
            source->do_attack(this->target_obj, source, this->obj->world_x,
                              this->obj->world_y, this->obj->world_z);
            this->set_state(1);
            break;
        }
        }

        if (hit_ground != 0 && this->state != 1) {
            RGE_Combat_Object* source;
            if (this->target_obj2 != 0) {
                source = (RGE_Combat_Object*)this->target_obj2;
            } else {
                source = (RGE_Combat_Object*)this->obj;
            }
            source->area_attack(this->obj->world_x, this->obj->world_y,
                                this->obj->world_z, source, 0);
            this->set_state(1);
        }
    }
    return 0;
}

void RGE_Action_Missile::save(int handle)
{
    RGE_Action::save(handle);
    rge_write(handle, &this->velocity_x, 4);
    rge_write(handle, &this->velocity_y, 4);
    rge_write(handle, &this->velocity_z, 4);
    rge_write(handle, &this->ballistic_velocity, 4);
    rge_write(handle, &this->ballistic_acceleration, 4);
}
