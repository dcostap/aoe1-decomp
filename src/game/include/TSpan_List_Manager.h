#pragma once
#include "common.h"
#include "TSpan_Node_List.h"
#include "VSpan_Node.h"

struct VSpanMiniList;

struct TSpan_List_Manager {
    TSpan_List_Manager(int num_pixels, int num_lines);
    ~TSpan_List_Manager();

    void SetSpanRegions(int left_px, int top_line, int right_px, int bottom_line);
    void ResetAll();
    void AddSpan(int start_px, int end_px, int line);
    void SubtractMiniList(VSpanMiniList* mini_list, int x_off, int y_off);
    void DeleteSpan(int start_px, int end_px, int line);
    int PointVisible(int x_px, int y_line);
    void Merge_n_Align(TSpan_List_Manager* list_a, TSpan_List_Manager* list_b);

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
