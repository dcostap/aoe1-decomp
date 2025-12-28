#include "TDrawArea.h"
#include "TDrawSystem.h"
#include "TSpan_List_Manager.h"
#include <string.h>
#include <stdlib.h>
#include <algorithm>

// Helper global or define from engine
extern int DDSys_CanColorFill; 

TDrawArea::TDrawArea(const char *name, int system_mem) {
    this->DrawSystem = nullptr;
    this->Wnd = nullptr;
    this->DrawSurface = nullptr;
    this->UsingVidMem = 0;
    this->DrawDc = nullptr;
    
    // Allocate BitmapInfo (size 0x428 = header + 256 colors)
    this->BitmapInfo = (BITMAPINFO256 *)calloc(1, 0x428);
    
    this->Bitmap = nullptr;
    this->OldBitmap = nullptr;
    this->Bits = nullptr;
    this->Width = 0;
    this->Height = 0;
    this->Pitch = 0;
    this->UseTrans = 0;
    this->TransColor = 0xFF; // Ghidra initializes to 0xFF
    this->Node = nullptr;
    this->Restored = 0;
    this->IsPrimarySurface = 0;
    this->SystemMemOnly = system_mem;
    
    this->ClipRect.left = 0;
    this->ClipRect.top = 0;
    this->ClipRect.right = 0;
    this->ClipRect.bottom = 0;
    
    this->LastBits = nullptr;
    this->DisplayOffsets = nullptr;
    this->CurDisplayOffsets = nullptr;
    this->DisplayOffsetsSz = 0;
    this->ExtendedLines = 0;
    this->FloatOffsets = nullptr;
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    this->FloatOffsetsSz = 0;
    
    memset(&this->SurfaceDesc, 0, sizeof(DDSURFACEDESC));
    
    this->Orien = 1;
    this->SpanList = nullptr;
    this->CurSpanList = nullptr;
    this->shadow_color_table = nullptr;
    
    // Manual string duplication logic from Ghidra
    if (name) {
        int len = 0;
        const char *ptr = name;
        while (*ptr++) len++;
        
        if (len > 0) {
            this->Name = (char *)malloc(len + 1);
            if (this->Name) {
                // Copy with loop (roughly strcpy)
                memcpy(this->Name, name, len + 1);
            }
        } else {
            this->Name = nullptr;
        }
    } else {
        this->Name = nullptr;
    }
}

TDrawArea::~TDrawArea() {
    // Linked List Node Removal
    if (this->Node) {
        if (this->DrawSystem && this->DrawSystem->DrawAreaList == this->Node) {
            this->DrawSystem->DrawAreaList = this->Node->NextNode;
        }
        if (this->Node->PrevNode) {
            this->Node->PrevNode->NextNode = this->Node->NextNode;
        }
        if (this->Node->NextNode) {
            this->Node->NextNode->PrevNode = this->Node->PrevNode;
        }
        free(this->Node);
        this->Node = nullptr;
    }

    // Release DirectDraw Surface
    if (!this->DrawSystem || this->DrawSystem->DrawType != 1) { // 1 = GDI, 2 = DDRAW
        if (this->DrawSurface && !this->IsPrimarySurface) {
            this->DrawSurface->Release();
            this->DrawSurface = nullptr;
        }
    } else if (this->DrawDc) {
        // GDI Cleanup (Simulated based on decomp)
        if (this->Bitmap) {
            if (this->OldBitmap) SelectObject((HDC)this->DrawDc, (HBITMAP)this->OldBitmap);
            DeleteObject((HBITMAP)this->Bitmap);
        }
        DeleteDC((HDC)this->DrawDc);
    }

    if (this->BitmapInfo) free(this->BitmapInfo);
    if (this->DisplayOffsets) free(this->DisplayOffsets);
    if (this->FloatOffsets) free(this->FloatOffsets);
    
    if (this->SpanList) {
        delete this->SpanList; // Assuming TSpan_List_Manager has destructor
        this->SpanList = nullptr;
    }

    if (this->Name) free(this->Name);
}

int TDrawArea::Init(TDrawSystem *draw_system, long width, long height, int using_vid_mem, int is_primary_surface) {
    this->DrawSystem = draw_system;
    this->IsPrimarySurface = is_primary_surface;

    if (draw_system) {
        this->Wnd = draw_system->Wnd;
        if (!this->Node) {
            this->Node = (DrawAreaNode *)calloc(1, sizeof(DrawAreaNode));
            if (!this->Node) return 0;
            this->Node->DrawArea = this;
            if (!this->DrawSystem->DrawAreaList) {
                this->DrawSystem->DrawAreaList = this->Node;
            } else {
                DrawAreaNode *curr = this->DrawSystem->DrawAreaList;
                while (curr->NextNode) curr = curr->NextNode;
                curr->NextNode = this->Node;
                this->Node->PrevNode = curr;
            }
        }
        if (this->DrawSystem && this->DrawSystem->DrawType == 1) return 0;
    }
    this->SetSize(width, height, 0);
    return 1;
}

void TDrawArea::SetSize(long width, long height, int extended_lines) {
    if (!this->DrawSystem || this->DrawSystem->DrawType == 1) return;

    if (width < 1) width = 1;
    if (height < 1) height = 1;

    long alloc_height = (extended_lines == 0) ? height : (height + 10);
    this->ExtendedLines = extended_lines;
    this->Width = (int)width;
    this->Height = (int)height;

    if (!this->IsPrimarySurface) {
        if (this->DrawSurface) {
            this->DrawSurface->Release();
            this->DrawSurface = nullptr;
        }

        DDSURFACEDESC ddsd;
        memset(&ddsd, 0, sizeof(ddsd));
        ddsd.dwSize = sizeof(ddsd);
        ddsd.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH;
        ddsd.dwHeight = alloc_height;
        ddsd.dwWidth = width;
        ddsd.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
        if (this->SystemMemOnly) ddsd.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;

        // Obtain legacy IDirectDraw interface to use DDSURFACEDESC (v1)
        IDirectDraw *pDD = nullptr;
        if (this->DrawSystem->DirDraw->QueryInterface(IID_IDirectDraw, (void**)&pDD) == S_OK) {
            HRESULT hr = pDD->CreateSurface(&ddsd, &this->DrawSurface, NULL);
            if (hr == DD_OK) {
                this->SurfaceDesc.dwSize = sizeof(this->SurfaceDesc);
                this->DrawSurface->GetSurfaceDesc(&this->SurfaceDesc);
                this->SetInfo();
            }
            pDD->Release();
        }
    } else {
        // QueryInterface to ensure versions match if PrimarySurface is v7
        this->DrawSystem->PrimarySurface->QueryInterface(IID_IDirectDrawSurface, (void**)&this->DrawSurface);
    }

    this->SetClipRect(nullptr);
    this->Clear(nullptr, 0);

    if (this->SpanList) delete this->SpanList;
    this->SpanList = new TSpan_List_Manager(width, height);
    for (int i = 0; i < height; i++) this->SpanList->AddSpan(0, width - 1, i);
    this->CurSpanList = this->SpanList;
}

uchar* TDrawArea::Lock(const char* name, int wait) {
    if (!this->DrawSystem || this->DrawSystem->DrawType == 1 || !this->DrawSurface) return nullptr;
    if (this->Bits) return this->Bits;

    // Use DDSURFACEDESC (Version 1)
    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    
    HRESULT hr = this->DrawSurface->Lock(NULL, &ddsd, (wait ? DDLOCK_WAIT : 0), NULL);
    if (hr == DD_OK) {
        this->Bits = (uchar*)ddsd.lpSurface;
        memcpy(&this->SurfaceDesc, &ddsd, sizeof(DDSURFACEDESC));
        this->SetInfo();
        if (this->Bits != this->LastBits) this->SetAccessOffsets();
    }
    return this->Bits;
}

void TDrawArea::Unlock(const char* name) {
    if (!this->DrawSystem || this->DrawSystem->DrawType == 1) return;

    if (this->DrawSurface && this->Bits) {
        this->DrawSurface->Unlock(NULL);
        this->Bits = nullptr;
    }
}

void TDrawArea::GetPalette(PALETTEENTRY *param_1) {
    // Logic from decomp: copies from DrawSystem palette
    if (this->DrawSystem && param_1) {
        memcpy(param_1, this->DrawSystem->palette, sizeof(PALETTEENTRY) * 256);
    }
}

// Utility: intersect two RECTs, return false if empty
static bool IntersectRectSimple(RECT &out, const RECT &a, const RECT &b) {
    out.left   = (a.left   > b.left)   ? a.left   : b.left;
    out.top    = (a.top    > b.top)    ? a.top    : b.top;
    out.right  = (a.right  < b.right)  ? a.right  : b.right;
    out.bottom = (a.bottom < b.bottom) ? a.bottom : b.bottom;
    return (out.right > out.left) && (out.bottom > out.top);
}

void TDrawArea::SetClipRect(RECT *rect) {
    if (!rect) {
        this->ClipRect.left = 0;
        this->ClipRect.top = 0;
        this->ClipRect.right = this->Width;
        this->ClipRect.bottom = this->Height;
        return;
    }

    // Clamp to surface bounds
    RECT r = *rect;
    if (r.left < 0) r.left = 0;
    if (r.top < 0) r.top = 0;
    if (r.right > this->Width) r.right = this->Width;
    if (r.bottom > this->Height) r.bottom = this->Height;

    // Avoid inverted rects
    if (r.right < r.left) r.right = r.left;
    if (r.bottom < r.top) r.bottom = r.top;

    this->ClipRect = r;
}

void TDrawArea::SetClipRect(long l, long t, long r, long b) {
    RECT rc;
    rc.left = (LONG)l;
    rc.top = (LONG)t;
    rc.right = (LONG)r;
    rc.bottom = (LONG)b;
    SetClipRect(&rc);
}

void TDrawArea::SetInfo() {
    // Pitch: prefer the value from the current surface desc
    if (this->SurfaceDesc.lPitch != 0) {
        this->Pitch = (int)this->SurfaceDesc.lPitch;
    } else {
        // Fallback: compute from width + bpp (rarely used)
        int bpp = (this->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount != 0)
                    ? (int)this->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount
                    : 8;
        int bytesPerPixel = (bpp + 7) / 8;
        int raw = this->Width * bytesPerPixel;
        this->Pitch = (raw + 3) & ~3; // align 4 bytes
    }

    // Setup BitmapInfo for any GDI/DIB-style debug usage
    if (this->BitmapInfo) {
        memset(this->BitmapInfo, 0, sizeof(BITMAPINFO256));
        this->BitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
        this->BitmapInfo->bmiHeader.biWidth = this->Width;
        this->BitmapInfo->bmiHeader.biHeight = -this->Height; // top-down
        this->BitmapInfo->bmiHeader.biPlanes = 1;

        int bpp = (this->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount != 0)
                    ? (int)this->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount
                    : 8;

        this->BitmapInfo->bmiHeader.biBitCount = (WORD)bpp;
        this->BitmapInfo->bmiHeader.biCompression = BI_RGB;
        this->BitmapInfo->bmiHeader.biSizeImage = (DWORD)(this->Pitch * this->Height);

        if (bpp == 8 && this->DrawSystem) {
            for (int i = 0; i < 256; i++) {
                this->BitmapInfo->bmiColors[i].rgbRed   = this->DrawSystem->palette[i].peRed;
                this->BitmapInfo->bmiColors[i].rgbGreen = this->DrawSystem->palette[i].peGreen;
                this->BitmapInfo->bmiColors[i].rgbBlue  = this->DrawSystem->palette[i].peBlue;
                this->BitmapInfo->bmiColors[i].rgbReserved = 0;
            }
        }
    }
}

void TDrawArea::SetAccessOffsets() {
    // Build per-scanline pointers for fast addressing
    if (!this->Bits || this->Pitch <= 0 || this->Height <= 0) {
        this->CurDisplayOffsets = nullptr;
        return;
    }

    // Match your SetSize allocation rule: extra 10 lines when ExtendedLines != 0
    int alloc_height = (this->ExtendedLines == 0) ? this->Height : (this->Height + 10);
    if (alloc_height < 1) alloc_height = 1;

    if (!this->DisplayOffsets || this->DisplayOffsetsSz != alloc_height) {
        if (this->DisplayOffsets) free(this->DisplayOffsets);
        this->DisplayOffsets = (void**)malloc(sizeof(void*) * alloc_height);
        this->DisplayOffsetsSz = alloc_height;
    }

    if (this->DisplayOffsets) {
        for (int y = 0; y < alloc_height; y++) {
            this->DisplayOffsets[y] = (void*)(this->Bits + y * this->Pitch);
        }
        this->CurDisplayOffsets = this->DisplayOffsets;
    }

    this->LastBits = this->Bits;
}

void TDrawArea::Clear(RECT *rect, int color) {
    // Determine target clear rect = intersection(requested rect or full) with ClipRect
    RECT full;
    full.left = 0;
    full.top = 0;
    full.right = this->Width;
    full.bottom = this->Height;

    RECT req = rect ? *rect : full;
    RECT clipped;
    if (!IntersectRectSimple(clipped, req, this->ClipRect)) return;

    // GDI path (DrawType == 1 per your comments)
    if (this->DrawSystem && this->DrawSystem->DrawType == 1) {
        // If you later wire up DrawDc, you can do a FillRect/PatBlt here.
        // For now, just no-op safely.
        return;
    }

    if (!this->DrawSurface) return;

    // Fast path: DirectDraw color fill (works fine for 8-bit as palette index fill)
    if (DDSys_CanColorFill) {
        DDBLTFX fx;
        memset(&fx, 0, sizeof(fx));
        fx.dwSize = sizeof(fx);
        fx.dwFillColor = (DWORD)color;

        HRESULT hr = this->DrawSurface->Blt(&clipped, nullptr, nullptr, DDBLT_COLORFILL | DDBLT_WAIT, &fx);
        if (SUCCEEDED(hr)) return;
        // If it fails, fall through to manual fill.
    }

    // Manual fill: lock if needed, fill, unlock if we locked
    bool did_lock = false;
    if (!this->Bits) {
        if (!this->Lock("Clear", 1)) return;
        did_lock = true;
    }

    int bpp = (this->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount != 0)
                ? (int)this->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount
                : 8;

    int w = clipped.right - clipped.left;
    int h = clipped.bottom - clipped.top;

    if (bpp == 8) {
        for (int y = 0; y < h; y++) {
            uchar *row = this->Bits + (clipped.top + y) * this->Pitch + clipped.left;
            memset(row, (uchar)color, (size_t)w);
        }
    } else if (bpp == 16) {
        // Treat 'color' as already packed 16-bit
        uint16_t c = (uint16_t)color;
        for (int y = 0; y < h; y++) {
            uint16_t *row = (uint16_t*)(this->Bits + (clipped.top + y) * this->Pitch) + clipped.left;
            for (int x = 0; x < w; x++) row[x] = c;
        }
    } else if (bpp == 32) {
        // Treat 'color' as already packed 0x00RRGGBB or similar
        uint32_t c = (uint32_t)color;
        for (int y = 0; y < h; y++) {
            uint32_t *row = (uint32_t*)(this->Bits + (clipped.top + y) * this->Pitch) + clipped.left;
            for (int x = 0; x < w; x++) row[x] = c;
        }
    } else {
        // Unknown format: do nothing (safe fallback)
    }

    if (did_lock) this->Unlock("Clear");
}