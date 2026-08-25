// VA: 00442DC0 TDrawSystem::SetDisplaySize (300 bytes)
// PDB source: Drawarea.cpp, lines 845-906
//
// Attempt log:
// - baseline: replaced the old raw shim with the typed TDrawSystem,
//   DirectDraw, DDBLTFX, and TDrawArea surfaces; behavior was still wrong
//   because the requested dimensions were mistaken for DDBLTFX output fields.
// - behavior: use wid/hgt for the display-mode change; frame and call/CFG
//   structure aligned, leaving a register/lifetime mismatch.
// - variant: the period Win32 MAKELONG(wid,hgt) spelling recovered the
//   original EBX/EDI roles and reduced the drift to three stack-offset bytes.
// - liveness/layout probes for scoped/reordered locals were codegen duplicates.
// - behavior: initialize DDBLTFX.dwSize, pass the complete structure to Blt,
//   and use dwFillColor for the color-fill operation; exact match.
// - Main-agent audit confirmed the non-polymorphic draw-system layout and
//   period DirectDraw/MAKELONG surfaces; emitted code remains exact.

#include "../drawarea_phase2_context.h"

extern int system_ignore_size_messages;
extern "C" __declspec(dllimport) long __stdcall SendMessageA(
    void* hwnd, unsigned int msg, unsigned int wparam, long lparam);

int TDrawSystem::SetDisplaySize(long wid, long hgt, int bits)
{
    _DDBLTFX ddbltfx;
    long save_wid;
    long save_hgt;

    if (this->DrawType != 2 || this->ScreenMode != 2)
        return 0;

    system_ignore_size_messages = 1;
    ddbltfx.dwSize = 100;
    ddbltfx.dwFillColor = 0;
    this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
    save_wid = this->ScreenWidth;
    save_hgt = this->ScreenHeight;
    this->ScreenWidth = wid;
    this->ScreenHeight = hgt;

    if (this->DirDraw->SetDisplayMode(this->ScreenWidth, this->ScreenHeight, bits) != 0) {
        system_ignore_size_messages = 0;
        this->ScreenWidth = save_wid;
        this->ScreenHeight = save_hgt;
        return 0;
    }

    system_ignore_size_messages = 0;
    this->ColorBits = bits;
    this->ChangedMode = 1;

    if (this->PrimarySurface != 0) {
        this->PrimarySurface->Release();
        this->PrimarySurface = 0;
    }

    this->CreateSurfaces();
    if (this->DrawArea != 0)
        this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);

    SendMessageA(this->Wnd, 5, 0, MAKELONG(wid, hgt));
    return 1;
}
