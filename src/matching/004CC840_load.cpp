// VA: 004CC840 TRIBE_History_Info::load (t_histry.cpp lines 82-103)

// attempt 1: natural load with rge_read/calloc

#include <stdlib.h>

extern "C" void rge_read(int file, void* data, int size);

#include "../../include/t_histry_context.h"

void TRIBE_History_Info::load(int file) {
    rge_read(file, &this->number_of_entries, 4);
    rge_read(file, &this->number_of_events, 4);
    rge_read(file, &this->max_number_of_entries, 4);

    this->history = (TRIBE_History_Entry*)calloc(
        this->max_number_of_entries, 1);
    rge_read(file, this->history, this->max_number_of_entries);

    int step_count;
    TRIBE_History_Events** prev_ptr = &this->events;
    rge_read(file, &step_count, 4);

    while (step_count > 0) {
        TRIBE_History_Events* step =
            (TRIBE_History_Events*)calloc(1, 0x10);
        rge_read(file, step, 0x10);
        *prev_ptr = step;
        prev_ptr = &step->next;
        step_count--;
    }
}
