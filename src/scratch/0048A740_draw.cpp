// 0048A740 RGE_Panel_Time::draw (805 bytes, rpnl_tim.cpp lines 47-138)
//
// Attempt log:
// Probe 1-5: see previous scratch (gap-based layouts, manual strlen loops)
// Probe 6-8: various experiments (my_strlen, member fcn ptrs)
// Probe 9-10: class layouts from inventory type dumps, correct TPanel offsets
// Probe 11: strlen() from <string.h> for inline repne scasb (3 of 3 match)
// Probe 12: void* vt local for vtable persistence (edi holds vtable, old_font in ebx reg)
//
// Status: Layout correct, 3x inline strlen, vtable saved in register.
// Remaining ~37 bytes: register alloc (edi vs ebx for vtable), stack frame (0x80 vs 0x7C),
// old_font in register vs stack. Variant_lab candidate for register/scheduling tune.
// Leaving in scratch.

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
    bool get_paused();
    void get_countdown_timer(int player_index, long* result);
};

class RGE_Panel_Time {
public:
    int field_04;
    int field_08;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
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
    void* font;
    long game_time;
    long last_game_time;
    long old_time;
    long real_time;

    virtual void draw();
    virtual long handle_idle();
    char* get_string(int id);
};

void RGE_Panel_Time::draw()
{
    if (this->render_area == 0 || this->visible == 0 || this->active == 0)
        return;

    void* vt = *(void**)this;
    ((void (__stdcall *)(int))(((void**)vt)[10]))(0);

    this->display_changed_count++;

    HDC dc = (HDC)this->render_area->GetDc("rpnl_tim::draw");

    HGDIOBJ old_font;
    if (dc != 0) {
        SelectClipRgn(dc, (HRGN)this->clip_rgn);
        old_font = SelectObject(dc, (HGDIOBJ)this->font);

        if (rge_base_game->get_paused()) {
            SetBkColor(dc, 0xFFFFFF);
            SetBkMode(dc, 2);
            SetTextColor(dc, 0xFF);
            {
                char str[100];
                sprintf(str, "Paused");
                TextOutA(dc, this->render_rect.left, this->render_rect.top - 2, str, strlen(str));
            }
        } else {
            SetBkMode(dc, 1);
            SetTextColor(dc, 0xFFFFFF);

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
                TextOutA(dc, this->render_rect.left, this->render_rect.top - 2, str, strlen(str));
            }

            int pi = 1;
            int pc = rge_base_game->world->player_num;

            if (pc > 1) {
                int yo = 13;

                while (pi < pc) {
                    long ct;
                    rge_base_game->get_countdown_timer(pi, &ct);

                    if (ct >= 0) {
                        PALETTEENTRY pe;
                        void* ct2 = *(void**)((char*)rge_base_game->world->players[pi] + 0x108);
                        unsigned char mc = *(unsigned char*)((char*)ct2 + 0x25);
                        HPALETTE hp = *(HPALETTE*)((char*)rge_base_game->draw_system + 8);

                        GetPaletteEntries(hp, mc, 1, &pe);

                        COLORREF c = (((pe.peBlue & 0xFF) << 8 | (pe.peGreen & 0xFF)) << 8 |
                                       (pe.peRed & 0xFF));

                        SetTextColor(dc, c);

                        char* ys = this->get_string(0x2C24);
                        {
                            char str[100];
                            sprintf(str, ys, ct);
                            TextOutA(dc, this->render_rect.left, yo + this->render_rect.top, str, strlen(str));
                        }
                        yo += 13;
                    }
                    pi++;
                }
            }
        }

        SelectObject(dc, old_font);
        SelectClipRgn(dc, 0);
        this->render_area->ReleaseDc("rpnl_tim::draw");
    }

    ((void (__stdcall *)())((void**)vt)[11])();
}
