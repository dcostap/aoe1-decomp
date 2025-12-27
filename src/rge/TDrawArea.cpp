#include "TDrawArea.h"
#include "TDrawSystem.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Address: 0x004439B0
TDrawArea::TDrawArea(const char *name, int system_mem) {
    memset(this, 0, sizeof(TDrawArea));
    this->SystemMemOnly = system_mem;
    if (name) {
        this->Name = _strdup(name);
    }
}

// Address: 0x00443A40
TDrawArea::~TDrawArea() {
    if (this->Name) {
        free(this->Name);
    }
}

// Address: 0x00443B00
int TDrawArea::Init(TDrawSystem *draw_system, int width, int height, int using_vid_mem, int is_primary_surface) {
    this->DrawSystem = draw_system;
    this->IsPrimarySurface = is_primary_surface;
    if (draw_system) {
        this->Wnd = draw_system->Wnd;
        // Add to DrawAreaList logic...
    }
    this->SetSize(width, height, 0);
    return (this->DrawSurface != nullptr);
}

// Address: 0x00443C00
void TDrawArea::SetSize(int width, int height, int extended_lines) {
    if (width < 1) width = 1;
    if (height < 1) height = 1;

    this->Width = width;
    this->Height = height;
    this->ExtendedLines = extended_lines;

    if (this->DrawSystem && this->DrawSystem->DrawType == 2) { // DirectDraw
        if (this->IsPrimarySurface) {
            this->DrawSurface = this->DrawSystem->PrimarySurface;
            if (this->DrawSurface) {
                this->DrawSurface->AddRef();
                DDSURFACEDESC2 ddsd2;
                memset(&ddsd2, 0, sizeof(ddsd2));
                ddsd2.dwSize = sizeof(ddsd2);
                this->DrawSurface->GetSurfaceDesc(&ddsd2);

                memset(&this->SurfaceDesc, 0, sizeof(this->SurfaceDesc));
                this->SurfaceDesc.dwSize = sizeof(this->SurfaceDesc);
                this->SurfaceDesc.dwFlags = ddsd2.dwFlags;
                this->SurfaceDesc.dwHeight = ddsd2.dwHeight;
                this->SurfaceDesc.dwWidth = ddsd2.dwWidth;
                this->SurfaceDesc.lPitch = ddsd2.lPitch;
                this->SurfaceDesc.lpSurface = ddsd2.lpSurface;
                this->SurfaceDesc.ddpfPixelFormat = ddsd2.ddpfPixelFormat;

                this->Pitch = this->SurfaceDesc.lPitch;
            } else {
#ifdef _DEBUG
                printf("TDrawArea::SetSize: PrimarySurface is NULL\n");
#endif
            }
        } else {
            if (this->DrawSurface) {
                this->DrawSurface->Release();
                this->DrawSurface = nullptr;
            }

            DDSURFACEDESC2 ddsd;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH | DDSD_PIXELFORMAT;
            ddsd.dwWidth = width;
            ddsd.dwHeight = height + extended_lines;
            ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
            if (this->SystemMemOnly) {
                ddsd.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
            }

            ddsd.ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
            ddsd.ddpfPixelFormat.dwFlags = DDPF_PALETTEINDEXED8;
            ddsd.ddpfPixelFormat.dwRGBBitCount = 8;

            HRESULT hr = this->DrawSystem->DirDraw->CreateSurface(&ddsd, &this->DrawSurface, NULL);
            if (hr == DDERR_INVALIDPIXELFORMAT) {
#ifdef _DEBUG
                printf("TDrawArea::SetSize: 8-bit failed, trying desktop format...\n");
#endif
                ddsd.dwFlags &= ~DDSD_PIXELFORMAT;
                hr = this->DrawSystem->DirDraw->CreateSurface(&ddsd, &this->DrawSurface, NULL);
            }

            if (hr == DD_OK) {
                if (this->DrawSystem->DirDrawPal) {
                    this->DrawSurface->SetPalette(this->DrawSystem->DirDrawPal);
                }
                // Copy to the old DDSURFACEDESC member for compatibility
                DDSURFACEDESC2 ddsd2;
                memset(&ddsd2, 0, sizeof(ddsd2));
                ddsd2.dwSize = sizeof(ddsd2);
                this->DrawSurface->GetSurfaceDesc(&ddsd2);
                
                memset(&this->SurfaceDesc, 0, sizeof(this->SurfaceDesc));
                this->SurfaceDesc.dwSize = sizeof(this->SurfaceDesc);
                this->SurfaceDesc.dwFlags = ddsd2.dwFlags;
                this->SurfaceDesc.dwHeight = ddsd2.dwHeight;
                this->SurfaceDesc.dwWidth = ddsd2.dwWidth;
                this->SurfaceDesc.lPitch = ddsd2.lPitch;
                this->SurfaceDesc.lpSurface = ddsd2.lpSurface;
                this->SurfaceDesc.ddpfPixelFormat = ddsd2.ddpfPixelFormat;
                
                this->Pitch = this->SurfaceDesc.lPitch;
            } else {
#ifdef _DEBUG
                printf("TDrawArea::SetSize: CreateSurface failed with %08X\n", hr);
#endif
            }
        }
    }

    this->SetClipRect(nullptr);
}

// Address: 0x00443F00
void TDrawArea::Clear(RECT *rect, int color) {
    if (this->DrawSurface) {
        DDBLTFX ddbltfx;
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = color;
        HRESULT hr = this->DrawSurface->Blt(rect, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
        if (hr != DD_OK) {
#ifdef _DEBUG
            printf("TDrawArea::Clear: Blt failed with %08X, color=%d\n", hr, color);
#endif
        } else {
#ifdef _DEBUG
            static int clear_log_count = 0;
            if (clear_log_count < 3) {
                printf("TDrawArea::Clear: SUCCESS color=%d rect=[%d,%d,%d,%d]\n", color,
                    rect ? rect->left : 0, rect ? rect->top : 0, rect ? rect->right : 0, rect ? rect->bottom : 0);
                clear_log_count++;
            }
#endif
        }
    }
}

void TDrawArea::SetClipRect(RECT *rect) {
    if (rect) {
        this->ClipRect = *rect;
    } else {
        this->ClipRect.left = 0;
        this->ClipRect.top = 0;
        this->ClipRect.right = this->Width - 1;
        this->ClipRect.bottom = this->Height - 1;
    }
}
