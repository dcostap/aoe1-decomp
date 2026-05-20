// do_terrain_brush
// VA: 00457320
// map.cpp lines 1205-1230
// Retry 2026-05-20 Boss pass: exact match found by switching to explicit while-loop
// cursors after computing natural x/y bounds. The matched shape keeps row/column
// cursors as long locals and lets VC5 assign ESI/EBP/EBX like the original.

#include "../../include/game_globals.h"

class RGE_Map {
public:
    char gap_00[8];
    int map_width;      // +0x08
    int map_height;     // +0x0C
    char gap_10[0x8DC0 - 0x10];
    void* game_world;   // +0x8DC0

    void set_terrain(void* world, int x, int y, unsigned char terrain, int a, int b);
    unsigned char do_terrain_brush(long x, long y, long radius, unsigned char terrain);
};

unsigned char RGE_Map::do_terrain_brush(long x, long y, long radius, unsigned char terrain)
{
    long rad = radius;
    long x1 = x - rad;
    long x2 = x + rad;
    long y1 = y - rad;
    long y2 = y + rad;

    if (x1 < 0)
        x1 = 0;
    if (x2 >= this->map_width)
        x2 = this->map_width - 1;
    if (y1 < 0)
        y1 = 0;
    if (y2 >= this->map_height)
        y2 = this->map_height - 1;

    long row = y1;
    while (row <= y2) {
        long col = x1;
        while (col <= x2) {
            this->set_terrain(this->game_world, col, row, terrain, 0, 0);
            ++col;
        }
        ++row;
    }
    return 1;
}
