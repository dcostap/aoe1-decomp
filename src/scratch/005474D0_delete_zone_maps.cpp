#include <stdlib.h>

#ifndef ZONE_MAP_TU_BUILD
class RGE_Zone_Map {
public:
    ~RGE_Zone_Map();
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    long zone_map_num;

    void delete_zone_maps();
};
#endif

void RGE_Zone_Map_List::delete_zone_maps()
{
    if (this->zone_maps == 0 || this->zone_map_num <= 0) {
        return;
    }
    for (long i = 0; i < this->zone_map_num; i++) {
        RGE_Zone_Map* zm = this->zone_maps[i];
        if (zm != 0) {
            delete zm;
        }
    }
    free(this->zone_maps);
    this->zone_maps = 0;
    this->zone_map_num = 0;
}
