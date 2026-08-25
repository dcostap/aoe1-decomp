// VA: 0052E920 TRIBE_World::setup_gaia()
// PDB: tworld.cpp lines 348-351 (102 bytes, 33 asm lines)
// FLAGS: config/flags/0052E920_setup_gaia.rsp (/nologo /c /O2 /Oy /GX)
// No inline asm/hacks.
//
// === ACCEPTED_DRIFT ===
// Remaining diff: 4-byte `test eax,eax; jne +0` (85c07500 = phi-merge artifact)
// inserted after xor eax,eax (null path) before the common players[0] = g store.
// This is the EXACT same VC5 phi-merge behavior observed in the previously accepted
// 0052E530/0052E590/0052E5F0/0052E650 accepted_drift functions — the `if (g == 0) g = 0;`
// normalization forces a common store point but VC5 adds a dead test/jne phi shunt.
//
// First 81 bytes match exactly (relocations masked by the tool are not real diffs).
// The 4-byte insert at offset 0x51 shifts the remaining code; the final 4 bytes of
// the 102-byte window are the shifted-out padding (difference in padding bytes only).
// edit diff = 7.84% (all from the 4-byte insert + corresponding tail deletion).
// positional diff = 16.67% (also from 4-byte insert cascade).
//
// No source/flag workaround found. Probes from multiple prior sessions (LemonLily,
// GraniteCub) tried: if/else/ternary/goto/comma/volatile/while/for/switch/null-normalization
// patterns; no /O flag variant eliminates the artifact for this +ctor SEH pattern.
//
// Accepted as same behavior-neutral no-op phi-merge artifact as sibling init helpers.
// Prefix TU pass: migrated to the shared canonical tworld context without changing
// the reviewed drift or the six exact anchors.

#ifndef TWORLD_PHASE2_CONTEXT
#include "../../include/tworld_prefix_context.h"
#endif

void TRIBE_World::setup_gaia() {
    TRIBE_Gaia* g;
    g = new TRIBE_Gaia(this, (RGE_Master_Player*)this->master_players[0], 0, "GAIA", 0);
    if (g == 0) {
        g = 0;
    }
    this->players[0] = g;
}
