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
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char idle_update(void);
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

    void remove_action(void);
    unsigned char inside_obj_update(void);
};
#endif

unsigned char RGE_Action_List::inside_obj_update(void) {
    if (this->list == 0) {
        return 1;
    }

    {
        RGE_Action_Node* node;
        unsigned char result;

        result = this->list->action->inside_obj_update();
        node = this->list->next;
        while (node != 0) {
            node->action->idle_update();
            node = node->next;
        }

        if (result == 1) {
            this->remove_action();
        }
        return result;
    }
}
