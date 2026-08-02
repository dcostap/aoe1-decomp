// 004BD8B0 TSpan_List_Manager::TSpan_List_Manager
// Source: spanlist.cpp (334-351, 234 bytes)
// FLAGS: config/flags/004BD8B0_TSpan_List_Manager.rsp (/GX for the EH-framed ctor)
//
// /GX constructor frame: base TSpan_Node_List is nontrivial (ctor + dtor), and
// the derived body calls C++ member SetSpanRegions after base construction, so
// VC5 emits the fs:[0] state-tracking frame (state -1 -> 0 after base ctor).
// calloc stays extern "C" via <stdlib.h> for the C symbol relocation.

#include <stdlib.h>

class VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;    // +0x00
    int* Zone_Size_Ptrs;       // +0x04
    int Used_Zones;            // +0x08
    int Max_Zones;             // +0x0C
    VSpan_Node* Free_Head;     // +0x10
    int Free_Pool_Zone;        // +0x14
    int Free_Pool_Index;       // +0x18
    int Total_Blocks;          // +0x1C
    int Free_Blocks;           // +0x20
    int Default_Grow_Size;     // +0x24
    int Element_Size;          // +0x28
    int Alloc_Count;           // +0x2C
    int Dealloc_Count;         // +0x30
    int NewZone_Count;         // +0x34
    int Reset_Count;           // +0x38

    TSpan_Node_List(int, int, int);
    ~TSpan_Node_List();
};

class TSpan_List_Manager : public TSpan_Node_List {
public:
    VSpan_Node** Line_Head_Ptrs; // +0x3C
    VSpan_Node** Line_Tail_Ptrs; // +0x40
    int* LeftMostPx;             // +0x44
    int* RightMostPx;            // +0x48
    int* Span_Count;             // +0x4C
    int Num_Lines;               // +0x50
    int Num_Pixels;              // +0x54
    int Min_Span_Px;             // +0x58
    int Max_Span_Px;             // +0x5C
    int Min_Line;                // +0x60
    int Max_Line;                // +0x64

    TSpan_List_Manager(int NumPixels, int NumLines);
    ~TSpan_List_Manager();
    void SetSpanRegions(int, int, int, int);
};

TSpan_List_Manager::TSpan_List_Manager(int NumPixels, int NumLines)
    : TSpan_Node_List(((NumPixels + 31) / 32) * NumLines, NumLines << 4, 0x10)
{
    this->Num_Lines = NumLines;
    if (NumLines < 0x10) this->Num_Lines = 0x10;
    this->Num_Pixels = NumPixels;
    if (NumPixels < 0x10) this->Num_Pixels = 0x10;
    this->SetSpanRegions(0, 0, this->Num_Pixels - 1, this->Num_Lines - 1);
    this->Line_Head_Ptrs = (VSpan_Node**)calloc(this->Num_Lines, 4);
    this->Line_Tail_Ptrs = (VSpan_Node**)calloc(this->Num_Lines, 4);
    this->LeftMostPx = (int*)calloc(this->Num_Lines, 4);
    this->RightMostPx = (int*)calloc(this->Num_Lines, 4);
    this->Span_Count = (int*)calloc(this->Num_Lines, 4);
}
