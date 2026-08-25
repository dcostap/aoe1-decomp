// VA: 0052EDF0 TRIBE_World::load_world (314 B)
// PDB source: tworld.cpp
// Packet-grounded: base load_world, version-checked field reads
//   field_108 (victory_type, int, read if ver >= 5.6)
//   field_10C (artifact_count, int), field_110 (ruin_count, int, read if ver >= 5.3)
//   field_114 (countdown_victory, byte), field_118 (countdown_clock, float, read if ver >= 5.4)
//   field_11C (score_displayed, byte, read if ver >= 6.6)
//   field_11D (controllingComputerPlayer, byte, read if ver >= 6.97)
// Attempt log:
// - Replaced the free base shim with the typed RGE_Game_World base call and
//   restored the proven vtable surface; this aligned all eight direct calls.
// - Positive version-read guards recover the original inline-read/cold-zero
//   CFG and 96% instruction-shape similarity.  A direct base-load guard also
//   removes the decompiler-only result local and reaches the 315-byte basin.
// - A scoped zero local was codegen-neutral and was removed.  Remaining drift
//   is the VC5 callee-save basin: rebuilt saves EBX at entry, while the oracle
//   shrink-wraps push/pop EBX around the first version gate (known SIB/shift
//   consequences); no ABI, call-set, or field-layout uncertainty remains.
// sequential pass: donor stdlib context, explicit zero reuse, ground-truth
// world-tail/member ownership, real destructor surfaces, explicit cdecl, and
// an explicit base-result zero comparison were all neutral or regressed.  The
// clean typed source remains the best 315B basin; the remaining structural gap
// is the entry EBX save versus the oracle's late push/pop EBX schedule.
// - The ordinary C++ rge_read declaration preserved the typed call ABI and
//   restored all 18 call relocations. Negative guards improved the prologue but
//   inverted the original branch blocks. The first gate's cold zero label keeps
//   the observed read-before-zero order and late EBX lifetime; this is exact.
// Prefix TU pass: moved world, field, base-load, and read ownership into the
//   shared canonical context. The isolated owner remains exact.

#ifndef TWORLD_PHASE2_CONTEXT
#include "../../include/tworld_prefix_context.h"
#endif

void rge_read(int handle, void* buf, int size);

extern float save_game_version;

unsigned char TRIBE_World::load_world(int handle)
{
    if (!RGE_Game_World::load_world(handle))
        return 0;

    // Version-checked conditional reads
    if (save_game_version >= 5.6f) {
        rge_read(handle, &this->victory_type, 4);
    } else {
        goto victory_zero;
    }
    goto victory_done;
victory_zero:
    this->victory_type = 0;
victory_done:;
    
    if (save_game_version >= 5.3f) {
        rge_read(handle, &this->artifact_count, 4);
        rge_read(handle, &this->ruin_count, 4);
    } else {
        this->artifact_count = 0;
        this->ruin_count = 0;
    }
    
    if (save_game_version >= 5.4f) {
        rge_read(handle, &this->countdown_victory, 1);
        rge_read(handle, &this->countdown_clock, 4);
    } else {
        this->countdown_victory = 0;
        this->countdown_clock = 0.0f;
    }
    
    if (save_game_version >= 6.6f) {
        rge_read(handle, &this->score_displayed, 1);
    } else {
        this->score_displayed = 0;
    }

    if (save_game_version >= 6.97f) {
        rge_read(handle, &this->controllingComputerPlayer, 1);
    } else {
        this->controllingComputerPlayer = 2;
    }

    return 1;
}
