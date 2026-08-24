// VA: 0050D9A0 RGE_Timeline::update (341 B)
// PDB source: Timeline.cpp lines 155-221.
// The typed event switch and the four observed virtual calls are retained.

#include "../../include/Timeline_context.h"

void RGE_Timeline::update() {
    RGE_Time_Entry* event = 0;
    RGE_Player* player;
    RGE_Master_Static_Object* master;
    RGE_Static_Object* object;
    RGE_Time_Entry* scan;
    float time = this->world->world_time * 0.001f;
    RGE_Time_Entry* entry = this->time_list;

    if (entry != 0) {
        do {
            if (event == 0 && entry->time > this->old_time)
                event = entry;

            if (entry->this_obj != 0 && entry->this_obj->object_state >= 8)
                entry->this_obj = 0;
            if (entry->target_obj != 0 && entry->target_obj->object_state >= 8)
                entry->target_obj = 0;
            entry = entry->next;
        } while (entry != 0);

        for (; event != 0 && event->time <= time; event = event->next) {
            switch (event->command) {
            case 0:
                if (event->this_obj != 0 && event->target_obj != 0)
                    event->this_obj->attack(event->target_obj);
                break;

            case 1: {
                player = this->world->players[event->player];
                master = player->master_objects[event->obj_type];
                if (master != 0) {
                    object = master->create(player, event->x, event->y, 0);
                    for (scan = this->time_list; scan != 0; scan = scan->next) {
                        if (event->this_obj_id == scan->this_obj_id)
                            scan->this_obj = object;
                        if (event->this_obj_id == scan->target_obj_id)
                            scan->target_obj = object;
                    }
                }
                break;
            }

            case 2:
                if (event->this_obj != 0)
                    event->this_obj->move(0, event->x, event->y, event->z);
                break;

            case 4:
                if (event->this_obj != 0)
                    event->this_obj->destroy_obj();
                break;
            }
        }
    }
    this->old_time = time;
}
