// STATUS: active
// NOTE: size-correct and structurally close, but VC5 still delays the `push ebx/push esi` saves until after the null-list check; current drift is prolog/register-shape rather than algorithmic.
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
    virtual void vf20(void);
    virtual void vf24(void);
    virtual unsigned char update(void);
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
    unsigned char update(void);
};

unsigned char RGE_Action_List::update(void) {
    if (this->list == 0) {
        return 1;
    }

    {
        RGE_Action_Node* node;
        unsigned char result;

        result = this->list->action->update();
        node = this->list;
        if (node != 0) {
            node = node->next;
            while (node != 0) {
                node->action->vf24();
                node = node->next;
            }
            if (result == 1) {
                this->remove_action();
            }
        }
        return result;
    }
}
