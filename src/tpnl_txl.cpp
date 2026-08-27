// PDB source module: C:/msdev/work/age1_x1/tpnl_txl.cpp.
// Definitions follow the original PDB source order.
//
// Context gate:
// - PDB source module: proved by the module packet as tpnl_txl.cpp.
// - Source order: proved by lines 23-34, 40-47, and 53-79.
// - Owning class: proved by the PDB symbols as TRIBE_Panel_Text_Line.
// - Address sequence: proved as 00520D70, 00520E30, and 00520ED0.
// - Exact anchors: proved by the constructor, set_info, and draw symbols,
//   their direct calls, and the shared TPanel/TRIBE_Panel_Text_Line layouts.

#include "../include/tpnl_txl.h"
#include <string.h>

// 00520D70 TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line
// Source: tpnl_txl.cpp lines 23-34
//
// Attempt log:
// Probe 1: reuse TPanel pattern from RGE_Panel_Time constructor + /GX for EH prolog

TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(TDrawArea* draw_area, TPanel* parent, void* font_arg) : TPanel() {
    this->font = font_arg;
    this->text_type = 0;
    this->text[0] = 0;
    this->id = 0;
    if (!this->setup(draw_area, parent, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
    }
}

// 00520E30 TRIBE_Panel_Text_Line::set_info
// Source: tpnl_txl.cpp lines 40-47
//
// Attempt log:
// Probe 1: strcmp/strcpy with __stdcall function ptr — 30.8% diff, register allocation off
// Probe 2: swapped operand order (type == text_type, strcmp(str, text)) — 20.1% diff, strcmp matches!
//   Remaining: vtable load timing and no ecx=this in set_redraw call
// Probe 3: declare set_redraw in TPanel and call as member function for thiscall codegen

void TRIBE_Panel_Text_Line::set_info(unsigned char type, char* str, long new_id)
{
    if (type == this->text_type && strcmp(str, this->text) == 0 && new_id == this->id)
        return;

    this->text_type = type;
    strcpy(this->text, str);
    this->id = new_id;

    this->set_redraw(TPanel::RedrawNormal);
}

// The original module declares these imported APIs before draw.
extern "C" {
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
}

extern char s_tpnl_txl_draw[];

// 00520ED0 TRIBE_Panel_Text_Line::draw
// Source: tpnl_txl.cpp lines 53-79
//
// Attempt log:
// Probe 1: standard structure — VC5 saves all registers in prologue using `sub esp,8`,
//   original uses `push ecx`+`push esi` and saves edi/ebp/ebx later in draw path
// Probe 2: goto-based single return — still `sub esp,8` prologue, 89.7% diff
// Probe 3: deep codegen basin mismatch on register saving pattern and stack frame
// Probe 4: void return + extern function pointers (failed VC5 syntax)
// Probe 5: eliminated dc local; GetDc used only as condition guard
// Probe 6-8: various virtual call approaches
// Probe 7: used render_area->DrawDc inline instead of cached HDC local
// Probe 8: eliminated vtable named local — lost mov ecx,esi for thiscall
// Probe 9: restored vtable local + dc elimination → push ecx prologue match!
// Probe 10: got parent_panel into ecx via typed virtual method
// Probe 11: added the period TPanel virtual surface for draw_setup,
//   draw_finish, and draw_rect → 0.0000% MATCH

void TRIBE_Panel_Text_Line::draw()
{
    if (this->render_area == 0 || this->visible == 0 || this->active == 0)
        return;

    if (this->parent_panel != 0)
        this->parent_panel->draw_rect(&this->clip_rect);

    this->draw_setup(0);

    if (this->render_area->GetDc(s_tpnl_txl_draw)) {
        HGDIOBJ old_font = SelectObject(this->render_area->DrawDc, (HGDIOBJ)this->font);
        SetBkMode(this->render_area->DrawDc, 1);
        SetTextColor(this->render_area->DrawDc, 0);

        if (this->text[0] != 0) {
            TextOutA(this->render_area->DrawDc, this->pnl_x, this->pnl_y,
                     this->text, strlen(this->text));
        }

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_txl_draw);
    }

    this->draw_finish();
}
