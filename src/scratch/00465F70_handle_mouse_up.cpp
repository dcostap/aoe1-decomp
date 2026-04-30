// 00465F70 TPanel::handle_mouse_up(unsigned char param_1, long param_2, long param_3, int param_4, int param_5)
// Source: Panel.cpp lines 1919-1959
// Size: 237 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 TU-context drift (virtual dispatch vtable slots)
// The function calls 4 virtual methods at vtable offsets 0xBC, 0x78, 0x90, 0xA4.
// These slots are determined by the full TPanel class hierarchy (48+ methods)
// and cannot be reproduced from a single-function scratch file.
//
// Attempt log:
// Probe 1: extern function pointer typedef + cast — call [eax+0BCh] MATCHED!
//   But __cdecl calling convention added stack cleanup (add esp, 0Ch)
//   80.2% positional diff, 51.9% edit diff, size correct
// Probe 2: member function pointer — VC5 can't cast void* to member fn ptr
// Probe 3: extern C functions — generates direct calls, not vtable calls
// Probe 4: explicit vtable dispatch via function pointer cast
//   call instructions matched offsets, but calling convention differed
//
// Key findings (struct offsets correct):
// +0x5C: last_child_node (PanelNode*)
// +0x68: mouse_captured (int)
// +0x6C: active (int)
// +0x80: handle_mouse_input (int)
// +0xEC: mouse_action (unsigned char)
// +0xED: mouse_down_button (unsigned char)
// PanelNode: +0x00 panel(TPanel*), +0x04 prev_node(PanelNode*)
//
// Remaining drift: virtual call instruction encoding (calling convention)

struct PanelNode;

struct TPanel {
    char vtable_ptr[4];           // +0x00
    char pad_04[0x54 - 0x04];
    PanelNode* node;              // +0x54
    PanelNode* first_child_node;  // +0x58
    PanelNode* last_child_node;   // +0x5C
    char pad_60[0x68 - 0x60];
    int mouse_captured;           // +0x68
    int active;                   // +0x6C
    char pad_70[0x80 - 0x70];
    int handle_mouse_input;       // +0x80
    char pad_84[0xEC - 0x84];
    unsigned char mouse_action;   // +0xEC
    unsigned char mouse_down_button; // +0xED
};

struct PanelNode {
    TPanel* panel;       // +0x00
    PanelNode* prev_node; // +0x04
    PanelNode* next_node; // +0x08
};

long handle_mouse_up(TPanel* this_, unsigned char param_1, long param_2, long param_3, int param_4, int param_5)
{
    if (!this_->active)
        return 0;

    if (!this_->mouse_captured) {
        // Not captured: hit-test then walk children
        if (!((long (*)(TPanel*, long, long))(((void***)this_)[0][0xBC / 4]))(this_, param_2, param_3))
            return 0;

        PanelNode* node = this_->last_child_node;
        if (!node)
            return 0;

        int p5 = param_5;
        int p4 = param_4;
        unsigned char p1 = param_1;

        do {
            if (((long (*)(TPanel*, unsigned char, long, long, int, int))(((void***)node->panel)[0][0x78 / 4]))(node->panel, p1, param_2, param_3, p4, p5))
                return 1;
            node = node->prev_node;
        } while (node != 0);

        return 0;
    }

    // Captured
    if (!this_->handle_mouse_input)
        return 0;

    long result;
    if (this_->mouse_down_button == 1)
        result = ((long (*)(TPanel*, long, long, int, int))(((void***)this_)[0][0x90 / 4]))(this_, param_2, param_3, param_4, param_5);
    else
        result = ((long (*)(TPanel*, long, long, int, int))(((void***)this_)[0][0xA4 / 4]))(this_, param_2, param_3, param_4, param_5);

    if (result != 0)
        return 0;

    if (param_1 == this_->mouse_down_button) {
        this_->mouse_down_button = 0;
        this_->mouse_action = 0;
    }

    return 1;
}
