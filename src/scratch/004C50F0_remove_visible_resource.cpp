// VA: 004C50F0 RGE_Static_Object::remove_visible_resource
// PDB source: stat_obj.cpp:2605-2659
// Attempt log:
// - baseline: natural typed reconstruction using the matching
//   create_doppleganger_when_dying source shape, canonical map/player/master
//   ownership, and the two binary-observed resource/doppleganger calls.
// - declaration/liveness probes: swapped mask/explored declarations,
//   separated assignments, mutating the full map word, split copies, and
//   low-mask-first expressions. The mutating full-word form was the best
//   natural emitted basin (182 positional bytes differing; size/calls/frame
//   aligned), but the original keeps explored in EBP while the low mask is
//   the stack-reloaded value in EBX.
// - control-flow probe: direct nonzero explored-bit testing moved away from
//   the original `and/cmp` shape; restored the equality form.
// - variant lab: 180 focused map/bit-test/player-surface variants; no exact
//   result. Best eligible group remained a localized map/liveness mismatch.
// - final: retained the best period-plausible full-word mutation source;
//   unresolved VC5 register/stack coloring remains in scratch.
// - Main-agent audit restored canonical destructor slots, symbol-backed map
//   ownership, and natural player-array indexing. The validated 182-byte gap
//   remains, without raw absolute addresses or byte-indexed player plumbing.
// fresh worker: fixed absolute map address improved only the relocation/map
// operand by 3 bytes; restored symbol-backed clean source.
// fresh worker: explicit map-word copies and low-mask-first declarations widened
// to 184B/63.9%; restored canonical map/explored form.
// fresh worker baseline: resumed the pinned canonical source at 182 differing
// bytes; ordered calls, size, frame, and all five call sites are aligned.
// fresh worker: direct map-cell assignment to the low-mask local plus the
// binary-proven absolute map address produced the best natural basin (180
// differing bytes, exact size/frame/calls); it also restored EBX map/EBP
// explored extraction, but the oracle still spills mask while this build spills
// explored around the virtual call.
// fresh worker: explored/mask declaration order, shared player scopes, register
// qualifier, loop-index placement, and function-scope local placement were
// unchanged codegen duplicates; a focused 40-variant map/guard/player-scope lab
// found no exact output. Narrow volatile mask was structural/worse (304 bytes)
// and was rolled back.
// final fresh worker before donor lead: retained the period-plausible direct
// mask/explored source with absolute unified-map ownership; EBX/EBP stack
// spill drift remained.
// orch2-4C50F0-mask: mirror exact same-TU donor 004C5210 initialization:
// load mask, derive explored from mask, then mask the low word in place.
// This restored the original 288-byte output exactly; calls and behavior stay
// unchanged.

typedef unsigned long ulong;

#define unified_map_offsets ((ulong**)0x00886808)

#include "../../include/stat_obj_context.h"
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
#define RGE_STAT_OBJ_SHARED_CONTEXT 1
#endif

void RGE_Static_Object::remove_visible_resource() {
    ulong mask;
    ulong explored;
    RGE_Player* player;
    if (this->id >= 0 && this->owner != 0 && this->master_obj != 0 &&
        (this->master_obj->create_doppleganger_on_death != 0 ||
         this->master_obj->track_as_resource != 0)) {
        mask = unified_map_offsets[(int)this->world_y][(int)this->world_x];
        explored = mask >> 16;
        mask &= 0xFFFF;
        if (explored > 0) {
            int player_index = 0;
            do {
                if ((explored & 1) == 1) {
                    if (this->master_obj->track_as_resource != 0) {
                        player = this->owner->world->players[player_index];
                        player->VR_List->Remove_Resource(
                            this->id, this->master_obj->resource_group);
                    }
                    if (this->master_obj->create_doppleganger_on_death == 1 &&
                        (mask & 1) == 0 && player_index > 0) {
                        player = this->owner->world->players[player_index];
                        static_cast<RGE_Master_Doppleganger_Object*>(player->master_objects[243])->make_new_obj(
                            player, this->world_x, this->world_y, this->world_z, this);
                    }
                }
                player_index++;
                mask >>= 1;
                explored >>= 1;
            } while (explored != 0);
        }
        if (this->master_obj->create_doppleganger_on_death == 2) {
            this->owner->doppleganger_creator->remove_doppleganger_check(this);
        }
    }
}
