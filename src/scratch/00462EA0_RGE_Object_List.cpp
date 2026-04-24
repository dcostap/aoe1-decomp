// first pass: reset the vtable, walk the object nodes to destroy any live objects, then free the node list and clear the count
// tried exact node/object layouts, explicit vtable init, decompiler-shaped loops, and a direct free pass; the remaining mismatch is register allocation / call-shape drift in the destructor prolog and free loop

#include <stdlib.h>

class RGE_Static_Object {
public:
    virtual void destroy(int);
};

struct RGE_Object_Node {
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    void** vftable;
    RGE_Object_Node* list;
    short number_of_objects;

    RGE_Object_List();
    ~RGE_Object_List();
};

RGE_Object_List::~RGE_Object_List() {
    RGE_Object_Node* pRVar1;
    RGE_Object_Node* pRVar2;
    RGE_Static_Object* ppRVar3;

    this->vftable = (void**)0x00570C2C;
    pRVar2 = this->list;
    while (pRVar2 != 0) {
        pRVar1 = pRVar2->next;
        ppRVar3 = pRVar2->object;
        pRVar2 = pRVar1;
        if (ppRVar3 != 0) {
            ppRVar3->destroy(1);
        }
    }

    pRVar2 = this->list;
    while (pRVar2 != 0) {
        pRVar2 = this->list->next;
        free(this->list);
        this->list = pRVar2;
    }

    this->number_of_objects = 0;
}
