// VA: 004653E0 TPanel::wnd_proc
// Attempt log:
// baseline: the old approximate source was 824 rebuilt bytes, had no local frame,
// and was missing the direct get_mouse_info call.
// probes 2-4: added the typed get_mouse_info surface and moved mouse/key handlers
// out of the common child/command path. The helper fixed the call multiset and
// recovered the 0x0c frame; an unscoped modifier/local layout temporarily made a
// 0x10 frame, then scoping restored it. The out-of-line topology improved edit
// alignment but did not align the compiler's block order with the original.
// probes 5-8: made child traversal the default fallthrough, modeled the 0x400
// user-command and msg-0x111 switch, and tested switch-shaped input dispatch.
// The natural command switch reached exact size (870 bytes) and 30 calls; the
// sparse input-switch variants changed the virtual-call order and were rejected.
// probe 9: used the Panel.cpp-era local GetKeyState function-pointer alias. Best
// current result is exact size/frame/instruction count, 30 calls, 796 differing
// bytes, and 83.33% ordered-call alignment. Remaining structural drift starts
// after the prologue: VC5 places the mouse/key blocks before the original child
// and command fallthrough, and colors the selected target/register homes
// differently. The helper output flags remain clean typed locals; no parameter
// home casts or inline asm were used.
// probe 10: positive key-family spelling worsened ordered calls and was rolled
// back. Final validated source is the probe-9 canonical reconstruction; paused
// because the remaining block-order/register basin is not a bounded blind axis.
// probe 11: typed low-message branch spelling sent the mouse family out of line,
// but replaced the first child/command calls and worsened ordered alignment; restored.
// Main-agent audit restored canonical panel/draw-area destructor ownership and
// removed the function-pointer cache retained solely for codegen metrics. Final
// audited check: exact 870-byte size/0xC frame, 30/30 calls with 83.33% ordered
// alignment, 798-byte diff.
// Revisit probes 12-20: natural nested handlers changed the same 870-byte basin;
// inverted and nested range guards reached 811-920 bytes or changed call order.
// Local lifetime, declaration order, target initialization, and comparison
// direction did not improve the structural split. A local GetKeyState alias and
// mutable import declaration did not beat the audited basin. Restoring the
// period Windows SDK context with windows.h and native POINT changed the result
// to 870 bytes, 339 instructions, and 796 differing bytes. Extra C runtime
// headers and POINT lifetime spelling were codegen duplicates. The original
// child and command blocks still precede mouse and keyboard blocks, while VC5
// keeps those blocks out of order in this source basin. Final validation remains
// MISMATCH; pinned as clean for the next worker.
// probes 30-39: external-source nesting, classifier polarity, positive child
// branches, and the full later virtual surface did not improve the clean basin.
// Probes 41-42: one grouped message switch preserved size and calls, and raised
// shape from 19.47% to 25.37% while keeping the same 796-byte diff. This also
// emits command, timer, scroll, user in the original physical order.
// Probes 43-47: sparse or arithmetic keyboard classifiers raised the shape
// metric, but added a 0x10 frame and moved farther from the clean source.
// context pass: the local slot and offset declarations moved to the recovered
// Panel.cpp header. Rebuild output stayed at 870 bytes, 0x0C frame, 30 calls,
// and the same 796-byte positional diff; the header is safe for this owner.

#include <windows.h>
#include "../../include/panel_context.h"

long TPanel::wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam)
{
    POINT point;
    TPanel* target;
    PanelNode* node;
    long result;

    if (this->active == 0) {
        goto done;
    }

    if (msg <= 0x206) {
        if (msg >= 0x200) {
            goto mouse_input;
        } else if (msg != 0x100 && msg != 0x102 && msg != 0x104) {
            ;
        } else {
            goto keyboard_input;
        }
    }

    node = this->last_child_node;
    while (node != 0) {
        result = node->panel->wnd_proc(hwnd, msg, wParam, lParam);
        if (result != 0) {
            return result;
        }
        node = node->prev_node;
    }

    if (msg <= 0x400) {
        switch (msg) {
        case 0x111:
            return this->handle_command(wParam, lParam);
        case 0x113:
            return this->handle_timer_command(wParam, lParam);
        case 0x114:
        case 0x115:
            return this->handle_scroll(wParam, lParam);
        case 0x400:
            return this->handle_user_command(wParam, lParam);
        }
    }

done:
    return 0;

mouse_input:
{
    int focus_flag;
    int capture_flag;
    if (this->render_area->Wnd != hwnd) {
        goto done;
    }
    if (panel_system.GetInputEnabled() == 0) {
        goto done;
    }

    this->get_mouse_info(wParam, lParam, point, focus_flag, capture_flag);
    target = this;
    if (panel_system.mouseOwner() != 0) {
        target = panel_system.mouseOwner();
    } else if (panel_system.keyboardOwner() != 0) {
        target = panel_system.keyboardOwner();
    } else if (panel_system.modalPanel() != 0) {
        target = panel_system.modalPanel();
    }

    switch (msg) {
    case 0x200:
        return target->handle_mouse_move(point.x, point.y, focus_flag, capture_flag);
    case 0x201:
        return target->handle_mouse_down(1, point.x, point.y, focus_flag, capture_flag);
    case 0x202:
        return target->handle_mouse_up(1, point.x, point.y, focus_flag, capture_flag);
    case 0x203:
        return target->handle_mouse_dbl_click(1, point.x, point.y, focus_flag, capture_flag);
    case 0x204:
        return target->handle_mouse_down(2, point.x, point.y, focus_flag, capture_flag);
    case 0x205:
        return target->handle_mouse_up(2, point.x, point.y, focus_flag, capture_flag);
    case 0x206:
        return target->handle_mouse_dbl_click(2, point.x, point.y, focus_flag, capture_flag);
    }
    goto done;
}

keyboard_input:
{
    int alt;
    int ctrl;
    int shift;
    if (this->render_area->Wnd != hwnd) {
        goto done;
    }
    if (panel_system.GetInputEnabled() == 0) {
        goto done;
    }

    target = this;
    if (panel_system.keyboardOwner() != 0) {
        target = panel_system.keyboardOwner();
    } else if (panel_system.modalPanel() != 0) {
        target = panel_system.modalPanel();
    }

    if (msg == 0x102) {
        return target->handle_char(wParam, (short)lParam);
    }

    alt = GetKeyState(0x12) < 0;
    ctrl = GetKeyState(0x11) < 0;
    shift = GetKeyState(0x10) < 0;
    return target->handle_key_down(wParam, (short)lParam, alt, ctrl, shift);
}
}
