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
// BLOCKER: behavior is sketched but source shape/register allocation is wrong from coordinate setup. Original loads y into EBP before pushing EDI, computes frame table via `[shape+1c]`, then subtracts table y/x offsets into EBP/EDI; current VC5 keeps different local assignment/order (EDI/EBP swapped around table loads), causing broad cascade. Later fog/shadow branches are approximate but not yet reliable.

extern int fog_next_shape;
extern "C" void __cdecl _ASMSet_Shadowing(int a, int b, int c, int d);

class TDrawArea { public: char gap[0xcc]; int field_cc; int field_d0; };

class TShape {
public:
    char gap_00[0x1c];
    int* x_offsets; // table payload via [shape+1c]+frame*0x20
    int shape_draw(TDrawArea* area, long y, long x, long frame, unsigned char color_flag, unsigned char* color_table);
};

class RGE_View {
public:
    char gap_000[0x0f4];
    TDrawArea* draw_area; // +f4
    char gap_0f8[0x104 - 0x0f8];
    char* fog; // +104
    char gap_108[0x178 - 0x108];
    int terrain_draw_value2; // +178
    int terrain_draw_value1; // +17c

    void draw_terrain_shape(int x, int y, TShape* shape, int frame, unsigned char vis, unsigned char fog_flag, int draw1, int draw2);
};

void RGE_View::draw_terrain_shape(int x, int y, TShape* shape, int frame, unsigned char vis, unsigned char fog_flag, int draw1, int draw2)
{
    int draw_x = x;
    int draw_y = y;
    char* info = (char*)shape->x_offsets + (frame << 5);
    draw_x -= *(int*)(info + 0x18);
    draw_y -= *(int*)(info + 0x1c);

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
    if (this->fog[0x8db9] != 0 && vis == 0x80) {
        fog_next_shape = one;
    }

    if (draw2 != 0) {
        this->draw_area->field_d0 = this->terrain_draw_value1;
        fog_next_shape = one;
        shape->shape_draw(this->draw_area, x, draw_y, frame, 0, 0);
        fog_next_shape = zero;
    }

    if ((fog_flag & 0xa0) != 0) {
        fog_next_shape = one;
    }

    if (draw1 != 0) {
        this->draw_area->field_d0 = this->terrain_draw_value2;
        shape->shape_draw(this->draw_area, x, draw_y, frame, 0, 0);
    }

    this->draw_area->field_d0 = this->draw_area->field_cc;
    _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
    fog_next_shape = zero;
}
