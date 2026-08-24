// VA: 00442A90 TDrawSystem::Init
// PDB source: Drawarea.cpp lines 621-839
// Attempt log:
// - Replaced the placeholder parameter/offset shim with the period DirectDraw
//   initialization surface, typed local records, and named TDrawSystem fields.
// - Removing the persistent DirectDraw value local fixed the 0x610 frame to 0x60C;
//   a scoped receiver across the cooperative-level branch preserved the original
//   call set and the closest register/liveness basin.
// - Typed DDSURFACEDESC/DDCAPS/palette ownership and the natural palette loops
//   match all calls and CFG; the remaining drift is the entry scheduling and a
//   small receiver/vtable register basin, so this stays in scratch.
// - Early store-order, register-qualified parameter, top-level receiver, and
//   layout probes did not move the first block; the mode-field layout is now
//   named from the generated TDrawSystem dump rather than an anonymous gap.
// - A focused six-way first-store variant lab preserved size/frame/call-set but
//   found no exact prologue. The best clean source remains the typed form.
// - Moving long-lived DirectDraw declarations to function entry was a codegen
//   duplicate; the first-block preload stayed unchanged.
// - Reverse comma-grouping and Wnd/Inst/Pal order probes reached diff 450 but
//   worsened source order or edit shape; both were rolled back.
// - One-line initial stores, combined register hints, and <stdlib.h> context
//   were codegen duplicates. The first paired hunk remains the ABI/liveness
//   frontier.
// - Follow-up claim probes tested parameter qualifier, pointer-local scope,
//   receiver alias scope, handle typedefs, local declaration order, direct
//   out-parameter use, and initial-store permutations.  These kept the 0x60C
//   frame and all 15 ordered calls; none recovered the entry preload.
// - The original palette loop writes Red, Blue, Green, Flags.  Restoring that
//   proven order changed its LEA/store bytes and improved the full result.
// - A 24-variant source lab and a 3072-variant ambient-declaration/context lab
//   found no exact result.  All variants kept size, frame, and call-set gates.
// - The best clean reconstruction is 802 bytes, 15/15 ordered calls, 0x60C
//   frame, 446 differing bytes, and 91.29% shape similarity. The first
//   mismatch remains the natural entry parameter-load/store schedule.
// - Behavior review restored Wnd, Pal, Inst, ScreenMode publication order by
//   placing ScreenMode before Inst in source. VC5 schedules that pair in the
//   executable order while preserving all later code and the exact size.
// Accepted-drift review: all initial member stores, 15 calls and arguments,
// DirectDraw failure codes, mode changes, palette bytes, surface setup, caps,
// return values, and faulting member accesses match. Residual drift is stack
// parameter preload and equivalent receiver/vtable register scheduling.
// Exact-finish audit: a fresh grouped check stayed at 453 differing bytes and
// 801 rebuilt bytes versus 802 original bytes. Calls, frame, owner, and EH
// gates matched. A direct DirDraw GetCaps probe reached diff 436 but did not
// recover the entry block or exact bytes, so the clean source was restored.
// Exact-finish audit: the canonical anchors 00446230, 00446340, 00444B50,
// and 004443D0 stayed exact after the target rebuild. A local SDK declaration
// probe was blocked by duplicate definitions in the authentic Drawarea TU.

#include <string.h>
#include "../../include/drawarea_context.h"
#pragma function(memset)

#ifndef DRAWAREA_CANONICAL_TU
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void*, unsigned int, unsigned int, PALETTEENTRY*);
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void*, RECT*);
#endif

int TDrawSystem::Init(void* inst, void* wnd, void* pal,
                      unsigned char draw_type, unsigned char screen_mode,
                      long width, long height, unsigned long flags)
{
    _DDSURFACEDESC ddsd;
    _DDBLTFX ddbltfx;
    _DDCAPS ddcaps;
    PALETTEENTRY color_table[256];
    IDirectDraw** direct_draw;
    IDirectDraw* dd;

    this->Wnd = wnd;
    this->Pal = pal;
    this->ScreenMode = screen_mode;
    this->Inst = inst;
    this->ScreenWidth = width;
    this->DrawType = draw_type;
    this->ScreenHeight = height;
    this->Flags = flags;
    if (draw_type == 1)
        return 0;

    direct_draw = &this->DirDraw;
    if (DirectDrawCreate(0, direct_draw, 0) != 0) {
        this->ErrorCode = 1;
        return 0;
    }

    this->CheckAvailModes(1);
    dd = *direct_draw;
    if (this->ScreenMode == 1) {
        if (dd->SetCooperativeLevel(this->Wnd, 8) != 0) {
            this->ErrorCode = 1;
            return 0;
        }

        memset(&ddsd, 0, 0x6C);
        ddsd.dwSize = 0x6C;
        if ((*direct_draw)->GetDisplayMode(&ddsd) != 0) {
            this->ErrorCode = 1;
            return 0;
        }
        if (ddsd.dwHeight != 8) {
            this->ErrorCode = 2;
            return 0;
        }
    }
    else {
        if (dd->SetCooperativeLevel(this->Wnd, 0x11) != 0) {
            this->ErrorCode = 1;
            return 0;
        }
        this->ColorBits = 8;
        if ((*direct_draw)->SetDisplayMode(this->ScreenWidth, this->ScreenHeight, 8) != 0) {
            this->ErrorCode = 1;
            return 0;
        }
        this->ChangedMode = 1;
    }

    if (this->Pal != 0) {
        GetPaletteEntries(this->Pal, 0, 0x100, color_table);
    }
    else {
        for (int i = 0; i < 0x100; ++i) {
            color_table[i].peRed = 0;
            color_table[i].peGreen = 0;
            color_table[i].peBlue = 0;
            color_table[i].peFlags = 0;
        }
    }

    for (int i = 0; i < 0x100; ++i) {
        this->palette[i].peRed = 0;
        this->palette[i].peBlue = 0;
        this->palette[i].peGreen = 0;
        this->palette[i].peFlags = 0;
    }

    if ((*direct_draw)->CreatePalette(0x44, color_table, &this->DirDrawPal, 0) != 0) {
        this->ErrorCode = 1;
        return 0;
    }
    this->DirDrawPal->lpVtbl->setEntries(this->DirDrawPal, 0, 0, 0x100,
                                         this->palette);

    if ((*direct_draw)->CreateClipper(0, &this->Clipper, 0) != 0) {
        this->ErrorCode = 1;
        return 0;
    }
    if (this->Clipper->SetHWnd(0, this->Wnd) != 0) {
        this->ErrorCode = 1;
        return 0;
    }
    if (this->CreateSurfaces() == 0) {
        this->ErrorCode = 1;
        return 0;
    }

    ddcaps.dwSize = 0x13C;
    this->IsBanked = 0;
    if ((*direct_draw)->GetCaps(&ddcaps, 0) == 0) {
        if ((ddcaps.dwCaps & 0x08000000) != 0)
            this->IsBanked = 1;
        if ((ddcaps.dwCaps & 0x00400000) != 0 &&
            (ddcaps.dwCKeyCaps & 0x200) != 0)
            this->CanSrcBlt = 1;
    }

    if (this->ScreenMode == 2) {
        ddbltfx.dwSize = 0x64;
        ddbltfx.dwFillColor = 0;
        this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
    }
    return 1;
}
