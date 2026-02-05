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

    if (actual_type_is_primary) {
        ddsd.dwFlags = DDSD_CAPS;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
        hr = system->DirDraw->CreateSurface(&ddsd, &system->PrimarySurface, NULL);
        this->DrawSurface = system->PrimarySurface;
    } else {
        ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
        ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
        if (use_sys_mem) ddsd.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
        else ddsd.ddsCaps.dwCaps |= DDSCAPS_VIDEOMEMORY;
        ddsd.dwWidth = width;
        ddsd.dwHeight = height;

        hr = system->DirDraw->CreateSurface(&ddsd, &system->PrimarySurface, NULL);
        this->DrawSurface = system->PrimarySurface;
    }

    if (FAILED(hr)) return 0;
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
    if (!this->DrawSystem || !this->DrawSystem->PrimarySurface) return;
    DDBLTFX ddbltfx;
    memset(&ddbltfx, 0, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = color;
    this->DrawSystem->PrimarySurface->Blt(rect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
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

void TDrawArea::FillRect(long left, long top, long right, long bottom, uchar color) {
    if (!this->DrawSystem || !this->DrawSystem->PrimarySurface) {
        CUSTOM_DEBUG_LOG_FMT("FillRect: early return - DrawSystem=%p, PrimarySurface=%p", 
            this->DrawSystem, this->DrawSystem ? this->DrawSystem->PrimarySurface : nullptr);
        return;
    }
    DDBLTFX ddbltfx;
    memset(&ddbltfx, 0, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = color; 
    RECT r = { left, top, right, bottom };
    HRESULT hr = this->DrawSystem->PrimarySurface->Blt(&r, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
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

void TDrawArea::ReleaseDc(char* name) {
    if (this->DrawSurface && this->DrawDc) {
        this->DrawSurface->ReleaseDC((HDC)this->DrawDc);
        this->DrawDc = nullptr;
    }
}
