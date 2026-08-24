// VA: 0050DFD0 RGE_Timeline::sub (100 B target)
// Timeline.cpp lines 499-530.
//
// ACCEPTED_DRIFT: VC5 folds the redundant head-null test and chooses a
// different self-call tail, while list unlinking and the command-1 rescan
// remain behaviorally equivalent.

#include "../../include/Timeline_context.h"
#include <stdlib.h>

void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry* p = this->time_list;
    RGE_Time_Entry** link = &this->time_list;
    if (p != 0) {
        for (; p != 0 && p != entry; ) {
            link = &p->next;
            p = p->next;
            if (p == 0)
                return;
        }
        *link = p->next;
        if (p->command == 1) {
            entry = this->time_list;
            while (entry != 0)
                entry = entry->next;
        }
        this->sub(entry);
        free(p);
        this->list_num--;
    }
}
