// VA: 00465DC0 TPanel::handle_mouse_move
// Panel.cpp lines 1857-1913
// Attempt log:
// 1: natural source with helper iabs: exact through 0x65, but helper calls bloated drag block; positional 46.2%, edit 27.0%.
// 2: inline ternary absolute-value expressions: no helper calls but VC5 emitted branchy abs; still mismatch.
// 3: use abs from stdlib: VC5 emits original cdq/xor/sub and drops edit diff to 7.8%, but captured x/y regs are swapped (x=ESI,y=ECX not original x=EBX,y=ESI).
// 4: captured-branch x/y locals: no codegen change.
// 5: register captured x/y locals: no codegen change.
// 6: swapped long parameter declaration order: worsened first mismatch to 0x26; rolled back.
// 7: reverse local declaration order: no codegen change.
// 8: named dx/dy abs temporaries: worsened prologue/register allocation (first mismatch 4); rolled back.
// 9: flags /O2 no-/Oy and /Ox unchanged; /O1 much too short.
// 10: int virtual returns: no codegen change.
// 11: remove captured mx/my aliases and use parameters directly: no codegen change.
// Best final: exact through offset 0xBF; positional diff 31/422 (7.3460%), edit diff 33/422 (7.8199%).
// Accepted-drift suggestion: remaining drift is localized to captured-drag branch register allocation/order (rebuilt keeps x in ESI and y in ECX instead of original x in EBX and y in ESI); calls, tests, constants, member stores, returns, and stack cleanup are behavior-equivalent.

#include <stdlib.h>

#ifndef AOE1_PANEL_CONTEXT_H
class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int); // +0x74
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int); // +0x80
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int); // +0x8C
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int); // +0xA0
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(void*);
    virtual int is_inside(long x, long y);                       // +0xBC

    char gap_04[0x58];
    PanelNode* last_child_node; // +0x5C
    char gap_60[0x08];
    int mouse_captured;         // +0x68
    int active;                 // +0x6C
    char gap_70[0x10];
    int handle_mouse_input;     // +0x80
    char gap_84[0x3C];
    int mouse_move_tolerance;   // +0xC0
    long mouse_down_x;          // +0xC4
    long mouse_down_y;          // +0xC8
    char gap_CC[0x20];
    unsigned char mouse_action; // +0xEC
    unsigned char mouse_down_button; // +0xED

};

#endif
long TPanel::handle_mouse_move(long x, long y, int a, int b)
{
    if (this->active == 0) {
        return 0;
    }

    if (this->mouse_captured == 0) {
        if (!this->is_inside(x, y)) {
            return 0;
        }
        PanelNode* node = this->last_child_node;
        while (node != 0) {
            int r = node->panel->handle_mouse_move(x, y, a, b);
            if (r != 0) {
                return r;
            }
            node = node->prev;
        }
        if (this->handle_mouse_input == 0) {
            return 0;
        }
        return this->mouse_move_action(x, y, a, b);
    }

    if (this->handle_mouse_input == 0) {
        return 0;
    }

    if (this->mouse_action == 1 || this->mouse_action == 2) {
        if (this->mouse_down_button == 1) {
            if (abs(x - this->mouse_down_x) <= this->mouse_move_tolerance &&
                abs(y - this->mouse_down_y) <= this->mouse_move_tolerance) {
                return 1;
            }
        } else {
            if (abs(x - this->mouse_down_x) <= 10 &&
                abs(y - this->mouse_down_y) <= 10) {
                return 1;
            }
        }
    }

    this->mouse_action = 3;
    if (this->mouse_down_button == 1) {
        this->mouse_left_move_action(x, y, a, b);
        return 1;
    }
    if (this->mouse_down_button == 2) {
        this->mouse_right_move_action(x, y, a, b);
        return 1;
    }
    this->mouse_move_action(x, y, a, b);
    return 1;
}
