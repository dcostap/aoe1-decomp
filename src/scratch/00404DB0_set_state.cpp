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
// - block-scoped target_distance to model the packet's guided stack reuse;
//   emitted code was unchanged at diff 436, so restored the top-level local.
// - revisit: 33 evidence-led probes covered declaration scope/order, guided
//   expression grouping, typed master/target aliases, update order, and the
//   ballistic tail.  The useful change makes target_distance hold only the
//   guided square-root result, then uses speed - target_distance + master speed
//   in both the guard and scale.  This reduces positional drift to 210 bytes
//   while preserving the 0x28 frame, all 12 calls, and exact case islands.
// - direct repeated-sqrt, split-assignment, reversed-term, branch-local, and
//   threshold-local variants did not improve this result.  Keep the natural
//   float source; do not retain metric-only operand reordering.
// Review blocker: the original keeps the intercept square root in x87 extended
// precision for the lead-correction guard. The rebuild spills and reloads it
// as float first, which can change a threshold result. The ballistic tail has
// the reverse problem: the original rounds acceleration through a float stack
// home before both outputs, while the rebuild uses its extended value.
//
// Context audit: the PDB owner and all original line bands identify ACT_misl.cpp,
// not ACT_make.cpp.  ACT_make.cpp set_state is 00404A70 and is already exact.
// This target was kept in its authentic ACT_misl.cpp owner context.
// Current claim probes: a post-distance denominator local worsened 210 to 424;
// function-scope and declaration-order changes, an uncast guided sqrt, constants,
// acceleration mutation, and PDB switch-case order did not change the 210 basin.
// A double guided-distance local changed the frame to 0x2C and worsened 210 to 241.
// All variants were restored to the pinned 210-byte clean source.
// Captain pass: the authentic-TU baseline remains 805B, frame 0x28, 12 ordered
// calls, and 210 positional diff bytes. H1/H2/H3 tested inline, grouped, and
// denominator-local guided forms; results were 434/451/436 diff bytes.
// H4/H7 tested vector declaration scope and order; both reproduced 210 bytes.
// H5/H10 tested dead launch-speed-home reuse; both reproduced the 436-byte
// denominator basin. H8/H9/H12 tested acceleration scope, rounding, and
// initialization; all reproduced 210 bytes. H11 reversed ballistic stores and
// worsened the result to 212 bytes. The clean source is restored.
//
// Authentic-TU probe: src/act_misl_tu.cpp includes the PDB-ordered ACT_misl.cpp
// owners through include/act_misl_context.h.  The module flag evidence is
// /nologo /c /O2 /Oy /GX: the two constructors at 00404BB0 and 00404C90 carry
// the original EH setup. Fresh wrapper extraction kept exact sibling anchors
// 00404BB0, 00404C90, 00404D10, 00404D50, and 004054B0 after relocation
// masking. The shared wrapper keeps the 0x28 frame and 12 ordered calls here,
// but this body still has an 0x330-byte section with a 0x325-byte original
// boundary and a larger positional drift than the standalone clean source. It
// did not resolve the switch/register hunk. The x87 differences below are also
// behavior-relevant, so this owner stays scratch and unregistered. Do not
// replace this target owner until a source-level fix preserves the calls,
// state publication, size, CFG, x87 precision, and fault order.

#include <math.h>

#ifndef ACT_MISL_SHARED_CONTEXT

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
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual float teleport(float, float, float);
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state();
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();       // +0x6C
    virtual void damage();
    virtual void calculateDamage();
    virtual void rotate();
    virtual uchar can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual int heal();
    virtual uchar heal_float();
    virtual int canRepair();
    virtual void notify_of_relation();
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);    // +0xB4
    virtual void spawn_death_obj();
    virtual void get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual uchar is_moving();
    virtual void get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual void explore_terrain();
    virtual void unexplore_terrain();
    virtual void get_los_table();
    virtual void inAttackRange();
    virtual void underAttack();
    virtual void setUnderAttack();
    virtual float calc_attack_modifier();
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
#endif

void RGE_Action_Missile::set_state(uchar param_1)
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
