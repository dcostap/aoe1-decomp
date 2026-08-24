#include <stdlib.h>

class RGE_Game_World {
public:
    void* vtable_ptr;
    unsigned long world_time;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
};

extern RGE_Base_Game* rge_base_game;

#include "../../include/t_histry_context.h"

void TRIBE_History_Info::add_history_event(unsigned char event) {
    if (this->number_of_entries > 0) {
        TRIBE_History_Events* ev = (TRIBE_History_Events*)calloc(1, 0x10);
        ev->next = this->events;
        ev->time = this->number_of_entries;
        ev->world_time = rge_base_game->world->world_time;
        ev->event = event;
        this->events = ev;
    }
}
