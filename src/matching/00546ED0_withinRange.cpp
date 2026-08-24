#ifndef ZONE_MAP_TU_BUILD
struct XYPoint {
    int x;
    int y;
};

class RGE_Zone_Map {
public:
    char gap_00[0x408];
    unsigned char** zone_map_rows;

    int withinRange(unsigned char zone, XYPoint from, float range);
    int withinRange(XYPoint point, XYPoint from, float range);
};
#endif

int RGE_Zone_Map::withinRange(XYPoint point, XYPoint from, float range) {
    return withinRange(this->zone_map_rows[point.y][point.x], from, range);
}
