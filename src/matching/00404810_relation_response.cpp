#ifndef ACT_LIST_SHARED_CONTEXT
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
    virtual int vf30(void);
    virtual int vf34(void);
    virtual int vf38(void);
    virtual int vf3C(long, unsigned char);
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

    int relation_response(long, unsigned char);
};
#endif

int RGE_Action_List::relation_response(long param_1, unsigned char param_2) {
    if (this->list != 0) {
        return this->list->action->relation_response(param_1, param_2) & 0xff;
    }
    return 0;
}
