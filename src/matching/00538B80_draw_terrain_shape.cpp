// 00538B80 RGE_View::draw_terrain_shape
// Attempt log:
// 1: Natural reconstruction from packet with local stubs for TShape/draw area/fog globals: broad diff; shape table pointer was at +0x1c and x/y offsets were swapped.
// 2: Fix TShape table offset and source x/y offset mapping: table offset fixed, but coordinate local scheduling/registers still wrong.
// 3: Seed draw_y/draw_x locals from params before table lookups: no codegen change.
// 4: Declare draw_x before draw_y to probe saved-register assignment: no useful change.
// 5: Move fog_next_shape assignment before shadow setup in early fog branch: slightly improved edit diff but still wrong top scheduling.
// 6: Use explicit byte-offset table arithmetic for shape frame info: no codegen change.
// 7: Tried /Ob0: no codegen change; removed flag.
// 8: Tried /O1: wrong-size 407-byte function; removed flag.
// 9: Tried /Od: broad 85.17% mismatch from first byte; removed flag.
// 10: Replaced the sketch with typed Shape_Info, RGE_Map, TDrawArea, and view clip-list fields. Restored original x/y for ordinary draws; typed baseline reached a 6-byte diff.
// 11: Declared draw_x before draw_y. VC5 then assigned EDI/EBP like the original; exact 472-byte match.
// Exact: the source uses named shape hotspots, map fog state, and terrain/fog span-list ownership.

#ifndef RGE_VIEW_SHARED_CONTEXT
extern int fog_next_shape;
extern "C" void __cdecl _ASMSet_Shadowing(int a, int b, int c, int d);
#endif

#ifndef RGE_VIEW_SHARED_CONTEXT
class TSpan_List_Manager;

class TDrawArea {
public:
    char gap_00[0xcc];
    TSpan_List_Manager* SpanList;     // +0xcc
    TSpan_List_Manager* CurSpanList;  // +0xd0
};

struct Shape_Info {
    long gap_00[4];
    long Width;        // +0x10
    long Height;       // +0x14
    long Hotspot_X;    // +0x18
    long Hotspot_Y;    // +0x1c
};

class TShape {
public:
    char gap_00[0x1c];
    Shape_Info* shape_info; // +0x1c
    unsigned char shape_draw(TDrawArea* area, long x, long y, long frame,
                             unsigned char color_flag, unsigned char* color_table);
};

class RGE_Map {
public:
    char gap_000[0x8db9];
    unsigned char fog_flag; // +0x8db9
};

class RGE_View {
public:
    char gap_000[0x0f4];
    TDrawArea* draw_area; // +f4
    char gap_0f8[0x104 - 0x0f8];
    RGE_Map* map; // +104
    char gap_108[0x178 - 0x108];
    TSpan_List_Manager* Terrain_Clip_Mask; // +178
    TSpan_List_Manager* Terrain_Fog_Clip_Mask; // +17c

    void draw_terrain_shape(int x, int y, TShape* shape, int frame, unsigned char vis, unsigned char fog_flag, int draw1, int draw2);
};
#endif

void RGE_View::draw_terrain_shape(int x, int y, TShape* shape, int frame, unsigned char vis, unsigned char fog_flag, int draw1, int draw2)
{
    int draw_x = x - shape->shape_info[frame].Hotspot_X;
    int draw_y = y - shape->shape_info[frame].Hotspot_Y;

    if ((fog_flag & 0x10) == 0x10) {
        fog_next_shape = 1;
        _ASMSet_Shadowing(0x00ff00ff, 0x28002800, 0xff00ff00, 0x00280028);
        shape->shape_draw(this->draw_area, draw_x, draw_y, frame, 0, 0);
        _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
        fog_next_shape = 0;
        return;
    }

    if ((fog_flag & 0x20) == 0x20) {
        _ASMSet_Shadowing(0x00ff00ff, 0x56005600, 0xff00ff00, 0x00560056);
    }

    if ((fog_flag & 0x80) == 0x80) {
        int c = fog_flag & 0x0f;
        int value = (((c << 16) + c) << 12) + 0x04000400;
        _ASMSet_Shadowing(0x00ff00ff, value, 0xff00ff00, value);
    }

    int one = 1;
    int zero = 0;
    if (this->map->fog_flag != 0 && vis == 0x80) {
        fog_next_shape = one;
    }

    if (draw2 != 0) {
        this->draw_area->CurSpanList = this->Terrain_Fog_Clip_Mask;
        fog_next_shape = one;
        shape->shape_draw(this->draw_area, x, y, frame, 0, 0);
        fog_next_shape = zero;
    }

    if ((fog_flag & 0xa0) != 0) {
        fog_next_shape = one;
    }

    if (draw1 != 0) {
        this->draw_area->CurSpanList = this->Terrain_Clip_Mask;
        shape->shape_draw(this->draw_area, x, y, frame, 0, 0);
    }

    this->draw_area->CurSpanList = this->draw_area->SpanList;
    _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
    fog_next_shape = zero;
}
