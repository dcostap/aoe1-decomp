class RGE_Static_Object;

#ifndef AOE1_TACT_ART_TU_CONTEXT
class TRIBE_Action_Artifact {
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
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(int mode);
    virtual int move_to(RGE_Static_Object* obj, float x, float y, float z);

    char gap_04[0x1C];
    float move_x;
    float move_y;
    float move_z;
};
#endif

int TRIBE_Action_Artifact::move_to(RGE_Static_Object* obj, float x, float y, float z) {
    this->move_x = x;
    this->move_y = y;
    this->move_z = z;
#ifdef AOE1_TACT_ART_TU_CONTEXT
    this->set_state(4);
#else
    this->vf5C(4);
#endif
    return 1;
}
