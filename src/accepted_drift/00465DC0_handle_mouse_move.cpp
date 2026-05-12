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

class TPanel;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev;
};

class TPanel {
public:
#define VPAD(n) virtual void v##n();
    VPAD(0) VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
    VPAD(8) VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23)
    VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28)
#undef VPAD
    virtual int child_mouse_move(long x, long y, int a, int b); // +0x74
    virtual void v30();
    virtual void v31();
    virtual int on_mouse_move(long x, long y, int a, int b);     // +0x80
    virtual void v33();
    virtual void v34();
    virtual int on_left_drag(long x, long y, int a, int b);      // +0x8C
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual int on_right_drag(long x, long y, int a, int b);     // +0xA0
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
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

    long handle_mouse_move(long x, long y, int a, int b);
};

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
            int r = node->panel->child_mouse_move(x, y, a, b);
            if (r != 0) {
                return r;
            }
            node = node->prev;
        }
        if (this->handle_mouse_input == 0) {
            return 0;
        }
        return this->on_mouse_move(x, y, a, b);
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
        this->on_left_drag(x, y, a, b);
        return 1;
    }
    if (this->mouse_down_button == 2) {
        this->on_right_drag(x, y, a, b);
        return 1;
    }
    this->on_mouse_move(x, y, a, b);
    return 1;
}
