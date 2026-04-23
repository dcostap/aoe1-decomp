class RGE_Static_Object;

class RGE_Action_Transport {
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
    virtual int vf3C(void);
    virtual int vf40(void);
    virtual int vf44(void);
    virtual int vf48(void);
    virtual int vf4C(void);
    virtual int vf50(void);
    virtual int vf54(void);
    virtual int vf58(void);
    virtual void set_state(int state);
    char gap_04[0x1C];
    float field_20;
    float field_24;
    float field_28;

    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
};

int RGE_Action_Transport::move_to(RGE_Static_Object* object, float x, float y, float z) {
    this->field_20 = x;
    this->field_24 = y;
    *(int*)((char*)this + 0x1C) = 0;
    this->field_28 = z;
    this->set_state(0x0B);
    return 1;
}
