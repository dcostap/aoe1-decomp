// quick-win attempt log:
// no existing work file for 004C1D60; the oracle is an EH-framed new-expression helper
// from stat_obj.cpp. Tried direct `new`, `try/catch`, and placement-new shapes; the
// remaining mismatch stayed at the prolog / first instruction basin.
// Tried moving the target function first in the TU; that changed the emitted basin
// but still did not reproduce the original `push -1` / FS:[0] EH entry sequence.

void* operator new(unsigned int, void*);

class RGE_Object_List {
public:
    void* vtable_ptr;
    int list;
    short number_of_objects;
    RGE_Object_List();
    virtual ~RGE_Object_List();
};

class RGE_Static_Object {
public:
    virtual RGE_Object_List* create_object_list(void);
};

RGE_Object_List* RGE_Static_Object::create_object_list(void) {
    RGE_Object_List* list = (RGE_Object_List*)operator new(0xC);
    if (list != 0) {
        new (list) RGE_Object_List();
    }
    return list;
}

RGE_Object_List::RGE_Object_List() {
    list = 0;
    number_of_objects = 0;
}

RGE_Object_List::~RGE_Object_List() {
}
