#include "../../include/tvw_dmap_context.h"

TRIBE_Diamond_Map_View::TRIBE_Diamond_Map_View() : RGE_Diamond_Map_View() {
    this->last_attack_time = 0;
    this->flash_on = 0;
}

// BINARY NOTE: The deleting destructor calls this derived destructor thunk.
TRIBE_Diamond_Map_View::~TRIBE_Diamond_Map_View() {
}
