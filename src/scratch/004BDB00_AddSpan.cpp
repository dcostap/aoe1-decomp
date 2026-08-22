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
// compare-algebra probes: spell each observed boundary in the original
// operand order (end >= RightMostPx, end+1 < node StartPx, start >= other
// StartPx, start-1 > previous EndPx, and node StartPx > end+1). These forms
// expose four more exact blocks and improve shape/resync similarity without
// changing calls, frame, size, or the first structural hunk.
// an old-node alias around the left drain moved five positional bytes closer
// but worsened shape and size; restored the simpler ownership form.
// memory.h context and function-scope temporary-node declarations were
// codegen duplicates; retained the period-plausible stdlib-only context.
// fresh claim baseline: diff 729, size 924, shape 87.39%, calls 9/9.
// entry tail-first declaration/use order improved diff to 612 but added 2 bytes.
// A branch-local end+1 boundary and do/while left drain improved diff to 607;
// an old-tail/previous-node split then improved diff to 593 and size +6.
// Rewriting the left old-node split, count entry pointer, and middle old/next
// split was worse or lost exact blocks; direct header and register probes did
// not change the emitted basin. A 16-way lab found no exact variant; tail-first
// plus do/while was the strongest group, with no size/frame/call-set invariant.
// final clean source: typed natural reconstruction, diff 593, size 922,
// shape 86.83%, exact blocks 55.74%, calls 9/9; first mismatch remains +0F.
// retained: natural typed source; unresolved pointer scheduling and late block
// placement leave a broad non-exact codegen gap, so this target stays scratch.
// revisit direct member reads: removing the left and right boundary scalar
// aliases reduced the strict diff to 589 with the same size, CFG, and calls.
// A function-scope boundary, direct end+1 spelling, and direct RightMostPx
// rereads were codegen duplicates; the branch-local boundary is simpler.
// Current best: diff 589, size 922, shape 86.83%, exact blocks 55.74%, calls
// 9/9; first mismatch remains +0F and the central drain CFG remains non-exact.

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

    other = this->Line_Tail_Ptrs[line];
    if (start <= this->LeftMostPx[line]) {
        if (end < this->LeftMostPx[line] - 1) {
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

        if (end >= this->RightMostPx[line]) {
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
        int boundary = end;
        boundary++;
        if (boundary >= node->StartPx) {
            do {
                if (end <= node->EndPx) {
                    node->StartPx = start;
                    return;
                }
                other = node->Next;
                if (boundary < other->StartPx) {
                    break;
                }
                this->Line_Head_Ptrs[line] = other;
                other->Prev = 0;
                this->VSList.FreeNode(node);
                this->Span_Count[line] = this->Span_Count[line] - 1;
                node = other;
                if (boundary < other->StartPx) {
                    return;
                }
            } while (1);
            node->StartPx = start;
            node->EndPx = end;
        }
    } else {
        if (end >= this->RightMostPx[line]) {
            if (start > this->RightMostPx[line] + 1) {
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
            if (start - 1 <= other->EndPx) {
                while (1) {
                    if (start >= other->StartPx) {
                        other->EndPx = end;
                        return;
                    }
                    node = other;
                    other = other->Prev;
                    if (start - 1 > other->EndPx) {
                        break;
                    }
                    this->Line_Tail_Ptrs[line] = other;
                    other->Next = 0;
                    this->VSList.FreeNode(node);
                    this->Span_Count[line] = this->Span_Count[line] - 1;
                    node = other;
                    if (other->EndPx < start - 1) {
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

            if (node->StartPx > end + 1) {
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
