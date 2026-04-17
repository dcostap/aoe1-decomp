class RGE_Static_Object {
public:
    void* vtable;
    int object_id;
};

class RGE_Action {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual RGE_Static_Object* get_target_obj();
};

class RGE_Action_List {
public:
    unsigned char have_action();
    RGE_Action* get_action();
};

class RGE_Combat_Object {
public:
    unsigned char gap_00[0x180];
    RGE_Action_List* action_list;

    virtual int currentTargetID() const;
};

int RGE_Combat_Object::currentTargetID() const {
    if (action_list->have_action() == 1) {
        if (action_list->get_action()->get_target_obj() != 0) {
            return action_list->get_action()->get_target_obj()->object_id;
        }
    }
    return -1;
}
