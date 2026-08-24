// VA: 00547180 RGE_Zone_Map_List::RGE_Zone_Map_List(int, RGE_Map*) (183 B)
// PDB source: zone_map.cpp
// attempt: natural /GX loading constructor using rge_read, calloc, and new RGE_Zone_Map.

#include <stdlib.h>

#ifndef ZONE_MAP_TU_BUILD
class RGE_Map;

class RGE_Zone_Map {
public:
    char _size[0x51c];
    RGE_Zone_Map(int file, RGE_Map* map);
};

void rge_read(int handle, void* buffer, int count);
void* calloc(size_t num, size_t size);

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;  // +0x00
    int zone_map_num;          // +0x04
    RGE_Map* map;              // +0x08

    RGE_Zone_Map_List(int file, RGE_Map* map);
};
#endif

RGE_Zone_Map_List::RGE_Zone_Map_List(int file, RGE_Map* map)
{
    this->zone_maps = 0;
    this->map = map;
    rge_read(file, &this->zone_map_num, 4);

    if (this->zone_map_num > 0) {
        this->zone_maps = (RGE_Zone_Map**)calloc(this->zone_map_num, 4);
        for (int i = 0; i < this->zone_map_num; i++) {
            this->zone_maps[i] = new RGE_Zone_Map(file, this->map);
        }
    } else {
        this->zone_maps = 0;
    }
}
