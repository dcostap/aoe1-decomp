#ifndef ZONE_MAP_TU_BUILD
class RGE_Map;

class RGE_Zone_Map_List {
public:
    int zone_maps;
    int zone_map_num;
    RGE_Map* map;

    RGE_Zone_Map_List(RGE_Map* param);
};
#endif

RGE_Zone_Map_List::RGE_Zone_Map_List(RGE_Map* param) {
    map = param;
    zone_maps = 0;
    zone_map_num = 0;
}
