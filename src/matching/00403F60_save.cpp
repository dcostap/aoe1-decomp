void __cdecl rge_write(int file, void* data, int size);

#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action_Object;
class RGE_Action_List;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook(void);
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
