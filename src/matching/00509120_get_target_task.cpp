#include "../../include/task_lst_context.h"

// VA: 00509120 RGE_Task_List::get_target_task
// PDB source: task_lst.cpp, lines 159-237
//
// The four object-priority scans and the coordinate fallback follow the source
// order shown by the PDB line bands.  The terrain result remains a short local
// because the executable materializes the unsigned-byte result before its list
// comparison.

RGE_Task* RGE_Task_List::get_target_task(RGE_Action_Object* action_obj,
                                          RGE_Static_Object* static_obj,
                                          float x_coord, float y_coord,
                                          float z_coord)
{
    int i;
    short terrain_type;

    if (list_num == 0)
        return 0;

    if (static_obj != 0) {
        if (static_obj->object_state == 0) {
            for (i = 0; i < list_num; i++) {
                RGE_Task* task = list[i];
                if (task->state_building == 1) {
                    if (check_task(task, action_obj, static_obj))
                        return task;
                }
            }
        }

        for (i = 0; i < list_num; i++) {
            RGE_Task* task = list[i];
            if (task->object_id == static_obj->master_obj->id) {
                if (check_task(task, action_obj, static_obj))
                    return task;
            }
        }

        for (i = 0; i < list_num; i++) {
            RGE_Task* task = list[i];
            if (task->object_group == static_obj->master_obj->object_group) {
                if (check_task(task, action_obj, static_obj))
                    return task;
            }
        }

        if (static_obj->object_state < 3 &&
            static_obj->master_obj->combat_level > 0) {
            for (i = 0; i < list_num; i++) {
                RGE_Task* task = list[i];
                if (task->combat_level > 0) {
                    if (check_task(task, action_obj, static_obj))
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
            for (i = 0; i < list_num; i++) {
                RGE_Task* task = list[i];
                if (task->terrain_id == terrain_type)
                    return task;
            }
        }
    }

    return 0;
}
