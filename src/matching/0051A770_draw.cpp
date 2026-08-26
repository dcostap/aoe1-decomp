// TRIBE_Panel_Inven::draw
// Canonical ownership: TPanel render_area/clip/parent/visibility fields, the
// TDrawArea DrawDc surface, and TRIBE_Player's inherited attributes table.
// The four text passes mirror the period inventory-panel drawing idiom.
// The source uses typed TPanel/TDrawArea surfaces and four direct text passes.
// Earlier nested positive guards emitted test instructions and an 11-byte tail.
// Natural early no-redraw returns reproduce the original zero-compare guard.
// This source now matches the original function exactly.

#include "../../include/game_globals.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

extern const char s_tpnl_inv_draw[];
extern const char s_fmt_ld[];

extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);

extern "C" {
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC hdc, HGDIOBJ obj);
__declspec(dllimport) int __stdcall SetBkMode(HDC hdc, int mode);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC hdc, COLORREF color);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC hdc, int x, int y,
                                                LPCSTR text, int len);
}

#include "../../include/tpnl_inv_context.h"

void TRIBE_Panel_Inven::draw() {
    char str[20];

    if (this->render_area == 0 || this->visible == 0 ||
        this->active == 0) {
        this->need_redraw = TPanel::NoRedraw;
        return;
    }

    if (this->parent_panel != 0)
        this->parent_panel->draw_rect(&this->clip_rect);

    if (this->player == 0) {
        this->need_redraw = TPanel::NoRedraw;
        return;
    }

            this->draw_setup(0);
            if (this->render_area->GetDc((char*)s_tpnl_inv_draw) != 0) {
                HGDIOBJ old_font = SelectObject(this->render_area->DrawDc,
                                                 (HGDIOBJ)this->font);
                SetBkMode(this->render_area->DrawDc, 1);

                long x = this->pnl_x + 0x20;
                long y = this->pnl_y + 2;

                sprintf(str, s_fmt_ld,
                        (long)this->player->attributes[1]);
                SetTextColor(this->render_area->DrawDc,
                             (COLORREF)this->back_color);
                TextOutA(this->render_area->DrawDc, x - 1, y + 1,
                         str, strlen(str));
                SetTextColor(this->render_area->DrawDc,
                             (COLORREF)this->font_color);
                TextOutA(this->render_area->DrawDc, x, y,
                         str, strlen(str));

                x = this->pnl_x + 0x63;
                sprintf(str, s_fmt_ld,
                        (long)this->player->attributes[0]);
                SetTextColor(this->render_area->DrawDc,
                             (COLORREF)this->back_color);
                TextOutA(this->render_area->DrawDc, x - 1, y + 1,
                         str, strlen(str));
                SetTextColor(this->render_area->DrawDc,
                             (COLORREF)this->font_color);
                TextOutA(this->render_area->DrawDc, x, y,
                         str, strlen(str));

                x = this->pnl_x + 0xA6;
                sprintf(str, s_fmt_ld,
                        (long)this->player->attributes[3]);
                SetTextColor(this->render_area->DrawDc,
                             (COLORREF)this->back_color);
                TextOutA(this->render_area->DrawDc, x - 1, y + 1,
                         str, strlen(str));
                SetTextColor(this->render_area->DrawDc,
                             (COLORREF)this->font_color);
                TextOutA(this->render_area->DrawDc, x, y,
                         str, strlen(str));

                x = this->pnl_x + 0xE9;
                sprintf(str, s_fmt_ld,
                        (long)this->player->attributes[2]);
                SetTextColor(this->render_area->DrawDc,
                             (COLORREF)this->back_color);
                TextOutA(this->render_area->DrawDc, x - 1, y + 1,
                         str, strlen(str));
                SetTextColor(this->render_area->DrawDc,
                             (COLORREF)this->font_color);
                TextOutA(this->render_area->DrawDc, x, y,
                         str, strlen(str));

                SelectObject(this->render_area->DrawDc, old_font);
                this->render_area->ReleaseDc((char*)s_tpnl_inv_draw);
            }
            this->draw_finish();
}
