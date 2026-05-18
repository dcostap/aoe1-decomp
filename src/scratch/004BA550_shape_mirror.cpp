// 004BA550 TShape::shape_mirror
// Attempt log:
// try 1: packet-grounded mirror dispatcher reconstruction from 004BA550 packet and sibling 004B9440 shape_draw attempt. Covers Check_shape guard, FShape capture/ASM fast paths, mirrored bounds/clip computation, and unclipped/clipped dispatch by mode/table. Compiled too short (896B vs 944B).
// try 2: diagnostic-only padding branch reached byte compare, then removed. Diagnostic compare was broad mismatch (83.4746% positional / 126.1653% edit); first mismatch frame 0x20 vs original 0x1c and parameter/register order diverges immediately.
// try 3: modeled mirrored FShape capture path using SDI globals, +2 fog_next_shape, color xform, AddDrawNode, and mirrored x/y offset arithmetic.
// try 4: modeled mirrored FShape fast ASM path: surface setup, optional xlate table, ASMDraw_Sprite with +2 fog_next_shape, ASM_Fast_Count++.
// try 5: modeled normal shape path: frame lookup from offset table, mirrored x bounds (x-xmax/x-xmin), y bounds, clip rect/draw-area clamp, empty return.
// try 6: modeled unclipped/clipped dispatch families for mode 0/1/2 and table present/absent to mirror helper variants.
// GIVEUP blockers: exact DrawArea/FShape/Shape frame layouts and ASM helper signatures/globals, precise stack-slot reuse for rectangle locals, and source shape for mirrored bound arithmetic/switch tails. No inline asm used; no accepted_drift proposal.

typedef unsigned char byte;
class TDrawArea;
extern int SDI_Capture_Info, SDI_Draw_Level, SDI_Object_ID, SDI_Draw_Line, fog_next_shape, SDI_List, ASM_Fast_Count;
extern "C" void* __cdecl ASMGet_Color_Xform(int,int);
extern "C" void __cdecl ASMSet_Surface_Info(void*,int,int,int,int,int,int);
extern "C" void __cdecl ASMSet_Xlate_Table(void*);
extern "C" void __cdecl DClipInfo_List_AddDrawNode(int,void*,void*,int,int,int,int,long,void*);
extern "C" void __cdecl ASMDraw_Sprite(void*,int,int,int,int,int,int,int);

struct Rect { long left, top, right, bottom; };
struct Frame { long a0,a4,xmin,ymin,xmax,ymax,xoff,yoff; };
struct ShapeFile { char gap[0x14]; int* offsets; };
struct FShapeFile { char gap[0xc0]; void* surface; char gap2[8]; int* pcc; int* pd0; };
class TDrawArea { public: char gap0[0x18]; long width; long height; char gap20[8]; Rect clip; };

class TShape {
public:
    byte* shape; int load_type; int load_size; Frame* shape_header; ShapeFile* head; char gap14[4]; FShapeFile* fshape;
    byte Check_shape(long,char*);
    byte shape_mirror_unclipped(TDrawArea*,long,long,long);
    byte shape_mirror_color_trans_unclipped(TDrawArea*,long,long,long,byte*);
    byte shape_mirror_shadow_unclipped(TDrawArea*,long,long,long,void*);
    byte shape_mirror_clipped(TDrawArea*,long,long,long,long,long,long);
    byte shape_mirror_color_trans_clipped(TDrawArea*,long,long,long,long,long,long,byte*);
    byte shape_mirror_shadow_clipped(TDrawArea*,long,long,long,long,long,long,void*);
    byte shape_mirror(TDrawArea*, long x, long y, long shape_num, byte mode, void* table);
};

byte TShape::shape_mirror(TDrawArea* td, long x, long y, long shape_num, byte mode, void* table)
{
    byte ret = 0;
    if (shape_num < 0) return 0;
    if (this->Check_shape(shape_num, (char*)0x00587058)) return 0;

    if (this->fshape) {
        if (SDI_Capture_Info) {
            Frame* f = (Frame*)((char*)this->fshape + ((shape_num + 1) << 5));
            void* xf = ASMGet_Color_Xform(SDI_Draw_Level, SDI_Object_ID);
            DClipInfo_List_AddDrawNode(SDI_List, this->fshape, f, SDI_Draw_Line,
                y + f->xmax - f->xmin - f->yoff, x - f->xoff, fog_next_shape + 2, (long)table, xf);
            return 1;
        }
        FShapeFile* fs = this->fshape;
        int a = fs->pcc[0x14];
        int b = fs->pd0[0x14];
        int last = (a < b) ? (a - 1) : (b - 1);
        ASMSet_Surface_Info(fs->surface, fs->pd0[0x0f], fs->pd0[0x10], 0, 0, fs->pd0[0x17], last);
        if (table) ASMSet_Xlate_Table(table);
        Frame* f = (Frame*)((char*)fs + ((shape_num + 1) << 5));
        ASMDraw_Sprite(fs, y + f->xmax - f->xmin - f->yoff, x - f->xoff, f->xmin, f->ymin, f->xmax, f->ymax, fog_next_shape + 2);
        ASM_Fast_Count++;
        return 1;
    }

    Rect r = td->clip;
    if (!this->shape) return 0;
    Frame* f = (Frame*)((char*)this->shape + this->head->offsets[shape_num * 2]);
    this->shape_header = f;

    long sx0 = x - f->xmax;
    long sy0 = y + f->ymin;
    long sx1 = x - f->xmin;
    long sy1 = y + f->ymax;
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
        case 0: return this->shape_mirror_unclipped(td, y, x, table ? (long)table : 0);
        case 1: if (table) return this->shape_mirror_color_trans_unclipped(td, y, x, (long)table, (byte*)table); return this->shape_mirror_unclipped(td, y, x, 0);
        case 2: if (table) return this->shape_mirror_shadow_unclipped(td, y, x, (long)table, table); return this->shape_mirror_unclipped(td, y, x, 0);
        default: return ret;
        }
    }

    switch ((unsigned char)mode) {
    case 0: return this->shape_mirror_clipped(td, sy0, sx0, sx1, y, x, sy1);
    case 1: if (table) return this->shape_mirror_color_trans_clipped(td, sy0, sx0, sx1, y, x, sy1, (byte*)table); return this->shape_mirror_clipped(td, sy0, sx0, sx1, y, x, sy1);
    case 2: if (table) return this->shape_mirror_shadow_clipped(td, sy0, sx0, sx1, y, x, sy1, table); return this->shape_mirror_clipped(td, sy0, sx0, sx1, y, x, sy1);
    default: return ret;
    }
}
