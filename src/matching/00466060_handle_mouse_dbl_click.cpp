// 00466060 TPanel::handle_mouse_dbl_click
// Source: Panel.cpp lines 1965-1998, size 219 bytes
//
// Attempt log:
// Baseline: natural child traversal and left/right action dispatch had the right fields/calls,
// but a raw cdecl fallback was 15 bytes short and colored the saved parameters differently.
// Raw member-pointer and typed-vtable fallback variants preserved behavior but did not improve
// the compiler basin.
// Exact: model the binary's +70h fallback as TPanel::handle_mouse_down. The pre-pushed param_5
// and stack-home vtable save then arise naturally from the four-argument action calls.
// Exact: return a child's nonzero result directly; fallback alone returns the literal 1.
// Canonical ownership: TPanel fields +0x5C/+0x68/+0x6C/+0x80 and PanelNode::prev at +0x04.

#ifndef AOE1_PANEL_CONTEXT_H
struct PanelNode;

struct TPanel {
    // vtable slots needed: 28(0x70), 31(0x7C), 37(0x94), 42(0xA8), 47(0xBC)
    virtual long d0();  virtual void d1();  virtual void d2();
    virtual void d3();  virtual void d4();  virtual void d5();
    virtual void d6();  virtual void d7();  virtual void d8();
    virtual void d9();  virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14();
    virtual void d15(); virtual void d16(); virtual void d17();
    virtual void d18(); virtual void d19(); virtual void d20();
    virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26();
    virtual void d27();
    // slot 28 = 0x70
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual void d29(); virtual void d30();
    // slot 31 = 0x7C
    virtual long handle_dbl_click_child(unsigned char, long, long, int, int);
    virtual void d32(); virtual void d33(); virtual void d34();
    virtual void d35(); virtual void d36();
    // slot 37 = 0x94
    virtual long left_dbl_click_action(long, long, int, int);
    virtual void d38(); virtual void d39(); virtual void d40();
    virtual void d41();
    // slot 42 = 0xA8
    virtual long right_dbl_click_action(long, long, int, int);
    virtual void d43(); virtual void d44(); virtual void d45();
    virtual void d46();
    // slot 47 = 0xBC
    virtual long is_inside(long, long);

    // Fields used by this function
    char pad_04[0x5C - 4];
    PanelNode* last_child_node;         // +0x5C
    char pad_60[0x68 - 0x60];
    int mouse_captured;                 // +0x68
    int active;                         // +0x6C
    char pad_70[0x80 - 0x70];
    int handle_mouse_input;             // +0x80

    long handle_mouse_dbl_click(unsigned char, long, long, int, int);
};

struct PanelNode {
    TPanel* panel;     // +0x00
    PanelNode* prev;   // +0x04
    PanelNode* next;   // +0x08
};

#endif
long TPanel::handle_mouse_dbl_click(unsigned char param_1, long param_2, long param_3,
                                    int param_4, int param_5)
{
    if (!active)
        return 0;

    if (!mouse_captured) {
        if (!is_inside(param_2, param_3))
            return 0;

        for (PanelNode* node = last_child_node; node; node = node->prev) {
            long child_result = node->panel->handle_mouse_dbl_click(
                param_1, param_2, param_3, param_4, param_5);
            if (child_result)
                return child_result;
        }
    }

    if (!handle_mouse_input)
        return 0;

    long result;
    if (param_1 == 1)
        result = left_dbl_click_action(param_2, param_3, param_4, param_5);
    else
        result = right_dbl_click_action(param_2, param_3, param_4, param_5);

    if (!result) {
        handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
        return 1;
    }

    return result;
}
