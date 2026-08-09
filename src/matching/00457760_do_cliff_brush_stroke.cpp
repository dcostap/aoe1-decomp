// VA: 00457760 RGE_Map::do_cliff_brush_stroke
// map.cpp lines 1401-1445
//
// The stroke clips its endpoints to the map, computes the integer-length
// interpolation count, invokes the virtual cliff brush at the first point and
// each interpolated point, then emits the clipped endpoint when needed.
//
// Attempt log:
// - Baseline uses the proven RGE_Map virtual prefix and typed long/byte ABI,
//   with natural double interpolation and parameter-home clipping.
// - `(double)dx * dx + (double)dy * dy` moved the distance calculation into
//   the target x87 basin; the integer-squared spelling did not.
// - A separate natural `count = index` inside the positive-count arm moved
//   the loop/count homes and reduced drift from 224 to 20 bytes.
// - Updating x before y reduced the remaining drift to 17 bytes; reversing
//   the commutative add operands was a codegen duplicate.
// - A volatile-count diagnostic changed the frame and was rejected.  The
//   validated best remains 316 bytes with all six calls/CFG aligned; the
//   remaining 17 bytes are the initial x87 local spill/order sequence.
// - Mirroring the exact terrain-stroke donor's distance/step/position
//   declaration and initialization order reduced the gap to five bytes.
// - Declaring count inside the positive index arm delayed its stack store past
//   the test and produced an exact 316-byte match.
// Main-agent audit confirmed canonical map virtual ownership and retained the
// natural clipped interpolation source.

#include <math.h>

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int file);
    virtual void load_random_map(char* a, char* b, char* c, char* d);
    virtual unsigned char do_terrain_brush(long x, long y, long radius,
                                           unsigned char terrain);
    virtual unsigned char do_terrain_brush_stroke(long x0, long y0, long x1,
                                                  long y1, long radius,
                                                  unsigned char terrain);
    virtual unsigned char do_elevation_brush(long x, long y, long radius,
                                              unsigned char elevation);
    virtual unsigned char do_elevation_brush_stroke(long x0, long y0, long x1,
                                                    long y1, long radius,
                                                    unsigned char elevation);
    virtual unsigned char do_cliff_brush(long x, long y, unsigned char a,
                                         unsigned char b);
    virtual unsigned char do_cliff_brush_stroke(long x0, long y0, long x1,
                                                long y1, unsigned char a,
                                                unsigned char b);

    char gap_04[0x4];
    long map_width;
    long map_height;
};

unsigned char RGE_Map::do_cliff_brush_stroke(long x0, long y0, long x1,
                                              long y1, unsigned char a,
                                              unsigned char b)
{
    if (x0 < 0)
        x0 = 0;
    if (x1 >= this->map_width)
        x1 = this->map_width - 1;
    if (y0 < 0)
        y0 = 0;
    if (y1 >= this->map_height)
        y1 = this->map_height - 1;

    long x_distance = x1 - x0;
    long y_distance = y1 - y0;
    long index;
    double step_x;
    double step_y;
    double x;
    double y;
    index = (long)sqrt((double)x_distance * x_distance +
                       (double)y_distance * y_distance);
    step_x = (double)x_distance / (double)index;
    step_y = (double)y_distance / (double)index;
    x = (double)x0;
    y = (double)y0;

    this->do_cliff_brush(x0, y0, a, b);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_cliff_brush((long)x, (long)y, a, b);
            --count;
        } while (count != 0);
    }

    if ((double)x1 != x || (double)y1 != y)
        this->do_cliff_brush(x1, y1, a, b);

    return 1;
}
