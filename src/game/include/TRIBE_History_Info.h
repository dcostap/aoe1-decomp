#pragma once
#include "common.h"

struct TRIBE_History_Info {
    TRIBE_History_Entry* history;
    TRIBE_History_Events* events;
    long number_of_events;
    long number_of_entries;
    long max_number_of_entries;
};
static_assert(sizeof(TRIBE_History_Info) == 0x14, "Size mismatch");
