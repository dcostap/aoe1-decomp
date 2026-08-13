// VA: 0045D3D0 RGE_Moving_Object::teleport(float, float, float)
// PDB: move_obj.cpp:527-587
// Attempt log:
// - Replaced the old reduced guard/pointer stub with the binary-supported
//   moving-object trail update: master trail options, tile/owner/master
//   ownership, trail-master construction, interpolated trail objects, and
//   the qualified RGE_Static_Object teleport tail.
// - Baseline candidate: natural switch dispatch for option 1/2, named world
//   deltas and trail remainder, and typed virtual make_new_obj/new_angle
//   calls.  The target's odd low-count remainder update is retained as
//   executable behavior rather than corrected.
// - Direct master-object rereads removed a long-lived saved pointer and
//   improved the first guard, but the frame became four bytes short.
// - A separate int interpolation countdown restored the proven 0x24 frame;
//   declaration-only coordinate locals did not rotate the remaining homes.
// - Positive count dispatch plus a distinct >=1 inner loop guard produced the
//   best clean emitted basin (491B, 256 differing bytes, all calls aligned).
// - <=0 outer spelling, a cached options byte, and truthy inner spelling were
//   regressive.  A redundant countdown reset improved shape but emitted 495B
//   past the boundary, so it was rolled back.  Remaining gap is local/register
//   coloring and stack-home order; no source-only exact match in this pass.
// - Nested typed option-then-tile guards preserved the observed branch order
//   but emitted the same 491B code; restored the combined natural guard.
// - Reordered case-local declarations and split the distance assignment; the
//   compiler kept the same 491B code, so the clean source is retained.
// - Reusing the short count as the loop countdown reduced the frame to 0x20;
//   a typed master local raised it to 0x28.  Both were rolled back.
// - A separate countdown reset before the inner gate recovered the oracle's
//   stack homes and 62.66% exact-block coverage, but remained 303B/495B or
//   303B/491B in nearby orderings.  The clean 256B basin remains best.

#include <math.h>

class RGE_Sprite;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Master_Moving_Object;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, unsigned char);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    void* player_object_node;
    char gap_54[0x34];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;

    virtual float teleport(float, float, float);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);

    char gap_04[0x0C];
    short id;
    char gap_12[0xA6];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    void* move_sprite;
    void* run_sprite;
    float turn_speed;
    unsigned char size_class;
    unsigned char gap_C9;
    short obj_trail_id;
    unsigned char obj_trail_options;
    unsigned char gap_CD[3];
    float obj_trail_spacing;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
};

float RGE_Moving_Object::teleport(float x, float y, float z) {
    if (((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_options != 0 &&
        this->tile != 0) {
        RGE_Master_Static_Object* trail_master =
            this->owner->master_objects[
                ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_id];

        if (trail_master != 0) {
            switch (((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_options) {
            case 1: {
                RGE_Static_Object* trail =
                    trail_master->make_new_obj(this->owner, x, y, z);
                if (trail->master_obj->id > 30) {
                    trail->new_angle(this->angle);
                }
                break;
            }

            case 2: {
                float tx;
                float ty;
                float tz;
                float dx = x - this->world_x;
                float dy = y - this->world_y;
                float dz = z - this->world_z;
                float distance =
                    (float)sqrt(dx * dx + dy * dy + dz * dz) +
                    this->trail_remainder;
                short count =
                    (short)(distance /
                            ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_spacing);

                if (count > 0) {
                    int loop_count = count;
                    float count_float = (float)loop_count;
                    dx /= count_float;
                    dy /= count_float;
                    dz /= count_float;
                    tx = this->world_x;
                    ty = this->world_y;
                    tz = this->world_z;

                    if (count >= 1) {
                        do {
                            RGE_Static_Object* trail =
                                trail_master->make_new_obj(
                                    this->owner, tx, ty, tz);
                            if (trail->master_obj->id > 30) {
                                trail->new_angle(this->angle);
                            }
                            tx += dx;
                            ty += dy;
                            tz += dz;
                            --loop_count;
                        } while (loop_count != 0);
                    }

                    this->trail_remainder =
                        distance -
                        ((RGE_Master_Moving_Object*)this->master_obj)->obj_trail_spacing *
                            count_float;
                } else {
                    this->trail_remainder = distance + this->trail_remainder;
                }
                break;
            }
            }
        }
    }

    return RGE_Static_Object::teleport(x, y, z);
}
