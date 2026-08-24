// VA: 0050D7E0 RGE_Timeline::~RGE_Timeline (70 B, 23 asm)
//
// ACCEPTED_DRIFT: the loop has equivalent free-argument scheduling.  The
// shared context gives this owner the authentic virtual destructor surface.

#include "../../include/Timeline_context.h"
#include <stdlib.h>

RGE_Timeline::~RGE_Timeline() {
    volatile RGE_Timeline* self = this;
    RGE_Time_Entry* list = self->time_list;
    if (list != 0) {
        RGE_Time_Entry* nxt;
        do {
            RGE_Time_Entry* current = self->time_list;
            nxt = current->next;
            free(current);
            self->time_list = nxt;
        } while (nxt != 0);
    }
    self->avail_id = 0;
    self->old_time = -1.0f;
    self->world = 0;
    self->list_num = 0;
}
