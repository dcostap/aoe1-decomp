// explicit entry liveness for both locals forced the right early pushes, but it also hoisted a `mov bl,1` before the null-list test
// next lead: use separate head and node locals while still birthing the return value only after the virtual update call, to see if VC5 keeps the full push-save prolog without the early `mov bl,1`
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
    RGE_Action_Node* head;
    RGE_Action_Node* node;
    unsigned char uVar2;

    head = this->list;
    if (head == 0) {
        return 1;
    }

    uVar2 = head->action->update();
    head = this->list;
    if (head != 0) {
        node = head->next;
        while (node != 0) {
            node->action->vf24();
            node = node->next;
        }
        if (uVar2 == 1) {
            this->remove_action();
        }
    }
    return uVar2;
}
