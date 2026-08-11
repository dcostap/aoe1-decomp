// 0048A740 RGE_Panel_Time::draw (805 bytes, rpnl_tim.cpp lines 47-138)
//
// Attempt log:
// Prior scratch probes established the typed panel offsets and the three inline
// strlen paths; gap-based layouts and manual strlen loops were inferior.
// This pass restored the period helper ABI (int get_paused, long countdown
// reference, and TPanel-owned get_string), and changed the player loop to the
// binary-proven guarded do/while form.
// GetDc is a status guard; all GDI calls use the named TDrawArea::DrawDc member,
// matching the repeated +0x38 reloads.  Inlining get_string in sprintf restores
// the observed countdown push before the member call.
// The final source uses inherited draw_setup(0)/draw_finish() calls and the
// canonical TPanel/RGE_Panel_Time ownership surface.  Unused vtable scaffolding
// was removed after it proved codegen-neutral.
// Exact under config/flags/default.rsp: 805/805 bytes, 0.0000% diff.

#include "..\..\include\game_globals.h"
#include <windows.h>
#include <stdio.h>
#include <string.h>

extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(HDC, HRGN);
extern "C" __declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
extern "C" __declspec(dllimport) COLORREF __stdcall SetBkColor(HDC, COLORREF);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(HDC, int);
extern "C" __declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
extern "C" __declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
extern "C" __declspec(dllimport) UINT __stdcall GetPaletteEntries(HPALETTE, UINT, UINT, LPPALETTEENTRY);

class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    char _gap_00[0x38];
    HDC DrawDc;
    void* GetDc(const char* name);
    void ReleaseDc(const char* name);
};

class RGE_Game_World {
public:
    char _gap_00[0x18];
    float game_speed;
    char _gap_1C[0x20];
    short player_num;
    char _pad_3E[2];
    void** players;
};

class RGE_Base_Game {
public:
    char _gap_00[0x48];
    void* draw_system;
    char _gap_4C[0x170];
    int paused;
    char _gap_1C0[0x234];
    RGE_Game_World* world;
    int get_paused();
    void get_countdown_timer(long player_index, long& result);
};

class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void draw_setup(int value);
    virtual void draw_finish();
    virtual void draw();

    char _gap_04[0x1C];
    TDrawArea* render_area;
    char _gap24[0x48];
    int active;
    int visible;
    char _gap74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap9C[0x44];
    int display_changed_count;
    char _gapE4[0x10];
    char* get_string(int id);
};

class RGE_Panel_Time : public TPanel {
public:
    void* font;
    long game_time;
    long last_game_time;
    long old_time;
    long real_time;

    virtual void draw();
    virtual long handle_idle();
};

void RGE_Panel_Time::draw()
{
    if (this->render_area == 0 || this->visible == 0 || this->active == 0)
        return;

    this->draw_setup(0);

    this->display_changed_count++;

    HGDIOBJ old_font;
    if (this->render_area->GetDc("rpnl_tim::draw") != 0) {
        SelectClipRgn(this->render_area->DrawDc, (HRGN)this->clip_rgn);
        old_font = SelectObject(this->render_area->DrawDc, (HGDIOBJ)this->font);

        if (rge_base_game->get_paused()) {
            SetBkColor(this->render_area->DrawDc, 0xFFFFFF);
            SetBkMode(this->render_area->DrawDc, 2);
            SetTextColor(this->render_area->DrawDc, 0xFF);
            {
                char str[100];
                sprintf(str, "Paused");
                TextOutA(this->render_area->DrawDc, this->render_rect.left,
                         this->render_rect.top - 2, str, strlen(str));
            }
        } else {
            SetBkMode(this->render_area->DrawDc, 1);
            SetTextColor(this->render_area->DrawDc, 0xFFFFFF);

            int t = this->game_time;
            int m = 0;
            int h = 0;

            if (t > 59) {
                m = t / 60;
                t = t - m * 60;
                if (m > 59) {
                    h = m / 60;
                    m = m - h * 60;
                }
            }

            {
                char str[100];
                sprintf(str, "%02ld:%02ld:%02ld (%3.1f)", h, m, t,
                        (double)rge_base_game->world->game_speed);
                TextOutA(this->render_area->DrawDc, this->render_rect.left,
                         this->render_rect.top - 2, str, strlen(str));
            }

            int pi = 1;
            int pc = rge_base_game->world->player_num;

            if (pc > 1) {
                int yo = 13;

                do {
                    long ct;
                    rge_base_game->get_countdown_timer(pi, ct);

                    if (ct >= 0) {
                        PALETTEENTRY pe;
                        void* ct2 = *(void**)((char*)rge_base_game->world->players[pi] + 0x108);
                        unsigned char mc = *(unsigned char*)((char*)ct2 + 0x25);
                        HPALETTE hp = *(HPALETTE*)((char*)rge_base_game->draw_system + 8);

                        GetPaletteEntries(hp, mc, 1, &pe);

                        COLORREF c = (((pe.peBlue & 0xFF) << 8 | (pe.peGreen & 0xFF)) << 8 |
                                       (pe.peRed & 0xFF));

                        SetTextColor(this->render_area->DrawDc, c);

                        {
                            char str[100];
                            sprintf(str, this->get_string(0x2C24), ct);
                            TextOutA(this->render_area->DrawDc, this->render_rect.left,
                                     yo + this->render_rect.top, str, strlen(str));
                        }
                        yo += 13;
                    }
                    pi++;
                } while (pi < pc);
            }
        }

        SelectObject(this->render_area->DrawDc, old_font);
        SelectClipRgn(this->render_area->DrawDc, 0);
        this->render_area->ReleaseDc("rpnl_tim::draw");
    }

    this->draw_finish();
}
