#ifndef ZONE_MAP_TU_BUILD
class RGE_Zone_Map {
public:
    char gap_00[0x408];
    unsigned char** zone_map_rows;

    unsigned char get_zone_info(long param1, long param2);
};
#endif

unsigned char RGE_Zone_Map::get_zone_info(long param1, long param2) {
    return zone_map_rows[param2][param1];
}
