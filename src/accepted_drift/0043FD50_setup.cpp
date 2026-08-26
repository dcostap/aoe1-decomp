// VA: 0043FD50 TMessageDialog::setup (main)
// Dlg_msg.cpp lines 71-165

// attempt 1 baseline: simple panel stubs, but wrong virtual slots and setup order
// attempt 2: restored the period panel virtual surface; create_text is vt[64]
// and create_button(char*, char*) is vt[59]. Base setup uses p4/p5. Button
// and text ownership remains named.
// attempt 3: nested renderArea evaluation kept the base setup call ordered.
// attempt 4: reserved the two unused text overload slots to select vt[64].
// attempt 5: shared the button text and hotkey switch tail.
// attempt 6: a counted for loop hoisted the create_button function pointer.
// attempt 7: an info_id local had no emitted-code effect; it was removed.
// attempt 8: the spacing guard variant was rolled back; the original source
// shape uses the prior < 1 form in this compiler basin.
// attempt 9: corrected create_button arguments to x, y, button width, height.
// attempt 10: separate adjacent button fields emitted the same code.
// attempt 11: passed p5 as the dialog height to base setup per the original
// stack load; this grew the body to 676 bytes and worsened the first hunk.
// attempt 12: removed the redundant positive button-count wrapper; the packet
// shows one loop-entry test before the create_button vtable load. Diff improved
// 586->563 bytes, but shape and exact-block coverage worsened; kept natural code.
// claim orch-43FD50-a: result-local and array variants worsened structural shape;
// chained button initialization retained the original first-hunk basin.
// Local draw-area staging with p5 base height is the best period-plausible source
// reconstruction here; it reaches exact size and ordered calls.
// attempt 13: restored the two empty string arguments proven by the button-call
// relocations. This reduced the diff by one byte and improved block shape.
// attempt 14: ordered the count switch as cases 0, 4, and 1-3 from PDB blocks.
// attempt 15: ordered the text switch as cases 0, 1, 2, 4, and 3 from PDB
// blocks. Direct case-local button1 calls recover the original immediate pushes.
// Declaration, loop-form, spacing, and separate-zero probes were unchanged or
// worse. Canonical ABI reduction restored both TDialogPanel setup overloads,
// the inline button array, and the reviewed s_592A40 empty string object. These
// changes do not alter emitted bytes in the standalone build. Best current
// result: exact size and ordered call parity; diff 525, shape 80.85%, with the
// first mismatch at +0005 in register scheduling.
//
// BINARY NOTE: The PDB owner is Dlg_msg.cpp:71-165. The target has one
// compiler-facing owner and no EH frame. The original calls renderArea, the
// char* create_text slot (+0x100), one cached char* create_button slot (+0xEC),
// eight set_text calls, set_tab_order (+0xC8), and set_curr_child in order.
//
// Exact-finish reduction: inline renderArea worsened the diff to 574. The
// positive spacing guard worsened it to 536. A do/while loop added a second
// create_button call site and 89 bytes. A while loop was a codegen duplicate.
// Full setup overloads, array ownership, parent-base ownership, top local
// declarations, the global empty string, and a named button height were
// tested. The reduced clean source remains the natural local-staging form.
// Accepted-drift review: button members clear before the first call; base setup
// arguments and failure publication match; dlg_type publishes before text
// creation; text and button geometry, member output addresses, labels, hotkey,
// tab order, current-child publication, call faults, and returns match.
// Residual drift is parameter preload order, private loop homes, division
// lowering, vtable-pointer scheduling, and equivalent switch tails.

#ifndef DLG_MSG_CANONICAL_TU
#include "../../include/dlg_msg_context.h"
#endif

long TMessageDialog::setup(TPanel* p1, char* p2, long p3, long p4,
    long p5, unsigned char p6, char* p7, long p8, long p9) {
    TDrawArea* draw_area;
    int num_buttons;
    int space;
    int y;
    TButtonPanel** next;
    int x;
    int i;
    TButtonPanel* hotkey_button;
    button[0] = button[1] = button[2] = 0;
    draw_area = p1->renderArea();
    if (TDialogPanel::setup(draw_area, p1, p4, p5, p2, p3, 1) == 0) {
        return 0;
    }

    dlg_type = p6;
    if (create_text((TPanel*)this, &text, p7, 3, 3,
            width - 3, height - p9 - 6, 0x0B, 1, 1, 1) == 0) {
        return 0;
    }

    switch (dlg_type) {
    case 0:
        num_buttons = 1;
        break;
    case 4:
        num_buttons = 3;
        break;
    case 1:
    case 2:
    case 3:
        num_buttons = 2;
        break;
    default:
        return 0;
    }

    space = width - num_buttons * p8;
    if (space < 1) {
        space = 0;
    } else {
        space /= num_buttons + 1;
    }

    y = height - p9 - 7;
    next = button;
    x = space;
    for (i = 0; i < num_buttons; ++i) {
        if (create_button((TPanel*)this, next, s_592A40, s_592A40,
                x, y, p8, p9, 0x0B, 0, 0) == 0) {
            return 0;
        }
        x += space + p8;
        ++next;
    }

    switch (dlg_type) {
    case 0:
        button[0]->set_text(0, 0xFA1);
        goto set_tab_order;
    case 1:
        button[0]->set_text(0, 0xFA1);
        button[1]->set_text(0, 0xFA2);
        hotkey_button = button[1];
        goto set_hotkey;
    case 2:
        button[0]->set_text(0, 0xFA3);
        button[1]->set_text(0, 0xFA4);
        hotkey_button = button[1];
        goto set_hotkey;
    case 4:
        button[0]->set_text(0, 0xFA3);
        button[1]->set_text(0, 0xFA4);
        button[2]->set_text(0, 0xFA2);
        hotkey_button = button[2];
        goto set_hotkey;
        break;
    case 3:
        button[0]->set_text(0, 0xFA5);
        button[1]->set_text(0, 0xFA7);
        hotkey_button = button[1];
        goto set_hotkey;
    default:
        goto set_tab_order;
    }

set_hotkey:
    hotkey_button->hotkey = 0x1B;
    hotkey_button->hotkey_shift = 0;
set_tab_order:
    set_tab_order((TPanel**)button, num_buttons);
    set_curr_child(button[0]);
    return 1;
}
