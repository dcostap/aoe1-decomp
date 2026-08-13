// 0051D060 TRIBE_Panel_Pop::draw
// tpnl_pop.cpp
//
// Attempt log:
// try 1: broad reconstruction from packet: guard surfaces, animation-state update, optional backing panel draw, text/rect drawing and restore.
// try 2: modeled early guards for screen(+0x20), palette(+0x70), surface(+0x6C), frame increment, and virtual draw/postDraw calls.
// try 3: modeled current-player lookup through global panel manager and cached object at +0x10C.
// try 4: modeled animMode +0x118 transition from player/font metric table and animTime +0x11C accumulation/reset cycle.
// try 5: modeled coordinate calculation via camera floats at +0x50/+0x2C/+0x10/+0x80 using roundFloat.
// try 6: modeled redraw/rebuild path controlled by image +0x124, changed flag, needsRedraw +0xF3, lastX +0x110, lastY +0x114.
// try 7: modeled overlay/image fast path with lock/draw/unlock and early virtual postDraw.
// try 8: modeled main drawing setup: lock, SelectObject, SetTextColor, SetBkMode, sprintf label from coord helper.
// try 9: modeled border text as repeated SetRect + DrawTextA around panel bounds (+8C/+90/+18/+14), then foreground text and GDI restore.
// try 10: default compile produced .text 928B vs original 1033B, no full diff.
// try 11: /GX probe produced identical 928B, removed flag file.
// try 12: restored the same-TU TPanel/TRIBE_Panel_Pop layout and real DrawArea/GDI/member-call surfaces from exact tpnl_pop donors; replaced fake lock/roundFloat helpers with draw_begin, get_player, __ftol, SetTrans/Copy, GetDc/ReleaseDc, and imported GDI calls.
// try 13: changed the byte-mode gate from != 0 to > 0; test/jbe now matches the oracle, with no other structural movement.
// try 14: tested function-scope rect bounds, height/width declaration order, and in-place right/bottom updates; VC5 stayed in the same LEA family (the oracle uses sub/sub/add/add).
// try 15: tested foreground color-area assignment/declaration order and a 25-variant focused rect/color lab; no exact variant, with all size/frame/call-set gates stable.
// try 16: modeled the canonical same-TU TPanel render bounds as one RECT; VC5 emitted identical code, so the typed aggregate is retained.
// try 17: reused adjusted width/height as right/bottom, following the original EBX/EAX sub/sub/add/add block and the decompiler's lack of named right/bottom locals; emitted duplicate bytes, so restored.
// try 18: spelled width/height decrements as explicit assignments to test compound-assignment lowering; emitted duplicate bytes, so restored.
// final validated scratch state: typed structural reconstruction is retained; only the localized VC5 rectangle scheduling/register family remains nonexact.

#include <windows.h>
#include <stdio.h>

class RGE_Game_World {
public:
    char gap_000[0x84];
    float world_time_delta_seconds;
};

class RGE_Player {
public:
    char gap_000[0x3C];
    RGE_Game_World* world;
    char gap_040[0x0A];
    short player_id;
    char gap_04C[4];
    float* attributes;
};

class RGE_Base_Game {
public:
    char gap_000[0x3F4];
    RGE_Game_World* world;
    char gap_3F8[0x63C];
    int mode_counts[0x100];

    RGE_Player* get_player();
};

extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    char gap_000[0x38];
    HDC DrawDc;

    void* GetDc(char* name);
    void ReleaseDc(char* name);
    void SetTrans(int enabled, unsigned char color);
    void Copy(TDrawArea* area, long x, long y, RECT* rect, int mode);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual long set_redraw(int);
    virtual long handle_idle();
    virtual void draw_begin(int);
    virtual void finish_up();

    char gap_004[0x08];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_01C[4];
    TDrawArea* render_area;
    char gap_024[0x48];
    int field_06C;
    int field_070;
    char gap_074[0x14];
    HRGN clip_rgn;
    RECT render_rect;
    char gap_09C[0x44];
    long draw_depth;
    char gap_0E4[0x0F];
    unsigned char field_0F3;

    char* get_string(int string_id);
};

class TRIBE_Panel_Pop : public TPanel {
public:
    void* font;
    unsigned long color1;
    unsigned long color2;
    unsigned long color3;
    int player_id;
    RGE_Game_World* world;
    RGE_Player* player;
    int pop;
    int max_pop;
    unsigned char mode;
    unsigned char gap_119[3];
    float timer;
    HRGN image_clip_region;
    TDrawArea* ImageBuffer;
    RECT ImageRect;
    RECT UsedImageRect;
    RECT UsedScreenRect;
    int ImageTextActive;
    long LastIBWidth;
    long LastIBHeight;

    int render_to_image_buffer();
    virtual void draw();
};

void TRIBE_Panel_Pop::draw()
{
    char str[256];
    HGDIOBJ old_font;
    RECT rect;
    unsigned char changed_mode;
    long right;
    long bottom;

    if (this->render_area == 0)
        return;
    if (this->field_070 == 0)
        return;
    if (this->field_06C == 0)
        return;

    this->draw_depth++;
    this->draw_begin(0);

    RGE_Player* player = rge_base_game->get_player();
    this->player = player;
    changed_mode = 0;

    if (this->mode == 0) {
        if (rge_base_game->mode_counts[player->player_id] > 0) {
            this->mode = 1;
            this->timer = 0.0f;
            changed_mode = 1;
        }
    }

    if (this->mode > 0) {
        this->timer += player->world->world_time_delta_seconds;
        if (this->timer > 1.0f) {
            changed_mode = 1;
            this->timer = 0.0f;
            if (++this->mode > 2)
                this->mode = 0;
        }
    }

    {
        int pop = (int)player->attributes[0x2C / 4];
        int max_pop = pop + (int)player->attributes[0x10 / 4];
        int max_available = (int)player->attributes[0x80 / 4];
        if (max_pop > max_available)
            max_pop = max_available;

        if (this->ImageBuffer != 0 &&
            (changed_mode != 0 || this->field_0F3 != 0 ||
             this->pop != pop || this->max_pop != max_pop)) {
            this->pop = pop;
            this->max_pop = max_pop;
            this->render_to_image_buffer();
            if (this->field_0F3 != 0) {
                this->field_0F3 = 0;
                goto finish;
            }
        }
    }

    if (this->ImageTextActive != 0 && this->ImageBuffer != 0) {
        this->ImageBuffer->SetTrans(1, 1);
        this->ImageBuffer->Copy(this->render_area,
                                this->UsedScreenRect.left,
                                this->UsedScreenRect.top,
                                &this->UsedImageRect, 1);
        this->ImageBuffer->SetTrans(0, 1);
        goto finish;
    }

    if (this->render_area->GetDc((char*)"tpnl_tim::draw") != 0) {
        SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
        old_font = SelectObject(this->render_area->DrawDc, (HGDIOBJ)this->font);
        SetBkMode(this->render_area->DrawDc, 1);
        sprintf(str, "%s%ld/%ld", this->get_string(0x2B2A),
                this->pop, this->max_pop);

        SetTextColor(this->render_area->DrawDc, this->color2);

        long left = this->render_rect.left;
        long top = this->render_rect.top;
        long width = this->pnl_wid;
        long height = this->pnl_hgt;
        ++left;
        ++top;
        width -= 2;
        height -= 2;
        right = width + left;
        bottom = height + top;

        SetRect(&rect, left - 1, top - 1, right - 2, bottom - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left - 1, top + 1, right - 2, bottom);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left + 1, top - 1, right, bottom - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);
        SetRect(&rect, left + 1, top + 1, right, bottom);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);

        unsigned long color;
        TDrawArea* color_area;
        if (this->mode == 1) {
            color = this->color3;
            color_area = this->ImageBuffer;
        } else {
            color = this->color1;
            color_area = this->render_area;
        }
        SetTextColor(color_area->DrawDc, color);

        SetRect(&rect, left, top, right - 1, bottom - 1);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, 0x21);

        SelectObject(this->render_area->DrawDc, old_font);
        SelectClipRgn(this->render_area->DrawDc, 0);
        this->render_area->ReleaseDc((char*)"tpnl_tim::draw");
    }

finish:
    this->finish_up();
}
