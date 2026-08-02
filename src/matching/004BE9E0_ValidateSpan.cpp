// 004BE9E0 TSpan_List_Manager::ValidateSpan
// Source: spanlist.cpp:1717-1781
// Attempt log:
// - Baseline: canonical node/base/manager layout from matched donors (004BE690
//   AlignamizeSpans); natural validation with bounds guard, empty-line triple
//   check, and node walk (count/prev/prevEnd). Only diff was 6 bytes.
// - Probe 2: spelled StartPx > EndPx (left operand loaded first) instead of
//   EndPx < StartPx so VC5 loads StartPx into esi before EndPx into edx and
//   emits cmp esi,edx; jg. EXACT MATCH at probe 2.

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

    int ValidateSpan(int line);
};

int TSpan_List_Manager::ValidateSpan(int line)
{
    int count = 0;
    int prevEnd = 0;

    if (line >= 0 && line < this->Num_Lines) {
        VSpan_Node* node = this->Line_Head_Ptrs[line];
        if (node == 0) {
            if (this->Line_Tail_Ptrs[line] == 0
                && this->Span_Count[line] == 0
                && this->LeftMostPx[line] == 0) {
                return this->RightMostPx[line] == 0;
            }
        } else {
            VSpan_Node* prev = 0;
            while (node != 0) {
                count++;
                if (count == 1 && node->StartPx != this->LeftMostPx[line]) return 0;
                if (node->Prev != prev) return 0;
                if (node->StartPx > node->EndPx) return 0;
                if (count > 1 && node->StartPx <= prevEnd) return 0;
                prevEnd = node->EndPx;
                prev = node;
                node = node->Next;
            }
            if (this->Span_Count[line] != count) return 0;
            if (this->Line_Tail_Ptrs[line] != prev) return 0;
            if (prev->EndPx != this->RightMostPx[line]) return 0;
            return this->LeftMostPx[line] <= this->RightMostPx[line];
        }
    }
    return 0;
}
