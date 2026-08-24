// VA: 004573C0 RGE_Map::do_terrain_brush_stroke
// map.cpp lines 1234-1280
//
// This is the terrain analogue of the neighboring cliff stroke: halve the
// terrain brush radius, clip endpoints, walk the integer-length interpolation,
// invoke the virtual terrain brush at each point, and finish at the clipped
// endpoint when interpolation does not land exactly there.
//
// Attempt log:
// - Baseline reuses the proven map.cpp virtual prefix and the best natural
//   clipped interpolation shape from do_cliff_brush_stroke.
// - Declaring integer x/y distances before the step and position doubles
//   recovered the target x87 spill order to a 5-byte mismatch.
// - Keeping `long count = index` inside the positive-count guard (after its
//   test) reproduced the target test/store order and reached an exact match.
// - Main-agent audit confirmed canonical map virtual ownership and natural
//   clipped interpolation; exact bytes were revalidated after promotion.

#include <math.h>

#ifndef MAP_CONTEXT_H
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

#endif

unsigned char RGE_Map::do_terrain_brush_stroke(long x0, long y0, long x1,
                                                long y1, long radius,
                                                unsigned char terrain)
{
    radius >>= 1;

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

    this->do_terrain_brush(x0, y0, radius, terrain);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_terrain_brush((long)x, (long)y, radius, terrain);
            --count;
        } while (count != 0);
    }

    if ((double)x1 != x || (double)y1 != y)
        this->do_terrain_brush(x1, y1, radius, terrain);

    return 1;
}
