// VA: 0050DB10 RGE_Timeline::mock_update (529 B target)
// PDB source: Timeline.cpp lines 227-320.
// This is the complete natural rewind/forward scan in one shared class context.

#include "../../include/Timeline_context.h"

void RGE_Timeline::mock_update(float t)
{
    RGE_Time_Entry* list;
    RGE_Time_Entry* e;
    RGE_Time_Entry* n;
    RGE_Static_Object* obj;

    if (t < old_time) {
        list = time_list;
        e = time_list;
        if (e != 0) {
            while (e != 0) {
                n = e->next;
                if (n == 0)
                    break;
                if (n->time > old_time)
                    break;
                e = e->next;
            }
            while (e != 0) {
                if (e->time <= t) break;
                if (!(e->time > old_time)) {
                    switch (e->command) {
                    case 1:
                        obj = e->this_obj;
                        if (obj != 0) {
                            RGE_Time_Entry* p = time_list;
                            for (; p != 0; p = p->next) {
                                if (obj == p->this_obj) p->this_obj = 0;
                                if (obj == p->target_obj) p->target_obj = 0;
                            }
                        }
                        if (obj != 0) delete obj;
                        break;
                    case 4:
                        {
                            RGE_Player* p = world->players[e->player];
                            RGE_Master_Static_Object* mo = p->master_objects[e->obj_type];
                            if (mo != 0) {
                                obj = mo->create(p, e->x, e->y, 0);
                                for (n = time_list; n != 0; n = n->next) {
                                    if (e->this_obj_id == n->this_obj_id) n->this_obj = obj;
                                    if (e->this_obj_id == n->target_obj_id) n->target_obj = obj;
                                }
                            }
                        }
                        break;
                    }
                }
                list = time_list;
                if (e == list) {
                    e = 0;
                } else {
                    RGE_Time_Entry* p = time_list;
                    while (p != 0) {
                        if (p->next == e) e = p;
                        p = p->next;
                    }
                }
            }
        }
    }
    if (old_time < t) {
        e = time_list;
        while (e != 0) {
            if (e->time > old_time && !(e->time > t)) {
                switch (e->command) {
                case 1:
                    {
                        RGE_Player* p = world->players[e->player];
                        RGE_Master_Static_Object* mo = p->master_objects[e->obj_type];
                        if (mo != 0) {
                            obj = mo->create(p, e->x, e->y, 0);
                            for (n = time_list; n != 0; n = n->next) {
                                if (e->this_obj_id == n->this_obj_id) n->this_obj = obj;
                                if (e->this_obj_id == n->target_obj_id) n->target_obj = obj;
                            }
                        }
                    }
                    break;
                case 4:
                    obj = e->this_obj;
                    if (obj != 0) {
                        for (n = time_list; n != 0; n = n->next) {
                            if (obj == n->this_obj) n->this_obj = 0;
                            if (obj == n->target_obj) n->target_obj = 0;
                        }
                    }
                    if (obj != 0) delete obj;
                    break;
                }
            }
            e = e->next;
        }
    }
    old_time = t;
}
