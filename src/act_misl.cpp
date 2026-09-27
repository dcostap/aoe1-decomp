#include <math.h>

#include "../include/act_misl.h"
#include "../include/game_globals.h"
#include "../include/act_obj.h"
#include "../include/m_mi_obj.h"
#include "../include/misl_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/world.h"




RGE_Action_Missile::RGE_Action_Missile(int infile, RGE_Action_Object* obj_in)
    : RGE_Action(infile, obj_in, 1) {
    this->action_type = 8;
    rge_read(infile, &velocity_x, 4);
    rge_read(infile, &velocity_y, 4);
    rge_read(infile, &velocity_z, 4);
    rge_read(infile, &ballistic_velocity, 4);
    rge_read(infile, &ballistic_acceleration, 4);
}

RGE_Action_Missile::RGE_Action_Missile(RGE_Action_Object* obj_in, RGE_Static_Object* launcher, RGE_Static_Object* target, float x, float y, float z)
    : RGE_Action(obj_in, 1) {
    this->target_x = x;
    this->action_type = 8;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(target);
    this->set_target_obj2(launcher);
}

void RGE_Action_Missile::first_in_stack(unsigned char first_time) {
    if (first_time != 0) {
        if (this->target_obj == 0 && (this->target_x == -1.0f || this->target_y == -1.0f)) {
            this->set_state(1);
        } else {
            this->set_state(3);
        }
    } else {
        this->set_state(4);
    }
}

void RGE_Action_Missile::intercept(float& tx, float& ty, float& tz) {
    if (!this->target_obj) {
        *(long*)&tx = *(long*)&this->target_x;
        *(long*)&ty = *(long*)&this->target_y;
        *(long*)&tz = *(long*)&this->target_z;
    } else {
        *(long*)&tx = *(long*)&this->target_obj->world_x;
        *(long*)&ty = *(long*)&this->target_obj->world_y;
        tz = (this->target_obj->master_obj->radius_z * 0.5f) +
            this->target_obj->world_z;
    }
}

void RGE_Action_Missile::set_state(unsigned char new_state) {
    this->state = new_state;

    switch (new_state) {
    case 3: {
        float tx;
        float ty;
        float tz;
        float dx;
        float dy;
        float dz;
        float d;

        this->intercept(tx, ty, tz);
        dx = tx - this->obj->world_x;
        dy = ty - this->obj->world_y;
        dz = tz - this->obj->world_z;
        d = (float)sqrt(dx * dx + dy * dy + dz * dz);

        if (((RGE_Master_Missile_Object*)this->obj->master_obj) ->targetting_type == 1 && this->target_obj != 0 &&
            this->target_obj->getSpeed() > g_missile_positive_value_threshold) {
            float target_speed = this->target_obj->getSpeed();

            if (this->target_obj2 != 0 && (this->target_obj2->master_obj->id == 0x23 ||
                 this->target_obj2->master_obj->id == 0x24 || this->target_obj2->master_obj->id == 0x118) &&
                target_speed > g_missile_target_speed_normalization_limit) {
                target_speed = 1.0f;
            }

            float target_vx =
                (float)cos(this->target_obj->getAngle()) * target_speed;
            // The original stores the sine product as a float for the later correction.
            float target_vy =
                (float)(sin(this->target_obj->getAngle()) * target_speed);
            target_speed =
                d -
                (float)sqrt((dx + target_vx) * (dx + target_vx) + (dy + target_vy) * (dy + target_vy) + dz * dz) +
                ((RGE_Master_Animated_Object*)this->obj->master_obj)->speed;

            if (target_speed > ((RGE_Master_Animated_Object*)this->obj->master_obj)->speed * g_missile_half_time_factor) {
                float adjustment = d / target_speed;
                dx += target_vx * adjustment;
                dy += target_vy * adjustment;
                d = (float)sqrt(dx * dx + dy * dy + dz * dz);
            }
        }

        switch (((RGE_Master_Missile_Object*)this->obj->master_obj) ->missile_type) {
        case 0:
            this->velocity_x = dx / d;
            this->velocity_y = dy / d;
            this->velocity_z = dz / d;
            this->obj->new_angle((float)atan2(this->velocity_y, this->velocity_x));
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
            this->obj->new_angle((float)atan2(this->velocity_y, this->velocity_x));
            break;
        }

        if (((RGE_Master_Missile_Object*)this->obj->master_obj) ->ballistics_ratio > g_missile_positive_value_threshold) {
            float time;
            if (((RGE_Master_Animated_Object*)this->obj->master_obj)->speed > g_missile_minimum_speed) {
                time = d /
                       ((RGE_Master_Animated_Object*)this->obj->master_obj)
                           ->speed;
            } else {
                time = g_missile_minimum_speed;
            }

            time *= g_missile_half_time_factor;
            float acceleration =
                -(d *
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
    float vx = 0.0f;
    float vy = 0.0f;
    float vz = 0.0f;
    float t = this->obj->owner->world->world_time_delta_seconds;
    float s = ((RGE_Master_Animated_Object*)this->obj->master_obj)->speed * t;
    unsigned char hit_ground;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
    }
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
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
        if (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type == 0) {
            this->timer += s;
            vx = this->velocity_x * s;
            vy = this->velocity_y * s;
            vz = this->velocity_z * s;
            if (this->timer >= ((RGE_Missile_Object*)this->obj)->max_range) {
                this->set_state(1);
            }
        } else if (((RGE_Master_Missile_Object*)this->obj->master_obj) ->missile_type == 3) {
            vx = this->velocity_x;
            vy = this->velocity_y;
            vz = this->velocity_z;
        }

        if (((RGE_Master_Missile_Object*)this->obj->master_obj) ->ballistics_ratio > g_missile_positive_value_threshold) {
            float change = this->ballistic_acceleration * t;
            float new_velocity = this->ballistic_velocity + change;
            float average_velocity =
                this->ballistic_velocity + change * g_missile_half_time_factor;
            this->ballistic_velocity = new_velocity;
            vz += average_velocity * t;
        }

        this->obj->set_velocity(vx, vy, vz);
        hit_ground = ((RGE_Missile_Object*)this->obj)->missile_move();

        switch (((RGE_Master_Missile_Object*)this->obj->master_obj)->missile_type) {
        case 0:
        case 1:
        case 2: {
            RGE_Check_List* bounds = ((RGE_Missile_Object*)this->obj)
                                         ->make_object_collision_list(s);

            if (bounds != 0) {
                RGE_Check_Node* node = bounds->list;
                while (node != 0) {
                    RGE_Combat_Object* source;

                    switch (((RGE_Master_Missile_Object*)this->obj->master_obj) ->missile_hit_info) {
                    case 0:
                        if (node->node != this->target_obj) {
                            break;
                        }
                        if (this->target_obj2 != 0) {
                            source = (RGE_Combat_Object*)this->target_obj2;
                        } else {
                            source = (RGE_Combat_Object*)this->obj;
                        }
                        source->do_attack(node->node, source, this->obj->world_x, this->obj->world_y, this->obj->world_z);
                        this->set_state(1);
                        break;

                    case 1:
                        if (node->node->owner == this->obj->owner || node->node->owner->id == 0) {
                            break;
                        }
                        if (this->target_obj2 != 0) {
                            source = (RGE_Combat_Object*)this->target_obj2;
                        } else {
                            source = (RGE_Combat_Object*)this->obj;
                        }
                        source->do_attack(node->node, source, this->obj->world_x, this->obj->world_y, this->obj->world_z);
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

                        if (node->node->owner != this->obj->owner && node->node->owner->id != 0) {
                            source->do_attack(node->node, source, this->obj->world_x,
                                              this->obj->world_y, this->obj->world_z);
                        } else {
                            source->area_attack(this->obj->world_x, this->obj->world_y, this->obj->world_z, source, 0);
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
            source->do_attack(this->target_obj, source, this->obj->world_x, this->obj->world_y, this->obj->world_z);
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
            source->area_attack(this->obj->world_x, this->obj->world_y, this->obj->world_z, source, 0);
            this->set_state(1);
        }
    }
    return 0;
}

void RGE_Action_Missile::save(int outfile) {
    RGE_Action::save(outfile);
    rge_write(outfile, &this->velocity_x, 4);
    rge_write(outfile, &this->velocity_y, 4);
    rge_write(outfile, &this->velocity_z, 4);
    rge_write(outfile, &this->ballistic_velocity, 4);
    rge_write(outfile, &this->ballistic_acceleration, 4);
}
