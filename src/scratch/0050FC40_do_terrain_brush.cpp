// 0050FC40 TRIBE_Map::do_terrain_brush (tmap.cpp:318-352)
// EXACT MATCH
//
// unsigned char __thiscall TRIBE_Map::do_terrain_brush(long x, long y, long r, unsigned char type)
//
// Virtual method. Applies a terrain brush of radius r centered at (x, y).
// For water terrain types, checks each tile with do_terrain_brush_check before setting.
// For non-water types, sets terrain directly across the brush area.
//
// Attempt log:
// - Probe 1: natural variable order, cached game_world in local → 88.7% pos_diff, wrong reg alloc
// - Probe 2: inline game_world access, same order → 88.3% pos_diff, esi=this correct but extra y load
// - Probe 3: local rad = r, adjusted decl order → MATCH (0.0000%)

#ifndef TMAP_GROUP_CONTEXT
class RGE_Map {
public:
    void* vtable;        // +0x00
    void* map;           // +0x04
    long map_width;      // +0x08
    long map_height;     // +0x0C
    long world_width;    // +0x10
    long world_height;   // +0x14
};

class TRIBE_Map : public RGE_Map {
public:
    unsigned char water(unsigned char type);
    unsigned char do_terrain_brush_check(long x, long y);
    void set_terrain(void* game_world, short x, short y, unsigned char type, int a, int b);
    unsigned char do_terrain_brush(long x, long y, long r, unsigned char type);
};
#endif

unsigned char TRIBE_Map::do_terrain_brush(long x, long y, long r, unsigned char type)
{
    long rad = r;
    long start_x = x - rad;
    long end_x = x + rad;
    long start_y = y - rad;
    long end_y = y + rad;

    if (start_x < 0)
        start_x = 0;
    if (end_x >= map_width)
        end_x = map_width - 1;
    if (start_y < 0)
        start_y = 0;
    if (end_y >= map_height)
        end_y = map_height - 1;

    if (water(type)) {
        for (long cy = start_y; cy <= end_y; cy++) {
            for (long cx = start_x; cx <= end_x; cx++) {
                if (do_terrain_brush_check(cx, cy)) {
                    set_terrain(*(void**)((char*)this + 0x8DC0), (short)cx, (short)cy, type, 0, 0);
                }
            }
        }
        return 1;
    }

    for (long cy = start_y; cy <= end_y; cy++) {
        for (long cx = start_x; cx <= end_x; cx++) {
            set_terrain(*(void**)((char*)this + 0x8DC0), (short)cx, (short)cy, type, 0, 0);
        }
    }
    return 1;
}

#ifndef TMAP_GROUP_CONTEXT
// Stubs
unsigned char TRIBE_Map::water(unsigned char type) { return 0; }
unsigned char TRIBE_Map::do_terrain_brush_check(long x, long y) { return 1; }
#endif
void TRIBE_Map::set_terrain(void* game_world, short x, short y, unsigned char type, int a, int b) { }
