// TRIBE_Action_Wonder::set_state
// VA: 004D36B0
// PDB: tact_wnd.cpp:108-148
//
// Attempt log:
// - prior drafts used raw offset/function-pointer scaffolding and did not compile
//   against the local global surface; this is the clean typed baseline.
// - baseline hypothesis: period-style switch with case 6 first, a moving player
//   pointer, the real action-object virtual slots, and the base-game notification
//   slot.  The inherited action fields are kept at their proven offsets.
// - widened the local player bound to int after the oracle's early word movsx;
//   correcting RGE_Base_Game's polymorphic gap placed world at +0x3F4.
// - direct world expressions and declaration-order/ABI variants were unchanged;
//   a player temporary regressed the loop basin and was rolled back.
// - exact: advancing players once before the do-loop and again after incrementing
//   i recovered the oracle's add/inc/compare topology and all 345 bytes.

#include "../../include/game_globals.h"

void TRIBE_Action_Wonder::set_state(unsigned char param_1)
{
    this->state = param_1;

    switch (param_1) {
    case 6: {
        int player_num = (int)rge_base_game->world->player_num;
        RGE_Player** players = rge_base_game->world->players;
        int i = 1;

        if (1 < player_num) {
            ++players;
            do {
                if (i != this->object->owner->id) {
                    this->object->unexplore_terrain(players[0], 1, -1);
                    this->object->explore_terrain(players[0], 0, -1);
                }
                ++i;
                ++players;
            } while (i < player_num);
        }

        if (rge_base_game->world->countdown_active == 0) {
            rge_base_game->set_countdown_timer(this->object->owner->id, 2000);
        }

        rge_base_game->notification(
            0x6D,
            this->object->owner->id,
            (long)this->object->world_x,
            (long)this->object->world_y,
            0);
        return;
    }

    case 2: {
        int player_num = (int)rge_base_game->world->player_num;
        RGE_Player** players = rge_base_game->world->players;
        int i = 1;

        if (1 < player_num) {
            ++players;
            do {
                if (i != this->object->owner->id) {
                    this->object->explore_terrain(players[0], 1, -1);
                }
                ++i;
                ++players;
            } while (i < player_num);
        }

        rge_base_game->notification(
            0x6C,
            this->object->owner->id,
            (long)this->object->world_x,
            (long)this->object->world_y,
            0);
        return;
    }

    default:
        return;
    }
}
