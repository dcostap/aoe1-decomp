// target: VA 00547000 RGE_Zone_Map::numberTilesInZone(unsigned char)
// first implementation follows binary-observed cached count scan; parameter is reused as count scratch by VC5.
// matched to 1-byte SIB encoding drift: cmp [edi+ecx],bl original vs [ecx+edi],bl rebuilt.
// tried pointer term-order casts and odd indexed form ((unsigned char*)x)[row]; VC5 still chooses [ecx+edi].
// Additional tries: normal row[x], explicit pointer add both orders, unsigned x, row as int*, volatile row pointer, and flags /Oa /Ob0 /Og /Ot /G5 /O1 /Od. No exact; /O2-family stays in the same 1-byte SIB drift, volatile/low-opt perturb broad register/frame shape.
// ACCEPTED_DRIFT: reviewed by Boss. Behavior, frame, registers, stack slots, loops,
// and all other bytes match. The only differing byte is the SIB encoding for
// commutative base/index addressing of the same byte compare: original `[edi+ecx]`,
// rebuilt `[ecx+edi]`. Same effective address, flags, memory effects, size, and epilogue.

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[256];
    char gap_400[8];
    unsigned char** zone_map_rows;
    char gap_40C[0x10C];
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
