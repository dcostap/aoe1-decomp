extern "C" void free(void* ptr);

#include "../../include/t_histry_context.h"

TRIBE_History_Info::~TRIBE_History_Info() {
    TRIBE_History_Events* events;

    if (this->history != 0) {
        free(this->history);
    }
    while ((events = this->events) != 0) {
        this->events = events->next;
        free(events);
    }
}
