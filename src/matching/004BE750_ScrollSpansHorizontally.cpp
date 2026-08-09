// 004BE750 TSpan_List_Manager::ScrollSpansHorizontally
// Source: spanlist.cpp:1544-1608
// Attempt log:
// - Initial source was only a layout stub; reconstructed the natural span-node
//   traversal and region clipping from the original CFG and exact spanlist.cpp
//   donors.  Baseline: exact size/frame/calls/CFG except two compare operand
//   spellings (4 strict bytes).
// - Spelled the non-overlap test as `start > Max_Span_Px`; this reproduced the
//   original `cmp start,max; jg` pair and reduced the drift to 2 bytes.
// - Spelled the upper clamp as `end > Max_Span_Px`; exact match.  The source
//   remains a natural named-field traversal with the proven offset-zero node
//   list ownership; no codegen-only scaffolding or custom flags.

#include <stdlib.h>

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
    VSpan_Node** Line_Head_Ptrs;   // +0x3C
    VSpan_Node** Line_Tail_Ptrs;   // +0x40
    int* LeftMostPx;               // +0x44
    int* RightMostPx;              // +0x48
    int* Span_Count;               // +0x4C
    int Num_Lines;                 // +0x50
    int Num_Pixels;                // +0x54
    int Min_Span_Px;               // +0x58
    int Max_Span_Px;               // +0x5C
    int Min_Line;                  // +0x60
    int Max_Line;                  // +0x64

    void ResetAll();
    void ScrollSpansHorizontally(int dx, int use_regions);
};

void TSpan_List_Manager::ScrollSpansHorizontally(int dx, int use_regions)
{
    if (dx != 0) {
        if (use_regions != 0 && abs(dx) > this->Max_Span_Px - this->Min_Span_Px) {
            this->ResetAll();
            return;
        }

        int line = 0;
        if (0 < this->Num_Lines) {
            do {
                VSpan_Node* node = this->Line_Head_Ptrs[line];

                while (node != 0) {
                    VSpan_Node* next = node->Next;
                    int start = node->StartPx + dx;
                    int end = node->EndPx + dx;
                    VSpan_Node* prev = node->Prev;

                    if (use_regions != 0) {
                        int min = this->Min_Span_Px;
                        if (end < min || start > this->Max_Span_Px) {
                            if (prev != 0) {
                                prev->Next = next;
                            }
                            if (next != 0) {
                                next->Prev = prev;
                            }
                            this->VSList.FreeNode(node);
                            this->Span_Count[line] = this->Span_Count[line] - 1;
                            node = 0;
                        } else {
                            if (start < min) {
                                start = min;
                            }
                            if (end > this->Max_Span_Px) {
                                end = this->Max_Span_Px;
                            }
                        }
                    }

                    if (node != 0) {
                        node->StartPx = start;
                        node->EndPx = end;
                    }

                    node = next;
                }

                line++;
            } while (line < this->Num_Lines);
        }
    }
}
