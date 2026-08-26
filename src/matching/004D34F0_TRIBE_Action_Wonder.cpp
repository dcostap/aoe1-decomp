// TRIBE_Action_Wonder::~TRIBE_Action_Wonder
// VA: 004D34F0
// PDB: tact_wnd.cpp:50-97
//
// FLAGS: /GX
//
// Attempt log:
// - draft 1: standalone class, no base -> no EH/no base destructor call, 88.9%.
// - baseline: restored the RGE_Action base/EH surface and the action-object/state
//   ownership, but the decompiler-shaped raw locals left a 0x10 frame and 12
//   bytes of excess code.
// - hypothesis 2: use the same-TU typed action/world/player surfaces as set_state,
//   natural moving-player do-loops, and direct countdown/notification calls.
// - hypothesis 3: keep the original player array as a source local and use a
//   branch-local cursor for each state loop; the prior single cursor was
//   behaviorally wrong because state 6 started at the end of state 2's scan.

#include "../../include/game_globals.h"

TRIBE_Action_Wonder::~TRIBE_Action_Wonder()
{
    RGE_Game_World* world = rge_base_game->world;

    if (world->game_state == 0) {
        RGE_Player** players = world->players;
        int player_num = (int)world->player_num;

        if (this->state == 2) {
            RGE_Player** current = players;
            int i = 1;
            if (1 < player_num) {
                ++current;
                do {
                    if (i != this->object->owner->id) {
                        this->object->unexplore_terrain(current[0], 1, -1);
                    }
                    ++i;
                    ++current;
                } while (i < player_num);
            }
        }

        if (this->state == 6) {
            RGE_Player** current = players;
            int i = 1;
            if (1 < player_num) {
                ++current;
                do {
                    if (i != this->object->owner->id) {
                        this->object->unexplore_terrain(current[0], 0, -1);
                    }
                    ++i;
                    ++current;
                } while (i < player_num);
            }

            if (rge_base_game->world->countdown_active == 0) {
                int found = 0;
                RGE_Action_Object* object = this->object;
                RGE_Player* owner = object->owner;
                RGE_Action_Node* node = owner->action_list->head;

                while (node != 0) {
                    RGE_Action_Object* action = node->object;
                    if (action != object) {
                        RGE_Master_Object* master = (RGE_Master_Object*)action->master_obj;
                        if (master->id == 0x114 && action->object_state >= 2) {
                            found = 1;
                            break;
                        }
                    }
                    node = node->next;
                }

                rge_base_game->reset_countdown_timer(owner->id);
                if (found) {
                    rge_base_game->set_countdown_timer(this->object->owner->id, 2000);
                }
            }
        }

        rge_base_game->notification(
            0x6E,
            this->object->owner->id,
            (long)this->object->world_x,
            (long)this->object->world_y,
            0);
    }
}
