extern "C" void __cdecl free(void* block);

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
    virtual void destroy(unsigned char param_1);
    virtual int setup(RGE_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(unsigned char param_1);
};

void RGE_Action_List::remove_action() {
    RGE_Action_Node* pRVar1;

    pRVar1 = this->list;
    if (pRVar1 != 0) {
        this->list = pRVar1->next;
        if (pRVar1->action != 0) {
            pRVar1->action->destroy(1);
        }
        free(pRVar1);
        if (this->list != 0 && (unsigned char)this->obj->gap_00[0x48] < 3) {
            this->list->action->first_in_stack(0);
        }
    }
}
