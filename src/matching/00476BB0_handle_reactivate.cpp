// VA: 00476BB0 TEditPanel::handle_reactivate (45 B, EXACT MATCH)
// PDB source: pnl_edit.cpp lines 1060-1067
// PDB-qualified owner and boundary: TEditPanel::handle_reactivate at
// 00476BB0..00476BDC, followed by padding before the normal 00476BE0
// handle_mouse_down sibling. The shared panel surface in pnl_edit_context.h
// keeps edit_wnd at +0xF4, have_focus at +0x78, and the sibling text anchor at
// +0xFC; do not add a local TEditPanel owner or a duplicate virtual surface.
// Key insight: local HWND hFocus = GetFocus() forces VC5 to save this in esi
// and reuse it for edit_wnd after the call. Comparison order matters:
// if (hFocus != this->edit_wnd) generates cmp eax, esi (3B C6).
// BINARY NOTE: The two imported __stdcall calls stay in source order. The
// natural guards preserve their fault order and caller cleanup (no explicit
// cleanup is emitted for either call).

#include "../../include/pnl_edit_context.h"

extern "C" __declspec(dllimport) HWND __stdcall GetFocus(void);
extern "C" __declspec(dllimport) HWND __stdcall SetFocus(HWND hwnd);

void TEditPanel::handle_reactivate() {
    if (this->edit_wnd && this->have_focus) {
        HWND hFocus = GetFocus();
        if (hFocus != this->edit_wnd)
            SetFocus(this->edit_wnd);
    }
}
