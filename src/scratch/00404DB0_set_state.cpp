// VA: 00404DB0 RGE_Action_Missile::set_state (805 bytes)
// ACT_misl.cpp, lines 91-200
//
// Initial clean reconstruction.  The action owns the five float values at
// +0x40, while its object/master pair is the period action-object surface.
//
// Attempt log:
// - baseline: replaced the stub with typed missile/master/object ownership;
//   recovered all 12 calls, but the virtual surface was initially two slots high.
// - switched state dispatch to a natural switch and changed ballistics to a
//   positive guard; size/frame and call-site topology then matched.
// - corrected guided getters to target_obj (+0x10), not the missile obj (+0x08).
// - reversed the distance comparison for VC5's fcompp direction; declaration,
//   expression, and local-order probes did not close the remaining FPU hunk.
// - two focused variant labs (guided block and ballistic tail) found no exact
//   variant; their codegen-only winners were not retained as source.
// - final source keeps canonical vector ownership: cos contributes x+d and
//   sin contributes y+dx.  Validated best source remains in scratch: drift is
//   localized to VC5 temporary homes/FPU scheduling and the ballistic spill.
// - reordered the guided-distance terms to evaluate x+d before y+dx, matching
//   the original x87 sequence; this worsened positional diff 436 -> 448, so
//   restored the clean source.

#include <math.h>

typedef unsigned char uchar;

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Missile_Object;
class RGE_Action_List;
class RGE_Task;
class RGE_Sprite;
class RGE_Master_Action_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    uchar master_type;
    uchar gap_05[0x0B];
    short id;                         // +0x10
    uchar gap_12[0x26];
    float radius_z;                   // +0x38
    uchar gap_3C[0x7C];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                      // +0xB8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    uchar gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    uchar gap_D8[0x24];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    uchar gap_FC[0x4C];
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    uchar missile_type;               // +0x148
    uchar targetting_type;            // +0x149
    uchar gap_14A[6];
    float ballistics_ratio;           // +0x150
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void die_die_die();       // +0x6C
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void new_angle(float);    // +0xB4
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual float getSpeed();         // +0xF4
    virtual float getAngle();         // +0xF8

    long id;                          // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    uchar gap_0C[0x2C];               // +0x0C..+0x37
    float world_x;                    // +0x38
    float world_y;                    // +0x3C
    float world_z;                    // +0x40
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(uchar);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual uchar attack_response(RGE_Static_Object*);
    virtual uchar relation_response(long, uchar);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(uchar);

    short action_type;                // +0x04
    uchar gap_06[2];
    RGE_Action_Object* obj;           // +0x08
    uchar state;                      // +0x0C
    uchar gap_0D[3];
    RGE_Static_Object* target_obj;    // +0x10
    RGE_Static_Object* target_obj2;   // +0x14
    int targetID;                     // +0x18
    int target2ID;                    // +0x1C
    float target_x;                   // +0x20
    float target_y;                   // +0x24
    float target_z;                   // +0x28
    float timer;                      // +0x2C
    RGE_Task* task;                   // +0x30
    RGE_Action_List* sub_actions;     // +0x34
    RGE_Sprite* sprite;               // +0x38
    uchar subActionValue;             // +0x3C
    uchar gap_3D[3];
};

class RGE_Action_Missile : public RGE_Action {
public:
    virtual void set_state(uchar);

    float velocity_x;                 // +0x40
    float velocity_y;                 // +0x44
    float velocity_z;                 // +0x48
    float ballistic_velocity;         // +0x4C
    float ballistic_acceleration;     // +0x50

    void intercept(float&, float&, float&);
};

void RGE_Action_Missile::set_state(uchar param_1)
{
    float tx;
    float ty;
    float tz;
    float d;
    float dx;
    float dz;
    float speed;
    float target_vx;
    float target_vy;
    float target_vz;
    float target_distance;

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

            target_vx = (float)cos(this->target_obj->getAngle()) * launch_speed;
            target_vy = (float)sin(this->target_obj->getAngle()) * launch_speed;

            target_distance =
                (speed - (float)sqrt((target_vy + dx) * (target_vy + dx) +
                                     (target_vx + d) * (target_vx + d) + target_vz)) +
                ((RGE_Master_Missile_Object*)this->obj->master_obj)->speed;

            if (target_distance >
                ((RGE_Master_Missile_Object*)this->obj->master_obj)->speed * 0.5f) {
                float scale = speed / target_distance;
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
        float time;
        float acceleration;

        if (master->ballistics_ratio > 0.0) {
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
