// first pass: free the five manager-owned arrays in packet order, then run the embedded span-list destructor
// tried member-call vs explicit base-call spelling; the only remaining diff is the tail pop/return after the helper call
// leaving this in scratch because the body is behaviorally right and the mismatch is now localized to the final epilog basin
#include <stdlib.h>

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

TSpan_List_Manager::~TSpan_List_Manager() {
    if (Line_Head_Ptrs != 0) free(Line_Head_Ptrs);
    if (Line_Tail_Ptrs != 0) free(Line_Tail_Ptrs);
    if (LeftMostPx != 0) free(LeftMostPx);
    if (RightMostPx != 0) free(RightMostPx);
    if (Span_Count != 0) free(Span_Count);
    this->TSpan_Node_List::~TSpan_Node_List();
}
