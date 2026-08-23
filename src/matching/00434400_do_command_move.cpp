// 00434400 do_command_move (Command.cpp)
// The packet, object, player, and map surfaces follow the same Command.cpp
// donor as do_command_order and do_command_work.
// BINARY NOTE: The packet count is one byte. Target and object IDs are four
// bytes. The executable reads each field at its packet offset.
// BINARY NOTE: The executable rereads target master fields for move and AI
// calls. This source does not cache these fields or the unit-AI result.
// BINARY NOTE: In-place total division preserves the original x87 stores.
// Both outer indices initialize before their positive-count guards.
// The main-index walkback caused 26 changed bytes in one scheduling span.
// The fallback-index walkback reduced the body by four bytes.
// Typed packet copies and cursor aliases were incidental. Direct packet
// traversal remains exact and gives the smallest natural source.
// BINARY NOTE: The PDB owner is a protected RGE_Command method. The packet
// type is RGE_Command_Order, so the rebuilt qualified symbol uses that owner.
// CONTEXT NOTE: No registered grouped owner includes this VA. The available
// target-only and one-prior context objects emit the same target bytes.
// EXACT CANDIDATE: The checker reports MATCH and 0.0000% with default flags.

#include "../../include/game_globals.h"

struct RGE_Obj_Info { int id; };
class UnitAIModule { public: void setCurrentOrder(int); void setCurrentAction(int); void setCurrentTarget(int,int,float,float,float); };
class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short object_group;
    char gap_16[0x1a];
    float radius_x;
    float radius_y;
};
class RGE_Map {
public:
    char gap_00[8];
    int width;
    int height;
};
class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};
class RGE_Player {
public:
    char gap_00[0x3c];
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
    long id; RGE_Master_Static_Object* master; RGE_Player* owner; char pad10[0x28]; float world_x; float world_y;
    void removeAllFromPathingGroup(); void addToPathingGroup(int); UnitAIModule* unitAI();
};
struct RGE_Command_Order {
    unsigned char command;
    unsigned char gap_01[3];
    RGE_Obj_Info target;
    unsigned char unit_num;
    unsigned char gap_09[3];
    float location_x;
    float location_y;
    RGE_Obj_Info ids[1];
};
class RGE_Command {
public:
    virtual ~RGE_Command();
    char pad4[4];
    void* world;
protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info);
    void do_command_move(RGE_Command_Order*);
};

void RGE_Command::do_command_move(RGE_Command_Order* order) {
    int n = order->unit_num;
    RGE_Obj_Info* ids = order->ids;
    RGE_Static_Object* target = this->get_obj(order->target);
    if (n > 1) {
        float minx = 10000.0f;
        float maxx = 0.0f;
        float miny = 10000.0f;
        float maxy = 0.0f;
        float totalx = 0.0f;
        float totaly = 0.0f;
        if (n > 0) {
            int i = n;
            RGE_Obj_Info* p = ids;
            do {
                RGE_Static_Object* obj = this->get_obj(*p);
                if (obj) {
                    if (obj->world_x < minx) minx = obj->world_x; else if (obj->world_x > maxx) maxx = obj->world_x;
                    if (obj->world_y < miny) miny = obj->world_y; else if (obj->world_y > maxy) maxy = obj->world_y;
                    totalx += obj->world_x;
                    totaly += obj->world_y;
                }
                ++p;
            } while (--i);
        }
        if (maxx - minx > DAT_0056f4d8 || maxy - miny > DAT_0056f4d8) goto simple;
        totalx /= (float)n;
        totaly /= (float)n;
        int idx = 0;
        if (n > 0) {
            RGE_Obj_Info* p = ids;
            do {
            RGE_Static_Object* obj = this->get_obj(*p);
            if (obj) {
                obj->removeAllFromPathingGroup(); obj->setWaitingToMove(1);
                int j = 0; RGE_Obj_Info* q = ids;
                do { if (j != idx) obj->addToPathingGroup(q->id); ++j; ++q; } while (j < n);
                float nx = (obj->world_x - totalx) + order->location_x;
                float ny = (obj->world_y - totaly) + order->location_y;
                if (nx < DAT_0056f4e0) nx = 1.0f;
                else {
                    float width = (float)obj->owner->world->map->width;
                    if (nx >= width) nx = width - DAT_0056f4e8;
                }
                if (ny < DAT_0056f4e0) ny = 1.0f;
                else {
                    float height = (float)obj->owner->world->map->height;
                    if (ny >= height) ny = height - DAT_0056f4e8;
                }
                if (target != 0 &&
                    (target->master->radius_x > DAT_0056f4e0 ||
                     target->master->radius_y > DAT_0056f4e0))
                obj->move_to(target, nx, ny, 0);
                else
                obj->move_to(0, nx, ny, 0);
                UnitAIModule* ai = obj->unitAI();
                if (ai) {
                    obj->unitAI()->setCurrentOrder(0x2c6); obj->unitAI()->setCurrentAction(0x262);
                    if (target != 0 &&
                        (target->master->radius_x > DAT_0056f4e0 ||
                         target->master->radius_y > DAT_0056f4e0))
                        obj->unitAI()->setCurrentTarget(target->id, target->master->object_group, nx, ny, 0.0f);
                    else obj->unitAI()->setCurrentTarget(-1, -1, nx, ny, 0.0f);
                }
            }
                ++idx; ++p;
            } while (idx < n);
        }
        return;
    }
simple:
    int idx = 0;
    if (n > 0) {
        RGE_Obj_Info* p = ids;
        do {
            RGE_Static_Object* obj = this->get_obj(*p);
            if (obj) {
                obj->removeAllFromPathingGroup(); obj->setWaitingToMove(1);
                int j = 0; RGE_Obj_Info* q = ids;
                do { if (j != idx) obj->addToPathingGroup(q->id); ++j; ++q; } while (j < n);
                obj->move_to(target, order->location_x, order->location_y, 0);
                UnitAIModule* ai = obj->unitAI();
                if (ai) {
                    obj->unitAI()->setCurrentOrder(0x2c6); obj->unitAI()->setCurrentAction(0x262);
                    if (target != 0 &&
                        (target->master->radius_x > DAT_0056f4e0 ||
                         target->master->radius_y > DAT_0056f4e0))
                        obj->unitAI()->setCurrentTarget(target->id, target->master->object_group, order->location_x, order->location_y, 0.0f);
                    else obj->unitAI()->setCurrentTarget(-1, -1, order->location_x, order->location_y, 0.0f);
                }
            }
            ++idx; ++p;
        } while (idx < n);
    }
}
