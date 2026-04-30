// VA: 0047E340 get_id (46B, Pnl_txt.cpp)
// Linked list traversal with index comparison.
// Returns node->id at matching index, or -1 if not found.
// Uses while (node != 0) loop rotation for correct block layout.

struct TextNode {
    char gap_00[0x8];
    long id;           // +0x08
    TextNode* next;    // +0x0C
};

class TTTextPanel {
public:
    char gap_00[0xF4];
    TextNode* list;    // +0xF4

    long get_id(long index);
};

long TTTextPanel::get_id(long index) {
    long count = 0;
    long target = index;
    TextNode* node = this->list;
    
    if (node == 0) return -1;
    
    while (node != 0) {
        if (count == target) {
            return node->id;
        }
        node = node->next;
        count++;
    }
    return -1;
}
