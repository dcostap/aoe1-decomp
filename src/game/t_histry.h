#pragma once
#include "../common.h"

class TRIBE_History_Info       {
public:
    TRIBE_History_Entry* history;            // 0x0
    TRIBE_History_Events* events;            // 0x4
    long number_of_events;                   // 0x8
    long number_of_entries;                  // 0xC
    long max_number_of_entries;              // 0x10

    TRIBE_History_Info(int param_1);

    // --- Non-Virtual Destructor ---
    ~TRIBE_History_Info() noexcept(false);
    // --- Non-Virtual Members ---
    void save(int param_1);
    void load(int param_1);
    void add_history_entry(uchar param_1, uchar param_2);
    long get_history_entry_num();
    uchar get_history_entry(uchar param_1, long param_2);
    void add_history_event(uchar param_1);
    long get_history_event_num();
    uchar get_history_event(long param_1, uchar* param_2, long* param_3);
    uchar get_history_event(long param_1, uchar* param_2);
};

static_assert(sizeof(TRIBE_History_Info) == 0x14, "TRIBE_History_Info Size Mismatch");
static_assert(offsetof(TRIBE_History_Info, max_number_of_entries) == 0x10, "TRIBE_History_Info Offset Mismatch");

