// tried the current update scaffold; size and behavior are close, but VC5 still delays the callee-save pushes
// leaving this in scratch because the remaining gap is register/prolog shape, not logic
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
    RGE_Action_Node* pRVar1;
    unsigned char uVar2;

    if (this->list != 0) {
        uVar2 = this->list->action->update();
        if (this->list != 0) {
            for (pRVar1 = this->list->next; pRVar1 != 0; pRVar1 = pRVar1->next) {
                pRVar1->action->vf24();
            }
            if (uVar2 == 1) {
                this->remove_action();
            }
        }
        return uVar2;
    }
    return 1;
}
