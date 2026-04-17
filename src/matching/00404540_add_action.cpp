void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Action {
public:
    virtual void vf00(int);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void activate(int);
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

void RGE_Action_List::add_action(RGE_Action* action) {
    RGE_Action_Node* node;

    if (this->obj->state > 2) {
        if (action != 0) {
            action->vf00(1);
        }
        return;
    }

    node = (RGE_Action_Node*)calloc(1, 8);
    node->action = action;
    node->next = this->list;
    this->list = node;
    action->activate(1);
}
