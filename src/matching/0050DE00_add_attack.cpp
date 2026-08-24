// VA: 0050DE00 RGE_Timeline::add_attack (80 B)
// Timeline.cpp lines 383-399.

#include "../../include/Timeline_context.h"

RGE_Time_Entry* RGE_Timeline::add_attack(float time,
                                          RGE_Static_Object* object,
                                          RGE_Static_Object* target) {
    RGE_Time_Entry* entry = this->add(time);
    if (entry != 0) {
        entry->this_obj = object;
        entry->player = object->owner->id;
        entry->this_obj_id = this->find_id(object);
        entry->target_obj = target;
        // ORIGINAL BUG: the shipped code looks up the source object again.
        entry->target_obj_id = this->find_id(object);
        entry->command = 0;
    }
    return entry;
}
