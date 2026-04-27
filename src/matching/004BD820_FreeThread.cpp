// attempt 1: direct free-thread walk/splice using the real list offsets from the type dump
// target shape: return 0 on null head; otherwise count nodes, bump Free_Blocks, and splice the chain onto Free_Head

struct VSpan_Node {
    VSpan_Node* Next;
    VSpan_Node* Prev;
    int StartPx;
    int EndPx;
};

class TSpan_Node_List {
public:
    char gap_00[0x10];
    VSpan_Node* Free_Head;
    char gap_14[0x0C];
    int Free_Blocks;

    int FreeThread(VSpan_Node* first, VSpan_Node* second);
};

int TSpan_Node_List::FreeThread(VSpan_Node* first, VSpan_Node* second) {
    int count;
    VSpan_Node* current;
    VSpan_Node* last;

    count = 0;
    current = first;
    if (first == 0) {
        return 0;
    }

    if (second == 0) {
        do {
            last = current;
            this->Free_Blocks = this->Free_Blocks + 1;
            count = count + 1;
            current = last->Next;
        } while (current != 0);
        last->Next = this->Free_Head;
        this->Free_Head = first;
    } else {
        do {
            this->Free_Blocks = this->Free_Blocks + 1;
            count = count + 1;
            if (current != second) {
                current = current->Next;
            } else {
                current = 0;
            }
        } while (current != 0);
        second->Next = this->Free_Head;
        this->Free_Head = first;
    }

    return count;
}
