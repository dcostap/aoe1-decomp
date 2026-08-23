#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
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
    virtual void set_redraw(int param_1);
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
};

class RGE_View {
public:
    int start_scroll_view(unsigned char param_1, long param_2, long param_3, int param_4, int param_5);
};

class RGE_Main_View {
public:
    char gap_000[0x360];
    TPanel* map_view;

    int start_scroll_view(unsigned char param_1, long param_2, long param_3, int param_4, int param_5);
};
#endif

int RGE_Main_View::start_scroll_view(unsigned char param_1, long param_2, long param_3, int param_4, int param_5) {
#ifdef RGE_MAIN_VIEW_SHARED_CONTEXT
    if (this->RGE_View::start_scroll_view(param_1, param_2, param_3, param_4, param_5) != 0) {
#else
    if (((RGE_View*)this)->start_scroll_view(param_1, param_2, param_3, param_4, param_5) != 0) {
#endif
        if (this->map_view != 0) {
            this->map_view->set_redraw(1);
        }
        return 1;
    }
    return 0;
}
