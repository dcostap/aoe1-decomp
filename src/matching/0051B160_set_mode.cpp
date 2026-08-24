#ifndef AOE1_TPNL_OBJ_CONTEXT_H
class TRIBE_Panel_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(int mode);
    char gap_04[0x11C];
    unsigned char mode;

    void save_object_info();
    void set_mode(unsigned char mode);
};
#endif

void TRIBE_Panel_Object::set_mode(unsigned char mode) {
    this->mode = mode;
    save_object_info();
#ifdef AOE1_TPNL_OBJ_CONTEXT_H
    this->set_redraw(1);
#else
    vf20(1);
#endif
}
