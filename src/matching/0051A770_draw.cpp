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

#ifndef TPNL_INV_SHARED_CONTEXT
class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;

    void* GetDc(char* name);
    void ReleaseDc(char* name);
};

class TPanel {
public:
    enum RedrawMode { NoRedraw = 0, Redraw = 1, RedrawFull = 2 };

    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_redraw(int mode);
    virtual long handle_idle();
    virtual void draw_setup(int clear);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT* rect);

    char gap_04[8];
    long pnl_x;
    long pnl_y;
    char gap_14[0x0C];
    TDrawArea* render_area;
    RECT clip_rect;
    char gap_34[0x04];
    RedrawMode need_redraw;
    char gap_3C[0x04];
    TPanel* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x80];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x4C];
    float* attributes;
};

class TRIBE_Player : public RGE_Player {
};

class TRIBE_Panel_Inven : public TPanel {
public:
    virtual void draw();

    char gap_F4[0x04];
    TRIBE_Player* player;
    short save_attr_num;
    short gap_FE;
    short* save_attr;
    int idle_time;
    int idle_interval;
    void* font;
    unsigned long font_color;
    unsigned long back_color;
};
#else
#include "../../include/tpnl_inv_context.h"
#endif

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
