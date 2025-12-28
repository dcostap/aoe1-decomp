#pragma once

#include <stdlib.h>

struct VSpan_Node;

class TSpan_Node_List {
public:
    // 0x00
    VSpan_Node **Zone_Ptrs;
    
    // 0x04
    int *Zone_Size_Ptrs;
    
    // 0x08
    int Used_Zones;
    
    // 0x0C
    int Max_Zones;
    
    // 0x10
    VSpan_Node *Free_Head;
    
    // 0x14
    int Free_Pool_Zone;
    
    // 0x18
    int Free_Pool_Index;
    
    // 0x1C
    int Total_Blocks;
    
    // 0x20
    int Free_Blocks;
    
    // 0x24
    int Default_Grow_Size;
    
    // 0x28
    int Element_Size;
    
    // 0x2C
    int Alloc_Count;
    
    // 0x30
    int Dealloc_Count;
    
    // 0x34
    int NewZone_Count;
    
    // 0x38
    int Reset_Count;

public:
    TSpan_Node_List(int initial_size, int grow_size, int element_size);
    ~TSpan_Node_List();

    VSpan_Node* GetNode();
    void FreeNode(VSpan_Node *node);
    int FreeThread(VSpan_Node *head, VSpan_Node *tail);
    void ReclaimAllNodes();
    void ResetStats();

private:
    void SetNumZones(int count);
    void InitNewZone(int size);
};

// MANDATORY VERIFICATION
static_assert(sizeof(TSpan_Node_List) == 0x3C, "TSpan_Node_List size mismatch");
static_assert(offsetof(TSpan_Node_List, Zone_Ptrs) == 0x0, "TSpan_Node_List::Zone_Ptrs offset mismatch");
static_assert(offsetof(TSpan_Node_List, Zone_Size_Ptrs) == 0x4, "TSpan_Node_List::Zone_Size_Ptrs offset mismatch");
static_assert(offsetof(TSpan_Node_List, Used_Zones) == 0x8, "TSpan_Node_List::Used_Zones offset mismatch");
static_assert(offsetof(TSpan_Node_List, Max_Zones) == 0xC, "TSpan_Node_List::Max_Zones offset mismatch");
static_assert(offsetof(TSpan_Node_List, Free_Head) == 0x10, "TSpan_Node_List::Free_Head offset mismatch");
static_assert(offsetof(TSpan_Node_List, Free_Pool_Zone) == 0x14, "TSpan_Node_List::Free_Pool_Zone offset mismatch");
static_assert(offsetof(TSpan_Node_List, Free_Pool_Index) == 0x18, "TSpan_Node_List::Free_Pool_Index offset mismatch");
static_assert(offsetof(TSpan_Node_List, Total_Blocks) == 0x1C, "TSpan_Node_List::Total_Blocks offset mismatch");
static_assert(offsetof(TSpan_Node_List, Free_Blocks) == 0x20, "TSpan_Node_List::Free_Blocks offset mismatch");
static_assert(offsetof(TSpan_Node_List, Default_Grow_Size) == 0x24, "TSpan_Node_List::Default_Grow_Size offset mismatch");
static_assert(offsetof(TSpan_Node_List, Element_Size) == 0x28, "TSpan_Node_List::Element_Size offset mismatch");
static_assert(offsetof(TSpan_Node_List, Alloc_Count) == 0x2C, "TSpan_Node_List::Alloc_Count offset mismatch");
static_assert(offsetof(TSpan_Node_List, Dealloc_Count) == 0x30, "TSpan_Node_List::Dealloc_Count offset mismatch");
static_assert(offsetof(TSpan_Node_List, NewZone_Count) == 0x34, "TSpan_Node_List::NewZone_Count offset mismatch");
static_assert(offsetof(TSpan_Node_List, Reset_Count) == 0x38, "TSpan_Node_List::Reset_Count offset mismatch");