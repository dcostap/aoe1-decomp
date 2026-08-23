#ifndef SPANLIST_SHARED_CONTEXT
struct VSpan_Node {
    VSpan_Node* Next;
    VSpan_Node* Prev;
};

class TSpan_Node_List {
public:
    char gap_00[0x10];
    VSpan_Node* Free_Head;
    char gap_14[0x0C];
    int Free_Blocks;

    void FreeNode(VSpan_Node* node);
};
#endif

void TSpan_Node_List::FreeNode(VSpan_Node* node) {
    node->Next = this->Free_Head;
    node->Prev = 0;
    this->Free_Head = node;
    this->Free_Blocks = this->Free_Blocks + 1;
}
