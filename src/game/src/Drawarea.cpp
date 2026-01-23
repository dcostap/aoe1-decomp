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
    if (pal) {
        GetPaletteEntries((HPALETTE)pal, 0, 256, color_table);
    } else {
        memset(color_table, 0, sizeof(color_table));
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

void TDrawArea::Clear(tagRECT* rect) {
    if (!this->DrawSystem || !this->DrawSystem->PrimarySurface) return;
    DDBLTFX ddbltfx;
    memset(&ddbltfx, 0, sizeof(ddbltfx));
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = 0;
    this->DrawSystem->PrimarySurface->Blt(rect, NULL, NULL, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
}

void TDrawArea::PtrClear(tagRECT* rect) {}
void TDrawArea::OverlayMemCopy(tagRECT* rect, TDrawArea* src, int x, int y) {}

uchar* TDrawArea::Lock(char* name, int p2) {
    if (!this->DrawSystem || !this->DrawSystem->PrimarySurface) return NULL;
    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    if (FAILED(this->DrawSystem->PrimarySurface->Lock(NULL, &ddsd, DDLOCK_WAIT, NULL))) return NULL;
    this->Bits = (uchar*)ddsd.lpSurface;
    this->Pitch = ddsd.lPitch;
    return this->Bits;
}

void TDrawArea::Unlock(char* name) {
    if (!this->DrawSystem || !this->DrawSystem->PrimarySurface) return;
    this->DrawSystem->PrimarySurface->Unlock(NULL);
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

void* TDrawArea::GetDc(char* name) { return this->DrawDc; }
void TDrawArea::ReleaseDc(char* name) {}
