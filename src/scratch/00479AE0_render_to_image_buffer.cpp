// Attempt log:
// baseline: natural render path with local typed Win32 and draw-area stubs; frame 0x44, diff 1552.
// layout: restored TPanel ownership for width, height, and draw origin; frame 0x48, diff 1526.
// control-flow: used panel dimensions and original justification enum values; frame 0x40, diff 1506.
// liveness: retained ImageRect and text pointers and corrected RGB local order; best diff 1361.
// current claim: moving text/ImageRect declarations and testing direct text forms did not improve codegen.
// current claim: pointer-walk length form reaches exact size and 78.24% shape, but positional diff is 1443.
// current claim: explicit first-byte local and CRT strlen return to diff 1452; rolled back.
// restored best: typed source with text pointer after PtrClear and natural index scan, diff 1361.
// remaining drift: target keeps text in EDI and ImageRect in EBX before the empty-text gate; source keeps ImageRect in EDI.
// r2 liveness: reusing text for all DrawTextA calls, function-scope local order, const text, and direct empty-byte test were codegen duplicates.
// r2 behavior: spelling UsedImageRect clipping as value > ImageRect moved the compare blocks; diff 1361 -> 1358.
// r2 ABI: SetRect as a proven dllimport produced exact size and 37.15% exact blocks; kept. Full Win32 import surfaces changed the frame or worsened layout.
// r2 ABI: GetTextExtentPoint32A and SetTextColor imports were neutral; GetPaletteEntries and DrawTextA imports worsened the basin and were rolled back.
// remaining drift: structural first hunk is still the early text/ImageRect register assignment; ordered calls remain 31/31.
// r3 control-flow: inverted the index-color branch so the palette path stays inline; diff 1340 -> 1320.
// r3 layout: direct typed ImageRect member uses improved the best diff to 1260; pointer and reference aliases were rolled back.
// r3 liveness: direct this->text for extent and DrawTextA, non-const scan text, and local declaration changes were neutral.
// r3 ABI: extern-C const GetPaletteEntries pointer was neutral; dllimport forms worsened the early frame basin.
// r3 final: PDB-ordered dimension assignments were neutral; remaining structural gap is target EBX ImageRect and EDI scan-text carriers.
// r4 ABI: added the shared typed rge_base_game pointer declaration/definition with its proven 0062C574 seed; target codegen is unchanged at diff 1260.
// r4 audit: use the shared typed fixed-storage accessor for the two palette reads; it emits [62C574] loads without a raw macro, but its natural source shape is farther from the current VC5 basin.
// r5 layout: restored a named ImageRect pointer before PtrClear; the fixed-storage source reaches diff 1426 but still colors it EDI.
// r5 liveness: text gate, declaration order, explicit first-element address, array reference, and full text-local call lifetime were neutral.
// r5 behavior: CRT strlen enlarged the frame to 0x44; restored the indexed scan. Pointer-walk subtraction worsened diff to 1514.
// r5 final: clean source keeps named ImageRect pointer and text view with direct typed storage access; +0031 remains a register-coloring gap.
// r6 liveness: using the named text view for the empty gate was codegen-neutral.
// r6 layout: direct ImageRect.top matched the target's direct load but worsened strict diff to 1461; restored pointer ownership.
// r6 liveness: making text function-scope live across PtrClear was neutral.
// r6 behavior: combining that lifetime with strlen enlarged the frame to 0x44 and worsened diff to 1551; restored clean source.
// r7 probes: 22 meaningful source, type, layout, ABI, and context hypotheses were checked in this claim.
// r7 strlen: explicit cdecl strlen forms emit target-like repne scasb, but add a 0x44 frame and worsen positional drift; restored.
// r7 layout: target icon blocks read TShape::shape_info at +0x1C. The gap before shape_info is retained from this binary evidence.
// r7 layout checkpoint: the +0x1C TShape correction makes two late icon blocks exact and raises exact-block coverage to 49.16%; full diff remains 1431.
// r7 unresolved: target keeps ImageRect in EBX and text in EDI before the empty-text gate; current natural source keeps ImageRect in EDI.
// r8 liveness: direct ImageRect.top plus a pointer-increment text walk restored the target EBX/EDI early carriers; H29 reached diff 1294, shape 82.40%, and exact blocks 50.66%, with a 6-byte overflow.
// r8 ABI: the period GetPaletteEntries dllimport form kept the 0x40 frame and reduced H47 to diff 1303 with exact size and 31/31 ordered calls.
// r8 rejected: naming the palette handle reached diff 1122 and exact size, but the target reloads the global palette at both calls while that alias loads it once; do not retain this metric-only form.
// r8 final: direct global palette calls, direct ImageRect.top, and the pointer-increment text walk are the reduced natural source. First divergence is the GetPaletteEntries setup at +00EC; target LEA p precedes its cached IAT load.
#include <string.h>
#ifndef AOE1_PNL_MSG_CONTEXT_H
#include "..\..\include\rge_base_game_global.h"

struct tagRECT { long left; long top; long right; long bottom; };
struct tagSIZE { long cx; long cy; };
struct tagPALETTEENTRY { unsigned char peRed, peGreen, peBlue, peFlags; };

extern int (__stdcall *SelectClipRgn)(void*, void*);
extern void* (__stdcall *SelectObject)(void*, void*);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(void*, unsigned int, unsigned int, tagPALETTEENTRY*);
extern unsigned int (__stdcall *SetBkColor)(void*, unsigned int);
extern int (__stdcall *SetBkMode)(void*, int);
extern "C" __declspec(dllimport) int __stdcall GetTextExtentPoint32A(void*, const char*, int, tagSIZE*);
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT*, int, int, int, int);
extern "C" __declspec(dllimport) unsigned int __stdcall SetTextColor(void*, unsigned int);
extern int (__stdcall *DrawTextA)(void*, const char*, int, tagRECT*, unsigned int);

struct DrawSystem { char gap_00[8]; void* Pal; };
class RGE_Base_Game {
public:
    char gap_00[0x48];
    DrawSystem* draw_system;
};

struct Shape_Info {
    char gap_00[0x10];
    long Width;
    char gap_14[4];
    long Hotspot_X;
    long Hotspot_Y;
};

class TShape;

class TDrawArea {
public:
    char gap_00[0x38];
    void* DrawDc;

    void PtrClear(tagRECT* rect, int mode);
    void SetClipRect(tagRECT* rect);
    void* GetDc(char* tag);
    void ReleaseDc(char* tag);
};

class TPanel {
public:
    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void pv5(int);
    virtual void pv6();
    virtual void pv7();
    virtual void pv8(int);

    char gap_04[0x10];
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[4];
    TDrawArea* render_area;
    char gap_24[0x68];
    tagRECT render_rect;
    char gap_94[0x5F];
    unsigned char need_restore;
};

class TShape {
public:
    char gap_00[0x1C];
    Shape_Info* shape_info;
    void shape_draw(TDrawArea* draw_area, long x, long y, long frame, unsigned char transparent, unsigned char* remap);
};

class TMessagePanel : public TPanel {
public:
    int message_type;
    char text[0x200];
    int showing_message;
    int start_time;
    int show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    char gap_312[2];
    int index_color;
    unsigned long font_color1;
    unsigned long font_color2;
    int horz_just;
    int vert_just;
    int word_wrap;
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int LastIBWidth;
    int LastIBHeight;
    int ImageTextActive;
    TShape* Icon1;
    TShape* Icon2;
    int IconFrame1;
    int IconFrame2;

    int render_to_image_buffer();
};
#endif

int TMessagePanel::render_to_image_buffer() {
    tagRECT* image_rect;
    void* dc;
    void* old_font;
    tagPALETTEENTRY p;
    unsigned long font_rgb;
    unsigned long back_rgb;
    long x;
    long display_hgt;
    long y;
    long wid;
    long hgt;
    tagSIZE ts;
    int len;
    tagRECT rect;
    unsigned int flags;
    long used_x;
    long used_y;
    long used_w;
    int tight;

    if (this->ImageBuffer == 0) {
        return 0;
    }

    image_rect = &this->ImageRect;
    this->ImageBuffer->PtrClear(image_rect, 1);
    char* text = this->text;
    if (this->text[0] == 0) {
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        SetRect(&this->UsedScreenRect, this->render_rect.left, this->render_rect.top,
                this->render_rect.left + 1, this->render_rect.top + 1);
        this->ImageTextActive = 1;
        return 1;
    }

    dc = this->ImageBuffer->GetDc("pnl_msg::render_to_image_buffer");
    if (dc == 0) {
        return 0;
    }

    this->ImageBuffer->SetClipRect(image_rect);
    SelectClipRgn(this->ImageBuffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->ImageBuffer->DrawDc, this->font);

    if (this->index_color != 0) {
        GetPaletteEntries(rge_base_game_at_storage()->draw_system->Pal, this->font_color, 1, &p);
        font_rgb = ((unsigned long)p.peBlue << 16) | ((unsigned long)p.peGreen << 8) | p.peRed;
        GetPaletteEntries(rge_base_game_at_storage()->draw_system->Pal, this->back_color, 1, &p);
        back_rgb = ((unsigned long)p.peBlue << 16) | ((unsigned long)p.peGreen << 8) | p.peRed;
    } else {
        back_rgb = this->font_color2;
        font_rgb = this->font_color1;
    }

    if (this->message_type == 2) {
        SetBkColor(this->ImageBuffer->DrawDc, 0);
        SetBkMode(this->ImageBuffer->DrawDc, 2);
    } else {
        SetBkMode(this->ImageBuffer->DrawDc, 1);
    }

    wid = this->pnl_wid - 2;
    x = image_rect->left;
    hgt = this->pnl_hgt - 2;
    y = this->ImageRect.top;

    while (*text != 0) {
        ++text;
    }
    len = (int)(text - this->text);
    int ok = GetTextExtentPoint32A(this->ImageBuffer->DrawDc, this->text, len, &ts);

    if (ok == 0) {
        SetRect(&rect, x, y, x + wid - 2, y + hgt - 2);
        SetRect(&this->UsedImageRect, 0, 0, 1, 1);
        this->ImageTextActive = 0;
    } else {
        used_x = 0;
        used_y = 0;
        display_hgt = ts.cy + 2;
        used_w = ts.cx + 2;
        int message_type = this->message_type;
        tight = 1;

        if (message_type == 1) {
            flags = 0x21;
            used_x = ((this->pnl_wid - used_w) >> 1) - 1;
        } else if (message_type == 5) {
            flags = 0x22;
            used_x = (this->pnl_wid - used_w) - 1;
            used_y = 0;
        } else {
            if (this->word_wrap == 0 || ts.cx <= wid) {
                used_w = ts.cx + 1;
                display_hgt = ts.cy + 1;
                flags = 0x20;
                tight = 1;
            } else {
                used_w = this->pnl_wid;
                display_hgt = this->pnl_hgt;
                flags = 0x10;
                tight = 0;
            }
            used_x = 0;
            used_y = 0;
            if (this->horz_just == 4) {
                flags |= 1;
                if (tight) used_x = ((this->pnl_wid - used_w) >> 1) - 1;
            } else if (this->horz_just == 3) {
                flags |= 2;
                if (tight) used_x = (this->pnl_wid - used_w) - 1;
            } else if (tight) {
                used_x = 0;
            }
            if (this->vert_just == 4) {
                flags |= 4;
                if (tight) used_y = ((this->pnl_hgt - display_hgt) >> 1) - 1;
            } else if (this->vert_just == 1) {
                flags |= 8;
                if (tight) used_y = (this->pnl_hgt - display_hgt) - 1;
            } else if (tight) {
                used_y = 0;
            }
        }

        if (used_y < 0) used_y = 0;
        if (used_x < 0) used_x = 0;

        this->UsedImageRect.left = used_x;
        this->UsedImageRect.top = used_y;
        this->UsedImageRect.right = used_x + used_w;
        this->UsedImageRect.bottom = used_y + display_hgt;
        if (this->UsedImageRect.right > this->ImageRect.right) this->UsedImageRect.right = this->ImageRect.right;
        if (this->UsedImageRect.bottom > this->ImageRect.bottom) this->UsedImageRect.bottom = this->ImageRect.bottom;

        SetTextColor(this->ImageBuffer->DrawDc, back_rgb);
        SetRect(&rect, x, y, x + wid - 1, y + hgt - 1);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x, y + 2, x + wid - 1, y + hgt + 1);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x + 2, y, x + wid + 1, y + hgt - 1);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetRect(&rect, x + 2, y + 2, x + wid + 1, y + hgt + 1);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);
        SetTextColor(this->ImageBuffer->DrawDc, font_rgb);
        SetRect(&rect, x + 1, y + 1, x + wid, y + hgt);
        DrawTextA(this->ImageBuffer->DrawDc, this->text, -1, &rect, flags);

        if (this->Icon1 != 0) {
            Shape_Info* info = this->Icon1->shape_info;
            long frame = this->IconFrame1;
            long width = info[frame].Width;
            this->Icon1->shape_draw(this->ImageBuffer, info[frame].Hotspot_X - width - 4 + this->UsedImageRect.left,
                                    info[frame].Hotspot_Y + 6 + this->UsedImageRect.top, frame, 0, 0);
            this->UsedImageRect.left += -4 - width;
        }
        if (this->Icon2 != 0) {
            Shape_Info* info = this->Icon2->shape_info;
            long frame = this->IconFrame2;
            long width = info[frame].Width;
            this->Icon2->shape_draw(this->ImageBuffer, info[frame].Hotspot_X - width - 4 + this->UsedImageRect.left,
                                    info[frame].Hotspot_Y + 6 + this->UsedImageRect.top, frame, 0, 0);
            this->UsedImageRect.left += -4 - width;
        }
        this->ImageTextActive = 1;
    }

    SelectObject(this->ImageBuffer->DrawDc, old_font);
    SelectClipRgn(this->ImageBuffer->DrawDc, 0);
    this->ImageBuffer->ReleaseDc("pnl_msg::render_to_image_buffer");

    this->UsedScreenRect.left = this->UsedImageRect.left + this->render_rect.left;
    this->UsedScreenRect.top = this->UsedImageRect.top + this->render_rect.top;
    this->UsedScreenRect.right = this->UsedImageRect.right + this->render_rect.left;
    this->UsedScreenRect.bottom = this->UsedImageRect.bottom + this->render_rect.top;
    return this->ImageTextActive;
}
