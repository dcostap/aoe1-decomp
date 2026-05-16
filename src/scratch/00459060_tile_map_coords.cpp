// VA: 00459060 RGE_Map::tile_map_coords
// PDB source: map.cpp lines 2269-2364
// attempt log:
// 1: initial high-level decompiler-shaped switch using double intermediates; compiled same size but 73.34% positional diff, first mismatch frame 0x10 vs 0x08.
// 2: added dummy volatile double stack pressure; no change, VC5 optimized it away / same diff.
// 3: used gotos for shared case tails (case0/case5/case6/case7/case8/add_fy); recovered overall size but FPU scheduling/block family remains broad mismatch.
// 4: preserved original switch over tile->tile_type and double literals; jump table present but expression basin differs widely.
// left in scratch: behavior likely close from Ghidra, but exact source expression/FPU stack shaping needs a focused map.cpp source reconstruction or variant lab.

struct RGE_Tile { int pad0; unsigned char tile_type; };

class RGE_Map {
public:
    char pad_00[0x8D96];
    short tile_width;
    short tile_height;
    void tile_map_coords(short x, short y, RGE_Tile* tile, float* out1, float* out2);
};

void RGE_Map::tile_map_coords(short x, short y, RGE_Tile* tile, float* out1, float* out2) {
    double fx = (double)(int)x / (double)(int)this->tile_width;
    volatile double keep_stack;
    double z = 0.0;
    double fy = (double)(int)y / (double)(int)this->tile_height;

    switch (tile->tile_type) {
    case 1:
        if (fx <= 0.5) z = (fy + fy) - ((0.5 - fx) + (0.5 - fx));
        else z = (fy + fy) - ((fx - 0.5) + (fx - 0.5));
        break;
    case 2:
        if (0.5 < fx) { z = fx * -0.5 - (fy - 0.5); break; }
        goto case8;
    case 3:
        z = 1.0 - fx;
        if (fx * 0.5 < fy) { z = z * 0.5 - (fy - 0.5); break; }
        fy = fy + fy;
        z = (z + z) - 1.0;
        goto add_fy;
    case 4:
        if ((1.0 - fx) * 0.5 < fy) { z = fx * 0.5 - (fy - 0.5); break; }
    case 7:
case7:
        fy = fy + fy;
        z = (fx + fx) - 1.0;
add_fy:
        z = z + fy;
        break;
    case 5:
        goto case5;
    case 6:
case6:
        z = fx * -0.5 - (fy - 0.5);
        break;
    case 8:
case8:
        z = (1.0 - fx) * -0.5 - (fy - 0.5);
        break;
    case 10:
        if (1.0 <= fy) z = -1.0;
        else z = -fy;
        break;
    case 11:
        if (fx <= 0.5) { z = (0.5 - fx) + (0.5 - fx); break; }
        goto case0;
    case 12:
        if (0.5 < fx) { z = (fx - 0.5) + (fx - 0.5); break; }
    case 0:
    case 9:
case0:
        z = 0.0;
        break;
    case 13:
        if (fx <= 0.5) z = ((0.5 - fx) + fy) + ((0.5 - fx) + fy);
        else z = ((fx - 0.5) + fy) + ((fx - 0.5) + fy);
        break;
    case 14:
        if (fx <= 0.5) goto case6;
        goto case8;
    case 15:
        if (fy <= 1.0 - fx * 0.5) goto case7;
        goto case8;
    case 16:
        if (1.0 - (1.0 - fx) * 0.5 < fy) goto case6;
case5:
        z = fy + fy;
        fy = 1.0 - (fx + fx);
        goto add_fy;
    default:
        break;
    }
    z = (((fx + fx) - (1.0 - (fy + fy))) + z) * 0.5;
    *out2 = (float)z;
    *out1 = (float)((fx + fx) - z);
}
