#include "../../include/tvw_dmap_context.h"

// tried the straightforward time-threshold/toggle shape first
// current hypothesis: any remaining mismatch would be in the shared layout or base-call basin

void TRIBE_Diamond_Map_View::draw_objects() {
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\tvw_dmap.cpp", 0x40);
    if (0x14D <= now - this->last_attack_time) {
        this->flash_on = (this->flash_on == 0);
        this->last_attack_time = now;
    }
    RGE_Diamond_Map::draw_objects();
}
