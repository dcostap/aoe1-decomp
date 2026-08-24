// VA: 00443F10 ~TDrawArea (292 B)
// PDB source: Drawarea.cpp, lines 1751-1812
// Attempt log:
// - Replaced the prior raw shim and fake Release/dtor helpers with the
//   period-plausible TDrawArea ownership surface, DrawAreaNode links, COM
//   Release method, GDI imports, and real TSpan_List_Manager delete.
// - Main-agent audit confirmed the non-polymorphic Drawarea.cpp ownership and
//   natural COM/GDI lifetime source; emitted code remains exact.

#include <stdlib.h>

#ifndef DRAWAREA_CANONICAL_TU
class TDrawArea;
class TSpan_List_Manager;

struct DrawAreaNode {
    TDrawArea* DrawArea;
    DrawAreaNode* PrevNode;
    DrawAreaNode* NextNode;
};

class TDrawSystem {
public:
    void* Inst;                         // +0x00
    void* Wnd;                          // +0x04
    void* Pal;                          // +0x08
    TDrawArea* DrawArea;                // +0x0C
    TDrawArea* PrimaryArea;             // +0x10
    DrawAreaNode* DrawAreaList;         // +0x14
    char gap_18[0x460];                 // +0x18 .. +0x477
    unsigned char DrawType;             // +0x478
};

class IDirectDrawSurface {
public:
    virtual void __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

extern "C" {
__declspec(dllimport) void* __stdcall SelectObject(void* dc, void* object);
__declspec(dllimport) int __stdcall DeleteObject(void* object);
__declspec(dllimport) int __stdcall DeleteDC(void* dc);
}

class TSpan_List_Manager {
public:
    ~TSpan_List_Manager();
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;             // +0x00
    void* Wnd;                           // +0x04
    unsigned char* Bits;                 // +0x08
    void* BitmapInfo;                    // +0x0C
    void* Bitmap;                        // +0x10
    void* OldBitmap;                     // +0x14
    int Width;                           // +0x18
    int Height;                          // +0x1C
    int Pitch;                           // +0x20
    int Orien;                           // +0x24
    char gap_28[0x10];                   // +0x28
    void* DrawDc;                        // +0x38
    IDirectDrawSurface* DrawSurface;     // +0x3C
    char SurfaceDesc[0x6C];              // +0x40
    DrawAreaNode* Node;                  // +0xAC
    char* Name;                          // +0xB0
    unsigned char* LastBits;             // +0xB4
    int LastPitch;                       // +0xB8
    void** DisplayOffsets;               // +0xBC
    void** CurDisplayOffsets;            // +0xC0
    void** FloatOffsets;                 // +0xC4
    void* shadow_color_table;            // +0xC8
    TSpan_List_Manager* SpanList;        // +0xCC
    TSpan_List_Manager* CurSpanList;     // +0xD0
    int Float_X_Delta;                   // +0xD4
    int Float_Y_Delta;                   // +0xD8
    int DisplayOffsetsSz;                // +0xDC
    int FloatOffsetsSz;                  // +0xE0
    int SystemMemOnly;                   // +0xE4
    int UsingVidMem;                     // +0xE8
    int UseTrans;                        // +0xEC
    int IsPrimarySurface;                // +0xF0
    int Restored;                        // +0xF4
    int ExtendedLines;                   // +0xF8
    unsigned char TransColor;            // +0xFC
    unsigned char gap_FD[3];

    ~TDrawArea();
};
#endif

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
