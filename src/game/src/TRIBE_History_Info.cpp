#include "../include/TRIBE_History_Info.h"
#include "../include/TRIBE_History_Entry.h"
#include "../include/TRIBE_History_Events.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

// Source of truth: t_histry.cpp.decomp

TRIBE_History_Info::TRIBE_History_Info(int param_1) {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC730
    this->history = nullptr;
    this->events = nullptr;
    this->number_of_entries = 0;
    this->number_of_events = 0;
    this->max_number_of_entries = 0;
    if (param_1 >= 0) {
        load(param_1);
    }
}

TRIBE_History_Info::~TRIBE_History_Info() {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC760
    if (this->history != nullptr) {
        free(this->history);
    }
    TRIBE_History_Events* evt = this->events;
    while (evt != nullptr) {
        this->events = evt->next;
        free(evt);
        evt = this->events;
    }
}

void TRIBE_History_Info::save(int param_1) {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC7A0
    rge_write(param_1, &this->number_of_entries, 4);
    rge_write(param_1, &this->number_of_events, 4);
    rge_write(param_1, &this->max_number_of_entries, 4);
    rge_write(param_1, this->history, this->max_number_of_entries);
    // Count events in linked list
    int count = 0;
    for (TRIBE_History_Events* p = this->events; p != nullptr; p = p->next) {
        count++;
    }
    rge_write(param_1, &count, 4);
    for (TRIBE_History_Events* p = this->events; p != nullptr; p = p->next) {
        rge_write(param_1, p, 0x10);
    }
}

void TRIBE_History_Info::load(int param_1) {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC840
    rge_read(param_1, &this->number_of_entries, 4);
    rge_read(param_1, &this->number_of_events, 4);
    rge_read(param_1, &this->max_number_of_entries, 4);
    this->history = (TRIBE_History_Entry*)calloc(this->max_number_of_entries, 1);
    rge_read(param_1, this->history, this->max_number_of_entries);
    TRIBE_History_Events** tail = &this->events;
    int count = 0;
    rge_read(param_1, &count, 4);
    for (; count > 0; count--) {
        TRIBE_History_Events* evt = (TRIBE_History_Events*)calloc(1, 0x10);
        rge_read(param_1, evt, 0x10);
        *tail = evt;
        tail = &evt->next;
    }
}

void TRIBE_History_Info::add_history_entry(uchar param_1, uchar param_2) {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC8E0
    if ((long)(unsigned long)this->max_number_of_entries <= this->number_of_entries) {
        long old_size = this->max_number_of_entries;
        this->max_number_of_entries = old_size + 0x3c;
        TRIBE_History_Entry* new_history = (TRIBE_History_Entry*)calloc(old_size + 0x3c, 1);
        if (old_size > 0) {
            memcpy(new_history, this->history, old_size);
            free(this->history);
        }
        this->history = new_history;
    }
    if (param_1 == 0) {
        this->history[this->number_of_entries].population = param_2;
    }
    this->number_of_entries++;
}

void TRIBE_History_Info::add_history_event(uchar param_1) {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC990
    if (this->number_of_entries > 0) {
        TRIBE_History_Events* evt = (TRIBE_History_Events*)calloc(1, 0x10);
        evt->next = this->events;
        evt->time = this->number_of_entries;
        evt->world_time = rge_base_game->world->world_time;
        evt->event = param_1;
        this->events = evt;
    }
}

long TRIBE_History_Info::get_history_entry_num() {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC950
    return this->number_of_entries;
}

long TRIBE_History_Info::get_history_event_num() {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC9E0
    return this->number_of_events;
}

uchar TRIBE_History_Info::get_history_entry(uchar param_1, long param_2) {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC960
    if (param_2 < this->number_of_entries && param_2 >= 0 && param_1 == 0) {
        return this->history[param_2].population;
    }
    return 0;
}

uchar TRIBE_History_Info::get_history_event(long param_1, uchar* param_2, long* param_3) {
    // Source of truth: t_histry.cpp.decomp @ 0x004CC9F0
    TRIBE_History_Events* evt = this->events;
    if (evt == nullptr) return 0;
    do {
        if (param_1 == 0) {
            *param_2 = evt->event;
            *param_3 = evt->time;
            return 1;
        }
        evt = evt->next;
    } while (evt != nullptr);
    return 0;
}

uchar TRIBE_History_Info::get_history_event(long param_1, uchar* param_2) {
    // Source of truth: t_histry.cpp.decomp @ 0x004CCA30
    TRIBE_History_Events* evt = this->events;
    if (evt == nullptr) return 0;
    do {
        if (evt->time == param_1) {
            *param_2 = evt->event;
            return 1;
        }
        evt = evt->next;
    } while (evt != nullptr);
    return 0;
}
