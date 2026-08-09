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
// FLAGS: config/flags/005473B0_get_zone_map.rsp (/GX with default /O2 /Oy)

#include <stdlib.h>
#include <string.h>

class RGE_Map;

class RGE_Zone_Map {
public:
    char _size[0x51c];

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
