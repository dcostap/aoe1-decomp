#pragma once
#include "common.h"
#include "TRIBE_History_Entry.h"
#include "TRIBE_History_Events.h"

struct TRIBE_History_Info {
    TRIBE_History_Info(int param_1);
    ~TRIBE_History_Info();

    void save(int param_1);
    void load(int param_1);
    void add_history_entry(uchar param_1, uchar param_2);
    void add_history_event(uchar param_1);
    long get_history_entry_num();
    long get_history_event_num();
    uchar get_history_entry(uchar param_1, long param_2);
    uchar get_history_event(long param_1, uchar* param_2, long* param_3);
    uchar get_history_event(long param_1, uchar* param_2);

    TRIBE_History_Entry* history;
    TRIBE_History_Events* events;
    long number_of_events;
    long number_of_entries;
    long max_number_of_entries;
};
static_assert(sizeof(TRIBE_History_Info) == 0x14, "Size mismatch");
