#pragma once
#include "common.h"
#include "TSpan_Node_List.h"
#include "VSpan_Node.h"

struct VSpanMiniList;
class TShape;
struct Shape_Info;
struct TDrawArea;

struct TSpan_List_Manager {
    TSpan_List_Manager(int num_pixels, int num_lines);
    ~TSpan_List_Manager();

    void SetSpanRegions(int left_px, int top_line, int right_px, int bottom_line);
    void ResetAll();
    void AddSpan(int start_px, int end_px, int line);
    void AddShape(TShape* shape, int shape_idx, int x, int y, int mirrored);
    void AddShape_Align(uchar* shape_data, Shape_Info* shape_info, int x, int y, int mirrored);
    void AddLine_Align(int x1, int y1, int x2, int y2);
    void AddMiniList(VSpanMiniList* mini_list, int x_off, int y_off);
    void SubtractMiniList(VSpanMiniList* mini_list, int x_off, int y_off);
    void DeleteSpan(int start_px, int end_px, int line);
    void DeleteShape(TShape* shape, int shape_idx, int x, int y, int mirrored);
    int PointVisible(int x_px, int y_line);
    void Merge_n_Align(TSpan_List_Manager* list_a, TSpan_List_Manager* list_b);
    void AlignamizeSpans();
    void ScrollSpansHorizontally(int delta_x, int clamp_to_span_region);
    void ScrollSpansVertically(int delta_y, int clamp_to_line_region);
    int ValidateSpan(int line);
    int DecodeLine(uchar* dst, int line, uchar add_value, int width);
    void take_snapshot(char* filename_fmt, int* snapshot_number, TDrawArea* draw_area, int base_value,
                       TSpan_List_Manager** overlay_lists, int* overlay_values, int overlay_count);

    TSpan_Node_List VSList;
    VSpan_Node** Line_Head_Ptrs;
    VSpan_Node** Line_Tail_Ptrs;
    int* LeftMostPx;
    int* RightMostPx;
    int* Span_Count;
    int Num_Lines;
    int Num_Pixels;
    int Min_Span_Px;
    int Max_Span_Px;
    int Min_Line;
    int Max_Line;
};
static_assert(sizeof(TSpan_List_Manager) == 0x68, "Size mismatch");
