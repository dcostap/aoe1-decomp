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

struct VSpan_Node {
    VSpan_Node* Next;
    VSpan_Node* Prev;
    int StartPx;
    int EndPx;
};

class TSpan_List_Manager {
public:
    char gap_00[0x3C];
    VSpan_Node** Heads;
    VSpan_Node** Tails;
    int* LineStarts;
    int* LineEnds;
    int* Counts;
    char gap_50[8];
    int minX;
    int maxX;
    int minLine;
    int maxLine;

    VSpan_Node* GetNode();
    void FreeNode(VSpan_Node* node);
    int FreeThread(VSpan_Node* first, VSpan_Node* second);
    void DeleteSpan(int left, int right, int line);
};

void TSpan_List_Manager::DeleteSpan(int left, int right, int line)
{
    if (line < this->minLine || line > this->maxLine) return;

    if (left > right) {
        int t = left;
        left = right;
        right = t;
    }
    if (right < this->minX || left > this->maxX) return;
    if (left < this->minX) left = this->minX;
    if (right > this->maxX) right = this->maxX;

    int off = line * 4;
    VSpan_Node* head = *(VSpan_Node**)((char*)this->Heads + off);
    if (head == 0) return;
    int lineStart = *(int*)((char*)this->LineStarts + off);
    if (right < lineStart) return;
    int lineEnd = *(int*)((char*)this->LineEnds + off);
    if (left > lineEnd) return;

    if (left <= lineStart && right >= lineEnd) {
        VSpan_Node* tail = *(VSpan_Node**)((char*)this->Tails + off);
        this->FreeThread(head, tail);
        *(VSpan_Node**)((char*)this->Heads + off) = 0;
        *(VSpan_Node**)((char*)this->Tails + off) = 0;
        *(int*)((char*)this->Counts + off) = 0;
        *(int*)((char*)this->LineStarts + off) = 0;
        *(int*)((char*)this->LineEnds + off) = 0;
        return;
    }

    VSpan_Node* first = head;
    VSpan_Node* savedHead = head;
    VSpan_Node* last = *(VSpan_Node**)((char*)this->Tails + off);

    while (first->EndPx < left) {
        first = first->Next;
    }

    if (left > first->StartPx && right < first->EndPx) {
        VSpan_Node* node = this->GetNode();
        node->Prev = first;
        node->Next = first->Next;
        first->Next = node;
        if (node->Next != 0) node->Next->Prev = node;
        if (first == last) *(VSpan_Node**)((char*)this->Tails + off) = node;
        node->StartPx = right + 1;
        node->EndPx = first->EndPx;
        first->EndPx = left - 1;
        (*(int*)((char*)this->Counts + off))++;
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
            this->FreeNode(first);
            (*(int*)((char*)this->Counts + off))--;
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
    *(VSpan_Node**)((char*)this->Heads + off) = savedHead;
    *(VSpan_Node**)((char*)this->Tails + off) = last;
    if (savedHead != 0) savedHead->Prev = 0;
    if (last != 0) last->Next = 0;
}
