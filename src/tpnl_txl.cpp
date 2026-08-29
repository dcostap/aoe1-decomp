//
// Context gate:
// - Address sequence: proved as 00520D70, 00520E30, and 00520ED0.
// - Exact anchors: proved by the constructor, set_info, and draw symbols,
//   their direct calls, and the shared TPanel/TRIBE_Panel_Text_Line layouts.

#include "../include/tpnl_txl.h"
#include <string.h>

//

TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(TDrawArea* draw_area, TPanel* parent, void* font_arg) : TPanel() {
    this->font = font_arg;
    this->text_type = 0;
    this->text[0] = 0;
    this->id = 0;
    if (!this->setup(draw_area, parent, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
    }
}

//
//   Remaining: vtable load timing and no ecx=this in set_redraw call

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

//
//   original uses `push ecx`+`push esi` and saves edi/ebp/ebx later in draw path

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
