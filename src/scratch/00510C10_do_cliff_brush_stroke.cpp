// 00510C10 TRIBE_Map::do_cliff_brush_stroke
// Source: tmap.cpp lines 923-935
// Size: 125 bytes
//
// Attempt log:
// Probe 1: natural C++ with base delegation

class RGE_Map {
public:
    char _gap_00[4];
    unsigned char do_cliff_brush_stroke(long a, long b, long c, long d, unsigned char e, unsigned char f);
};

class TRIBE_Map : public RGE_Map {
public:
    int old_cliff_x;            // +0x8DE4
    int old_cliff_y;            // +0x8DE8
    int safe_cliff_x;           // +0x8DEC
    int safe_cliff_y;           // +0x8DF0
    int old_cliff_direction;    // +0x8DF4

    unsigned char do_cliff_brush_stroke(long a, long b, long c, long d, unsigned char e, unsigned char f);
};

unsigned char TRIBE_Map::do_cliff_brush_stroke(long a, long b, long c, long d, unsigned char e, unsigned char f)
{
    if (this->safe_cliff_x != a / 3 || this->safe_cliff_y != b / 3) {
        this->old_cliff_x = -1;
        this->old_cliff_y = -1;
        this->safe_cliff_x = -1;
        this->safe_cliff_y = -1;
        this->old_cliff_direction = -1;
    }
    RGE_Map::do_cliff_brush_stroke(a, b, c, d, e, f);
    return 1;
}
