// 00509120 RGE_Task_List::get_target_task
// Source: task_lst.cpp lines 159-237
// Size: 430 bytes, virtual member
//
// Attempt log:
// - Baseline compiled at 436B with all seven calls aligned, but the decompiler
//   cursor aliases colored static_obj/task/i as EBP/EDI/EBX instead of the
//   oracle's EDI/EBX/EBP and used an anonymous -1.0f constant.
// - Reconstructed the period typed task/master/player/world/map ownership,
//   direct named loops, true slot-3 check_task call, and DAT_00576540 sentinel.
// - Restored master copy_id so object_group is +0x14, and used unsigned > 0
//   predicates for the oracle's jbe byte filters.
// - The terrain result is intentionally a short local: the unsigned-byte API
//   result is promoted before the final list guard, matching the observed DI
//   materialization without raw aliases or volatile/compiler scaffolding.
// - Final default flags: MATCH, 430/430 bytes, 0 differing bytes.

#include "..\..\include\game_globals.h"

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;

class RGE_Task {
public:
    short task_type;                 // +0x00
    short id;                        // +0x02
    unsigned char is_default;        // +0x04
    unsigned char _gap_05;            // +0x05
    short action_type;               // +0x06
    short object_group;              // +0x08
    short object_id;                 // +0x0A
    unsigned char combat_level;      // +0x0C
    unsigned char combat_level_flag; // +0x0D
    short terrain_id;                // +0x0E
    unsigned char owner_type;        // +0x10
    unsigned char holding_attr;      // +0x11
    unsigned char state_building;    // +0x12
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;       // +0x04
    char _gap_05[0x0B];              // +0x05..+0x0F
    short id;                        // +0x10
    short copy_id;                   // +0x12
    short object_group;              // +0x14
    char _gap_16[0x76];              // +0x16..+0x8B
    unsigned char combat_level;      // +0x8C
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char _gap_04[0x24];              // +0x04..+0x27
    RGE_Map* map;                    // +0x28
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char _gap_04[0x38];              // +0x04..+0x3B
    RGE_Game_World* world;           // +0x3C
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char _gap_04[4];                 // +0x04..+0x07
    int map_width;                   // +0x08
    int map_height;                  // +0x0C
    unsigned char get_terrain(short x, short y);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                          // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;               // +0x0C
    char _gap_10[0x38];              // +0x10..+0x47
    unsigned char object_state;      // +0x48
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short, short);
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*,
                                      float, float, float);
    virtual int is_attack_task(RGE_Task*);
    virtual int check_task(RGE_Task*, RGE_Action_Object*, RGE_Static_Object*);

    RGE_Task** list;                 // +0x04
    short list_num;                  // +0x08
};

RGE_Task* RGE_Task_List::get_target_task(RGE_Action_Object* action_obj,
                                          RGE_Static_Object* static_obj,
                                          float x_coord, float y_coord,
                                          float z_coord)
{
    int i;
    short terrain_type;

    if (this->list_num == 0)
        return 0;

    if (static_obj != 0) {
        if (static_obj->object_state == 0) {
            for (i = 0; i < this->list_num; i++) {
                RGE_Task* task = this->list[i];
                if (task->state_building == 1) {
                    if (this->check_task(task, action_obj, static_obj))
                        return task;
                }
            }
        }

        for (i = 0; i < this->list_num; i++) {
            RGE_Task* task = this->list[i];
            if (task->object_id == static_obj->master_obj->id) {
                if (this->check_task(task, action_obj, static_obj))
                    return task;
            }
        }

        for (i = 0; i < this->list_num; i++) {
            RGE_Task* task = this->list[i];
            if (task->object_group == static_obj->master_obj->object_group) {
                if (this->check_task(task, action_obj, static_obj))
                    return task;
            }
        }

        if (static_obj->object_state < 3 &&
            static_obj->master_obj->combat_level > 0) {
            for (i = 0; i < this->list_num; i++) {
                RGE_Task* task = this->list[i];
                if (task->combat_level > 0) {
                    if (this->check_task(task, action_obj, static_obj))
                        return task;
                }
            }
        }
    }

    if (x_coord != DAT_00576540 && y_coord != DAT_00576540) {
        short tile_x = (short)(int)x_coord;
        short tile_y = (short)(int)y_coord;
        RGE_Map* map = action_obj->owner->world->map;

        if (tile_x >= 0 && tile_x < map->map_width &&
            tile_y >= 0 && tile_y < map->map_height) {
            terrain_type = (unsigned char)map->get_terrain(tile_x, tile_y);
            for (i = 0; i < this->list_num; i++) {
                RGE_Task* task = this->list[i];
                if (task->terrain_id == terrain_type)
                    return task;
            }
        }
    }

    return 0;
}
