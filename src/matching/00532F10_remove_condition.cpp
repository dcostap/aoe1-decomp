#ifndef VICTORY_CONTEXT_H
#include "../../include/victory_context.h"
#endif

unsigned char RGE_Victory_Conditions::remove_condition(long index) {
    int i = 0;
    RGE_Victory_Entry* entry = this->victory_list;
    while (entry) {
        if (i == index) {
            this->sub(entry);
            return 1;
        }
        i++;
        entry = entry->next;
    }
    return 0;
}
