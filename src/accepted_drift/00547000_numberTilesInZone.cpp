// target: VA 00547000 RGE_Zone_Map::numberTilesInZone(unsigned char)
// Attempt log:
// - Baseline: canonical zone-cache ownership and natural nested width/height scan;
//   121 of 122 bytes match. The only gap is the byte-compare SIB encoding.
// - Access-shape lab: pointer casts, pointer-add forms, integer address adds,
//   and x+0 all emit the same [ecx+edi] encoding.
// - Named row-value and widened row-pointer probes optimize to the same bytes.
// - Volatile byte access changes the whole frame and CFG; it was rolled back.
// - Restored same-TU RGE_Map vptr and complete RGE_Zone_Map member surface;
//   no emitted-code change. Double-negated equality also stayed duplicate.
// - Final clean source uses the full period-plausible member surface. Remaining
//   drift is one commutative SIB byte: original [edi+ecx], rebuilt [ecx+edi].
// ACCEPTED_DRIFT: behavior, frame, registers, stack slots, loops, and all other
// bytes match. Both SIB forms address the same byte and have the same effects.

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
                    if (((unsigned char*)x)[(unsigned int)(*row)] == zone) {
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
