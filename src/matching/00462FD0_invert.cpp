struct RGE_Object_Node {
    void* object;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;

    void invert(void);
};

void RGE_Object_List::invert(void) {
    RGE_Object_Node* prev = 0;
    RGE_Object_Node* node = this->list;

    while (node != 0) {
        this->list = node->next;
        node->next = prev;
        if (prev != 0) {
            prev->prev = node;
        }
        prev = node;
        node->prev = 0;
        node = this->list;
    }
    this->list = prev;
}
