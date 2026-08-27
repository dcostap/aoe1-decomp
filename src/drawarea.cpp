#include "../include/drawarea.h"
#include "../include/color.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern "C" void __cdecl _ASMSet_Shadowing(int, int, int, int);
extern "C" void __cdecl _ASMDraw_HLine(int, int, int, unsigned int);
extern int DDSys_CanColorFill;
extern int PalSetRes;
extern int FullPalSets;
extern int AniPalSets;
extern unsigned int DAT_0062e64c;
extern unsigned int DAT_0062e650;
struct TRANSINFO;
extern "C" void __cdecl TransDibBlt(
    BITMAPINFO256*, unsigned char*, RECT*, long, long, long, long,
    BITMAPINFO256*, unsigned char*, TRANSINFO*, long, long, long, long,
    int, int, int, int);
extern "C" void __cdecl DibBlt(
    BITMAPINFO256*, unsigned char*, RECT*, long, long, long, long,
    BITMAPINFO256*, unsigned char*, long, long, long, long, int, int, int);
extern "C" int __cdecl __open(const char*, int, ...);
extern "C" int __cdecl write(int, void*, int);
extern "C" int __cdecl close(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern void* __cdecl calloc(unsigned int, unsigned int);
extern void* __cdecl operator new(unsigned int);
#define system_ignore_size_messages (*(int*)0x62E63C)
#pragma function(memset)

TDrawSystem::TDrawSystem()
{
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
    _ASMSet_Shadowing(0x00ff00ff, 0, 0xff00ff00, 0);
}

TDrawSystem::~TDrawSystem()
{
    DDBLTFX ddbltfx;
    if (this->ScreenMode == 2 && this->PrimarySurface != 0) {
        IDirectDrawSurface* s = this->PrimarySurface;
        ddbltfx.dwSize = 0x64;
        ddbltfx.dwFillColor = 0;
        s->Blt(0, 0, 0, 0x1000400, &ddbltfx);
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

void TDrawSystem::CheckAvailModes(int param_1)
{
    if (param_1 == 0) {
        this->ModeAvail640 = 1;
        void* dc = CreateICA("DISPLAY", 0, 0, 0);
        if (dc != 0) {
            int width = GetDeviceCaps(dc, 8);
            GetDeviceCaps(dc, 10);
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

long __stdcall TDrawSystem::CheckAvailModesCallback(
    _DDSURFACEDESC* mode_desc, void* context)
{
    register long result = 1;
    TDrawSystem* mode_info = (TDrawSystem*)context;
    int bpp = mode_desc->ddpfPixelFormat.dwRGBBitCount;

    if (bpp == 8) {
        if (mode_desc->dwWidth == 640 && mode_desc->dwHeight == 480) {
            mode_info->ModeAvail640 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 800 && mode_desc->dwHeight == 600) {
            mode_info->ModeAvail800 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 1024 && mode_desc->dwHeight == 768) {
            mode_info->ModeAvail1024 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 1280 && mode_desc->dwHeight == 1024) {
            mode_info->ModeAvail1280 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 320 && mode_desc->dwHeight == 200) {
            mode_info->ModeAvail320_200 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 320 && mode_desc->dwHeight == 240) {
            mode_info->ModeAvail320_240 = 1;
            goto done;
        }
    } else if (bpp == 16) {
        if (mode_desc->dwWidth == 640 && mode_desc->dwHeight == 480) {
            mode_info->ModeAvail640_16 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 800 && mode_desc->dwHeight == 600) {
            mode_info->ModeAvail800_16 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 1024 && mode_desc->dwHeight == 768) {
            mode_info->ModeAvail1024_16 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 320 && mode_desc->dwHeight == 200) {
            mode_info->ModeAvail320_200_16 = 1;
            goto done;
        }
        if (mode_desc->dwWidth == 320 && mode_desc->dwHeight == 240) {
            mode_info->ModeAvail320_240_16 = 1;
            goto done;
        }
    }
done:
    return result;
}

int TDrawSystem::IsModeAvail(long width, long height, int bpp)
{
    if (bpp == 8) {
        if (width <= 0x280) {
            if (width != 0x280) {
                if (width == 0x140) {
                    if (height == 0xC8) {
                        return this->ModeAvail320_200;
                    }
                    if (height == 0xF0) {
                        return this->ModeAvail320_240;
                    }
                }
            } else {
                return this->ModeAvail640;
            }
        } else {
            if (width != 0x320) {
                if (width != 0x400) {
                    if (width == 0x500) {
                        return this->ModeAvail1280;
                    }
                } else {
                    return this->ModeAvail1024;
                }
            } else {
                return this->ModeAvail800;
            }
        }
    } else if (bpp == 0x10) {
        if (width <= 0x280) {
            if (width != 0x280) {
                if (width == 0x140) {
                    if (height == 0xC8) {
                        return this->ModeAvail320_200_16;
                    }
                    if (height == 0xF0) {
                        return this->ModeAvail320_240_16;
                    }
                }
            } else {
                return this->ModeAvail640_16;
            }
        } else {
            if (width != 0x320) {
                if (width == 0x400) {
                    return this->ModeAvail1024_16;
                }
            } else {
                return this->ModeAvail800_16;
            }
        }
    }
    return 0;
}

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
        if (ddsd.ddpfPixelFormat.dwRGBBitCount != 8) {
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
    this->DirDrawPal->SetEntries(0, 0, 0x100, this->palette);

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

int TDrawSystem::SetDisplaySize(long wid, long hgt, int bits)
{
    _DDBLTFX ddbltfx;
    long save_wid;
    long save_hgt;

    if (this->DrawType != 2 || this->ScreenMode != 2)
        return 0;

    system_ignore_size_messages = 1;
    ddbltfx.dwSize = 100;
    ddbltfx.dwFillColor = 0;
    this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
    save_wid = this->ScreenWidth;
    save_hgt = this->ScreenHeight;
    this->ScreenWidth = wid;
    this->ScreenHeight = hgt;

    if (this->DirDraw->SetDisplayMode(this->ScreenWidth, this->ScreenHeight, bits) != 0) {
        system_ignore_size_messages = 0;
        this->ScreenWidth = save_wid;
        this->ScreenHeight = save_hgt;
        return 0;
    }

    system_ignore_size_messages = 0;
    this->ColorBits = bits;
    this->ChangedMode = 1;

    if (this->PrimarySurface != 0) {
        this->PrimarySurface->Release();
        this->PrimarySurface = 0;
    }

    this->CreateSurfaces();
    if (this->DrawArea != 0)
        this->DrawArea->SetSize(this->ScreenWidth, this->ScreenHeight, 0);

    SendMessageA(this->Wnd, 5, 0, MAKELONG(wid, hgt));
    return 1;
}

void TDrawSystem::ClearPrimarySurface()
{
    if (this->ScreenMode != 2)
        return;

    IDirectDrawSurface* surface = this->PrimarySurface;
    if (surface == 0)
        return;

    _DDBLTFX ddbltfx;
    ddbltfx.dwSize = 0x64;
    ddbltfx.dwFillColor = 0;
    surface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
}

unsigned char TDrawSystem::CheckSurfaces()
{
    if (this->DrawType != 2)
        return 0;

    if (this->PrimarySurface != 0 && this->DrawArea != 0 &&
        this->DrawArea->DrawSurface != 0) {
        unsigned char result = 0;
        _DDSURFACEDESC ddsd;
        _DDBLTFX ddbltfx;

        long hr = this->PrimarySurface->IsLost();
        if (hr != 0) {
            this->GetIsLostErrorNum(hr);
            memset(&ddsd, 0, sizeof(ddsd));
            ddsd.dwSize = sizeof(ddsd);

            hr = this->DirDraw->GetDisplayMode(&ddsd);
            if (hr == 0 &&
                (ddsd.dwWidth != (unsigned long)this->ScreenWidth ||
                 ddsd.dwHeight != (unsigned long)this->ScreenHeight ||
                 ddsd.ddpfPixelFormat.dwRGBBitCount != 8))
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
            this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
        }

        DrawAreaNode* node = this->DrawAreaList;
        while (node != 0) {
            if (node->DrawArea != this->PrimaryArea &&
                node->DrawArea->CheckSurface() == 3)
                return 3;
            node = node->NextNode;
        }
        return result;
    }
    return 3;
}

void TDrawSystem::ClearRestored()
{
    DrawAreaNode* node;

    node = this->DrawAreaList;
    this->Restored = 0;
    while (node != 0) {
        node->DrawArea->Restored = 0;
        node = node->NextNode;
    }
}

void TDrawSystem::DeleteSurfaces()
{
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

int TDrawSystem::CreateSurfaces()
{
    DDSURFACEDESC ddsd;
    DDBLTFX ddbltfx;
    RECT wnd_rect;

    if (this->DrawType == 2) {
        if (this->PrimarySurface == 0) {
            memset(&ddsd, 0, 0x6c);
            ddsd.dwSize = 0x6c;
            ddsd.dwFlags = 1;
            ddsd.ddsCaps.dwCaps = 0x200;
            if (this->DirDraw->CreateSurface(&ddsd, &this->PrimarySurface, 0)) return 0;
            if (this->ScreenMode == 2) {
                ddbltfx.dwSize = 0x64;
                ddbltfx.dwFillColor = 0;
                this->PrimarySurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
            }
            if (this->ColorBits == 8) {
                if (this->PrimarySurface->SetPalette(this->DirDrawPal)) return 0;
            }
            if (this->PrimarySurface->SetClipper(this->Clipper)) return 0;
        }
        if (this->PrimaryArea == 0) {
            TDrawArea* area = new TDrawArea("Primary Area", 0);
            this->PrimaryArea = area;
            if (area == 0) return 0;
            if (this->ScreenMode == 1) {
                GetClientRect(this->Wnd, &wnd_rect);
                if (!this->PrimaryArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 1)) return 0;
            } else {
                if (!area->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 1)) return 0;
            }
        }
    }
    if (this->DrawArea == 0) {
        TDrawArea* area2 = new TDrawArea("Draw Area", 0);
        this->DrawArea = area2;
        if (area2 == 0) return 0;
        if (this->ScreenMode == 1) {
            GetClientRect(this->Wnd, &wnd_rect);
            if (!this->DrawArea->Init(this, wnd_rect.right, wnd_rect.bottom, 0, 0)) return 0;
        } else {
            if (!area2->Init(this, this->ScreenWidth, this->ScreenHeight, 0, 0)) return 0;
        }
    }
    return 1;
}

void TDrawSystem::HandleSize(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    if (this->DrawArea == 0) return;

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

void TDrawSystem::HandlePaletteChanged(void* hwnd, unsigned int msg, unsigned int wparam, long lparam) {
    if (hwnd != this->Wnd) {
        HandleQueryNewPalette(hwnd, msg, wparam, lparam);
    }
}

int TDrawSystem::HandleQueryNewPalette(void* param1, unsigned int param2, unsigned int param3, long param4)
{
    if (this->Pal != 0 && (this->DrawType == 1 || this->ScreenMode == 1)) {
        void* hdc = GetDC(this->Wnd);
        if (this->Pal != 0)
            SelectPalette(hdc, this->Pal, 0);
        unsigned char result = (unsigned char)RealizePalette(hdc);
        ReleaseDC(this->Wnd, hdc);
        if (result != 0) {
            InvalidateRect(this->Wnd, 0, 0);
            return 1;
        }
    }
    this->ModifyPalette(0, 256, (tagPALETTEENTRY*)((char*)this + 0x78));
    return 0;
}

void TDrawSystem::Paint(tagRECT* param_1)
{
    tagRECT dest;
    tagRECT src;
    long dest_top;

    if (this->DrawType != 1) {
    if (this->PrimarySurface &&
        this->DrawArea &&
        this->DrawArea->DrawSurface) {
        if (this->ScreenMode == 1) {
        GetClientRect(this->Wnd, &src);
        dest.left = src.left;
        dest.top = src.top;
        dest.right = src.right;
        dest.bottom = src.bottom;
        ClientToScreen(this->Wnd, (POINT*)&dest.left);
        ClientToScreen(this->Wnd, (POINT*)&dest.right);
        } else {
            int w = this->ScreenWidth;
            int h = this->ScreenHeight;
            src.left = 0;
            src.top = 0;
            src.right = w;
            src.bottom = h;
            dest.left = 0;
            dest.top = 0;
            dest.right = w;
            dest.bottom = h;
        }

        if (param_1) {
        src.left = param_1->left;
        src.top = param_1->top;
        src.right = param_1->right;
        src.bottom = param_1->bottom;

        if (src.left < 0) src.left = 0;
        if (src.top < 0) src.top = 0;
        if (src.right >= this->ScreenWidth)
            src.right = this->ScreenWidth - 1;
        if (src.bottom >= this->ScreenHeight)
            src.bottom = this->ScreenHeight - 1;

        dest.left = dest.left + src.left;
        dest_top = dest.top;
        dest_top = dest_top + src.top;
        dest.top = dest_top;
        dest.right = dest.left + src.right - src.left + 1;
        dest.bottom = dest_top + src.bottom - src.top + 1;

        src.right += 1;
        src.bottom += 1;
        }

        this->PrimarySurface->Blt(&dest, this->DrawArea->DrawSurface,
                                  &src, 0x1000000, 0);
    }
    }
}

int TDrawSystem::GetIsLostErrorNum(long error_num) {
    switch (error_num) {
    case 0x88760082: return 0x6A4;
    case 0x80070057: return 0x6A5;
    case 0x887601C2: return 0x6A6;
    case 0: return 0;
    default: return 0x707;
    }
}

int TDrawSystem::GetRestoreErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x708;
    case (long)0x8876024C:
        return 0x709;
    case (long)0x8876005F:
        return 0x70A;
    case (long)0x88760082:
        return 0x70B;
    case (long)0x80070057:
        return 0x70C;
    case (long)0x887600E1:
        return 0x70D;
    case (long)0x8007000E:
        return 0x70E;
    case (long)0x80004001:
        return 0x70F;
    case (long)0x8876024B:
        return 0x710;
    default:
        return 0x76B;
    }
}

int TDrawSystem::GetSetDispModeErrorNum(long hr)
{
    switch (hr) {
    case (long)0x00000000: return 0;
    case (long)0x80004001: return 0x773;
    case (long)0x80004005: return 0x76C;
    case (long)0x80070057: return 0x76F;
    case (long)0x88760078: return 0x76D;
    case (long)0x88760082: return 0x76E;
    case (long)0x887600A0: return 0x770;
    case (long)0x887600E1: return 0x771;
    case (long)0x887601AE: return 0x772;
    case (long)0x8876021C: return 0x775;
    case (long)0x8876024E: return 0x774;
    default: return 0x7CF;
    }
}

int TDrawSystem::GetLockErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x7D0;
    case (long)0x88760082:
        return 0x7D1;
    case (long)0x80070057:
        return 0x7D2;
    case (long)0x887601AE:
        return 0x7D3;
    case (long)0x887601C2:
        return 0x7D4;
    case (long)0x8876021C:
        return 0x7D5;
    case (long)0x8007000E:
        return 0x7D6;
    case (long)0x88760248:
        return 0x7D7;
    case (long)0x88760096:
        return 0x7D8;
    default:
        return 0x833;
    }
}

int TDrawSystem::GetBlitErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x898;
    case (long)0x88760082:
        return 0x899;
    case (long)0x80070057:
        return 0x89A;
    case (long)0x88760154:
        return 0x89B;
    case (long)0x8876006E:
        return 0x89C;
    case (long)0x88760096:
        return 0x89D;
    case (long)0x887600B4:
        return 0x89E;
    case (long)0x887601C2:
        return 0x8A2;
    case (long)0x887600CD:
        return 0x8A0;
    case (long)0x88760240:
        return 0x8A1;
    case (long)0x8876023F:
        return 0x89F;
    case (long)0x80004001:
        return 0x8A3;
    case (long)0x887600FA:
        return 0x8A4;
    case (long)0x88760118:
        return 0x8A5;
    case (long)0x88760122:
        return 0x8A6;
    case (long)0x88760136:
        return 0x8A7;
    case (long)0x887601AE:
        return 0x8A8;
    default:
        return 0x8FB;
    }
}

int TDrawSystem::GetCreateErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x8FC;
    case (long)0x88760082:
        return 0x8FD;
    case (long)0x80070057:
        return 0x8FE;
    case (long)0x8876017C:
        return 0x8FF;
    case (long)0x88760233:
        return 0x900;
    case (long)0x887600D4:
        return 0x901;
    case (long)0x88760064:
        return 0x902;
    case (long)0x88760091:
        return 0x903;
    case (long)0x887600B4:
        return 0x904;
    case (long)0x887600E6:
        return 0x905;
    case (long)0x88760154:
        return 0x906;
    case (long)0x887600E1:
        return 0x907;
    case (long)0x8007000E:
        return 0x908;
    case (long)0x88760234:
        return 0x909;
    case (long)0x88760235:
        return 0x90A;
    case (long)0x8876005F:
        return 0x90B;
    default:
        return 0x95F;
    }
}

int TDrawSystem::GetColorKeyErrorNum(long hr)
{
    switch (hr) {
    case 0:
        return 0;
    case (long)0x80004005:
        return 0x960;
    case (long)0x88760082:
        return 0x961;
    case (long)0x80070057:
        return 0x962;
    case (long)0x88760250:
        return 0x963;
    case (long)0x88760104:
        return 0x964;
    case (long)0x88760244:
        return 0x965;
    case (long)0x887601C2:
        return 0x966;
    case (long)0x80004001:
        return 0x967;
    case (long)0x8876021C:
        return 0x968;
    default:
        return 0x9C3;
    }
}

void TDrawSystem::SetPalette(void* hPal)
{
    tagPALETTEENTRY color_table[256];
    tagPALETTEENTRY* p;
    int count;

    this->Pal = hPal;

    if (hPal) {
        GetPaletteEntries(hPal, 0, 0x100, color_table);
    } else {
        p = color_table;
        count = 0x100;
        do {
            p->peRed = 0;
            p->peGreen = 0;
            p->peBlue = 0;
            p->peFlags = 0;
            p++;
            count--;
        } while (count != 0);
    }

    color_table[0].peRed = 0;
    color_table[0].peGreen = 0;
    color_table[0].peBlue = 0;
    color_table[0].peFlags = 0;

    color_table[255].peRed = 0xFF;
    color_table[255].peGreen = 0xFF;
    color_table[255].peBlue = 0xFF;
    color_table[255].peFlags = 0;

    this->ModifyPalette(0, 0x100, color_table);
}

void TDrawSystem::ModifyPalette(int start, int count, PALETTEENTRY* entries) {
    PalSetRes = -99;

    if (count == 256) {
        FullPalSets++;
    }

    for (int i = start; i < start + count; i++) {
        palette[i] = entries[i - start];
    }

    if (DrawType != 1 && DirDrawPal != 0) {
        if (count == 7) {
            AniPalSets++;
        }
        DirDrawPal->SetEntries(0, start, count, entries);
    }
}

TDrawArea::TDrawArea(char* name, int system_mem_only)
{
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
    this->SystemMemOnly = system_mem_only;
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

    memset(&this->SurfaceDesc, 0, 0x6C);
    this->BitmapInfo = (BITMAPINFO256*)calloc(1, 0x428);
    this->Orien = 1;
    this->SpanList = 0;
    this->CurSpanList = 0;
    this->shadow_color_table = 0;

    int name_length = (int)strlen(name);
    if (name_length > 0) {
        this->Name = (char*)malloc(name_length + 1);
        strcpy(this->Name, name);
    }
    else {
        this->Name = 0;
    }
}

TDrawArea::~TDrawArea()
{
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
    }
    else if (this->DrawDc != 0) {
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

int TDrawArea::Init(TDrawSystem* draw_system, long width, long height,
                    int flags, int is_primary)
{
    DrawAreaNode* node;
    DrawAreaNode* cur;

    this->DrawSystem = draw_system;
    this->IsPrimarySurface = is_primary;
    if (draw_system != 0) {
        this->Wnd = draw_system->Wnd;
        if (this->Node == 0) {
            node = (DrawAreaNode*)calloc(1, 0x0C);
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
                for (node = cur->NextNode; node != 0; node = node->NextNode) {
                    cur = node;
                }
                cur->NextNode = this->Node;
                this->Node->PrevNode = cur;
            }
        }

        if (this->DrawSystem->DrawType == 1) {
            return 0;
        }
    }

    this->SetSize(width, height, flags);
    return 1;
}

unsigned char TDrawArea::CheckSurface()
{
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
            if (hr == 0 &&
                (ddsd.dwWidth != (unsigned long)this->DrawSystem->ScreenWidth ||
                 ddsd.dwHeight != (unsigned long)this->DrawSystem->ScreenHeight ||
                 ddsd.ddpfPixelFormat.dwRGBBitCount != 8))
                return 1;

            hr = this->DrawSurface->Restore();
            if (hr != 0) {
                if (hr == (long)0x8876024B || hr == (long)0x8007000E) {
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
            this->DrawSurface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
            this->Restored = 1;
            return 2;
        }
    }
    return 0;
}

unsigned char* TDrawArea::Lock(char* name, int waitFlag)
{
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
    if (waitFlag) {
        hr = this->DrawSurface->Lock(0, &this->SurfaceDesc, 1, 0);
    }
    else {
        hr = this->DrawSurface->Lock(0, &this->SurfaceDesc, 0, 0);
    }

    if (hr != 0)
        return 0;

    this->Bits = (unsigned char*)this->SurfaceDesc.lpSurface;
    this->SetInfo();

    if (this->Bits != this->LastBits)
        this->SetAccessOffsets();

    return this->Bits;
}

void TDrawArea::Unlock(char* name)
{
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->Bits == 0)
        return;

    this->DrawSurface->Unlock(this->Bits);
    this->Bits = 0;
}

void* TDrawArea::GetDc(char* unused)
{
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

void TDrawArea::ReleaseDc(char* name)
{
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->DrawDc == 0)
        return;

    this->DrawSurface->ReleaseDC(this->DrawDc);
    this->DrawDc = 0;
}

void TDrawArea::SetSize(long width, long height, int flags)
{
    DDSURFACEDESC ddsd;
    DDBLTFX ddbltfx;
    TDrawSystem* draw_system = this->DrawSystem;

    if (draw_system != 0 && draw_system->DrawType != 1) {
        if (this->DrawSystem != 0 && this->DrawSystem->DirDraw != 0 &&
            width != 0 && height != 0 &&
            (width != this->Width || height != this->Height ||
             this->DrawSurface == 0)) {
            if (width < 1) {
                width = 1;
            }
            if (height < 1) {
                height = 1;
            }

            long surface_height = height + 10;
            if (flags == 0) {
                surface_height = height;
            }

            this->ExtendedLines = flags;
            this->BitmapInfo->bmiHeader.biWidth = width;
            if (this->Orien == 1) {
                this->BitmapInfo->bmiHeader.biHeight = -surface_height;
            }
            else {
                this->BitmapInfo->bmiHeader.biHeight = surface_height;
            }
            this->Width = width;
            this->Height = height;

            if (this->IsPrimarySurface == 0) {
                if (this->DrawSurface != 0) {
                    this->DrawSurface->Release();
                    this->DrawSurface = 0;
                    memset(&this->SurfaceDesc, 0, 0x6C);
                    this->Pitch = 0;
                    this->UsingVidMem = 0;
                }

                memset(&ddsd, 0, 0x6C);
                ddsd.dwSize = 0x6C;
                ddsd.dwFlags = 7;
                if ((this->DrawSystem->Flags & 1) != 0 ||
                    flags != 0 || this->SystemMemOnly != 0) {
                    ddsd.ddsCaps.dwCaps = 0x840;
                }
                else {
                    ddsd.ddsCaps.dwCaps = 0x40;
                }
                ddsd.dwHeight = surface_height;
                ddsd.dwWidth = this->Width;

                if (this->DrawSystem->DirDraw->CreateSurface(
                        &ddsd, &this->DrawSurface, 0) == 0) {
                    this->SurfaceDesc.dwSize = 0x6C;
                    long hr = this->DrawSurface->GetSurfaceDesc(
                        &this->SurfaceDesc);
                    if (hr == 0) {
                        this->SetInfo();
                        this->SetAccessOffsets();
                        ddbltfx.dwSize = 0x64;
                        ddbltfx.dwFillColor = 0;
                        this->DrawSurface->Blt(0, 0, 0, 0x1000400,
                                               &ddbltfx);
                    }
                    else {
                        this->DrawSystem->GetCreateErrorNum(hr);
                    }
                }
            }
            else {
                this->DrawSurface = this->DrawSystem->PrimarySurface;
            }

            this->SetClipRect(0);
            this->Clear(0, 0);
        }
    }

    if (this->SpanList != 0) {
        delete this->SpanList;
    }

    this->SpanList = new TSpan_List_Manager(width, height);
    int i = 0;
    if (height > 0) {
        do {
            this->SpanList->AddSpan(0, width - 1, i);
            ++i;
        } while (i < height);
    }
    this->CurSpanList = this->SpanList;
}

void TDrawArea::Clear(tagRECT* rect, int color)
{
    if (DDSys_CanColorFill == 0) {
        this->PtrClear(rect, color);
        return;
    }

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1) {
        unsigned char* p = this->Bits;

        if (p != 0) {
            if (rect == 0) {
                memset(p, color, this->Height * this->Pitch);
                return;
            }

            int x1 = rect->left;
            int y1 = rect->top;
            int x2 = rect->right;
            int y2 = rect->bottom;

            if (x1 < 0) {
                x1 = 0;
            }
            else if (x1 >= this->Width) {
                x1 = this->Width - 1;
            }

            if (y1 < 0) {
                y1 = 0;
            }
            else if (y1 >= this->Height) {
                y1 = this->Height - 1;
            }

            if (x2 < 0) {
                x2 = 0;
            }
            else if (x2 >= this->Width) {
                x2 = this->Width - 1;
            }

            if (y2 < 0) {
                y2 = 0;
            }
            else if (y2 >= this->Height) {
                y2 = this->Height - 1;
            }

            if (x1 < x2 && y1 < y2) {
                int width = x2 - x1 + 1;

                int step;
                int offset;
                if (this->Orien == 1) {
                    step = this->Pitch;
                    offset = y1 * step;
                }
                else {
                    offset = (this->Height - y1 - 1) * this->Pitch;
                    step = -this->Pitch;
                }

                p = p + offset + x1;

                if (y1 <= y2) {
                    int rows = y2 - y1 + 1;
                    do {
                        memset(p, color, width);
                        p += step;
                        --rows;
                    } while (rows != 0);
                }
            }
        }
    }
    else {
        tagRECT dest;
        _DDBLTFX ddbltfx;
        IDirectDrawSurface* surface = this->DrawSurface;

        if (surface != 0) {
            ddbltfx.dwSize = sizeof(ddbltfx);
            ddbltfx.dwFillColor = color;

            if (rect == 0) {
                surface->Blt(0, 0, 0, 0x1000400, &ddbltfx);
                return;
            }

            dest.left = rect->left;
            dest.top = rect->top;
            dest.right = rect->right + 1;
            dest.bottom = rect->bottom + 1;
            surface->Blt(&dest, 0, 0, 0x1000400, &ddbltfx);
        }
    }
}

void TDrawArea::SetAccessOffsets()
{
    int size = this->Height << 2;
    if (size != this->DisplayOffsetsSz) {
        if (this->DisplayOffsets != 0)
            free(this->DisplayOffsets);
        this->DisplayOffsets = (void**)malloc(size);
        this->DisplayOffsetsSz = size;
        this->CurDisplayOffsets = this->DisplayOffsets;
    }

    unsigned char* p;
    int delta;
    if (this->Orien == 1 || this->ExtendedLines != 0) {
        if (this->ExtendedLines == 0)
            p = this->Bits;
        else
            p = this->Bits + this->Pitch * 5;

        delta = this->Pitch;
        if (this->ExtendedLines != 0)
            delta = this->Width;
    }
    else {
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

void TDrawArea::SetFloatOffsets(int x, int y)
{
    int size = this->Height << 2;
    if (size != 0 && this->ExtendedLines != 0 && x >= 0 && y >= 0) {
        if (size != this->FloatOffsetsSz) {
            if (this->FloatOffsets != 0)
                free(this->FloatOffsets);
            this->FloatOffsets = (void**)malloc(size);
            this->FloatOffsetsSz = size;
        }

        int out = 0;
        int cur = y;
        if (this->Height > 0) {
            do {
                this->FloatOffsets[out] =
                    (void*)((unsigned char*)this->DisplayOffsets[cur] + x);
                cur++;
                if (cur >= this->Height)
                    cur = 0;
                out++;
            } while (out < this->Height);
        }
        this->Float_X_Delta = x;
        this->Float_Y_Delta = y;
        this->CurDisplayOffsets = this->FloatOffsets;
    }
}

void TDrawArea::SetInfo(void) {
    this->Pitch = this->SurfaceDesc.lPitch;
    this->BitmapInfo->bmiHeader.biWidth = this->SurfaceDesc.lPitch;
    if ((this->SurfaceDesc.ddsCaps.dwCaps & 0x800) != 0) {
        this->UsingVidMem = 0;
        return;
    }
    this->UsingVidMem = 1;
}

long TDrawArea::AlignedWidth()
{
    return this->Pitch;
}

void TDrawArea::SetClipRect(tagRECT* rect)
{
    if (rect != 0) {
        this->ClipRect.left = rect->left;
        this->ClipRect.top = rect->top;
        this->ClipRect.right = rect->right;
        this->ClipRect.bottom = rect->bottom;

        if (this->ClipRect.left < 0) {
            this->ClipRect.left = 0;
        }
        else if (this->ClipRect.left > this->Width - 1) {
            this->ClipRect.left = this->Width - 1;
        }

        if (this->ClipRect.right < 0) {
            this->ClipRect.right = 0;
        }
        else if (this->ClipRect.right > this->Width - 1) {
            this->ClipRect.right = this->Width - 1;
        }

        if (this->ClipRect.top < 0) {
            this->ClipRect.top = 0;
        }
        else if (this->ClipRect.top > this->Height - 1) {
            this->ClipRect.top = this->Height - 1;
        }

        if (this->ClipRect.bottom < 0) {
            this->ClipRect.bottom = 0;
        }
        else if (this->ClipRect.bottom > this->Height - 1) {
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
    }
    else {
        this->ClipRect.left = 0;
        this->ClipRect.top = 0;
        this->ClipRect.right = this->Width - 1;
        this->ClipRect.bottom = this->Height - 1;
    }

    this->SetClipRect(this->ClipRect.left, this->ClipRect.top,
                      this->ClipRect.right, this->ClipRect.bottom);
}

void TDrawArea::SetClipRect(long left, long top, long right, long bottom)
{
    TSpan_List_Manager* span_list = this->SpanList;

    this->ClipRect.left = left;
    this->ClipRect.top = top;
    this->ClipRect.right = right;
    this->ClipRect.bottom = bottom;

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
    span_list->SetSpanRegions(this->ClipRect.left, this->ClipRect.top,
                              this->ClipRect.right, this->ClipRect.bottom);

    int y = this->ClipRect.top;
    if (y <= this->ClipRect.bottom) {
        do {
            this->SpanList->AddSpan(this->ClipRect.left, this->ClipRect.right, y);
            ++y;
        } while (y <= this->ClipRect.bottom);
    }

    this->CurSpanList = this->SpanList;
}

void TDrawArea::Copy(TDrawArea* area, long x, long y, RECT* rect,
                     int transparent)
{
    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 1) {
        if (this->Bits != 0 && area != 0 && area->Bits != 0) {
            int width;
            int height;
            int source_x;
            int source_y;

            if (rect == 0) {
                width = this->Width;
                height = this->Height;
                source_x = 0;
                source_y = 0;
            }
            else {
                source_x = rect->left;
                source_y = rect->top;
                width = rect->right - source_x + 1;
                height = rect->bottom - source_y + 1;
            }

            if (width + source_x > this->Width) {
                width = this->Width - source_x;
            }
            if (height + source_y > this->Height) {
                height = this->Height - source_y;
            }

            if (this->UseTrans != 0 && transparent != 0) {
                TransDibBlt(area->BitmapInfo, area->Bits, &area->ClipRect,
                            x, y, width, height,
                            this->BitmapInfo, this->Bits, 0,
                            source_x, source_y, width, height,
                            1, 0, 0, this->TransColor);
                DAT_0062e650 = 0;
                return;
            }

            DibBlt(area->BitmapInfo, area->Bits, &area->ClipRect,
                   x, y, width, height,
                   this->BitmapInfo, this->Bits,
                   source_x, source_y, width, height, 1, 0, 0);
            DAT_0062e650 = 0;
            return;
        }
    }
    else if (this->DrawSurface != 0 && area != 0 &&
             area->DrawSurface != 0) {
        RECT src_rect2;
        RECT dest_rect2;

        if (rect == 0) {
            src_rect2.left = 0;
            src_rect2.top = 0;
            src_rect2.right = this->Width - 1;
            src_rect2.bottom = this->Height - 1;
        }
        else {
            src_rect2.left = rect->left;
            src_rect2.top = rect->top;
            src_rect2.right = rect->right;
            src_rect2.bottom = rect->bottom;
        }

        ++src_rect2.right;
        ++src_rect2.bottom;

        SetRect(&dest_rect2, x, y,
                (src_rect2.right - src_rect2.left) + x,
                (src_rect2.bottom - src_rect2.top) + y);

        if (src_rect2.left < 0) {
            dest_rect2.left -= src_rect2.left;
            src_rect2.left = 0;
        }
        if (src_rect2.top < 0) {
            dest_rect2.top -= src_rect2.top;
            src_rect2.top = 0;
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

        if (dest_rect2.left < area->ClipRect.left) {
            long amount = area->ClipRect.left - dest_rect2.left;
            dest_rect2.left += amount;
            src_rect2.left += amount;
        }
        if (dest_rect2.top < area->ClipRect.top) {
            long amount = area->ClipRect.top - dest_rect2.top;
            dest_rect2.top += amount;
            src_rect2.top += amount;
        }
        if (dest_rect2.right > area->ClipRect.right + 1) {
            long amount = dest_rect2.right - area->ClipRect.right - 1;
            dest_rect2.right -= amount;
            src_rect2.right -= amount;
        }
        if (dest_rect2.bottom > area->ClipRect.bottom + 1) {
            long amount = dest_rect2.bottom - area->ClipRect.bottom - 1;
            dest_rect2.bottom -= amount;
            src_rect2.bottom -= amount;
        }

        if (dest_rect2.left < dest_rect2.right &&
            dest_rect2.top < dest_rect2.bottom &&
            src_rect2.left < src_rect2.right &&
            src_rect2.top < src_rect2.bottom) {
            DAT_0062e64c = 1;
            if (this->UseTrans != 0 && transparent != 0) {
                DAT_0062e64c = area->DrawSurface->Blt(
                    &dest_rect2, this->DrawSurface, &src_rect2,
                    0x1008000, 0);
            }
            else {
                DAT_0062e64c = area->DrawSurface->Blt(
                    &dest_rect2, this->DrawSurface, &src_rect2,
                    0x1000000, 0);
            }

            DAT_0062e650 = 0;
            if (DAT_0062e64c != 0) {
                DAT_0062e650 = this->DrawSystem->GetBlitErrorNum(
                    DAT_0062e64c);
            }
            if (DAT_0062e650 == 0) {
                DAT_0062e650 = 0;
            }
        }
    }
}

void TDrawArea::SetTrans(int useTrans, unsigned char transColor)
{
    this->UseTrans = useTrans;

    if (useTrans != 0)
        this->TransColor = transColor;
    else
        this->TransColor = 0xFF;

    if (useTrans == 0)
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
    this->DrawSurface->SetColorKey(8, (DDCOLORKEY*)ddck);
}

void TDrawArea::SetOverlayTrans(int useTrans, unsigned char transColor)
{
    this->UseTrans = useTrans;
    this->TransColor = transColor;

    if (useTrans == 0)
        return;

    if (this->DrawSurface == 0)
        return;

    if (this->DrawSystem == 0)
        return;

    if (this->DrawSystem->DrawType != 2)
        return;

    int ddck[2];
    ddck[0] = transColor;
    ddck[1] = transColor;
    this->DrawSurface->SetColorKey(0x10, (DDCOLORKEY*)ddck);
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
    }
    else {
        Bits[((Height - y) - 1) * Pitch + x] = color;
    }
}

void TDrawArea::DrawLine(int x1, int y1, int x2, int y2, unsigned char color) {
    if (x1 == x2) {
        int y_start = y1;
        int y_end = y2;
        if (y_start > y_end) {
            int t = y_start;
            y_start = y_end;
            y_end = t;
        }
        unsigned int c = (unsigned int)color;
        do {
            _ASMDraw_HLine(x1, x2, y_start, c);
            y_start++;
        } while (y_start <= y_end);
    } else if (y1 == y2) {
        _ASMDraw_HLine(x1, x2, y1, (unsigned int)color);
    } else {
        int step;
        int dy;

        if (x2 < x1) {
            int t = x2;
            x2 = x1;
            x1 = t;
            t = y2;
            y2 = y1;
            y1 = t;
        }

        int dx;
        dx = x2 - x1 + 1;
        if (y1 < y2) {
            dy = y2 - y1;
            step = 1;
        } else {
            dy = y1 - y2;
            step = -1;
        }
        ++dy;

        if (dx >= dy) {
            int error = 0;
            int line_start = x1;
            for (; x1 < x2; ++x1) {
                error += dy;
                if (error >= dx) {
                    _ASMDraw_HLine(line_start, x1, y1, (unsigned int)color);
                    y1 += step;
                    error -= dx;
                    line_start = x1 + 1;
                }
            }
            _ASMDraw_HLine(line_start, x1, y1, (unsigned int)color);
        } else {
            int error = 0;
            for (;;) {
                _ASMDraw_HLine(x1, x1, y1, (unsigned int)color);
                if (y1 == y2) {
                    break;
                }
                error += dx;
                if (error >= dy) {
                    ++x1;
                    error -= dy;
                }
                y1 += step;
            }
        }
    }
}

void TDrawArea::DrawRect(long x1, long y1, long x2, long y2,
                         unsigned char color)
{
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


void TDrawArea::DrawHorzLine(long x, long y, long w, unsigned char color)
{
    if (this->Bits == 0)
        return;

    if (x > this->ClipRect.right)
        return;

    if (y < this->ClipRect.top || y > this->ClipRect.bottom)
        return;

    if (x < this->ClipRect.left) {
        w += x - this->ClipRect.left;
        x = this->ClipRect.left;
    }

    if (x + w - 1 > this->ClipRect.right) {
        w = this->ClipRect.right - x + 1;
    }

    if (w < 1)
        return;

    int offset;
    if (this->Orien == 1)
        offset = this->Pitch * y;
    else
        offset = (this->Height - y - 1) * this->Pitch;

    memset(this->Bits + offset + x, color, w);
}

void TDrawArea::DrawVertLine(long x, long y, long h, unsigned char color)
{
    unsigned char* bits = this->Bits;
    if (bits == 0) return;
    if (x < this->ClipRect.left || x > this->ClipRect.right) return;
    if (y > this->ClipRect.bottom) return;
    if (y < this->ClipRect.top) { h += y - this->ClipRect.top; y = this->ClipRect.top; }
    if (y + h - 1 > this->ClipRect.bottom) h = this->ClipRect.bottom - y + 1;
    if (h < 1) return;
    unsigned char* dest; int step;
    if (this->Orien == 1) { dest = bits + y * this->Pitch + x; step = this->Pitch; }
    else { dest = bits + (this->Height - y - 1) * this->Pitch + x; step = -this->Pitch; }
    while (h > 0) { *dest = color; dest += step; h--; }
}

void TDrawArea::FillRect(long x1, long y1, long x2, long y2,
                         unsigned char color)
{
    long width;
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

        if (x1 > this->ClipRect.right || x2 < this->ClipRect.left ||
            y1 > this->ClipRect.bottom || y2 < this->ClipRect.top)
            return;

        if (x1 < this->ClipRect.left)
            x1 = this->ClipRect.left;
        if (x2 > this->ClipRect.right)
            x2 = this->ClipRect.right;
        if (y1 < this->ClipRect.top)
            y1 = this->ClipRect.top;
        if (y2 > this->ClipRect.bottom)
            y2 = this->ClipRect.bottom;

        width = x2 - x1 + 1;
        height = y2 - y1 + 1;
        if (width < 1 || height < 1)
            return;

        if (this->Orien == 1) {
            p = this->Bits + (y1 * this->Pitch + x1);
            delta = this->Pitch;
        } else {
            p = this->Bits + ((this->Height - y1 - 1) * this->Pitch + x1);
            delta = -this->Pitch;
        }

        while (height > 0) {
            memset(p, color, width);
            p += delta;
            --height;
        }
    }
}

void TDrawArea::DrawBevel(long x1,long y1,long x2,long y2,unsigned char c1,unsigned char c2){ if(x1>x2){long t=x1;x1=x2;x2=t;} if(y1>y2){long t=y1;y1=y2;y2=t;} long w=x2-x1+1; if(w<1)return; long h=y2-y1+1; if(h<1)return; DrawHorzLine(x1+1,y1,w-1,c1); DrawVertLine(x2,y1+1,h-1,c1); DrawHorzLine(x1,y2,w,c2); DrawVertLine(x1,y1,h-1,c2);}

void TDrawArea::DrawBevel2(long x1, long y1, long x2, long y2,
                           unsigned char c1, unsigned char c2,
                           unsigned char c3, unsigned char c4)
{
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

void TDrawArea::DrawBevel3(long x1, long y1, long x2, long y2,
                           unsigned char c1, unsigned char c2,
                           unsigned char c3, unsigned char c4,
                           unsigned char c5, unsigned char c6)
{
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

void TDrawArea::DrawBevel21(long x1, long y1, long x2, long y2,
                            unsigned char c1, unsigned char c2,
                            unsigned char c3, unsigned char c4)
{
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

void TDrawArea::DrawBevel32(long x1, long y1, long x2, long y2,
                            unsigned char c1, unsigned char c2,
                            unsigned char c3, unsigned char c4,
                            unsigned char c5, unsigned char c6)
{
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

void TDrawArea::SetShadowTable(RGE_Color_Table* table)
{
    this->shadow_color_table = table;
}

void TDrawArea::DrawShadowBox(long x1, long y1, long x2, long y2)
{
    if (this->shadow_color_table != 0 && this->Bits != 0) {
        if (x1 < this->ClipRect.left) {
            x1 = this->ClipRect.left;
        }
        if (y1 < this->ClipRect.top) {
            y1 = this->ClipRect.top;
        }
        if (x2 > this->ClipRect.right) {
            x2 = this->ClipRect.right;
        }
        if (y2 > this->ClipRect.bottom) {
            y2 = this->ClipRect.bottom;
        }
        if (x1 < 0) {
            x1 = 0;
        }
        if (y1 < 0) {
            y1 = 0;
        }
        if (x2 >= this->Width) {
            x2 = this->Width - 1;
        }
        if (y2 >= this->Height) {
            y2 = this->Height - 1;
        }

        if (x2 < x1 || y2 < y1) {
            return;
        }

        long orientation = this->Orien;
        long row_pitch = this->AlignedWidth() * orientation;

        unsigned char* row_start;
        unsigned char* row_end;
        unsigned char* pixel;
        unsigned char* table;

        if (orientation < 1) {
            row_start = this->Bits + x1;
            row_start += (y1 - this->Height + 1) * row_pitch;
        }
        else {
            row_start = this->Bits + x1;
            row_start += row_pitch * y1;
        }

        row_end = row_start + (x2 - x1);
        table = this->shadow_color_table->table;

        if (y1 <= y2) {
            int row_count = (y2 - y1) + 1;
            do {
                pixel = row_start;
                for (; pixel <= row_end; pixel++) {
                    *pixel = table[*pixel];
                }
                row_start += row_pitch;
                row_end += row_pitch;
                row_count--;
            } while (row_count != 0);
        }
    }
}

void TDrawArea::GetPalette(tagPALETTEENTRY* entries)
{
    for (int i = 0; i < 256; ++i)
        entries[i] = this->DrawSystem->Palette[i];
}

void TDrawArea::SetPalette(tagPALETTEENTRY* entries)
{
    entries[0].peRed = 0;
    entries[0].peGreen = 0;
    entries[0].peBlue = 0;
    entries[0].peFlags = 0;

    entries[255].peRed = 0xFF;
    entries[255].peGreen = 0xFF;
    entries[255].peBlue = 0xFF;
    entries[255].peFlags = 0;

    this->DrawSystem->ModifyPalette(0, 256, entries);
}

void TDrawArea::take_snapshot(char* name, int& number)
{
    int bmWide;
    int bmHeight;
    BITMAPFILEHEADER bmFH;
    BITMAPINFOHEADER bmIH;
    char BMPFile[60];
    RGBQUAD bmPAL[256];
    PALETTEENTRY thePal[256];

    bmIH.biWidth = this->Width;
    bmHeight = this->Height;
    bmWide = (bmIH.biWidth + 3) & 0xfffc;

    bmFH.bfType = 0x4d42;
    int total = this->Height * bmWide;
    bmFH.bfSize = total + 0x436;
    bmIH.biHeight = bmHeight;
    bmFH.bfReserved1 = 0;
    bmFH.bfReserved2 = 0;
    bmFH.bfOffBits = 0x436;

    bmIH.biSize = 0x28;
    bmIH.biPlanes = 1;
    bmIH.biBitCount = 8;
    bmIH.biCompression = 0;
    bmIH.biSizeImage = 0;
    bmIH.biXPelsPerMeter = 0;
    bmIH.biYPelsPerMeter = 0;
    bmIH.biClrUsed = 0;
    bmIH.biClrImportant = 0;

    *(int*)BMPFile = 0;

    this->GetPalette(thePal);
    for (int i = 0; i < 256; ++i) {
        bmPAL[i].rgbBlue = thePal[i].peBlue;
        bmPAL[i].rgbGreen = thePal[i].peGreen;
        bmPAL[i].rgbRed = thePal[i].peRed;
        bmPAL[i].rgbReserved = 0;
    }

    int tries = 0;
    int file;
    while (1) {
        if (name == 0) {
            sprintf(BMPFile, (char*)0x5845e4, number);
        }
        else {
            sprintf(BMPFile, name, number);
        }

        ++tries;
        file = __open(BMPFile, 0);
        if (file == -1)
            break;

        ++number;
        close(file);
        if (tries <= 1000)
            continue;
        return;
    }

    unsigned char* buffer = (unsigned char*)malloc(bmWide);
    file = __open(BMPFile, 0x8301, 0x180);
    if (file != -1) {
        write(file, &bmFH, 0x0e);
        write(file, &bmIH, 0x28);
        write(file, bmPAL, 0x400);

        if (this->Lock("take_snapshot", 1) != 0) {
            int y = bmHeight - 1;
            while (y >= 0) {
                unsigned char* source =
                    (unsigned char*)this->CurDisplayOffsets[y];
                int x = 0;
                if (this->Width > 0) {
                    do {
                        buffer[x] = *source;
                        ++x;
                        ++source;
                    } while (x < this->Width);
                }
                write(file, buffer, bmWide);
                --y;
            }
            this->Unlock("take_snapshot");
        }
        close(file);
    }
    free(buffer);
}
