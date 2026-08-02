// VA: 00421A80 RGE_Base_Game::handle_query_new_palette (234 B)
// PDB source: basegame.cpp lines 4683-4726
//
// Attempt log:
// - Baseline rewrite (this session): corrected both TDrawSystem::HandleQueryNewPalette
//   calls to pass (hwnd, msg, wparam, lparam) through unchanged (the old scratch passed
//   (long)hwnd as the last arg, a Ghidra stack-mis-analysis). Rebuilt the palette path
//   from the binary: double currentPanel call (first result only null-tested), double
//   get_palette call (second inline in SelectPalette), prog_palette default load sunk
//   into the else arm, SelectPalette spelled in both arms to preserve the split push 0
//   and shared push-palette/push-dc/call tail, RealizePalette result saved across
//   ReleaseDC, final draw_system guard with reload, return 1.
// - Fixed RGE_Base_Game layout: gap_00[0x1C] (no-vptr class) so prog_palette lands at +0x1C
//   and draw_system at +0x48; first HandleQueryNewPalette call site reloads this->draw_system
//   (ds local dies after the guard) to reproduce the post-InvalidateRect reload.
// - MATCH: dropped the pal local entirely; tested panel->get_palette() twice (second call
//   inline in SelectPalette args) and used direct this->prog_palette access in the else
//   branch. VC5 then sinks the prog_palette load into the else arm and tail-merges the
//   shared SelectPalette push-palette/push-dc/call with the split push 0 in each arm.
// Result: MATCH locally with `python tools/check_function.py --va 00421A80`.

__declspec(dllimport) void* __stdcall GetDC(void* hwnd);
__declspec(dllimport) void* __stdcall SelectPalette(void* hdc, void* hpal, int bForceBackground);
__declspec(dllimport) int __stdcall RealizePalette(void* hdc);
__declspec(dllimport) int __stdcall ReleaseDC(void* hwnd, void* hdc);
__declspec(dllimport) int __stdcall InvalidateRect(void* hwnd, void* rect, int bErase);

class TDrawSystem {
public:
    char gap_00[0x04];
    void* Wnd;                      // +0x04
    void* Pal;                      // +0x08
    char gap_0C[0x46C];
    unsigned char DrawType;         // +0x478
    unsigned char ScreenMode;       // +0x479

    int HandleQueryNewPalette(void* param1, unsigned int param2, unsigned int param3, long param4);
};

class TPanel {
public:
    void* get_palette();
};

class TPanelSystem {
public:
    TPanel* currentPanel();
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_00[0x1C];              // +0x00..+0x1C (no vptr needed)
    void* prog_palette;             // +0x1C
    char gap_20[0x48 - 0x20];
    TDrawSystem* draw_system;       // +0x48

    int handle_query_new_palette(void* hwnd, unsigned int msg, unsigned int wparam, long lparam);
};

int RGE_Base_Game::handle_query_new_palette(void* hwnd, unsigned int msg, unsigned int wparam, long lparam)
{
    TDrawSystem* ds = this->draw_system;
    if (ds != 0 && ds->DrawType != 1 && ds->ScreenMode != 1) {
        InvalidateRect(hwnd, 0, 0);
        return this->draw_system->HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    }

    void* dc = GetDC(hwnd);
    if (panel_system.currentPanel() != 0) {
        TPanel* panel = panel_system.currentPanel();
        if (panel->get_palette() != 0)
            SelectPalette(dc, panel->get_palette(), 0);
    } else {
        if (this->prog_palette != 0)
            SelectPalette(dc, this->prog_palette, 0);
    }
    int result = RealizePalette(dc);
    ReleaseDC(hwnd, dc);
    if (result != 0)
        InvalidateRect(hwnd, 0, 0);
    if (this->draw_system != 0)
        return this->draw_system->HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    return 1;
}
