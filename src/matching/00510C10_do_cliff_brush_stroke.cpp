// 00510C10 TRIBE_Map::do_cliff_brush_stroke
// first pass: direct offsets, signed /3 tests, base delegation.

class RGE_Map {
public:
    unsigned char do_cliff_brush_stroke(long a, long b, long c, long d, unsigned char e, unsigned char f);
};

class TRIBE_Map : public RGE_Map {
public:
    char gap_00[0x8DE4];
    int old_cliff_x;
    int old_cliff_y;
    int safe_cliff_x;
    int safe_cliff_y;
    int old_cliff_direction;

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
