// 004BA550 TShape::shape_mirror
// Attempt log:
// try 1: packet-grounded mirror dispatcher reconstruction from 004BA550 packet and sibling 004B9440 shape_draw attempt. Covers Check_shape guard, FShape capture/ASM fast paths, mirrored bounds/clip computation, and unclipped/clipped dispatch by mode/table. Compiled too short (896B vs 944B).
// try 2: diagnostic-only padding branch reached byte compare, then removed. Diagnostic compare was broad mismatch (83.4746% positional / 126.1653% edit); first mismatch frame 0x20 vs original 0x1c and parameter/register order diverges immediately.
// try 3: modeled mirrored FShape capture path using SDI globals, +2 fog_next_shape, color xform, AddDrawNode, and mirrored x/y offset arithmetic.
// try 4: modeled mirrored FShape fast ASM path: surface setup, optional xlate table, ASMDraw_Sprite with +2 fog_next_shape, ASM_Fast_Count++.
// try 5: modeled normal shape path: frame lookup from offset table, mirrored x bounds (x-xmax/x-xmin), y bounds, clip rect/draw-area clamp, empty return.
// try 6: modeled unclipped/clipped dispatch families for mode 0/1/2 and table present/absent to mirror helper variants.
// GIVEUP blockers: exact DrawArea/FShape/Shape frame layouts and ASM helper signatures/globals, precise stack-slot reuse for rectangle locals, and source shape for mirrored bound arithmetic/switch tails. No inline asm used; no accepted_drift proposal.
// sa-040f7d5d-r1 baseline: rebuilt the prior scratch candidate before interpreting its stale metrics.
// sa-040f7d5d-r1 abi: replaced the free AddDrawNode shim with the typed DClipInfo_List member;
// nested the zero-argument ASMGet_Color_Xform call so the outer draw-level/object-id pushes stay live.
// sa-040f7d5d-r1 layout: restored period TShape offsets, TDrawArea span ownership, SLhape/Shape_Info
// records, and the actual mirrored helper signatures. This fixed the direct call set and canonical
// address ownership, although the standalone frame/local basin remained different.
// sa-040f7d5d-r1 control-flow: used the packet's positive outer guard, persistent zero return,
// one shared clipped fallback, and reverse switch order for the clipped mode handlers. Kept the
// three distinct natural unclipped fallback call sites required by the original call topology.
// final bounded result: 917 rebuilt bytes vs 944, 14/14 call targets with one ordered site gap,
// 885 strict differing bytes, 61.29% shape similarity. Left in scratch: frame/prologue/local-home
// basin and late dispatch block order; no behavior/call/layout uncertainty remains from this pass.
// shardB3-BA550 control-flow: reordered the unclipped dispatcher as the original reverse switch;
// table-null mode-2 and mode-1 arms return to the unclipped helper before shadow/color calls.
// This restores all 14 ordered call sites; the remaining gap is the known frame/local basin.
// shardE-4BA550 baseline: prior clean typed dispatcher remains the canonical source reconstruction.
// Probed draw-area alias removal, clipped-bound local modeling, span-local declaration order,
// alias/return declaration order, and explicit FShape else-if topology. All were duplicate or
// worse. Restored the clean source. Remaining binary-backed gap is the entry frame/local-home
// basin: original 0x1c frame, parameter homes, and late local dispatch schedule versus rebuilt
// 0x18 frame. Calls and direct target order remain exact (14/14).

typedef unsigned char byte;
class TDrawArea;
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
class DClipInfo_List {
public:
    void AddDrawNode(void*, Shape_Info*, int, int, int, int, byte*, int, int, int);
};
extern int SDI_Capture_Info, SDI_Draw_Level, SDI_Object_ID, SDI_Draw_Line, fog_next_shape, ASM_Fast_Count;
extern DClipInfo_List* SDI_List;
extern "C" void* __cdecl ASMGet_Color_Xform();
extern "C" void __cdecl ASMSet_Surface_Info(void*,void*,void*,int,int,int,int);
extern "C" void __cdecl ASMSet_Xlate_Table(void*);
extern "C" void __cdecl ASMDraw_Sprite(void*,int,int,int,int,int,int,int);

struct Rect { long left, top, right, bottom; };
struct Shape_Header { long bounds, origin, xmin, ymin, xmax, ymax; };
struct ShapeFile { long version; long shape_num; };
struct Shape_Offsets { long shape; long palette; };
struct SLhape_File_Header { char Version[4]; long Num_Shapes; char Comment[24]; };
struct TSpan_List_Manager {
    char gap[0x3c];
    void* Line_Head_Ptrs;
    void* Line_Tail_Ptrs;
    char gap44[0x0c];
    long Num_Lines;
    long Num_Pixels;
    long Min_Span_Px;
    long Max_Span_Px;
};
class TDrawArea {
public:
    char gap0[0x18];
    long Width;
    long Height;
    long Pitch;
    long Orien;
    Rect ClipRect;
    char gap38[0x88];
    void** CurDisplayOffsets;
    void* FloatOffsets;
    void* shadow_color_table;
    TSpan_List_Manager* SpanList;
    TSpan_List_Manager* CurSpanList;
};

class TShape {
public:
    byte* shape; int load_type; int load_size; Shape_Header* shape_header;
    ShapeFile* head; Shape_Offsets* offsets; SLhape_File_Header* fshape; Shape_Info* shape_info;
    byte Check_shape(long,char*);
    byte shape_mirror_unclipped(TDrawArea*,long,long);
    byte shape_mirror_color_trans_unclipped(TDrawArea*,long,long,long,byte*);
    byte shape_mirror_shadow_unclipped(TDrawArea*,long,long,byte*);
    byte shape_mirror_clipped(TDrawArea*,long,long,long,long,long,long);
    byte shape_mirror_color_trans_clipped(TDrawArea*,long,long,long,long,long,long,long,byte*);
    byte shape_mirror_shadow_clipped(TDrawArea*,long,long,long,long,long,long,byte*);
    byte shape_mirror(TDrawArea*, long x, long y, long shape_num, byte mode, byte* table);
};

byte TShape::shape_mirror(TDrawArea* td, long x, long y, long shape_num, byte mode, byte* table)
{
    byte ret_num = 0;
    TDrawArea* draw_area = td;
    long clip_y0;
    long shape_y1;
    Rect rect;

    if (shape_num >= 0 && this->Check_shape(shape_num, (char*)0x00587058) == 0) {
        if (this->fshape != 0) {
            if (SDI_Capture_Info != 0) {
                Shape_Info* info = (Shape_Info*)(this->fshape + shape_num + 1);
                SDI_List->AddDrawNode(this->fshape, info, SDI_Draw_Line,
                    (info->Hotspot_X - info->Width) + x, y - info->Hotspot_Y,
                    fog_next_shape + 2, table, (int)ASMGet_Color_Xform(),
                    SDI_Draw_Level, SDI_Object_ID);
                return 1;
            }

            int span_lines = draw_area->SpanList->Num_Lines;
            TSpan_List_Manager* current = draw_area->CurSpanList;
            int current_lines = current->Num_Lines;
            if (span_lines < current_lines)
                current_lines = span_lines;
            ASMSet_Surface_Info(draw_area->CurDisplayOffsets,
                current->Line_Head_Ptrs, current->Line_Tail_Ptrs,
                0, 0, current->Max_Span_Px, current_lines - 1);
            if (table != 0)
                ASMSet_Xlate_Table(table);

            Shape_Info* info = (Shape_Info*)(this->fshape + shape_num + 1);
            ASMDraw_Sprite(this->fshape,
                (info->Hotspot_X + x) - info->Width,
                y - info->Hotspot_Y, info->Width, info->Height,
                info->Shape_Data_Offsets, info->Shape_Outline_Offset,
                fog_next_shape + 2);
            ASM_Fast_Count++;
            return 1;
        }

        if (this->shape != 0) {
            rect = draw_area->ClipRect;
            Shape_Header* header = (Shape_Header*)(this->shape + this->offsets[shape_num].shape);
            this->shape_header = header;

            long shape_x0 = x - header->xmax;
            long raw_y0 = y + header->ymin;
            long shape_x1 = x - header->xmin;
            clip_y0 = raw_y0;
            shape_y1 = y + header->ymax;
            x = shape_x0;
            td = (TDrawArea*)shape_x1;
            y = shape_y1;

            if (x < rect.left)
                x = rect.left;
            if (clip_y0 < rect.top)
                clip_y0 = rect.top;
            if (rect.right < shape_x1)
                td = (TDrawArea*)rect.right;
            if (rect.bottom < shape_y1)
                y = rect.bottom;
            if ((long)x < 0)
                x = 0;
            if (clip_y0 < 0)
                clip_y0 = 0;
            if (draw_area->Width <= (long)td)
                td = (TDrawArea*)(draw_area->Width - 1);
            if (draw_area->Height <= y)
                y = draw_area->Height - 1;

            if ((long)x <= (long)td && clip_y0 <= y) {
                if (x != shape_x0 || clip_y0 != raw_y0 ||
                    (long)td != shape_x1 || y != shape_y1) {
                    switch ((unsigned char)mode) {
                    case 2:
                        if (table != 0)
                            return this->shape_mirror_shadow_clipped(
                                draw_area, shape_x1, clip_y0,
                                (long)x, clip_y0, (long)td, y, table);
                        break;
                    case 1:
                        if (table != 0)
                            return this->shape_mirror_color_trans_clipped(
                                draw_area, shape_x1, clip_y0, shape_num,
                                (long)x, clip_y0, (long)td, y, table);
                        break;
                    case 0:
                        break;
                    default:
                        return ret_num;
                    }
                    return this->shape_mirror_clipped(draw_area, shape_x1, clip_y0,
                        (long)x, clip_y0, (long)td, y);
                }

                switch ((unsigned char)mode) {
                case 2:
                    if (table == 0)
                        return this->shape_mirror_unclipped(draw_area, shape_x1, clip_y0);
                    return this->shape_mirror_shadow_unclipped(
                        draw_area, shape_x1, clip_y0, table);
                case 1:
                    if (table == 0)
                        return this->shape_mirror_unclipped(draw_area, shape_x1, clip_y0);
                    return this->shape_mirror_color_trans_unclipped(
                        draw_area, shape_x1, clip_y0, shape_num, table);
                case 0:
                    return this->shape_mirror_unclipped(draw_area, shape_x1, clip_y0);
                default:
                    return ret_num;
                }
            }
        }
    }
    return ret_num;
}
