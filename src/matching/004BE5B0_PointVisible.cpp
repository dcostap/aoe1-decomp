// 004BE5B0 TSpan_List_Manager::PointVisible (spanlist.cpp:1410-1426, 59B)
// Checks if a point (x, y) is visible by walking span linked list.
// FLAGS: /nologo /c /O2 /Oy

#ifndef SPANLIST_SHARED_CONTEXT
struct VSpan_Node {
    VSpan_Node* next;     // +0x00
    char _pad_04[4];       // +0x04
    int StartPx;           // +0x08
    int EndPx;             // +0x0C
};

struct TSpan_List_Manager {
    char _pad_3C[0x3C];
    VSpan_Node** line_head_ptrs; // +0x3C
    char _pad_40[0x50 - 0x40];
    int num_lines;                // +0x50

    int PointVisible(int x, int y);
};
#endif

int TSpan_List_Manager::PointVisible(int x, int y)
{
    if (y < 0 || y >= num_lines) return 0;

#ifdef SPANLIST_SHARED_CONTEXT
    VSpan_Node* node = this->Line_Head_Ptrs[y];
#else
    VSpan_Node* node = line_head_ptrs[y];
#endif
    if (!node) return 0;

    while (node) {
        if (x >= node->StartPx && x <= node->EndPx) return 1;
        node = node->next;
    }

    return 0;
}
