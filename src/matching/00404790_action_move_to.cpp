class RGE_Static_Object;

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
    virtual int vf30(RGE_Static_Object *, float, float, float);
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

    int action_move_to(RGE_Static_Object *, float, float, float);
};

int RGE_Action_List::action_move_to(RGE_Static_Object *param_1, float param_2, float param_3, float param_4) {
    if (this->list != 0) {
        return this->list->action->vf30(param_1, param_2, param_3, param_4);
    }
    return 0;
}
