struct RGE_Static_Object {
    virtual void destroy(int value);
};

struct RGE_Object_Node {
    RGE_Static_Object* object;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;
    unsigned short number_of_objects;

    void removeAllObjects(void);
};

void RGE_Object_List::removeAllObjects(void) {
    RGE_Object_Node* node = this->list;

    while (node != 0) {
        RGE_Object_Node* next = node->next;
        if (node->object != 0) {
            node->object->destroy(1);
        }
        node = next;
    }
    this->list = 0;
    this->number_of_objects = 0;
}
