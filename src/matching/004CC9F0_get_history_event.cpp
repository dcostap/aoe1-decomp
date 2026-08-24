// 004CC9F0 TRIBE_History_Info::get_history_event
// Source: t_histry.cpp lines 198-211
// Size: 54 bytes, 0.0000% MATCH
//
// Attempt log:
// Probe 1: while(1)+break -> `je exit; jmp loop` control flow, mismatch
// Probe 2: while(node) -> `jne loop` back-edge, EXACT MATCH

#include "../../include/t_histry_context.h"

unsigned char TRIBE_History_Info::get_history_event(long index, unsigned char& event, long& time)
{
    TRIBE_History_Events* node = this->events;

    if (node == 0)
        return 0;

    while (node != 0) {
        if (index == 0) {
            event = node->event;
            time = node->time;
            return 1;
        }
        node = node->next;
    }

    return 0;
}
