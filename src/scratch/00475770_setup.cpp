// VA: 00475770 TEditPanel::setup
// Source: pnl_edit.cpp lines 121-189
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 1: first pass - compilation issues with windows.h
// 2: clean version - 447 bytes match! 63.3% positional, 68.9% edit match
// 3: fix IAT calls + restructure style computation
// 4: use the proven render-area -> draw-system -> instance ownership instead
//    of a raw vtable-shaped pointer; the remaining baseline drift is the
//    argument-evaluation order at CreateWindowExA.
// 5: restored FormatType/FormatMultiLine; the ternary -1/0 mask recovered
//    the original sub/neg/sbb style computation (278 differing bytes).
// 6-9: named-area/direct-member and declaration-order variants were emitted
//    identically; no further liveness lead was found in the custom-import TU.
// 10: switched to the period <windows.h> import surface.  This retained the
//     typed draw ownership, reached exact size, and reduced the mismatch to
//     92 bytes with all nine call sites aligned.
// Left in scratch: remaining drift begins in the CreateWindowExA argument
// scheduling (render-area/style/instance loads); current source is the best
// canonical typed reconstruction, not a raw-address or vtable scaffold.
// New claim: baseline revalidated the 447-byte/92-byte-diff clean source.
// Probes 1-8 tested post-style geometry locals, instance/style declaration
// order, inline versus DWORD style masks, and full TDrawArea/TDrawSystem sizes;
// only the explicit unary-bool mask was worse (450 bytes), so clean source was
// restored.  The unresolved lead remains CreateWindowExA argument scheduling.
// Fresh direct-expression probe inlined the typed style, geometry, and
// render-area DrawSystem instance into CreateWindowExA; VC5 emitted the same
// 447-byte group, so the clean typed reconstruction remains authoritative.
// 11: inlined only the typed DrawSystem instance argument; VC5 kept the same
//     447-byte/92-byte group, so the direct expression is retained as natural source.
// 12: replaced the boolean style mask with a natural format-minus-enum branch;
//     this produced 448 bytes and a 300-byte diff, then was rolled back.
// 13: a gated eight-way typed area/style/instance lifetime lab had one emitted
//     447-byte group for all valid variants; no scheduling lead remained.
// 14: inlined the typed format expression as the CreateWindowExA style
//     argument; VC5 emitted the same 447-byte group, so the clean source is
//     restored.

#include <windows.h>
#include <stdlib.h>

long pnl_sub_wnd_proc(void*, unsigned int, unsigned int, long);

class TDrawSystem {
public:
    void* Inst;        // +0x00
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem; // +0x00
    void* Wnd;               // +0x04
};

enum FormatType {
    FormatMultiLine = 7
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
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    char gap_04[0x1C];
    TDrawArea* render_area; // +0x20
    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, long p7);
};

class TEditPanel : public TPanel {
public:
    char gap_24[0xF4 - 0x24];
    void* edit_wnd;             // +0xF4
    short fixed_len;            // +0xF8
    char gap_FA[0xFC - 0xFA];
    char* text;                 // +0xFC
    int text_len;               // +0x100
    char gap_104[0x108 - 0x104];
    void* brush;                // +0x108
    char gap_10C[0x110 - 0x10C];
    void* old_sub_wnd_proc;     // +0x110
    int text_color1;            // +0x114
    int text_color2;            // +0x118
    int highlight_text_color1;  // +0x11C
    int highlight_text_color2;  // +0x120
    int back_color;             // +0x124
    FormatType format;          // +0x128
    void* font;                 // +0x12C
    char gap_130[0x144 - 0x130];
    int draw_format;            // +0x144
    int auto_sel;               // +0x148

    long setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, void* p7, short p8, char* p9, FormatType p10, int p11);
    void set_text(char* txt);
};

long TEditPanel::setup(
    TDrawArea* param_1,
    TPanel* param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6,
    void* param_7,
    short param_8,
    char* param_9,
    FormatType param_10,
    int param_11)
{
    long result;

    this->format = param_10;

    if (param_8 > 0) {
        param_8++;
    }
    this->fixed_len = param_8;

    this->font = param_7;
    this->auto_sel = param_11;

    result = TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, 0xFF);
    if (result == 0) {
        return 0;
    }

    // Create edit window.  The instance is owned by the draw system behind
    // this panel's render area.  Keep the boolean style mask in the natural
    // source form used by the original FormatType test.
    TDrawArea* panel_area = this->render_area;
    int styleVal = ((this->format != FormatMultiLine ? -1 : 0) & 0xFFE0003C) + 0x40200044;
    this->edit_wnd = CreateWindowExA(
        0, "edit", 0,
        styleVal,
        param_3 + 1, param_4 + 1, param_5 - 2, param_6 - 2,
        param_1->Wnd, (void*)1,
        panel_area->DrawSystem->Inst,
        0
    );
    if (this->edit_wnd == 0) {
        return 0;
    }

    // SetWindowLongA(edit_wnd, -0x15, this)
    SetWindowLongA(this->edit_wnd, -0x15, (long)(void*)this);

    // GetWindowLongA(edit_wnd, -4) -> old_sub_wnd_proc
    this->old_sub_wnd_proc = (void*)GetWindowLongA(this->edit_wnd, -4);

    // SetWindowLongA(edit_wnd, -4, pnl_sub_wnd_proc)
    SetWindowLongA(this->edit_wnd, -4, (long)(void*)pnl_sub_wnd_proc);

    // Allocate text buffer
    {
        char* textBuf = (char*)calloc(this->fixed_len + 2, 1);
        this->text = textBuf;
        if (textBuf == 0) {
            return 0;
        }
        *textBuf = 0;
    }

    this->text_len = 0;

    if (param_9 != 0 && *param_9 != 0) {
        this->set_text(param_9);
    }

    this->brush = GetStockObject(4);

    this->text_color1 = 0xFFFFFF;
    this->highlight_text_color1 = 0xFFFFFF;
    this->back_color = 0;
    this->text_color2 = 0;
    this->highlight_text_color2 = 0;

    if (this->font != 0) {
        SendMessageA(this->edit_wnd, 0x30, (unsigned int)this->font, 0);
    }

    // draw_format: 0x2000 then -(format != 7) & 0x10 + 0x2010
    this->draw_format = 0x2000;
    {
        int df2 = this->format - 7;
        if (df2) df2 = -1;
        df2 &= 0x10;
        df2 += 0x2010;
        this->draw_format = df2;
    }

    return 1;
}
