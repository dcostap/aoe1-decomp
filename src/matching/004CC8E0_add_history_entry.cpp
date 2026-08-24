// VA: 004CC8E0 | TRIBE_History_Info::add_history_entry(uchar,uchar) | t_histry.cpp:110-137 | 106 bytes
//
// Attempt log:
// [1] First attempt.

#include "../../include/game_types.h"
#include <stdlib.h>
#include <string.h>

#pragma intrinsic(memcpy)

#include "../../include/t_histry_context.h"

void TRIBE_History_Info::add_history_entry(unsigned char flag, unsigned char value) {
    if (this->number_of_entries >= this->max_number_of_entries) {
        int oldCapacity = this->max_number_of_entries;
        this->max_number_of_entries += 0x3C;
        TRIBE_History_Entry* newBuf = (TRIBE_History_Entry*)calloc(
            this->max_number_of_entries, 1);
        if (oldCapacity > 0) {
            memcpy(newBuf, this->history, oldCapacity);
            free(this->history);
        }
        this->history = newBuf;
    }

    if (flag == 0) {
        this->history[this->number_of_entries].population = value;
    }

    this->number_of_entries++;
}
