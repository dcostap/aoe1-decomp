// VA: 0050DEF0 RGE_Timeline::add_move (80 B)
// Timeline.cpp lines 436-454.

#include "../../include/Timeline_context.h"

RGE_Time_Entry* RGE_Timeline::add_move(float time,
                                        RGE_Static_Object* object,
                                        float x, float y, float z) {
    RGE_Time_Entry* entry = this->add(time);
    if (entry != 0) {
        entry->player = object->owner->id;
        entry->this_obj = object;
        entry->this_obj_id = this->find_id(object);
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->command = 2;
    }
    return entry;
}
