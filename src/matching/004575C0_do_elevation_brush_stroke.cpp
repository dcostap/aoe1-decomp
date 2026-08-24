// VA 004575C0 RGE_Map::do_elevation_brush_stroke
// map.cpp:1318-1391
// Attempt log:
// 1: Replaced the placeholder with the period-plausible map.cpp stroke: halve
//    the radius, clip endpoints, interpolate with x87 doubles, invoke the
//    virtual elevation brush, then clean the expanded clipped rectangle.
// 2: Factored cleanup into one common call and reused the reversed-endpoint
//    parameter homes; this preserved the exact 0x24 frame and reduced drift
//    to 77 bytes.
// 3: Mutating the clipped endpoint parameters directly, with scoped old-value
//    temporaries for reversed strokes, reproduced all 395 oracle bytes.

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

    void clean_elevation(long x1, long y1, long x2, long y2,
                         unsigned char elevation);
};

#endif

unsigned char RGE_Map::do_elevation_brush_stroke(long x0, long y0, long x1,
                                                  long y1, long radius,
                                                  unsigned char elevation)
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

    this->do_elevation_brush(x0, y0, radius, elevation);
    if (index > 0) {
        long count = index;
        do {
            x = step_x + x;
            y = step_y + y;
            this->do_elevation_brush((long)x, (long)y, radius, elevation);
            --count;
        } while (count != 0);
    }

    if ((double)x1 != x || (double)y1 != y)
        this->do_elevation_brush(x1, y1, radius, elevation);

    if (x0 < x1) {
        x0 -= radius;
        x1 += radius;
    } else {
        long temp_x = x0;
        x0 = x1 - radius;
        x1 = temp_x + radius;
    }
    if (y0 < y1) {
        y0 -= radius;
        y1 += radius;
    } else {
        long temp_y = y0;
        y0 = y1 - radius;
        y1 = temp_y + radius;
    }
    this->clean_elevation(x0, y0, x1, y1, elevation);

    return 1;
}
