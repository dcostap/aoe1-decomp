struct TextNode {
    char gap_00[8];
    long id;
    TextNode* next_node;
};

class TTextPanel {
public:
    char gap_00[0xF4];
    TextNode* list;

    long get_id(long index);
};

long TTextPanel::get_id(long index) {
    TextNode* node = this->list;
    int count = 0;

    if (node == 0) {
        return -1;
    }

    do {
        if (count == index) {
            return node->id;
        }
        node = node->next_node;
        ++count;
    } while (node != 0);

    return -1;
}
