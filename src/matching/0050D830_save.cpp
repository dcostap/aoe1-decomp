// VA: 0050D830 RGE_Timeline::save
// Timeline.cpp lines 108-148.  Source and target player IDs are short locals;
// this preserves the two serialized low-word stores in the shipped routine.

#include "../../include/Timeline_context.h"

void RGE_Timeline::save(int file) {
    short source_player_id;
    short target_player_id;
    RGE_Time_Entry* entry;
    short* count_ptr;
    int i;
    int save_file;

    save_file = file;
    count_ptr = &this->list_num;
    rge_write(save_file, count_ptr, 2);
    rge_write(save_file, &this->avail_id, 2);
    rge_write(save_file, &this->old_time, 4);

    i = 0;
    if (*count_ptr > 0) {
        do {
            entry = &this->time_list[i];
            if (entry->this_obj != 0) {
                source_player_id = entry->this_obj->owner->id;
            } else {
                source_player_id = -1;
            }
            if (entry->target_obj != 0) {
                target_player_id = entry->target_obj->owner->id;
            } else {
                target_player_id = -1;
            }
            rge_write(save_file, entry, 4);
            rge_write(save_file, &entry->command, 1);
            rge_write(save_file, &entry->obj_type, 2);
            rge_write(save_file, &entry->player, 1);
            rge_write(save_file, &entry->x, 4);
            rge_write(save_file, &entry->y, 4);
            rge_write(save_file, &entry->z, 4);
            rge_write(save_file, &entry->task, 2);
            rge_write(save_file, &entry->this_obj_id, 2);
            rge_write(save_file, &source_player_id, 2);
            rge_write(save_file, &entry->target_obj_id, 2);
            rge_write(save_file, &target_player_id, 2);
            ++i;
        } while (i < *count_ptr);
    }
}
