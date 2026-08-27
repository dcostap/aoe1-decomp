#include "../include/game_globals.h"
#include "../include/task_lst.h"
#include "../include/act_obj.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/world.h"

extern "C" void __cdecl rge_read(int fd, void* buffer, int size);
extern "C" void __cdecl rge_write(int fd, void* buffer, int size);
extern void* __cdecl calloc(int count, int size);
extern void __cdecl free(void* block);
extern int __cdecl fscanf(FILE* file, const char* format, ...);

RGE_Task_List::RGE_Task_List()
{
    list_num = 0;
    list = 0;
}

RGE_Task_List::~RGE_Task_List()
{
    delete_list();
}

void RGE_Task_List::copy(RGE_Task_List* src)
{
    if (list)
        delete_list();

    list_num = src->list_num;
    if (list_num > 0) {
        list = (RGE_Task**)calloc((int)list_num, 4);
        for (short i = 0; i < list_num; i++) {
            list[i] = create_task(src->list[i]->task_type, i);
            list[i]->copy(src->list[i]);
        }
    }
}

void RGE_Task_List::load(int handle, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short task_type;
    RGE_Task_List* self = this;

    if (self->list)
        self->delete_list();

    rge_read(handle, &self->list_num, 2);
    if (self->list_num <= 0)
        return;

    self->list = (RGE_Task**)calloc(self->list_num, 4);
    for (int i = 0; (short)i < self->list_num; i++) {
        rge_read(handle, &task_type, 2);
        self->list[(short)i] = self->create_task(task_type, i);
        self->list[(short)i]->load(handle, sprites, sounds);
    }
}

void RGE_Task_List::load(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds)
{
    short task_type;

    if (list)
        delete_list();

    fscanf(file, "%hd", &list_num);
    if (list_num > 0) {
        list = (RGE_Task**)calloc((int)list_num, 4);
        for (int i = 0; (short)i < list_num; i++) {
            fscanf(file, "%hd", &task_type);
            list[(short)i] = create_task(task_type, i);
            list[(short)i]->load(file, sprites, sounds);
        }
    }
}

void RGE_Task_List::save(int fd)
{
    rge_write(fd, &list_num, 2);
    for (short i = 0; i < list_num; ++i)
        list[i]->save(fd);
}

void RGE_Task_List::delete_list()
{
    short i = 0;

    if (list != 0) {
        if (list_num > 0) {
            do {
                RGE_Task* task = list[i];
                if (task != 0) {
                    delete task;
                    list[i] = 0;
                }
                ++i;
            } while (i < list_num);
        }

        free(list);
        list = 0;
    }

    list_num = 0;
}

RGE_Task* RGE_Task_List::create_task(short task_type, short object_id)
{
    if (task_type != 1)
        return 0;

    RGE_Task* task = new RGE_Task(object_id);
    return task;
}

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

int RGE_Task_List::is_attack_task(RGE_Task* task)
{
    return task->action_type == 7;
}

int RGE_Task_List::check_task(RGE_Task* task,
                               RGE_Action_Object* action_obj,
                               RGE_Static_Object* static_obj)
{
    if (task->holding_attr == 1) {
        if (static_obj->attribute_type_held == -1 ||
            static_obj->attribute_amount_held <= DAT_00576544)
            return 0;
    }

    switch (task->owner_type) {
    case 1:
        if (static_obj->owner != action_obj->owner)
            return 0;
        break;

    case 2:
        if (static_obj->owner != action_obj->owner) {
            if (static_obj->owner->id != 0) {
                if (!action_obj->owner->relation(static_obj->owner->id))
                    return 0;
                break;
            }
        }
        return 0;

    case 3:
        if (static_obj->owner->id == 0)
            break;
        return 0;

    case 4:
        if (static_obj->owner == action_obj->owner)
            return 1;
        if (static_obj->owner->id != 0) {
            if (action_obj->owner->isAlly(static_obj->owner->id)) {
                if (static_obj->owner->isAlly(action_obj->owner->id))
                    return 1;
            }
        }
        return 0;

    case 5:
        if (static_obj->owner == action_obj->owner)
            goto case5_failure;
        if (static_obj->owner->id != 0) {
            if (!action_obj->owner->relation(static_obj->owner->id))
                goto case5_failure;
        }
        if (static_obj->owner->id == 0 &&
            action_obj->master_obj->combat_level == 0)
            goto case5_failure;
        break;

    case5_failure:
        return 0;
    }

    return (int)(action_obj != static_obj);
}
