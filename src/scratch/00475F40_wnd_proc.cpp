// 00475F40 TEditPanel::wnd_proc(void*, unsigned int, unsigned int, long)
// Source: pnl_edit.cpp lines 524-598
// Size: 242 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Status: PAUSED — 8-byte VC5 register-color drift in two base forwarding sites
//
// Attempt log:
// 1: Early if/goto reconstruction was 221 bytes with direct Win32 calls; this
//    established the guards/fields but had the wrong dispatch and call surface.
// 2: Natural sparse switch plus dllimport APIs restored 88/88 instructions,
//    all six ordered calls, and the original 242-byte boundary.
// 3: Signed short high-word notification test restored the original cmp cx,400.
// 4-7: Virtual/base layout, canonical active/visible ownership, and register
//    local aliases were tested; the emitted bytes stayed unchanged.
// 8: A 20-variant forwarding-call lab (casts, declaration order, and base
//    aliases) produced one codegen group, all with the same 8-byte drift.
// 9-10: Combined positive guard and the same-TU TPanel virtual surface were
//    restored as the final period-plausible source; no emitted-code change.
//
// Canonical facts:
// - TPanel owns active(+0x6C), visible(+0x70), and has size +0xF4.
// - TEditPanel owns edit_wnd(+0xF4), hidden(+0x104), brush(+0x108),
//   highlight_text_color1(+0x11C), and back_color(+0x124).
// - A sparse switch handles 7, 0x111, and 0x133; the default forwards to the
//   qualified TPanel::wnd_proc. Win32 calls use the original IAT surfaces.
//
// Final evidence: 242/242 bytes, 100% instruction/CFG/call/block shape, six
// relocations safely masked, and 8 positional bytes differ. The first drift
// is the default forward at +0xBE: original loads param_1 to ECX, while VC5
// chooses EDX. The case-7 forward also colors its three reloads differently
// (original ECX/EDX/EAX, rebuilt EAX/ECX/EDX). No productive lead remains in
// the bounded session; keep this readable source in scratch for a later worker.

extern "C" __declspec(dllimport) void* __stdcall SetBkColor(void* hdc, int color);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);
extern "C" __declspec(dllimport) void* __stdcall SetTextColor(void* hdc, int color);
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void* hWnd, int* lpRect, int bErase);

struct TPanel {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44();
    virtual long wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
    char pad_04[0x68];
    int active;                  // +0x6C
    int visible;                 // +0x70
    char pad_74[0x80];
};

struct TEditPanel : TPanel {
    void* edit_wnd;              // +0x0F4
    char pad_F8[0x104 - 0xF8];
    int hidden;                  // +0x104
    void* brush;                 // +0x108
    char pad_10C[0x11C - 0x10C];
    int highlight_text_color1;   // +0x11C
    char pad_120[0x124 - 0x120];
    int back_color;              // +0x124

    virtual long wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4);
};

long TEditPanel::wnd_proc(void* param_1, unsigned int param_2, unsigned int param_3, long param_4)
{
    if (edit_wnd != 0 && active != 0 && visible != 0 && hidden == 0) {
        switch (param_2) {
        case 7:
            return TPanel::wnd_proc(param_1, 7, param_3, param_4);

        case 0x111:
            if ((void*)param_4 == edit_wnd && (short)(param_3 >> 16) == 0x400)
                InvalidateRect(edit_wnd, 0, 1);
            break;

        case 0x133:
            if (brush != 0 && (void*)(param_4 & 0xFFFF) == edit_wnd) {
                SetBkColor((void*)param_3, back_color);
                SetBkMode((void*)param_3, 2);
                SetTextColor((void*)param_3, highlight_text_color1);
                return (long)brush;
            }
            break;
        }
    }

    return TPanel::wnd_proc(param_1, param_2, param_3, param_4);
}
