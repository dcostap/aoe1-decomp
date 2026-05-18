// 004B9440 TShape::shape_draw
// Attempt log:
// try 1: packet-grounded dispatcher/wrapper reconstruction: Check_shape guard, fast FShape/ASM paths,
// clip rectangle computation, unclipped dispatch by draw mode, clipped dispatch by draw mode/shadow table. Compiled too short (880B vs 933B).
// try 2: diagnostic-only padding branch reached byte compare, then removed. Diagnostic compare was broad mismatch (85.9593% positional / 127.1168% edit), first mismatch frame 0x20 vs original 0x1c and parameter/register order wrong from the prologue.
// try 3: modeled Check_shape(shape_num,"RGL_shape_draw") guard and negative shape_num return; call surface compiles but not codegen-close.
// try 4: modeled FShape capture path using SDI globals, color xform, AddDrawNode, fog_next_shape, and frame offsets.
// try 5: modeled FShape fast ASM surface setup path: surface info, optional xlate table, ASMDraw_Sprite, ASM_Fast_Count++.
// try 6: modeled normal shape path: load shape frame from offset table, compute unclipped bounds, clamp against draw-area clip and dimensions, early empty return.
// try 7: modeled exact high-level dispatch families for mode 0/1/2 and table present/absent to unclipped and clipped shape helper variants.
// GIVEUP blockers: exact DrawArea/FShape/Shape frame layouts and signatures for ASM helper calls/globals, precise stack-slot reuse for rectangle locals, and source shape for switch/early-return dispatcher tails. No inline asm used; no accepted_drift proposal.

typedef unsigned char byte;

class TDrawArea;
class TShape;

extern int SDI_Capture_Info;
extern int SDI_Draw_Level;
extern int SDI_Object_ID;
extern int SDI_Draw_Line;
extern int fog_next_shape;
extern int SDI_List;
extern int ASM_Fast_Count;

extern "C" void* __cdecl ASMGet_Color_Xform(int, int);
extern "C" void __cdecl ASMSet_Surface_Info(void*, int, int, int, int, int, int);
extern "C" void __cdecl ASMSet_Xlate_Table(void*);
extern "C" void __cdecl DClipInfo_List_AddDrawNode(int list, void* fshape, void* shape, int line, int y, int x, int fog, long p6, void* xform);
extern "C" void __cdecl ASMDraw_Sprite(void* fshape, int y, int x, int a, int b, int c, int d, int fog);

struct Rect { long left; long top; long right; long bottom; };
struct Frame { long a0; long a4; long xmin; long ymin; long xmax; long ymax; long xoff; long yoff; };
struct ShapeFile { char gap[0x14]; int* offsets; };
struct FShapeFile { char gap[0xc0]; void* surface; char gap2[8]; int* pcc; int* pd0; };

class TDrawArea {
public:
    char gap0[0x18];
    long width;      // +18
    long height;     // +1c
    char gap20[0x08];
    Rect clip;       // +28
};

class TShape {
public:
    byte* shape;
    int load_type;
    int load_size;
    Frame* shape_header;
    ShapeFile* head;
    char gap14[4];
    FShapeFile* fshape;

    byte Check_shape(long, char*);
    byte shape_draw_unclipped(TDrawArea*, long, long, long);
    byte shape_color_trans_unclipped(TDrawArea*, long, long, long, byte*);
    byte shape_shadow_unclipped(TDrawArea*, long, long, void*);
    byte shape_draw_clipped(TDrawArea*, long, long, long, long, long, long);
    byte shape_color_trans_clipped(TDrawArea*, long, long, long, long, long, long, byte*);
    byte shape_shadow_clipped(TDrawArea*, long, long, long, long, long, long, void*);
    byte shape_draw(TDrawArea*, long, long, long, byte, void*);
};

byte TShape::shape_draw(TDrawArea* td, long x, long y, long shape_num, byte mode, void* table)
{
    byte ret = 0;
    if (shape_num < 0) return 0;
    if (this->Check_shape(shape_num, (char*)0x00587058)) return 0;

    if (this->fshape) {
        if (SDI_Capture_Info) {
            Frame* f = (Frame*)((char*)this->fshape + ((shape_num + 1) << 5));
            void* xform = ASMGet_Color_Xform(SDI_Draw_Level, SDI_Object_ID);
            DClipInfo_List_AddDrawNode(SDI_List, this->fshape, f, SDI_Draw_Line,
                y - f->yoff, x - f->xoff, fog_next_shape, (long)table, xform);
            return 1;
        }
        TDrawArea* area = td;
        FShapeFile* fs = this->fshape;
        int a = fs->pcc[0x14];
        int b = fs->pd0[0x14];
        int last = (a < b) ? (a - 1) : (b - 1);
        ASMSet_Surface_Info(fs->surface, fs->pd0[0x0f], fs->pd0[0x10], 0, 0, fs->pd0[0x17], last);
        if (table) ASMSet_Xlate_Table(table);
        Frame* f = (Frame*)((char*)fs + ((shape_num + 1) << 5));
        ASMDraw_Sprite(fs, y - f->yoff, x - f->xoff, f->xmin, f->ymin, f->xmax, f->ymax, fog_next_shape);
        ASM_Fast_Count++;
        return 1;
    }

    Rect r = td->clip;
    if (!this->shape) return 0;
    Frame* f = (Frame*)((char*)this->shape + this->head->offsets[shape_num * 2]);
    this->shape_header = f;

    long sx0 = f->xmin + x;
    long sy0 = f->ymin + y;
    long sx1 = f->xmax + x;
    long sy1 = f->ymax + y;
    long ox0 = sx0, oy0 = sy0, ox1 = sx1, oy1 = sy1;

    if (sx0 < r.left) sx0 = r.left;
    if (sy0 < r.top) sy0 = r.top;
    if (sx1 > r.right) sx1 = r.right;
    if (sy1 > r.bottom) sy1 = r.bottom;
    if (sx0 < 0) sx0 = 0;
    if (sy0 < 0) sy0 = 0;
    if (sx1 >= td->width) sx1 = td->width - 1;
    if (sy1 >= td->height) sy1 = td->height - 1;
    if (sx1 < sx0 || sy1 < sy0) return 0;

    if (sx0 == ox0 && sy0 == oy0 && sx1 == ox1 && sy1 == oy1) {
        switch ((unsigned char)mode) {
        case 0:
            return this->shape_draw_unclipped(td, y, x, table ? (long)table : 0);
        case 1:
            if (table) return this->shape_color_trans_unclipped(td, y, x, (long)table, (byte*)table);
            return this->shape_draw_unclipped(td, y, x, table ? (long)table : 0);
        case 2:
            if (table) return this->shape_shadow_unclipped(td, y, x, table);
            return this->shape_draw_unclipped(td, y, x, 0);
        default:
            return ret;
        }
    }

    switch ((unsigned char)mode) {
    case 0:
        return this->shape_draw_clipped(td, sy0, sx0, sx1, y, x, sy1);
    case 1:
        if (table) return this->shape_color_trans_clipped(td, sy0, sx0, sx1, y, x, sy1, (byte*)table);
        return this->shape_draw_clipped(td, sy0, sx0, sx1, y, x, sy1);
    case 2:
        if (table) return this->shape_shadow_clipped(td, sy0, sx0, sx1, y, x, sy1, table);
        return this->shape_draw_clipped(td, sy0, sx0, sx1, y, x, sy1);
    default:
        return ret;
    }
}
