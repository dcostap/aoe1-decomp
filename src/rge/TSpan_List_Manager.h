#pragma once

#include <stdlib.h>
#include "TSpan_Node_List.h"

// Forward declarations
class TShape;
class TDrawArea;
struct Shape_Info;

// Structures defined from decompilation
struct VSpan_Node {
    VSpan_Node *Next;
    VSpan_Node *Prev;
    int StartPx;
    int EndPx;
};

struct VSpanMiniList {
    unsigned char Y_delta;
    unsigned char X_start;
    unsigned char X_end;
};

class TSpan_List_Manager {
public:
    // Member Variables (Layout from JSON)
    
    // 0x00 - Size: 60 (0x3C)
    TSpan_Node_List VSList; 

    // 0x3C
    VSpan_Node **Line_Head_Ptrs;
    
    // 0x40
    VSpan_Node **Line_Tail_Ptrs;
    
    // 0x44
    int *LeftMostPx;
    
    // 0x48
    int *RightMostPx;
    
    // 0x4C
    int *Span_Count;
    
    // 0x50
    int Num_Lines;
    
    // 0x54
    int Num_Pixels;
    
    // 0x58
    int Min_Span_Px;
    
    // 0x5C
    int Max_Span_Px;
    
    // 0x60
    int Min_Line;
    
    // 0x64
    int Max_Line;

public:
    // Functions mapped from logic.cpp
    
    TSpan_List_Manager(int width, int height);
    ~TSpan_List_Manager();

    void SetSpanRegions(int x1, int y1, int x2, int y2);
    void ResetAll();
    void AddSpan(int x1, int x2, int y);
    void AddShape(TShape *shape, int frame, int x, int y, int flag);
    void AddShape_Align(unsigned char *data, Shape_Info *info, int x, int y, int flag);
    void AddLine_Align(int x1, int y1, int x2, int y2);
    void AddMiniList(VSpanMiniList *list, int x_off, int y_off);
    void SubtractMiniList(VSpanMiniList *list, int x_off, int y_off);
    void DeleteSpan(int x1, int x2, int y);
    void DeleteShape(TShape *shape, int frame, int x, int y, int flag);
    int PointVisible(int x, int y);
    void Merge_n_Align(TSpan_List_Manager *list1, TSpan_List_Manager *list2);
    void AlignamizeSpans();
    void ScrollSpansHorizontally(int dx, int clip);
    void ScrollSpansVertically(int dy, int clip);
    int ValidateSpan(int line);
    int DecodeLine(unsigned char *buffer, int y, unsigned char color, int width);
    
    // Snapshot function
    void take_snapshot(char *filename_fmt, int *seq, TDrawArea *draw_area, int color_base, TSpan_List_Manager **others, int *colors, int count);
};

// MANDATORY VERIFICATION
static_assert(sizeof(TSpan_List_Manager) == 0x68, "TSpan_List_Manager size mismatch");
static_assert(offsetof(TSpan_List_Manager, VSList) == 0x0, "TSpan_List_Manager::VSList offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Line_Head_Ptrs) == 0x3C, "TSpan_List_Manager::Line_Head_Ptrs offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Line_Tail_Ptrs) == 0x40, "TSpan_List_Manager::Line_Tail_Ptrs offset mismatch");
static_assert(offsetof(TSpan_List_Manager, LeftMostPx) == 0x44, "TSpan_List_Manager::LeftMostPx offset mismatch");
static_assert(offsetof(TSpan_List_Manager, RightMostPx) == 0x48, "TSpan_List_Manager::RightMostPx offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Span_Count) == 0x4C, "TSpan_List_Manager::Span_Count offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Num_Lines) == 0x50, "TSpan_List_Manager::Num_Lines offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Num_Pixels) == 0x54, "TSpan_List_Manager::Num_Pixels offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Min_Span_Px) == 0x58, "TSpan_List_Manager::Min_Span_Px offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Max_Span_Px) == 0x5C, "TSpan_List_Manager::Max_Span_Px offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Min_Line) == 0x60, "TSpan_List_Manager::Min_Line offset mismatch");
static_assert(offsetof(TSpan_List_Manager, Max_Line) == 0x64, "TSpan_List_Manager::Max_Line offset mismatch");