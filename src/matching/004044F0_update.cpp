class RGE_Static_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Static_Object*);
    virtual int setup(int, RGE_Static_Object*);
    virtual void* create_action_list(RGE_Static_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
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

    void remove_action();
    unsigned char update();
};

unsigned char RGE_Action_List::update() {
    RGE_Action_Node* node;
    unsigned char result;

    if (this->list == 0)
        return 1;

    result = this->list->action->update();
    if (this->list != 0) {
        node = this->list->next;
        while (node != 0) {
            node->action->idle_update();
            node = node->next;
        }

        if (result != 1)
            return result;
        this->remove_action();
    }

    return result;
}
