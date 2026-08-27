// Authentic source module for C:\\msdev\\work\\age1_x1\\tact_dar.cpp.
// Definitions follow PDB source order. The compiler-generated vector
// deleting destructor is not a handwritten owner here.

#include "../include/tact_dar.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/map.h"
#include "../include/world.h"
#include "../include/obj_list.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/game_globals.h"
#include <stdlib.h>

// 00575078 is an unnamed read-only float used by the original map scan.
extern float DAT_00575078;

// VA 004CE530; tact_dar.cpp lines 32-37; matching before reunification.
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
    int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1)
{
    this->action_type = 0x6C;
    this->flags = (unsigned char*)calloc(
        this->obj->owner->world->player_num, 1);
    rge_read(file, this->flags, this->obj->owner->world->player_num);
}

// VA 004CE5F0; tact_dar.cpp lines 42-48; matching before reunification.
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
    RGE_Action_Object* object, RGE_Task* task, RGE_Static_Object* target)
    : RGE_Action(object, 1)
{
    this->task = task;
    this->action_type = 0x6C;
    RGE_Action::set_target_obj(target);
    this->flags = (unsigned char*)calloc(
        this->obj->owner->world->player_num, 1);
}

// VA 004CE670; tact_dar.cpp lines 53-61; matching before reunification.
TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
    RGE_Action_Object* object, RGE_Task* task,
    float x, float y, float z)
    : RGE_Action(object, 1)
{
    this->task = task;
    this->action_type = 0x6C;
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->flags = (unsigned char*)calloc(
        this->obj->owner->world->player_num, 1);
}

// VA 004CE6D0; tact_dar.cpp lines 65-69; matching before reunification.
void TRIBE_Action_Discovery_Artifact::save(int file)
{
    int size;

    RGE_Action::save(file);
    size = this->obj->owner->world->player_num;
    rge_write(file, this->flags, size);
}

// VA 004CE700; tact_dar.cpp lines 73-76; matching before reunification.
void TRIBE_Action_Discovery_Artifact::first_in_stack(unsigned char value)
{
    if (value != 0) {
        this->set_state(6);
    }
}

// VA 004CE720; tact_dar.cpp lines 80-92; matching before reunification.
void TRIBE_Action_Discovery_Artifact::set_state(unsigned char value)
{
    this->state = value;
    if (value == 10) {
        this->timer = 3.0f;
    }
}

// VA 004CE740; tact_dar.cpp lines 96-121; accepted drift before reunification.
unsigned char TRIBE_Action_Discovery_Artifact::update()
{
    switch (this->state) {
    case 1:
        return 1;

    case 6:
        this->check_objects();
        this->set_state(10);
        break;

    case 10:
        this->timer -= this->obj->owner->world->world_time_delta_seconds;
        if (this->timer <= DAT_00575070) {
            this->set_state(6);
        }
        break;
    }

    return 0;
}

// VA 004CE7A0; tact_dar.cpp lines 125-165; matching before reunification.
void TRIBE_Action_Discovery_Artifact::check_objects()
{
    RGE_Action_Object* obj = this->obj;
    RGE_Master_Static_Object* master = obj->master_obj;

    short map_x = (short)(obj->world_x - DAT_00575078 - master->radius_x);
    short map_y = (short)(obj->world_y - DAT_00575078 - master->radius_y);
    short x0 = (short)(master->radius_x + obj->world_x - DAT_0057507c);
    short y0 = (short)(master->radius_y + obj->world_y - DAT_0057507c);

    RGE_Map* map = obj->owner->world->map;

    if (map_x < 0) {
        map_x = 0;
    }
    if (map_y < 0) {
        map_y = 0;
    }
    if (x0 >= map->map_width) {
        x0 = (short)map->map_width - 1;
    }
    if (y0 >= map->map_height) {
        y0 = (short)map->map_height - 1;
    }

    for (short y = map_y; y <= y0; ++y) {
        for (short x = map_x; x <= x0; ++x) {
            RGE_Object_Node* node = map->map_row_offset[y][x].objects.list;
            while (node != 0) {
                if (node->node->owner != this->obj->owner &&
                    this->flags[node->node->owner->id] == 0) {
                    this->flags[node->node->owner->id] = 1;
                    node->node->owner->master_objects[162]->make_new_obj(
                        node->node->owner,
                        node->node->world_x,
                        node->node->world_y,
                        node->node->world_z);
                }
                node = node->next;
            }
        }
    }
}
