// TRIBE_Map::tribe_clean_elevation
// VA: 005110E0, tmap.cpp:1067-1087
// Status: PARKED in scratch - VC5 register allocation (esi vs edi swap)
//
// Attempt log:
// v0: Basic implementation, extern "C" set_terrain → 181 bytes, 31% diff
// v1: Member function set_terrain → 176 bytes, register issues
// v2: Local vars, while+goto loop structure → 12% positional diff
// v3: Direct param manipulation → 12%, same register swap
// v4: Short variable names (xc, tr, row, etc.) → 12%, same issue
// Retry 2026-05-26 Boss pass: 16 more probes. Revalidated current scratch (181B,
// 22 positional / 25 edit, first mismatch +3). Tried for/positive outer loop,
// direct row expressions, pointer rowbase, self alias/register self, parameter-slot reuse,
// no-continue forms, x-local before self, register x local, self declared after clips,
// x_start2 temp, and reloading x from the parameter slot. All non-regressing variants
// stayed in the same this-vs-x register swap family; attempts to force x into EDI and
// this into ESI regressed broadly (~150 positional). No accepted_drift proposal because
// although behavior is equivalent, the diff is a whole-function register-coloring swap.
//
// Remaining diff: 22 bytes / 12% positional
// All diffs are from register swap: original uses esi=this, edi=x;
// rebuild uses edi=this, esi=x. Everything else (loop structure, field
// accesses, set_terrain call) matches perfectly.
//
// Struct layout:
//   RGE_Map: gap_00[8], map_width(+8), map_height(+C), gap_10[0x8D7C],
//            map_row_offset(+0x8D8C), gap_8D90[0x30], game_world(+0x8DC0)
//   TRIBE_Map: extends RGE_Map, no fields accessed here
//
// Size: 181 bytes, ret 10h

struct RGE_Map {
    char gap_00[8];
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    int* map_row_offset;
    char gap_8D90[0x30];
    int game_world;

    void set_terrain(int world, int x, int y, int a, int b, int c);
};

struct TRIBE_Map : RGE_Map {
    char gap_8DC4[0x2E34];

    unsigned char water(unsigned char elevation);
    unsigned char do_terrain_brush_check(int x, int y);
    void tribe_clean_elevation(int x_start, int y_start, int x_end, int y_end);
};

void TRIBE_Map::tribe_clean_elevation(int x_start, int y_start, int x_end, int y_end) { if(x_start<0){ x_start=0; } if(y_start<0) y_start=0; if(x_end>=map_width) x_end=map_width-1; if(y_end>=map_height) y_end=map_height-1; for(; y_start<=y_end; ++y_start){ if(x_start<=x_end){ int xc=x_start; int row=xc*24; do{ int* tr=(int*)map_row_offset[y_start]; unsigned char tb=*((unsigned char*)tr+row+5); unsigned char elev=tb&0x1F; if(water(elev)){ if(!do_terrain_brush_check(xc,y_start)){ set_terrain(game_world,xc,y_start,0,0,0); } } xc++; row+=24; }while(xc<=x_end); } } }
