#include <windows.h>
#include <ddraw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "../include/TDrawSystem.h"
#include "../include/TDrawArea.h"
#include "../include/TSpan_List_Manager.h"
#include "../include/RGE_Color_Table.h"
#include "../include/custom_debug.h"

// EXTERNAL
int system_ignore_size_messages = 0;

extern "C" {
// Mirrors the original DAT_0088c058 block (prefix + 8 dwords starting at +8).
// The first 8 bytes (offsets 0/4) are referenced by the ASM render path, but are not currently
// consumed by our software renderer; keep them for parity/future porting.
struct ASMShadowingState {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int table[8]; // DAT_0088c058 + 8
};
ASMShadowingState g_ASMShadowing_State = {0};
unsigned int g_ASMShadowing_Amount = 0; // derived 0..255, consumed by the software shape drawers

// Mirrors the original DAT_0088c000..DAT_0088c08c render block used by the ASM draw routines.
// For our software renderer, this is primarily consumed for parity and for span clipping state.
struct ASMSurfaceInfoState {
    void** DisplayOffsets;     // DAT_0088c000
    VSpan_Node** LineHeadPtrs; // DAT_0088c004
    VSpan_Node** LineTailPtrs; // DAT_0088c008
    int MinLine;               // DAT_0088c080
    int MaxLine;               // DAT_0088c084
    int MinSpanPx;             // DAT_0088c088
    int MaxSpanPx;             // DAT_0088c08c
};
ASMSurfaceInfoState g_ASMSurfaceInfo_State = {0};

unsigned int g_ASMColorXform = 0;          // DAT_0088c040 (replicated byte)
unsigned char* g_ASMXlateTable = nullptr;  // DAT_0088c01c
}

static unsigned int asm_shadowing_extract_amount(unsigned int p2, unsigned int p4) {
    // Calls in view.cpp use two patterns for the same 8-bit amount:
    // - "shifted":   0xNN00NN00  (amount in bytes 1 and 3)
    // - "unshifted": 0x00NN00NN  (amount in bytes 0 and 2)
    if ((p2 & 0xFF00FF00u) != 0) return (p2 >> 8) & 0xFFu;
    if ((p4 & 0xFF00FF00u) != 0) return (p4 >> 8) & 0xFFu;
    if ((p2 & 0x00FF00FFu) != 0) return p2 & 0xFFu;
    if ((p4 & 0x00FF00FFu) != 0) return p4 & 0xFFu;
    return 0;
}

// Fully verified. Source of truth: bucket_056C.decomp @ 0x0056C680
extern "C" void _ASMSet_Shadowing(int p1, int p2, int p3, int p4) {
    g_ASMShadowing_State.table[0] = (unsigned int)p1;
    g_ASMShadowing_State.table[1] = (unsigned int)p3;
    g_ASMShadowing_State.table[2] = (unsigned int)p1;
    g_ASMShadowing_State.table[3] = (unsigned int)p3;
    g_ASMShadowing_State.table[4] = (unsigned int)p2;
    g_ASMShadowing_State.table[5] = (unsigned int)p4;
    g_ASMShadowing_State.table[6] = (unsigned int)p2;
    g_ASMShadowing_State.table[7] = (unsigned int)p4;

    g_ASMShadowing_Amount = asm_shadowing_extract_amount((unsigned int)p2, (unsigned int)p4);
}

// Fully verified. Source of truth: bucket_056C.decomp @ 0x0056C6C0
extern "C" void _ASMSet_ShadowingEx(int* p) {
    // Note: original ASM dereferences unconditionally; keep parity (no defensive null check).
    g_ASMShadowing_State.table[0] = (unsigned int)p[0];
    g_ASMShadowing_State.table[1] = (unsigned int)p[1];
    g_ASMShadowing_State.table[2] = (unsigned int)p[2];
    g_ASMShadowing_State.table[3] = (unsigned int)p[3];
    g_ASMShadowing_State.table[4] = (unsigned int)p[4];
    g_ASMShadowing_State.table[5] = (unsigned int)p[5];
    g_ASMShadowing_State.table[6] = (unsigned int)p[6];
    g_ASMShadowing_State.table[7] = (unsigned int)p[7];

    g_ASMShadowing_Amount = asm_shadowing_extract_amount(g_ASMShadowing_State.table[4], g_ASMShadowing_State.table[5]);
}

// Fully verified. Source of truth: bucket_056C.decomp @ 0x0056C720
extern "C" void _ASMSet_Surface_Info(
    void** display_offsets,
    VSpan_Node** line_head_ptrs,
    VSpan_Node** line_tail_ptrs,
    int min_span_px,
    int min_line,
    int max_span_px,
    int max_line) {
    g_ASMSurfaceInfo_State.DisplayOffsets = display_offsets;
    g_ASMSurfaceInfo_State.LineHeadPtrs = line_head_ptrs;
    g_ASMSurfaceInfo_State.LineTailPtrs = line_tail_ptrs;
    g_ASMSurfaceInfo_State.MinLine = min_line;
    g_ASMSurfaceInfo_State.MaxLine = max_line;
    g_ASMSurfaceInfo_State.MinSpanPx = min_span_px;
    g_ASMSurfaceInfo_State.MaxSpanPx = max_span_px;
}

// Fully verified. Source of truth: bucket_056C.decomp @ 0x0056C760
extern "C" void _ASMSet_Color_Xform(int v) {
    const unsigned int b = (unsigned int)((unsigned char)v);
    g_ASMColorXform = b | (b << 8) | (b << 16) | (b << 24);
}

// Fully verified. Source of truth: bucket_056C.decomp @ 0x0056C780
extern "C" unsigned int _ASMGet_Color_Xform() {
    return g_ASMColorXform & 0xFFu;
}

// Fully verified. Source of truth: bucket_056C.decomp @ 0x0056C7A0
extern "C" void _ASMSet_Xlate_Table(void* p) {
    g_ASMXlateTable = (unsigned char*)p;
}

// Fully verified. Source of truth: bucket_056C.asm @ 0x0056C7AD (label _ASMGet_Xlate_Table @ 0x0056C7C0)
extern "C" void* _ASMGet_Xlate_Table() {
    return (void*)g_ASMXlateTable;
}

static unsigned long scale_component_to_mask_ul(unsigned int c, unsigned long mask) {
    if (mask == 0) return 0;
    unsigned long m = mask;
    int shift = 0;
    while ((m & 1) == 0) {
        m >>= 1;
        shift++;
    }
    int bits = 0;
    while ((m & 1) != 0) {
        m >>= 1;
        bits++;
    }
    if (bits <= 0) return 0;
    unsigned int maxv = (1u << bits) - 1u;
    unsigned int v = (c * maxv + 127u) / 255u;
    return ((unsigned long)v << shift) & mask;
}

static unsigned long map_color_index_to_surface_pixel(TDrawArea* area, int idx, const DDSURFACEDESC* ddsd, HRESULT sdesc_hr) {
    if (!area) return (unsigned long)idx;
    if (idx < 0) idx = 0;
    if (idx > 255) idx = 255;

    unsigned long bpp = 8;
    if (sdesc_hr == DD_OK && ddsd) bpp = ddsd->ddpfPixelFormat.dwRGBBitCount;
    if (bpp <= 8) return (unsigned long)(idx & 0xff);

    if (!area->DrawSystem) return (unsigned long)idx;
    const tagPALETTEENTRY* pe = &area->DrawSystem->palette[idx];
    const unsigned long r = (unsigned long)pe->peRed;
    const unsigned long g = (unsigned long)pe->peGreen;
    const unsigned long b = (unsigned long)pe->peBlue;

    if (sdesc_hr == DD_OK && ddsd) {
        const unsigned long pr = scale_component_to_mask_ul((unsigned int)r, ddsd->ddpfPixelFormat.dwRBitMask);
        const unsigned long pg = scale_component_to_mask_ul((unsigned int)g, ddsd->ddpfPixelFormat.dwGBitMask);
        const unsigned long pb = scale_component_to_mask_ul((unsigned int)b, ddsd->ddpfPixelFormat.dwBBitMask);
        return pr | pg | pb;
    }

    // Fallback: assume 0x00RRGGBB.
    return (r << 16) | (g << 8) | b;
}

static int drawarea_bytes_per_pixel(TDrawArea* area) {
    if (!area) return 1;
    int bpp = 0;
    if (area->SurfaceDesc.dwSize == sizeof(DDSURFACEDESC)) {
        bpp = (int)area->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount;
    }
    if (bpp <= 0 && area->Width > 0 && area->Pitch > 0) {
        bpp = (int)((area->Pitch * 8) / area->Width);
    }
    if (bpp <= 0) bpp = 8;
    int bytes = bpp / 8;
    if (bytes <= 0) bytes = 1;
    if (bytes > 4) bytes = 4;
    return bytes;
}

static unsigned long drawarea_index_to_pixel_locked(TDrawArea* area, uchar color_idx) {
    if (!area) return (unsigned long)color_idx;
    if (area->SurfaceDesc.dwSize == sizeof(DDSURFACEDESC)) {
        return map_color_index_to_surface_pixel(area, (int)color_idx, &area->SurfaceDesc, DD_OK);
    }
    return map_color_index_to_surface_pixel(area, (int)color_idx, (const DDSURFACEDESC*)0, DDERR_GENERIC);
}

static void drawarea_store_pixel(uchar* dst, int bytes_per_pixel, unsigned long px) {
    if (bytes_per_pixel <= 1) {
        dst[0] = (uchar)(px & 0xFF);
        return;
    }
    if (bytes_per_pixel == 2) {
        dst[0] = (uchar)(px & 0xFF);
        dst[1] = (uchar)((px >> 8) & 0xFF);
        return;
    }
    if (bytes_per_pixel == 3) {
        dst[0] = (uchar)(px & 0xFF);
        dst[1] = (uchar)((px >> 8) & 0xFF);
        dst[2] = (uchar)((px >> 16) & 0xFF);
        return;
    }
    dst[0] = (uchar)(px & 0xFF);
    dst[1] = (uchar)((px >> 8) & 0xFF);
    dst[2] = (uchar)((px >> 16) & 0xFF);
    dst[3] = (uchar)((px >> 24) & 0xFF);
}

static void drawarea_fill_run(uchar* dst, int count, int bytes_per_pixel, unsigned long px) {
    if (count <= 0) return;
    if (bytes_per_pixel <= 1) {
        memset(dst, (int)(px & 0xFF), (size_t)count);
        return;
    }

    uchar* p = dst;
    for (int i = 0; i < count; ++i) {
        drawarea_store_pixel(p, bytes_per_pixel, px);
        p += bytes_per_pixel;
    }
}

static unsigned long drawarea_palette_checksum(const tagPALETTEENTRY* entries, int count) {
    if (entries == nullptr || count <= 0) {
        return 0;
    }

    unsigned long hash = 2166136261UL;
    for (int i = 0; i < count; ++i) {
        hash ^= (unsigned long)entries[i].peRed;
        hash *= 16777619UL;
        hash ^= (unsigned long)entries[i].peGreen;
        hash *= 16777619UL;
        hash ^= (unsigned long)entries[i].peBlue;
        hash *= 16777619UL;
        hash ^= (unsigned long)entries[i].peFlags;
        hash *= 16777619UL;
    }
    return hash;
}

TDrawSystem::TDrawSystem() {
    memset(this, 0, sizeof(TDrawSystem));
    this->ColorBits = 8; // Default to 8-bit
    system_ignore_size_messages = 0;
    _ASMSet_Shadowing(0x00FF00FF, 0, (int)0xFF00FF00u, 0);
}

// Source of truth: Drawarea.cpp.decomp @ 0x00442710
TDrawSystem::~TDrawSystem() {
    // In fullscreen, clear the primary surface before shutdown
    if (this->ScreenMode == 2 && this->PrimarySurface != nullptr) {
        DDBLTFX ddbltfx;
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = 0;
        this->PrimarySurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
    }
    this->DeleteSurfaces();
    if (this->DirDraw != nullptr) {
        if (this->DirDrawPal) {
            this->DirDrawPal->Release();
            this->DirDrawPal = NULL;
        }
        if (this->Clipper) {
            this->Clipper->Release();
            this->Clipper = NULL;
        }
        if (this->ChangedMode != 0) {
            this->DirDraw->RestoreDisplayMode();
            this->ChangedMode = 0;
        }
        this->DirDraw->Release();
        this->DirDraw = NULL;
    }
}

int TDrawSystem::Init(void* inst, void* wnd, void* pal, uchar draw_type, uchar screen_mode, long width, long height, ulong flags) {
    this->Wnd = wnd;
    this->Pal = pal;
    this->Inst = inst;
    this->ScreenMode = screen_mode;
    this->ScreenWidth = width;
    this->DrawType = draw_type;
    this->ScreenHeight = height;
    this->Flags = flags;

    // DrawType 1 = WinG (unsupported)
    if (draw_type == 1) {
        return 0;
    }

    // DirectDraw initialization
    HRESULT hr = DirectDrawCreate(NULL, &this->DirDraw, NULL);
    if (hr != DD_OK) {
        this->ErrorCode = 1;
        return 0;
    }

    this->CheckAvailModes(1);

    if (this->ScreenMode == 2) {
        // Try fullscreen mode: DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE
        hr = this->DirDraw->SetCooperativeLevel((HWND)this->Wnd, DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE);
        if (hr == DD_OK) {
            this->ColorBits = 8;
            hr = this->DirDraw->SetDisplayMode(this->ScreenWidth, this->ScreenHeight, 8);
        }
        if (hr != DD_OK) {
            // Fullscreen 8-bit failed (common on modern Windows) — fall back to windowed
            CUSTOM_DEBUG_LOG_FMT("TDrawSystem::Init: Fullscreen failed (hr=0x%x), falling back to windowed", hr);
            this->DirDraw->SetCooperativeLevel((HWND)this->Wnd, DDSCL_NORMAL);
            this->ScreenMode = 1;
            this->ChangedMode = 0;
            // Resize window to game resolution BEFORE surfaces are created
            DWORD style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
            SetWindowLongA((HWND)this->Wnd, GWL_STYLE, style);
            RECT rc = {0, 0, this->ScreenWidth, this->ScreenHeight};
            AdjustWindowRect(&rc, style, FALSE);
            SetWindowPos((HWND)this->Wnd, HWND_TOP, 0, 0,
                         rc.right - rc.left, rc.bottom - rc.top,
                         SWP_NOMOVE | SWP_FRAMECHANGED);
            ShowWindow((HWND)this->Wnd, SW_SHOW);
        } else {
            this->ChangedMode = 1;
        }
    }

    if (this->ScreenMode == 1) {
        // Windowed mode: DDSCL_NORMAL
        hr = this->DirDraw->SetCooperativeLevel((HWND)this->Wnd, DDSCL_NORMAL);
        if (hr != DD_OK) {
            this->ErrorCode = 1;
            return 0;
        }
        // Query actual display mode (don't require 8-bit — modern displays are 32-bit)
        DDSURFACEDESC ddsd;
        memset(&ddsd, 0, sizeof(ddsd));
        ddsd.dwSize = sizeof(ddsd);
        hr = this->DirDraw->GetDisplayMode(&ddsd);
        if (hr == DD_OK) {
            this->ColorBits = (int)ddsd.ddpfPixelFormat.dwRGBBitCount;
            CUSTOM_DEBUG_LOG_FMT("TDrawSystem::Init: Windowed mode, display=%d-bit", this->ColorBits);
        }
    }

    // Palette initialization
    tagPALETTEENTRY color_table[256];
    if (this->Pal == nullptr) {
        memset(color_table, 0, sizeof(color_table));
    } else {
        GetPaletteEntries((HPALETTE)this->Pal, 0, 256, color_table);
    }

    // Zero internal palette
    memset(this->palette, 0, sizeof(this->palette));

    // Create DirectDraw palette (may fail on non-8-bit displays — that's OK)
    hr = this->DirDraw->CreatePalette(DDPCAPS_8BIT | DDPCAPS_INITIALIZE, color_table, &this->DirDrawPal, NULL);
    if (hr == DD_OK) {
        this->DirDrawPal->GetEntries(0, 0, 256, this->palette);
    } else {
        CUSTOM_DEBUG_LOG_FMT("TDrawSystem::Init: CreatePalette failed hr=0x%x (non-8-bit display, OK)", hr);
        // Copy color_table to internal palette directly
        memcpy(this->palette, color_table, sizeof(this->palette));
    }

    // Create clipper
    hr = this->DirDraw->CreateClipper(0, &this->Clipper, NULL);
    if (hr != DD_OK) {
        this->ErrorCode = 1;
        return 0;
    }
    hr = this->Clipper->SetHWnd(0, (HWND)this->Wnd);
    if (hr != DD_OK) {
        this->ErrorCode = 1;
        return 0;
    }

    // Create surfaces
    if (!this->CreateSurfaces()) {
        this->ErrorCode = 1;
        return 0;
    }

    // Query hardware caps
    this->IsBanked = 0;
    DDCAPS ddcaps;
    memset(&ddcaps, 0, sizeof(ddcaps));
    ddcaps.dwSize = sizeof(ddcaps);
    hr = this->DirDraw->GetCaps(&ddcaps, NULL);
    if (hr == DD_OK) {
        if ((ddcaps.dwCaps & DDCAPS_BANKSWITCHED) != 0) {
            this->IsBanked = 1;
        }
        if ((ddcaps.dwCaps & DDCAPS_BLT) != 0 && (ddcaps.dwCaps & DDCAPS_BLTCOLORFILL) != 0) {
            this->CanSrcBlt = 1;
        }
    }

    // Decomp: clear primary surface in fullscreen after init
    if (this->ScreenMode == 2 && this->PrimarySurface != nullptr) {
        DDBLTFX ddbltfx;
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = 0;
        this->PrimarySurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
    }

    return 1;
}

// Source of truth: Drawarea.cpp.decomp @ 0x004430F0
int TDrawSystem::CreateSurfaces() {
    // When DrawType == 2 (DirectDraw), create the DD primary surface
    if (this->DrawType == 2) {
        if (this->PrimarySurface == nullptr) {
            DDSURFACEDESC ddsd;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            ddsd.dwFlags = DDSD_CAPS;
            ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
            HRESULT hr = this->DirDraw->CreateSurface(&ddsd, &this->PrimarySurface, NULL);
            if (hr != DD_OK) {
                return 0;
            }
            // Attach palette to primary surface
            if (this->ColorBits == 8 && this->DirDrawPal) {
                hr = this->PrimarySurface->SetPalette(this->DirDrawPal);
            }
            // Attach clipper to primary surface
            if (this->Clipper) {
                hr = this->PrimarySurface->SetClipper(this->Clipper);
            }
        }

        // Create PrimaryArea TDrawArea ("Primary Surface", is_primary=1)
        if (this->PrimaryArea == nullptr) {
            TDrawArea* pa = new TDrawArea("Primary Surface");
            if (!pa) return 0;
            this->PrimaryArea = pa;
            int w, h;
            if (this->ScreenMode == 1) {
                RECT rc;
                GetClientRect((HWND)this->Wnd, &rc);
                w = rc.right;
                h = rc.bottom;
            } else {
                w = this->ScreenWidth;
                h = this->ScreenHeight;
            }
            if (!pa->Init(this, this->Wnd, w, h, 0, 1, 0)) {
                return 0;
            }
        }
    }

    // Create DrawArea TDrawArea ("Back Buffer", is_primary=0)
    if (this->DrawArea == nullptr) {
        TDrawArea* da = new TDrawArea("Back Buffer");
        if (!da) return 0;
        this->DrawArea = da;
        int w, h;
        if (this->ScreenMode == 1) {
            RECT rc;
            GetClientRect((HWND)this->Wnd, &rc);
            w = rc.right;
            h = rc.bottom;
        } else {
            w = this->ScreenWidth;
            h = this->ScreenHeight;
        }
        if (!da->Init(this, this->Wnd, w, h, 0, 0, 0)) {
            return 0;
        }
    }

    return 1;
}

// Source of truth: Drawarea.cpp.decomp @ 0x004427A0
void TDrawSystem::CheckAvailModes(int p1) {
    if (p1 == 0) {
        // Windowed mode: check desktop resolution via GDI
        this->ModeAvail640 = 1;
        HDC hdc = CreateICA("DISPLAY", NULL, NULL, NULL);
        if (hdc != NULL) {
            int horz = GetDeviceCaps(hdc, HORZRES);
            GetDeviceCaps(hdc, VERTRES); // decomp calls but ignores result
            DeleteDC(hdc);
            if (horz > 799)  this->ModeAvail800 = 1;
            if (horz > 1023) this->ModeAvail1024 = 1;
            if (horz > 1279) this->ModeAvail1280 = 1;
        }
    } else {
        // Fullscreen mode: enumerate via DirectDraw
        int created_temp = 0;
        if (this->DirDraw == nullptr) {
            HRESULT hr = DirectDrawCreate(NULL, &this->DirDraw, NULL);
            if (hr != DD_OK) return;
            created_temp = 1;
        }
        this->DirDraw->EnumDisplayModes(0, NULL, this, TDrawSystem::CheckAvailModesCallback);
        if (created_temp) {
            this->DirDraw->Release();
            this->DirDraw = nullptr;
        }
    }
}

long __stdcall TDrawSystem::CheckAvailModesCallback(_DDSURFACEDESC* p1, void* p2) {
    TDrawSystem* ds = (TDrawSystem*)p2;
    if (p1->ddpfPixelFormat.dwRGBBitCount == 8) {
        if (p1->dwWidth == 640 && p1->dwHeight == 480) ds->ModeAvail640 = 1;
        else if (p1->dwWidth == 800 && p1->dwHeight == 600) ds->ModeAvail800 = 1;
        else if (p1->dwWidth == 1024 && p1->dwHeight == 768) ds->ModeAvail1024 = 1;
        else if (p1->dwWidth == 1280 && p1->dwHeight == 1024) ds->ModeAvail1280 = 1;
    }
    return DDENUMRET_OK;
}

int TDrawSystem::IsModeAvail(long w, long h, int bpp) {
    // Decomp calls this with h=0 for width-only checks
    if (bpp == 8) {
        if (w == 640  && (h == 0 || h == 480))  return this->ModeAvail640;
        if (w == 800  && (h == 0 || h == 600))  return this->ModeAvail800;
        if (w == 1024 && (h == 0 || h == 768))  return this->ModeAvail1024;
        if (w == 1280 && (h == 0 || h == 1024)) return this->ModeAvail1280;
    }
    return 0;
}

// Source of truth: Drawarea.cpp.decomp @ 0x00443090
void TDrawSystem::DeleteSurfaces() {
    // Delete back buffer first
    if (this->DrawArea != nullptr) {
        delete this->DrawArea;
        this->DrawArea = nullptr;
    }
    // Delete primary area (doesn't release PrimarySurface — IsPrimarySurface flag prevents it)
    if (this->PrimarySurface != nullptr) {
        if (this->PrimaryArea != nullptr) {
            delete this->PrimaryArea;
        }
        this->PrimaryArea = nullptr;
        this->PrimarySurface->Release();
        this->PrimarySurface = nullptr;
    }
}

// Source of truth: Drawarea.cpp.decomp @ 0x00443520
void TDrawSystem::Paint(tagRECT* param_rect) {
    if (this->DrawType == 1) return;
    if (this->PrimarySurface == nullptr) return;
    if (this->DrawArea == nullptr) return;
    if (this->DrawArea->DrawSurface == nullptr) return;

    RECT dest;
    RECT src;

    if (this->ScreenMode == 1) {
        // Windowed: get client rect and convert dest to screen coords
        GetClientRect((HWND)this->Wnd, &src);
        dest = src;
        ClientToScreen((HWND)this->Wnd, (POINT*)&dest.left);
        ClientToScreen((HWND)this->Wnd, (POINT*)&dest.right);
    } else {
        // Fullscreen: full screen blit
        src.left = 0;
        src.top = 0;
        src.right = this->ScreenWidth;
        src.bottom = this->ScreenHeight;
        dest.left = 0;
        dest.top = 0;
        dest.right = this->ScreenWidth;
        dest.bottom = this->ScreenHeight;
    }

    if (param_rect != nullptr) {
        int sx = param_rect->left;
        int sy = param_rect->top;
        int ex = param_rect->right;
        int ey = param_rect->bottom;
        if (sx < 0) sx = 0;
        if (sy < 0) sy = 0;
        if (ex >= this->ScreenWidth) ex = this->ScreenWidth - 1;
        if (ey >= this->ScreenHeight) ey = this->ScreenHeight - 1;
        dest.left = dest.left + sx;
        dest.top = dest.top + sy;
        dest.right = dest.left + (ex - sx) + 1;
        dest.bottom = dest.top + (ey - sy) + 1;
        src.left = sx;
        src.top = sy;
        src.right = ex + 1;
        src.bottom = ey + 1;
    }

    this->PrimarySurface->Blt(&dest, this->DrawArea->DrawSurface, &src, DDBLT_WAIT, NULL);
}

// Source of truth: Drawarea.cpp.decomp @ 0x00443CB0
void TDrawSystem::SetPalette(void* pal) {
    this->Pal = pal;
    PALETTEENTRY color_table[256];
    if (pal == nullptr) {
        memset(color_table, 0, sizeof(color_table));
    } else {
        GetPaletteEntries((HPALETTE)pal, 0, 256, color_table);
    }
    // Decomp zeros entry 0 (transparent/black) after reading
    color_table[0].peRed = 0;
    color_table[0].peGreen = 0;
    color_table[0].peBlue = 0;
    color_table[0].peFlags = 0;

    CUSTOM_DEBUG_BEGIN
    static int s_set_palette_logs = 0;
    if (s_set_palette_logs < 8) {
        const PALETTEENTRY* p1 = &color_table[1];
        const PALETTEENTRY* p16 = &color_table[16];
        const PALETTEENTRY* p64 = &color_table[64];
        const PALETTEENTRY* p200 = &color_table[200];
        CUSTOM_DEBUG_LOG_FMT(
            "TDrawSystem::SetPalette pal=%p idx1=(%u,%u,%u) idx16=(%u,%u,%u) idx64=(%u,%u,%u) idx200=(%u,%u,%u)",
            pal,
            (unsigned)p1->peRed,
            (unsigned)p1->peGreen,
            (unsigned)p1->peBlue,
            (unsigned)p16->peRed,
            (unsigned)p16->peGreen,
            (unsigned)p16->peBlue,
            (unsigned)p64->peRed,
            (unsigned)p64->peGreen,
            (unsigned)p64->peBlue,
            (unsigned)p200->peRed,
            (unsigned)p200->peGreen,
            (unsigned)p200->peBlue);
        s_set_palette_logs++;
    }
    CUSTOM_DEBUG_END

    this->ModifyPalette(0, 256, color_table);
}

// Source of truth: Drawarea.cpp.decomp @ 0x00443D40
void TDrawSystem::ModifyPalette(int start, int count, tagPALETTEENTRY* entries) {
    if (start < start + count) {
        memcpy(&this->palette[start], entries, count * sizeof(tagPALETTEENTRY));
    }
    if (this->DrawType != 1 && this->DirDrawPal != nullptr) {
        this->DirDrawPal->SetEntries(0, start, count, entries);
    }
}

// Source of truth: Drawarea.cpp.decomp @ 0x00442EF0
void TDrawSystem::ClearPrimarySurface() {
    if (this->ScreenMode == 2 && this->PrimarySurface != nullptr) {
        DDBLTFX ddbltfx;
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = 0;
        this->PrimarySurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
    }
}

// Source of truth: Drawarea.cpp.decomp @ 0x00442F30
// Returns: 0=OK, 1=display mode changed, 2=surfaces restored, 3=fatal error
uchar TDrawSystem::CheckSurfaces() {
    if (this->DrawType != 2) return 0;
    if (this->PrimarySurface == nullptr || this->DrawArea == nullptr ||
        this->DrawArea->DrawSurface == nullptr) {
        return 3;
    }

    uchar result = 0;
    HRESULT hr = this->PrimarySurface->IsLost();
    if (hr != DD_OK) {
        // Primary surface is lost — check if display mode changed
        DDSURFACEDESC ddsd;
        memset(&ddsd, 0, sizeof(ddsd));
        ddsd.dwSize = sizeof(ddsd);
        hr = this->DirDraw->GetDisplayMode(&ddsd);
        if (hr == DD_OK &&
            ((int)ddsd.dwWidth != this->ScreenWidth ||
             (int)ddsd.dwHeight != this->ScreenHeight ||
             (int)ddsd.ddpfPixelFormat.dwRGBBitCount != 8)) {
            return 1; // display mode changed
        }
        hr = this->PrimarySurface->Restore();
        if (hr != DD_OK) {
            return 3; // fatal
        }
        this->Restored = 1;
        result = 2;
        // Clear primary surface after restore
        DDBLTFX ddbltfx;
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = 0;
        this->PrimarySurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
    }

    // Walk DrawAreaList — check each surface (except PrimaryArea)
    DrawAreaNode* node = this->DrawAreaList;
    while (node != nullptr) {
        if (node->DrawArea != this->PrimaryArea) {
            uchar chk = node->DrawArea->CheckSurface();
            if (chk == 3) return 3;
        }
        node = node->NextNode;
    }

    return result;
}

// Source of truth: Drawarea.cpp.decomp @ 0x00443070
void TDrawSystem::ClearRestored() {
    this->Restored = 0;
    DrawAreaNode* node = this->DrawAreaList;
    for (; node != nullptr; node = node->NextNode) {
        node->DrawArea->Restored = 0;
    }
}

int TDrawSystem::SetDisplaySize(long p1, long p2, int p3) {
    return 1;
}

// Fully verified. Source of truth: drawarea.cpp.decomp @ 0x004433F0
void TDrawSystem::HandleSize(void* wnd, uint msg, uint wparam, long lparam) {
    (void)wnd;
    (void)msg;
    (void)wparam;
    (void)lparam;

    if (this->DrawArea != nullptr) {
        if (this->DrawType == 1 || this->ScreenMode == 1) {
            RECT wnd_rect;
            GetClientRect((HWND)this->Wnd, &wnd_rect);
            this->ScreenWidth = wnd_rect.right;
            this->ScreenHeight = wnd_rect.bottom;
        }

        if (this->PrimaryArea != nullptr) {
            this->PrimaryArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
        }
        this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
    }
}

// TDrawArea Implementation

TDrawArea::TDrawArea(char* name) {
    memset(this, 0, sizeof(TDrawArea));
    this->TransColor = 0xFF;
    if (name) {
        this->Name = _strdup(name);
    }
}

// Source of truth: Drawarea.cpp.decomp @ TDrawArea::~TDrawArea
TDrawArea::~TDrawArea() {
    // Unlink from DrawSystem's DrawAreaList
    if (this->Node != nullptr) {
        TDrawSystem* ds = this->DrawSystem;
        if (ds != nullptr && this->Node == ds->DrawAreaList) {
            ds->DrawAreaList = this->Node->NextNode;
        }
        if (this->Node->PrevNode != nullptr) {
            this->Node->PrevNode->NextNode = this->Node->NextNode;
        }
        if (this->Node->NextNode != nullptr) {
            this->Node->NextNode->PrevNode = this->Node->PrevNode;
        }
        free(this->Node);
        this->Node = nullptr;
    }

    // Only release DrawSurface if this is NOT the primary (primary is shared)
    if (this->DrawSystem == nullptr || this->DrawSystem->DrawType != 1) {
        if (this->DrawSurface != nullptr && this->IsPrimarySurface == 0) {
            this->DrawSurface->Release();
            this->DrawSurface = nullptr;
        }
    }

    if (this->BitmapInfo != nullptr) {
        free(this->BitmapInfo);
    }
    if (this->DisplayOffsets) {
        free(this->DisplayOffsets);
        this->DisplayOffsets = nullptr;
    }
    if (this->FloatOffsets) {
        free(this->FloatOffsets);
        this->FloatOffsets = nullptr;
    }
    if (this->SpanList) {
        delete this->SpanList;
        this->SpanList = nullptr;
    }
    if (this->Name) {
        free(this->Name);
    }
}

// Source of truth: Drawarea.cpp.decomp @ 0x00444110
// Returns: 0=OK, 1=display mode changed, 2=restored, 3=fatal
uchar TDrawArea::CheckSurface() {
    if (this->DrawSystem != nullptr && this->DrawSystem->DrawType == 2) {
        if (this->DrawSurface == nullptr) {
            return 3;
        }
        HRESULT hr = this->DrawSurface->IsLost();
        if (hr != DD_OK) {
            // Check if display mode changed
            DDSURFACEDESC ddsd;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            HRESULT hr2 = this->DrawSystem->DirDraw->GetDisplayMode(&ddsd);
            if (hr2 == DD_OK &&
                ((int)ddsd.dwWidth != this->DrawSystem->ScreenWidth ||
                 (int)ddsd.dwHeight != this->DrawSystem->ScreenHeight ||
                 (int)ddsd.ddpfPixelFormat.dwRGBBitCount != 8)) {
                return 1;
            }
            hr = this->DrawSurface->Restore();
            if (hr == DD_OK) {
                // Clear after restore
                DDBLTFX ddbltfx;
                memset(&ddbltfx, 0, sizeof(ddbltfx));
                ddbltfx.dwSize = sizeof(ddbltfx);
                ddbltfx.dwFillColor = 0;
                this->DrawSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
                this->Restored = 1;
                return 2;
            }
            // Restore failed — try recreating via SetSize
            if (hr == DDERR_INVALIDOBJECT || hr == DDERR_INVALIDPARAMS) {
                this->DrawSurface->Release();
                this->DrawSurface = nullptr;
                this->SetSize(this->Width, this->Height, 0);
                if (this->DrawSurface != nullptr) {
                    return 2;
                }
            }
            return 3;
        }
    }
    return 0;
}

// Source of truth: Drawarea.cpp.decomp @ 0x00443F60
// Decomp signature: Init(TDrawSystem*, long width, long height, int use_trans, int is_primary)
// Our signature keeps wnd/use_sys_mem for compat but ignores them per decomp
int TDrawArea::Init(TDrawSystem* system, void* wnd, int width, int height, int use_trans, int is_primary, int use_sys_mem) {
    this->DrawSystem = system;
    this->IsPrimarySurface = is_primary;

    if (system != nullptr) {
        this->Wnd = system->Wnd;

        // Link into DrawSystem's DrawAreaList
        if (this->Node == nullptr) {
            DrawAreaNode* node = (DrawAreaNode*)calloc(1, sizeof(DrawAreaNode));
            if (!node) return 0;
            this->Node = node;
            node->DrawArea = this;
            node->PrevNode = nullptr;
            node->NextNode = nullptr;
            DrawAreaNode* list = system->DrawAreaList;
            if (list == nullptr) {
                system->DrawAreaList = node;
            } else {
                while (list->NextNode != nullptr) {
                    list = list->NextNode;
                }
                list->NextNode = node;
                node->PrevNode = list;
            }
        }

        if (system->DrawType == 1) {
            return 0; // WinG not supported
        }
    }

    this->Orien = 1;
    this->SetSize(width, height, 0);
    return 1;
}

// Source of truth: Drawarea.cpp.decomp @ 0x00443600
void TDrawArea::SetSize(long width, long height, int pitch) {
    TDrawSystem* ds = this->DrawSystem;

    // Surface creation/update (only for DirectDraw mode with valid params)
    if (ds != nullptr && ds->DrawType != 1 && ds != nullptr &&
        ds->DirDraw != nullptr && width != 0 && height != 0 &&
        (width != this->Width || height != this->Height || this->DrawSurface == nullptr)) {

        if (width < 1) width = 1;
        if (height < 1) height = 1;

        this->Width = width;
        this->Height = height;

        if (this->IsPrimarySurface == 0) {
            // Back buffer: create offscreen surface
            if (this->DrawSurface != nullptr) {
                this->DrawSurface->Release();
                this->DrawSurface = nullptr;
                memset(&this->SurfaceDesc, 0, sizeof(this->SurfaceDesc));
                this->Pitch = 0;
                this->UsingVidMem = 0;
            }

            DDSURFACEDESC ddsd;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
            ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
            if ((ds->Flags & 1) != 0 || pitch != 0 || this->SystemMemOnly != 0) {
                ddsd.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
            }
            ddsd.dwWidth = width;
            ddsd.dwHeight = height;

            HRESULT hr = ds->DirDraw->CreateSurface(&ddsd, &this->DrawSurface, NULL);
            if (hr == DD_OK) {
                this->SurfaceDesc.dwSize = sizeof(DDSURFACEDESC);
                hr = this->DrawSurface->GetSurfaceDesc(&this->SurfaceDesc);
                if (hr == DD_OK) {
                    this->SetInfo();
                    this->SetAccessOffsets();
                    // Clear the surface
                    DDBLTFX ddbltfx;
                    memset(&ddbltfx, 0, sizeof(ddbltfx));
                    ddbltfx.dwSize = sizeof(ddbltfx);
                    ddbltfx.dwFillColor = 0;
                    this->DrawSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
                }
            }
        } else {
            // Primary area: reuse the DD primary surface
            this->DrawSurface = ds->PrimarySurface;
        }

        this->SetClipRect((tagRECT*)nullptr);
        this->Clear(nullptr, 0);
    } else {
        this->Width = width;
        this->Height = height;
    }

    // SpanList setup
    if (this->SpanList) {
        delete this->SpanList;
        this->SpanList = nullptr;
    }
    this->SpanList = new TSpan_List_Manager((int)width, (int)height);
    if (this->SpanList && height > 0) {
        for (int y = 0; y < (int)height; ++y) {
            this->SpanList->AddSpan(0, (int)width - 1, y);
        }
    }
    this->CurSpanList = this->SpanList;
}

void TDrawArea::SetFloatOffsets(int p1, int p2) {
    // Source of truth: `Drawarea.cpp.decomp` / `Drawarea.cpp.asm`.
    int bytes = this->Height << 2;
    if (((bytes != 0) && (this->ExtendedLines != 0)) && (-1 < p1) && (-1 < p2)) {
        if (bytes != this->FloatOffsetsSz) {
            if (this->FloatOffsets) {
                free(this->FloatOffsets);
            }
            this->FloatOffsets = (void**)malloc((size_t)bytes);
            this->FloatOffsetsSz = bytes;
        }

        int out_i = 0;
        int y = p2;
        if (0 < this->Height) {
            do {
                uchar* base = (uchar*)this->DisplayOffsets[y];
                this->FloatOffsets[out_i] = (void*)(base + p1);
                y = y + 1;
                if (this->Height <= y) y = 0;
                out_i = out_i + 1;
            } while (out_i < this->Height);
        }

        this->Float_X_Delta = p1;
        this->Float_Y_Delta = p2;
        this->CurDisplayOffsets = this->FloatOffsets;
    }
}

void TDrawArea::Clear(tagRECT* rect, int color) {
    if (!this->DrawSurface) return;

    // AoE UI code primarily uses 8-bit palette indices for colors. On modern systems we may be running
    // a 16/32-bit surface; map palette index -> pixel value when possible.
    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    HRESULT sdesc_hr = this->DrawSurface->GetSurfaceDesc(&ddsd);
    (void)sdesc_hr;

    DDBLTFX ddbltfx;
    memset(&ddbltfx, 0, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = map_color_index_to_surface_pixel(this, color, &ddsd, sdesc_hr);
    if (!rect) {
        this->DrawSurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
        return;
    }

    // `tagRECT` is inclusive in AoE code; DirectDraw expects exclusive right/bottom.
    RECT dr;
    dr.left = rect->left;
    dr.top = rect->top;
    dr.right = rect->right + 1;
    dr.bottom = rect->bottom + 1;
    this->DrawSurface->Blt(&dr, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
}

void TDrawArea::PtrClear(tagRECT* rect, int color) {}
void TDrawArea::OverlayMemCopy(tagRECT* rect, TDrawArea* src, int x, int y) {}

// Source of truth: Drawarea.cpp.decomp @ 0x00444270
uchar* TDrawArea::Lock(char* name, int p2) {
    if (this->DrawSystem != nullptr && this->DrawSystem->DrawType == 1) {
        return this->Bits; // WinG path
    }
    if (this->DrawSurface == nullptr) return nullptr;
    if (this->Bits != nullptr) return this->Bits;
    if (this->DrawDc != nullptr) return nullptr;

    // DirectDraw requires dwSize be set before calling Lock/GetSurfaceDesc.
    this->SurfaceDesc.dwSize = sizeof(DDSURFACEDESC);
    HRESULT hr = this->DrawSurface->Lock(NULL, &this->SurfaceDesc, (name != nullptr) ? 1 : 0, NULL);
    if (hr != DD_OK) return nullptr;

    this->Bits = (uchar*)this->SurfaceDesc.lpSurface;
    this->SetInfo();
    if (this->Bits != this->LastBits) {
        this->SetAccessOffsets();
    }
    return this->Bits;
}

// Source of truth: Drawarea.cpp.decomp @ 0x00444300
void TDrawArea::Unlock(char* name) {
    if (this->DrawSystem != nullptr && this->DrawSystem->DrawType == 1) return;
    if (this->DrawSurface != nullptr && this->Bits != nullptr) {
        this->DrawSurface->Unlock(this->Bits);
        this->Bits = nullptr;
    }
}

// Fully verified. Source of truth: drawarea.cpp.decomp @ 0x00445710
void TDrawArea::SetTrans(int enabled, uchar trans_color) {
    this->UseTrans = enabled;
    if (enabled == 0) {
        this->TransColor = 0xFF;
    } else {
        this->TransColor = trans_color;
    }

    if (enabled != 0) {
        IDirectDrawSurface* surf = this->DrawSurface;
        if (surf != nullptr && this->DrawSystem != nullptr && this->DrawSystem->DrawType == 2) {
            DDCOLORKEY ddck;
            ddck.dwColorSpaceLowValue = (DWORD)this->TransColor;
            ddck.dwColorSpaceHighValue = (DWORD)this->TransColor;
            surf->SetColorKey(DDCKEY_SRCBLT, &ddck);
        }
    }
}

void TDrawArea::SetInfo() {
    // Source of truth: `Drawarea.cpp.decomp` / `.asm`.
    this->Pitch = (int)this->SurfaceDesc.lPitch;

    if (this->BitmapInfo) {
        // Note: Original sets biWidth to pitch (bytes per scanline), not `this->Width`.
        this->BitmapInfo->bmiHeader.biWidth = (long)this->Pitch;
    }

    if (((this->SurfaceDesc).ddsCaps.dwCaps & 0x800) != 0) {
        this->UsingVidMem = 0;
        return;
    }
    this->UsingVidMem = 1;
}

void TDrawArea::SetAccessOffsets() {
    // Source of truth: `Drawarea.cpp.decomp` / `.asm`.
    int bytes = this->Height << 2;
    if (bytes != this->DisplayOffsetsSz) {
        if (this->DisplayOffsets) {
            free(this->DisplayOffsets);
        }
        this->DisplayOffsets = (void**)malloc((size_t)bytes);
        this->DisplayOffsetsSz = bytes;
        this->CurDisplayOffsets = this->DisplayOffsets;
    }

    uchar* line_ptr;
    int delta;

    if ((this->Orien == 1) || (this->ExtendedLines != 0)) {
        if (this->ExtendedLines == 0) {
            line_ptr = this->Bits;
        } else {
            line_ptr = this->Bits + this->Pitch * 5;
        }
        delta = this->Pitch;
        if (this->ExtendedLines != 0) {
            delta = this->Width;
        }
    } else {
        line_ptr = this->Bits + (this->Height - 1) * this->Pitch;
        delta = -this->Pitch;
    }

    for (int i = 0; i < this->Height; ++i) {
        this->DisplayOffsets[i] = line_ptr;
        line_ptr = line_ptr + delta;
    }

    if (this->FloatOffsets) {
        this->SetFloatOffsets(this->Float_X_Delta, this->Float_Y_Delta);
    }

    this->LastBits = this->Bits;
}

void TDrawArea::PtrSpanCopy(TDrawArea* src, int x, int y) {}
void TDrawArea::DrawLine(int x1, int y1, int x2, int y2, uchar color) {}

static void normalize_inclusive(long* a, long* b) {
    if (!a || !b) return;
    if (*a > *b) {
        long t = *a;
        *a = *b;
        *b = t;
    }
}

void TDrawArea::FillRect(long left, long top, long right, long bottom, uchar color) {
    int locked_here = 0;
    if (!this->Bits) {
        if (!this->Lock((char*)"TDrawArea::FillRect", 0)) return;
        locked_here = 1;
    }

    long x2 = right;
    if (right < left) {
        x2 = left;
        left = right;
    }
    long y1 = top;
    if (bottom < top) {
        y1 = bottom;
        bottom = top;
    }

    if ((left <= this->ClipRect.right) && (this->ClipRect.left <= x2) &&
        (y1 <= this->ClipRect.bottom) && (this->ClipRect.top <= bottom)) {
        if (left < this->ClipRect.left) left = this->ClipRect.left;
        if (x2 > this->ClipRect.right) x2 = this->ClipRect.right;
        if (y1 < this->ClipRect.top) y1 = this->ClipRect.top;
        if (bottom > this->ClipRect.bottom) bottom = this->ClipRect.bottom;

        int w = (int)((x2 - left) + 1);
        int h = (int)((bottom - y1) + 1);
        if ((0 < w) && (0 < h)) {
            int bytes_per_pixel = drawarea_bytes_per_pixel(this);
            unsigned long px = drawarea_index_to_pixel_locked(this, color);
            int delta;
            int base_off;
            if (this->Orien == 1) {
                delta = this->Pitch;
                base_off = (int)(y1 * delta);
            } else {
                base_off = (int)(((this->Height - y1) - 1) * this->Pitch);
                delta = -this->Pitch;
            }

            uchar* p = this->Bits + base_off + left * bytes_per_pixel;
            while (h-- > 0) {
                drawarea_fill_run(p, w, bytes_per_pixel, px);
                p = p + delta;
            }
        }
    }

    if (locked_here) {
        this->Unlock((char*)"TDrawArea::FillRect");
    }
}

void TDrawArea::SaveBitmap(char* filename) {
    if (!this->DrawSurface) {
         CUSTOM_DEBUG_LOG("SaveBitmap: No DrawSurface");
         return;
    }

    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    HRESULT hr = this->DrawSurface->Lock(NULL, &ddsd, DDLOCK_WAIT | DDLOCK_READONLY, NULL);
    if (FAILED(hr)) {
        CUSTOM_DEBUG_LOG_FMT("SaveBitmap: Lock failed hr=0x%x", hr);
        return;
    }

    int width = ddsd.dwWidth;
    int height = ddsd.dwHeight;
    int depth = ddsd.ddpfPixelFormat.dwRGBBitCount;
    int pitch = ddsd.lPitch;
    void* bits = ddsd.lpSurface;
    
    // Support 8-bit and 32-bit
    if (depth != 8 && depth != 32) {
         CUSTOM_DEBUG_LOG_FMT("SaveBitmap: Unsupported depth %d", depth);
         this->DrawSurface->Unlock(NULL);
         return;
    }

    FILE* f = fopen(filename, "wb");
    if (!f) {
         CUSTOM_DEBUG_LOG_FMT("SaveBitmap: Failed to open %s", filename);
         this->DrawSurface->Unlock(NULL);
         return;
    }

    // Bitmap Header
    BITMAPFILEHEADER bmfh;
    BITMAPINFOHEADER bmih;
    
    memset(&bmfh, 0, sizeof(bmfh));
    memset(&bmih, 0, sizeof(bmih));

    bmih.biSize = sizeof(bmih);
    bmih.biWidth = width;
    bmih.biHeight = -height; // Top-down
    bmih.biPlanes = 1;
    bmih.biBitCount = depth; // 8 or 32
    bmih.biCompression = BI_RGB;
    bmih.biSizeImage = (width * depth / 8) * height; // Rough estimate, actual size includes padding

    // Palette handling
    int paletteSize = 0;
    if (depth == 8) {
        paletteSize = 256 * 4; // RGBQUAD
    }

    bmfh.bfType = 0x4D42; // BM
    bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + paletteSize;
    bmfh.bfSize = bmfh.bfOffBits + bmih.biSizeImage;

    fwrite(&bmfh, sizeof(bmfh), 1, f);
    fwrite(&bmih, sizeof(bmih), 1, f);

    // Write Palette (only for 8-bit)
    if (depth == 8) {
        PALETTEENTRY palEntries[256];
        memset(palEntries, 0, sizeof(palEntries));
        
        if (this->DrawSystem && this->DrawSystem->DirDrawPal) {
            this->DrawSystem->DirDrawPal->GetEntries(0, 0, 256, palEntries);
        } else {
            for(int i=0; i<256; i++) {
                palEntries[i].peRed = i;
                palEntries[i].peGreen = i;
                palEntries[i].peBlue = i;
            }
        }

        for(int i=0; i<256; i++) {
            RGBQUAD rgb;
            rgb.rgbBlue = palEntries[i].peBlue;
            rgb.rgbGreen = palEntries[i].peGreen;
            rgb.rgbRed = palEntries[i].peRed;
            rgb.rgbReserved = 0;
            fwrite(&rgb, sizeof(rgb), 1, f);
        }
    }

    // Write Data
    uchar* line = (uchar*)bits;
    int bytesPerPixel = depth / 8;
    int rowBytes = width * bytesPerPixel;
    int pad = (4 - (rowBytes % 4)) % 4;

    for (int y = 0; y < height; y++) {
         fwrite(line, 1, rowBytes, f);
         if (pad > 0) {
             uchar zeroes[4] = {0};
             fwrite(zeroes, 1, pad, f);
         }
         line += pitch;
    }

    fclose(f);
    this->DrawSurface->Unlock(NULL);
    CUSTOM_DEBUG_LOG_FMT("SaveBitmap: Saved to %s (%dx%d @ %dbpp)", filename, width, height, depth);
}

void TDrawArea::DrawHorzLine(long x, long y, long len, uchar color) {
    int locked_here = 0;
    if (!this->Bits) {
        if (!this->Lock((char*)"TDrawArea::DrawHorzLine", 0)) return;
        locked_here = 1;
    }
    if (x > this->ClipRect.right) {
        if (locked_here) this->Unlock((char*)"TDrawArea::DrawHorzLine");
        return;
    }
    if (y < this->ClipRect.top || y > this->ClipRect.bottom) {
        if (locked_here) this->Unlock((char*)"TDrawArea::DrawHorzLine");
        return;
    }

    long clip_r = this->ClipRect.right;
    long clip_l = this->ClipRect.left;

    if (x < clip_l) {
        len = len + (x - clip_l);
        x = clip_l;
    }
    if (clip_r < (len - 1 + x)) {
        len = (clip_r - x) + 1;
    }
    if (len <= 0) {
        if (locked_here) this->Unlock((char*)"TDrawArea::DrawHorzLine");
        return;
    }

    int off;
    if (this->Orien == 1) off = (int)(this->Pitch * y);
    else off = (int)(((this->Height - y) - 1) * this->Pitch);

    int bytes_per_pixel = drawarea_bytes_per_pixel(this);
    unsigned long px = drawarea_index_to_pixel_locked(this, color);
    drawarea_fill_run(this->Bits + off + x * bytes_per_pixel, (int)len, bytes_per_pixel, px);
    if (locked_here) {
        this->Unlock((char*)"TDrawArea::DrawHorzLine");
    }
}

void TDrawArea::DrawVertLine(long x, long y, long len, uchar color) {
    int locked_here = 0;
    if (!this->Bits) {
        if (!this->Lock((char*)"TDrawArea::DrawVertLine", 0)) return;
        locked_here = 1;
    }
    if (x < this->ClipRect.left || x > this->ClipRect.right) {
        if (locked_here) this->Unlock((char*)"TDrawArea::DrawVertLine");
        return;
    }
    if (y > this->ClipRect.bottom) {
        if (locked_here) this->Unlock((char*)"TDrawArea::DrawVertLine");
        return;
    }

    long clip_b = this->ClipRect.bottom;
    long clip_t = this->ClipRect.top;

    if (y < clip_t) {
        len = len + (y - clip_t);
        y = clip_t;
    }
    if (clip_b < (len - 1 + y)) {
        len = (clip_b - y) + 1;
    }
    if (len <= 0) {
        if (locked_here) this->Unlock((char*)"TDrawArea::DrawVertLine");
        return;
    }

    int delta;
    int base_off;
    int bytes_per_pixel = drawarea_bytes_per_pixel(this);
    unsigned long px = drawarea_index_to_pixel_locked(this, color);
    if (this->Orien == 1) {
        delta = this->Pitch;
        base_off = (int)(y * delta);
    } else {
        base_off = (int)(((this->Height - y) - 1) * this->Pitch);
        delta = -this->Pitch;
    }

    uchar* p = this->Bits + base_off + x * bytes_per_pixel;
    while (len-- > 0) {
        drawarea_store_pixel(p, bytes_per_pixel, px);
        p = p + delta;
    }
    if (locked_here) {
        this->Unlock((char*)"TDrawArea::DrawVertLine");
    }
}

// Source of truth: Drawarea.cpp.decomp @ 0x004457E0
void TDrawArea::SetPixel(long x, long y, uchar color) {
    if (!this->Bits) return;
    if (x < this->ClipRect.left || x > this->ClipRect.right) return;
    if (y < this->ClipRect.top || y > this->ClipRect.bottom) return;

    int bytes_per_pixel = drawarea_bytes_per_pixel(this);
    unsigned long px = drawarea_index_to_pixel_locked(this, color);

    int off;
    if (this->Orien == 1) {
        off = (int)(this->Pitch * y);
    } else {
        off = (int)(((this->Height - y) - 1) * this->Pitch);
    }

    drawarea_store_pixel(this->Bits + off + x * bytes_per_pixel, bytes_per_pixel, px);
}

void TDrawArea::DrawRect(long x1, long y1, long x2, long y2, uchar color) {
    normalize_inclusive(&x1, &x2);
    normalize_inclusive(&y1, &y2);
    int w = (int)((x2 - x1) + 1);
    int h = (int)((y2 - y1) + 1);
    if (w <= 0 || h <= 0) return;
    this->DrawHorzLine(x1, y1, w, color);
    this->DrawHorzLine(x1, y2, w, color);
    this->DrawVertLine(x1, y1, h, color);
    this->DrawVertLine(x2, y1, h, color);
}

void TDrawArea::DrawRect(tagRECT* rect, uchar color) {
    if (!rect) return;
    this->DrawRect(rect->left, rect->top, rect->right, rect->bottom, color);
}

void TDrawArea::DrawBevel(long x1, long y1, long x2, long y2, uchar c_tl, uchar c_br) {
    normalize_inclusive(&x1, &x2);
    normalize_inclusive(&y1, &y2);
    int w = (int)((x2 - x1) + 1);
    int h_minus_1 = (int)(y2 - y1);
    if (w <= 0 || (h_minus_1 + 1) <= 0) return;

    this->DrawHorzLine(x1 + 1, y1, (x2 - x1), c_tl);
    this->DrawVertLine(x2, y1 + 1, h_minus_1, c_tl);
    this->DrawHorzLine(x1, y2, w, c_br);
    this->DrawVertLine(x1, y1, h_minus_1, c_br);
}

void TDrawArea::DrawBevel2(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4) {
    normalize_inclusive(&x1, &x2);
    normalize_inclusive(&y1, &y2);

    int w_minus_1 = (int)(x2 - x1);
    int h_minus_1 = (int)(y2 - y1);
    if ((w_minus_1 + 1) <= 0 || (h_minus_1 + 1) <= 0) return;

    long x1p1 = x1 + 1;
    this->DrawHorzLine(x1p1, y1, w_minus_1, c1);
    long y1p1 = y1 + 1;
    this->DrawVertLine(x2, y1p1, h_minus_1 - 1, c1);
    this->DrawHorzLine(x1 + 2, y1p1, w_minus_1 - 2, c2);
    this->DrawVertLine(x2 - 1, y1 + 2, h_minus_1 - 3, c2);
    this->DrawHorzLine(x1, y2, w_minus_1 + 1, c4);
    this->DrawVertLine(x1, y1, h_minus_1, c4);
    this->DrawHorzLine(x1p1, y2 - 1, w_minus_1 - 1, c3);
    this->DrawVertLine(x1p1, y1p1, h_minus_1 - 2, c3);
}

void TDrawArea::DrawBevel21(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4) {
    normalize_inclusive(&x1, &x2);
    normalize_inclusive(&y1, &y2);

    int w_minus_1 = (int)(x2 - x1);
    int h_minus_1 = (int)(y2 - y1);
    if ((w_minus_1 + 1) <= 0 || (h_minus_1 + 1) <= 0) return;

    this->DrawHorzLine(x1 + 1, y1, w_minus_1, c1);
    this->DrawVertLine(x2, y1 + 1, h_minus_1 - 1, c1);
    this->DrawHorzLine(x1 + 1, y1 + 1, w_minus_1 - 1, c2);
    this->DrawVertLine(x2 - 1, y1 + 2, h_minus_1 - 2, c2);
    this->DrawHorzLine(x1, y2, w_minus_1 + 1, c4);
    this->DrawVertLine(x1, y1, h_minus_1, c4);
}

void TDrawArea::DrawBevel3(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4, uchar c5, uchar c6) {
    normalize_inclusive(&x1, &x2);
    normalize_inclusive(&y1, &y2);

    int w_minus_1 = (int)(x2 - x1);
    int h_minus_1 = (int)(y2 - y1);
    if ((w_minus_1 + 1) <= 0 || (h_minus_1 + 1) <= 0) return;

    long x1p1 = x1 + 1;
    this->DrawHorzLine(x1p1, y1, w_minus_1, c1);
    long y1p1 = y1 + 1;
    this->DrawVertLine(x2, y1p1, h_minus_1 - 1, c1);

    long x1p2 = x1 + 2;
    this->DrawHorzLine(x1p2, y1p1, w_minus_1 - 2, c2);
    long y1p2 = y1 + 2;
    this->DrawVertLine(x2 - 1, y1p2, h_minus_1 - 3, c2);

    this->DrawHorzLine(x1 + 3, y1 + 2, w_minus_1 - 4, c3);
    this->DrawVertLine(x2 - 2, y1 + 3, h_minus_1 - 5, c3);

    this->DrawHorzLine(x1, y2, w_minus_1 + 1, c6);
    this->DrawVertLine(x1, y1, h_minus_1, c6);

    this->DrawHorzLine(x1p1, y2 - 1, w_minus_1 - 1, c5);
    this->DrawVertLine(x1p1, y1p1, h_minus_1 - 2, c5);

    this->DrawHorzLine(x1p2, y2 - 2, w_minus_1 - 3, c4);
    this->DrawVertLine(x1p2, y1p2, h_minus_1 - 4, c4);
}

void TDrawArea::DrawBevel32(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4, uchar c5, uchar c6) {
    normalize_inclusive(&x1, &x2);
    normalize_inclusive(&y1, &y2);

    int w_minus_1 = (int)(x2 - x1);
    int h_minus_1 = (int)(y2 - y1);
    if ((w_minus_1 + 1) <= 0 || (h_minus_1 + 1) <= 0) return;

    long x1p1 = x1 + 1;
    this->DrawHorzLine(x1p1, y1, w_minus_1, c1);
    long y1p1 = y1 + 1;
    this->DrawVertLine(x2, y1p1, h_minus_1 - 1, c1);
    this->DrawHorzLine(x1 + 2, y1p1, w_minus_1 - 2, c2);
    this->DrawVertLine(x2 - 1, y1 + 2, h_minus_1 - 3, c2);
    this->DrawHorzLine(x1 + 2, y1 + 2, w_minus_1 - 3, c3);
    this->DrawVertLine(x2 - 2, y1 + 3, h_minus_1 - 4, c3);
    this->DrawHorzLine(x1, y2, w_minus_1 + 1, c6);
    this->DrawVertLine(x1, y1, h_minus_1, c6);
    this->DrawHorzLine(x1p1, y2 - 1, w_minus_1 - 1, c5);
    this->DrawVertLine(x1p1, y1p1, h_minus_1 - 2, c5);
}

void* TDrawArea::GetDc(char* name) {
    if (!this->DrawSurface) return nullptr;

    HDC hdc = nullptr;
    HRESULT hr = this->DrawSurface->GetDC(&hdc);
    if (hr == DDERR_SURFACELOST) {
        if (this->DrawSurface->Restore() == DD_OK) {
            hr = this->DrawSurface->GetDC(&hdc);
        }
    }

    if (SUCCEEDED(hr)) {
        if (this->DrawSystem && this->DrawSystem->Pal) {
            SelectPalette(hdc, (HPALETTE)this->DrawSystem->Pal, FALSE);
            RealizePalette(hdc);
        }
        this->DrawDc = hdc;
        return hdc;
    }

    CUSTOM_DEBUG_LOG_FMT("TDrawArea::GetDc: Failed to get DC from surface hr=0x%x", hr);
    return nullptr;
}

long TDrawArea::AlignedWidth() {
    // Source of truth: `Drawarea.cpp.decomp` returns `this->Pitch`.
    return (long)this->Pitch;
}

void TDrawArea::SetClipRect(tagRECT* rect) {
    if (!rect) {
        this->ClipRect.left = 0;
        this->ClipRect.top = 0;
        this->ClipRect.right = this->Width - 1;
        this->ClipRect.bottom = this->Height - 1;
    } else {
        this->ClipRect = *rect;

        long l = this->ClipRect.left;
        if (l < 0) this->ClipRect.left = 0;
        else {
            long max_x = this->Width - 1;
            if (max_x < l) this->ClipRect.left = max_x;
        }

        long r = this->ClipRect.right;
        if (r < 0) this->ClipRect.right = 0;
        else {
            long max_x = this->Width - 1;
            if (max_x < r) this->ClipRect.right = max_x;
        }

        long t = this->ClipRect.top;
        if (t < 0) this->ClipRect.top = 0;
        else {
            long max_y = this->Height - 1;
            if (max_y < t) this->ClipRect.top = max_y;
        }

        long b = this->ClipRect.bottom;
        if (b < 0) this->ClipRect.bottom = 0;
        else {
            long max_y = this->Height - 1;
            if (max_y < b) this->ClipRect.bottom = max_y;
        }

        if (this->ClipRect.right < this->ClipRect.left) {
            long swap = this->ClipRect.left;
            this->ClipRect.left = this->ClipRect.right;
            this->ClipRect.right = swap;
        }
        if (this->ClipRect.bottom < this->ClipRect.top) {
            long swap = this->ClipRect.top;
            this->ClipRect.top = this->ClipRect.bottom;
            this->ClipRect.bottom = swap;
        }
    }

    // Source of truth: `Drawarea.cpp.decomp` calls through to the long overload.
    this->SetClipRect(this->ClipRect.left, this->ClipRect.top, this->ClipRect.right, this->ClipRect.bottom);
}

void TDrawArea::SetClipRect(long left, long top, long right, long bottom) {
    this->ClipRect.left = left;
    this->ClipRect.top = top;
    this->ClipRect.right = right;
    this->ClipRect.bottom = bottom;

    // SpanList sync (source of truth: `Drawarea.cpp.decomp` / `.asm`).
    if (this->SpanList && this->Height != this->SpanList->Num_Lines) {
        delete this->SpanList;
        this->SpanList = nullptr;
    }
    if (!this->SpanList) {
        this->SpanList = new TSpan_List_Manager(this->Width, this->Height);
    }

    if (this->SpanList) {
        this->SpanList->ResetAll();
        this->SpanList->SetSpanRegions((int)this->ClipRect.left, (int)this->ClipRect.top, (int)this->ClipRect.right, (int)this->ClipRect.bottom);
        for (int y = (int)this->ClipRect.top; y <= (int)this->ClipRect.bottom; ++y) {
            this->SpanList->AddSpan((int)this->ClipRect.left, (int)this->ClipRect.right, y);
        }
    }
    this->CurSpanList = this->SpanList;
}

void TDrawArea::Copy(TDrawArea* dest, long x, long y, tagRECT* src_rect, int flags) {
    if (!dest) return;
    if (!this->DrawSurface || !dest->DrawSurface) return;

    tagRECT s;
    if (src_rect) {
        s = *src_rect;
    } else {
        s.left = 0;
        s.top = 0;
        s.right = this->Width - 1;
        s.bottom = this->Height - 1;
    }

    if (s.left > s.right) {
        long t = s.left; s.left = s.right; s.right = t;
    }
    if (s.top > s.bottom) {
        long t = s.top; s.top = s.bottom; s.bottom = t;
    }

    long w = (s.right - s.left) + 1;
    long h = (s.bottom - s.top) + 1;
    if (w <= 0 || h <= 0) return;

    // Destination rect (inclusive).
    tagRECT d;
    d.left = x;
    d.top = y;
    d.right = x + w - 1;
    d.bottom = y + h - 1;

    // Clip to destination clip rect.
    long cl = dest->ClipRect.left;
    long ct = dest->ClipRect.top;
    long cr = dest->ClipRect.right;
    long cb = dest->ClipRect.bottom;

    if (d.right < cl || d.bottom < ct || d.left > cr || d.top > cb) return;

    if (d.left < cl) {
        long delta = cl - d.left;
        d.left += delta;
        s.left += delta;
    }
    if (d.top < ct) {
        long delta = ct - d.top;
        d.top += delta;
        s.top += delta;
    }
    if (d.right > cr) {
        long delta = d.right - cr;
        d.right -= delta;
        s.right -= delta;
    }
    if (d.bottom > cb) {
        long delta = d.bottom - cb;
        d.bottom -= delta;
        s.bottom -= delta;
    }

    // Clip to source bounds.
    if (s.left < 0) {
        long delta = -s.left;
        s.left = 0;
        d.left += delta;
    }
    if (s.top < 0) {
        long delta = -s.top;
        s.top = 0;
        d.top += delta;
    }
    if (s.right >= this->Width) {
        long delta = s.right - (this->Width - 1);
        s.right -= delta;
        d.right -= delta;
    }
    if (s.bottom >= this->Height) {
        long delta = s.bottom - (this->Height - 1);
        s.bottom -= delta;
        d.bottom -= delta;
    }

    if (s.left > s.right || s.top > s.bottom) return;
    if (d.left > d.right || d.top > d.bottom) return;

    RECT sr;
    sr.left = s.left;
    sr.top = s.top;
    sr.right = s.right + 1;
    sr.bottom = s.bottom + 1;

    RECT dr;
    dr.left = d.left;
    dr.top = d.top;
    dr.right = d.right + 1;
    dr.bottom = d.bottom + 1;

    DWORD blt_flags = DDBLT_WAIT;
    if ((this->UseTrans != 0) && (flags != 0)) {
        blt_flags |= DDBLT_KEYSRC;
    }
    dest->DrawSurface->Blt(&dr, this->DrawSurface, &sr, blt_flags, NULL);
}

void TDrawArea::SetShadowTable(RGE_Color_Table* table) {
    this->shadow_color_table = table;
}

void TDrawArea::DrawShadowBox(long left, long top, long right, long bottom) {
    if (!this->shadow_color_table) return;
    if (!this->Bits) return;

    if (left > right) {
        long t = left; left = right; right = t;
    }
    if (top > bottom) {
        long t = top; top = bottom; bottom = t;
    }

    long cl = this->ClipRect.left;
    long ct = this->ClipRect.top;
    long cr = this->ClipRect.right;
    long cb = this->ClipRect.bottom;

    if (left < cl) left = cl;
    if (top < ct) top = ct;
    if (right > cr) right = cr;
    if (bottom > cb) bottom = cb;

    if (left < 0) left = 0;
    if (top < 0) top = 0;
    if (right >= this->Width) right = this->Width - 1;
    if (bottom >= this->Height) bottom = this->Height - 1;
    if (left > right || top > bottom) return;

    // Determine surface format.
    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    HRESULT sdesc_hr = DDERR_GENERIC;
    if (this->DrawSurface) sdesc_hr = this->DrawSurface->GetSurfaceDesc(&ddsd);

    unsigned long bpp = 8;
    if (sdesc_hr == DD_OK) bpp = ddsd.ddpfPixelFormat.dwRGBBitCount;
    int bytes_per_pixel = (int)(bpp / 8);
    if (bytes_per_pixel <= 0) bytes_per_pixel = 1;

    if (bpp <= 8) {
        // 8bpp palette-index mapping (original behavior).
        for (long y = top; y <= bottom; ++y) {
            uchar* row = this->Bits + y * this->Pitch;
            for (long x = left; x <= right; ++x) {
                row[x] = this->shadow_color_table->table[row[x]];
            }
        }
        return;
    }

    // 16/32bpp fallback: apply a simple darkening. We store the percent in `RGE_Color_Table::id`
    // for the runtime-generated shadow table (non-original but contained to this reimplementation).
    int percent = (int)this->shadow_color_table->id;
    if (percent < 0) percent = 0;
    if (percent > 100) percent = 100;
    int keep = 100 - percent;

    unsigned long rmask = (sdesc_hr == DD_OK) ? ddsd.ddpfPixelFormat.dwRBitMask : 0x00FF0000;
    unsigned long gmask = (sdesc_hr == DD_OK) ? ddsd.ddpfPixelFormat.dwGBitMask : 0x0000FF00;
    unsigned long bmask = (sdesc_hr == DD_OK) ? ddsd.ddpfPixelFormat.dwBBitMask : 0x000000FF;

    int rshift = 0, gshift = 0, bshift = 0;
    while (rmask && ((rmask >> rshift) & 1) == 0) rshift++;
    while (gmask && ((gmask >> gshift) & 1) == 0) gshift++;
    while (bmask && ((bmask >> bshift) & 1) == 0) bshift++;

    unsigned long rmax = rmask ? (rmask >> rshift) : 0xFF;
    unsigned long gmax = gmask ? (gmask >> gshift) : 0xFF;
    unsigned long bmax = bmask ? (bmask >> bshift) : 0xFF;

    for (long y = top; y <= bottom; ++y) {
        uchar* row = this->Bits + y * this->Pitch;
        for (long x = left; x <= right; ++x) {
            unsigned long px = 0;
            memcpy(&px, row + x * bytes_per_pixel, (size_t)bytes_per_pixel);

            unsigned long r = (rmask ? ((px & rmask) >> rshift) : ((px >> 16) & 0xFF));
            unsigned long g = (gmask ? ((px & gmask) >> gshift) : ((px >> 8) & 0xFF));
            unsigned long b = (bmask ? ((px & bmask) >> bshift) : (px & 0xFF));

            r = (r * (unsigned long)keep) / 100;
            g = (g * (unsigned long)keep) / 100;
            b = (b * (unsigned long)keep) / 100;

            if (r > rmax) r = rmax;
            if (g > gmax) g = gmax;
            if (b > bmax) b = bmax;

            unsigned long out = px;
            if (rmask) out = (out & ~rmask) | ((r << rshift) & rmask);
            else out = (out & 0xFF00FFFF) | ((r & 0xFF) << 16);
            if (gmask) out = (out & ~gmask) | ((g << gshift) & gmask);
            else out = (out & 0xFFFF00FF) | ((g & 0xFF) << 8);
            if (bmask) out = (out & ~bmask) | ((b << bshift) & bmask);
            else out = (out & 0xFFFFFF00) | (b & 0xFF);

            memcpy(row + x * bytes_per_pixel, &out, (size_t)bytes_per_pixel);
        }
    }
}

void TDrawArea::GetPalette(tagPALETTEENTRY* out_entries) {
    if (!out_entries) return;
    if (!this->DrawSystem) {
        memset(out_entries, 0, sizeof(tagPALETTEENTRY) * 256);
        return;
    }
    memcpy(out_entries, this->DrawSystem->palette, sizeof(tagPALETTEENTRY) * 256);
}

void TDrawArea::SetPalette(tagPALETTEENTRY* entries) {
    if (!entries) return;
    if (this->DrawSystem) {
        this->DrawSystem->ModifyPalette(0, 256, entries);
    }
}

void TDrawArea::ReleaseDc(char* name) {
    if (this->DrawSurface && this->DrawDc) {
        this->DrawSurface->ReleaseDC((HDC)this->DrawDc);
        this->DrawDc = nullptr;
    }
}

// Fully verified. Source of truth: drawarea.cpp.decomp/.asm @ 0x004463B0
void TDrawArea::take_snapshot(char* filename_fmt, int* snapshot_number) {
    // Matches original implementation: 8-bit paletted BMP with DWORD-aligned scanlines.
    unsigned int bmWide = ((unsigned int)this->Width + 3u) & 0xFFFFFFFCu;

    BITMAPFILEHEADER bmFH;
    BITMAPINFOHEADER bmIH;
    char BMPFile[60];
    RGBQUAD bmPAL[257];
    tagPALETTEENTRY thePal[257];

    bmIH.biSize = 0x28;
    bmIH.biWidth = this->Width;
    bmIH.biHeight = this->Height;
    bmIH.biPlanes = 1;
    bmIH.biBitCount = 8;
    bmIH.biCompression = BI_RGB;
    bmIH.biSizeImage = 0;
    bmIH.biXPelsPerMeter = 0;
    bmIH.biYPelsPerMeter = 0;
    bmIH.biClrUsed = 0;
    bmIH.biClrImportant = 0;

    memset(&bmFH, 0, sizeof(bmFH));
    bmFH.bfType = 0x4D42; // 'BM'
    bmFH.bfOffBits = 0x436;
    bmFH.bfSize = (DWORD)(this->Height * (int)bmWide + 0x436);

    BMPFile[0] = '\0';
    BMPFile[1] = '\0';
    BMPFile[2] = '\0';
    BMPFile[3] = '\0';

    this->GetPalette(thePal + 1);

    int iVar4 = 0;
    do {
        unsigned char g = (&thePal[1].peGreen)[iVar4];
        (&bmPAL[1].rgbBlue)[iVar4] = (&thePal[1].peBlue)[iVar4];
        unsigned char r = (&thePal[1].peRed)[iVar4];
        (&bmPAL[1].rgbGreen)[iVar4] = g;
        (&bmPAL[1].rgbRed)[iVar4] = r;
        (&bmPAL[1].rgbReserved)[iVar4] = '\0';
        iVar4 = iVar4 + 4;
    } while (iVar4 < 0x400);

    iVar4 = 0;
    while (true) {
        char* pcVar10;
        int iVar5 = *snapshot_number;
        if (filename_fmt == (char*)0x0) {
            pcVar10 = (char*)"C:\\AOE_%03d.BMP";
        } else {
            pcVar10 = filename_fmt;
        }

        sprintf(BMPFile + 4, pcVar10, iVar5);
        iVar4 = iVar4 + 1;
        int h = _open(BMPFile + 4, 0);
        if (h == -1) break;
        *snapshot_number = *snapshot_number + 1;
        _close(h);
        if (1000 < iVar4) {
            return;
        }
    }

    unsigned char* line_buf = (unsigned char*)malloc((size_t)bmWide);
    int out = _open(BMPFile + 4, _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC, _S_IREAD | _S_IWRITE);
    if (out != -1) {
        _write(out, &bmFH, 0xE);
        _write(out, &bmIH, 0x28);
        _write(out, bmPAL + 1, 0x400);

        unsigned char* locked = this->Lock((char*)"take_snapshot", 1);
        int iVar3 = this->Height;
        if (locked != (unsigned char*)0x0) {
            while (iVar3 = iVar3 + -1, -1 < iVar3) {
                int iVar7 = 0;
                unsigned char* puVar8 = (unsigned char*)this->CurDisplayOffsets[iVar3];
                if (0 < this->Width) {
                    do {
                        *(unsigned char*)(iVar7 + line_buf) = *puVar8;
                        iVar7 = iVar7 + 1;
                        puVar8 = puVar8 + 1;
                    } while (iVar7 < this->Width);
                }
                _write(out, line_buf, (unsigned int)bmWide);
            }
            this->Unlock((char*)"take_snapshot");
        }
        _close(out);
    }
    free(line_buf);
}
