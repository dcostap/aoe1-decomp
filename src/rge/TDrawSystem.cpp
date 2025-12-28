#include "TDrawSystem.h"
#include "TDrawArea.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _DEBUG
#define LOG_PAINT 0 // Set to 1 to see every paint call
#endif

// Address: 0x00443000
TDrawSystem::TDrawSystem() {
    memset(this, 0, sizeof(TDrawSystem));
    this->ColorBits = 8;

    // Initialize palette with some basic colors
    for (int i = 0; i < 256; ++i) {
        this->palette[i].peRed = (BYTE)i;
        this->palette[i].peGreen = (BYTE)i;
        this->palette[i].peBlue = (BYTE)i;
        this->palette[i].peFlags = 0;
    }
    // Make index 3 green
    this->palette[3].peRed = 0;
    this->palette[3].peGreen = 255;
    this->palette[3].peBlue = 0;
    // Make index 4 blue
    this->palette[4].peRed = 0;
    this->palette[4].peGreen = 0;
    this->palette[4].peBlue = 255;
}

// Address: 0x00443100
TDrawSystem::~TDrawSystem() {
}

// Address: 0x00443200
void TDrawSystem::CheckAvailModes(int full_screen) {
    // Simplified: assume common modes are available
    this->ModeAvail640 = 1;
    this->ModeAvail800 = 1;
    this->ModeAvail1024 = 1;
    this->ModeAvail1280 = 1;
}

// Address: 0x00443300
int TDrawSystem::IsModeAvail(int width, int height, int color_bits) {
    if (color_bits != 8) return 0;
    if (width == 640 && height == 480) return this->ModeAvail640;
    if (width == 800 && height == 600) return this->ModeAvail800;
    if (width == 1024 && height == 768) return this->ModeAvail1024;
    if (width == 1280 && height == 1024) return this->ModeAvail1280;
    return 0;
}

// Address: 0x00443400
int TDrawSystem::Init(HINSTANCE instance, HWND window, void *palette, int draw_type, int screen_mode, int width, int height, int system_mem) {
    this->Inst = instance;
    this->Wnd = window;
    this->Pal = palette;
    this->DrawType = (unsigned char)draw_type;
    this->ScreenMode = (unsigned char)screen_mode;
    this->ScreenWidth = width;
    this->ScreenHeight = height;
    
    if (draw_type == 1) { // GDI?
#ifdef _DEBUG
        printf("TDrawSystem::Init: GDI not implemented\n");
#endif
        return 0;
    }

    if (DirectDrawCreateEx(NULL, (void**)&this->DirDraw, IID_IDirectDraw7, NULL) != DD_OK) {
#ifdef _DEBUG
        printf("TDrawSystem::Init: DirectDrawCreateEx failed\n");
#endif
        this->ErrorCode = 1;
        return 0;
    }

    this->CheckAvailModes(1);

    if (this->ScreenMode == 1) { // Windowed
        if (this->DirDraw->SetCooperativeLevel(this->Wnd, DDSCL_NORMAL) != DD_OK) {
#ifdef _DEBUG
            printf("TDrawSystem::Init: SetCooperativeLevel failed\n");
#endif
            this->ErrorCode = 1;
            return 0;
        }
    } else { // Fullscreen
        if (this->DirDraw->SetCooperativeLevel(this->Wnd, DDSCL_EXCLUSIVE | DDSCL_FULLSCREEN) != DD_OK) {
#ifdef _DEBUG
            printf("TDrawSystem::Init: SetCooperativeLevel Fullscreen failed\n");
#endif
            this->ErrorCode = 1;
            return 0;
        }
        if (this->DirDraw->SetDisplayMode(width, height, 8, 0, 0) != DD_OK) {
#ifdef _DEBUG
            printf("TDrawSystem::Init: SetDisplayMode failed\n");
#endif
            this->ErrorCode = 1;
            return 0;
        }
        this->ChangedMode = 1;
    }

    // Palette setup
    if (this->DirDraw->CreatePalette(DDPCAPS_8BIT | DDPCAPS_ALLOW256, this->palette, &this->DirDrawPal, NULL) != DD_OK) {
#ifdef _DEBUG
        printf("TDrawSystem::Init: CreatePalette failed\n");
#endif
        this->ErrorCode = 1;
        return 0;
    }

    // Clipper setup
    if (this->DirDraw->CreateClipper(0, &this->Clipper, NULL) != DD_OK) {
#ifdef _DEBUG
        printf("TDrawSystem::Init: CreateClipper failed\n");
#endif
        this->ErrorCode = 1;
        return 0;
    }
    this->Clipper->SetHWnd(0, this->Wnd);

    if (!this->CreateSurfaces()) {
#ifdef _DEBUG
        printf("TDrawSystem::Init: CreateSurfaces failed\n");
#endif
        this->ErrorCode = 1;
        return 0;
    }

    return 1;
}

// Address: 0x00443500
int TDrawSystem::CreateSurfaces() {
    if (this->DrawType == 2) { // DirectDraw
        if (this->PrimarySurface == NULL) {
            DDSURFACEDESC2 ddsd;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            ddsd.dwFlags = DDSD_CAPS;
            ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;

            if (this->DirDraw->CreateSurface(&ddsd, &this->PrimarySurface, NULL) != DD_OK) {
#ifdef _DEBUG
                printf("TDrawSystem::CreateSurfaces: CreateSurface Primary failed\n");
#endif
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
                if (!this->PrimaryArea->Init(this, rect.right, rect.bottom, 0, 1)) {
#ifdef _DEBUG
                    printf("TDrawSystem::CreateSurfaces: PrimaryArea Init failed\n");
#endif
                    return 0;
                }
            } else {
                if (!this->PrimaryArea->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 1)) {
#ifdef _DEBUG
                    printf("TDrawSystem::CreateSurfaces: PrimaryArea Init Fullscreen failed\n");
#endif
                    return 0;
                }
            }
        }
    }

    if (this->DrawArea == NULL) {
        this->DrawArea = new TDrawArea("Back Buffer", 1); // Use system memory for 8-bit windowed
        if (this->ScreenMode == 1) {
            RECT rect;
            GetClientRect(this->Wnd, &rect);
            if (!this->DrawArea->Init(this, rect.right, rect.bottom, 0, 0)) {
#ifdef _DEBUG
                printf("TDrawSystem::CreateSurfaces: DrawArea Init failed\n");
#endif
                return 0;
            }
        } else {
            if (!this->DrawArea->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 0)) {
#ifdef _DEBUG
                printf("TDrawSystem::CreateSurfaces: DrawArea Init Fullscreen failed\n");
#endif
                return 0;
            }
        }
    }

    return 1;
}

// Address: 0x00443600
void TDrawSystem::Paint(RECT *rect) {
    if (this->DrawType == 2 && this->PrimarySurface && this->DrawArea && this->DrawArea->DrawSurface) {
        if (this->PrimarySurface->IsLost() == DDERR_SURFACELOST) {
            this->PrimarySurface->Restore();
        }
        if (this->DrawArea->DrawSurface->IsLost() == DDERR_SURFACELOST) {
            this->DrawArea->DrawSurface->Restore();
        }

        HRESULT hr;
        if (this->ScreenMode == 1) { // Windowed
            POINT pt = {0, 0};
            ClientToScreen(this->Wnd, &pt);
            RECT dest;
            GetClientRect(this->Wnd, &dest);
            OffsetRect(&dest, pt.x, pt.y);
            hr = this->PrimarySurface->Blt(&dest, this->DrawArea->DrawSurface, rect, DDBLT_WAIT, nullptr);
        } else { // Fullscreen
            hr = this->PrimarySurface->Blt(rect, this->DrawArea->DrawSurface, rect, DDBLT_WAIT, nullptr);
        }

        if (hr != DD_OK) {
            static int blt_error_count = 0;
            if (blt_error_count < 10) {
                printf("TDrawSystem::Paint: Blt failed with %08X\n", hr);
                blt_error_count++;
            }
        }
    }
}

void TDrawSystem::ModifyPalette(int start, int count, PALETTEENTRY *entries) {
    if (start < 0 || start >= 256) return;
    if (start + count > 256) count = 256 - start;

    memcpy(&this->palette[start], entries, count * sizeof(PALETTEENTRY));

    if (this->DirDrawPal) {
        this->DirDrawPal->SetEntries(0, start, count, entries);
    }
}
