#pragma once
#include "common.h"

class TSpan_List_Manager {
public:
    TSpan_Node_List VSList;                  // 0x0
    VSpan_Node** Line_Head_Ptrs;             // 0x3C
    VSpan_Node** Line_Tail_Ptrs;             // 0x40
    int* LeftMostPx;                         // 0x44
    int* RightMostPx;                        // 0x48
    int* Span_Count;                         // 0x4C
    int Num_Lines;                           // 0x50
    int Num_Pixels;                          // 0x54
    int Min_Span_Px;                         // 0x58
    int Max_Span_Px;                         // 0x5C
    int Min_Line;                            // 0x60
    int Max_Line;                            // 0x64

    TSpan_List_Manager(int param_1, int param_2);
    ~TSpan_List_Manager();
    void SetSpanRegions(int param_1, int param_2, int param_3, int param_4);
    void ResetAll();
    void AddSpan(int param_1, int param_2, int param_3);
    void AddShape(TShape* param_1, int param_2, int param_3, int param_4, int param_5);
    void AddShape_Align(uchar* param_1, Shape_Info* param_2, int param_3, int param_4, int param_5);
    void AddLine_Align(int param_1, int param_2, int param_3, int param_4);
    void AddMiniList(VSpanMiniList* param_1, int param_2, int param_3);
    void SubtractMiniList(VSpanMiniList* param_1, int param_2, int param_3);
    void DeleteSpan(int param_1, int param_2, int param_3);
    void DeleteShape(TShape* param_1, int param_2, int param_3, int param_4, int param_5);
    int PointVisible(int param_1, int param_2);
    void Merge_n_Align(TSpan_List_Manager* param_1, TSpan_List_Manager* param_2);
    void AlignamizeSpans();
    void ScrollSpansHorizontally(int param_1, int param_2);
    void ScrollSpansVertically(int param_1, int param_2);
    int ValidateSpan(int param_1);
    int DecodeLine(uchar* param_1, int param_2, uchar param_3, int param_4);
    void take_snapshot(char* param_1, int* param_2, TDrawArea* param_3, int param_4, TSpan_List_Manager** param_5, int* param_6, int param_7);
};

static_assert(sizeof(TSpan_List_Manager) == 0x68, "TSpan_List_Manager Size Mismatch");

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;                  // 0x0
    int* Zone_Size_Ptrs;                     // 0x4
    int Used_Zones;                          // 0x8
    int Max_Zones;                           // 0xC
    VSpan_Node* Free_Head;                   // 0x10
    int Free_Pool_Zone;                      // 0x14
    int Free_Pool_Index;                     // 0x18
    int Total_Blocks;                        // 0x1C
    int Free_Blocks;                         // 0x20
    int Default_Grow_Size;                   // 0x24
    int Element_Size;                        // 0x28
    int Alloc_Count;                         // 0x2C
    int Dealloc_Count;                       // 0x30
    int NewZone_Count;                       // 0x34
    int Reset_Count;                         // 0x38

    TSpan_Node_List(int param_1, int param_2, int param_3);
    ~TSpan_Node_List();
    void SetNumZones(int param_1);
    void InitNewZone(int param_1);
    VSpan_Node* GetNode();
    void FreeNode(VSpan_Node* param_1);
    int FreeThread(VSpan_Node* param_1, VSpan_Node* param_2);
    void ReclaimAllNodes();
    void ResetStats();
};

static_assert(sizeof(TSpan_Node_List) == 0x3C, "TSpan_Node_List Size Mismatch");

