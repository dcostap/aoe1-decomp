#include "../include/t_histry.h"
#include "../include/world.h"
#include "../include/basegame.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"
#include <stdlib.h>
#include <string.h>

#pragma intrinsic(memcpy)

TRIBE_History_Info::TRIBE_History_Info(int infile) {
    this->history = 0;
    this->events = 0;
    this->number_of_entries = 0;
    this->number_of_events = 0;
    this->max_number_of_entries = 0;
    if (infile >= 0) {
        load(infile);
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

void TRIBE_History_Info::save(int outfile) {
    TRIBE_History_Events* step;

    rge_write(outfile, &this->number_of_entries, 4);
    rge_write(outfile, &this->number_of_events, 4);
    rge_write(outfile, &this->max_number_of_entries, 4);
    rge_write(outfile, this->history, this->max_number_of_entries);

    int count = 0;
    step = this->events;
    while (step) {
        count++;
        step = step->next;
    }

    rge_write(outfile, &count, 4);

    step = this->events;
    while (step) {
        rge_write(outfile, step, 16);
        step = step->next;
    }
}

void TRIBE_History_Info::load(int infile) {
    rge_read(infile, &this->number_of_entries, 4);
    rge_read(infile, &this->number_of_events, 4);
    rge_read(infile, &this->max_number_of_entries, 4);

    this->history = (TRIBE_History_Entry*) calloc(this->max_number_of_entries, 1);
    rge_read(infile, this->history, this->max_number_of_entries);

    int count;
    TRIBE_History_Events** prev_ptr = &this->events;
    rge_read(infile, &count, 4);

    while (count > 0) {
        TRIBE_History_Events* step = (TRIBE_History_Events*) calloc(1, 16);
        rge_read(infile, step, 16);
        *prev_ptr = step;
        prev_ptr = &step->next;
        count--;
    }
}

void TRIBE_History_Info::add_history_entry(unsigned char history_type, unsigned char entry) {
    if (this->number_of_entries >= this->max_number_of_entries) {
        int old_capacity = this->max_number_of_entries;
        this->max_number_of_entries += 0x3C;
        TRIBE_History_Entry* new_entries = (TRIBE_History_Entry*) calloc(this->max_number_of_entries, 1);
        if (old_capacity > 0) {
            memcpy(new_entries, this->history, old_capacity);
            free(this->history);
        }
        this->history = new_entries;
    }

    if (history_type == 0) {
        this->history[this->number_of_entries].population = entry;
    }

    this->number_of_entries++;
}

long TRIBE_History_Info::get_history_entry_num() {
    return this->number_of_entries;
}

unsigned char TRIBE_History_Info::get_history_entry(unsigned char history_type, long time) {
    if ((time < this->number_of_entries) && (time >= 0) && (history_type == 0)) {
        return this->history[time].population;
    }
    return 0;
}

void TRIBE_History_Info::add_history_event(unsigned char history_event) {
    if (this->number_of_entries > 0) {
        TRIBE_History_Events* event_node = (TRIBE_History_Events*) calloc(1, 16);
        event_node->next = this->events;
        event_node->time = this->number_of_entries;
        event_node->world_time = rge_base_game->world->world_time;
        event_node->event = history_event;
        this->events = event_node;
    }
}

long TRIBE_History_Info::get_history_event_num() {
    return this->number_of_events;
}

unsigned char TRIBE_History_Info::get_history_event(long number, unsigned char& event, long& time) {
    TRIBE_History_Events* node = this->events;

    if (node == 0) {
        return 0;
    }

    while (node != 0) {
        if (number == 0) {
            event = node->event;
            time = node->time;
            return 1;
        }
        node = node->next;
    }

    return 0;
}

unsigned char TRIBE_History_Info::get_history_event(long time_slice, unsigned char& event) {
    TRIBE_History_Events* node = this->events;

    while (node != 0) {
        if (node->time == time_slice) {
            event = node->event;
            return 1;
        }
        node = node->next;
    }
    return 0;
}
