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
// the saved RECT pointer; parameter-home alias casts are explicitly prohibited, so the natural 9-byte drift is kept.

#include <stdlib.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;

class TShape {
public:
    unsigned char shape_minmax(long* out_minx, long* out_miny,
                               long* out_maxx, long* out_maxy, long frame);
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

    void draw_button_pic(int param_1, int param_2, tagRECT* param_3);
};

typedef unsigned long DWORD;

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

        this->button_pics->shape_minmax(&y_max, &x_max, &x_min, &y_min,
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
