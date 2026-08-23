// 004BE690 TSpan_List_Manager::AlignamizeSpans
// Source: spanlist.cpp:1485-1536
// Attempt log:
// - Baseline used the proven node/base layout and natural span-list traversal;
//   VC5 selected the wrong callee-save pair and inverted the null/merge block.
// - Rewrote the inner guard as positive next/non-overlap/merge arms and modeled
//   VSList as the proven offset-zero member; size and block topology aligned.
// - Keeping the aligned EndPx value in an explicit int local reproduces the
//   original carried compare/store scheduling; exact match at probe 7.

#ifndef SPANLIST_SHARED_CONTEXT
struct VSpan_Node {
    VSpan_Node* Next;      // +0x00
    VSpan_Node* Prev;      // +0x04
    int StartPx;           // +0x08
    int EndPx;             // +0x0C
};

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;       // +0x00
    int* Zone_Size_Ptrs;          // +0x04
    int Used_Zones;               // +0x08
    int Max_Zones;                // +0x0C
    VSpan_Node* Free_Head;        // +0x10
    int Free_Pool_Zone;           // +0x14
    int Free_Pool_Index;          // +0x18
    int Total_Blocks;             // +0x1C
    int Free_Blocks;              // +0x20
    int Default_Grow_Size;        // +0x24
    int Element_Size;             // +0x28
    int Alloc_Count;              // +0x2C
    int Dealloc_Count;            // +0x30
    int NewZone_Count;            // +0x34
    int Reset_Count;              // +0x38

    void FreeNode(VSpan_Node* node);
};

class TSpan_List_Manager {
public:
    TSpan_Node_List VSList;        // +0x00
    VSpan_Node** Line_Head_Ptrs;  // +0x3C
    VSpan_Node** Line_Tail_Ptrs;  // +0x40
    int* LeftMostPx;              // +0x44
    int* RightMostPx;             // +0x48
    int* Span_Count;              // +0x4C
    int Num_Lines;                // +0x50
    int Num_Pixels;               // +0x54
    int Min_Span_Px;              // +0x58
    int Max_Span_Px;              // +0x5C
    int Min_Line;                 // +0x60
    int Max_Line;                 // +0x64

    void AlignamizeSpans();
};
#endif

void TSpan_List_Manager::AlignamizeSpans()
{
    int i = 0;

    if (0 < this->Num_Lines) {
        do {
            VSpan_Node* node = this->Line_Head_Ptrs[i];

            while (node != 0) {
                VSpan_Node* next = node->Next;

                node->StartPx = node->StartPx & ~3;
                int end = node->EndPx | 3;
                node->EndPx = end;

                if (next != 0) {
                    if (end >= ((next->StartPx & 0x7FFFFFFC) - 1)) {
                        node->EndPx = next->EndPx | 3;
                        node->Next = next->Next;

                        if (next == this->Line_Tail_Ptrs[i]) {
                            this->Line_Tail_Ptrs[i] = node;
                        }

                        if (next->Next != 0) {
                            next->Next->Prev = node;
                        }

                        this->VSList.FreeNode(next);
                        this->Span_Count[i] = this->Span_Count[i] - 1;
                    } else {
                        node = node->Next;
                    }
                } else {
                    node = 0;
                }
            }

            int next_i = i + 1;
            this->LeftMostPx[i] = this->Line_Head_Ptrs[i]->StartPx;
            this->RightMostPx[i] = this->Line_Tail_Ptrs[i]->EndPx;
            i = next_i;
        } while (i < this->Num_Lines);
    }
}
