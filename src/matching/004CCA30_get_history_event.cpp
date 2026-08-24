#include "../../include/t_histry_context.h"

unsigned char TRIBE_History_Info::get_history_event(long time, unsigned char& event) {
    TRIBE_History_Events* node = this->events;

    while (node != 0) {
        if (node->time == time) {
            event = node->event;
            return 1;
        }
        node = node->next;
    }
    return 0;
}
