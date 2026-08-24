// 00511000 TRIBE_Map::do_terrain_brush_check(long x, long y)
// Source: tmap.cpp lines 1029-1063
// Size: 223 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: EXACT MATCH
//
// Attempt log:
// Probe 1 (prev session): tile = map_row_offset[y] + x with tile_up/tile_down locals
//   - 78% match; register allocation edx for map_row_offset instead of eax
//   - Loads y first (from [esp+8]) instead of x first (from [esp+4])
// Probe 2 (prev session): split tile = rows[y]; tile += x; — same result
// Probe 3 (this session): tile = x + map_row_offset[y] — identical output (commutative)
// Probe 4 (this session): inline tile_up/tile_down arithmetic (no named locals),
//   matching the PDB line bands (line 1040 covers computation+check).
//   RESULT: EXACT MATCH (0.0000%). The named tile_up/tile_down locals shifted
//   register allocation (x->esi instead of edx, extra mov ebp,eax in up-block,
//   +2 bytes). Inline CSE'd expressions recover the original basin. Matches
//   LESSONS.md "Inline repeated row-address expressions to avoid base-pointer
//   liveness".
//
// Key findings:
// - RGE_Map: map_width(+0x08), map_height(+0x0C), map_row_offset(+0x8D8C)
// - TRIBE_Map inherits from RGE_Map
// - RGE_Tile: 0x18 bytes, tile_type at +0x04 (the flag checked)
// - 8 neighbor checks: left, right, up(center+diagonals), down(center+diagonals)
// - All early-return paths have inline epilogues (return 0 with pop/pop/pop/pop/ret)
// - Single return 1 path at end with mov al,1
// - No sub esp (no stack locals), just 4 push/pop for register saves
// - ret 8 = 2 params x 4 bytes
// - Tile computation: lea edi,[x + x*2]; lea edi,[row_ptr + edi*8] = x * 24
// - Row offset: tile - map_width -> tile above; tile + map_width -> tile below
// - map_width is loaded once and cached in ebx (= map_width - 1)
// - y is reloaded from stack ([esp+18h]) after esi is repurposed
// - ecx (this) is overwritten with map_height at line 1050
//
// Exact match achieved with inline (tile - map_width) / (tile + map_width)
// expressions in the checks; named tile_up/tile_down locals perturbed VC5
// register allocation (see attempt log).

#ifndef TMAP_GROUP_CONTEXT
struct RGE_Tile {
    short screen_xpos;         // +0x00
    short screen_ypos;         // +0x02
    unsigned char tile_type;   // +0x04
    char pad_05[0x18 - 0x05]; // rest of tile (total 0x18 = 24 bytes)
};

class RGE_Map {
public:
    void* vtable_ptr;           // +0x00
    RGE_Tile* map;              // +0x04
    long map_width;             // +0x08
    long map_height;            // +0x0C
    long world_width;           // +0x10
    long world_height;          // +0x14
    char pad_18[0x8D8C - 0x18]; // skip to map_row_offset
    RGE_Tile** map_row_offset;  // +0x8D8C
};

class TRIBE_Map : public RGE_Map {
public:
    unsigned char do_terrain_brush_check(long x, long y);
};
#endif

unsigned char TRIBE_Map::do_terrain_brush_check(long x, long y)
{
    RGE_Tile* tile = map_row_offset[y] + x;

    if (x > 0 && tile[-1].tile_type != 0)
        return 0;

    if (x < map_width - 1 && tile[+1].tile_type != 0)
        return 0;

    if (y > 0) {
        if ((tile - map_width)->tile_type != 0)
            return 0;
        if (x > 0 && (tile - map_width)[-1].tile_type != 0)
            return 0;
        if (x < map_width - 1 && (tile - map_width)[+1].tile_type != 0)
            return 0;
    }

    if (y < map_height - 1) {
        if ((tile + map_width)->tile_type != 0)
            return 0;
        if (x > 0 && (tile + map_width)[-1].tile_type != 0)
            return 0;
        if (x < map_width - 1 && (tile + map_width)[+1].tile_type != 0)
            return 0;
    }

    return 1;
}
