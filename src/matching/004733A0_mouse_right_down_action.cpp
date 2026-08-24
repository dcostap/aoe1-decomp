extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class TButtonPanel;
#ifndef PNL_BTN_SHARED_CONTEXT
class TPanel {
public:
    void action(TButtonPanel*, int, long, long);
};
#endif

#ifndef PNL_BTN_SHARED_CONTEXT
class TDigital {
public:
    int is_playing(void);
    void stop(void);
    int play(void);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
class NotifyTarget {
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
    virtual void vfB4(TButtonPanel* panel, int code, long id, long id2);
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

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0xB0];
    long id[9];
    long id2[9];
    long buttonTypeValue;
    long drawTypeValue;
    long notifyTypeValue;
    TDigital* sound;
    char gap_14C[0xAA];
    short cur_state;
    long is_down;
    char gap_1FC[0x08];
    unsigned long button_down_time;
    char gap_208[0xA8];
    long disabled;

    void set_redraw(int);
    int capture_mouse(void);
    long mouse_right_down_action(long x, long y, int ctrl, int shift);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::mouse_right_down_action(long x, long y, int ctrl, int shift) {
    if (disabled != 0) {
        return 0;
    }
    if (sound != 0) {
        if (sound->is_playing() != 0) {
            sound->stop();
        }
        sound->play();
    }
    capture_mouse();
    is_down = 1;
    button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x3CC);
    set_redraw(1);
    if (parent_panel != 0) {
        parent_panel->action(this, 5, id[cur_state], id2[cur_state]);
    }
    return 1;
}
