extern "C" void __cdecl free(void* block);

#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action;
class RGE_Action_Object;

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_Object {
public:
    char gap_00[0x48];
    unsigned char object_state;
};

class RGE_Action_List {
public:
    char gap_00[0x4];
    RGE_Action_Object* obj;
    RGE_Action_Node* list;

    void remove_action();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(unsigned char param_1);
};
#endif

void RGE_Action_List::remove_action() {
    RGE_Action_Node* pRVar1;

    pRVar1 = this->list;
    if (pRVar1 != 0) {
        this->list = pRVar1->next;
        if (pRVar1->action != 0) {
            delete pRVar1->action;
        }
        free(pRVar1);
        if (this->list != 0 && this->obj->object_state < 3) {
            this->list->action->first_in_stack(0);
        }
    }
}
