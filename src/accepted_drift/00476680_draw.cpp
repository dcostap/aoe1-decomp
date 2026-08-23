// VA 00476680 TEditPanel::draw
// pnl_edit.cpp:859-973
// Attempt log:
// 1: Natural implementation from packet/decompiler with local TDrawArea/vtable and Win32 imports.
// 2: First compiling pass had exact 940-byte size but field offsets after rect were 4 bytes early; fixed TEditPanel gap so dirty is +0x38, visible +0x70, brush +0x108, bevel_type +0x150, colors +0x154..+0x159.
// 3: Fixed TDrawArea virtual surface: background border call is vtable +0x34 and high-bevel background call is +0x3c; inserted unused +0x38 slot.
// 4: Recovered the palette access through the typed DrawSystem ownership,
// matching the original GetNearestPaletteIndex argument load.
// 5: Implemented top draw_setup/draw_finish flow, dirty clear, Clear/fill background path, background image/border path, bevel switch cases 1..7, Lock/Unlock calls, and edit HWND show/hide/DrawTextEx path.
// 6: Bevel switch now uses original offsets/order for bevel_type and six colors; switch body is close enough that edit diff dropped to 18.8298% while size stayed exact.
// 7: Restructured early visible test from early return to `if (visible != 0) { body }`; no codegen change, rolled form kept harmless.
// 8: Probed /Ob0: no change. Probed /Og-: much worse (91.2766% positional, first mismatch 0), flag removed.
// 9: Remaining first mismatch is at offset 3: rebuilt saves EBX and EDI in the prologue, while original shrink-wraps them until after the visible/null check (`push edi; push ebx` at 00476697/98).
// 10: Current default validation: exact 940-byte size, with the remaining drift in callee-save scheduling and shifted branch distances.
// GIVEUP: left in scratch for future source-shape/context work to recover VC5 shrink-wrapped EBX/EDI saves and exact branch distances.
// Current bounded pass:
// 11: <windows.h> import declarations fixed all 13 indirect API relocations;
//     current checker result is 940B exact size, 27/27 calls, 38 differing bytes.
// 12-16: branch/lifetime, virtual draw declaration, and done-label variants
//     left the emitted code unchanged; canonical TPanel inheritance restored.
// 17: typed DrawArea->DrawSystem->Pal ownership replaced the diagnostic raw
//     vtable read with identical bytes. Final gap is prologue shrink-wrapping:
//     original delays EDI/EBX until after the visible path, while VC5 saves them
//     at entry in this TU; the body is otherwise a 98.19% resynchronized match.
// New claim: baseline revalidated the 940-byte/38-byte-diff clean source.
// Probes 1-6 scoped RECT/old_font, tried positive visible nesting, removed the
// redundant panel receiver, reordered stack-local declarations, and completed
// the same-TU virtual surface; all were codegen duplicates. Restore clean
// source for the documented shrink-wrap blocker.
// New claim probes: a focused guard/receiver variant lab (4 cases), a TPanel
// reference receiver, a shared hidden-exit goto label, and a braced invisible
// guard all preserved the 940-byte/38-byte-diff result. Restored the clean
// pointer receiver and early-return source. The only lead remains VC5's
// entry-save choice versus the original delayed EBX/EDI saves.
// Latest pass: 20 meaningful hypotheses. Header/context, class-surface,
// receiver/lifetime, guard, flag, and declaration variants did not change the
// prologue basin. A narrow offset overlay corrected the proven +0x12C font,
// +0x134 RECT, and +0x144 format accesses; diff improved 38 -> 30 bytes.
// Final clean source remains unresolved only at VC5 entry-save placement and
// its two epilogues. Ambient and risky/small flag labs found no exact variant.
// New claim #2: analyzed all three strict spans before probing. Span
// +0003..+0018 (00476683..00476698) is the entry-save and branch-span hunk.
// The original saves only EBP/ESI, then conditionally pushes EDI/EBX after
// the visible test. VC5 saves EBX/EBP/ESI at entry and EDI before that test.
// Spans +0297..+029A (00476917..0047691A) and +03A4..+03A7
// (00476A24..00476A27) are the matching pop-order hunks. The original pops
// EBX, EDI, ESI, EBP. The rebuilt code pops EDI, ESI, EBP, EBX.
// These three spans account for all 30 strict bytes. Calls, owner identity,
// frame size, and all body bytes outside the spans match after relocation
// masking. Twenty new natural hypotheses covered class ownership, full
// declarations, receiver and local lifetimes, control flow, local types,
// same-TU method declarations, and header context. The best result stayed
// 30 bytes in three spans. The canonical clean source is restored.
// ACCEPTED DRIFT: all 30 changed bytes are VC5 callee-save shrink wrapping.
// The original saves EDI and EBX only after the visible test. The rebuild
// saves them at entry. The visible path restores the same four registers in
// a different order. The hidden path performs only the extra private save and
// restore pair. The 0x18 frame, all 27 calls, both returns, field stores, GDI
// effects, virtual calls, cleanup, and fault order match. This function has no
// SEH. The complete body between the prologue and two epilogues is exact.
// Prior flags and context probes did not recover the original save schedule.
// Bounded original-TU follow-up: exact RGE_Panel_Time::draw and
// TInputPanel::draw donors both delay EDI/EBX until after real guards.
// Restoring their draw_setup/draw_finish names, full TPanel virtual names,
// draw_rect ownership, RedrawMode, local declaration points, and the exact
// view include order did not change the 30-byte result. A positive outer
// visible guard also did not change it. All probes were restored. The
// standalone source has no evidence-backed prologue allocation change.
// Source-gate audit: removed the artificial TPanel receiver lifetime and
// replaced the generic virtual slots with the canonical panel surface.
// Replaced the raw this-relative GDI field cursors with named fields at the
// executable-proven +0x12C, +0x134, and +0x144 offsets. The clean validation
// remains 940 bytes with 30 differing bytes and all 27 calls aligned.
// New claim follow-up: restored the reviewed TPanel, TDrawArea, TDrawSystem,
// and TEditPanel field and method surfaces, including parent_panel, just_drawn,
// clip_rect, color, the full virtual panel names, and the real edit helpers.
// Revalidated after each ownership, layout, ABI, lifetime, control-flow, and
// header change. All twelve natural probes remained a 30-byte mismatch.
// The remaining spans stay limited to the VC5 delayed EBX/EDI saves and the
// two corresponding pop orders. No natural source evidence changes them.
// Claim follow-up: twenty additional natural probes covered reviewed class
// method surfaces, method constness, declaration order, guard switch scopes,
// local lifetimes, named field access, and period header context.
// BINARY NOTE: all supported class and context changes stayed at 940 bytes,
// 27 ordered calls, and the same 30-byte three-span mismatch.
// BINARY NOTE: a render_area alias in the background path extended receiver
// liveness and worsened the result to 143 bytes; direct field access is kept.
// BINARY NOTE: branch scopes, declaration points, unqualified member calls,
// full TPanel/TDrawArea/TDrawSystem surfaces, and exact sibling header context
// did not move the delayed EBX/EDI saves.
// The canonical clean source is restored after this bounded pass.
// Context audit: the draw owner now consumes the shared TPanel/TEditPanel and
// proven TDrawArea method surface. The accepted 30-byte save-schedule drift
// remains unchanged.
// Exact-finish follow-up: function-scope RECT/old_font, function-scope HDC,
// function-scope palette byte, the original focus-branch polarity, a negative
// background guard, and a labelled invisible exit were tested one at a time.
// The declaration and guard forms stayed at 940 bytes with the same 30-byte
// three-span mismatch. The inverted focus form changed the call layout and
// was restored. The canonical source is restored.
// Validation: 004755C0, 00475690, 00475930, and 00475CC0 remain MATCH with
// 0.0000% diff. The fresh draw check remains 30 bytes with 27 ordered calls,
// the same owner and boundary, and the same body islands.

#include "../../include/pnl_edit_context.h"
#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;

extern "C" __declspec(dllimport) unsigned int __stdcall GetNearestPaletteIndex(HPALETTE, COLORREF);
extern "C" __declspec(dllimport) int __stdcall ShowWindow(HWND, int);
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(HWND, const tagRECT*, int);
extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(HDC, HRGN);
extern "C" __declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(HDC, int);
extern "C" __declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
extern "C" __declspec(dllimport) int __stdcall DrawTextExA(HDC, const char*, int, tagRECT*, unsigned int, void*);

void TEditPanel::draw()
{
    this->need_redraw = 0;
    if (this->visible == 0) return;
    RECT r;
    HGDIOBJ old_font;
    this->draw_setup(0);

    if (this->brush && this->active && this->have_focus) {
        uchar c = (uchar)GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, this->back_color);
        this->render_area->Clear(&this->clip_rect, c);
    } else {
        TPanel* bg = this->parent_panel;
        if (bg) {
            if (this->bevel_type >= 2 && this->bevel_type <= 7) {
                bg->draw_rect2(&this->clip_rect);
            } else if (bg->just_drawn == 0) {
                bg->draw_rect(&this->clip_rect);
            }
        } else {
            this->render_area->Clear(&this->clip_rect, this->color);
        }
    }

    if (this->bevel_type != 0) {
        if (this->render_area->Lock("pnl_edit::draw", 1)) {
            switch (this->bevel_type) {
            case 1:
                this->render_area->DrawRect(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color1);
                break;
            case 2:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color1);
                break;
            case 3:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color5, this->bevel_color2, this->bevel_color1);
                break;
            case 4:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color6, this->bevel_color5, this->bevel_color4, this->bevel_color3, this->bevel_color2, this->bevel_color1);
                break;
            case 5:
                this->render_area->DrawBevel(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color6);
                break;
            case 6:
                this->render_area->DrawBevel2(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color2, this->bevel_color5, this->bevel_color6);
                break;
            case 7:
                this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
                break;
            }
        }
        this->render_area->Unlock("pnl_edit::draw");
    }

    if (this->edit_wnd && this->active) {
        if (this->have_focus) {
            if (this->hidden) {
                ShowWindow(this->edit_wnd, 5);
                InvalidateRect(this->edit_wnd, 0, 1);
                this->hidden = 0;
                this->draw_finish();
                return;
            }
        } else {
            if (!this->hidden) {
                ShowWindow(this->edit_wnd, 0);
                this->hidden = 1;
            }
            HDC dc = this->render_area->GetDc("pnl_edit::draw");
            if (dc) {
                SelectClipRgn(dc, this->clip_rgn);
                old_font = SelectObject(dc, this->font);
                SetBkMode(dc, 1);
                SetTextColor(dc, this->text_color2);
                r.left = this->draw_rect.left - 1;
                r.top = this->draw_rect.top + 1;
                r.right = this->draw_rect.right - 1;
                r.bottom = this->draw_rect.bottom + 1;
                DrawTextExA(dc, this->text, -1, &r, this->draw_format, 0);
                SetTextColor(dc, this->text_color1);
                DrawTextExA(dc, this->text, -1, &this->draw_rect, this->draw_format, 0);
                SelectObject(dc, old_font);
                SelectClipRgn(dc, 0);
                this->render_area->ReleaseDc("pnl_edit::draw");
            }
        }
    }

    this->draw_finish();
}
