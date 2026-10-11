#include "../include/drawarea.h"
#include "../include/asm_draw.h"
#include "../include/color.h"
#include "../include/game_globals.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

extern int DDSys_CanColorFill;
extern int PalSetRes;
extern int FullPalSets;
extern int AniPalSets;
struct TRANSINFO;
extern void __cdecl TransDibBlt(
    BITMAPINFO256*, unsigned char*, RECT*, long, long, long, long, BITMAPINFO256*, unsigned char*, TRANSINFO*, long,
    long, long, long, int, int, int, int
);
extern void __cdecl DibBlt(
    BITMAPINFO256*, unsigned char*, RECT*, long, long, long, long, BITMAPINFO256*, unsigned char*, long, long, long,
    long, int, int, int
);
extern "C" int __cdecl _open(const char*, int, ...);
extern "C" int __cdecl write(int, void*, int);
extern "C" int __cdecl close(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern void* __cdecl calloc(unsigned int, unsigned int);
extern void* __cdecl operator new(unsigned int);
#pragma function(memset)

TDrawSystem::TDrawSystem() {
    this->Inst = 0;
    this->Wnd = 0;
    this->Pal = 0;
    this->DrawArea = 0;
    this->PrimaryArea = 0;
    this->DirDraw = 0;
    this->PrimarySurface = 0;
    this->Clipper = 0;
    this->DirDrawPal = 0;
    this->ChangedMode = 0;
    this->DrawType = 0;
    this->ScreenMode = 0;
    this->ScreenWidth = 0;
    this->ScreenHeight = 0;
    this->ColorBits = 8;
    this->Flags = 0;
    this->IsBanked = 0;
    this->CanSrcBlt = 0;
    this->DrawAreaList = 0;
    this->Restored = 0;
    this->ModeAvail640 = 0;
    this->ModeAvail800 = 0;
    this->ModeAvail1024 = 0;
    this->ModeAvail1280 = 0;
    this->ModeAvail320_200 = 0;
    this->ModeAvail320_240 = 0;
    this->ModeAvail320_200_16 = 0;
    this->ModeAvail320_240_16 = 0;
    this->ModeAvail640_16 = 0;
    this->ModeAvail800_16 = 0;
    this->ModeAvail1024_16 = 0;
    this->ErrorCode = 0;
    system_ignore_size_messages = 0;
    ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
}

TDrawSystem::~TDrawSystem() {
    DDBLTFX ddbltfx;
    if (this->ScreenMode == 2 && this->PrimarySurface != 0) {
        IDirectDrawSurface* s = this->PrimarySurface;
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = 0;
        s->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
    }

    this->DeleteSurfaces();

    if (this->DirDraw != 0) {
        if (this->DirDrawPal != 0) {
            IDirectDrawPalette* p = this->DirDrawPal;
            p->Release();
            this->DirDrawPal = 0;
        }
        if (this->Clipper != 0) {
            IDirectDrawClipper* c = this->Clipper;
            c->Release();
            this->Clipper = 0;
        }
        if (this->ChangedMode != 0) {
            IDirectDraw* d = this->DirDraw;
            d->RestoreDisplayMode();
            this->ChangedMode = 0;
        }
        IDirectDraw* d = this->DirDraw;
        d->Release();
        this->DirDraw = 0;
    }
}

void TDrawSystem::CheckAvailModes(int full_screen) {
    if (full_screen == 0) {
        this->ModeAvail640 = 1;
        void* dc = CreateICA("DISPLAY", 0, 0, 0);
        if (dc != 0) {
            int width = GetDeviceCaps(dc, HORZRES);
            GetDeviceCaps(dc, VERTRES);
            DeleteDC(dc);
            if (width >= 800)
                this->ModeAvail800 = 1;
            if (width >= 1024)
                this->ModeAvail1024 = 1;
            if (width >= 1280)
                this->ModeAvail1280 = 1;
        }
    } else {
        IDirectDraw** direct_draw = &this->DirDraw;
        int was_present;
        if (this->DirDraw == 0) {
            if (DirectDrawCreate(0, direct_draw, 0) != 0)
                return;
            was_present = 0;
        } else {
            was_present = 1;
        }

        (*direct_draw)->EnumDisplayModes(0, 0, this, CheckAvailModesCallback);
        if (was_present == 0) {
            (*direct_draw)->Release();
            *direct_draw = 0;
        }
    }
}

long __stdcall TDrawSystem::CheckAvailModesCallback(_DDSURFACEDESC* lpDDSurfaceDesc, void* lpContext) {
    register long result = 1;
    TDrawSystem* mode_info = (TDrawSystem*) lpContext;
    int bpp = lpDDSurfaceDesc->ddpfPixelFormat.dwRGBBitCount;

    if (bpp == 8) {
        if (lpDDSurfaceDesc->dwWidth == 640 && lpDDSurfaceDesc->dwHeight == 480) {
            mode_info->ModeAvail640 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 800 && lpDDSurfaceDesc->dwHeight == 600) {
            mode_info->ModeAvail800 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 1024 && lpDDSurfaceDesc->dwHeight == 768) {
            mode_info->ModeAvail1024 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 1280 && lpDDSurfaceDesc->dwHeight == 1024) {
            mode_info->ModeAvail1280 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 320 && lpDDSurfaceDesc->dwHeight == 200) {
            mode_info->ModeAvail320_200 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 320 && lpDDSurfaceDesc->dwHeight == 240) {
            mode_info->ModeAvail320_240 = 1;
            goto done;
        }
    } else if (bpp == 16) {
        if (lpDDSurfaceDesc->dwWidth == 640 && lpDDSurfaceDesc->dwHeight == 480) {
            mode_info->ModeAvail640_16 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 800 && lpDDSurfaceDesc->dwHeight == 600) {
            mode_info->ModeAvail800_16 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 1024 && lpDDSurfaceDesc->dwHeight == 768) {
            mode_info->ModeAvail1024_16 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 320 && lpDDSurfaceDesc->dwHeight == 200) {
            mode_info->ModeAvail320_200_16 = 1;
            goto done;
        }
        if (lpDDSurfaceDesc->dwWidth == 320 && lpDDSurfaceDesc->dwHeight == 240) {
            mode_info->ModeAvail320_240_16 = 1;
            goto done;
        }
    }
done:
    // DDENUMRET_OK keeps the DirectDraw mode enumeration running.
    return result;
}

int TDrawSystem::IsModeAvail(long wid_in, long hgt_in, int color_bits) {
    if (color_bits == 8) {
        if (wid_in <= 640) {
            if (wid_in != 640) {
                if (wid_in == 320) {
                    if (hgt_in == 200) {
                        return this->ModeAvail320_200;
                    }
                    if (hgt_in == 240) {
                        return this->ModeAvail320_240;
                    }
                }
            } else {
                return this->ModeAvail640;
            }
        } else {
            if (wid_in != 800) {
                if (wid_in != 1024) {
                    if (wid_in == 1280) {
                        return this->ModeAvail1280;
                    }
                } else {
                    return this->ModeAvail1024;
                }
            } else {
                return this->ModeAvail800;
            }
        }
    } else if (color_bits == 16) {
        if (wid_in <= 640) {
            if (wid_in != 640) {
                if (wid_in == 320) {
                    if (hgt_in == 200) {
                        return this->ModeAvail320_200_16;
                    }
                    if (hgt_in == 240) {
                        return this->ModeAvail320_240_16;
                    }
                }
            } else {
                return this->ModeAvail640_16;
            }
        } else {
            if (wid_in != 800) {
                if (wid_in == 1024) {
                    return this->ModeAvail1024_16;
                }
            } else {
                return this->ModeAvail800_16;
            }
        }
    }
    return 0;
}

int TDrawSystem::Init(
    void* inst_in, void* wnd_in, void* pal_in, unsigned char type_in, unsigned char mode_in, long wid_in, long hgt_in,
    unsigned long flags_in
) {
    DDSURFACEDESC ddsd;
    DDBLTFX ddbltfx;
    DDCAPS ddcaps;
    PALETTEENTRY color_table[256];

    this->Inst = inst_in;
    this->Wnd = wnd_in;
    this->Pal = pal_in;
    this->DrawType = type_in;
    this->ScreenMode = mode_in;
    this->ScreenWidth = wid_in;
    this->ScreenHeight = hgt_in;
    this->Flags = flags_in;

    if (type_in == 1)
        return 0;

    if (DirectDrawCreate(0, &this->DirDraw, 0) != 0) {
        this->ErrorCode = 1;
        return 0;
    }

    this->CheckAvailModes(1);

    if (this->ScreenMode == 1) {
        if (this->DirDraw->SetCooperativeLevel(this->Wnd, DDSCL_NORMAL) != 0) {
            this->ErrorCode = 1;
            return 0;
        }

        memset(&ddsd, 0, sizeof(ddsd));
        ddsd.dwSize = sizeof(ddsd);
        if (this->DirDraw->GetDisplayMode(&ddsd) != 0) {
            this->ErrorCode = 1;
            return 0;
        }
        if (ddsd.ddpfPixelFormat.dwRGBBitCount != 8) {
            this->ErrorCode = 2;
            return 0;
        }
    } else {
        if (this->DirDraw->SetCooperativeLevel(this->Wnd, DDSCL_FULLSCREEN | DDSCL_EXCLUSIVE) != 0) {
            this->ErrorCode = 1;
            return 0;
        }

        this->ColorBits = 8;
        if (this->DirDraw->SetDisplayMode(this->ScreenWidth, this->ScreenHeight, 8) != 0) {
            this->ErrorCode = 1;
            return 0;
        }
        this->ChangedMode = 1;
    }

    if (this->Pal != 0) {
        GetPaletteEntries(this->Pal, 0, 256, color_table);
    } else {
        for (int index = 0; index < 256; ++index) {
            color_table[index].peRed = 0;
            color_table[index].peBlue = 0;
            color_table[index].peGreen = 0;
            color_table[index].peFlags = 0;
        }
    }

    for (int index = 0; index < 256; ++index) {
        this->palette[index].peRed = 0;
        this->palette[index].peBlue = 0;
        this->palette[index].peGreen = 0;
        this->palette[index].peFlags = 0;
    }

    if (this->DirDraw->CreatePalette(DDPCAPS_8BIT | DDPCAPS_ALLOW256, color_table, &this->DirDrawPal, 0) != 0) {
        this->ErrorCode = 1;
        return 0;
    }
    this->DirDrawPal->SetEntries(0, 0, 256, this->palette);

    if (this->DirDraw->CreateClipper(0, &this->Clipper, 0) != 0) {
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

    IDirectDraw* direct_draw = this->DirDraw;
    this->IsBanked = 0;
    ddcaps.dwSize = sizeof(ddcaps);
    if (direct_draw->GetCaps(&ddcaps, 0) == 0) {
        if ((ddcaps.dwCaps & 0x08000000) != 0)
            this->IsBanked = 1;

        if ((ddcaps.dwCaps & 0x00400000) != 0 && (ddcaps.dwCKeyCaps & 0x00000200) != 0)
            this->CanSrcBlt = 1;
    }

    if (this->ScreenMode == 2) {
        ddbltfx.dwSize = sizeof(ddbltfx);
        ddbltfx.dwFillColor = 0;
        this->PrimarySurface->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
    }

    return 1;
}

int TDrawSystem::SetDisplaySize(long wid_in, long hgt_in, int color_bits) {
    _DDBLTFX ddbltfx;
    long save_wid;
    long save_hgt;

    if (this->DrawType != 2 || this->ScreenMode != 2)
        return 0;

    system_ignore_size_messages = 1;
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = 0;
    this->PrimarySurface->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
    save_wid = this->ScreenWidth;
    save_hgt = this->ScreenHeight;
    this->ScreenWidth = wid_in;
    this->ScreenHeight = hgt_in;

    if (this->DirDraw->SetDisplayMode(this->ScreenWidth, this->ScreenHeight, color_bits) != 0) {
        system_ignore_size_messages = 0;
        this->ScreenWidth = save_wid;
        this->ScreenHeight = save_hgt;
        return 0;
    }

    system_ignore_size_messages = 0;
    this->ColorBits = color_bits;
    this->ChangedMode = 1;

    if (this->PrimarySurface != 0) {
        this->PrimarySurface->Release();
        this->PrimarySurface = 0;
    }

    this->CreateSurfaces();
    if (this->DrawArea != 0)
        this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);

    SendMessageA(this->Wnd, WM_SIZE, 0, MAKELONG(wid_in, hgt_in));
    return 1;
}

void TDrawSystem::ClearPrimarySurface() {
    if (this->ScreenMode != 2)
        return;

    IDirectDrawSurface* surface = this->PrimarySurface;
    if (surface == 0)
        return;

    _DDBLTFX ddbltfx;
    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = 0;
    surface->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
}

unsigned char TDrawSystem::CheckSurfaces() {
    if (this->DrawType != 2)
        return 0;

    if (this->PrimarySurface != 0 && this->DrawArea != 0 && this->DrawArea->DrawSurface != 0) {
        unsigned char result = 0;
        _DDSURFACEDESC ddsd;
        _DDBLTFX ddbltfx;

        long hr = this->PrimarySurface->IsLost();
        if (hr != 0) {
            this->GetIsLostErrorNum(hr);
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);

            hr = this->DirDraw->GetDisplayMode(&ddsd);
            if (hr == 0
                && (ddsd.dwWidth != (unsigned long) this->ScreenWidth
                    || ddsd.dwHeight != (unsigned long) this->ScreenHeight || ddsd.ddpfPixelFormat.dwRGBBitCount != 8))
                return 1;

            hr = this->PrimarySurface->Restore();
            if (hr != 0) {
                this->GetRestoreErrorNum(hr);
                return 3;
            }

            this->Restored = 1;
            result = 2;
            ddbltfx.dwSize = sizeof(ddbltfx);
            ddbltfx.dwFillColor = 0;
            this->PrimarySurface->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
        }

        DrawAreaNode* node = this->DrawAreaList;
        while (node != 0) {
            if (node->DrawArea != this->PrimaryArea && node->DrawArea->CheckSurface() == 3)
                return 3;
            node = node->NextNode;
        }
        return result;
    }
    return 3;
}

void TDrawSystem::ClearRestored() {
    DrawAreaNode* node;

    node = this->DrawAreaList;
    this->Restored = 0;
    while (node != 0) {
        node->DrawArea->Restored = 0;
        node = node->NextNode;
    }
}

void TDrawSystem::DeleteSurfaces() {
    if (this->DrawArea != 0) {
        delete this->DrawArea;
        this->DrawArea = 0;
    }

    if (this->PrimarySurface != 0) {
        if (this->PrimaryArea != 0)
            delete this->PrimaryArea;

        this->PrimaryArea = 0;
        this->PrimarySurface->Release();
        this->PrimarySurface = 0;
    }
}

int TDrawSystem::CreateSurfaces() {
    DDSURFACEDESC ddsd;
    DDBLTFX ddbltfx;
    RECT wnd_rect;

    if (this->DrawType == 2) {
        if (this->PrimarySurface == 0) {
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);
            ddsd.dwFlags = DDSD_CAPS;
            ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE;
            if (this->DirDraw->CreateSurface(&ddsd, &this->PrimarySurface, 0))
                return 0;
            if (this->ScreenMode == 2) {
                ddbltfx.dwSize = sizeof(ddbltfx);
                ddbltfx.dwFillColor = 0;
                this->PrimarySurface->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
            }
            if (this->ColorBits == 8) {
                if (this->PrimarySurface->SetPalette(this->DirDrawPal))
                    return 0;
            }
            if (this->PrimarySurface->SetClipper(this->Clipper))
                return 0;
        }
        if (this->PrimaryArea == 0) {
            TDrawArea* area = new TDrawArea("Primary Area", 0);
            this->PrimaryArea = area;
            if (area == 0)
                return 0;
            if (this->ScreenMode == 1) {
                GetClientRect(this->Wnd, &wnd_rect);
                if (!this->PrimaryArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 1))
                    return 0;
            } else {
                if (!area->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 1))
                    return 0;
            }
        }
    }
    if (this->DrawArea == 0) {
        TDrawArea* area2 = new TDrawArea("Draw Area", 0);
        this->DrawArea = area2;
        if (area2 == 0)
            return 0;
        if (this->ScreenMode == 1) {
            GetClientRect(this->Wnd, &wnd_rect);
            if (!this->DrawArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 0))
                return 0;
        } else {
            if (!area2->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 0))
                return 0;
        }
    }
    return 1;
}

void TDrawSystem::HandleSize(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    if (this->DrawArea == 0)
        return;

    if (this->DrawType == 1 || this->ScreenMode == 1) {
        RECT rect;
        GetClientRect(this->Wnd, &rect);
        this->ScreenWidth = rect.right;
        this->ScreenHeight = rect.bottom;
    }

    if (this->PrimaryArea != 0) {
        this->PrimaryArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
    }

    this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);
}

void TDrawSystem::HandlePaletteChanged(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    if (hwnd != this->Wnd) {
        HandleQueryNewPalette(hwnd, msg, wParam, lParam);
    }
}

int TDrawSystem::HandleQueryNewPalette(void* hwnd, unsigned int msg, unsigned int wParam, long lParam) {
    if (this->Pal != 0 && (this->DrawType == 1 || this->ScreenMode == 1)) {
        void* hdc = GetDC(this->Wnd);
        if (this->Pal != 0)
            SelectPalette(hdc, this->Pal, 0);
        unsigned char result = (unsigned char) RealizePalette(hdc);
        ReleaseDC(this->Wnd, hdc);
        if (result != 0) {
            InvalidateRect(this->Wnd, NULL, FALSE);
            return 1;
        }
    }
    this->ModifyPalette(0, 256, this->palette);
    return 0;
}

void TDrawSystem::Paint(tagRECT* rect) {
    tagRECT dest;
    tagRECT src;

    if (this->DrawType == 1 || this->PrimarySurface == 0 || this->DrawArea == 0 || this->DrawArea->DrawSurface == 0)
        return;

    if (this->ScreenMode == 1) {
        GetClientRect(this->Wnd, &src);

        dest.left = src.left;
        dest.top = src.top;
        dest.right = src.right;
        dest.bottom = src.bottom;

        ClientToScreen(this->Wnd, (POINT*) &dest.left);
        ClientToScreen(this->Wnd, (POINT*) &dest.right);
    } else {
        src.left = 0;
        src.top = 0;
        src.right = this->ScreenWidth;
        src.bottom = this->ScreenHeight;

        dest.left = 0;
        dest.top = 0;
        dest.right = this->ScreenWidth;
        dest.bottom = this->ScreenHeight;
    }

    if (rect != 0) {
        int left = rect->left;
        int top = rect->top;
        int right = rect->right;
        int bottom = rect->bottom;

        if (left < 0)
            left = 0;
        if (top < 0)
            top = 0;
        if (right >= this->ScreenWidth)
            right = this->ScreenWidth - 1;
        if (bottom >= this->ScreenHeight)
            bottom = this->ScreenHeight - 1;

        src.left = left;
        src.top = top;
        dest.left += left;
        dest.top += top;
        dest.right = dest.left + right - left + 1;
        dest.bottom = dest.top + bottom - top + 1;

        src.right = right + 1;
        src.bottom = bottom + 1;
    }

    this->PrimarySurface->Blt(&dest, this->DrawArea->DrawSurface, &src, DDBLT_WAIT, 0);
}

int TDrawSystem::GetIsLostErrorNum(long ddrval) {
    switch (ddrval) {
        case 0x88760082:
            return 0x6A4;
        case 0x80070057:
            return 0x6A5;
        case 0x887601C2:
            return 0x6A6;
        case 0:
            return 0;
        default:
            return 0x707;
    }
}

int TDrawSystem::GetRestoreErrorNum(long ddrval) {
    switch (ddrval) {
        case 0:
            return 0;
        case (long) 0x80004005:
            return 0x708;
        case (long) 0x8876024C:
            return 0x709;
        case (long) 0x8876005F:
            return 0x70A;
        case (long) 0x88760082:
            return 0x70B;
        case (long) 0x80070057:
            return 0x70C;
        case (long) 0x887600E1:
            return 0x70D;
        case (long) 0x8007000E:
            return 0x70E;
        case (long) 0x80004001:
            return 0x70F;
        case (long) 0x8876024B:
            return 0x710;
        default:
            return 0x76B;
    }
}

int TDrawSystem::GetSetDispModeErrorNum(long ddrval) {
    switch (ddrval) {
        case (long) 0x00000000:
            return 0;
        case (long) 0x80004001:
            return 0x773;
        case (long) 0x80004005:
            return 0x76C;
        case (long) 0x80070057:
            return 0x76F;
        case (long) 0x88760078:
            return 0x76D;
        case (long) 0x88760082:
            return 0x76E;
        case (long) 0x887600A0:
            return 0x770;
        case (long) 0x887600E1:
            return 0x771;
        case (long) 0x887601AE:
            return 0x772;
        case (long) 0x8876021C:
            return 0x775;
        case (long) 0x8876024E:
            return 0x774;
        default:
            return 0x7CF;
    }
}

int TDrawSystem::GetLockErrorNum(long ddrval) {
    switch (ddrval) {
        case 0:
            return 0;
        case (long) 0x80004005:
            return 0x7D0;
        case (long) 0x88760082:
            return 0x7D1;
        case (long) 0x80070057:
            return 0x7D2;
        case (long) 0x887601AE:
            return 0x7D3;
        case (long) 0x887601C2:
            return 0x7D4;
        case (long) 0x8876021C:
            return 0x7D5;
        case (long) 0x8007000E:
            return 0x7D6;
        case (long) 0x88760248:
            return 0x7D7;
        case (long) 0x88760096:
            return 0x7D8;
        default:
            return 0x833;
    }
}

int TDrawSystem::GetDCErrorNum(long ddrval) {
    switch (ddrval) {
        case 0:
            return 0;
        case -2147467259L:
            return 0x834;
        case -2147467263L:
            return 0x83A;
        case -2147024809L:
            return 0x837;
        case -2005532542L:
            return 0x836;
        case -2005532222L:
            return 0x839;
        case -2005532132L:
            return 0x83B;
        case -2005532080L:
            return 0x838;
        case -2005532052L:
            return 0x835;
        default:
            return 0x897;
    }
}

int TDrawSystem::GetBlitErrorNum(long ddrval) {
    switch (ddrval) {
        case 0:
            return 0;
        case (long) 0x80004005:
            return 0x898;
        case (long) 0x88760082:
            return 0x899;
        case (long) 0x80070057:
            return 0x89A;
        case (long) 0x88760154:
            return 0x89B;
        case (long) 0x8876006E:
            return 0x89C;
        case (long) 0x88760096:
            return 0x89D;
        case (long) 0x887600B4:
            return 0x89E;
        case (long) 0x887601C2:
            return 0x8A2;
        case (long) 0x887600CD:
            return 0x8A0;
        case (long) 0x88760240:
            return 0x8A1;
        case (long) 0x8876023F:
            return 0x89F;
        case (long) 0x80004001:
            return 0x8A3;
        case (long) 0x887600FA:
            return 0x8A4;
        case (long) 0x88760118:
            return 0x8A5;
        case (long) 0x88760122:
            return 0x8A6;
        case (long) 0x88760136:
            return 0x8A7;
        case (long) 0x887601AE:
            return 0x8A8;
        default:
            return 0x8FB;
    }
}

int TDrawSystem::GetCreateErrorNum(long ddrval) {
    switch (ddrval) {
        case 0:
            return 0;
        case (long) 0x80004005:
            return 0x8FC;
        case (long) 0x88760082:
            return 0x8FD;
        case (long) 0x80070057:
            return 0x8FE;
        case (long) 0x8876017C:
            return 0x8FF;
        case (long) 0x88760233:
            return 0x900;
        case (long) 0x887600D4:
            return 0x901;
        case (long) 0x88760064:
            return 0x902;
        case (long) 0x88760091:
            return 0x903;
        case (long) 0x887600B4:
            return 0x904;
        case (long) 0x887600E6:
            return 0x905;
        case (long) 0x88760154:
            return 0x906;
        case (long) 0x887600E1:
            return 0x907;
        case (long) 0x8007000E:
            return 0x908;
        case (long) 0x88760234:
            return 0x909;
        case (long) 0x88760235:
            return 0x90A;
        case (long) 0x8876005F:
            return 0x90B;
        default:
            return 0x95F;
    }
}

int TDrawSystem::GetColorKeyErrorNum(long ddrval) {
    switch (ddrval) {
        case 0:
            return 0;
        case (long) 0x80004005:
            return 0x960;
        case (long) 0x88760082:
            return 0x961;
        case (long) 0x80070057:
            return 0x962;
        case (long) 0x88760250:
            return 0x963;
        case (long) 0x88760104:
            return 0x964;
        case (long) 0x88760244:
            return 0x965;
        case (long) 0x887601C2:
            return 0x966;
        case (long) 0x80004001:
            return 0x967;
        case (long) 0x8876021C:
            return 0x968;
        default:
            return 0x9C3;
    }
}

void TDrawSystem::SetPalette(void* pal_in) {
    tagPALETTEENTRY color_table[256];

    this->Pal = pal_in;

    if (pal_in) {
        GetPaletteEntries(pal_in, 0, 256, color_table);
    } else {
        for (int index = 0; index < 256; ++index) {
            color_table[index].peRed = 0;
            color_table[index].peGreen = 0;
            color_table[index].peBlue = 0;
            color_table[index].peFlags = 0;
        }
    }

    color_table[0].peRed = 0;
    color_table[0].peGreen = 0;
    color_table[0].peBlue = 0;
    color_table[0].peFlags = 0;

    color_table[255].peRed = 0xFF;
    color_table[255].peGreen = 0xFF;
    color_table[255].peBlue = 0xFF;
    color_table[255].peFlags = 0;

    this->ModifyPalette(0, 256, color_table);
}

void TDrawSystem::ModifyPalette(int start_entry, int num_entries, PALETTEENTRY* pal_entries) {
    PalSetRes = -99;

    if (num_entries == 256) {
        FullPalSets++;
    }

    for (int i = start_entry; i < start_entry + num_entries; i++) {
        palette[i] = pal_entries[i - start_entry];
    }

    if (DrawType != 1 && DirDrawPal != 0) {
        if (num_entries == 7) {
            AniPalSets++;
        }
        DirDrawPal->SetEntries(0, start_entry, num_entries, pal_entries);
    }
}

TDrawArea::TDrawArea(char* SurfaceName, int ForceSystemMem) {
    this->DrawSystem = 0;
    this->Wnd = 0;
    this->DrawSurface = 0;
    this->UsingVidMem = 0;
    this->DrawDc = 0;
    this->BitmapInfo = 0;
    this->Bitmap = 0;
    this->OldBitmap = 0;
    this->Bits = 0;
    this->Width = 0;
    this->Height = 0;
    this->Pitch = 0;
    this->UseTrans = 0;
    this->TransColor = 0xFF;
    this->Node = 0;
    this->Restored = 0;
    this->IsPrimarySurface = 0;
    this->SystemMemOnly = ForceSystemMem;
    this->ClipRect.left = 0;
    this->ClipRect.top = 0;
    this->ClipRect.right = 0;
    this->ClipRect.bottom = 0;
    this->LastBits = 0;
    this->DisplayOffsets = 0;
    this->CurDisplayOffsets = 0;
    this->DisplayOffsetsSz = 0;
    this->ExtendedLines = 0;
    this->FloatOffsets = 0;
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    this->FloatOffsetsSz = 0;

    memset(&this->SurfaceDesc, 0, sizeof(this->SurfaceDesc));
    this->BitmapInfo = (BITMAPINFO256*) calloc(1, 1064);
    this->Orien = 1;
    this->SpanList = 0;
    this->CurSpanList = 0;
    this->shadow_color_table = 0;

    int name_length = (int) strlen(SurfaceName);
    if (name_length > 0) {
        this->Name = (char*) malloc(name_length + 1);
        strcpy(this->Name, SurfaceName);
    } else {
        this->Name = 0;
    }
}

TDrawArea::~TDrawArea() {
    DrawAreaNode* node = this->Node;
    if (node != 0) {
        TDrawSystem* draw_system = this->DrawSystem;
        if (draw_system != 0 && node == draw_system->DrawAreaList) {
            draw_system->DrawAreaList = node->NextNode;
        }

        node = this->Node->PrevNode;
        if (node != 0) {
            node->NextNode = this->Node->NextNode;
        }

        node = this->Node->NextNode;
        if (node != 0) {
            node->PrevNode = this->Node->PrevNode;
        }

        free(this->Node);
        this->Node = 0;
    }

    if (this->DrawSystem == 0 || this->DrawSystem->DrawType != 1) {
        IDirectDrawSurface* surface = this->DrawSurface;
        if (surface != 0 && this->IsPrimarySurface == 0) {
            surface->Release();
            this->DrawSurface = 0;
        }
    } else if (this->DrawDc != 0) {
        if (this->Bitmap != 0) {
            if (this->OldBitmap != 0) {
                SelectObject(this->DrawDc, this->OldBitmap);
            }
            DeleteObject(this->Bitmap);
        }
        DeleteDC(this->DrawDc);
    }

    if (this->BitmapInfo != 0) {
        free(this->BitmapInfo);
    }
    if (this->DisplayOffsets != 0) {
        free(this->DisplayOffsets);
    }
    if (this->FloatOffsets != 0) {
        free(this->FloatOffsets);
    }

    TSpan_List_Manager* span_list = this->SpanList;
    if (span_list != 0) {
        delete span_list;
    }

    if (this->Name != 0) {
        free(this->Name);
    }
}

int TDrawArea::Init(TDrawSystem* draw_system_in, long wid_in, long hgt_in, int Extend, int isPrimary_in) {
    DrawAreaNode* node;
    DrawAreaNode* cur;

    this->DrawSystem = draw_system_in;
    this->IsPrimarySurface = isPrimary_in;
    if (draw_system_in != 0) {
        this->Wnd = draw_system_in->Wnd;
        if (this->Node == 0) {
            node = (DrawAreaNode*) calloc(1, 12);
            this->Node = node;
            if (node == 0) {
                return 0;
            }

            node->DrawArea = this;
            this->Node->PrevNode = 0;
            this->Node->NextNode = 0;
            cur = this->DrawSystem->DrawAreaList;
            if (cur == 0) {
                this->DrawSystem->DrawAreaList = this->Node;
            } else {
                while (cur->NextNode != 0)
                    cur = cur->NextNode;
                cur->NextNode = this->Node;
                this->Node->PrevNode = cur;
            }
        }

        if (this->DrawSystem->DrawType == 1) {
            return 0;
        }
    }

    this->SetSize(wid_in, hgt_in, Extend);
    return 1;
}

unsigned char TDrawArea::CheckSurface() {
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        if (this->DrawSurface == 0)
            return 3;

        long hr = this->DrawSurface->IsLost();
        if (hr != 0) {
            this->DrawSystem->GetIsLostErrorNum(hr);

            _DDSURFACEDESC ddsd;
            _DDBLTFX ddbltfx;
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);

            hr = this->DrawSystem->DirDraw->GetDisplayMode(&ddsd);
            if (hr == 0
                && (ddsd.dwWidth != (unsigned long) this->DrawSystem->ScreenWidth
                    || ddsd.dwHeight != (unsigned long) this->DrawSystem->ScreenHeight
                    || ddsd.ddpfPixelFormat.dwRGBBitCount != 8))
                return 1;

            hr = this->DrawSurface->Restore();
            if (hr != 0) {
                if (hr == (long) 0x8876024B || hr == (long) 0x8007000E) {
                    this->DrawSurface->Release();
                    this->DrawSurface = 0;
                    this->SetSize(this->Width, this->Height, 0);
                    if (this->DrawSurface != 0)
                        return 2;
                }

                this->DrawSystem->GetRestoreErrorNum(hr);
                return 3;
            }

            ddbltfx.dwSize = sizeof(ddbltfx);
            ddbltfx.dwFillColor = 0;
            this->DrawSurface->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
            this->Restored = 1;
            return 2;
        }
    }
    return 0;
}

unsigned char* TDrawArea::Lock(char* caller_name, int wait) {
    if (this->DrawSystem != 0) {
        if (this->DrawSystem->DrawType == 1)
            return this->Bits;
    }

    if (this->DrawSurface == 0)
        return 0;

    if (this->Bits != 0)
        return this->Bits;

    if (this->DrawDc != 0)
        return 0;

    int hr;
    if (wait) {
        hr = this->DrawSurface->Lock(0, &this->SurfaceDesc, 1, 0);
    } else {
        hr = this->DrawSurface->Lock(0, &this->SurfaceDesc, 0, 0);
    }

    if (hr != 0)
        return 0;

    this->Bits = (unsigned char*) this->SurfaceDesc.lpSurface;
    this->SetInfo();

    if (this->Bits != this->LastBits)
        this->SetAccessOffsets();

    return this->Bits;
}

void TDrawArea::Unlock(char* caller_name) {
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->Bits == 0)
        return;

    this->DrawSurface->Unlock(this->Bits);
    this->Bits = 0;
}

void* TDrawArea::GetDc(char* caller_name) {
    if (this->DrawSystem != 0) {
        if (this->DrawSystem->DrawType == 1)
            return this->DrawDc;
    }

    if (this->DrawSurface == 0)
        return 0;

    if (this->DrawDc != 0)
        return this->DrawDc;

    if (this->Bits != 0)
        return 0;

    IDirectDrawSurface* surface = this->DrawSurface;
    surface->GetDC(&this->DrawDc);
    return this->DrawDc;
}

void TDrawArea::ReleaseDc(char* caller_name) {
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->DrawDc == 0)
        return;

    this->DrawSurface->ReleaseDC(this->DrawDc);
    this->DrawDc = 0;
}

void TDrawArea::SetSize(long wid_in, long hgt_in, int ExtendSurface) {
    DDSURFACEDESC ddsd;
    DDBLTFX ddbltfx;
    TDrawSystem* draw_system = this->DrawSystem;

    if (draw_system != 0 && draw_system->DrawType != 1) {
        if (this->DrawSystem != 0 && this->DrawSystem->DirDraw != 0 && wid_in != 0 && hgt_in != 0
            && (wid_in != this->Width || hgt_in != this->Height || this->DrawSurface == 0)) {
            if (wid_in < 1) {
                wid_in = 1;
            }
            if (hgt_in < 1) {
                hgt_in = 1;
            }

            long surface_height = hgt_in + 10;
            if (ExtendSurface == 0) {
                surface_height = hgt_in;
            }

            this->ExtendedLines = ExtendSurface;
            this->BitmapInfo->bmiHeader.biWidth = wid_in;
            if (this->Orien == 1) {
                this->BitmapInfo->bmiHeader.biHeight = -surface_height;
            } else {
                this->BitmapInfo->bmiHeader.biHeight = surface_height;
            }
            this->Width = wid_in;
            this->Height = hgt_in;

            if (this->IsPrimarySurface == 0) {
                if (this->DrawSurface != 0) {
                    this->DrawSurface->Release();
                    this->DrawSurface = 0;
                    memset(&this->SurfaceDesc, 0, sizeof(this->SurfaceDesc));
                    this->Pitch = 0;
                    this->UsingVidMem = 0;
                }

                memset(&ddsd, 0, sizeof(ddsd));
                ddsd.dwSize = sizeof(ddsd);
                ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
                if ((this->DrawSystem->Flags & 1) != 0 || ExtendSurface != 0 || this->SystemMemOnly != 0) {
                    ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
                } else {
                    ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
                }
                ddsd.dwHeight = surface_height;
                ddsd.dwWidth = this->Width;

                if (this->DrawSystem->DirDraw->CreateSurface(&ddsd, &this->DrawSurface, 0) == 0) {
                    this->SurfaceDesc.dwSize = sizeof(this->SurfaceDesc);
                    long hr = this->DrawSurface->GetSurfaceDesc(&this->SurfaceDesc);
                    if (hr == 0) {
                        this->SetInfo();
                        this->SetAccessOffsets();
                        ddbltfx.dwSize = sizeof(ddbltfx);
                        ddbltfx.dwFillColor = 0;
                        this->DrawSurface->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
                    } else {
                        this->DrawSystem->GetCreateErrorNum(hr);
                    }
                }
            } else {
                this->DrawSurface = this->DrawSystem->PrimarySurface;
            }

            this->SetClipRect(0);
            this->Clear(0, 0);
        }
    }

    if (this->SpanList != 0) {
        delete this->SpanList;
    }

    this->SpanList = new TSpan_List_Manager(wid_in, hgt_in);
    int i = 0;
    if (hgt_in > 0) {
        do {
            this->SpanList->AddSpan(0, wid_in - 1, i);
            ++i;
        } while (i < hgt_in);
    }
    this->CurSpanList = this->SpanList;
}

void TDrawArea::Clear(tagRECT* rect, int color) {
    RECT dest;
    DDBLTFX ddbltfx;
    int wid;

    if (DDSys_CanColorFill == 0) {
        this->PtrClear(rect, color);
        return;
    }

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1) {
        unsigned char* bits = this->Bits;
        if (bits == 0)
            return;

        if (rect == 0) {
            memset(bits, color, this->Height * this->Pitch);
            return;
        }

        long left = rect->left;
        long top = rect->top;
        long right = rect->right;
        long bottom = rect->bottom;

        if (left < 0)
            left = 0;
        else if (left >= this->Width)
            left = this->Width - 1;

        if (top < 0)
            top = 0;
        else if (top >= this->Height)
            top = this->Height - 1;

        if (right < 0)
            right = 0;
        else if (right >= this->Width)
            right = this->Width - 1;

        if (bottom < 0)
            bottom = 0;
        else if (bottom >= this->Height)
            bottom = this->Height - 1;

        if (right <= left || bottom <= top)
            return;

        wid = right - left + 1;
        int delta;
        if (this->Orien == 1) {
            bits += top * this->Pitch + left;
            delta = this->Pitch;
        } else {
            bits += (this->Height - top - 1) * this->Pitch + left;
            delta = -this->Pitch;
        }

        if (top <= bottom) {
            int height = bottom - top + 1;
            do {
                memset(bits, color, wid);
                bits += delta;
                --height;
            } while (height != 0);
        }
        return;
    }

    IDirectDrawSurface* surface = this->DrawSurface;
    if (surface == 0)
        return;

    ddbltfx.dwSize = sizeof(ddbltfx);
    ddbltfx.dwFillColor = color;
    if (rect == 0) {
        surface->Blt(0, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
        return;
    }

    dest.left = rect->left;
    dest.top = rect->top;
    dest.right = rect->right;
    dest.bottom = rect->bottom;
    ++dest.right;
    ++dest.bottom;
    surface->Blt(&dest, 0, 0, DDBLT_WAIT | DDBLT_COLORFILL, &ddbltfx);
}

void TDrawArea::SetAccessOffsets() {
    int size = this->Height << 2;
    if (size != this->DisplayOffsetsSz) {
        if (this->DisplayOffsets != 0)
            free(this->DisplayOffsets);
        this->DisplayOffsets = (void**) malloc(size);
        this->DisplayOffsetsSz = size;
        this->CurDisplayOffsets = this->DisplayOffsets;
    }

    unsigned char* p;
    int delta;
    if (this->Orien == 1 || this->ExtendedLines != 0) {
        // Extended surfaces place five extra rows before the visible rows.
        if (this->ExtendedLines == 0)
            p = this->Bits;
        else
            p = this->Bits + this->Pitch * 5;

        delta = this->Pitch;
        if (this->ExtendedLines != 0)
            delta = this->Width;
    } else {
        p = this->Bits + (this->Height - 1) * this->Pitch;
        delta = -this->Pitch;
    }

    int i = 0;
    if (this->Height > 0) {
        do {
            this->DisplayOffsets[i] = p;
            p += delta;
            ++i;
        } while (i < this->Height);
    }

    if (this->FloatOffsets != 0)
        this->SetFloatOffsets(this->Float_X_Delta, this->Float_Y_Delta);

    this->LastBits = this->Bits;
}

void TDrawArea::SetFloatOffsets(int X_Delta, int Y_Delta) {
    int size = this->Height << 2;
    if (size != 0 && this->ExtendedLines != 0 && X_Delta >= 0 && Y_Delta >= 0) {
        if (size != this->FloatOffsetsSz) {
            if (this->FloatOffsets != 0)
                free(this->FloatOffsets);
            this->FloatOffsets = (void**) malloc(size);
            this->FloatOffsetsSz = size;
        }

        int out = 0;
        int cur = Y_Delta;
        if (this->Height > 0) {
            do {
                this->FloatOffsets[out] = (void*) ((unsigned char*) this->DisplayOffsets[cur] + X_Delta);
                cur++;
                if (cur >= this->Height)
                    cur = 0;
                out++;
            } while (out < this->Height);
        }
        this->Float_X_Delta = X_Delta;
        this->Float_Y_Delta = Y_Delta;
        this->CurDisplayOffsets = this->FloatOffsets;
    }
}

void TDrawArea::SetInfo(void) {
    this->Pitch = this->SurfaceDesc.lPitch;
    this->BitmapInfo->bmiHeader.biWidth = this->SurfaceDesc.lPitch;
    if ((this->SurfaceDesc.ddsCaps.dwCaps & DDSCAPS_SYSTEMMEMORY) != 0) {
        this->UsingVidMem = 0;
        return;
    }
    this->UsingVidMem = 1;
}

long TDrawArea::AlignedWidth() {
    return this->Pitch;
}

void TDrawArea::SetClipRect(tagRECT* rect) {
    if (rect != 0) {
        this->ClipRect.left = rect->left;
        this->ClipRect.top = rect->top;
        this->ClipRect.right = rect->right;
        this->ClipRect.bottom = rect->bottom;

        if (this->ClipRect.left < 0) {
            this->ClipRect.left = 0;
        } else if (this->ClipRect.left > this->Width - 1) {
            this->ClipRect.left = this->Width - 1;
        }

        if (this->ClipRect.right < 0) {
            this->ClipRect.right = 0;
        } else if (this->ClipRect.right > this->Width - 1) {
            this->ClipRect.right = this->Width - 1;
        }

        if (this->ClipRect.top < 0) {
            this->ClipRect.top = 0;
        } else if (this->ClipRect.top > this->Height - 1) {
            this->ClipRect.top = this->Height - 1;
        }

        if (this->ClipRect.bottom < 0) {
            this->ClipRect.bottom = 0;
        } else if (this->ClipRect.bottom > this->Height - 1) {
            this->ClipRect.bottom = this->Height - 1;
        }

        if (this->ClipRect.right < this->ClipRect.left) {
            long temp = this->ClipRect.right;
            this->ClipRect.right = this->ClipRect.left;
            this->ClipRect.left = temp;
        }

        if (this->ClipRect.bottom < this->ClipRect.top) {
            long temp = this->ClipRect.bottom;
            this->ClipRect.bottom = this->ClipRect.top;
            this->ClipRect.top = temp;
        }
    } else {
        this->ClipRect.left = 0;
        this->ClipRect.top = 0;
        this->ClipRect.right = this->Width - 1;
        this->ClipRect.bottom = this->Height - 1;
    }

    this->SetClipRect(this->ClipRect.left, this->ClipRect.top, this->ClipRect.right, this->ClipRect.bottom);
}

void TDrawArea::SetClipRect(long x1, long y1, long x2, long y2) {
    TSpan_List_Manager* span_list = this->SpanList;

    this->ClipRect.left = x1;
    this->ClipRect.top = y1;
    this->ClipRect.right = x2;
    this->ClipRect.bottom = y2;

    if (span_list != 0 && span_list->Num_Lines != this->Height) {
        if (this->SpanList != 0) {
            delete this->SpanList;
        }
        this->SpanList = 0;
    }

    if (this->SpanList == 0) {
        span_list = new TSpan_List_Manager(this->Width, this->Height);
        this->SpanList = span_list;
    }

    this->SpanList->ResetAll();
    span_list = this->SpanList;
    span_list->SetSpanRegions(this->ClipRect.left, this->ClipRect.top, this->ClipRect.right, this->ClipRect.bottom);

    int y = this->ClipRect.top;
    if (y <= this->ClipRect.bottom) {
        do {
            this->SpanList->AddSpan(this->ClipRect.left, this->ClipRect.right, y);
            ++y;
        } while (y <= this->ClipRect.bottom);
    }

    this->CurSpanList = this->SpanList;
}

void TDrawArea::Copy(TDrawArea* dest_area, long dest_x, long dest_y, RECT* src_rect, int allow_trans) {
    static long ddrval;
    static int err;
    tagRECT dest_rect2;
    tagRECT src_rect2;

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1) {
        if (this->Bits == 0 || dest_area == 0 || dest_area->Bits == 0)
            return;

        long src_x;
        long src_y;
        long width;
        long height;
        if (src_rect == 0) {
            src_x = 0;
            src_y = 0;
            width = this->Width;
            height = this->Height;
        } else {
            src_x = src_rect->left;
            src_y = src_rect->top;
            width = src_rect->right - src_x + 1;
            height = src_rect->bottom - src_y + 1;
        }

        if (src_x + width > this->Width)
            width = this->Width - src_x;
        if (src_y + height > this->Height)
            height = this->Height - src_y;

        if (this->UseTrans != 0 && allow_trans != 0) {
            TransDibBlt(
                dest_area->BitmapInfo, dest_area->Bits, &dest_area->ClipRect, dest_x, dest_y, width, height,
                this->BitmapInfo, this->Bits, 0, src_x, src_y, width, height, 1, 0, 0, this->TransColor
            );
        } else {
            DibBlt(
                dest_area->BitmapInfo, dest_area->Bits, &dest_area->ClipRect, dest_x, dest_y, width, height,
                this->BitmapInfo, this->Bits, src_x, src_y, width, height, 1, 0, 0
            );
        }
        err = 0;
        return;
    }

    if (this->DrawSurface == 0 || dest_area == 0 || dest_area->DrawSurface == 0)
        return;

    if (src_rect == 0) {
        src_rect2.left = 0;
        src_rect2.top = 0;
        src_rect2.right = this->Width - 1;
        src_rect2.bottom = this->Height - 1;
    } else {
        src_rect2.left = src_rect->left;
        src_rect2.top = src_rect->top;
        src_rect2.right = src_rect->right;
        src_rect2.bottom = src_rect->bottom;
    }

    ++src_rect2.right;
    ++src_rect2.bottom;
    SetRect(
        &dest_rect2, dest_x, dest_y, dest_x + src_rect2.right - src_rect2.left,
        dest_y + src_rect2.bottom - src_rect2.top
    );

    if (src_rect2.left < 0) {
        long amount = -src_rect2.left;
        src_rect2.left = 0;
        dest_rect2.left += amount;
    }
    if (src_rect2.top < 0) {
        long amount = -src_rect2.top;
        src_rect2.top = 0;
        dest_rect2.top += amount;
    }
    if (src_rect2.right > this->Width) {
        long amount = src_rect2.right - this->Width;
        src_rect2.right -= amount;
        dest_rect2.right -= amount;
    }
    if (src_rect2.bottom > this->Height) {
        long amount = src_rect2.bottom - this->Height;
        src_rect2.bottom -= amount;
        dest_rect2.bottom -= amount;
    }

    if (dest_rect2.left < dest_area->ClipRect.left) {
        long amount = dest_area->ClipRect.left - dest_rect2.left;
        dest_rect2.left += amount;
        src_rect2.left += amount;
    }
    if (dest_rect2.top < dest_area->ClipRect.top) {
        long amount = dest_area->ClipRect.top - dest_rect2.top;
        dest_rect2.top += amount;
        src_rect2.top += amount;
    }
    if (dest_rect2.right > dest_area->ClipRect.right + 1) {
        long amount = dest_rect2.right - dest_area->ClipRect.right - 1;
        dest_rect2.right -= amount;
        src_rect2.right -= amount;
    }
    if (dest_rect2.bottom > dest_area->ClipRect.bottom + 1) {
        long amount = dest_rect2.bottom - dest_area->ClipRect.bottom - 1;
        dest_rect2.bottom -= amount;
        src_rect2.bottom -= amount;
    }

    if (dest_rect2.left >= dest_rect2.right || dest_rect2.top >= dest_rect2.bottom || src_rect2.left >= src_rect2.right
        || src_rect2.top >= src_rect2.bottom)
        return;

    ddrval = 1;
    if (this->UseTrans != 0 && allow_trans != 0) {
        ddrval = dest_area->DrawSurface->Blt(&dest_rect2, this->DrawSurface, &src_rect2, DDBLT_WAIT | DDBLT_KEYSRC, 0);
    } else {
        ddrval = dest_area->DrawSurface->Blt(&dest_rect2, this->DrawSurface, &src_rect2, DDBLT_WAIT, 0);
    }

    err = 0;
    if (ddrval != 0)
        err = this->DrawSystem->GetBlitErrorNum(ddrval);
    if (err != 0)
        return;
    err = 0;
}

void TDrawArea::SetTrans(int use_trans_in, unsigned char trans_color_in) {
    this->UseTrans = use_trans_in;

    if (use_trans_in != 0)
        this->TransColor = trans_color_in;
    else
        this->TransColor = 0xFF;

    if (use_trans_in == 0)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->DrawSystem == 0)
        return;

    if (this->DrawSystem->DrawType != 2)
        return;

    int ddck[2];
    ddck[0] = this->TransColor;
    ddck[1] = this->TransColor;
    this->DrawSurface->SetColorKey(DDCKEY_SRCBLT, (DDCOLORKEY*) ddck);
}

void TDrawArea::SetOverlayTrans(int use_trans_in, unsigned char trans_color_in) {
    this->UseTrans = use_trans_in;
    this->TransColor = trans_color_in;

    if (use_trans_in == 0)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->DrawSystem == 0)
        return;

    if (this->DrawSystem->DrawType != 2)
        return;

    int ddck[2];
    ddck[0] = trans_color_in;
    ddck[1] = trans_color_in;
    this->DrawSurface->SetColorKey(DDCKEY_SRCOVERLAY, (DDCOLORKEY*) ddck);
}

void TDrawArea::SetPixel(long x, long y, unsigned char color) {
    if (Bits == 0) {
        return;
    }

    if (x < ClipRect.left || x > ClipRect.right) {
        return;
    }

    if (y < ClipRect.top || y > ClipRect.bottom) {
        return;
    }

    if (Orien == 1) {
        Bits[Pitch * y + x] = color;
    } else {
        Bits[((Height - y) - 1) * Pitch + x] = color;
    }
}

void TDrawArea::DrawLine(int x1, int y1, int x2, int y2, unsigned char color) {
    int temp;

    if (x1 == x2) {
        if (y1 > y2) {
            temp = y1;
            y1 = y2;
            y2 = temp;
        }

        for (; y1 <= y2; ++y1)
            ASMDraw_HLine(x1, x2, y1, color);
        return;
    }

    if (y1 == y2) {
        ASMDraw_HLine(x1, x2, y1, color);
        return;
    }

    if (x2 < x1) {
        temp = y1;
        y1 = y2;
        y2 = temp;

        temp = x1;
        x1 = x2;
        x2 = temp;
    }

    int x_length = x2 - x1 + 1;
    int y = y1;
    int y_length;
    int y_step;

    if (y1 < y2) {
        y_length = y2 - y1 + 1;
        y_step = 1;
    } else {
        y_length = y1 - y2 + 1;
        y_step = -1;
    }

    if (y_length <= x_length) {
        int error = 0;
        int run_start = x1;

        while (x1 < x2) {
            error += y_length;
            if (error >= x_length) {
                ASMDraw_HLine(run_start, x1, y, color);
                y += y_step;
                error -= x_length;
                run_start = x1 + 1;
            }
            ++x1;
        }
        ASMDraw_HLine(run_start, x1, y, color);
        return;
    }

    int error = 0;
    for (;;) {
        ASMDraw_HLine(x1, x1, y, color);
        if (y == y2)
            return;

        error += x_length;
        if (error >= y_length) {
            ++x1;
            error -= y_length;
        }
        y += y_step;
    }
}

void TDrawArea::DrawRect(long x1, long y1, long x2, long y2, unsigned char color) {
    // Ensure x1 <= x2
    if (x1 > x2) {
        int tmp = x1;
        x1 = x2;
        x2 = tmp;
    }

    // Ensure y1 <= y2
    if (y1 > y2) {
        int tmp = y1;
        y1 = y2;
        y2 = tmp;
    }

    int w = x2 - x1 + 1;
    if (w < 1)
        return;

    int h = y2 - y1 + 1;
    if (h < 1)
        return;

    // Draw rectangle outline
    this->DrawHorzLine(x1, y1, w, color);
    this->DrawHorzLine(x1, y2, w, color);
    this->DrawVertLine(x1, y1, h, color);
    this->DrawVertLine(x2, y1, h, color);
}

void TDrawArea::DrawRect(tagRECT* rect, unsigned char mode) {
    DrawRect(rect->left, rect->top, rect->right, rect->bottom, mode);
}

void TDrawArea::DrawHorzLine(long x, long y, long len, unsigned char color) {
    if (this->Bits == 0)
        return;

    if (x > this->ClipRect.right)
        return;

    if (y < this->ClipRect.top || y > this->ClipRect.bottom)
        return;

    if (x < this->ClipRect.left) {
        len += x - this->ClipRect.left;
        x = this->ClipRect.left;
    }

    if (x + len - 1 > this->ClipRect.right) {
        len = this->ClipRect.right - x + 1;
    }

    if (len < 1)
        return;

    int offset;
    if (this->Orien == 1)
        offset = this->Pitch * y;
    else
        offset = (this->Height - y - 1) * this->Pitch;

    memset(this->Bits + offset + x, color, len);
}

void TDrawArea::DrawVertLine(long x, long y, long len, unsigned char color) {
    unsigned char* bits = this->Bits;
    if (bits == 0)
        return;
    if (x < this->ClipRect.left || x > this->ClipRect.right)
        return;
    if (y > this->ClipRect.bottom)
        return;
    if (y < this->ClipRect.top) {
        len += y - this->ClipRect.top;
        y = this->ClipRect.top;
    }
    if (y + len - 1 > this->ClipRect.bottom)
        len = this->ClipRect.bottom - y + 1;
    if (len < 1)
        return;

    unsigned char* dest;
    int step;
    if (this->Orien == 1) {
        dest = bits + y * this->Pitch + x;
        step = this->Pitch;
    } else {
        dest = bits + (this->Height - y - 1) * this->Pitch + x;
        step = -this->Pitch;
    }
    while (len > 0) {
        *dest = color;
        dest += step;
        len--;
    }
}

void TDrawArea::FillRect(long x1, long y1, long x2, long y2, unsigned char color) {
    long rect_wid;
    long height;
    long delta;
    unsigned char* p;

    if (this->Bits != 0) {
        if (x1 > x2) {
            long temp = x1;
            x1 = x2;
            x2 = temp;
        }

        if (y1 > y2) {
            long temp = y1;
            y1 = y2;
            y2 = temp;
        }

        if (x1 > this->ClipRect.right || x2 < this->ClipRect.left || y1 > this->ClipRect.bottom
            || y2 < this->ClipRect.top)
            return;

        if (x1 < this->ClipRect.left)
            x1 = this->ClipRect.left;
        if (x2 > this->ClipRect.right)
            x2 = this->ClipRect.right;
        if (y1 < this->ClipRect.top)
            y1 = this->ClipRect.top;
        if (y2 > this->ClipRect.bottom)
            y2 = this->ClipRect.bottom;

        rect_wid = x2 - x1 + 1;
        height = y2 - y1 + 1;
        if (rect_wid < 1 || height < 1)
            return;

        if (this->Orien == 1) {
            p = this->Bits + (y1 * this->Pitch + x1);
            delta = this->Pitch;
        } else {
            p = this->Bits + ((this->Height - y1 - 1) * this->Pitch + x1);
            delta = -this->Pitch;
        }

        while (height > 0) {
            memset(p, color, rect_wid);
            p += delta;
            --height;
        }
    }
}

void TDrawArea::DrawBevel(long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2) {
    if (x1 > x2) {
        long temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        long temp = y1;
        y1 = y2;
        y2 = temp;
    }

    long w = x2 - x1 + 1;
    if (w < 1)
        return;
    long rect_hgt = y2 - y1 + 1;
    if (rect_hgt < 1)
        return;

    DrawHorzLine(x1 + 1, y1, w - 1, c1);
    DrawVertLine(x2, y1 + 1, rect_hgt - 1, c1);
    DrawHorzLine(x1, y2, w, c2);
    DrawVertLine(x1, y1, rect_hgt - 1, c2);
}

void TDrawArea::DrawBevel2(
    long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4
) {
    int width;
    int height;
    int x1_plus_one;
    int y1_plus_one;

    if (x1 > x2) {
        long temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        long temp = y1;
        y1 = y2;
        y2 = temp;
    }

    width = x2 - x1 + 1;
    if (width < 1)
        return;
    height = y2 - y1 + 1;
    if (height < 1)
        return;

    x1_plus_one = x1 + 1;
    DrawHorzLine(x1_plus_one, y1, width - 1, c1);
    y1_plus_one = y1 + 1;
    DrawVertLine(x2, y1_plus_one, height - 2, c1);
    DrawHorzLine(x1 + 2, y1_plus_one, width - 3, c2);
    DrawVertLine(x2 - 1, y1 + 2, height - 4, c2);
    DrawHorzLine(x1, y2, width, c4);
    DrawVertLine(x1, y1, height - 1, c4);
    DrawHorzLine(x1_plus_one, y2 - 1, width - 2, c3);
    DrawVertLine(x1_plus_one, y1_plus_one, height - 3, c3);
}

void TDrawArea::DrawBevel3(
    long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4,
    unsigned char c5, unsigned char c6
) {
    if (x1 > x2) {
        long temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        long temp = y1;
        y1 = y2;
        y2 = temp;
    }

    int width = x2 - x1 + 1;
    if (width < 1)
        return;
    int height = y2 - y1 + 1;
    if (height < 1)
        return;

    int x1_plus_one = x1 + 1;
    DrawHorzLine(x1_plus_one, y1, width - 1, c1);
    int y1_plus_one = y1 + 1;
    DrawVertLine(x2, y1_plus_one, height - 2, c1);
    int x1_plus_two = x1 + 2;
    DrawHorzLine(x1_plus_two, y1_plus_one, width - 3, c2);
    int y1_plus_two = y1 + 2;
    DrawVertLine(x2 - 1, y1_plus_two, height - 4, c2);
    DrawHorzLine(x1 + 3, y1_plus_two, width - 5, c3);
    DrawVertLine(x2 - 2, y1 + 3, height - 6, c3);
    DrawHorzLine(x1, y2, width, c6);
    DrawVertLine(x1, y1, height - 1, c6);
    DrawHorzLine(x1_plus_one, y2 - 1, width - 2, c5);
    DrawVertLine(x1_plus_one, y1_plus_one, height - 3, c5);
    DrawHorzLine(x1_plus_two, y2 - 2, width - 4, c4);
    DrawVertLine(x1_plus_two, y1_plus_two, height - 5, c4);
}

void TDrawArea::DrawBevel21(
    long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4
) {
    if (x1 > x2) {
        long temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        long temp = y1;
        y1 = y2;
        y2 = temp;
    }

    long width = x2 - x1 + 1;
    if (width < 1)
        return;
    long height = y2 - y1 + 1;
    if (height < 1)
        return;

    DrawHorzLine(x1 + 1, y1, width - 1, c1);
    DrawVertLine(x2, y1 + 1, height - 2, c1);
    DrawHorzLine(x1 + 1, y1 + 1, width - 2, c2);
    DrawVertLine(x2 - 1, y1 + 2, height - 3, c2);
    DrawHorzLine(x1, y2, width, c4);
    DrawVertLine(x1, y1, height - 1, c4);
}

void TDrawArea::DrawBevel32(
    long x1, long y1, long x2, long y2, unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4,
    unsigned char c5, unsigned char c6
) {
    if (x1 > x2) {
        long temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        long temp = y1;
        y1 = y2;
        y2 = temp;
    }

    int width = x2 - x1 + 1;
    if (width < 1)
        return;
    int height = y2 - y1 + 1;
    if (height < 1)
        return;

    DrawHorzLine(x1 + 1, y1, width - 1, c1);
    DrawVertLine(x2, y1 + 1, height - 2, c1);
    DrawHorzLine(x1 + 2, y1 + 1, width - 3, c2);
    DrawVertLine(x2 - 1, y1 + 2, height - 4, c2);
    DrawHorzLine(x1 + 2, y1 + 2, width - 4, c3);
    DrawVertLine(x2 - 2, y1 + 3, height - 5, c3);
    DrawHorzLine(x1, y2, width, c6);
    DrawVertLine(x1, y1, height - 1, c6);
    DrawHorzLine(x1 + 1, y2 - 1, width - 2, c5);
    DrawVertLine(x1 + 1, y1 + 1, height - 3, c5);
}

void TDrawArea::SetShadowTable(RGE_Color_Table* color_table_in) {
    this->shadow_color_table = color_table_in;
}

void TDrawArea::DrawShadowBox(long x1, long y1, long x2, long y2) {
    if (this->shadow_color_table == 0 || this->Bits == 0)
        return;

    if (x1 < this->ClipRect.left)
        x1 = this->ClipRect.left;
    if (y1 < this->ClipRect.top)
        y1 = this->ClipRect.top;
    if (x2 > this->ClipRect.right)
        x2 = this->ClipRect.right;
    if (y2 > this->ClipRect.bottom)
        y2 = this->ClipRect.bottom;

    if (x1 < 0)
        x1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (x2 >= this->Width)
        x2 = this->Width - 1;
    if (y2 >= this->Height)
        y2 = this->Height - 1;

    if (x1 <= x2 && y1 <= y2) {
        int orientation = this->Orien;
        int row_size = this->AlignedWidth() * orientation;
        int row_offset;

        if (orientation < 1) {
            row_offset = y1 - this->Height + 1;
            row_offset *= row_size;
        } else {
            row_offset = row_size * y1;
        }

        RGE_Color_Table* table = this->shadow_color_table;
        unsigned char* start = this->Bits + row_offset + x1;
        unsigned char* end = start;
        end -= x1;
        end += x2;

        if (y1 <= y2) {
            int rows = y2 - y1 + 1;
            unsigned char* row_start = start;
            do {
                for (; start <= end; ++start)
                    *start = table->table[*start];

                start = row_start + row_size;
                end += row_size;
                --rows;
                row_start = start;
            } while (rows != 0);
        }
    }
}

void TDrawArea::GetPalette(tagPALETTEENTRY* palette1) {
    for (int i = 0; i < 256; ++i)
        palette1[i] = this->DrawSystem->Palette[i];
}

void TDrawArea::SetPalette(tagPALETTEENTRY* palette1) {
    palette1[0].peRed = 0;
    palette1[0].peGreen = 0;
    palette1[0].peBlue = 0;
    palette1[0].peFlags = 0;

    palette1[255].peRed = 0xFF;
    palette1[255].peGreen = 0xFF;
    palette1[255].peBlue = 0xFF;
    palette1[255].peFlags = 0;

    this->DrawSystem->ModifyPalette(0, 256, palette1);
}

void TDrawArea::take_snapshot(char* filespec, int& index_no) {
    BITMAPFILEHEADER bmFH;
    BITMAPINFOHEADER bmIH;
    char BMPFile[60];
    RGBQUAD bmPAL[256];
    PALETTEENTRY thePal[256];

    int bmWide = this->Width;
    int bitmap_height = this->Height;
    int row_width = (bmWide + 3) & 0xFFFC;

    bmFH.bfType = 0x4D42;
    bmFH.bfSize = bitmap_height * row_width + 0x436;
    bmFH.bfReserved1 = 0;
    bmFH.bfReserved2 = 0;
    bmFH.bfOffBits = 0x436;

    bmIH.biSize = sizeof(bmIH);
    bmIH.biWidth = bmWide;
    bmIH.biHeight = bitmap_height;
    bmIH.biPlanes = 1;
    bmIH.biBitCount = 8;
    bmIH.biCompression = 0;
    bmIH.biSizeImage = 0;
    bmIH.biXPelsPerMeter = 0;
    bmIH.biYPelsPerMeter = 0;
    bmIH.biClrUsed = 0;
    bmIH.biClrImportant = 0;

    BMPFile[0] = '\0';
    this->GetPalette(thePal);
    for (int i = 0; i < 256; ++i) {
        bmPAL[i].rgbBlue = thePal[i].peBlue;
        bmPAL[i].rgbGreen = thePal[i].peGreen;
        bmPAL[i].rgbRed = thePal[i].peRed;
        bmPAL[i].rgbReserved = 0;
    }

    int attempts = 0;
    for (;;) {
        if (filespec == 0)
            sprintf(BMPFile, "C:\\AOE_%03d.BMP", index_no);
        else
            sprintf(BMPFile, filespec, index_no);

        ++attempts;
        int existing_file = _open(BMPFile, 0);
        if (existing_file == -1)
            break;

        ++index_no;
        close(existing_file);
        if (attempts > 1000)
            return;
    }

    unsigned char* row = (unsigned char*) malloc(row_width);
    int output_file = _open(BMPFile, _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC, _S_IREAD | _S_IWRITE);
    if (output_file != -1) {
        write(output_file, &bmFH, sizeof(bmFH));
        write(output_file, &bmIH, sizeof(bmIH));
        write(output_file, bmPAL, sizeof(bmPAL));

        if (this->Lock("take_snapshot", 1) != 0) {
            // A positive BMP height stores the display rows from bottom to top.
            for (int y = bitmap_height - 1; y >= 0; --y) {
                unsigned char* source = (unsigned char*) this->CurDisplayOffsets[y];
                for (int x = 0; x < this->Width; ++x)
                    row[x] = source[x];
                write(output_file, row, row_width);
            }
            this->Unlock("take_snapshot");
        }
        close(output_file);
    }
    free(row);
}
