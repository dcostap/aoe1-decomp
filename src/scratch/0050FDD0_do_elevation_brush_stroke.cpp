/*
 * 0050FDD0 TRIBE_Map::do_elevation_brush_stroke (tmap.cpp:400-439)
 *
 * Virtual unsigned char method with 6 params (long x1, long y1, long x2, long y2, long r, uchar c).
 * Calls RGE_Map::do_elevation_brush_stroke base, then adjusts x1/x2 and y1/y2 boundaries
 * based on comparisons and (r + c), then calls tribe_clean_elevation and tribe_clean_terrain.
 *
 * Remaining drift: persistent VC5 register-allocation basin.
 *
 * Attempt history:
 * - Initial: direct else-branch with local temps → 89.8% pos_diff, wrong register mapping
 * - Using ox1/oy1 save-orig approach → 70.7% pos_diff, still wrong register mapping
 * - Variant lab (36 probes): c_form × x_else_form × y_else_form axes
 *   No exact matches found; best group G0006 (save_orig for both branches): 73 pos_diff, 
 *   first mismatch at offset 13 (parameter loading).
 * - All 36 variants produce the same register allocation: r assigned to esi instead of ebx,
 *   x1 to edi instead of esi, x2 to ebx instead of edi.
 * - Follow-up tries: explicit locals in 6 declaration orders, r local before/after base call,
 *   self-assign/casts, precomputing r+c, /Od, and vc5-risky variant lab (432 variants).
 *   None reached the original load basin; best remained first mismatch offset 13 / edit 88.
 * - This is a stable VC5 codegen basin: VC5's heuristic chooses different callee-saved
 *   registers for the same parameter set regardless of source structure changes.
 *
 * Left in scratch: remaining ~73-byte drift is register allocation and equivalent address
 * arithmetic/scheduling (esi↔ebx↔edi swap for x1/x2/r). Behavior, call set, stack cleanup,
 * and conditional logic all match. Potential accepted_drift candidate only after reviewer
 * confirms broad register-renaming drift is acceptable.
 *
 * Luna50FDD0 pass (10 meaningful probes): dossier/donor/ABI evidence confirmed the
 * canonical six-argument member surface. register-qualified parameters, commutative
 * r+c order, inline unsigned promotion, int radius, and staged radius/byte updates did
 * not recover the entry basin (staged form worsened to 97 diff bytes; promotion to 87).
 * Removing local virtual keywords improved the diagnostic to 78 bytes and matched more
 * body blocks, but contradicts the PDB virtual surface and did not change the EBX/ESI/EDI
 * parameter coloring; derived-only virtual context worsened to 157 bytes. Restored the
 * period-plausible virtual source. Remaining lead is TU/compiler register allocation:
 * original assigns r/x1/x2 to EBX/ESI/EDI while the clean rebuild assigns x2/r/x1 to
 * EBX/ESI/EDI. Calls, cleanup, CFG, and 188-byte boundary remain aligned.
 *
 * orch-luna-50fdd0-w1 fresh pass (10 meaningful probes): tested Ghidra-shaped int endpoint
 * locals (145-byte diff), corrected virtual-vtable field/slot surfaces (no codegen change),
 * a persistent promoted-byte local after the x-axis (80-byte diagnostic, one byte better),
 * the same promotion before both axes (149-byte diff), x2-only and paired x1/x2 register
 * qualifiers (no change), and a mixed x-output-local/y-parameter model (141-byte diff).
 * The canonical direct-parameter virtual source was restored; no exact lead emerged. The
 * remaining mismatch is still the stable entry register coloring (oracle r/x1/x2 = EBX/ESI/EDI;
 * clean rebuild = ESI/EDI/EBX roles), with calls, cleanup, CFG, and size aligned.
 *
 * Source-plausibility audit: removed the duplicate explicit vtable field and the empty
 * base/helper definitions. The target now uses the smallest declaration-only polymorphic
 * surfaces; direct-call and helper symbol declarations remain explicit.
 *
 * sa-e4d7ed85-50fdd0 pass: top-level x/y swap temporaries, restored full RGE virtual
 * prefix, and radius register qualification were all codegen duplicates (81-byte diff).
 * Restored clean source; the only remaining lead is the known VC5 entry coloring basin.
 *
 * orch-tmap-01 fresh pass: corrected tribe_clean_terrain to the executable two-uchar
 * EE ABI (no emitted-byte change); reversed x/y comparison operands, parenthesized
 * explicit endpoint assignments, const-qualified radius, a named cleanup self alias,
 * and the proven full RGE_Map/TRIBE_Map layout (all duplicates or worse). A 729-variant
 * natural expression/branch lab found no exact output; its best size-gated group retained
 * the same entry coloring and had an appended context tail. The clean direct-parameter
 * source remains the defensible reconstruction; oracle r/x1/x2 are EBX/ESI/EDI while
 * VC5 emits ESI/EDI/EBX. Calls, corrected relocations, cleanup, CFG, and size align.
 *
 * orch-tmap-fresh-04 continuation: a promoted-byte local before the base call
 * worsened the build to 162 bytes; a pre-base receiver alias was a codegen
 * duplicate. Splitting saved-endpoint declarations from assignments and hoisting
 * those saves to function scope were also duplicates. Restored the clean direct
 * parameter source; the 81-byte result and first mismatch at +0x0D remain.
 *
 * wave21-tmap-01 bounded endpoint pass: a 4-variant x/y forward-assignment-order
 * lab and a 16-variant branch-local r+c-span lab found no exact output or entry
 * coloring change; only the all-inline form kept size/call invariants. A 2-variant
 * four-result-local declaration-timing lab stayed at 165 bytes, so the natural
 * direct-parameter source was retained. Materializing c after base delegation
 * worsened to 149 bytes. Reusing one shared reverse-arm temp and aliasing x1/x2
 * only in the base call both emitted the clean 81-byte basin (the latter in a
 * 4-variant lab). Restored the pinned canonical source; endpoint coloring remains
 * oracle r/x1/x2=EBX/ESI/EDI versus rebuild ESI/EDI/EBX.
 *
 * SA84a32a3f pass: same-width int formals, broad register hints, complete RGE/TRIBE
 * virtual/size context, and reverse-arm expression variants were neutral or worse.
 * Mutating x1/y1/x2/y2 by +/-2 before the two cleanup calls recovered the oracle
 * callee-save coloring, exact 188-byte size, and 182/188 bytes (7 effective bytes
 * remain in reverse-arm instruction ordering). The best source keeps ordinary
 * direct endpoint expansion and explicit common cleanup-bound mutation; the residual
 * sub/load ordering is localized to x/y reverse arms. A final explicit unsigned-byte
 * cast probe worsened to 18 bytes and was rolled back.
 *
 * orch2-50FDD0-order pass: sequential r-then-c updates in both reverse arms were
 * codegen duplicates; a separate computed x1 value was also a duplicate. Reordering
 * both reverse arms to apply both r updates before c worsened the result to 27 bytes.
 * Restored the pinned 7-byte clean source; call ABI, behavior, and cleanup calls stay
 * unchanged.
 * follow-50FDD0-r1 probe 1: explicit long promotion for the reverse-arm byte term,
 * based on the RGE elevation donor's typed long endpoint arithmetic; codegen duplicate,
 * so the clean direct-byte source remains authoritative.
 * follow-50FDD0-r1 probe 2: register-qualified reverse endpoint temporaries, testing
 * whether the RGE donor's local temporary declaration controls the remaining move order;
 * codegen duplicate, so ordinary long locals remain authoritative.
 * tu-tmap-50FDD0 probe 1: two-result reverse-arm locals were natural but moved the
 * base-call join and widened the mismatch to 126 bytes; restored the clean source.
 * sa99_elevation_brush probes: splitting reverse-arm radius and byte updates on both
 * axes worsened the localized mismatch to 27 bytes; x-only splitting worsened it to
 * 17 bytes. Grouped and explicitly long-promoted reverse expressions, int saved-endpoint
 * locals, and a 9-case x/y expression lab all kept the same clean 7-byte output.
 * Restored the pinned direct typed source. The remaining bytes are the x/y reverse-arm
 * subtraction ordering: the oracle subtracts r before c, while VC5 emits c before r.
 * sa-48616227 continuation: independently split the reverse x/y updates and delayed
 * the x endpoint declaration. Both probes were codegen duplicates. Restored the pinned
 * source; the 7-byte reverse-arm ordering drift remains.
 * sa-5d91df15 pass: reverse compound updates, endpoint swaps, parenthesized radius-plus-byte
 * terms, and a late reverse-x byte local were duplicates or much worse. Explicit unsigned-int
 * byte promotion improved one block but widened the complete result to 18 bytes. Restored
 * the pinned natural source; no simple source form changed the 7-byte ordering drift.
 * sa-3fda77e1 pass: tested split reverse updates, operand order, unsigned-int promotions,
 * shared byte locals, endpoint declaration scope, and result locals. Reverse-x promotion
 * made its block exact but changed reverse-y register colors; hoisted endpoint storage
 * corrected only the other block. Combined forms stayed at 18 bytes or worse. Restored
 * the pinned natural source; final validation remains the 7-byte reverse-arm drift.
 */

class RGE_Map {
public:
    virtual unsigned char do_elevation_brush_stroke(long x1, long y1, long x2, long y2, long r, unsigned char c);
};

class TRIBE_Map : public RGE_Map {
public:
    virtual unsigned char do_elevation_brush_stroke(long x1, long y1, long x2, long y2, long r, unsigned char c);
    void tribe_clean_elevation(long x1, long y1, long x2, long y2);
    void tribe_clean_terrain(long x1, long y1, long x2, long y2, unsigned char a, unsigned char b);
};

unsigned char TRIBE_Map::do_elevation_brush_stroke(long x1, long y1, long x2, long y2, long r, unsigned char c) {
    RGE_Map::do_elevation_brush_stroke(x1, y1, x2, y2, r, c);

    if (x1 < x2) {
        x1 -= r + c;
        x2 += r + c;
    } else {
        long ox1 = x1;
        x1 = x2 - r - c;
        x2 = ox1 + r + c;
    }

    if (y1 < y2) {
        y1 -= r + c;
        y2 += r + c;
    } else {
        long oy1 = y1;
        y1 = y2 - r - c;
        y2 = oy1 + r + c;
    }

    x1 -= 2;
    y1 -= 2;
    x2 += 2;
    y2 += 2;
    tribe_clean_elevation(x1, y1, x2, y2);
    tribe_clean_terrain(x1, y1, x2, y2, 1, 0);
    return 1;
}
