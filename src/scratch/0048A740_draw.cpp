// 0048A740 RGE_Panel_Time::draw
// Source: rpnl_tim.cpp lines 47-138
//
// Attempt log:
// Probe 1-5: see previous. Probe 5 matched first 12 bytes (prologue).
// Probe 6: my_strlen static function (bad, separate .text section)
// Probe 7: member function pointers (compile error)
// Probe 8: back to probe 5 baseline — remove old_font=0 init, inline strlen via for loop

#include "..\..\include\game_globals.h"
#include <windows.h>
#include <stdio.h>

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
    char _gap_00[0x3F4];
    RGE_Game_World* world;
    char _gap_3F8[0x50];
    void* draw_system;
    bool get_paused();
    void get_countdown_timer(int player_index, long* result);
};

class RGE_Panel_Time {
    char _gap_04[0x1C];
public:
    TDrawArea* render_area;
private:
    char _gap_24[0x48];
public:
    int active;
    int visible;
private:
    char _gap_74[0x14];
public:
    void* clip_rgn;
    RECT render_rect;
private:
    char _gap_9C[0x44];
public:
    int display_changed_count;
private:
    char _gap_E4[0x10];
public:
    void* font;
    long game_time;
    long last_game_time;
    long old_time;
    long real_time;

    virtual void draw();
    virtual long handle_idle();
    char* get_string(int id);
};

typedef void (__stdcall *VFunc10)(int);
typedef void (__stdcall *VFunc11)();

void RGE_Panel_Time::draw()
{
    if (this->render_area == 0 || this->visible == 0 || this->active == 0)
        return;

    ((VFunc10)((*(void***)this)[10]))(0);

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
                int sl = 0;
                while (str[sl]) sl++;
                TextOutA(dc, this->render_rect.left, this->render_rect.top - 2, str, sl);
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
                int sl = 0;
                while (str[sl]) sl++;
                TextOutA(dc, this->render_rect.left, this->render_rect.top - 2, str, sl);
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
                            int sl = 0;
                            while (str[sl]) sl++;
                            TextOutA(dc, this->render_rect.left, yo + this->render_rect.top, str, sl);
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

    ((VFunc11)((*(void***)this)[11]))();
}
