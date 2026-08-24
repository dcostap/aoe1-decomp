// VA: 0050FD40 TRIBE_Map::do_terrain_brush_stroke — EXACT MATCH
// Source: tmap.cpp lines 356-396
// FLAGS: /nologo /c /O2 /Oy
//
// Key matching insight:
// 1. RGE_Map::do_terrain_brush_stroke is a non-virtual base class member function
//    (direct call, not virtual dispatch).
// 2. tribe_clean_terrain must be a MEMBER function (__thiscall, callee cleanup ret 18h),
//    NOT an extern/C-style function (which would generate __cdecl with add esp, 1Ch).
// 3. Parameter reuse (modifying p1-p4 directly via the conditional swap logic) matches
//    the original's register allocation for EDI, EBX, EBP, EAX.
// 4. The conditional swap uses the brush size (p5 = ESI) to adjust min and max coords
//    before the final call to tribe_clean_terrain.

#ifndef TMAP_GROUP_CONTEXT
class RGE_Map {
public:
    unsigned char do_terrain_brush_stroke(long p1, long p2, long p3, long p4, long p5, unsigned char p6);
};

class TRIBE_Map : public RGE_Map {
public:
    unsigned char do_terrain_brush_stroke(long p1, long p2, long p3, long p4, long p5, unsigned char p6);
    void tribe_clean_terrain(int x1, int y1, int x2, int y2, int flag, unsigned char terrain);
};
#endif

unsigned char TRIBE_Map::do_terrain_brush_stroke(long p1, long p2, long p3, long p4, long p5, unsigned char p6) {
    RGE_Map::do_terrain_brush_stroke(p1, p2, p3, p4, p5, p6);

    if (p1 < p3) {
        p1 -= p5;
        p3 += p5;
    } else {
        int tmp = p1;
        p1 = p3 - p5;
        p3 = tmp + p5;
    }

    if (p2 < p4) {
        p2 -= p5;
        p4 += p5;
    } else {
        int tmp = p2;
        p2 = p4 - p5;
        p4 = tmp + p5;
    }

    tribe_clean_terrain(p1 - 2, p2 - 2, p3 + 2, p4 + 2, 1, p6);
    return 1;
}
