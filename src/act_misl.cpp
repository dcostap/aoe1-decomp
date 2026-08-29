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

void RGE_Action_Missile::set_state(unsigned char param_1)
{
    float tx;
    float ty;
    float tz;
    float d;
    float dx;
    float dz;
    float speed;
    float target_vz;

    this->state = param_1;

    switch (param_1) {
    case 1:
        this->obj->die_die_die();
        break;

    case 3: {
        this->intercept(tx, ty, tz);

        d = tx - this->obj->world_x;
        dx = ty - this->obj->world_y;
        dz = tz - this->obj->world_z;
        target_vz = dz * dz;
        speed = (float)sqrt(d * d + dx * dx + target_vz);

        if (((RGE_Master_Missile_Object*)this->obj->master_obj)->targetting_type == 1 &&
            this->target_obj != 0 && this->target_obj->getSpeed() > 0.0) {
            float launch_speed = this->target_obj->getSpeed();

            if (this->target_obj2 != 0 &&
                (this->target_obj2->master_obj->id == 0x23 ||
                 this->target_obj2->master_obj->id == 0x24 ||
                 this->target_obj2->master_obj->id == 0x118) &&
                launch_speed > 1.0f) {
                launch_speed = 1.0f;
            }

            float target_vx = (float)cos(this->target_obj->getAngle()) * launch_speed;
            float target_vy = (float)sin(this->target_obj->getAngle()) * launch_speed;

            float target_distance =
                (float)sqrt((target_vy + dx) * (target_vy + dx) +
                            (target_vx + d) * (target_vx + d) + target_vz);

            if (speed - target_distance +
                    ((RGE_Master_Missile_Object*)this->obj->master_obj)->speed >
                ((RGE_Master_Missile_Object*)this->obj->master_obj)->speed * 0.5f) {
                float scale = speed /
                    (speed - target_distance +
                     ((RGE_Master_Missile_Object*)this->obj->master_obj)->speed);
                d = scale * target_vx + d;
                dx = scale * target_vy + dx;
                speed = (float)sqrt(dx * dx + d * d + target_vz);
            }
        }

        switch (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type) {
        case 0:
            this->velocity_x = d / speed;
            this->velocity_y = dx / speed;
            this->velocity_z = dz / speed;
            this->obj->new_angle((float)atan2(dx / speed, d / speed));
            this->timer = 0.0f;
            break;

        case 1:
            this->set_state(4);
            break;

        case 2:
            this->set_state(4);
            break;

        case 3:
            this->velocity_x = d;
            this->velocity_y = dx;
            this->velocity_z = dz;
            this->obj->new_angle((float)atan2(dx, d));
            break;
        }

        RGE_Master_Missile_Object* master =
            (RGE_Master_Missile_Object*)this->obj->master_obj;
        if (master->ballistics_ratio > 0.0) {
            float time;
            float acceleration;
            if (master->speed > 0.0f)
                time = speed / master->speed;
            else
                time = 0.0f;

            time = time * 0.5f;
            acceleration = -(speed * master->ballistics_ratio);
            acceleration = (acceleration + acceleration) / (time * time);
            this->ballistic_acceleration = acceleration;
            this->ballistic_velocity = -(time * acceleration);
            this->set_state(4);
            break;
        }

        this->ballistic_velocity = 0.0f;
        this->ballistic_acceleration = 0.0f;
        this->set_state(4);
        break;
    }
    default:
        break;
    }
}

unsigned char RGE_Action_Missile::update()
{
    float delta;
    float time;
    unsigned char hit_ground;

    {
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;

        delta = this->obj->owner->world->world_time_delta_seconds;
        time = ((RGE_Master_Animated_Object*)this->obj->master_obj)->speed * delta;

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
            goto return_one;
        case 4:
            break;
        default:
            goto return_zero;
        }

        if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type != 0) {
            if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type == 3) {
                x = this->velocity_x;
                y = this->velocity_y;
                z = this->velocity_z;
            }
        } else {
            this->timer = time + this->timer;
            x = this->velocity_x * time;
            y = this->velocity_y * time;
            z = this->velocity_z * time;
            if (this->timer >= ((RGE_Missile_Object*)this->obj)->max_range) {
                this->set_state(1);
            }
        }

        if (((RGE_Master_Missile_Object*)this->obj->master_obj)->ballistics_ratio > DAT_0056e388) {
            float acceleration = this->ballistic_acceleration * delta;
            z = (this->ballistic_velocity + acceleration * DAT_0056e380) * delta + z;
            this->ballistic_velocity = acceleration + this->ballistic_velocity;
        }

        this->obj->set_velocity(x, y, z);
        hit_ground = ((RGE_Missile_Object*)this->obj)->missile_move();
    }

    if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type == 3) {
        RGE_Combat_Object* target =
            (RGE_Combat_Object*)this->target_obj2;
        if (target != 0) {
            target->do_attack(this->target_obj, target,
                              this->obj->world_x, this->obj->world_y,
                              this->obj->world_z);
        } else {
            ((RGE_Missile_Object*)this->obj)->do_attack(
                this->target_obj, (RGE_Combat_Object*)this->obj,
                this->obj->world_x, this->obj->world_y,
                this->obj->world_z);
        }
        this->set_state(1);
    } else if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type <= 2) {
        RGE_Check_List* collision_list =
            ((RGE_Missile_Object*)this->obj)->make_object_collision_list(time);
        if (collision_list != 0) {
            RGE_Check_Node* node = collision_list->list;
            while (node != 0) {
                RGE_Combat_Object* attack_target;
                RGE_Static_Object* attack_object;
                int collision_mode =
                    ((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_hit_info;

                switch (collision_mode) {
                case 0: {
                    if (node->node == this->target_obj) {
                        attack_object = this->target_obj;
                        if (this->target_obj2 != 0) {
                            attack_target =
                                (RGE_Combat_Object*)this->target_obj2;
                        } else {
                            attack_target = (RGE_Combat_Object*)this->obj;
                        }
                        goto collision_do_attack;
                    }
                    break;
                }

                case 1: {
                    if (node->node->owner != this->obj->owner &&
                        node->node->owner->id != 0) {
                        attack_object = node->node;
                        if (this->target_obj2 == 0) {
                            ((RGE_Combat_Object*)this->obj)->do_attack(
                                attack_object,
                                (RGE_Combat_Object*)this->obj,
                                this->obj->world_x, this->obj->world_y,
                                this->obj->world_z);
                        } else {
                            ((RGE_Combat_Object*)this->target_obj2)->do_attack(
                                attack_object,
                                (RGE_Combat_Object*)this->target_obj2,
                                this->obj->world_x, this->obj->world_y,
                                this->obj->world_z);
                        }
                        goto collision_state;
                    }
                    break;
                }

                case 2: {
                    attack_target =
                        (RGE_Combat_Object*)this->target_obj2;
                    if (attack_target != 0) {
                        if (node->node == (RGE_Static_Object*)attack_target) {
                            break;
                        }
                        if (node->node->owner != this->obj->owner &&
                            node->node->owner->id != 0) {
                            attack_object = node->node;
                            goto collision_do_attack;
                        } else {
                            attack_target->area_attack(this->obj->world_x,
                                                        this->obj->world_y,
                                                        this->obj->world_z,
                                                        attack_target, 0);
                            goto collision_state;
                        }
                    } else if (node->node->owner != this->obj->owner &&
                               node->node->owner->id != 0) {
                        attack_object = node->node;
                        attack_target = (RGE_Combat_Object*)this->obj;
                        goto collision_do_attack;
                    } else {
                        attack_target = (RGE_Combat_Object*)this->obj;
                        attack_target->area_attack(this->obj->world_x,
                                                   this->obj->world_y,
                                                   this->obj->world_z,
                                                   attack_target, 0);
                        goto collision_state;
                    }
                    break;
                }
                }

                goto collision_next;

            collision_do_attack:
                attack_target->do_attack(attack_object, attack_target,
                                         this->obj->world_x, this->obj->world_y,
                                         this->obj->world_z);
            collision_state:
                this->set_state(1);

            collision_next:
                node = node->next;
            }
            delete collision_list;
        }
    }

    if (hit_ground != 0 && this->state != 1) {
        RGE_Combat_Object* target =
            (RGE_Combat_Object*)this->target_obj2;
        if (target != 0) {
            target->area_attack(this->obj->world_x, this->obj->world_y,
                                this->obj->world_z, target, 0);
        } else {
            ((RGE_Combat_Object*)this->obj)->area_attack(
                this->obj->world_x, this->obj->world_y, this->obj->world_z,
                (RGE_Combat_Object*)this->obj, 0);
        }
        this->set_state(1);
    }
return_zero:
    return 0;

return_one:
    return 1;
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
