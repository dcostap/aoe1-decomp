// VA: 00473450 mouse_right_move_action (194B)
// Pnl_btn.cpp
//
// Attempt log:
// - Restored the period-plausible TPanel/TButtonPanel ownership from the
//   neighboring exact Pnl_btn.cpp actions: is_inside, set_redraw, parent_panel,
//   id/id2, cur_state, is_down, and button_down_time.
// - Baseline matched all bytes except the final notification branch polarity;
//   keeping the positive is_down arm first recovered the original hot (code 5)
//   block layout and exact bytes.

extern "C" unsigned long __cdecl debug_timeGetTime(const char* file, int line);

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TPanel {
public:
    virtual ~TPanel();
    VPAD4(1) VPAD2(5) VPAD1(7)
    virtual void set_redraw(int mode);
    VPAD32(9) VPAD4(41)
    virtual long action(TPanel* panel, long code, unsigned long id, unsigned long id2);
    VPAD1(46)
    virtual int is_inside(long x, long y);

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0xB0];
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();

    long id[9];
    long id2[9];
    char gap_13C[0xBA];
    short cur_state;
    int is_down;
    char gap_1FC[0x8];
    unsigned long button_down_time;

    virtual long mouse_right_move_action(long x, long y, int ctrl, int shift);
};

long TButtonPanel::mouse_right_move_action(long x, long y, int ctrl, int shift) {
    int new_is_down = (this->is_inside(x, y) != 0);

    if (this->is_down != new_is_down) {
        this->is_down = new_is_down;
        if (new_is_down != 0) {
            this->button_down_time = debug_timeGetTime(
                "C:\\msdev\\work\\age1_x1\\Pnl_btn.cpp", 0x3E3);
        }
        this->set_redraw(1);
        if (this->is_down != 0) {
            if (this->parent_panel != 0) {
                this->parent_panel->action(
                    this, 5, this->id[this->cur_state], this->id2[this->cur_state]);
            }
            return 1;
        } else if (this->parent_panel != 0) {
            this->parent_panel->action(
                this, 6, this->id[this->cur_state], this->id2[this->cur_state]);
        }
    }

    return 1;
}
