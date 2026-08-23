// VA: 005420F0 RGE_Game_World::load_world
// PDB source: World.cpp lines 1021-1107
//
// Attempt log:
// - The prior raw-offset candidate had the correct 31-call surface and was
//   615 bytes, but cross-member cursors made player_num/player_time_delta
//   ownership opaque and left the first structural drift after load_map.
// - This reconstruction names the serialized world fields and map/player
//   ownership while retaining the
//   original narrow read widths and +0x34/+0xF4 dispatch surfaces.
// - Typed virtual declarations moved the candidate from 247 differing bytes
//   to 45 and then the short player-count temporary plus positive version gate
//   reached an 8-byte, 99.07% shape candidate with all 31 calls aligned.
// - Remaining bytes are localized to VC5 scheduling: `test ax, ax` versus the
//   original `cmp ax, bp`, and the players-field store occurring three bytes
//   before the original flag-preserving store position. A short-index predicate
//   regressed the whole tail and was rolled back.
// - Paused after the bounded 10-hypothesis budget; no inline asm or raw
//   absolute-address macros are retained.
// - Main-agent audit removed the player-count pointer and file-parameter byte
//   reuse. Named count/save-state locals are the plausible serialization source;
//   prior stack-home proximity remains diagnostic only.
// - This pass recovered the later 614-byte/31-call basin, with a natural
//   direct player_num gate leaving only the two-byte `test ax,ax` versus
//   original `cmp ax,bp` hunk.  Player-index comparisons, narrow-index and
//   zero aliases, declaration/initialization movement, and explicit signed or
//   unsigned 16-bit predicates either duplicated that basin or worsened the
//   tail.  A seven-case focused gate lab found no exact emitted variant.
// - Final source keeps named member ownership rather than the diagnostic
//   short-count alias; remaining drift is a compiler comparison/register
//   scheduling basin with all calls, size, frame, CFG, and memory effects
//   aligned.
// - Tested the natural same-TU guard `i < player_num` with the live zero
//   player-loop index at the first allocation gate; VC5 widened the compare,
//   shifted the hunk earlier, and regressed to 244 differing bytes. Rolled back.
// - A separate short initial-index local, a union alias for the 16/32-bit loop
//   index, and a cached short count all reproduced the 2-byte test basin.
// - Reusing the cleared old_time field as the zero RHS widened the first load
//   and regressed to 247 bytes. Restored the natural direct player_num guard.
// - Comparing the first allocation gate against old_time's low word emitted a
//   memory compare and 229 differing bytes; restored the clean source.
// - Reloading old_time into the loop index after initialization changed the
//   zero-store schedule and reached 278 differing bytes; restored.
// - Corrected initializePathingSystem to its proven int return ABI; emitted
//   bytes stayed unchanged at the 2-byte cmp/test basin, so the ABI is kept.
// - Adding an explicit nonnegative loop-index conjunct regressed to 244 bytes;
//   reversing the direct comparison operands reproduced the 2-byte basin.
// ACCEPTED_DRIFT: main-agent adjudication confirmed BP is cleared before the
// only differing gate and preserved by both preceding calls. `cmp ax,bp` and
// `test ax,ax` thus give the same jle condition. No memory, width, call, CFG,
// cleanup, or lifetime effect differs.

#include "../../include/world_scenario_context.h"

unsigned char RGE_Game_World::load_world(int file) {
    int i;
    unsigned long* p;
    int count;
    int player_type;
    int f = file;
    unsigned char saved_game_state;

    this->game_state = 2;
    this->game_end_condition = 0;
    rge_read(f, &this->world_time, 4);
    rge_read(f, &this->old_world_time, 4);
    rge_read(f, &this->world_time_delta, 4);
    rge_read(f, &this->world_time_delta_seconds, 4);
    rge_read(f, &this->timer, 4);
    rge_read(f, &this->game_speed, 4);
    rge_read(f, &this->temp_pause, 1);
    rge_read(f, &this->next_object_id, 4);
    rge_read(f, &this->next_reusable_object_id, 4);
    rge_read(f, &this->random_seed, 4);
    rge_read(f, &this->curr_player, 2);

    rge_read(f, &this->player_num, 2);
    rge_read(f, &saved_game_state, 1);
    rge_read(f, &this->campaign, 4);
    rge_read(f, &this->campaign_player, 4);
    rge_read(f, &this->campaign_scenario, 4);
    rge_read(f, &this->player_turn, 4);

    p = this->player_time_delta;
    count = 9;
    do {
        rge_read(f, p, 4);
        p++;
        count--;
    } while (count != 0);

    i = 0;
    this->old_time = 0;
    this->map->load_map(f);
    this->initializePathingSystem();
    this->currentUpdateComputerPlayer = -1;

    if (0 < this->player_num) {
        this->players = (RGE_Player**)calloc(4, this->player_num);
        if (0 < this->player_num) {
            do {
                rge_read(f, &player_type, 1);
                this->load_player(f, player_type, (short)i);
                i++;
            } while (i < this->player_num);
        }
    }

    this->update_mutual_allies();
    this->map->unified_vis_map->suppress_updates(1);
    i = 0;
    if (0 < this->player_num) {
        do {
            this->players[i]->load_info(f);
            i++;
        } while (i < this->player_num);
    }
    this->map->unified_vis_map->suppress_updates(0);
    this->scenario_init(f, this);

    if (save_game_version >= DAT_00577a10) {
        rge_read(f, &this->difficultyLevelValue, 4);
    } else {
        this->difficultyLevelValue = -1;
    }
    if (rge_base_game->singlePlayerGame()) {
        this->game_speed = rge_base_game->get_game_speed();
    }
    this->game_state = saved_game_state;
    return 1;
}
