// Attempt log for 0051D4F0 TRIBE_Panel_Pop::render_to_image_buffer
// baseline: typed TPanel-owned fields, TDrawArea calls, GDI calls, and natural
// pop text plus five DrawTextA passes. Frame and early setup match.
// ABI probe: inherited one-argument TPanel::get_string is the correct period
// source surface. It leaves all 23 calls aligned, but sprintf starts 4 bytes high.
// layout probe: PDB local declaration order did not move the string destination.
// liveness probe: direct pop/max members and no named copies were codegen-neutral.
// control-flow probe: reordered Used* tail stores improved resync only; restored.
// rectangle probe: width/height update spelling improved resync but grew the frame;
// restored the natural direct bounds form.
// liveness probe: using str as the old-font spill was an unsupported compiler hack;
// it changed the frame and was restored.
// BLOCKER: exact 668B remains blocked at the sprintf destination and downstream
// rectangle scheduling. Calls, ABI, pixel layout, cleanup, and frame are understood.

#include <stdio.h>
struct RECT { long left, top, right, bottom; };
class TDrawArea { public: char pad[0x38]; void* DrawDc; void PtrClear(RECT*, int); void* GetDc(char*); void SetClipRect(RECT*); void ReleaseDc(char*); };
class TPanel {
public:
    char gap_00[0x14];
    int width;
    int height;
    char gap_1c[0x70];
    int screen_left;
    int screen_top;
    char gap_94[0x60];
    char* get_string(int);
};
class TRIBE_Panel_Pop : public TPanel {
public:
    void* font; unsigned long color1; unsigned long color2; unsigned long color3; char pad104[0x0c]; int pop; int max_pop; unsigned char mode; char pad119[7]; void* image_clip_region; TDrawArea* ImageBuffer; RECT ImageRect; RECT UsedImageRect; RECT UsedScreenRect; int ImageTextActive;
    int render_to_image_buffer();
};
extern "C" int (__stdcall* const SelectClipRgn)(void*, void*);
extern "C" void* (__stdcall* const SelectObject)(void*, void*);
extern "C" int (__stdcall* const SetBkMode)(void*, int);
extern "C" unsigned long (__stdcall* const SetTextColor)(void*, unsigned long);
extern "C" int (__stdcall* const SetRect)(RECT*, int, int, int, int);
extern "C" int (__stdcall* const DrawTextA)(void*, char*, int, RECT*, unsigned int);
static char tag[] = "tpnl_tim::render_to_image_buffer";

int TRIBE_Panel_Pop::render_to_image_buffer()
{
    char str[256];
    void* old_font;
    RECT rect;
    if (this->ImageBuffer == 0) return 0;
    this->ImageBuffer->PtrClear(&this->ImageRect, 1);
    if (this->ImageBuffer->GetDc(tag) == 0) return 0;
    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(this->ImageBuffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->ImageBuffer->DrawDc, this->font);
    SetBkMode(this->ImageBuffer->DrawDc, 1);
    sprintf(str + 4, "%s%ld/%ld", this->TPanel::get_string(0x2b2a), this->pop, this->max_pop);
    SetTextColor(this->ImageBuffer->DrawDc, this->color2);
    int w = this->width;
    int h = this->height;
    SetRect(&rect, 0, 0, w - 3, h - 3); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 0, 2, w - 3, h - 1); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 2, 0, w - 1, h - 3); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetRect(&rect, 2, 2, w - 1, h - 1); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SetTextColor(this->ImageBuffer->DrawDc, this->mode == 1 ? this->color3 : this->color1);
    --h; --w;
    SetRect(&rect, 1, 1, w, h); DrawTextA(this->ImageBuffer->DrawDc, str + 4, -1, &rect, 0x21);
    SelectObject(this->ImageBuffer->DrawDc, old_font);
    SelectClipRgn(this->ImageBuffer->DrawDc, 0);
    this->ImageBuffer->ReleaseDc(tag);
    int right = this->width - 1;
    int bottom = this->height - 1;
    this->UsedImageRect.left = 0; this->UsedImageRect.top = 0;
    this->UsedScreenRect.left = this->screen_left; this->UsedScreenRect.top = this->screen_top;
    this->UsedImageRect.right = right; this->UsedImageRect.bottom = bottom;
    this->UsedScreenRect.right = this->screen_left + right;
    this->UsedScreenRect.bottom = this->screen_top + bottom;
    this->ImageTextActive = 1;
    return 1;
}
