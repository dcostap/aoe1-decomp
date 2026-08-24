#ifndef RGE_VIEW_SHARED_CONTEXT
struct DClipInfo_Node {
    DClipInfo_Node* Next;
};

class DClipInfo_List {
public:
    char gap_00[0x10];
    DClipInfo_Node* Free_Head;
    char gap_14[0x0C];
    int Free_Blocks;

    void FreeNode(DClipInfo_Node* node);
};
#endif

void DClipInfo_List::FreeNode(DClipInfo_Node* node) {
    node->Next = Free_Head;
    Free_Head = node;
    Free_Blocks = Free_Blocks + 1;
}
