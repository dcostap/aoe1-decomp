// VA: 0050DF40 RGE_Timeline::add_delete (144 B)
// Timeline.cpp lines 459-494.
// The final call is a slot-zero, one-argument object operation.  The narrow
// Delete_View declaration preserves that observed caller ABI.

#include "../../include/Timeline_context.h"

RGE_Time_Entry* RGE_Timeline::add_delete(float time,
                                          RGE_Static_Object* obj)
{
    if (obj == 0)
        return 0;

    RGE_Time_Entry* node = this->add(time);
    if (node != 0) {
        RGE_Time_Entry* cur = this->time_list;
        while (cur != 0) {
            if (obj == cur->this_obj) {
                unsigned char cmd = cur->command;
                cur->this_obj = 0;
                if (cmd == 1)
                    node->this_obj_id = cur->this_obj_id;
            }
            if (obj == cur->target_obj)
                cur->target_obj = 0;
            cur = cur->next;
        }

        node->player = *(unsigned char*)((char*)obj->owner + 0x4A);
        node->obj_type = *(short*)((char*)obj->master_obj + 0x10);
        node->command = 4;
        node->x = obj->world_x;
        node->y = obj->world_y;
        ((RGE_Static_Object_Delete_View*)obj)->delete_from_timeline(1);
    }
    return node;
}
