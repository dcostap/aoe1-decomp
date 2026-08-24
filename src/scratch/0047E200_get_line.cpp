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
    while (true) {
        if (node == 0) {
            return -1;
        }
        if (node->id == index) {
            break;
        }
        node = node->next_node;
        ++i;
    }
    return i;
}
