class RGE_Static_Object {
public:
    virtual void release_being_worked_on(RGE_Static_Object* object);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void set_sleep_flag(unsigned char value);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    void release_being_worked_on(RGE_Static_Object* object);
};

void RGE_Animated_Object::release_being_worked_on(RGE_Static_Object* object) {
    RGE_Static_Object::release_being_worked_on(object);
    RGE_Static_Object::set_sleep_flag(0);
}
