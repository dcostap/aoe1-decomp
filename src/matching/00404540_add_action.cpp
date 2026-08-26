#ifndef ACT_LIST_SHARED_CONTEXT
void* __cdecl calloc(unsigned int count, unsigned int size);
#endif

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
    virtual short type(void);
    virtual void first_in_stack(unsigned char value);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List_Object {
public:
    char gap_00[0x48];
    unsigned char state;
};

class RGE_Action_List {
public:
    char gap_00[4];
    RGE_Action_List_Object* obj;
    RGE_Action_Node* list;

    void add_action(RGE_Action* action);
};
#endif

void RGE_Action_List::add_action(RGE_Action* action) {
    RGE_Action_Node* node;

    if (this->obj->object_state > 2) {
        if (action != 0) {
            delete action;
        }
        return;
    }

    node = (RGE_Action_Node*)calloc(1, 8);
    node->action = action;
    node->next = this->list;
    this->list = node;
    action->first_in_stack(1);
}
