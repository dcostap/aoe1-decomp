// Attempt log:
// The original loads the index after the list test and uses one bottom-tested
// loop.  The natural while(node) form with a direct success return reproduces
// the 35-byte body exactly.  The while(true)/break form hoists the index load.

#ifndef PNL_TXT_TU_CONTEXT
struct TextNode {
    char gap_00[8];
    long id;
    TextNode* next_node;
};

class TTextPanel {
public:
    char gap_00[0xF4];
    TextNode* list;

    long get_line(long index);
};
#endif

long TTextPanel::get_line(long index) {
    TextNode* node = this->list;
    int i = 0;
    while (node != 0) {
        if (node->id == index) {
            return i;
        }
        node = node->next_node;
        ++i;
    }
    return -1;
}
