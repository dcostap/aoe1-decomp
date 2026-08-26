// VA: 00434320 RGE_Command::do_command_work (216B)
// Command.cpp lines 466-494.
//
// Initial reconstruction: the order packet owns a target id followed by a
// variable-length unit-id array.  Each resolved unit is removed from its old
// pathing group, marked waiting, rebuilt into the same group except for itself,
// and sent the work command.
//
// Attempt log:
// - The inherited stub was only a placeholder and omitted the command loop.
// - Restored the canonical packet layout, target/unit lookups, pathing calls,
//   and work virtual surface; this reached the correct frame, size, and call set.
// - Replaced the nested for loop with the binary-supported do/while topology;
//   this removed the extra inner pretest and aligned the loop body.
// - Declared count/base before the target lookup.  This preserves VC5's original
//   load/save order and produces an exact 216-byte match under default.rsp.

#ifndef COMMAND_TU_CONTEXT
struct RGE_Obj_Info {
    int id;
};

class RGE_Player;

class RGE_Command_Order {
public:
    unsigned char command;
    unsigned char gap_01[3];
    RGE_Obj_Info target;
    unsigned char unit_num;
    unsigned char gap_09[3];
    float location_x;
    float location_y;
    RGE_Obj_Info units[1];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game(); virtual void draw(); virtual void shadow_draw();
    virtual void normal_draw(); virtual void draw_front_frame(); virtual void draw_back_frame();
    virtual void draw_frame(); virtual unsigned char update(); virtual void check_damage_sprites();
    virtual void rehook(); virtual void save(int); virtual float teleport(float, float, float);
    virtual void new_sprite(void*); virtual void add_overlay_sprite(void*, unsigned char);
    virtual void remove_overlay_sprite(void*); virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char); virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char); virtual void transform(void*);
    virtual void copy_obj(void*); virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(); virtual void create_doppleganger_when_dying();
    virtual void destroy_obj(); virtual void die_die_die(); virtual void damage();
    virtual float calculateDamage(); virtual void rotate(long); virtual unsigned char can_attack();
    virtual void set_attribute(short, float); virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int); virtual unsigned char heal(float); virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object* target, float x, float y, float z);
    virtual void stop(); virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound(); virtual void play_move_sound(); virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj(); virtual void* get_command_master();
    virtual void set_being_worked_on(); virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving(); virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*); virtual void exit_obj();
    virtual int explore_terrain(); virtual void unexplore_terrain();
    virtual void* get_los_table(); virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack(); virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*); virtual float getSpeed();
    virtual float getAngle(); virtual float maximumSpeed(); virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*); virtual float damageCapability();
    virtual float weaponRange(); virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int); virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID(); virtual float currentTargetX(); virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char waiting);

    void removeAllFromPathingGroup();
    void addToPathingGroup(int group_index);
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[4];
    void* world;
protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_work(RGE_Command_Order* order);
};
#endif

void RGE_Command::do_command_work(RGE_Command_Order* order)
{
    int unit_num = order->unit_num;
    RGE_Obj_Info* units = order->units;
    RGE_Static_Object* target = this->get_obj(order->target);
    int index = 0;

    if (unit_num > 0) {
        RGE_Obj_Info* unit = units;
        do {
            RGE_Static_Object* obj = this->get_obj(*unit);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->setWaitingToMove(1);
                int i = 0;
                do {
                    if (i != index)
                        obj->addToPathingGroup(units[i].id);
                    ++i;
                } while (i < unit_num);
                obj->work(target, order->location_x, order->location_y, 0);
            }
            ++index;
            ++unit;
        } while (index < unit_num);
    }
}
