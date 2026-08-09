// VA: 00433F20 RGE_Command::do_command_order (880B)
// PDB: Command.cpp lines 283-420
// Attempt log:
// - Reconstructed the order packet's target lookup, bounding-box/average scan,
//   narrow-formation path, map clamping, and ordinary fallback path.
// - Moved the fallback loop index initialization before its positive-count
//   guard; this aligned the guard/epilogue topology.
// - Confirmed the fallback virtual command passes the saved target object,
//   not null; this reduced the remaining drift from 64 bytes to 8 bytes.
// - Final validated drift is limited to callee-save reload order after the two
//   virtual command calls: original reloads count before this, rebuilt this
//   before count. Calls, frame, size, CFG, and all other bytes align.

#include "../../include/game_globals.h"

struct RGE_Obj_Info {
    int id;
};

struct RGE_Command_Order {
    unsigned char command;
    unsigned char gap_01[3];
    RGE_Obj_Info target;
    unsigned char unit_num;
    unsigned char gap_09[3];
    float location_x;
    float location_y;
    RGE_Obj_Info units[1];
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x30];
    float radius_x;
    float radius_y;
};

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
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
    virtual void do_command(RGE_Static_Object* target, float x, float y, float z);
    virtual void move_to(RGE_Static_Object*, float, float, float); virtual void work();
    virtual void stop(); virtual void set_attack(RGE_Static_Object*); virtual void play_command_sound();
    virtual void play_move_sound(); virtual void new_angle(float); virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(); virtual void set_being_worked_on();
    virtual void release_being_worked_on(RGE_Static_Object*); virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj(); virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj(); virtual int explore_terrain(); virtual void unexplore_terrain();
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

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;

    void removeAllFromPathingGroup(void);
    void addToPathingGroup(int group_index);
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[4];
    void* world;
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_order(RGE_Command_Order* command);
};

void RGE_Command::do_command_order(RGE_Command_Order* command)
{
    int unit_num = command->unit_num;
    RGE_Obj_Info* units = command->units;
    RGE_Static_Object* target = this->get_obj(command->target);

    if (unit_num > 1) {
        float min_x = 10000.0f;
        float max_x = 0.0f;
        float min_y = 10000.0f;
        float max_y = 0.0f;
        float total_x = 0.0f;
        float total_y = 0.0f;

        if (unit_num > 0) {
            int remaining = unit_num;
            RGE_Obj_Info* unit = units;
            do {
                RGE_Static_Object* object = this->get_obj(*unit);
                if (object != 0) {
                    if (object->world_x < min_x) {
                        min_x = object->world_x;
                    } else if (object->world_x > max_x) {
                        max_x = object->world_x;
                    }

                    if (object->world_y < min_y) {
                        min_y = object->world_y;
                    } else if (object->world_y > max_y) {
                        max_y = object->world_y;
                    }

                    total_x += object->world_x;
                    total_y += object->world_y;
                }
                ++unit;
                --remaining;
            } while (remaining != 0);
        }

        if (max_x - min_x <= DAT_0056f4d8 &&
            max_y - min_y <= DAT_0056f4d8) {
            total_x /= (float)unit_num;
            total_y /= (float)unit_num;

            RGE_Obj_Info* unit;
            int index = 0;
            if (unit_num > 0) {
                unit = units;
                do {
                    RGE_Static_Object* object = this->get_obj(*unit);
                    if (object != 0) {
                        object->removeAllFromPathingGroup();
                        object->setWaitingToMove(1);

                        int other_index = 0;
                        RGE_Obj_Info* other_unit = units;
                        do {
                            if (other_index != index)
                                object->addToPathingGroup(other_unit->id);
                            ++other_index;
                            ++other_unit;
                        } while (other_index < unit_num);

                        float adjusted_x =
                            (object->world_x - total_x) + command->location_x;
                        float adjusted_y =
                            (object->world_y - total_y) + command->location_y;

                        if (adjusted_x < DAT_0056f4e0) {
                            adjusted_x = 1.0f;
                        } else {
                            float width = (float)object->owner->world->map->map_width;
                            if (adjusted_x >= width)
                                adjusted_x = width - DAT_0056f4e8;
                        }

                        if (adjusted_y < DAT_0056f4e0) {
                            adjusted_y = 1.0f;
                        } else {
                            float height = (float)object->owner->world->map->map_height;
                            if (adjusted_y >= height)
                                adjusted_y = height - DAT_0056f4e8;
                        }

                        if (target != 0 &&
                            (target->master_obj->radius_x > DAT_0056f4e0 ||
                             target->master_obj->radius_y > DAT_0056f4e0)) {
                            object->do_command(target, adjusted_x, adjusted_y, 0);
                        } else {
                            object->do_command(0, adjusted_x, adjusted_y, 0);
                        }
                    }
                    ++index;
                    ++unit;
                } while (index < unit_num);
            }
            return;
        }
    }

    int index = 0;
    if (unit_num > 0) {
        RGE_Obj_Info* unit = units;
        do {
            RGE_Static_Object* object = this->get_obj(*unit);
            if (object != 0) {
                object->removeAllFromPathingGroup();
                object->setWaitingToMove(1);

                int other_index = 0;
                RGE_Obj_Info* other_unit = units;
                do {
                    if (other_index != index)
                        object->addToPathingGroup(other_unit->id);
                    ++other_index;
                    ++other_unit;
                } while (other_index < unit_num);

                object->do_command(target, command->location_x,
                                   command->location_y, 0);
            }
            ++index;
            ++unit;
        } while (index < unit_num);
    }
}
