// RGE_Victory_Conditions::handle_points_attribute_first
// VA: 00533180
// victory.cpp
//
// The complete victory.cpp class and record surface is shared in
// include/victory_context.h.  The body remains the exact natural reconstruction.

#include "../../include/victory_context.h"

void RGE_Victory_Conditions::handle_points_attribute_first(RGE_Victory_Point_Entry* entry) {
    RGE_Player* player;
    RGE_Victory_Point_Entry* p;
    if (entry->state == 0) {
        player = this->player;
        p = entry;
        int val = (int)player->attributes[p->attribute];
        int points = p->points;
        RGE_Player** players = player->world->players;
        p->curr_attribute_amount = (float)val;
        if (val < p->amount) return;

        val = 0;
        int count = this->player->world->player_num;
        if (0 < count) {
            do {
                if (val == this->player->id) {
                    val = val + 1;
                    players = players + 1;
                } else if ((float)p->amount > (*players)->attributes[p->attribute]) {
                    val = val + 1;
                    players = players + 1;
                } else {
                    p->state = 1;
                    return;
                }
            } while (val < count);
        }
        this->tot_victory_points += points - p->curr_points;
        p->curr_points = points;
        p->state = 2;
    }
}
