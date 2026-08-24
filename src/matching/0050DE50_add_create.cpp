// VA: 0050DE50 RGE_Timeline::add_create (149 B)
// Timeline.cpp lines 404-431.

#include "../../include/Timeline_context.h"

RGE_Time_Entry* RGE_Timeline::add_create(float time, short type,
                                          unsigned char player, float x,
                                          float y, float z)
{
    RGE_Static_Object* obj = 0;
    RGE_Time_Entry* node = this->add(time);
    RGE_Player* p = this->world->players[player];
    RGE_Master_Static_Object* master = p->master_objects[type];
    if (master != 0)
        obj = master->make_new_obj(p, x, y, 0);

    if (node != 0 && master != 0) {
        node->player = player;
        node->obj_type = type;
        node->this_obj = obj;
        node->this_obj_id = this->avail_id;
        this->avail_id++;
        node->x = *(int*)&x;
        node->y = *(int*)&y;
        node->z = *(int*)&z;
        node->command = 1;
    }
    return node;
}
