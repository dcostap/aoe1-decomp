extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

#ifndef PNL_BTN_SHARED_CONTEXT
class TDrawArea {
public:
    char gap_00[0x04];
    void* Wnd;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
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

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0x118];
    long buttonTypeValue;
    char gap_140[0xB6];
    short cur_state;
    long is_down;

    void set_redraw(int);
    void release_mouse(void);
    void do_action(void);
    long mouse_left_up_action(long x, long y, int ctrl, int shift);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::mouse_left_up_action(long x, long y, int ctrl, int shift) {
    release_mouse();
    if (is_down != 0) {
        if (buttonTypeValue != 2) {
            is_down = 0;
        }
        set_redraw(1);
        SendMessageA(render_area->Wnd, 0x0F, 0, 0);
        do_action();
        return 1;
    }
    if (buttonTypeValue == 2 && cur_state == 1) {
        is_down = 1;
        set_redraw(1);
    }
    return 1;
}
