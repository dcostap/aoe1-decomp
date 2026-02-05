#include <windows.h>
#include <ddraw.h>
#include <stdio.h>
#include "../include/TDrawSystem.h"
#include "../include/TDrawArea.h"
#include "../include/RGE_Color_Table.h"
#include "../include/custom_debug.h"

// EXTERNAL
int system_ignore_size_messages = 0;

extern "C" void _ASMSet_Shadowing(int p1, int p2, int p3) {
    // Stub
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

TDrawSystem::TDrawSystem() {
    memset(this, 0, sizeof(TDrawSystem));
    this->ColorBits = 8; // Default to 8-bit
    system_ignore_size_messages = 0;
    _ASMSet_Shadowing(0, 0xFF00FF00, 0); 
    _ASMSet_Shadowing(0x1111, 0xFF00FF, 0); 
}

TDrawSystem::~TDrawSystem() {
    this->DeleteSurfaces();
    if (this->DirDrawPal) {
        this->DirDrawPal->Release();
        this->DirDrawPal = NULL;
    }
    if (this->Clipper) {
        this->Clipper->Release();
        this->Clipper = NULL;
    }
    if (this->DirDraw) {
        this->DirDraw->Release();
        this->DirDraw = NULL;
    }
}

int TDrawSystem::Init(void* inst, void* wnd, void* pal, uchar draw_mode, uchar err, long width, long height, ulong flags) {
    this->Inst = inst;
    this->Wnd = wnd;
    this->Pal = pal;
    this->ScreenMode = draw_mode;
    this->ErrorCode = err;
    this->ScreenWidth = width;
    this->ScreenHeight = height;
    this->Flags = flags;

    // DirectDraw initialization
    HRESULT hr = DirectDrawCreate(NULL, &this->DirDraw, NULL);
    if (FAILED(hr)) {
        CUSTOM_DEBUG_LOG_FMT("TDrawSystem::Init: DirectDrawCreate failed hr=0x%x", hr);
        this->ErrorCode = 1;
        return 0;
    }

    // Set Cooperative Level
    DWORD coopFlags = DDSCL_NORMAL;
    if (this->ScreenMode == 2) coopFlags = DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE | DDSCL_ALLOWREBOOT;
    
    if (this->Wnd) {
        hr = this->DirDraw->SetCooperativeLevel((HWND)this->Wnd, coopFlags);
        if (FAILED(hr)) {
             CUSTOM_DEBUG_LOG_FMT("TDrawSystem::Init: SetCooperativeLevel failed hr=0x%x", hr);
        }
    }
    
    this->CheckAvailModes(1);

    // Initial palette update if provided
    if (this->Pal) {
        this->SetPalette(this->Pal);
    }

    // Create Surfaces (Primary DrawArea)
    if (!this->CreateSurfaces()) {
        CUSTOM_DEBUG_LOG("TDrawSystem::Init: CreateSurfaces failed");
        return 0;
    }

    return 1;
}

int TDrawSystem::CreateSurfaces() {
    if (this->PrimaryArea) return 1;

    // Create the TDrawArea object for the primary surface
    TDrawArea* da = new TDrawArea("Primary");
    if (!da) return 0;
    
    this->PrimaryArea = da;
    this->DrawArea = da;

    // da->Init will create the DirectDraw surface
    if (!da->Init(this, this->Wnd, this->ScreenWidth, this->ScreenHeight, 0, 1, 0)) {
        return 0;
    }

    // Palette handling if screen mode is 8-bit
    if (this->ColorBits == 8 && this->DirDraw) {
        // Create DirectDraw palette
        HRESULT hr = this->DirDraw->CreatePalette(DDPCAPS_8BIT | DDPCAPS_INITIALIZE, this->palette, &this->DirDrawPal, NULL);
        if (SUCCEEDED(hr)) {
            if (this->PrimarySurface) {
                this->PrimarySurface->SetPalette(this->DirDrawPal);
            }
        }
    }

    return 1;
}

void TDrawSystem::CheckAvailModes(int p1) {
    this->ModeAvail640 = 1;
    this->ModeAvail800 = 1;
    this->ModeAvail1024 = 1;
    this->ModeAvail1280 = 1;

    if (!p1) {
        HDC hdc = CreateICA("DISPLAY", NULL, NULL, NULL);
        if (hdc) {
            int horz = GetDeviceCaps(hdc, HORZRES);
            int vert = GetDeviceCaps(hdc, VERTRES);
            DeleteDC(hdc);
            if (vert >= 600) this->ModeAvail800 = 1;
            if (vert >= 768) this->ModeAvail1024 = 1;
            if (vert >= 1024) this->ModeAvail1280 = 1;
        }
        return;
    }

    if (this->DirDraw) {
        this->DirDraw->EnumDisplayModes(0, NULL, this, TDrawSystem::CheckAvailModesCallback);
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
    if (bpp == 8) {
        if (w == 640 && h == 480) return this->ModeAvail640;
        if (w == 800 && h == 600) return this->ModeAvail800;
        if (w == 1024 && h == 768) return this->ModeAvail1024;
        if (w == 1280 && h == 1024) return this->ModeAvail1280;
    }
    return 0;
}

void TDrawSystem::DeleteSurfaces() {
    if (this->PrimarySurface) {
        this->PrimarySurface->Release();
        this->PrimarySurface = NULL;
    }
    this->Restored = 0;
}

void TDrawSystem::Paint(tagRECT* rect) {
    if (!this->PrimarySurface || !this->Wnd) {
        static bool logged = false;
        if (!logged) {
            CUSTOM_DEBUG_LOG_FMT("Paint: early return - PrimarySurface=%p, Wnd=%p", this->PrimarySurface, this->Wnd);
            logged = true;
        }
        return;
    }

    HDC hdcSurf;
    HRESULT hr = this->PrimarySurface->GetDC(&hdcSurf);
    if (hr == DDERR_SURFACELOST) {
        if (this->PrimarySurface->Restore() == DD_OK) {
            hr = this->PrimarySurface->GetDC(&hdcSurf);
        }
    }
    if (SUCCEEDED(hr)) {
        HDC hdcWin = GetDC((HWND)this->Wnd);
        if (hdcWin) {
            RECT r;
            GetClientRect((HWND)this->Wnd, &r);
            BitBlt(hdcWin, 0, 0, r.right - r.left, r.bottom - r.top, hdcSurf, 0, 0, SRCCOPY);
            ReleaseDC((HWND)this->Wnd, hdcWin);
            static bool logged2 = false;
            if (!logged2) {
                CUSTOM_DEBUG_LOG_FMT("Paint: BitBlt executed, size=%dx%d", r.right - r.left, r.bottom - r.top);
                logged2 = true;
            }
        }
        this->PrimarySurface->ReleaseDC(hdcSurf);
    } else {
        static bool logged3 = false;
        if (!logged3) {
            CUSTOM_DEBUG_LOG_FMT("Paint: GetDC failed hr=0x%x", hr);
            logged3 = true;
        }
    }
}

void TDrawSystem::SetPalette(void* pal) {
    this->Pal = pal;
    PALETTEENTRY color_table[256];
    memset(color_table, 0, sizeof(color_table));
    if (pal) {
        int retrieved = GetPaletteEntries((HPALETTE)pal, 0, 256, color_table);
        CUSTOM_DEBUG_LOG_FMT("TDrawSystem::SetPalette: retrieved %d entries from HPALETTE %p", retrieved, pal);
        if (retrieved > 0) {
            CUSTOM_DEBUG_LOG_FMT("TDrawSystem::SetPalette: Entry 0: R=%d G=%d B=%d", (int)color_table[0].peRed, (int)color_table[0].peGreen, (int)color_table[0].peBlue);
            for (int i = 0; i < 16; i++) {
                CUSTOM_DEBUG_LOG_FMT("  Pal[%d]: R=%d G=%d B=%d", i, (int)color_table[i].peRed, (int)color_table[i].peGreen, (int)color_table[i].peBlue);
            }
            CUSTOM_DEBUG_LOG_FMT("TDrawSystem::SetPalette: Entry 255: R=%d G=%d B=%d", (int)color_table[255].peRed, (int)color_table[255].peGreen, (int)color_table[255].peBlue);
        }
    } else {
        CUSTOM_DEBUG_LOG("TDrawSystem::SetPalette: NULL HPALETTE provided");
    }
    this->ModifyPalette(0, 256, color_table);
}

void TDrawSystem::ModifyPalette(int start, int count, tagPALETTEENTRY* entries) {
    if (start < 0 || start + count > 256) return;
    memcpy(&this->palette[start], entries, count * sizeof(tagPALETTEENTRY));
    if (this->DirDrawPal) {
        this->DirDrawPal->SetEntries(0, start, count, entries);
    }
}

void TDrawSystem::ClearPrimarySurface() {
    if (this->PrimarySurface) {
        DDBLTFX ddbltfx;
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = 0;
        this->PrimarySurface->Blt(NULL, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
    }
}

uchar TDrawSystem::CheckSurfaces() {
    if (!this->PrimarySurface) return 0;
    if (this->PrimarySurface->IsLost() == DDERR_SURFACELOST) {
        if (this->PrimarySurface->Restore() == DD_OK) {
            this->Restored = 1;
            return 1;
        }
        return 0;
    }
    return 1;
}

void TDrawSystem::ClearRestored() {
    this->Restored = 0;
}

int TDrawSystem::SetDisplaySize(long p1, long p2, int p3) {
    return 1;
}

// TDrawArea Implementation

TDrawArea::TDrawArea(char* name) {
    memset(this, 0, sizeof(TDrawArea));
    this->TransColor = 0xFF;
    if (name) {
        this->Name = _strdup(name);
    }
}

TDrawArea::~TDrawArea() {
    if (this->Name) {
        free(this->Name);
    }
}

int TDrawArea::Init(TDrawSystem* system, void* wnd, int width, int height, int use_trans, int is_primary, int use_sys_mem) {
    this->DrawSystem = system;
    this->Wnd = wnd;
    this->Width = width;
    this->Height = height;
    this->UseTrans = use_trans;
    this->IsPrimarySurface = is_primary;
    this->SystemMemOnly = use_sys_mem;

    if (!system || !system->DirDraw) return 0;

    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);

    HRESULT hr;

    int actual_type_is_primary = is_primary;
    if (system->Wnd) {
        actual_type_is_primary = 0;
    }

    IDirectDrawSurface* created_surface = NULL;

    if (actual_type_is_primary) {
        ddsd.dwFlags = DDSD_CAPS;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
        hr = system->DirDraw->CreateSurface(&ddsd, &created_surface, NULL);
    } else {
        ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
        ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
        if (use_sys_mem) ddsd.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
        else ddsd.ddsCaps.dwCaps |= DDSCAPS_VIDEOMEMORY;
        ddsd.dwWidth = width;
        ddsd.dwHeight = height;

        hr = system->DirDraw->CreateSurface(&ddsd, &created_surface, NULL);
    }

    if (FAILED(hr)) return 0;

    this->DrawSurface = created_surface;

    // In windowed mode the original engine often treats the main draw surface as an offscreen
    // surface and still stores it as `PrimarySurface` for paint/blt purposes. Preserve that.
    if (is_primary) {
        system->PrimarySurface = created_surface;
    }

    this->Orien = 1;
    this->SetClipRect((tagRECT*)0);
    return 1;
}

void TDrawArea::SetSize(long width, long height, int pitch) {
    this->Width = width;
    this->Height = height;
    this->Pitch = pitch;
}

void TDrawArea::SetFloatOffsets(int p1, int p2) {
    this->Float_X_Delta = p1;
    this->Float_Y_Delta = p2;
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

uchar* TDrawArea::Lock(char* name, int p2) {
    if (!this->DrawSurface) return NULL;
    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    HRESULT hr = this->DrawSurface->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL);
    if (hr == DDERR_SURFACELOST) {
        if (this->DrawSurface->Restore() == DD_OK) {
            hr = this->DrawSurface->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL);
        }
    }
    if (FAILED(hr)) return NULL;
    static bool logged_lock = false;
    if (!logged_lock) {
        CUSTOM_DEBUG_LOG_FMT("TDrawArea::Lock: %s bpp=%lu pitch=%ld R=0x%08lx G=0x%08lx B=0x%08lx", name ? name : "(null)", (unsigned long)ddsd.ddpfPixelFormat.dwRGBBitCount, (long)ddsd.lPitch, (unsigned long)ddsd.ddpfPixelFormat.dwRBitMask, (unsigned long)ddsd.ddpfPixelFormat.dwGBitMask, (unsigned long)ddsd.ddpfPixelFormat.dwBBitMask);
        logged_lock = true;
    }
    this->Bits = (uchar*)ddsd.lpSurface;
    this->Pitch = ddsd.lPitch;
    return this->Bits;
}

void TDrawArea::Unlock(char* name) {
    if (!this->DrawSurface) return;
    this->DrawSurface->Unlock(NULL);
    this->Bits = NULL;
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
    if (!this->DrawSurface) {
        CUSTOM_DEBUG_LOG_FMT("FillRect: early return - DrawSurface=%p", this->DrawSurface);
        return;
    }
    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    HRESULT sdesc_hr = this->DrawSurface->GetSurfaceDesc(&ddsd);
    (void)sdesc_hr;

    DDBLTFX ddbltfx;
    memset(&ddbltfx, 0, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = map_color_index_to_surface_pixel(this, (int)color, &ddsd, sdesc_hr);
    // Clamp to clip rect (inclusive).
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

    if (right < cl || bottom < ct || left > cr || top > cb) return;
    if (left < cl) left = cl;
    if (top < ct) top = ct;
    if (right > cr) right = cr;
    if (bottom > cb) bottom = cb;

    // `tagRECT` style inclusive -> DirectDraw exclusive.
    RECT r = { (LONG)left, (LONG)top, (LONG)(right + 1), (LONG)(bottom + 1) };
    HRESULT hr = this->DrawSurface->Blt(&r, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
    static bool logged = false;
    if (!logged) {
        CUSTOM_DEBUG_LOG_FMT("FillRect: Blt result=0x%x", hr);
        logged = true;
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

void TDrawArea::DrawHorzLine(long x1, long x2, long y, uchar color) {
    normalize_inclusive(&x1, &x2);
    this->FillRect(x1, y, x2, y, color);
}

void TDrawArea::DrawVertLine(long x, long y1, long y2, uchar color) {
    normalize_inclusive(&y1, &y2);
    this->FillRect(x, y1, x, y2, color);
}

void TDrawArea::DrawRect(long x1, long y1, long x2, long y2, uchar color) {
    normalize_inclusive(&x1, &x2);
    normalize_inclusive(&y1, &y2);
    if (x2 < x1 || y2 < y1) return;
    this->DrawHorzLine(x1, x2, y1, color);
    this->DrawHorzLine(x1, x2, y2, color);
    this->DrawVertLine(x1, y1, y2, color);
    this->DrawVertLine(x2, y1, y2, color);
}

void TDrawArea::DrawRect(tagRECT* rect, uchar color) {
    if (!rect) return;
    this->DrawRect(rect->left, rect->top, rect->right, rect->bottom, color);
}

void TDrawArea::DrawBevel(long x1, long y1, long x2, long y2, uchar c_tl, uchar c_br) {
    normalize_inclusive(&x1, &x2);
    normalize_inclusive(&y1, &y2);
    if (x2 - x1 < 1 || y2 - y1 < 1) return;
    this->DrawHorzLine(x1, x2, y1, c_tl);
    this->DrawVertLine(x1, y1, y2, c_tl);
    this->DrawHorzLine(x1, x2, y2, c_br);
    this->DrawVertLine(x2, y1, y2, c_br);
}

void TDrawArea::DrawBevel2(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4) {
    // Best-effort approximation: two nested 1px bevels.
    this->DrawBevel(x1, y1, x2, y2, c1, c4);
    this->DrawBevel(x1 + 1, y1 + 1, x2 - 1, y2 - 1, c2, c3);
}

void TDrawArea::DrawBevel21(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4) {
    // Best-effort approximation: `DrawBevel21` appears in UI code; treat as an order variant of `DrawBevel2`.
    // TODO: Verify exact layering from `Drawarea.cpp.asm` and adjust.
    this->DrawBevel2(x1, y1, x2, y2, c1, c2, c3, c4);
}

void TDrawArea::DrawBevel3(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4, uchar c5, uchar c6) {
    // Best-effort approximation of a 3-layer bevel using 6 palette indices.
    // Expected usage from `Pnl_btn.cpp.decomp`:
    // - pressed:  DrawBevel3(..., bevel_color1..bevel_color6)
    // - raised:   DrawBevel32(..., bevel_color6..bevel_color1)
    this->DrawBevel(x1, y1, x2, y2, c1, c6);
    this->DrawBevel(x1 + 1, y1 + 1, x2 - 1, y2 - 1, c2, c5);
    this->DrawBevel(x1 + 2, y1 + 2, x2 - 2, y2 - 2, c3, c4);
}

void TDrawArea::DrawBevel32(long x1, long y1, long x2, long y2, uchar c1, uchar c2, uchar c3, uchar c4, uchar c5, uchar c6) {
    // Best-effort: treat as the same layering function, with callers supplying the inverted color order.
    // TODO: Verify exact behavior from `Drawarea.cpp.asm` and adjust if needed.
    this->DrawBevel3(x1, y1, x2, y2, c1, c2, c3, c4, c5, c6);
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
        this->ClipRect.right = (this->Width > 0) ? (this->Width - 1) : 0;
        this->ClipRect.bottom = (this->Height > 0) ? (this->Height - 1) : 0;
        return;
    }

    this->ClipRect = *rect;

    if (this->ClipRect.left < 0) this->ClipRect.left = 0;
    if (this->ClipRect.top < 0) this->ClipRect.top = 0;
    if (this->ClipRect.right < 0) this->ClipRect.right = 0;
    if (this->ClipRect.bottom < 0) this->ClipRect.bottom = 0;

    if (this->Width > 0 && this->ClipRect.left > this->Width - 1) this->ClipRect.left = this->Width - 1;
    if (this->Width > 0 && this->ClipRect.right > this->Width - 1) this->ClipRect.right = this->Width - 1;
    if (this->Height > 0 && this->ClipRect.top > this->Height - 1) this->ClipRect.top = this->Height - 1;
    if (this->Height > 0 && this->ClipRect.bottom > this->Height - 1) this->ClipRect.bottom = this->Height - 1;

    if (this->ClipRect.right < this->ClipRect.left) {
        long t = this->ClipRect.left;
        this->ClipRect.left = this->ClipRect.right;
        this->ClipRect.right = t;
    }
    if (this->ClipRect.bottom < this->ClipRect.top) {
        long t = this->ClipRect.top;
        this->ClipRect.top = this->ClipRect.bottom;
        this->ClipRect.bottom = t;
    }
}

void TDrawArea::SetClipRect(long left, long top, long right, long bottom) {
    tagRECT r;
    r.left = left;
    r.top = top;
    r.right = right;
    r.bottom = bottom;
    this->SetClipRect(&r);
}

void TDrawArea::Copy(TDrawArea* dest, long x, long y, tagRECT* src_rect, int flags) {
    (void)flags;
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

    dest->DrawSurface->Blt(&dr, this->DrawSurface, &sr, DDBLT_WAIT, NULL);
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
