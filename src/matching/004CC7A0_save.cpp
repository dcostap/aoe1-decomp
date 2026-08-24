// VA: 004CC7A0 TRIBE_History_Info::save (t_histry.cpp lines 59-75)

// attempt 1: natural save with rge_write

extern "C" void rge_write(int file, void* data, int size);

#include "../../include/t_histry_context.h"

void TRIBE_History_Info::save(int file) {
    TRIBE_History_Events* step;

    rge_write(file, &this->number_of_entries, 4);
    rge_write(file, &this->number_of_events, 4);
    rge_write(file, &this->max_number_of_entries, 4);
    rge_write(file, this->history, this->max_number_of_entries);

    // Count steps in linked list
    int step_count = 0;
    step = this->events;
    while (step) {
        step_count++;
        step = step->next;
    }

    rge_write(file, &step_count, 4);

    // Write each step
    step = this->events;
    while (step) {
        rge_write(file, step, 0x10);
        step = step->next;
    }
}
