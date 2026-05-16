// Attempt log for 0051D4F0 TRIBE_Panel_Pop::render_to_image_buffer
// try 1: natural reconstruction from packet/decompiler; exact size but offsets 4 low and get_string/sprintf argument scheduling wrong.
// try 2: add missing pad before image_clip/ImageBuffer and split get_string local; offsets fixed to 0x124, first mismatch at pop/max/color field layout.
// try 3: correct font/color/pop/max/mode offsets and color usage; first mismatch at get_string/sprintf cleanup/scheduling.
// try 4: declare get_string as __cdecl; worse (push this/add esp 10), rolled back.
// try 5: restore thiscall get_string and inline expression variant; better edit diff but duplicates pop/max pushes before get_string.
// try 6: use local pop/max variables before sprintf/get_string; tiny edit improvement, still duplicate args.
// try 7: declare get_string varargs; worse, rolled back.
// try 8: restore fixed-arity get_string best.
// try 9: /Oy- flag probe; worse from offset 0, rolled back.
// try 10: /O1 flag probe; too small 638B, rolled back.
// BLOCKER: exact 668B, prologue/early image-buffer setup matches through SetBkMode, but get_string/sprintf vararg scheduling diverges at offset 161: original reuses pending pop/max/id pushes across get_string/sprintf cleanup, while rebuilt either duplicates/reloads args or uses wrong cdecl shape. Downstream rect drawing scheduling also drifts. Not accepted_drift-safe.

#include <stdio.h>
struct RECT { long left, top, right, bottom; };
class TDrawArea { public: char pad[0x38]; void* DrawDc; void PtrClear(RECT*, int); void* GetDc(char*); void SetClipRect(RECT*); void ReleaseDc(char*); };
class TRIBE_Panel_Pop {
public:
    char pad0[0x14]; int width; int height; char pad1c[0x70]; int screen_left; int screen_top; char pad94[0x60]; void* font; unsigned long color1; unsigned long color2; unsigned long color3; char pad104[0x0c]; int pop; int max_pop; unsigned char mode; char pad119[7]; void* image_clip_region; TDrawArea* ImageBuffer; RECT ImageRect; RECT UsedImageRect; RECT UsedScreenRect; int ImageTextActive;
    char* get_string(int, int, int);    int render_to_image_buffer();
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
    RECT rect;
    void* old_font;
    char str[256];
    if (this->ImageBuffer == 0) return 0;
    this->ImageBuffer->PtrClear(&this->ImageRect, 1);
    if (this->ImageBuffer->GetDc(tag) == 0) return 0;
    this->ImageBuffer->SetClipRect(&this->ImageRect);
    SelectClipRgn(this->ImageBuffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->ImageBuffer->DrawDc, this->font);
    SetBkMode(this->ImageBuffer->DrawDc, 1);
    int pop = this->pop;
    int max_pop = this->max_pop;
    sprintf(str + 4, "%s%ld/%ld", this->get_string(0x2b2a, pop, max_pop), pop, max_pop);
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
