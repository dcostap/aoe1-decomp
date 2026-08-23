// VA: 004C6270 RGE_Static_Object::drop_held_objects
// Source: stat_obj.cpp lines 3818-3875
// Attempt log:
// - the binary-backed local frame is 0xB4 with four contiguous float arrays,
//   an address-taken x/y pair, next/temp nodes, and a byte count; typed
//   DropLocals preserves those proven offsets and the complete four-call set;
// - self-alias removal was codegen-neutral; separate scalar/array locals
//   regressed the frame to 0xB8 and were rolled back;
// - changing the retry loop to while removed an emitted duplicate
//   find_drop_location call, and moving next-node reload into the retry loop
//   improved the diagnostic diff, but broad this/index/register and CFG drift
//   remains;
// - prior validated candidate: 350 rebuilt bytes versus 387 original,
//   64.06% instruction-shape similarity, four ordered calls. Left in scratch
//   after the bounded pass; next lead is recovering natural source lifetimes
//   that reproduce the proven overlapping stack homes without opaque padding.
// - current pass: direct node-object rereads at find_drop_location with a
//   success-block held alias improved the candidate to 336 differing bytes,
//   65.62% shape, 0xB4 frame, and four ordered calls; this remains natural
//   typed source but still selects EBP for this and EDI for the retry index.
// - removing register from the index and changing the outer traversal to a
//   pretested while were codegen duplicates; retain the success-block alias
//   candidate as the best source reconstruction for this pause.
// - moving next-node capture outside the retry loop followed the 004C62C4 /
//   004C62E0 split but worsened the rebuilt size and resync diff; rolled back.
// - moving list-head capture between world_x and world_y setup also worsened
//   the initial schedule; rolled back.
// - scoped running radius pointers produced a 0xB8 frame and broad drift;
//   rolled back because the original pointer-like EBP/EDI evidence is not a
//   natural fit for this aggregate source.
// - moving next after the four float arrays reproduced the original array
//   stack homes, raised shape similarity to 71.09%, and reduced the strict
//   diff to 331 bytes with the 0xB4 frame; keep this typed layout candidate.
// - reordering radius_x before world_y and the failure-copy radius stores
//   preserved that best 331-byte result; register and CFG drift remain.
// - current assigned pass: baseline rebuilt 365 bytes versus 387 original,
//   strict diff 331 bytes, 71.09% shape, 0xB4 frame, and four aligned calls;
//   the original saves EBX/ESI while this source saves EBP/EDI. Explicit
//   outer do/while structure, register index hints, canonical full fields,
//   and an explicit continuation were codegen duplicates. Declaring count
//   before i worsened the diff to 338 bytes. A distinct retry index reduced
//   the strict diff to 323 bytes but produced a 390-byte, 69.53% shape
//   variant with LEA instead of the original DEC, so it was rejected.
//   Reordering success radius stores kept the 331-byte strict diff but made
//   the diagnostic resynchronization worse; the baseline remains authoritative.
// - revisit: canonical typed list/node member names were codegen-neutral. A
//   natural outer traversal that captures next once before the retry loop
//   followed the original 004C62C4/004C62E0 split and reduced strict diff to
//   326 bytes, but made size and resynchronization worse; the pinned baseline
//   remains authoritative. Block-local next shifted the proven array homes.
//   Typed running radius pointers raised the frame to 0xB8 and were rejected.
// - revisit: an outer next capture with an inner while and radius-before-
//   coordinate success updates reduced the strict diff to 326 bytes and raised
//   shape to 71.32%, but shortened the body to 355 bytes and worsened resync;
//   rolled back. A separate next local reduced the diff to 322 bytes but fell
//   to 60.16% shape. Moving next before the arrays kept 322 bytes but only
//   66.41% shape. Both natural layout probes were rolled back.
// - fresh pass: canonical stat_obj master/object declarations and the proven
//   exit_obj +0xD4 slot were restored. Separate scalar locals for temp, y,
//   next, and the four arrays reached a 304-byte diff, 67.97% shape, and an
//   exact 0xB4 frame. Reusing the proven drop_y[0] stack home for the next
//   node restored EBX/ESI, 82.03% shape, 81.65% resync similarity, and a
//   277-byte diff; the frame is 0xB0 and the source uses a narrow pointer
//   overlay. Natural next-node locals reached 285 bytes, 77.34% shape, and
//   0xB4, but kept EBP for this. Running cursors, nested do loops, and retry
//   index variants were rejected for frame, call, or shape drift. Final
//   validation: 384 rebuilt bytes versus 387, four ordered calls, mismatch.
// - resumed exact-finish pass: the distinct typed x/y/next source is the
//   clean natural baseline at 386 bytes, 0xB4, and four ordered calls, with
//   a 285-byte mismatch. Real array aggregates, a typed drop_y/next union,
//   running radius cursors, goto retry labels, declaration reorders, and a
//   register-qualified self alias were tested and rejected. The union
//   reproduced the prior 384-byte, 277-byte diagnostic basin but still used
//   an unsupported local overlap. No exact result was found; keep the
//   separate typed source and do not claim the pointer-overlap candidate.

class RGE_Static_Object;
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(void*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(void*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    char gap_04[0x2c];
    float radius_x;
    float radius_y;
};
class RGE_Object_Node { public: RGE_Static_Object* object; RGE_Object_Node* next; };
class RGE_Object_List { public: virtual ~RGE_Object_List(); RGE_Object_Node* first; };

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, void*, float, float, float);
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
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(void*);
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
    virtual void damage(int, void*, float, void*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, void*, RGE_Static_Object*);
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
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(void*, unsigned char, int);
    virtual void unexplore_terrain(void*, unsigned char, int);
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);

    long id;
    RGE_Master_Static_Object* master_obj;
    void* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
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
    void set_location(float x, float y, float z);
    unsigned char find_drop_location(int mode, float* x, float* y, RGE_Master_Static_Object* master, RGE_Static_Object* obj, float drop_x, float drop_y, float radius_x, float radius_y);
    unsigned char drop_held_objects(int mode);
};

unsigned char RGE_Static_Object::drop_held_objects(int mode)
{
    int i = 1;
    unsigned char count = 0;
    RGE_Object_Node* temp;
    float x;
    float y;
    float drop_y[10];
    float radius_x[10];
    float drop_x[10];
    float radius_y[10];
    drop_x[1] = this->world_x;
    drop_y[1] = this->world_y;
    radius_x[1] = this->master_obj->radius_x + this->master_obj->radius_x;
    radius_y[1] = this->master_obj->radius_y + this->master_obj->radius_y;
    temp = this->objects->first;

    while (temp != 0) {
        RGE_Object_Node* next;
        next = temp->next;
        while (i > 0) {
                    if (this->find_drop_location(mode, &x, &y, temp->object->master_obj, temp->object, drop_x[1], drop_y[1], radius_x[1], radius_y[1])) {
                        RGE_Static_Object* held = temp->object;
                        held->set_location(this->world_x, this->world_y, this->world_z);
                        held->exit_obj();
                        held->teleport(x, y, this->world_z);
                        ++count;
                        if (i < 9) {
                            RGE_Master_Static_Object* master = held->master_obj;
                            int index = i++;
                            drop_x[index + 1] = x;
                            drop_y[index + 1] = y;
                            radius_x[index + 1] = master->radius_x + master->radius_x;
                            radius_y[index + 1] = master->radius_y + master->radius_y;
                        }
                        break;
                    }
                    --i;
                    if (i <= 0) break;
                    drop_x[i] = drop_x[i + 1];
                    drop_y[i] = drop_y[i + 1];
                    radius_y[i] = radius_y[i + 1];
                    radius_x[i] = radius_x[i + 1];
        }
        temp = next;
    }
    return count;
}
