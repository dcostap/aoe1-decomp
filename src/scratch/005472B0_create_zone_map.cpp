// VA: 005472B0 RGE_Zone_Map_List::create_zone_map (248 bytes)
// PDB source: zone_map.cpp lines 495-523
//
// Attempt log:
// - baseline candidate: natural cache lookup, reallocating the zone-map
//   pointer array with memcpy/free, then constructing a new RGE_Zone_Map.
// - default flags omit the original EH registration and produce 211 bytes;
//   donor-like /GX restores the exact 248-byte main path.
// - /GX natural early-return and ternary forms both retain duplicated cleanup
//   tails (55 strict bytes, first mismatch at the early-return epilogue).
// - common-goto/result and nested/function-scope declaration variants add a
//   local stack home and broadly perturb the otherwise exact body; reversed
//   guards do not remove the EH-tail drift.
// - the known nonvirtual RGE_Zone_Map destructor is declared for the canonical
//   type surface; it does not change the remaining emitted drift.
// - This TU-aware pass tested reusing the scan index through a shared done label
//   and a post-loop hit/create if-else. Moving declarations for the goto changed
//   the EH prologue; the if-else changed call/block layout. Restored the natural
//   direct ternary source.
// FLAGS: /nologo /c /O2 /Oy /GX
// Main-agent audit retained natural typed cache lookup/growth and nonvirtual
// zone-map lifetime ownership; no shared-tail steering survives.
// - SA6731d1e6 bounded probes: assignment plus branch-local return reached a
//   diagnostic 37-byte diff but emitted a 265-byte late epilogue; block-local
//   and function-scope goto forms introduced broad prologue/stack-home drift.
//   Break/sentinel, while, explicit-result/switch, and <new.h> context probes
//   did not improve the clean source; two VC5 variant labs found no exact case.
// - orch-005472B0-L: shared done-label forms with block/function-scope,
//   void, register, and initialized allocation pointers all added an EH
//   scratch slot and produced a 203-byte drift. A break-based common return
//   produced 228 bytes. The assignment-plus-return form remains the best
//   diagnostic at 37 bytes, but its duplicated hit cleanup is less plausible
//   than the clean natural ternary source.
// - final clean reconstruction remains the natural typed cache lookup/growth;
//   current unresolved drift is the original shared EH teardown versus VC5's
//   duplicated hit-path cleanup (55 strict bytes, first mismatch at +00D0).
// - orch2-5472B0-layout: replaced the opaque 0x51c body with the constructor-
//   proven named field layout; codegen and structural metrics were unchanged.

#include <stdlib.h>
#include <string.h>

class RGE_Map;
typedef unsigned char uchar;

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

    RGE_Zone_Map(RGE_Map* map, float* table, long count);
    ~RGE_Zone_Map();
    RGE_Zone_Map* check_info(float* table, long count);
    unsigned char do_zone_map();
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    long zone_map_num;
    RGE_Map* map;

    long create_zone_map(float* table, long count);
};

long RGE_Zone_Map_List::create_zone_map(float* table, long count)
{
    long i;

    for (i = 0; i < this->zone_map_num; i++) {
        if (this->zone_maps[i]->check_info(table, count) != 0) {
            return this->zone_maps[i]->do_zone_map() ? i : -1;
        }
    }

    RGE_Zone_Map** new_zone_maps =
        (RGE_Zone_Map**)calloc(this->zone_map_num + 1, 4);
    if (this->zone_maps != 0) {
        memcpy(new_zone_maps, this->zone_maps, this->zone_map_num * 4);
        free(this->zone_maps);
    }

    RGE_Zone_Map* new_zone_map =
        new RGE_Zone_Map(this->map, table, count);
    new_zone_maps[this->zone_map_num] = new_zone_map;
    this->zone_maps = new_zone_maps;
    this->zone_map_num++;
    return this->zone_map_num - 1;
}
