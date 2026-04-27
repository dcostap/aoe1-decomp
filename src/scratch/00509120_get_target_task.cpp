// 00509120 RGE_Task_List::get_target_task
// Source: task_lst.cpp lines 159-237
// Size: 430 bytes, virtual member
//
// Attempt log:
// Probe 1: 430/430, 93% diff — push ecx from stack locals (obj_state, master)
// Probe 2: 430/430, ~93% diff — inlined field accesses, same basin
// Left in scratch: register allocation codegen basin (same as copy/load/check_task)

#include "..\..\include\game_globals.h"

class RGE_Task {
public:
    short task_type;        // +0x00
    char _gap_02[6];
    short object_group;     // +0x08
    short object_id;        // +0x0A
    char combat_level;      // +0x0C
    char _gap_0D[1];
    short terrain_id;       // +0x0E
    char owner_type;        // +0x10
    char holding_attr;      // +0x11
    char state_building;    // +0x12
};

class RGE_Master_Static_Object {
public:
    char _gap_00[0x10];
    short master_id;            // +0x10
    short master_object_group;  // +0x14
    char _gap_16[0x76];
    char combat_level;          // +0x8C
};

class RGE_Player {
public:
    char _gap_00[0x3C];
    void* field_3C;             // +0x3C
};

class RGE_Map {
public:
    char _gap_00[8];
    int map_width;       // +0x08
    int map_height;      // +0x0C
    unsigned char get_terrain(short x, short y);
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short, int);
    virtual void dmy01() {}
    virtual void dmy02() {}
    virtual int can_assign_task(RGE_Task* task, RGE_Action_Object* action_obj, RGE_Static_Object* static_obj);
    RGE_Task** list;        // +0x04
    short list_num;         // +0x08
    void delete_list();
    virtual RGE_Task* get_target_task(RGE_Action_Object* action_obj, RGE_Static_Object* static_obj,
                                       float x, float y, float z);
};

RGE_Task* RGE_Task_List::get_target_task(RGE_Action_Object* action_obj, RGE_Static_Object* static_obj,
                                          float x_coord, float y_coord, float z_coord)
{
    if (this->list_num <= 0)
        return 0;

    if (static_obj != 0) {
        char* s = (char*)static_obj;

        // Loop 1: state_building == 1
        if (*(char*)(s + 0x48) == 0) {
            for (int i = 0; i < this->list_num; i++) {
                RGE_Task* task = this->list[i];
                if (task->state_building == 1) {
                    if (this->can_assign_task(task, action_obj, static_obj))
                        return task;
                }
            }
        }

        RGE_Master_Static_Object* master = *(RGE_Master_Static_Object**)(s + 0x08);

        // Loop 2: object_id == master->master_id
        for (int i = 0; i < this->list_num; i++) {
            RGE_Task* task = this->list[i];
            if (task->object_id == master->master_id) {
                if (this->can_assign_task(task, action_obj, static_obj))
                    return task;
            }
        }

        // Loop 3: object_group == master->master_object_group
        for (int i = 0; i < this->list_num; i++) {
            RGE_Task* task = this->list[i];
            if (task->object_group == master->master_object_group) {
                if (this->can_assign_task(task, action_obj, static_obj))
                    return task;
            }
        }

        // Loop 4: combat_level check
        if (*(char*)(s + 0x48) < 3 && master->combat_level != 0) {
            for (int i = 0; i < this->list_num; i++) {
                RGE_Task* task = this->list[i];
                if (task->combat_level != 0) {
                    if (this->can_assign_task(task, action_obj, static_obj))
                        return task;
                }
            }
        }
    }

    // Coordinate check
    if (x_coord != -1.0f && y_coord != -1.0f) {
        short tile_x = (short)(int)x_coord;
        short tile_y = (short)(int)y_coord;

        // Map chain through action_obj
        RGE_Player* owner = *(RGE_Player**)((char*)action_obj + 0x0C);
        void* gameData = *(void**)((char*)owner + 0x3C);
        RGE_Map* map = *(RGE_Map**)((char*)gameData + 0x28);

        if (tile_x >= 0 && tile_x < map->map_width &&
            tile_y >= 0 && tile_y < map->map_height)
        {
            unsigned char terrainType = map->get_terrain(tile_x, tile_y);
            for (int i = 0; i < this->list_num; i++) {
                RGE_Task* task = this->list[i];
                if (task->terrain_id == (short)terrainType)
                    return task;
            }
        }
    }

    return 0;
}
