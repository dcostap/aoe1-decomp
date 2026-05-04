// mirrored removeAllObjects for the destroy pass, then kept the destructor's odd binary-observed free-next walk

#include <stdlib.h>

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
    void* vftable;
    RGE_Object_Node* list;
    unsigned short number_of_objects;

    RGE_Object_List();
    ~RGE_Object_List();
};

RGE_Object_List::~RGE_Object_List() {
    RGE_Object_Node* node;

    this->vftable = (void*)0x00570C2C;
    node = this->list;
    while (node != 0) {
        RGE_Object_Node* next = node->next;
        if (node->object != 0) {
            node->object->destroy(1);
        }
        node = next;
    }

    node = this->list;
    while (node != 0) {
        node = this->list->next;
        free(node);
        this->list = node;
    }

    this->number_of_objects = 0;
}
