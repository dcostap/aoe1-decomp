// 004BDB00 TSpan_Node_List::AddSpan
// spanlist.cpp
// Attempt log:
// try 1: direct reconstruction from asm: bounds clipping, empty row insertion, left/right merge/split cases.
// try 2: modeled structure offsets from packet: Heads +0x3C, Tails +0x40, MinX +0x44, MaxX +0x48, Counts +0x4C, clip x/y at +0x58..+0x64.
// try 3: modeled VSpan_Node as 16 bytes: Next, Prev, Start, End; used matched GetNode/FreeNode/FreeThread member calls.
// try 4: implemented empty-row fast path with head/tail/min/max/count writes; rebuilt size reached original 916B.
// try 5: implemented insert-before-head case when new span is left of current min with gap.
// try 6: implemented full-row replacement case via FreeThread(head->Next,0), resetting the original head node.
// try 7: implemented left-side merge/drain loop, including removal of absorbed old head nodes.
// try 8: implemented right-side append and tail-merge/drain loop.
// try 9: implemented middle insertion/merge cases including unlink/free absorbed nodes and tail update.
// try 10: compared diff: first 15 bytes match, then branch displacements differ; rebuilt uses EBX as scaled row index and EDI as node, while original keeps EDI as scaled row index and EBX as current node.
// try 11: reviewed initial load/swap shape: original loads x2 into EBP then x1 into EAX and writes back to parameter slots; rebuilt loads x1 into EBP and x2 into EDX despite equivalent source. This register-family mismatch propagates through the whole function.
// left in scratch: behavior and size are close/broadly reconstructed, but exact VC5 register allocation/source topology is unresolved. No accepted_drift: broad register/layout drift from near prologue onward.

struct VSpan_Node { VSpan_Node* Next; VSpan_Node* Prev; int Start; int End; };

class TSpan_Node_List {
public:
    char gap_00[0x3C];
    VSpan_Node** Heads;   // +3c left/head
    VSpan_Node** Tails;   // +40 right/tail
    int* MinX;            // +44
    int* MaxX;            // +48
    int* Counts;          // +4c
    char gap_50[8];
    int ClipMinX;         // +58
    int ClipMaxX;         // +5c
    int ClipMinY;         // +60
    int ClipMaxY;         // +64

    VSpan_Node* GetNode();
    void FreeNode(VSpan_Node* n);
    int FreeThread(VSpan_Node* first, VSpan_Node* last);
    void AddSpan(int x1, int x2, int y);
};

void TSpan_Node_List::AddSpan(int x1, int x2, int y) {
    VSpan_Node* node;
    VSpan_Node* cur;
    VSpan_Node* prev;
    VSpan_Node* next;
    int idx;
    int tmp;

    if (y < ClipMinY || y > ClipMaxY) return;
    if (x1 > x2) { tmp = x1; x1 = x2; x2 = tmp; }
    if (x2 < ClipMinX || x1 > ClipMaxX) return;
    if (x1 < ClipMinX) x1 = ClipMinX;
    if (x2 > ClipMaxX) x2 = ClipMaxX;

    idx = y << 2;
    node = *(VSpan_Node**)((char*)Heads + idx);
    if (node == 0) {
        node = GetNode();
        node->Prev = 0;
        node->Next = 0;
        node->Start = x1;
        node->End = x2;
        *(VSpan_Node**)((char*)Heads + idx) = node;
        *(VSpan_Node**)((char*)Tails + idx) = node;
        *(int*)((char*)MinX + idx) = x1;
        *(int*)((char*)MaxX + idx) = x2;
        ++*(int*)((char*)Counts + idx);
        return;
    }

    prev = *(VSpan_Node**)((char*)Tails + idx);
    tmp = *(int*)((char*)MinX + idx);
    if (x1 <= tmp) {
        if (x2 < tmp - 1) {
            cur = GetNode();
            cur->Prev = 0;
            cur->Next = node;
            node->Prev = cur;
            cur->Start = x1;
            cur->End = x2;
            *(int*)((char*)MinX + idx) = x1;
            *(VSpan_Node**)((char*)Heads + idx) = cur;
            ++*(int*)((char*)Counts + idx);
            return;
        }
        if (x2 >= *(int*)((char*)MaxX + idx)) {
            int* pc = (int*)((char*)Counts + idx);
            *pc -= FreeThread(node->Next, 0);
            node->Prev = 0;
            node->Next = 0;
            node->Start = x1;
            node->End = x2;
            *(VSpan_Node**)((char*)Tails + idx) = node;
            *(int*)((char*)MaxX + idx) = x2;
            *(int*)((char*)MinX + idx) = x1;
            return;
        }
        *(int*)((char*)MinX + idx) = x1;
        tmp = node->Start;
        ++x2;
        cur = node;
        if (x2 < tmp) return;
        do {
            if (x2 <= node->End) {
                cur->Start = x1;
                return;
            }
            node = node->Next;
            if (x2 < node->Start) {
                cur->Start = x1;
                cur->End = tmp;
                return;
            }
            *(VSpan_Node**)((char*)Heads + idx) = node;
            node->Prev = 0;
            FreeNode(cur);
            --*(int*)((char*)Counts + idx);
            tmp = node->Start;
            cur = node;
        } while (x2 >= tmp);
        return;
    }

    tmp = *(int*)((char*)MaxX + idx);
    if (x2 >= tmp) {
        tmp++;
        if (x1 > tmp) {
            cur = GetNode();
            cur->Prev = prev;
            cur->Next = 0;
            prev->Next = cur;
            cur->Start = x1;
            cur->End = x2;
            *(int*)((char*)MaxX + idx) = x2;
            *(VSpan_Node**)((char*)Tails + idx) = cur;
            ++*(int*)((char*)Counts + idx);
            return;
        }
        prev->End = x2;
        node = prev;
        tmp = x1 - 1;
        if (tmp > prev->End) return;
        do {
            if (x1 >= prev->Start) {
                node->End = x2;
                return;
            }
            prev = prev->Prev;
            if (tmp > prev->End) {
                node->Start = x1;
                node->End = x2;
                return;
            }
            *(VSpan_Node**)((char*)Tails + idx) = prev;
            prev->Next = 0;
            FreeNode(node);
            --*(int*)((char*)Counts + idx);
            x1 = prev->End;
            node = prev;
        } while (tmp <= x1);
        return;
    }

    while (node->End < x1 - 1) node = node->Next;
    tmp = x2 + 1;
    if (node->Start > tmp) {
        cur = GetNode();
        cur->Next = node;
        cur->Prev = node->Prev;
        node->Prev = cur;
        cur->Prev->Next = cur;
        cur->Start = x1;
        cur->End = x2;
        ++*(int*)((char*)Counts + idx);
        return;
    }
    if (x1 < node->Start) node->Start = x1;
    if (node->End >= x2) return;
    prev = node->Next;
    if (prev == 0) return;
    while (tmp >= prev->Start) {
        if (x2 <= prev->End) {
            node->End = prev->End;
            node->Next = prev->Next;
            FreeNode(prev);
            --*(int*)((char*)Counts + idx);
            if (node->Next) node->Next->Prev = node;
            else *(VSpan_Node**)((char*)Tails + idx) = node;
            return;
        }
        next = prev->Next;
        if (prev->Prev) prev->Prev->Next = prev->Next;
        if (prev->Next) prev->Next->Prev = prev->Prev;
        FreeNode(prev);
        --*(int*)((char*)Counts + idx);
        prev = next;
        if (prev == 0) return;
    }
    node->End = x2;
}
