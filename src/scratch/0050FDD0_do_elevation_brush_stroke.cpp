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
 */

class RGE_Map {
public:
    void* vtable_ptr;

    virtual unsigned char do_elevation_brush_stroke(long x1, long y1, long x2, long y2, long r, unsigned char c);
};

class TRIBE_Map : public RGE_Map {
public:
    virtual unsigned char do_elevation_brush_stroke(long x1, long y1, long x2, long y2, long r, unsigned char c);
    void tribe_clean_elevation(long x1, long y1, long x2, long y2);
    void tribe_clean_terrain(long x1, long y1, long x2, long y2, int a, int b);
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

    tribe_clean_elevation(x1 - 2, y1 - 2, x2 + 2, y2 + 2);
    tribe_clean_terrain(x1 - 2, y1 - 2, x2 + 2, y2 + 2, 1, 0);
    return 1;
}

unsigned char RGE_Map::do_elevation_brush_stroke(long x1, long y1, long x2, long y2, long r, unsigned char c) { return 0; }
void TRIBE_Map::tribe_clean_elevation(long x1, long y1, long x2, long y2) { }
void TRIBE_Map::tribe_clean_terrain(long x1, long y1, long x2, long y2, int a, int b) { }
