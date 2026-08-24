#ifndef PNL_BTN_SHARED_CONTEXT
class TPanel {
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
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual long vfE4(long x, long y);

    char gap_04[0x64];
    int active;
    int visible;

    long handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel : public TPanel {
public:
    char gap_0C[0x228];

    int is_inside(long, long);
    long handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift) {
    if (visible == 0) {
        return 0;
    }
    if (active != 0) {
        return 0;
    }
    if (is_inside(x, y) == 0) {
        return 0;
    }
    return ((TPanel*)this)->handle_mouse_down(button, x, y, ctrl, shift);
}
