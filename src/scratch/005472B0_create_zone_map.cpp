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
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stdlib.h>
#include <string.h>

class RGE_Map;

class RGE_Zone_Map {
public:
    char data[0x51c];

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
