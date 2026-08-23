// VA: 00541EE0 RGE_Game_World::del_game_info()
// PDB source: World.cpp lines 926-1001
// attempt 1: direct reconstruction from packet with typed offsets, two player passes, and reset tail.
// attempt 2: add missing virtual slot for +0xB4 call and spell player checks as nested tests to keep VC5's reload/guard shape.
// attempt 3: volatile player_num kept passes separate but changed compares to memory form; rolled back.
// attempt 4: use explicit pass labels and a short count temp; VC5 still folds initial player_num/player-list guards.
// attempt 5: positive `num != 0 && num > 0` form; no change in the stubborn region.
// attempt 6: /O1, /GX, /Od probes; /O1 smaller, /GX unchanged, /Od broad mismatch; no custom flags kept.
// attempt 7: remove the cached `num` and redundant !=0 tests; this folded the
// duplicate pre-body test.
// attempt 8: retain the outer short count but use ordinary for loops for both
// passes.  VC5 then preserves the binary's early AX load, duplicate compare,
// and shared transition into the second pass.  Exact with default flags.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::del_game_info()
{
    int i;
    world_update_counter = 0;

    this->game_state = 2;
    this->game_end_condition = 0;
    this->reusable_static_objects->removeAllObjects();
    this->reusable_animated_objects->removeAllObjects();
    this->reusable_moving_objects->removeAllObjects();
    this->reusable_action_objects->removeAllObjects();
    this->reusable_combat_objects->removeAllObjects();
    this->reusable_missile_objects->removeAllObjects();
    this->reusable_doppleganger_objects->removeAllObjects();

    this->next_reusable_object_id = -1;
    this->campaign = -1;
    this->campaign_player = -1;
    this->campaign_scenario = -1;
    this->difficultyLevelValue = -1;
    this->next_object_id = 0;

    i = 0;
    if (this->maxNumberObjectsValue > 0) {
        do {
            this->objectsValue[i] = 0;
            i++;
        } while (i < this->maxNumberObjectsValue);
    }

    i = 0;
    if (this->maxNumberNegativeObjectsValue > 0) {
        do {
            this->negativeObjectsValue[i] = 0;
            i++;
        } while (i < this->maxNumberNegativeObjectsValue);
    }

    this->turn_sound_off();

    if (this->scenario != 0) {
        delete this->scenario;
        this->scenario = 0;
    }

    short num = this->player_num;
    if (num > 0 && this->players != 0) {
        for (i = 0; i < this->player_num; i++) {
            if (this->players[i] != 0) {
                this->players[i]->destroy_objects();
            }
        }
    }

    num = this->player_num;
    if (num > 0 && this->players != 0) {
        for (i = 0; i < this->player_num; i++) {
            if (this->players[i] != 0) {
                delete this->players[i];
                this->players[i] = 0;
            }
        }
        this->player_num = 0;
        free(this->players);
        this->players = 0;
    }

    this->next_object_id = 0;
    this->sound_update_index = 0;
    this->sprite_update_index = 0;
    this->player_turn = 0;
    for (i = 0; i < 9; i++) {
        this->player_time_delta[i] = 0;
    }
}
