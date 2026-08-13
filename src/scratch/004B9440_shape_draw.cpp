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
// try 8: restored the period TShape/TDrawArea/Shape_Info surfaces and the real
// DClipInfo_List::AddDrawNode thiscall ABI. Corrected the FShape capture/fast
// fields and all helper argument order/arity from the inventory declarations.
// The first integrated check after this source correction is the structural
// baseline for the current ownership model.
// session sa0400c379_r1 probes 9-10: splitting the result-byte declaration
// from its zero assignment and adding donor-era stdlib/string headers were
// both codegen duplicates. The retained natural source has exact ordered call
// and relocation parity; remaining drift is the broad VC5 prologue/frame and
// normal-path local/register basin (0x14 rebuilt frame versus 0x1c original),
// with the first mismatch at the entry register/home schedule.
// session shardB2-B9440 probe 1: captured draw_level and object_id locals
// through AddDrawNode; the typed local-liveness lead worsened the frame and
// structural diff, so the clean direct-global form is retained.
// session shardB6-B9440 probe 1: used a typed shared line-count local with
// branch-local subtraction for the Shape.cpp span-list gate; this follows the
// first non-prologue structural hunk and tests the donor-era branch topology.
// No inline asm used; no accepted_drift proposal.

typedef unsigned char byte;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};

struct Shape_Offsets {
    long shape;
    long palette;
};

struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

class TSpan_List_Manager {
public:
    char gap_00[0x3c];
    void* Line_Head_Ptrs;       // +3c
    void* Line_Tail_Ptrs;       // +40
    char gap_44[0x0c];
    int Num_Lines;              // +50
    char gap_54[8];
    int Max_Span_Px;            // +5c
};

class TDrawArea {
public:
    void* DrawSystem;           // +00
    void* Wnd;                  // +04
    byte* Bits;                 // +08
    void* BitmapInfo;           // +0c
    void* Bitmap;               // +10
    void* OldBitmap;            // +14
    int Width;                  // +18
    int Height;                 // +1c
    int Pitch;                  // +20
    int Orien;                  // +24
    tagRECT ClipRect;           // +28
    void* DrawDc;               // +38
    void* DrawSurface;           // +3c
    char SurfaceDesc[0x6c];     // +40
    void* Node;                 // +ac
    char* Name;                 // +b0
    byte* LastBits;             // +b4
    int LastPitch;              // +b8
    void** DisplayOffsets;      // +bc
    void** CurDisplayOffsets;   // +c0
    void* FloatOffsets;         // +c4
    void* shadow_color_table;   // +c8
    TSpan_List_Manager* SpanList;    // +cc
    TSpan_List_Manager* CurSpanList; // +d0
    int Float_X_Delta;          // +d4
    int Float_Y_Delta;          // +d8
    int DisplayOffsetsSz;       // +dc
    int FloatOffsetsSz;         // +e0
    int SystemMemOnly;          // +e4
    int UsingVidMem;            // +e8
    int UseTrans;               // +ec
    int IsPrimarySurface;       // +f0
    int Restored;               // +f4
    int ExtendedLines;          // +f8
    byte TransColor;            // +fc
    byte gap_fd[3];             // +fd
};

class DClipInfo_List {
public:
    void AddDrawNode(void* shape_base, Shape_Info* shape, int yline,
                     int draw_x, int draw_y, int draw_flag,
                     byte* color_table, int xform_mask,
                     int draw_level, int object_id);
};

class TShape {
public:
    byte* shape;                // +00
    int load_type;              // +04
    int load_size;              // +08
    Shape_Header* shape_header; // +0c
    void* head;                 // +10
    Shape_Offsets* offsets;     // +14
    void* FShape;               // +18
    Shape_Info* shape_info;     // +1c

    byte Check_shape(long, char*);
    byte shape_draw_unclipped(TDrawArea*, long, long, long);
    byte shape_color_trans_unclipped(TDrawArea*, long, long, long, byte*);
    byte shape_shadow_unclipped(TDrawArea*, long, long, byte*);
    byte shape_draw_clipped(TDrawArea*, long, long, long, long, long, long);
    byte shape_color_trans_clipped(TDrawArea*, long, long, long, long, long, long, long, byte*);
    byte shape_shadow_clipped(TDrawArea*, long, long, long, long, long, long, byte*);
    byte shape_draw(TDrawArea*, long, long, long, byte, byte*);
};

extern int SDI_Capture_Info;
extern int SDI_Draw_Level;
extern long SDI_Object_ID;
extern int SDI_Draw_Line;
extern int fog_next_shape;
extern DClipInfo_List* SDI_List;
extern int ASM_Fast_Count;

extern "C" void* __cdecl ASMGet_Color_Xform(int, long);
extern "C" void __cdecl ASMSet_Surface_Info(void*, void*, void*, int, int, int, int);
extern "C" void __cdecl ASMSet_Xlate_Table(void*);
extern "C" void __cdecl ASMDraw_Sprite(void*, long, long, long, long, long, long, int);

byte TShape::shape_draw(TDrawArea* td, long x, long y, long shape_num,
                        byte mode, byte* table)
{
    byte ret;
    ret = 0;

    if (shape_num >= 0 &&
        this->Check_shape(shape_num, (char*)0x00587058) == 0) {
      if (this->FShape != 0) {
        if (SDI_Capture_Info != 0) {
            Shape_Info* info = (Shape_Info*)((char*)this->FShape +
                                             ((shape_num + 1) << 5));
            int xform = (int)ASMGet_Color_Xform(SDI_Draw_Level, SDI_Object_ID);
            SDI_List->AddDrawNode(this->FShape, info, SDI_Draw_Line,
                                  x - info->Hotspot_X, y - info->Hotspot_Y,
                                  fog_next_shape, table, xform,
                                  SDI_Draw_Level, SDI_Object_ID);
            return 1;
        }

        TSpan_List_Manager* cur_span_list = td->CurSpanList;
        int line_count;
        if (td->SpanList->Num_Lines < cur_span_list->Num_Lines)
            line_count = td->SpanList->Num_Lines - 1;
        else
            line_count = cur_span_list->Num_Lines - 1;
        ASMSet_Surface_Info(td->CurDisplayOffsets,
                            cur_span_list->Line_Head_Ptrs,
                            cur_span_list->Line_Tail_Ptrs,
                            0, 0, cur_span_list->Max_Span_Px, line_count);
        if (table != 0)
            ASMSet_Xlate_Table(table);

        Shape_Info* info = (Shape_Info*)((char*)this->FShape +
                                         ((shape_num + 1) << 5));
        ASMDraw_Sprite(this->FShape, x - info->Hotspot_X,
                       y - info->Hotspot_Y, info->Width, info->Height,
                       info->Shape_Data_Offsets, info->Shape_Outline_Offset,
                       fog_next_shape);
        ++ASM_Fast_Count;
        return 1;
      }
      else {

        tagRECT rect = td->ClipRect;
        if (this->shape != 0) {
        Shape_Header* frame = (Shape_Header*)
            (this->shape + this->offsets[shape_num].shape);
        this->shape_header = frame;

        long x0 = frame->xmin + x;
        long y0 = frame->ymin + y;
        long x1 = frame->xmax + x;
        long y1 = frame->ymax + y;
        long original_x0 = x0;
        long original_y0 = y0;
        long original_x1 = x1;
        long original_y1 = y1;

        if (x0 < rect.left)
            x0 = rect.left;
        if (y0 < rect.top)
            y0 = rect.top;
        if (x1 > rect.right)
            x1 = rect.right;
        if (y1 > rect.bottom)
            y1 = rect.bottom;
        if (x0 < 0)
            x0 = 0;
        if (y0 < 0)
            y0 = 0;
        if (x1 >= td->Width)
            x1 = td->Width - 1;
        if (y1 >= td->Height)
            y1 = td->Height - 1;

        if (x0 <= x1 && y0 <= y1) {
            if (x0 == original_x0 && y0 == original_y0 &&
                x1 == original_x1 && y1 == original_y1) {
                switch ((unsigned char)mode) {
                case 2:
                    if (table == 0) {
                        long draw_x = x1;
                        long draw_y = y1;
                        return this->shape_draw_unclipped(td, draw_x, draw_y,
                                                           shape_num);
                    }
                    return this->shape_shadow_unclipped(
                        td, original_x0, original_y0, table);
                case 1:
                    if (table == 0) {
                        long draw_x = x0;
                        long draw_y = y0;
                        return this->shape_draw_unclipped(td, draw_x, draw_y,
                                                           shape_num);
                    }
                    return this->shape_color_trans_unclipped(
                        td, original_x0, original_y0, shape_num, table);
                case 0:
                    {
                        long draw_x = original_x0;
                        long draw_y = original_y0;
                        return this->shape_draw_unclipped(td, draw_x, draw_y,
                                                           shape_num);
                    }
                default:
                    return ret;
                }
            }

            if (mode == 2) {
                if (table != 0)
                    return this->shape_shadow_clipped(
                        td, original_x0, original_y0, x0, y0, x1, y1, table);
            } else if (mode == 1) {
                if (table != 0)
                    return this->shape_color_trans_clipped(
                        td, original_x0, original_y0, shape_num,
                        x0, y0, x1, y1, table);
            } else if (mode != 0) {
                return ret;
            }
            return this->shape_draw_clipped(td, original_x0, original_y0,
                                            x0, y0, x1, y1);
        }
      }
    }
    }

    return ret;
}
