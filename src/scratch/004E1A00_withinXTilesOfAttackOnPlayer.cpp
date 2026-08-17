// 004E1A00 TribeInformationAIModule::withinXTilesOfAttackOnPlayer
// Source: taiinfmd.cpp lines 6682-6716, size 233 bytes
//
// Attempt log:
// - Initial state: struct missing `type` at +0x04 (minX at +4 instead of +5,
//   stride 0x0C instead of 0x18) and an explicit `if (max <= 0) return 0;`
//   guard before the for loop -> rebuilt 219 bytes, redundant double guard
//   (test edi,edi; jle twice) and wrong field offsets.
// - Probe 1 (baseline): canonical AttackMemory layout from exact donor
//   004E1190 (type at +0x04, minX..targetOwner at +5..+0A, stride 0x18),
//   dropped explicit guard (VC5 for-loop guard covers it), natural dy/dx
//   reassignment checks. Now: rebuilt 211B vs 233B; struct offsets, stride,
//   call set, and 4-check register-reuse pattern (dy1=edi reused by check4)
//   all correct. Remaining drift is register allocation only: original spills
//   the loop counter to the param_1 slot ([esp+18h]) with am=edx (this stays
//   esi), tilesSq=ebp/tx=ebx, push ecx local; rebuilt keeps counter in eax,
//   am=esi (clobbers this), tilesSq=ebx/tx=ebp, no local. Matched sibling
//   004E1AF0 has the identical push-ecx/tilesSq=ebp prologue basin.
//   Next leads (untried): pointer-walk `AttackMemory* am = attackMemories`
//   declared before the loop; one-line `long dy=..., dx=...` declaration
//   (PDB line map attributes both statements to line 6694); indexed
//   `attackMemories[i]` access without the am local; hoisting this-based
//   reloads to keep `this` live in the loop body.
// - Follow-up probes: direct indexed access, split/compound square setup,
//   separate loop-counter/max locals, hoisted pointer declaration, and
//   one-line/long dy/dx declarations all emitted the same 211-byte basin.
//   A scoped pointer walk changed topology and worsened to 204 bytes; restored.
//   Modeling the proven InformationAIModule base changed only register/layout
//   scheduling (71.7% shape), so the narrow field-offset surface is retained.
// - Completed AttackMemory ownership/layout from ground truth: unsigned byte
//   fields, +0x0B padding, timestamp at +0x10, play at +0x14, total 0x18.
//   Final validated clean source remains natural indexed scan with shared
//   continue/increment path. Calls and touched offsets are correct; remaining
//   drift is the VC5 allocator basin (counter home, am/this coloring, and
//   tilesSq/tx register swap), not a known behavior or layout mismatch.
// - Main-agent normalization retained the proven InformationAIModule base and
//   canonical inheritance boundary; emitted code is unchanged.
// - Session probe: natural positive-count if/do-while around the indexed scan
//   worsened to 204 bytes with an extra CFG return; restored the clean for-loop.
// - Session probes: a natural positive-count do/while with a carried
//   AttackMemory pointer worsened to 204 bytes; an indexed nested positive gate
//   with a short-circuit four-corner expression reached 206 bytes but lost the
//   original CFG island; both were restored. Grouped coordinate declarations,
//   a dead target-parameter zero assignment, and an early loop-counter
//   declaration all emitted the same 211-byte basin. No source/layout/call
//   lead displaced the canonical indexed scan; remaining drift is the known
//   VC5 allocator/stack-home basin.
// - Fresh bounded pass: split eligibility guards, signed-char AttackMemory
//   declarations, a positive combined guard, a reference record alias, and a
//   Win32-long loop index all emitted the same 211-byte basin; restored.
// - Canonical full TribeInformation surface (+F0 ManagedArray/md), reversed
//   first sum terms, and coordinate declaration experiments were nonexact;
//   swapping y/x improved edit resync only (142 vs 187) while losing an exact
//   block, so the original x-then-y source was restored.
// - Variant lab (36 natural declaration/loop/access/sum combinations): no
//   exact or size/frame/call-set eligible result; emitted groups were 211 or
//   197 bytes. Clean source remains the typed indexed scan; unresolved drift
//   is allocator/stack-home coloring (counter, pointer/this, square/x).
// - Fresh lease baseline confirmed the clean 211-byte basin. A max local with
//   a positive cursor guard reached 219 bytes but added a CFG edge; a max plus
//   cursor for-loop stayed 211 bytes. Both were restored.
// - Named module owner/max/memory locals reached 214 bytes and lost exact
//   blocks. A donor-supported <stdlib.h> include, flat class layout, and an
//   address-taken index were unchanged or worse; the last was optimized away.
//   Separate max/base locals reached 214 bytes and were restored.
// - Refreshed assembly-donor search found the exact taiinfmd.cpp sibling
//   004E1AF0 prologue and confirmed the remaining gap is the target's distinct
//   allocator/stack-home basin, not a missing call or known layout fact.
// - Reassessment probes: a positive do/while with a carried cursor worsened
//   to 204 bytes and changed the CFG; top-level counter initialization inside
//   the positive guard added a duplicate bound test (219 bytes).  Restored.
// - Reassessment probes: moving the squared-range declaration after the
//   coordinate conversions reached 211 bytes with diff 218 but did not improve
//   structure; direct repeated member indexing, explicit this-based pointer
//   arithmetic, and top-level declaration reordering were codegen duplicates.
//   A for update ordered cursor before counter kept 211 bytes but lost an exact
//   block.  Restored the clean indexed scan.
// - Current lease baseline confirmed the clean 211-byte basin.  A natural
//   long loop copy inside the positive-count guard worsened to 204 bytes and
//   changed the loop CFG; it was restored.  No new lead remains within this
//   bounded pass.
// - Fresh bounded probes tested register-qualified tiles, a cached max local,
//   function-scoped dy/dx and AttackMemory declarations, explicit this-qualified
//   indexing, a flat class surface, a top-tested carried-pointer while loop,
//   const/long coordinate locals, and a hoisted pointer assignment. All natural
//   forms duplicated the 211-byte basin except the while form, which worsened
//   structural alignment. The clean indexed scan remains authoritative.
// - Revisit probes: a positive-count indexed do/while reached 204 bytes and
//   changed the loop CFG; an AttackMemory reference, named max copy, and y-before-x
//   declaration were duplicate 211-byte codegen. A function-scope memory alias
//   reached 214 bytes and hoisted the base load before the count guard.
// - Revisit probe: a carried-pointer positive do/while reached 204 bytes and
//   changed the record-gate CFG. Original PDB symbols show i/objY home aliases,
//   while the Ghidra lead uses a pointer walk and parameter-home counter. Those
//   forms are not retained because policy forbids raw cursor and home reuse.
// - Fresh revisit: an early initialized i local reached 221 bytes and 85.1%
//   shape with a local counter, but it did not recover the original parameter
//   home or EDX cursor; declaration-order variants and split guards duplicated
//   or worsened the clean 211-byte basin. Pointer-for and positive-gate forms
//   also changed CFG or size. Restored the natural indexed scan.
// - Revisit audit (current clean baseline, 220 strict bytes in 10 spans):
//   +00..+27 crosses the prologue and first max load; the missing push-ecx
//   local, parameter-home shift, and tiles/target register colors cause it.
//   +29..+3E crosses max-load tail, coordinate-home stores, the zero counter,
//   local max, and the initial JLE; the baseline has no pushed max local and
//   uses different homes. +41..+4A is the memory-base load and owner test;
//   the baseline reuses ESI for the cursor instead of retaining this in ESI
//   with the cursor in EDX. +4C..+9F is the player test and four corner
//   calculations; the source behavior and call set match, but the threshold,
//   x/y homes, byte-load registers, and square accumulators use another
//   allocator basin. +A2, +A4, +A6, and +A8 are isolated bytes inside the
//   max-X accumulator and branch encodings; they are not independent source
//   statements. +AA..+E8 covers the final corner, max reload, loop update,
//   three epilogues, and the rebuilt short tail; the baseline lacks the
//   original counter/max home pair and the push-ecx/pop-ecx epilogue shape.
//   Calls, direct targets, field offsets, stride, and return CFG behavior
//   remain aligned. No probe found a supported source lead for the allocator
//   basin. All 20 fresh probes were restored to this clean source.
// - Revisit pass: 20 new evidence-led probes tested source context, real
//   headers, object and base surfaces, counter lifetime, geometry declaration
//   order, and named square lifetimes. Most forms duplicated the 211-byte
//   basin. The best valid source names `dySquared` and `dxSquared` and carries
//   those values across the four corner checks. It emits 233 bytes, matches the
//   original boundary, and restores the push-ecx local plus five exact blocks.
// - BINARY NOTE: The improved source matches the original bytes through +2C.
//   The remaining first mismatch swaps the `ty` and `i` parameter-home stores
//   at +2D and +33. The original reloads `ty` before each needed subtraction.
//   The improved source keeps `ty` in EAX and avoids those reloads. This is a
//   register and home-allocation difference, not a proven behavior difference.
// - Revisit result: 233-byte rebuild, 144 strict-byte difference, 16 spans,
//   200 equal bytes, two ordered __ftol calls, and three returns. The semantic
//   square-local source is pinned as the clean reconstruction. No raw cursor,
//   home alias, volatility, helper, wrapper, or compiler steering is retained.

class RGE_Static_Object {
public:
    virtual void v00();
    int id;                              // +0x04
    char gap_08[0x38 - 0x08];
    float world_x;                       // +0x38
    float world_y;                       // +0x3C
};

struct AttackMemory {
    int id;                 // +0x00
    unsigned char type;              // +0x04
    unsigned char minX;              // +0x05
    unsigned char minY;              // +0x06
    unsigned char maxX;              // +0x07
    unsigned char maxY;              // +0x08
    unsigned char attackingOwner;    // +0x09
    unsigned char targetOwner;       // +0x0A
    unsigned char gap_0B;            // +0x0B
    short kills;            // +0x0C
    unsigned char success;  // +0x0E
    unsigned char gap_0F;   // +0x0F
    unsigned long timeStamp; // +0x10
    int play;               // +0x14
};

class InformationAIModule {
public:
    virtual ~InformationAIModule();
    char gap_04[0xEC];
};

// Main-agent audit confirmed canonical typed attack-memory ownership and kept
// the ordinary indexed proximity scan.
class TribeInformationAIModule : public InformationAIModule {
public:
    char gap_F0[0x1FC - 0xF0];
    int maxAttackMemories;               // +0x1FC
    AttackMemory* attackMemories;        // +0x200

    int withinXTilesOfAttackOnPlayer(RGE_Static_Object* target, int tiles, int playerId);
};

int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(
    RGE_Static_Object* target, int tiles, int playerId)
{
    int tilesSq = tiles * tiles;
    int tx = (int)target->world_x;
    int ty = (int)target->world_y;

    for (int i = 0; i < maxAttackMemories; i++) {
        AttackMemory* am = &attackMemories[i];
        if (am->id == -1 || !am->attackingOwner || (unsigned char)am->targetOwner != playerId)
            continue;

        int dy = (unsigned char)am->minY - ty;
        int dx = (unsigned char)am->minX - tx;
        int dySquared = dy * dy;
        int dxSquared = dx * dx;
        if (dySquared + dxSquared <= tilesSq) return 1;

        dy = (unsigned char)am->maxY - ty;
        dySquared = dy * dy;
        if (dySquared + dxSquared <= tilesSq) return 1;

        dx = (unsigned char)am->maxX - tx;
        dxSquared = dx * dx;
        if (dySquared + dxSquared <= tilesSq) return 1;

        dy = (unsigned char)am->minY - ty;
        dySquared = dy * dy;
        if (dySquared + dxSquared <= tilesSq) return 1;
    }

    return 0;
}
