#ifndef OBJLIST_SHARED_CONTEXT
class RGE_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void rehook(void);
};

class RGE_Object_Node {
public:
    RGE_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    void* vfptr;
    RGE_Object_Node* list;

    void rehook_list();
};
#endif

void RGE_Object_List::rehook_list() {
    RGE_Object_Node* node;

    node = this->list;
    while (node != 0) {
        node->node->rehook();
        node = node->next;
    }
}
