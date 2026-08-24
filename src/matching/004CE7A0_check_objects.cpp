// TRIBE_Action_Discovery_Artifact::check_objects: 004CE7A0, tact_dar.cpp:125-165
// The typed map and owner declarations preserve the observed tile stride,
// object-list offset, and inherited action-object ownership.

#ifndef TACT_DAR_SHARED_CONTEXT
#include "../../include/tact_dar_context.h"
#endif

void TRIBE_Action_Discovery_Artifact::check_objects() {
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
                if (node->object->owner != this->obj->owner &&
                    this->flags[node->object->owner->id] == 0) {
                    this->flags[node->object->owner->id] = 1;
                    node->object->owner->master_objects[162]->make_new_obj(
                        node->object->owner,
                        node->object->world_x,
                        node->object->world_y,
                        node->object->world_z);
                }
                node = node->next;
            }
        }
    }
}
