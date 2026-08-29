#include "../include/t_histry.h"
#include "../include/world.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"
#include <stdlib.h>
#include <string.h>

#pragma intrinsic(memcpy)

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

void TRIBE_History_Info::save(int file) {
    TRIBE_History_Events* step;

    rge_write(file, &this->number_of_entries, 4);
    rge_write(file, &this->number_of_events, 4);
    rge_write(file, &this->max_number_of_entries, 4);
    rge_write(file, this->history, this->max_number_of_entries);

    int step_count = 0;
    step = this->events;
    while (step) {
        step_count++;
        step = step->next;
    }

    rge_write(file, &step_count, 4);

    step = this->events;
    while (step) {
        rge_write(file, step, 0x10);
        step = step->next;
    }
}

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

void TRIBE_History_Info::add_history_entry(unsigned char flag,
                                           unsigned char value) {
    if (this->number_of_entries >= this->max_number_of_entries) {
        int old_capacity = this->max_number_of_entries;
        this->max_number_of_entries += 0x3C;
        TRIBE_History_Entry* new_entries = (TRIBE_History_Entry*)calloc(
            this->max_number_of_entries, 1);
        if (old_capacity > 0) {
            memcpy(new_entries, this->history, old_capacity);
            free(this->history);
        }
        this->history = new_entries;
    }

    if (flag == 0) {
        this->history[this->number_of_entries].population = value;
    }

    this->number_of_entries++;
}

long TRIBE_History_Info::get_history_entry_num() {
    return this->number_of_entries;
}

unsigned char TRIBE_History_Info::get_history_entry(unsigned char mode,
                                                     long index) {
    if ((index < this->number_of_entries) && (index >= 0) && (mode == 0)) {
        return this->history[index].population;
    }
    return 0;
}

void TRIBE_History_Info::add_history_event(unsigned char event) {
    if (this->number_of_entries > 0) {
        TRIBE_History_Events* history_event =
            (TRIBE_History_Events*)calloc(1, 0x10);
        history_event->next = this->events;
        history_event->time = this->number_of_entries;
        history_event->world_time = rge_base_game->world->world_time;
        history_event->event = event;
        this->events = history_event;
    }
}

long TRIBE_History_Info::get_history_event_num() {
    return this->number_of_events;
}

unsigned char TRIBE_History_Info::get_history_event(long index,
                                                     unsigned char& event,
                                                     long& time) {
    TRIBE_History_Events* node = this->events;

    if (node == 0) {
        return 0;
    }

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

unsigned char TRIBE_History_Info::get_history_event(long time,
                                                     unsigned char& event) {
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
