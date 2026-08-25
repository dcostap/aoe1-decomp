// tried the direct calloc-and-link helper shape first; if this is off, the gap is likely only field layout
// keep this compact: allocate 0x34, initialize the fields, link at head, increment list_num
// if it stays non-exact, the remaining difference is likely just return/branch layout, not behavior

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

#include "../../include/victory_context.h"

RGE_Victory_Entry* RGE_Victory_Conditions::add(unsigned char param_1, unsigned char param_2) {
    RGE_Victory_Entry* entry = (RGE_Victory_Entry*)calloc(1, 0x34);
    if (entry != 0) {
        entry->state = 0;
        entry->victory_group = param_1;
        entry->ally_flag = param_2;
        entry->count = 0;
        entry->next = this->victory_list;
        this->victory_list = entry;
        this->list_num++;
    }
    return entry;
}
