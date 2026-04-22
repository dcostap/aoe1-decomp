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
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void destroy(void);
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
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;

    void destroy_objects();
};

void RGE_Player::destroy_objects() {
    RGE_Object_Node* node;

    node = this->objects->list;
    while (node != 0) {
        node->node->destroy();
        node = node->next;
    }
}
