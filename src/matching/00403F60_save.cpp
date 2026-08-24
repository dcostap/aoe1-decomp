void __cdecl rge_write(int file, void* data, int size);

#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void save(int file);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node* list;

    void save(int file);
};
#endif

void RGE_Action_List::save(int file) {
    RGE_Action_Node* node;
    int zero;

    node = this->list;
    while (node != 0) {
        node->action->save(file);
        node = node->next;
    }
    zero = 0;
    rge_write(file, &zero, 2);
}
