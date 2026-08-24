#include "../../include/t_histry_context.h"

TRIBE_History_Info::TRIBE_History_Info(int index) {
    this->history = 0;
    this->events = 0;
    this->number_of_entries = 0;
    this->number_of_events = 0;
    this->max_number_of_entries = 0;
    if (index >= 0) {
        load(index);
    }
}
