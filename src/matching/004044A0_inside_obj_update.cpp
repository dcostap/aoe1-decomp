#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual unsigned char inside_obj_update(void);
    virtual void vf24(void);
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
