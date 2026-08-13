// VA: 004BE290 TSpan_List_Manager::DeleteSpan
// Attempt log:
// try 1: direct reconstruction from packet asm; local stack slots for first/last node and line offset.
// try 2: initial class inheritance made all manager fields 0x30 too early; switched to flat manager layout.
// try 3: added gap_50 so minX/maxX/minLine/maxLine land at +0x58/+0x5C/+0x60/+0x64; first mismatch moved to 004BE2FD.
// try 4: direct member-index expressions versus byte-offset expressions were neutral.
// try 5: declaring lineStart/lineEnd before head was neutral.
// try 6: rechecking head through member expression to avoid preserving it in ESI was neutral.
// try 7: /GX was neutral and unjustified; removed flag.
// try 8: split-node insertion and middle deletion modeled from asm; behavior appears right but codegen differs.
// try 9: all-covered fast path modeled and calls FreeThread with head/tail; only register choices differ in this block.
// try 10: final tail/head/count update modeled; remaining mismatch is broad register allocation/block layout after first span-array loads.
// left in scratch: not accepted-drift-safe; first mismatch is head kept in ESI instead of EAX and lineStart/lineEnd in ECX/EAX instead of ESI/ECX, cascading through split/delete cases.
// session baseline: rebuilt 531 bytes with exact frame/saved-register set and 3-call topology; first mismatch at 004BE2FE.
// session layout: restored the proven full TSpan_Node_List base surface and inherited method ABI from exact spanlist donors; bytes were unchanged, but base call relocation identity and source ownership are now canonical.
// session liveness: rereading the unchanged head member in the partial path added 8 bytes and widened the diff; restored.
// session liveness: reordered tail acquisition before first/savedHead; emitted 300 differing bytes and worsened block shape; restored.
// session control-flow: positive nested line/head guards, direct named range fields, and a guarded do/while seek all collapsed to the baseline VC5 codegen basin.
// session context: <stdlib.h> matched the period spanlist translation-unit context but was codegen-neutral for this function.
// session liveness: reusing head as the mutable saved-head value inserted a premature stack store before the null test and widened the diff to 392 bytes; restored.
// final best: canonical inherited manager and named span arrays retain 531-byte size/frame/saves and all three ordered calls; unresolved broad VC5 register/liveness coloring begins at 004BE2FE (299 strict bytes, 56.3089%).
// typed ownership lead: the original final partial-delete path refreshes LeftMostPx/RightMostPx from the retained head/tail; it does not write boundary links here.
// tried typed bound refresh: source now matches the original retained-list metadata, but VC5 moved the prologue and shrank output to 524 bytes; keep this behavior-faithful reconstruction and pause.
// shardA6 control-flow: combined the full-span deletion predicates into the while guard; emitted code was unchanged, so restored the typed retained-bound candidate.
// luna-r2 layout: exact spanlist.cpp manager donors use an embedded offset-zero VSList and qualified node-list calls; composition was tested and emitted code was unchanged.

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
    int FreeThread(VSpan_Node* first, VSpan_Node* second);
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

    void DeleteSpan(int left, int right, int line);
};

void TSpan_List_Manager::DeleteSpan(int left, int right, int line)
{
    if (line < this->Min_Line || line > this->Max_Line) return;

    if (left > right) {
        int t = left;
        left = right;
        right = t;
    }
    if (right < this->Min_Span_Px || left > this->Max_Span_Px) return;
    if (left < this->Min_Span_Px) left = this->Min_Span_Px;
    if (right > this->Max_Span_Px) right = this->Max_Span_Px;

    VSpan_Node* head = this->Line_Head_Ptrs[line];
    if (head != 0) {
        if (right >= this->LeftMostPx[line]) {
            if (left <= this->RightMostPx[line]) {
                if (left <= this->LeftMostPx[line]
                    && right >= this->RightMostPx[line]) {
                    VSpan_Node* tail = this->Line_Tail_Ptrs[line];
                    this->VSList.FreeThread(head, tail);
                    this->Line_Head_Ptrs[line] = 0;
                    this->Line_Tail_Ptrs[line] = 0;
                    this->Span_Count[line] = 0;
                    this->LeftMostPx[line] = 0;
                    this->RightMostPx[line] = 0;
                    return;
                }

                VSpan_Node* first = head;
                VSpan_Node* savedHead = head;
                VSpan_Node* last = this->Line_Tail_Ptrs[line];

                if (first->EndPx < left) {
                    do {
                        first = first->Next;
                    } while (first->EndPx < left);
                }

                if (left > first->StartPx && right < first->EndPx) {
                    VSpan_Node* node = this->VSList.GetNode();
                    node->Prev = first;
                    node->Next = first->Next;
                    first->Next = node;
                    if (node->Next != 0) node->Next->Prev = node;
                    if (first == last) this->Line_Tail_Ptrs[line] = node;
                    node->StartPx = right + 1;
                    node->EndPx = first->EndPx;
                    first->EndPx = left - 1;
                    this->Span_Count[line]++;
                    return;
                }

                if (left > first->EndPx) {
                    first->EndPx = left - 1;
                    first = first->Next;
                }

                while (first != 0) {
                    int cont;
                    if (left <= first->StartPx && right >= first->EndPx) {
                        if (first == savedHead) savedHead = first->Next;
                        if (first == last) last = first->Prev;
                        VSpan_Node* prev = first->Prev;
                        if (prev != 0) prev->Next = first->Next;
                        VSpan_Node* next = first->Next;
                        if (next != 0) next->Prev = first->Prev;
                        VSpan_Node* n = first->Next;
                        this->VSList.FreeNode(first);
                        this->Span_Count[line]--;
                        first = n;
                        cont = 1;
                    } else {
                        cont = 0;
                    }
                    if (cont == 0) break;
                }
                if (first != 0 && right >= first->StartPx) {
                    first->StartPx = right + 1;
                }
                this->Line_Head_Ptrs[line] = savedHead;
                this->Line_Tail_Ptrs[line] = last;
                this->LeftMostPx[line] = savedHead->StartPx;
                this->RightMostPx[line] = last->EndPx;
            }
        }
    }
}
