class RGE_Action_Object;

class RGE_Static_Object {
public:
    virtual void set_being_worked_on(RGE_Action_Object* action, short mode,
                                     unsigned char flag);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    void set_being_worked_on(RGE_Action_Object* action, short mode,
                             unsigned char flag);
};

void RGE_Animated_Object::set_being_worked_on(RGE_Action_Object* action,
                                               short mode,
                                               unsigned char flag) {
    RGE_Static_Object::set_being_worked_on(action, mode, flag);
}
