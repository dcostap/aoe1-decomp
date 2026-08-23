#ifndef OBJLIST_SHARED_CONTEXT
class RGE_Static_Object;

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    char gap_00[0x4];
    RGE_Object_Node* list;

    void save(int file);
};

class RGE_Static_Object {
public:
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(void);
    virtual void v10(void);
    virtual void v11(void);
    virtual void save(int file);
};

extern void rge_write(int file, void* data, int size);
#endif

#ifdef OBJLIST_SHARED_CONTEXT
extern void rge_write(int file, void* data, int size);
#endif

void RGE_Object_List::save(int file) {
    unsigned char finished;
    RGE_Object_Node* node = this->list;

    finished = 0;
    while (node != 0) {
        if (node->node != 0) {
            node->node->save(file);
        }
        node = node->next;
    }

    rge_write(file, &finished, 1);
}
