#include "../../include/tvictory_context.h"

unsigned char TRIBE_Victory_Conditions::add_tech(unsigned char id, long count) {
    RGE_Victory_Entry* entry;

    entry = this->add(id, 0);
    if (entry != 0) {
        entry->command = 0x64;
        entry->count = count;
        return 1;
    }
    return 0;
}
