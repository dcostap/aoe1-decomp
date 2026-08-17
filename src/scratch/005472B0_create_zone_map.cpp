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
// - follow-5472B0-r1: direct constructor-result assignment and direct truth
//   testing matched the exact donor style but emitted no change.
// - follow-5472B0-r1: a scoped allocation block with one final return restored
//   the shared-tail shape but caused 203 bytes of broad drift; rolled back.
// - This TU pass restored the decompiler-supported index assignment before
//   the hit return. The explicit zero test is codegen-duplicate, but the
//   natural assignment form reduces the body to 265B and a 37-byte diff.
//   Kept it as the best readable reconstruction; shared EH teardown remains.
// - Replaced the equivalent ternary with a failure-only assignment. VC5
//   emitted the same 265B/37-byte result, so the clearer form remains.
// - shardE-5472B0: explicit success self-assignment and failure assignment
//   emitted the same 265B/37-byte result; rolled back.
// - shardE-5472B0: explicit placement-new construction removed the EH
//   registration and produced a 240-byte diff; rolled back.
// - shardE-5472B0: removing the destructor declaration was codegen-duplicate.
//   Function-scope pointer/goto and void-result/goto forms both produced the
//   known 203-byte prologue/stack-home drift; restored the clean source.
// - sa47e4-create-zone-map: inverted single-final-return hit/create condition
//   changed the loop body and produced 226 bytes of drift; restored.
// - sa47e4-create-zone-map: one function-scope allocation pointer with a
//   shared goto reproduced the known 203-byte alternate EH basin; restored.
// - sa47e4-create-zone-map: clean source remains best; original CFG requires
//   a shared EH epilogue, while all natural shared-return forms perturb the
//   prologue or allocation body.
// - sa-f59bec2e-r1: separate return, scoped-goto, shared-index, postincrement,
//   and register-index probes did not improve the natural source. The exact-
//   flag return-form sweep found no size-eligible match. Restored clean source.
// - sa-8c6ed4de-r1: a single-return break plus allocation guard produced a
//   228-byte drift. A one-iteration allocation scope was codegen-duplicate.
//   A function-scope typed map pointer with direct new assignment preserved
//   size but produced the known 203-byte prologue/register basin; declaration
//   order did not change it. Restored the clean typed source.
// - sa-83e45bf9-r1: defining the binary-proven nonvirtual zone-map destructor
//   selected the original shared EH teardown and produced an exact body.
//   This form is rejected because VA 005469C0 owns the destructor. The current
//   single-function build has no policy-valid shared-TU mapping.

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
            if (this->zone_maps[i]->do_zone_map() != 0)
                return i;
            i = -1;
            return i;
        }
    }

    RGE_Zone_Map** new_zone_maps =
        (RGE_Zone_Map**)calloc(this->zone_map_num + 1, sizeof(RGE_Zone_Map*));
    if (this->zone_maps != 0) {
        memcpy(new_zone_maps, this->zone_maps,
               this->zone_map_num * sizeof(RGE_Zone_Map*));
        free(this->zone_maps);
    }

    RGE_Zone_Map* new_zone_map =
        new RGE_Zone_Map(this->map, table, count);
    new_zone_maps[this->zone_map_num] = new_zone_map;
    this->zone_maps = new_zone_maps;
    this->zone_map_num++;
    return this->zone_map_num - 1;
}
