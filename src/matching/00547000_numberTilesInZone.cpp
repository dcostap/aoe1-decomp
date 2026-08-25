// VA: 00547000 RGE_Zone_Map::numberTilesInZone(unsigned char)
// BINARY NOTE: The authentic zone_map.cpp context restores the original SIB
// operand order for the natural row-and-column access.

#ifndef ZONE_MAP_TU_BUILD
class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    int map_width;
    int map_height;
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];
    unsigned char* zone_map;
    unsigned char** zone_map_rows;
    unsigned char zone_info[257];
    char gap_50D[3];
    float* terrain_passability_rules;
    int terrain_passability_rules_num;
    RGE_Map* map;

    int numberTilesInZone(unsigned char zone);
};
#endif

int RGE_Zone_Map::numberTilesInZone(unsigned char zone) {
    int* cached;
    int width;
    int height;
    int x;
    int count;

    cached = &this->numberTilesInZoneValue[(unsigned int)zone];
    if (*cached > 0) {
        return *cached;
    }

    width = this->map->map_width;
    height = this->map->map_height;
    count = 0;
    x = 0;
    if (width > 0) {
        do {
            if (height > 0) {
                unsigned char** row = this->zone_map_rows;
                int y = height;
                do {
                    if ((*row)[x] == zone) {
                        count++;
                    }
                    row++;
                    y--;
                } while (y != 0);
            }
            x++;
        } while (x < width);
    }
    *cached = count;
    return count;
}
