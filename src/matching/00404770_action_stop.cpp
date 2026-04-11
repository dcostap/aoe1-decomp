class RGE_Action {
public:
    virtual int vf00(void);
    virtual int vf04(void);
    virtual int vf08(void);
    virtual int vf0C(void);
    virtual int vf10(void);
    virtual int vf14(void);
    virtual int vf18(void);
    virtual int vf1C(void);
    virtual int vf20(void);
    virtual int vf24(void);
    virtual int vf28(void);
    virtual int vf2C(void);
};

class RGE_Action_Node {
public:
    RGE_Action *action;
    RGE_Action_Node *next;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node *list;

    int action_stop(void);
};

int RGE_Action_List::action_stop(void) {
    if (this->list != 0) {
        return this->list->action->vf2C();
    }
    return 0;
}
