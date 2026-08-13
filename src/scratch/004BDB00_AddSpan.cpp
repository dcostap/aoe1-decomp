// 004BDB00 TSpan_List_Manager::AddSpan
// spanlist.cpp
// Attempt log:
// baseline: retained the prior broad reconstruction before this fresh typed pass.
// typed pass: model VSList as the real member object and use named span arrays;
// positional diff improved, but the first call basin reordered the drain paths.
// control-flow probe: left-side fallthrough before right-side code restored all
// nine direct calls in order; an append-first right-side branch kept that order.
// behavior audit: clipping, empty-row allocation, head/tail insertion, overlap,
// node draining, count updates, and tail/head ordering follow the original asm.
// pointer-entry probes did not improve the VC5 setup and were rolled back.
// structural CFG probe: internal-first right-side source reached diff 606 but
// reordered the call sites; restored the append-first source for call parity.
// tail-order probe: loading the tail pointer before LeftMost kept call parity
// but reached diff 614 and was a duplicate of an earlier codegen group.
// delayed-entry probe: named LeftMost array/entry after tail load reached diff
// 619 with no new exact blocks; restored the clean direct-member source.
// inheritance-layout probe: the same public TSpan_Node_List base as the
// constructor and exact siblings emitted the same bytes; restored nested
// member ownership because this lead did not change the structural hunk.
// retained: natural typed source; unresolved pointer scheduling and late block
// placement leave a broad non-exact codegen gap, so this target stays scratch.

#include <stdlib.h>

struct VSpan_Node {
    VSpan_Node* Next;
    VSpan_Node* Prev;
    int StartPx;
    int EndPx;
};

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

    VSpan_Node* GetNode();
    void FreeNode(VSpan_Node* node);
    int FreeThread(VSpan_Node* first, VSpan_Node* last);
};

class TSpan_List_Manager {
public:
    TSpan_Node_List VSList;
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

    void AddSpan(int start, int end, int line);
};

void TSpan_List_Manager::AddSpan(int start, int end, int line)
{
    VSpan_Node* node;
    VSpan_Node* other;
    VSpan_Node* next;
    int temp;

    if (line < this->Min_Line || line > this->Max_Line) {
        return;
    }

    if (start > end) {
        temp = end;
        end = start;
        start = temp;
    }

    if (end < this->Min_Span_Px || start > this->Max_Span_Px) {
        return;
    }
    if (start < this->Min_Span_Px) {
        start = this->Min_Span_Px;
    }
    if (end > this->Max_Span_Px) {
        end = this->Max_Span_Px;
    }

    node = this->Line_Head_Ptrs[line];
    if (node == 0) {
        node = this->VSList.GetNode();
        node->Prev = 0;
        node->Next = 0;
        node->StartPx = start;
        node->EndPx = end;
        this->Line_Head_Ptrs[line] = node;
        this->Line_Tail_Ptrs[line] = node;
        this->LeftMostPx[line] = start;
        this->RightMostPx[line] = end;
        this->Span_Count[line] = this->Span_Count[line] + 1;
        return;
    }

    temp = this->LeftMostPx[line];
    other = this->Line_Tail_Ptrs[line];
    if (start <= temp) {
        if (end < temp - 1) {
            other = this->VSList.GetNode();
            other->Prev = 0;
            other->Next = node;
            node->Prev = other;
            other->StartPx = start;
            other->EndPx = end;
            this->LeftMostPx[line] = start;
            this->Line_Head_Ptrs[line] = other;
            this->Span_Count[line] = this->Span_Count[line] + 1;
            return;
        }

        if (this->RightMostPx[line] <= end) {
            int* count = this->Span_Count;
            temp = this->VSList.FreeThread(node->Next, 0);
            count[line] = count[line] - temp;
            node->Prev = 0;
            node->Next = 0;
            node->StartPx = start;
            node->EndPx = end;
            this->Line_Tail_Ptrs[line] = node;
            this->RightMostPx[line] = end;
            this->LeftMostPx[line] = start;
            return;
        }

        this->LeftMostPx[line] = start;
        temp = end + 1;
        if (node->StartPx <= temp) {
            while (1) {
                if (end <= node->EndPx) {
                    node->StartPx = start;
                    return;
                }
                other = node->Next;
                if (temp < other->StartPx) {
                    break;
                }
                this->Line_Head_Ptrs[line] = other;
                other->Prev = 0;
                this->VSList.FreeNode(node);
                this->Span_Count[line] = this->Span_Count[line] - 1;
                node = other;
                if (temp < other->StartPx) {
                    return;
                }
            }
            node->StartPx = start;
            node->EndPx = end;
        }
    } else {
        temp = this->RightMostPx[line];
        if (end >= temp) {
            if (temp + 1 < start) {
                node = this->VSList.GetNode();
                node->Prev = other;
                node->Next = 0;
                other->Next = node;
                node->StartPx = start;
                node->EndPx = end;
                this->RightMostPx[line] = end;
                this->Line_Tail_Ptrs[line] = node;
                this->Span_Count[line] = this->Span_Count[line] + 1;
                return;
            }

            this->RightMostPx[line] = end;
            temp = start - 1;
            if (temp <= other->EndPx) {
                while (1) {
                    if (other->StartPx <= start) {
                        other->EndPx = end;
                        return;
                    }
                    node = other->Prev;
                    if (node->EndPx < temp) {
                        break;
                    }
                    this->Line_Tail_Ptrs[line] = node;
                    node->Next = 0;
                    this->VSList.FreeNode(other);
                    this->Span_Count[line] = this->Span_Count[line] - 1;
                    other = node;
                    if (node->EndPx < temp) {
                        return;
                    }
                }
                other->StartPx = start;
                other->EndPx = end;
            }
        } else {
            while (node->EndPx < start - 1) {
                node = node->Next;
            }

            if (end + 1 < node->StartPx) {
                VSpan_Node* inserted = this->VSList.GetNode();
                other = node->Prev;
                inserted->Next = node;
                inserted->Prev = other;
                node->Prev = inserted;
                inserted->Prev->Next = inserted;
                inserted->StartPx = start;
                inserted->EndPx = end;
                this->Span_Count[line] = this->Span_Count[line] + 1;
                return;
            }

            if (start < node->StartPx) {
                node->StartPx = start;
            }
            if (node->EndPx < end) {
                next = node->Next;
                if (next != 0) {
                    while (1) {
                        if (end + 1 < next->StartPx) {
                            node->EndPx = end;
                            return;
                        }
                        if (end <= next->EndPx) {
                            break;
                        }
                        if (next->Prev != 0) {
                            next->Prev->Next = next->Next;
                        }
                        if (next->Next != 0) {
                            next->Next->Prev = next->Prev;
                        }
                        VSpan_Node* after = next->Next;
                        this->VSList.FreeNode(next);
                        this->Span_Count[line] = this->Span_Count[line] - 1;
                        next = after;
                        if (next == 0) {
                            return;
                        }
                    }
                    node->EndPx = next->EndPx;
                    node->Next = next->Next;
                    this->VSList.FreeNode(next);
                    this->Span_Count[line] = this->Span_Count[line] - 1;
                    if (node->Next != 0) {
                        node->Next->Prev = node;
                        return;
                    }
                    this->Line_Tail_Ptrs[line] = node;
                }
            }
        }
    }
}
