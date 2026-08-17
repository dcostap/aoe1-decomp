#include <math.h>

// Attempt log:
// - Baseline: canonical RGE_Zone_Map layout with bounded XYPoint scan; 259B.
// - Recovered the binary's guarded do/while topology and live x/y indices; 247B.
// - sqrtf preserves the observed fsqrt/fcomp float-range comparison; remaining
//   drift is local register scheduling in max construction and the outer tail.
// - This assignment's probes swapped lower-bound declarations, split/rewrote
//   max additions, tried an outer do/while, and materialized x_distance squared;
//   the latter improved block alignment but widened the body, while the others
//   were duplicate or worse. Restored the simplest typed reconstruction.
// - Paused after the bounded 10-hypothesis matching assignment.
// - Follow-up control-flow probes found that a bounded for-body with
//   x_distance = from.x - x and an invariant x_squared reproduces the target
//   loop/tail topology; the direct max.y-then-max.x source order then reduced
//   the rebuilt function to 247 bytes and a 15-byte localized diff.
// - A late aggregate max initializer regressed the prologue and was rolled
//   back. Final best natural source retains named XYPoint ownership and the
//   bounded scan; remaining drift is the max-construction register/SIB shape.
// - Follow-up lease probes tested upper-bound assignment order, a map pointer
//   alias, the donor polymorphic map surface, add-term order, scalar bounds,
//   map dimension locals, stdlib context, declaration order, and post-guard
//   aggregate initialization. The first four were duplicates; the rest were
//   worse. Restored the clean 247-byte source; the 15-byte hunk remains local.
// - Tested donor-backed x_value/y_value aliases for every bound and distance
//   term, with declarations before max as in 00547080; emitted code was a
//   duplicate. Restored the clean source.
// - Follow-up closeout tested reversed coordinate-alias declaration order and
//   the donor's XYPoint min aggregate; both were duplicates. Natural max.x-
//   first arithmetic widened the body to 248B with or without that aggregate.
//   Restored this clean source; no codegen-only alias or aggregate remains.
// - This TU pass retested direct max.x-then-max.y assignment order against the
//   clean source; it widened the body to 248B and produced a 196-byte diff.
//   Restored the clean max.y-then-max.x source; the 15-byte max-bound hunk
//   remains the only exact-codegen gap.
// - Tested a computed XYPoint max aggregate initializer from the same-TU
//   donor-backed point ownership; it widened the body to 248B and produced a
//   196-byte diff. Restored the direct field assignments.
// - Reassessment retested the same-TU max.x-then-max.y source with max-first
//   declaration, coordinate aliases, mixed/compound additions, reversed terms,
//   and long radius. Each widened to 248B and a 196-byte diff; the comma lower
//   declaration was a duplicate of that basin.
// - Reversed lower-bound declaration order moved the first mismatch to the
//   parameter loads and reached 214B diff. Donor-polymorphic RGE_Map context,
//   including get_terrain, did not change the x-first basin. Restored the clean
//   direct max.y-then-max.x source; no policy-clean lead remains.
// - Related-donor follow-up retested the exact 00547080 RGE_Map surface,
//   named y aliases, split lower-bound initialization, XYPoint min ownership,
//   compound max additions, scalar bounds, and aggregate max copying. The
//   donor surface and natural aliases were duplicates; scalar and aggregate
//   forms were worse. Restored the clean 247B source and 15-byte hunk.
// - Revisit probes tested the exact donor local shape, scalar max temporaries,
//   int versus long map bounds, an XYPoint parameter copy, long radius, and
//   long XYPoint coordinates. The typed/liveness variants were duplicate or
//   worse. Restored the pinned natural source; the max-register hunk remains.
// - This revisit ran a 35-variant source lab over natural coordinate aliases,
//   declaration order, max assignment order, compound additions, and aggregate
//   copies. It found four emitted groups and no exact candidate; the 247-byte
//   group remained the 15-byte mismatch. Focused PDB-informed x-first and
//   declaration-grouping probes were 196-byte variants or duplicates. A full
//   period-plausible RGE_Zone_Map declaration surface was also a duplicate.
//   Restored the clean source; final validation remains a 247-byte mismatch
//   with one localized max-register/SIB hunk at +0x1B.
// - Revisit probes isolated the four strict spans: the original loads the
//   y-coordinate into EBX, then keeps it for max.y; the clean source loads it
//   into EDX and lets VC5 choose EBX for the y bound. The original computes
//   max.x into EDX and stores both max fields after loading map. Tested max
//   declaration order, one-coordinate aliases, field references, const radius,
//   reversed add terms, a scoped map alias, and windows.h context. They were
//   duplicates or 196-byte variants. Restored and validated the pinned source;
//   the natural 247-byte frontier and 15 strict bytes remain.
// - Canonical ownership audit: the type dump gives XYPoint two int fields at
//   +0/+4 and RGE_Map long dimensions at +0x8/+0xC behind its vptr. The target
//   symbol is EUXYPoint with ret 10h and direct stack field loads, proving a
//   by-value struct, not a reference or split ints. Exact callers construct
//   XYPoint start/goal locals and pass them by value; the ABUXYPoint donor is a
//   different reference ABI. Canonical RGE_Map, RGE_Zone_Map, constructor,
//   destructor, overload, and neighboring-method surfaces all duplicated the
//   15-byte frontier. The reference probe reached 258B/230B diff; split ints
//   reached a 0x10 frame and 39B diff. No canonical ownership lead maps y to
//   EBX naturally. Restored baseline.
// - Independent bound/order lab compiled 18 natural variants. Direct y-first
//   bounds remained the only 247B/15-byte group. PDB lines 335 and 336 cover
//   the two max-coordinate additions, while exact same-TU
//   findClosestPointInTerrainType uses x-first max fields and direct
//   map_width - 1/map_height - 1 clamps. That donor supports an x-first
//   hypothesis, but the target PDB has no source text to name those fields.
//   X-first target variants were 248B with a 196-byte diff; reversed and
//   equivalent bound comparisons changed the hunk or the CFG and did not
//   recover EBX. No source comparison order is behaviorally forced here.
// - Signedness/intermediate lab compiled 48 combinations (32 successful
//   extractions, 16 size/frame/call-set eligible). Grouped radius/minimum
//   declarations, long and unsigned radius forms, signed casts, an aggregate
//   max, and comparison-order forms produced no exact candidate. The target's
//   signed jge/jg/jle branches and signed imul agree with the pinned int
//   coordinates, int radius, and long map fields. No natural intermediate or
//   signedness change explains from.y in EBX.
// - Exact same-TU checks remain MATCH for 00546ED0 (44B) and 00547080
//   (249B); exact caller 0045F820 also remains MATCH (419B). These prove the
//   by-value XYPoint ABI and donor field ownership, but their natural aliases
//   do not transfer a register color to this function. Preserve the clean
//   by-value baseline; the remaining 15 bytes are a register/SIB scheduling
//   basin, not a recovered semantic defect.

typedef unsigned char uchar;

struct XYPoint {
    int x;
    int y;
};

struct RGE_Map {
    char gap_00[0x08];
    long map_width;
    long map_height;
};

// Main-agent audit confirmed canonical zone-map field ownership and retained
// the ordinary bounded range scan.
class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    uchar* zone_map;
    uchar** zone_map_rows;
    uchar zone_info[257];
    char gap_50D[3];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    int withinRange(uchar zone, XYPoint from, float range);
};

int RGE_Zone_Map::withinRange(uchar zone, XYPoint from, float range)
{
    int radius = (int)range;
    int min_x = from.x - radius;
    int min_y = from.y - radius;

    if (min_x < 0)
        min_x = 0;
    if (min_y < 0)
        min_y = 0;

    XYPoint max;
    max.y = from.y + radius;
    max.x = from.x + radius;

    if (max.x > this->map->map_width - 1)
        max.x = this->map->map_width - 1;
    if (max.y > this->map->map_height - 1)
        max.y = this->map->map_height - 1;

    for (int x = min_x; x <= max.x; ++x) {
        int x_distance = from.x - x;
        int y = min_y;
        if (y <= max.y) {
            int x_squared = x_distance * x_distance;
            int y_distance = from.y - min_y;
            do {
                if (sqrtf((float)(x_squared + y_distance * y_distance)) <= range &&
                    this->zone_map_rows[y][x] == zone)
                    return 1;
                ++y;
                --y_distance;
            } while (y <= max.y);
        }
    }
    return 0;
}
