class RGE_Static_Object;

#ifndef TACT_BLD_CONTEXT_H
class TRIBE_Action_Build {
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
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void set_target_obj(void* value);
    virtual void vf58(void);
    virtual int set_state(int value);

    char gap_04[0x1C];
    float target_x;
    float target_y;
    float target_z;

    int move_to(RGE_Static_Object* obj, float x, float y, float z);
};
#endif

int TRIBE_Action_Build::move_to(RGE_Static_Object* obj, float x, float y, float z) {
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(0x0B);
    return 1;
}
