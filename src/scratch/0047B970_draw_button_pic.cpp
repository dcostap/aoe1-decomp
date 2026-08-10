// 0047B970 TScrollBarPanel::draw_button_pic
// PDB: Pnl_scbr.cpp:805-836, 245 bytes
// void __thiscall draw_button_pic(int param_1, int param_2, tagRECT* param_3)
// ret 0Ch (3 params)
// Attempt log:
// 1: baseline used separate fallback returns, a decompiler-shaped parameter
//    alias, and a seven-argument shape_draw declaration; it emitted two panel
//    fallback calls and one extra shape_draw push.
// 2: restored the combined button-pic/frame guard, the period TPanel virtual
//    draw_rect surface, the natural x_min local, and the six-argument shape ABI.
// 3-4: split/rewrote the centered-x arithmetic using the Ghidra-supported
//    x_min + (1 - y_max) form; both emitted the same 245-byte basin.
// 5: focused six-way x-expression variant lab; every natural spelling stayed
//    in the same 9-byte-diff group, so no variant replaced the clean source.
// 6-9: restored the full TPanel/TScrollBarPanel layout and tested local
//    declaration/scope and explicit-cast sequencing; all were codegen duplicates.
// Final: size/frame/ordered calls/CFG and 240/245 bytes match. Remaining drift
//    is one scheduling swap at 0047B9EC: original `sub ecx,edi` then
//    `add cx,[esi]`, rebuilt in the opposite order. No behavior or ABI gap found.
// - Main-agent audit named the canonical TPanel destructor slot; emitted code
//   and the localized nine-byte drift are unchanged.
// New worker probe: combined the final x subtract/add expression; VC5 emitted the same 245B/9-byte basin.
// Binary/Ghidra evidence shows the original writes x_min through the incoming RECT* parameter home before using
// the saved RECT pointer; reproducing that with an implausible parameter-home alias cast would violate the
// source-plausibility gate, so the natural 9-byte drift is kept.

// Fresh bounded pass 2026-08-10 (orch-pnlscbr-02):
// probe-017 baseline: retained the clean 245B/9-byte natural source.
// probe-018: reused the exact Pnl_scbr windows.h context and reference-output shape_minmax ABI;
// codegen stayed unchanged. probe-019: a natural ptVar1 RECT alias was optimized away.
// probe-020: moving the independent y calculation before x's final RECT-left update caused a
// broad prologue/register regression; rolled back. probe-021: an x_max lifetime temp was a duplicate.
// probe-022: modeled the complete 0x1C4-byte TScrollBarPanel derived layout; duplicate output.
// Retain the canonical typed source/context. The only remaining drift is the documented 9-byte
// scheduling swap at 0047B9EC; reproducing it requires the same implausible parameter-home alias cast,
// so no opaque compiler-steering variant is retained.

#include <windows.h>

class TDrawArea;

class TShape {
public:
    unsigned char shape_minmax(long& out_minx, long& out_miny,
                               long& out_maxx, long& out_maxy, long frame);
    unsigned char shape_draw(TDrawArea* draw_area, long x, long y, long frame,
                             unsigned char color_flag, unsigned char* color_table);
};

class TDrawArea {
public:
    void SetClipRect(tagRECT* rect);
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
    virtual void vf20();
    virtual void vf24();
    virtual void enterCS(int unk);
    virtual void leaveCS();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void draw_rect(tagRECT* rect);

    char _gap_04[0x1C];
    TDrawArea* draw_area;
    char _gap_24[0x1C];
    TPanel* panel;
    char _gap_44[0xB0];
};

class TScrollBarPanel : public TPanel {
public:
    char _gap_F4[0x14];
    TShape* button_pics;
    int back_frame;          // +0x10C
    int up_frame;            // +0x110
    int down_frame;          // +0x114
    int tab_frame;           // +0x118
    long arrowSize;          // +0x11C
    long tabSize;            // +0x120
    long tab_y;              // +0x124
    long tab_min_y;          // +0x128
    long tab_max_y;          // +0x12C
    long tab_mouse_y;        // +0x130
    long tab_x;              // +0x134
    long tab_min_x;          // +0x138
    long tab_max_x;          // +0x13C
    long tab_mouse_x;        // +0x140
    unsigned char item_down; // +0x144
    char _pad_145[3];
    int item_is_down;        // +0x148
    long item_x;             // +0x14C
    long item_y;             // +0x150
    unsigned char item_mode; // +0x154
    char _pad_155[3];
    unsigned long item_last_time;     // +0x158
    unsigned long item_hold_interval; // +0x15C
    unsigned long item_down_interval; // +0x160
    tagRECT up_rect;          // +0x164
    tagRECT down_rect;        // +0x174
    tagRECT tab_rect;         // +0x184
    tagRECT top_rect;         // +0x194
    tagRECT bottom_rect;      // +0x1A4
    long orientationValue;    // +0x1B4
    int bevel_type;           // +0x1B8
    unsigned char bevel_color1; // +0x1BC
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char _pad_1C2[2];

    void draw_button_pic(int param_1, int param_2, tagRECT* param_3);
};

void TScrollBarPanel::draw_button_pic(int param_1, int param_2, tagRECT* param_3)
{
    long x_min;
    long y_max;
    short x;
    short y;
    long y_min;
    long x_max;

    if (this->button_pics != 0 && param_1 != -1) {
        this->draw_area->SetClipRect(param_3);

        this->button_pics->shape_minmax(y_max, x_max, x_min, y_min,
                                        param_1);

        x = (short)((param_3->right - param_3->left + 1) / 2) -
            (short)((x_min + (1 - y_max)) / 2);
        x -= (short)y_max;
        x += (short)param_3->left;
        y = (short)((param_3->bottom - param_3->top + 1) / 2) -
            (short)((y_min - x_max + 1) / 2) -
            (short)x_max + (short)param_3->top;

        if (param_2 != 0) {
            ++x;
            --y;
        }

        this->button_pics->shape_draw(this->draw_area, x, y,
                                      param_1 + (param_2 != 0), 0, 0);
    } else {
        this->panel->draw_rect(param_3);
    }
}
