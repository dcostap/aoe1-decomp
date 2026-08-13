// VA: 005473B0 RGE_Zone_Map_List::get_zone_map(float *, long, int &)
// PDB source: zone_map.cpp lines 529-556
//
// Attempt log:
// - Baseline natural typed list scan/new/memcpy source: 281 B, 267 differing bytes;
//   VC5 peeled the first check_info call and emitted one extra call site.
// - Guarded while scan restored the original five-call topology and 266 B size:
//   37 differing bytes, with the first mismatch isolated to the hit-path epilogue.
// - Result-local/common-goto, named check result, direct constructor assignment,
//   destructor declaration, direct-return, and break/if-else variants did not
//   improve the 37-byte family; the named check result widened the body to 270 B.
// - Variant loop lab (while/for/do, default source context) found no size/call-set
//   eligible improvement. Restored the direct guarded-while source.
// - Final validated drift: rebuilt hit path restores EDI before storing the output
//   index and has a duplicated cleanup, while the original keeps EDI live and jumps
//   back to the shared epilogue at 00547485. Left in scratch; no inline asm or
//   compiler-only scaffolding retained.
// - This TU-aware pass tried a result/goto common label (including reversed hit
//   assignment order) and a break/post-loop hit branch; both were worse or kept
//   the same duplicated EH cleanup. Restored the guarded-while reconstruction.
// - Fresh same-TU layout/EH pass: the full RGE_Zone_Map field surface and
//   destructor ownership were compiled with the donor /GX context; both emitted
//   the same 37-byte family. Result/goto, explicit result, cold-label, comma,
//   old-count, and shared-array-return forms were diagnostic only; the clean
//   guarded-while allocation source remains the best natural reconstruction.
// FLAGS: config/flags/005473B0_get_zone_map.rsp (/GX with default /O2 /Oy)
// Main-agent audit retained the natural typed cache growth and nonvirtual
// zone-map lifetime surface; no EH-tail steering survives.
// - Follow-up donor pass confirmed the constructor-proven full zone-map layout
//   and same-TU list ownership; the first 183 bytes remain exact.
// - Hit return indexing through zone_map_index, initialized/shared result
//   locals, declaration-order changes, and separate index initialization all
//   emitted the same 266-byte family. An infinite-loop break widened the
//   structural drift to 197 bytes and was rolled back.
// - Typed lookup probe bound this->zone_maps[i] to a local RGE_Zone_Map*
//   before check_info and returned that pointer on a hit; it widened the
//   body to 269 bytes and lost early exact blocks. Restored the clean source.
// - Explicit found-label/common-result ordering, captured check_info result,
//   do-while scan, and removal of the outer count guard were tested; the first
//   and last emitted the same 266-byte family, while the captured/do-while
//   forms widened or duplicated the check. Restored the guarded while source.

#include <stdlib.h>
#include <string.h>

class RGE_Map;

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    unsigned char* zone_map;
    unsigned char** zone_map_rows;
    unsigned char zone_info[257];
    char gap_50D[3];
    float* terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map* map;

    RGE_Zone_Map(RGE_Map* map, float* terrain_info, long terrain_info_num);
    ~RGE_Zone_Map();
    RGE_Zone_Map* check_info(float* terrain_info, long terrain_info_num);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;  // +0x00
    long zone_map_num;         // +0x04
    RGE_Map* map;              // +0x08

    RGE_Zone_Map* get_zone_map(float* terrain_info, long terrain_info_num,
                               int& zone_map_index);
};

RGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(
    float* terrain_info, long terrain_info_num, int& zone_map_index)
{
    int i = 0;
    RGE_Zone_Map** new_zone_maps;

    if (this->zone_map_num > 0) {
        while (i < this->zone_map_num) {
            if (this->zone_maps[i]->check_info(terrain_info, terrain_info_num) != 0) {
                zone_map_index = i;
                return this->zone_maps[i];
            }
            i++;
        }
    }

    new_zone_maps = (RGE_Zone_Map**)calloc(this->zone_map_num + 1, 4);
    if (this->zone_maps != 0) {
        memcpy(new_zone_maps, this->zone_maps, this->zone_map_num * 4);
        free(this->zone_maps);
    }
    new_zone_maps[this->zone_map_num] =
        new RGE_Zone_Map(this->map, terrain_info, terrain_info_num);
    this->zone_maps = new_zone_maps;
    this->zone_map_num++;
    zone_map_index = this->zone_map_num - 1;
    return new_zone_maps[this->zone_map_num - 1];
}
