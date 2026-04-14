struct InnerObj {
    char gap_0[0x48];
    unsigned char field_48;
};

class RGE_Action {
public:
    virtual void vf00() {}
    virtual void vf04() {}
    virtual void vf08() {}
    virtual void vf0C() {}
    virtual void vf10() {}
    virtual void vf14() {}
    virtual void vf18() {}
    virtual void vf1C() {}
    virtual void vf20() {}
    virtual void vf24() {}
    virtual void vf28() {}
    virtual void vf2C() {}
    virtual void vf30() {}
    virtual void vf34() {}
    virtual void vf38() {}
    virtual void vf3C() {}
    virtual void vf40() {}
    virtual void vf44() {}
    virtual void vf48() {}
    virtual void vf4C() {}
    virtual void vf50() {}
    virtual void vf54(int) {}
    virtual void vf58(int) {}

    short action_type;
    char gap_6[10];
    InnerObj* inside_obj;
    InnerObj* target_obj;

    unsigned char inside_obj_update();
};

unsigned char RGE_Action::inside_obj_update()
{
    if (this->inside_obj != 0 && this->inside_obj->field_48 >= 7) {
        this->vf54(0);
    }
    if (this->target_obj != 0 && this->target_obj->field_48 >= 7) {
        this->vf58(0);
    }
    return 1;
}