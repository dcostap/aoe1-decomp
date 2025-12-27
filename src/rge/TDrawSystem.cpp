#include "TDrawSystem.h"
#include "TDrawArea.h"
#include <stdio.h>
#include <stdlib.h>

TDrawSystem::TDrawSystem() {
    memset(this, 0, sizeof(TDrawSystem));
    this->ColorBits = 8;
}

TDrawSystem::~TDrawSystem() {
}

void TDrawSystem::CheckAvailModes(int full_screen) {
    // Simplified: assume common modes are available
    this->ModeAvail640 = 1;
    this->ModeAvail800 = 1;
    this->ModeAvail1024 = 1;
    this->ModeAvail1280 = 1;
}

int TDrawSystem::IsModeAvail(int width, int height, int color_bits) {
    if (color_bits != 8) return 0;
    if (width == 640 && height == 480) return this->ModeAvail640;
    if (width == 800 && height == 600) return this->ModeAvail800;
    if (width == 1024 && height == 768) return this->ModeAvail1024;
    if (width == 1280 && height == 1024) return this->ModeAvail1280;
    return 0;
}

int TDrawSystem::Init(HINSTANCE instance, HWND window, void *palette, int draw_type, int screen_mode, int width, int height, int system_mem) {
    this->Inst = instance;
    this->Wnd = window;
    this->Pal = palette;
    this->DrawType = (unsigned char)draw_type;
    this->ScreenMode = (unsigned char)screen_mode;
    this->ScreenWidth = width;
    this->ScreenHeight = height;
    
    if (draw_type == 1) { // GDI?
        return 0; // Not implemented
    }

    if (DirectDrawCreate(NULL, &this->DirDraw, NULL) != DD_OK) {
        this->ErrorCode = 1;
        return 0;
    }

    this->CheckAvailModes(1);

    if (this->ScreenMode == 1) { // Windowed
        if (this->DirDraw->SetCooperativeLevel(this->Wnd, DDSCL_NORMAL) != DD_OK) {
            this->ErrorCode = 1;
            return 0;
        }
    } else { // Fullscreen
        if (this->DirDraw->SetCooperativeLevel(this->Wnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN) != DD_OK) {
            this->ErrorCode = 1;
            return 0;
        }
        if (this->DirDraw->SetDisplayMode(width, height, 8) != DD_OK) {
            this->ErrorCode = 1;
            return 0;
        }
        this->ChangedMode = 1;
    }

    // Palette setup
    if (this->Pal) {
        // GetPaletteEntries(this->Pal, 0, 256, entries);
    }
    if (this->DirDraw->CreatePalette(DDPCAPS_8BIT | DDPCAPS_ALLOW256, this->palette, &this->DirDrawPal, NULL) != DD_OK) {
        this->ErrorCode = 1;
        return 0;
    }

    // Clipper setup
    if (this->DirDraw->CreateClipper(0, &this->Clipper, NULL) != DD_OK) {
        this->ErrorCode = 1;
        return 0;
    }
    this->Clipper->SetHWnd(0, this->Wnd);

    if (!this->CreateSurfaces()) {
        this->ErrorCode = 1;
        return 0;
    }

    return 1;
}

int TDrawSystem::CreateSurfaces() {
    if (this->DrawType == 2) { // DirectDraw
        if (this->PrimarySurface == NULL) {
            DDSURFACEDESC ddsd;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            ddsd.dwFlags = DDSD_CAPS;
            ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

            if (this->DirDraw->CreateSurface(&ddsd, &this->PrimarySurface, NULL) != DD_OK) {
                return 0;
            }

            if (this->ColorBits == 8) {
                this->PrimarySurface->SetPalette(this->DirDrawPal);
            }
            this->PrimarySurface->SetClipper(this->Clipper);
        }

        if (this->PrimaryArea == NULL) {
            this->PrimaryArea = new TDrawArea("Primary Surface", 0);
            if (this->ScreenMode == 1) {
                RECT rect;
                GetClientRect(this->Wnd, &rect);
                this->PrimaryArea->Init(this, rect.right, rect.bottom, 0, 1);
            } else {
                this->PrimaryArea->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 1);
            }
        }
    }

    if (this->DrawArea == NULL) {
        this->DrawArea = new TDrawArea("Back Buffer", 0);
        if (this->ScreenMode == 1) {
            RECT rect;
            GetClientRect(this->Wnd, &rect);
            this->DrawArea->Init(this, rect.right, rect.bottom, 0, 0);
        } else {
            this->DrawArea->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 0);
        }
    }

    return 1;
}

void TDrawSystem::Paint(RECT *rect) {
    // STUB
}
