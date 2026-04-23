class TRIBE_Action_Repair {
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
    virtual void reset_target(int value);
    virtual void vf58(void);
    virtual int set_state(int value);

    char gap_04[0x1C];
    float move_x;
    float move_y;
    float move_z;

    int move_to(void* obj, float x, float y, float z);
};

int TRIBE_Action_Repair::move_to(void* obj, float x, float y, float z) {
    this->move_y = y;
    this->move_x = x;
    this->move_z = z;
    this->reset_target(0);
    this->set_state(0x0B);
    return 1;
}
