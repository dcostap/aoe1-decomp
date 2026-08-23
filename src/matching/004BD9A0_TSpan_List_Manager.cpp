// 004BD9A0 ~TSpan_List_Manager
// Free 5 manager-owned arrays, then auto-destruct base class.
// Removing explicit base destructor call — VC5 auto-generates it.

#include <stdlib.h>

#ifndef SPANLIST_SHARED_CONTEXT
class VSpan_Node;

class TSpan_Node_List {
public:
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

    ~TSpan_Node_List();
};

class TSpan_List_Manager : public TSpan_Node_List {
public:
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

    ~TSpan_List_Manager();
};
#endif

TSpan_List_Manager::~TSpan_List_Manager() {
    if (Line_Head_Ptrs != 0) free(Line_Head_Ptrs);
    if (Line_Tail_Ptrs != 0) free(Line_Tail_Ptrs);
    if (LeftMostPx != 0) free(LeftMostPx);
    if (RightMostPx != 0) free(RightMostPx);
    if (Span_Count != 0) free(Span_Count);
}
