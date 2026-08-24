// VA: 00473240 TButtonPanel::mouse_left_move_action(long,long,int,int)
// Pnl_btn.cpp lines 893-920
// Attempt log:
// - Canonical typed fields and virtual is_inside/set-redraw/notify surfaces matched size, calls, and body shape;
//   the first natural branch order left only the notification-arm polarity different.
// - Putting the positive is_down notification arm first preserves the original je-to-code-3 layout. Exact.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

class TButtonPanel;
#ifndef PNL_BTN_SHARED_CONTEXT
class TPanel {
public:
    void action(TButtonPanel*, int, long, long);
};
#endif

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
    virtual int is_inside(long x, long y);

    char gap_04[0x3C];
    TPanel* parent_panel;              // +0x40
    char gap_44[0xB0];                 // to +0xF4
    long id[9];                        // +0xF4
    long id2[9];                       // +0x118
    char gap_13C[0xBA];                // to +0x1F6
    short cur_state;                   // +0x1F6
    long is_down;                      // +0x1F8
    char gap_1FC[0x8];                 // to +0x204
    unsigned long button_down_time;    // +0x204

    void set_redraw(int);
    long mouse_left_move_action(long x, long y, int ctrl, int shift);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

long TButtonPanel::mouse_left_move_action(long x, long y, int ctrl, int shift) {
    int new_state = (this->is_inside(x, y) != 0);
    if (this->is_down != new_state) {
        this->is_down = new_state;
        if (new_state != 0) {
            this->button_down_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x389);
        }
        this->set_redraw(1);
        TPanel* target = this->parent_panel;
        if (this->is_down != 0) {
            if (target != 0) {
                target->action(this, 2, this->id[this->cur_state], this->id2[this->cur_state]);
                return 1;
            }
        } else if (target != 0) {
            target->action(this, 3, this->id[this->cur_state], this->id2[this->cur_state]);
        }
    }
    return 1;
}
