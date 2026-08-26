// VA: 0045B760 TMousePointer::update_mouse_position
// PDB source: Mouseptr.cpp lines 567-717
// attempt log:
// 1: helper body with decompiler fields compiled but treated this as stack parameter; 88.21% positional diff.
// 2: switched to Poll.cpp TMousePointer field layout; body shrank to 752 bytes, close early WinAPI/point conversion but wrong this-load/prologue and game-window offsets.
// 3: tried free __fastcall wrapper to force ECX; VC5/build extraction still selected stack-this family, no improvement.
// 4: corrected game/window field order from Poll.cpp; early bounds now use +118/+11C etc, proving layout mismatch with this function's observed +138/+13C remains.
// 5: kept natural RECT assignment for cursor_rect=new_save_rect; size near original but scheduling/registers differ through clipping tail.
// 6: restored the complete Mouseptr.cpp class layout, modeled game_window at +0x10C,
//    and made the definition a real __thiscall member; this is the clean source baseline.
// 7: branch-specific bottom assignment improved the natural CFG/size basin; a selected
//    bottom local duplicated the earlier weaker codegen.
// 8: nested mode/window guards, bool in_game, and declaration initialization were
//    nonproductive; the best source keeps the ordinary combined guard and int selector.
// 9: swapping the game-arm right/bottom assignment order produced the best current
//    emitted code (196 strict diff bytes, 758 rebuilt bytes); retain that source order.
// 10: a top temporary moved a few late stores but did not improve positional bytes;
//     rolled back to direct member source.
// 11: tested direct bottom-clipping expressions without the temporary; VC5 rewrote
//     the subtraction into reverse add arithmetic, worsened CFG alignment, and was rolled back.
// 12: matched the line-675 temporary order for top clipping; emitted code was a
//     duplicate after rollback, with no positional gain.
// 13: tested top-declared decompiler-style clipping locals; the frame grew to 0xC
//     and structural similarity fell, so restored the natural block.
// 14: mutating mouse_rect.bottom before the clipping reductions reached exact size,
//     but caused broad CFG/register drift and was rolled back.
// 15: reordered the natural POINT and in_game declarations to test the decompiler's
//     local ordering; VC5 emitted an identical body, so restored the clean source.
// Fresh pass: tested bool and initialized selector forms, nested guards, canonical
// long coordinate widths, and function-scope TDrawArea/top-delta locals; none beat
// the 758-byte baseline. Direct top/bottom clipping forms changed arithmetic or
// CFG and were rolled back. Explicit cursor_rect pointer liveness worsened to 221.
// Fresh pass: added the exact TMousePointer tail and Poll/GetDDBltError member
// declarations, full TDrawArea and TDrawSystem donor surfaces, and period
// windows.h/stdlib/string/memory/stdio headers. All emitted the same baseline.
// Fresh pass: ambient declaration lab (32 variants) found one codegen group; a
// six-variant selector type/test lab found only baseline and bool groups; no exact.
// These probes confirm the remaining difference is the EBX/EDI/EBP allocation
// basin and three-byte late clipping shift, not calls, frame, layout, or headers.
// left in scratch: remaining work, if any, should be localized source/declaration or
// TU-context probes after validating the member-function baseline.
// Historical blocker: in the negative-top clipping arm, the executable clears
// mouse_rect.top before it writes cursor_rect.top and new_save_rect.bottom.
// The former direct-member source performed those writes first.
// Final values match, but member publication and failing-store order differed.
// Fresh worker probes: preserving the top value and pre-reading new_save_rect.bottom
// reproduced the prior 197-byte basin; adding decompiler-style function-scope
// clipping temporaries grew the frame to 0xC and reached 276 bytes. A register
// selector and the retained top/bottom local forms were duplicate basins.
// The clean 758-byte source remains the smallest natural reconstruction.
// Context pass: this owner now includes the canonical Mouseptr.cpp context.
// TMousePointer, TDrawSystem, TDrawArea, and RECT4 ownership use the reviewed
// PDB layout. The owner remains in PDB line band 567-717 and in mouseptr_tu.cpp.
// Prior continuation finish pass: named zero, register-selector, nested
// game-window, and historical clipping forms either reproduced the 196-byte
// basin or grew the frame/body. The baseline retained the executable's
// clipping and publication order; its register basin remained unresolved.
// Current-claim exact: a named top local with mouse_rect.top cleared before
// cursor_rect.top and new_save_rect.bottom reproduces the original 755 bytes.
// Walkback: the pre-read new_save_rect.bottom was incidental; direct member
// publication restored the 196-byte mismatch. The reduced top-local source is
// natural and preserves the proven publication order.

#include "../../include/mouseptr_context.h"

struct POINT { long x; long y; };
extern "C" int (__stdcall* const GetCursorPos)(POINT*);
extern "C" int (__stdcall* const ScreenToClient)(void*, POINT*);

int TMousePointer::update_mouse_position() {
    POINT point;
    int in_game;
    if (this->custom_draw == 0) return 0;
    GetCursorPos(&point);
    if (this->render_area->DrawSystem->ScreenMode == 1) {
        ScreenToClient(this->render_area->Wnd, &point);
        if (point.x > 0x8000) point.x -= 0x10000;
        if (point.y > 0x8000) point.y -= 0x10000;
    }
    this->mouse_x = point.x;
    this->mouse_y = point.y;
    if (this->GameMode != 0 && this->GameEnabled != 0 && this->mouse_x >= this->game_window.left && this->mouse_x < this->game_window.right && point.y >= this->game_window.top && point.y < this->game_window.bottom) {
        this->next_facet = this->game_facet; in_game = 1;
    } else {
        this->next_facet = this->facet; in_game = 0;
    }
    if (this->save_area_valid != 0 && point.x == this->save_x && point.y == this->save_y && this->next_facet == this->last_facet) return 0;
    this->save_x = point.x; this->save_y = point.y;
    this->new_save_rect.left = 0; this->new_save_rect.top = 0;
    if (in_game != 0) {
        this->new_save_rect.right = this->gWidth;
        this->new_save_rect.bottom = this->gHeight;
        this->mouse_rect.left = this->mouse_x - this->g_left;
        this->mouse_rect.top = this->mouse_y - this->g_top;
        this->mouse_rect.right = this->g_right + this->mouse_x;
        this->mouse_rect.bottom = this->g_bottom + this->mouse_y;
    } else {
        this->new_save_rect.right = this->cWidth;
        this->new_save_rect.bottom = this->cHeight;
        this->mouse_rect.left = this->mouse_x - this->d_left;
        this->mouse_rect.top = this->mouse_y - this->d_top;
        this->mouse_rect.right = this->d_right + this->mouse_x;
        this->mouse_rect.bottom = this->d_bottom + this->mouse_y;
    }
    this->cursor_rect = this->new_save_rect;
    if (this->mouse_rect.right >= 0 && this->mouse_rect.bottom >= 0) {
        TDrawArea* da = this->render_area;
        if (this->mouse_rect.left <= da->Width && this->mouse_rect.top <= da->Height) {
            if (this->mouse_rect.left < 0) { this->cursor_rect.left = -this->mouse_rect.left; this->new_save_rect.right -= this->cursor_rect.left; this->mouse_rect.left = 0; }
            if (this->mouse_rect.right > da->Width) { int t = this->mouse_rect.right - da->Width; this->cursor_rect.right -= t; this->new_save_rect.right -= t; this->mouse_rect.right = da->Width; }
            int top = this->mouse_rect.top;
            if (top < 0) {
                this->mouse_rect.top = 0;
                top = -top;
                this->cursor_rect.top = top;
                this->new_save_rect.bottom -= top;
            }
            if (this->mouse_rect.bottom > da->Height) { int t = this->mouse_rect.bottom - da->Height; this->cursor_rect.bottom -= t; this->new_save_rect.bottom -= t; this->mouse_rect.bottom = da->Height; }
            this->MouseOnScreen = 1; return 1;
        }
    }
    this->MouseOnScreen = 0; return 1;
}
