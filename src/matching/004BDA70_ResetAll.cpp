// VA: 004BDA70 TSpan_List_Manager::ResetAll
// PDB: spanlist.cpp lines 407-417 (137 bytes, 57 asm lines)
// Default flags. No inline asm/hacks.

#include <string.h>

class TSpan_Node_List {
public:
    void ReclaimAllNodes();
};

class TSpan_List_Manager {
public:
    char gap_00[0x3C];
    void** line_head_ptrs;     // +0x3C
    void** line_tail_ptrs;     // +0x40
    int* left_most_px;         // +0x44
    int* right_most_px;        // +0x48
    int* span_count;           // +0x4C
    int num_lines;              // +0x50

    void ResetAll();
};

void TSpan_List_Manager::ResetAll()
{
    ((TSpan_Node_List*)this)->ReclaimAllNodes();

    {
        unsigned int size = this->num_lines * 4;
        memset(this->line_head_ptrs, 0, size);
    }
    {
        unsigned int size = this->num_lines * 4;
        memset(this->line_tail_ptrs, 0, size);
    }
    {
        unsigned int size = this->num_lines * 4;
        memset(this->left_most_px, 0, size);
    }
    {
        unsigned int size = this->num_lines * 4;
        memset(this->right_most_px, 0, size);
    }
    {
        unsigned int size = this->num_lines * 4;
        memset(this->span_count, 0, size);
    }
}
