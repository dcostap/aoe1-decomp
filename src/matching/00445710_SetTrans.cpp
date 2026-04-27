// first pass: direct DrawSurface color-key setup from the packet/decompiler shape
// after the first build, the main gap was just the local layout / field offsets, so use the real TDrawArea surface
class TDrawSystem {
public:
    char pad_00[0x478];
    unsigned char DrawType;
};

struct IDirectDrawSurface;
struct IDirectDrawSurfaceVtbl {
    void* pad_00[0x1D];
    void (__stdcall *SetColorKey)(IDirectDrawSurface* this_, int, void*);
};

struct IDirectDrawSurface {
    IDirectDrawSurfaceVtbl* lpVtbl;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;      // +0x00
    void* Wnd;                    // +0x04
    unsigned char* Bits;          // +0x08
    void* BitmapInfo;             // +0x0C
    void* Bitmap;                 // +0x10
    void* OldBitmap;              // +0x14
    int Width;                    // +0x18
    int Height;                   // +0x1C
    int Pitch;                    // +0x20
    int Orien;                    // +0x24
    char ClipRect[0x10];          // +0x28
    void* DrawDc;                 // +0x38
    IDirectDrawSurface* DrawSurface; // +0x3C
    char SurfaceDesc[0x6C];       // +0x40
    void* Node;                   // +0xAC
    char* Name;                   // +0xB0
    unsigned char* LastBits;      // +0xB4
    int LastPitch;                // +0xB8
    void** DisplayOffsets;        // +0xBC
    void** CurDisplayOffsets;     // +0xC0
    void** FloatOffsets;          // +0xC4
    void* shadow_color_table;     // +0xC8
    void* SpanList;               // +0xCC
    void* CurSpanList;            // +0xD0
    int Float_X_Delta;            // +0xD4
    int Float_Y_Delta;            // +0xD8
    int DisplayOffsetsSz;         // +0xDC
    int FloatOffsetsSz;           // +0xE0
    int SystemMemOnly;            // +0xE4
    int UsingVidMem;              // +0xE8
    int UseTrans;                 // +0xEC
    int IsPrimarySurface;         // +0xF0
    int Restored;                 // +0xF4
    int ExtendedLines;            // +0xF8
    unsigned char TransColor;     // +0xFC

    void SetTrans(int param_1, unsigned char param_2);
};

void TDrawArea::SetTrans(int param_1, unsigned char param_2) {
    unsigned long ddck[2];
    unsigned long color;

    this->UseTrans = param_1;
    if (param_1 != 0) {
        this->TransColor = param_2;
    }
    else {
        this->TransColor = 0xFF;
    }

    if (param_1 != 0 && this->DrawSurface != 0 && this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        color = this->TransColor;
        ddck[0] = color;
        ddck[1] = color;
        this->DrawSurface->lpVtbl->SetColorKey(this->DrawSurface, 8, ddck);
    }
}
