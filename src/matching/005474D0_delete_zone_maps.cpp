#include <stdlib.h>

class RGE_Zone_Map {
public:
    void destructor();
};

void operator_delete(void*);

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;
    int zone_map_num;

    void delete_zone_maps();
};

void RGE_Zone_Map_List::delete_zone_maps() {
    if (zone_maps == 0 || zone_map_num <= 0) {
        return;
    }
    for (int i = 0; i < zone_map_num; i++) {
        RGE_Zone_Map* zm = zone_maps[i];
        if (zm != 0) {
            zm->destructor();
            operator_delete(zm);
        }
    }
    free(zone_maps);
    zone_maps = 0;
    zone_map_num = 0;
}
