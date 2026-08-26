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
// Canonical ownership: TPanel fields +0x5C/+0x68/+0x6C/+0x80 and PanelNode::prev_node at +0x04.
// BINARY NOTE: Panel.cpp calls the child, left, right, and fallback handlers at
// virtual slots 0x7C, 0x94, 0xA8, and 0x70.
// Context gate: the reviewed panel_context.h and PanelNode::prev_node surface
// provide these slots without a local placeholder class.

#include "../../include/panel_context.h"
long TPanel::handle_mouse_dbl_click(unsigned char param_1, long param_2, long param_3,
                                    int param_4, int param_5)
{
    if (!active)
        return 0;

    if (!mouse_captured) {
        if (!is_inside(param_2, param_3))
            return 0;

        for (PanelNode* node = last_child_node; node; node = node->prev_node) {
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
        result = mouse_left_dbl_click_action(param_2, param_3, param_4, param_5);
    else
        result = mouse_right_dbl_click_action(param_2, param_3, param_4, param_5);

    if (!result) {
        handle_mouse_down(param_1, param_2, param_3, param_4, param_5);
        return 1;
    }

    return result;
}
