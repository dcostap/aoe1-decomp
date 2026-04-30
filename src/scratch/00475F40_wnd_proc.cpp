// 00475F40 TEditPanel::wnd_proc(void*, unsigned int, unsigned int, long)
// Source: pnl_edit.cpp lines 524-598
// Size: 242 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PARKED — VC5 codegen drift (224/242 bytes)
//
// Attempt log:
// Probe 1: if/else chain — 224 bytes, short jumps for checks
// Probe 2: separate if/goto — same
//
// Key findings (struct layout correct):
// - edit_wnd(+0xF4), field_6C(+0x6C), field_70(+0x70), hidden(+0x104)
// - brush(+0x108), highlight_text_color1(+0x11C), back_color(+0x124)
// - Case 7: TPanel::wnd_proc(param_1, 7, param_3, param_4)
// - Case 0x111: InvalidateRect + fall-through to default
// - Case 0x133: SetBkColor, SetBkMode, SetTextColor, return brush
// - Default: TPanel::wnd_proc(param_1, param_2, param_3, param_4)
// - IAT: SetBkColor[88A5F0h], SetBkMode[88A5ECh], SetTextColor[88A5E4h], InvalidateRect[88A804h]
//
// Remaining drift:
// - je/jne short (2 bytes) vs je/jne near (6 bytes) — 16 bytes saved
// - cmp+jne vs mov+sub+je for switch dispatch
// - Different register loading for case 7 params

extern "C" void* __stdcall SetBkColor(void* hdc, int color);
extern "C" int __stdcall SetBkMode(void* hdc, int mode);
extern "C" void* __stdcall SetTextColor(void* hdc, int color);
extern "C" int __stdcall InvalidateRect(void* hWnd, int* lpRect, int bErase);

struct TPanel {
    long wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};

struct TEditPanel : TPanel {
    char pad_00[0x6C];
    void* field_6C;              // +0x6C
    void* field_70;              // +0x70
    char pad_74[0x0F4 - 0x74];
    void* edit_wnd;              // +0x0F4
    char pad_F8[0x104 - 0xF8];
    int hidden;                  // +0x104
    void* brush;                 // +0x108
    char pad_10C[0x11C - 0x10C];
    int highlight_text_color1;   // +0x11C
    char pad_120[0x124 - 0x120];
    int back_color;              // +0x124

    long wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};

long TEditPanel::wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4)
{
    if (edit_wnd == 0)
        goto def;
    if (field_6C == 0)
        goto def;
    if (field_70 == 0)
        goto def;
    if (hidden != 0)
        goto def;

    if (param_2 == 7)
        return TPanel::wnd_proc(param_1, 7, param_3, param_4);

    if (param_2 == 0x111) {
        if ((void*)param_4 == edit_wnd && (unsigned short)(param_3 >> 16) == 0x400)
            InvalidateRect(edit_wnd, 0, 1);
        goto def;
    }

    if (param_2 == 0x133) {
        if (brush != 0 && (void*)(param_4 & 0xFFFF) == edit_wnd) {
            SetBkColor((void*)param_3, back_color);
            SetBkMode((void*)param_3, 2);
            SetTextColor((void*)param_3, highlight_text_color1);
            return (long)brush;
        }
    }

def:
    return TPanel::wnd_proc(param_1, param_2, param_3, param_4);
}
