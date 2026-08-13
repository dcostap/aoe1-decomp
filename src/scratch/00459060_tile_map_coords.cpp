// VA: 00459060 RGE_Map::tile_map_coords
// PDB source: map.cpp lines 2269-2364
// attempt log:
// 1: initial high-level decompiler-shaped switch using double intermediates; compiled same size but 73.34% positional diff, first mismatch frame 0x10 vs 0x08.
// 2: added dummy volatile double stack pressure; no change, VC5 optimized it away / same diff.
// 3: used gotos for shared case tails (case0/case5/case6/case7/case8/add_fy); recovered overall size but FPU scheduling/block family remains broad mismatch.
// 4: preserved original switch over tile->tile_type and double literals; jump table present but expression basin differs widely.
// 5: restored the binary-proven raw y intermediate: cases 3, 15, and 16 compare
//    the unnormalized y value while the final geometry uses y/tile_height.
// 6: explicit z declaration/assignment and register qualification emitted the same code.
// 7: moving the final normalization into/around the switch default emitted the same code.
// 8: duplicating switch arms without shared labels moved farther; restored the shared-label source.
// 9: inverted case 1 to the natural greater-than coordinate test; preserved behavior and improved the first x87 branch hunk, but structural size drift remains.
// 10: split the branch result from the final normalized output and used a float output local; improved size, FPU output duplication, and exact-block coverage.
// 11: changed case 4's diagonal guard to the raw y intermediate proven by the original fcomp [esp+8]; added an exact block, with positional drift +5.
// 12: merged the branch result into the original-looking double z local and
//     made final normalization self-assignment; diff 650 -> 654, rolled back.
// 13: replaced shared gotos with natural switch breaks and duplicated outcomes
//     for compiler tail merging; diff 650 -> 724 and size +64, rolled back.
// 14: split the float branch result from the double qword tile result.  Store
//     the branch value only at z_result, matching the original fstp join;
//     diff 650 -> 393 and code size/frame now match.
// 15: spelled case 2 as fx > half; this matched the original fld st1/fcomp
//     order and improved the structural diff to 383.
// 16: moved case 3's diagonal gate before its result load; this recovered the
//     original compare line band and improved the diff to 356.
// 17: typed diagonal/y temporaries and a negative-first case-10 branch were
//     tested for block placement; both worsened positional output and rolled back.
// 18: reversing the case-3 comparison operands was a codegen duplicate; kept
//     the period-plausible fx*half < raw_y spelling.
// left in scratch: exact source expression/FPU stack shaping remains under test.

struct RGE_Tile { int pad0; unsigned char tile_type; };

extern double DAT_005706c0;
extern double DAT_005706d0;
extern double DAT_005706d8;

class RGE_Map {
public:
    char pad_00[0x8D96];
    short tile_width;
    short tile_height;
    void tile_map_coords(short x, short y, RGE_Tile* tile, float* out1, float* out2);
};

void RGE_Map::tile_map_coords(short x, short y, RGE_Tile* tile, float* out1, float* out2) {
    double fx = (double)(int)x / (double)(int)this->tile_width;
    register float result;
    double raw_y = (double)(int)y;
    double fy = raw_y / (double)(int)this->tile_height;
    double z = 0.0;

    switch (tile->tile_type) {
    case 1:
        if (fx > DAT_005706c0) result = (fy + fy) - ((fx - DAT_005706c0) + (fx - DAT_005706c0));
        else result = (fy + fy) - ((DAT_005706c0 - fx) + (DAT_005706c0 - fx));
        goto z_result;
    case 2:
        if (fx > DAT_005706c0) { result = fx * DAT_005706d0 - (fy - DAT_005706c0); goto z_result; }
        goto tile_case8;
    case 3:
        if (fx * DAT_005706c0 < raw_y) { result = (DAT_005706d8 - fx) * DAT_005706c0 - (fy - DAT_005706c0); goto z_result; }
        result = DAT_005706d8 - fx;
        fy = fy + fy;
        result = (result + result) - DAT_005706d8;
        goto add_fy;
    case 4:
        if ((DAT_005706d8 - fx) * DAT_005706c0 < raw_y) { result = fx * DAT_005706c0 - (fy - DAT_005706c0); goto z_result; }
        goto tile_case7;
    case 10:
        if (DAT_005706d8 <= fy) z = -1.0;
        else { result = -fy; goto z_result; }
        goto default_result;
    case 11:
        if (fx <= DAT_005706c0) { result = (DAT_005706c0 - fx) + (DAT_005706c0 - fx); goto z_result; }
        goto tile_case0;
    case 12:
        if (DAT_005706c0 < fx) { result = (fx - DAT_005706c0) + (fx - DAT_005706c0); goto z_result; }
    case 0:
    case 9:
 tile_case0:
        z = 0.0;
        goto default_result;
    case 13:
        if (fx <= DAT_005706c0) result = ((DAT_005706c0 - fx) + fy) + ((DAT_005706c0 - fx) + fy);
        else result = ((fx - DAT_005706c0) + fy) + ((fx - DAT_005706c0) + fy);
        goto z_result;
    case 14:
        if (fx <= DAT_005706c0) goto tile_case6;
        goto tile_case8;
    case 15:
        if (raw_y <= DAT_005706d8 - fx * DAT_005706c0) goto tile_case7;
        goto tile_case8;
    case 8:
 tile_case8:
        result = (DAT_005706d8 - fx) * DAT_005706d0 - (fy - DAT_005706c0);
        goto z_result;
    case 7:
 tile_case7:
        fy = fy + fy;
        result = (fx + fx) - DAT_005706d8;
 add_fy:
        result = result + fy;
        goto z_result;
    case 16:
        if (DAT_005706d8 - (DAT_005706d8 - fx) * DAT_005706c0 < raw_y) goto tile_case6;
        goto tile_case5;
    case 6:
 tile_case6:
        result = fx * DAT_005706d0 - (fy - DAT_005706c0);
        goto z_result;
    case 5:
 tile_case5:
        result = fy + fy;
        fy = DAT_005706d8 - (fx + fx);
        goto add_fy;
 z_result:
    z = result;
 default_result:
 default:
        {
            float normalized = (float)((((fx + fx) - (DAT_005706d8 - (fy + fy))) + z) * DAT_005706c0);
            *out2 = normalized;
            *out1 = (float)((fx + fx) - normalized);
        }
        break;
    }
}
