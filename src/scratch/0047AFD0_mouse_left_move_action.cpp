// 0047AFD0 TScrollBarPanel::mouse_left_move_action
// Attempt log:
// try 1: packet-grounded reconstruction. Models mode switch for arrow/page/thumb states, delayed repeat arming/cancel, value clamp, redraw/update calls, thumb position calculation, and last mouse tracking.
// try 2: modeled state dispatch as switch on byte +0x144 with cases 1..5.
// try 3: modeled cases 1/2/4/5 as is_inside_rect over rects +0x164/+0x174/+0x194/+0x1a4, arm repeat only when +0x148 is zero, and cancel if active when mouse leaves.
// try 4: modeled debug_timeGetTime calls with line constants 410/429/448/467 and stores to +0x158, +0x154=2.
// try 5: modeled shared scroll_action calls for arrow/page cases with pairs (0,0), (1,0), (2,0), (3,0) and repaint(1).
// try 6: modeled drag state +0x1b4==1 as horizontal branch, using x-last_x and h fields +0x134/+0x138/+0x13c/+0x140.
// try 7: modeled vertical drag branch using y-last_y and v fields +0x124/+0x128/+0x12c/+0x130.
// try 8: modeled dead-zone edge checks against min/max plus button span and zeroing delta.
// try 9: modeled clamping updated value, update_scrollbar call, repaint(1), thumb position = (pos-min)*thumb_span/(max-min) clamped to 0..thumb_span-1, then scroll_action(4,newthumb).
// try 10: modeled final last_x/last_y update only when state != 0.
// Current validation: exact configured size 991 but broad mismatch (86.1756% positional / 131.3824% edit). First mismatch: rebuilt saves an extra ECX stack slot and uses shifted param offsets; original has no local frame and keeps EBX zero/ESI this/EBP x.
// GIVEUP blockers: exact TScrollBarPanel field layout/names, avoiding VC5 local spill in drag arithmetic, source shape for shared arrow/page case tails, and correct signed edge-condition topology around thumb dragging. No inline asm used; no accepted_drift proposal.

extern "C" unsigned long __cdecl debug_timeGetTime(char*, int);
extern char pnl_scbr_cpp_path[];

struct Rect { long left, top, right, bottom; };

class TScrollBarPanel {
public:
    void* vftable;
    char gap04[0xf4]; int thumb_span;
    char gap0fc[0x28]; int h_pos; int h_min; int h_button; int h_max; int h_page; int h_drag;
    int v_pos; int v_min; int v_button; int v_max; int v_page; unsigned char state; char gap145[3]; int active; int last_x; int last_y; unsigned char repeat_mode; char gap155[3]; unsigned long repeat_time;
    char gap15c[8]; Rect r1; Rect r2; char gap184[0x10]; Rect r4; Rect thumb;
    int is_inside_rect(long x, long y, Rect* r);
    void update_scrollbar();
    void scroll_action(int part, int value);
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void repaint(int);
    long mouse_left_move_action(long x, long y, int a, int b);
};

long TScrollBarPanel::mouse_left_move_action(long x, long y, int a, int b)
{
    int delta;
    int pos;
    int minv;
    int maxv;
    int range;
    int newthumb;

    switch (this->state) {
    case 1:
        if (this->is_inside_rect(x, y, &this->r1)) {
            if (this->active == 0) {
                this->active = 1;
                this->repeat_mode = 2;
                this->repeat_time = debug_timeGetTime(pnl_scbr_cpp_path, 410);
                this->scroll_action(0, 0);
                this->repaint(1);
            }
        } else if (this->active != 0) {
            this->active = 0;
            this->repeat_mode = 0;
            this->repaint(1);
        }
        break;
    case 2:
        if (this->is_inside_rect(x, y, &this->r2)) {
            if (this->active == 0) {
                this->active = 1;
                this->repeat_mode = 2;
                this->repeat_time = debug_timeGetTime(pnl_scbr_cpp_path, 429);
                this->scroll_action(1, 0);
                this->repaint(1);
            }
        } else if (this->active != 0) {
            this->active = 0;
            this->repeat_mode = 0;
            this->repaint(1);
        }
        break;
    case 3:
        if (this->h_drag == 1) {
            delta = x - this->last_x;
            if (delta > 0) this->h_button;
            pos = this->h_pos;
            minv = this->h_min;
            maxv = this->h_max;
            if (minv == maxv && delta > 0 && x < minv + this->h_page) delta = 0;
            if (minv == this->h_button && delta < 0 && x >= minv + this->h_page) delta = 0;
            if (delta != 0) {
                pos = this->h_pos + delta;
                this->h_pos = pos;
                if (pos < maxv) this->h_pos = maxv;
                else if (pos > this->h_button) this->h_pos = this->h_button;
                this->update_scrollbar();
                this->repaint(1);
                minv = this->h_min;
                maxv = this->h_button;
                if (minv == maxv) newthumb = 0;
                else {
                    newthumb = (this->h_pos - minv) * this->thumb_span / (maxv - minv);
                    if (newthumb < 0) newthumb = 0;
                    else if (newthumb > this->thumb_span - 1) newthumb = this->thumb_span - 1;
                }
                this->scroll_action(4, newthumb);
            }
        } else {
            delta = y - this->last_y;
            if (delta > 0) this->v_min;
            pos = this->v_pos;
            minv = this->v_min;
            maxv = this->v_max;
            if (minv == maxv && delta > 0 && y < minv + this->v_page) delta = 0;
            if (minv == this->v_button && delta < 0 && y >= minv + this->v_page) delta = 0;
            if (delta != 0) {
                pos = this->v_pos + delta;
                this->v_pos = pos;
                if (pos < maxv) this->v_pos = maxv;
                else if (pos > this->v_button) this->v_pos = this->v_button;
                this->update_scrollbar();
                this->repaint(1);
                minv = this->v_min;
                maxv = this->v_button;
                if (minv == maxv) newthumb = 0;
                else {
                    newthumb = (this->v_pos - minv) * this->thumb_span / (maxv - minv);
                    if (newthumb < 0) newthumb = 0;
                    else if (newthumb > this->thumb_span - 1) newthumb = this->thumb_span - 1;
                }
                this->scroll_action(4, newthumb);
            }
        }
        break;
    case 4:
        if (this->is_inside_rect(x, y, &this->r4)) {
            if (this->active == 0) {
                this->active = 1;
                this->repeat_mode = 2;
                this->repeat_time = debug_timeGetTime(pnl_scbr_cpp_path, 448);
                this->scroll_action(2, 0);
                this->repaint(1);
            }
        } else if (this->active != 0) {
            this->active = 0;
            this->repeat_mode = 0;
            this->repaint(1);
        }
        break;
    case 5:
        if (this->is_inside_rect(x, y, &this->thumb)) {
            if (this->active == 0) {
                this->active = 1;
                this->repeat_mode = 2;
                this->repeat_time = debug_timeGetTime(pnl_scbr_cpp_path, 467);
                this->scroll_action(3, 0);
                this->repaint(1);
            }
        } else if (this->active != 0) {
            this->active = 0;
            this->repeat_mode = 0;
            this->repaint(1);
        }
        break;
    }
    if (this->state != 0) {
        this->last_x = x;
        this->last_y = y;
    }
    return 0;
}
