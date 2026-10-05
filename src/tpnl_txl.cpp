
#include "../include/tpnl_txl.h"
#include <string.h>

static char s_tpnl_txl_draw[] = "tpnl_txl::draw";

TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(TDrawArea* render_area_in, TPanel* parent_panel_in, void* font_in) :
    TPanel() {
    this->font = font_in;
    this->text_type = 0;
    this->text[0] = 0;
    this->id = 0;
    if (!this->setup(render_area_in, parent_panel_in, 0, 0, 0, 0, 0)) {
        this->error_code = 1;
    }
}

void TRIBE_Panel_Text_Line::set_info(unsigned char text_type_in, char* text_in, long id_in) {
    if (text_type_in == this->text_type && strcmp(text_in, this->text) == 0 && id_in == this->id)
        return;

    this->text_type = text_type_in;
    strcpy(this->text, text_in);
    this->id = id_in;

    this->set_redraw(TPanel::RedrawNormal);
}

extern "C" {
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
}

void TRIBE_Panel_Text_Line::draw() {
    if (this->render_area == 0 || this->visible == 0 || this->active == 0)
        return;

    if (this->parent_panel != 0)
        this->parent_panel->draw_rect(&this->clip_rect);

    this->draw_setup(0);

    if (this->render_area->GetDc(s_tpnl_txl_draw)) {
        HGDIOBJ old_font = SelectObject(this->render_area->DrawDc, (HGDIOBJ) this->font);
        SetBkMode(this->render_area->DrawDc, TRANSPARENT);
        SetTextColor(this->render_area->DrawDc, 0);

        if (this->text[0] != 0) {
            TextOutA(this->render_area->DrawDc, this->pnl_x, this->pnl_y, this->text, strlen(this->text));
        }

        SelectObject(this->render_area->DrawDc, old_font);
        this->render_area->ReleaseDc(s_tpnl_txl_draw);
    }

    this->draw_finish();
}
