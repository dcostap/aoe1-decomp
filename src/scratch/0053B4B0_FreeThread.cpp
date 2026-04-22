// STATUS: active lead
// free-list splice and block-count behavior match; the problem is still prologue/register scheduling around the null-head fast return
// next lead: declare count/current only after the head-null gate and keep the two scans in separate inner scopes, matching the original delayed esi/ebx saves more closely

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
    if (head == 0) {
        return 0;
    }

    if (tail == 0) {
        int count;
        DClipInfo_Node* current;

        count = 0;
        current = head;
        do {
            tail = current;
            count = count + 1;
            this->Free_Blocks = this->Free_Blocks + 1;
            current = tail->Next;
        } while (current != 0);
        tail->Next = this->Free_Head;
        this->Free_Head = head;
        return count;
    }
    {
        int count;
        DClipInfo_Node* current;

        count = 0;
        current = head;
        do {
            count = count + 1;
            this->Free_Blocks = this->Free_Blocks + 1;
            if (current == tail) {
                current = 0;
            } else {
                current = current->Next;
            }
        } while (current != 0);
        tail->Next = this->Free_Head;
        this->Free_Head = head;
        return count;
    }
}
