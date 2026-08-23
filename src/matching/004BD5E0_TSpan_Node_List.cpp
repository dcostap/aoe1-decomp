#ifndef SPANLIST_SHARED_CONTEXT
class VSpan_Node;
class TSpan_Node_List { public:
    VSpan_Node** Zone_Ptrs; int* Zone_Size_Ptrs; int Used_Zones; int Max_Zones; VSpan_Node* Free_Head; int Free_Pool_Zone; int Free_Pool_Index; int Total_Blocks; int Free_Blocks; int Default_Grow_Size; int Element_Size; int Alloc_Count; int Dealloc_Count; int NewZone_Count; int Reset_Count;
    TSpan_Node_List(int, int, int); void ResetStats(); void SetNumZones(int); void InitNewZone(int);
};
#endif
TSpan_Node_List::TSpan_Node_List(int p1, int p2, int p3)
    : Free_Pool_Zone(-1), Free_Pool_Index(-1), Zone_Ptrs(0), Zone_Size_Ptrs(0), Used_Zones(0), Free_Head(0), Total_Blocks(0), Free_Blocks(0), Max_Zones(8), Default_Grow_Size(p2), Element_Size(p3)
{
    this->ResetStats();
    this->SetNumZones(8);
    this->InitNewZone(p1);
}
