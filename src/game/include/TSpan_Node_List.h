#pragma once
#include "common.h"
#include "VSpan_Node.h"

struct TSpan_Node_List {
    TSpan_Node_List(int initial_zone_size, int default_grow_size, int element_size);
    ~TSpan_Node_List();

    VSpan_Node* GetNode();
    void FreeNode(VSpan_Node* node);
    int FreeThread(VSpan_Node* head, VSpan_Node* tail);
    void ReclaimAllNodes();
    void ResetStats();

private:
    void SetNumZones(int num_zones);
    void InitNewZone(int zone_size);

    VSpan_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    VSpan_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;
};
static_assert(sizeof(TSpan_Node_List) == 0x3C, "Size mismatch");
