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
    virtual int vf30(void);
    virtual int vf34(void);
    virtual int attack_response(RGE_Static_Object*);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node* list;

    int attack_response(RGE_Static_Object* obj);
};

int RGE_Action_List::attack_response(RGE_Static_Object* obj) {
    if (this->list != 0) {
        return this->list->action->attack_response(obj) & 0xff;
    }
    return 0;
}
