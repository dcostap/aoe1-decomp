#ifndef RGE_VIEW_SHARED_CONTEXT
struct DClipInfo_Node { DClipInfo_Node* Next; };
class DClipInfo_List { public: char gap_00[0x10]; DClipInfo_Node* Free_Head; char gap_14[0x0C]; int Free_Blocks; int FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail); };
#endif
int DClipInfo_List::FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail) {
    int count = 0;
    DClipInfo_Node* cur = head;
    if (head == 0) return 0;
    if (tail == 0) {
        do {
            tail = cur;
            ++this->Free_Blocks;
            ++count;
            cur = cur->Next;
        } while (cur != 0);
    } else {
        do {
            ++this->Free_Blocks;
            ++count;
            if (cur != tail) cur = cur->Next;
            else cur = 0;
        } while (cur != 0);
    }
    tail->Next = this->Free_Head;
    this->Free_Head = head;
    return count;
}
