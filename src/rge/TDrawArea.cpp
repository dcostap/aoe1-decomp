#include "TDrawArea.h"
#include "TDrawSystem.h"
#include <string.h>
#include <stdlib.h>

TDrawArea::TDrawArea(const char *name, int system_mem) {
    memset(this, 0, sizeof(TDrawArea));
    this->SystemMemOnly = system_mem;
    if (name) {
        this->Name = _strdup(name);
    }
}

TDrawArea::~TDrawArea() {
    if (this->Name) {
        free(this->Name);
    }
}

int TDrawArea::Init(TDrawSystem *draw_system, int width, int height, int using_vid_mem, int is_primary_surface) {
    this->DrawSystem = draw_system;
    this->IsPrimarySurface = is_primary_surface;
    if (draw_system) {
        this->Wnd = draw_system->Wnd;
        // Add to DrawAreaList logic...
    }
    this->SetSize(width, height, 0);
    return 1;
}

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
                memset(&this->SurfaceDesc, 0, sizeof(this->SurfaceDesc));
                this->SurfaceDesc.dwSize = sizeof(this->SurfaceDesc);
                this->DrawSurface->GetSurfaceDesc(&this->SurfaceDesc);
                this->Pitch = this->SurfaceDesc.lPitch;
            }
        } else {
            if (this->DrawSurface) {
                this->DrawSurface->Release();
                this->DrawSurface = nullptr;
            }

            DDSURFACEDESC ddsd;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
            ddsd.dwWidth = width;
            ddsd.dwHeight = height + extended_lines;
            ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
            if (this->SystemMemOnly) {
                ddsd.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
            }

            if (this->DrawSystem->DirDraw->CreateSurface(&ddsd, &this->DrawSurface, NULL) == DD_OK) {
                memset(&this->SurfaceDesc, 0, sizeof(this->SurfaceDesc));
                this->SurfaceDesc.dwSize = sizeof(this->SurfaceDesc);
                this->DrawSurface->GetSurfaceDesc(&this->SurfaceDesc);
                this->Pitch = this->SurfaceDesc.lPitch;
            }
        }
    }

    this->SetClipRect(nullptr);
}

void TDrawArea::Clear(RECT *rect, int color) {
    if (this->DrawSurface) {
        DDBLTFX ddbltfx;
        memset(&ddbltfx, 0, sizeof(ddbltfx));
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = color;
        this->DrawSurface->Blt(rect, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &ddbltfx);
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
