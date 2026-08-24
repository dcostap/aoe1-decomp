// VA: 0050D5B0 RGE_Timeline::RGE_Timeline
//
// ACCEPTED_DRIFT: the natural constructor has exact size and behavior.  The
// remaining drift is localized to the final link/index update at 0050D74C.
// This owner now uses the shared Timeline.cpp declaration surface.

#include "../../include/Timeline_context.h"
#include <stdlib.h>

RGE_Timeline::RGE_Timeline(int fd, RGE_Game_World* world_arg)
{
    int index;
    RGE_Time_Entry** link;
    RGE_Time_Entry** old_link;
    short target_player_id;
    short player_id;

    rge_read(fd, &this->list_num, 2);
    rge_read(fd, &this->avail_id, 2);
    rge_read(fd, &this->old_time, 4);
    this->world = world_arg;
    this->time_list = 0;

    link = &this->time_list;
    index = 0;
    if (this->list_num > 0) {
        do {
            RGE_Time_Entry* entry = (RGE_Time_Entry*)calloc(1, 0x30);
            rge_read(fd, &entry->time, 4);
            rge_read(fd, &entry->command, 1);
            rge_read(fd, &entry->obj_type, 2);
            rge_read(fd, &entry->player, 1);
            rge_read(fd, &entry->x, 4);
            rge_read(fd, &entry->y, 4);
            rge_read(fd, &entry->z, 4);
            rge_read(fd, &entry->task, 2);
            rge_read(fd, &entry->this_obj_id, 2);
            rge_read(fd, &target_player_id, 2);
            rge_read(fd, &entry->target_obj_id, 2);
            rge_read(fd, &player_id, 2);

            if (target_player_id >= 0 && this->world != 0) {
                entry->this_obj = this->world->players[target_player_id]->objects->find_by_id(entry->this_obj_id);
            } else {
                entry->this_obj = 0;
            }

            if (player_id >= 0 && this->world != 0) {
                entry->target_obj = this->world->players[target_player_id]->objects->find_by_id(entry->target_obj_id);
            } else {
                entry->target_obj = 0;
            }

            old_link = link;
            link = &entry->next;
            entry->next = 0;
            *old_link = entry;
            ++index;
        } while (index < this->list_num);
    }
}
