// VA: 0052ECF0 TRIBE_World::scenario_make_player
// PDB source: tworld.cpp lines 458-470
// Baseline reconstruction: allocate a TRIBE_Player for each scenario slot,
// selecting the computer-player constructor flag only for type 4.
// Attempt log:
// - /GX is required by the original FS:[0] EH registration; it improves the
//   clean default candidate from 152 to 219 bytes and restores the CFG/body
//   basin.  /Ob0 is codegen-neutral and was not retained.
// - Nested type dispatch, switch dispatch, type-4 outer dispatch, and a
//   branch-local type-4 result were tested.  The nested type-0-first form is
//   the best natural source and matches all original calls except one merged
//   TRIBE_Player constructor site.
// - Proven ABI/layout facts retained: TRIBE_World* constructor argument,
//   RGE_Player base size 0x220, TRIBE_Player size 0x848, world arrays at
//   +0x40/+0x48.  Remaining structural gap is VC5 call factoring: rebuilt
//   code is 219 vs 255 bytes with 4/5 calls and 83.13% shape similarity.
// probes 12-14: the type==4 predicate, a branch-local scalar flag, and
//   equivalent local name/flag expressions were codegen-neutral.
// probe 13: six natural local/master/flag spellings grouped into 219B, or
//   265-268B with extra saved-register liveness; none restored the call site.
// probe 14: reference/dereference/index expression variants likewise stayed
//   in the 219B basin; pointer references reached 268B with EBX/EBP saves.
// probe 15: corrected the inherited array ownership to RGE_Player**; emitted
//   bytes were unchanged and the canonical declaration is retained.
// probe 17: explicit placement-new/operator-new diagnostics destroyed the
//   EH/body basin (143-167B), so they are not source candidates.
// probe 18: an explicit goto store join was codegen-neutral.
// probe 19: /Ob0, /O1, and /Od flag variants did not produce the original
//   255B/5-call basin; only /GX retained the 219B candidate.
// probe 21: assigning the player slot directly in each natural branch inhibits
//   VC5's constructor-call tail factoring while its optimized common store
//   still reproduces the original 255B/5-call output exactly.
// Prefix TU pass: moved world, player, and constructor ownership into the
//   shared canonical context. The isolated owner remains exact.

#include "../../include/tworld_prefix_context.h"

void TRIBE_World::scenario_make_player(short player_id, unsigned char master_id,
    unsigned char type, unsigned char civ, char* player_info)
{
    if (type == 0) {
        this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
            (unsigned char)player_id, player_info, master_id, 0, 1, 0, 0, 0);
    } else {
        if (type == 4) {
            this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
                (unsigned char)player_id, player_info, master_id, 1, 1, 0, 0, 0);
        } else {
            this->players[player_id] = new TRIBE_Player(this, this->master_players[master_id],
                (unsigned char)player_id, player_info, master_id, 0, 1, 0, 0, 0);
        }
    }
}
