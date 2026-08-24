// VA: 0050DD30 RGE_Timeline::find_id (51 B)
// Timeline.cpp lines 326-335.

#include "../../include/Timeline_context.h"

short RGE_Timeline::find_id(RGE_Static_Object* obj) {
    RGE_Time_Entry* entry = this->time_list;
    if (entry == 0) return -1;

    while (entry != 0) {
        if (entry->command == 1 && entry->this_obj == obj) {
            return entry->this_obj_id;
        }
        entry = entry->next;
    }
    return -1;
}
