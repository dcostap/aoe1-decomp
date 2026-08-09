// VA: 00443DE0 TDrawArea::TDrawArea
// PDB source: Drawarea.cpp, lines 1686-1745
// Attempt log:
// - Baseline used an incorrect raw shim, operator_new, and an out-of-line string
//   copy; it was structurally wrong (5 calls versus the original 3).
// - Probe 2: restore the Drawarea.cpp TDrawArea layout, C calloc/malloc, and the
//   natural strlen/strcpy constructor source.
// - Probe 3: the target retains Drawarea.cpp's external memset call; the
//   binary-backed pragma preserves that call while strlen/strcpy remain inline.
//   Result: exact 304-byte match under the default flags.
// - Probe 4: typed forward declarations for the Drawarea ownership pointers
//   left the exact bytes unchanged and were retained for the source audit.
// - Main-agent audit confirmed the donor-backed non-polymorphic 0x100-byte
//   Drawarea layout and binary-required external memset surface; exactness holds.

#include <stdlib.h>
#include <string.h>

extern "C" void* __cdecl memset(void* s, int c, unsigned int n);
#pragma function(memset)

class TDrawSystem;
class DrawAreaNode;
class IDirectDrawSurface;
class TSpan_List_Manager;

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
    int ClipLeft;                        // +0x28
    int ClipTop;                         // +0x2C
    int ClipRight;                       // +0x30
    int ClipBottom;                      // +0x34
    void* DrawDc;                        // +0x38
    IDirectDrawSurface* DrawSurface;     // +0x3C
    char SurfaceDesc[0x6C];              // +0x40 .. +0xAB
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

    TDrawArea(char* name, int system_mem_only);
};

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
    this->ClipLeft = 0;
    this->ClipTop = 0;
    this->ClipRight = 0;
    this->ClipBottom = 0;
    this->LastBits = 0;
    this->DisplayOffsets = 0;
    this->CurDisplayOffsets = 0;
    this->DisplayOffsetsSz = 0;
    this->ExtendedLines = 0;
    this->FloatOffsets = 0;
    this->Float_X_Delta = 0;
    this->Float_Y_Delta = 0;
    this->FloatOffsetsSz = 0;

    memset(this->SurfaceDesc, 0, 0x6C);
    this->BitmapInfo = calloc(1, 0x428);
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
