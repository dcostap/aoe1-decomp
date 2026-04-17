class RGE_Static_Object;

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
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual RGE_Static_Object* get_target_obj(void);
};

class RGE_Action_List {
public:
    RGE_Action* get_action(void);
};

class RGE_Action_Object {
public:
    char gap_00[0x184];
    RGE_Action_List* actions;

    RGE_Static_Object* get_target_obj(void);
};

RGE_Static_Object* RGE_Action_Object::get_target_obj(void) {
    RGE_Action* action;
    RGE_Static_Object* target_obj;

    action = this->actions->get_action();
    if (action != 0) {
        return action->get_target_obj();
    }
    target_obj = 0;
    return target_obj;
}
