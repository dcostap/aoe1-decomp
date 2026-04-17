// STATUS: blocked
// BLOCKER: VC5 insists on hoisting ebx/esi saves before the null-head fast return and slightly reorders the count/current setup, so the prologue and both loop headers drift
// NOTE: free-list splice and block-count behavior match; remaining mismatch is prologue/register scheduling only

struct DClipInfo_Node {
    DClipInfo_Node* Next;
};

class DClipInfo_List {
public:
    char gap_00[0x10];
    DClipInfo_Node* Free_Head;
    char gap_14[0x0C];
    int Free_Blocks;

    int FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail);
};

int DClipInfo_List::FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail) {
    int count;

    if (head == 0) {
        return 0;
    }
    count = 0;
    if (tail == 0) {
        DClipInfo_Node* current;

        current = head;
        do {
            tail = current;
            count = count + 1;
            Free_Blocks = Free_Blocks + 1;
            current = tail->Next;
        } while (current != 0);
        tail->Next = Free_Head;
        Free_Head = head;
        return count;
    }
    {
        DClipInfo_Node* current;

        current = head;
        do {
            count = count + 1;
            Free_Blocks = Free_Blocks + 1;
            if (current == tail) {
                current = 0;
            } else {
                current = current->Next;
            }
        } while (current != 0);
    }
    tail->Next = Free_Head;
    Free_Head = head;
    return count;
}
