// VA: 00443520
// TDrawSystem::Paint(tagRECT* param_1)
// PDB source: Drawarea.cpp lines 1224-1328
// Size: 342 bytes (0x156), 119 asm lines

// Attempts:
// 1-3: Various struct copy patterns, field access order, early screenWidth loads
// 4-5: block-local zeros, registerized ClientToScreen ptr, !ptr null checks
// 6-9: explicit dl/dt temps, goto early-exit, inline vtable call
// All produce persistent zero register (ebp=0) which changes register save order
// (push ebp vs original push ebx) and compresses param_1 computation code size.
// The zero register pushes function body past 342-byte limit, truncating call+epilogue.
// 
// Root cause: VC5 /O2 allocates ebp as dedicated zero register when it detects
// enough zero-stores across multiple basic blocks (fullscreen path 4 zero stores +
// param_1 clamping 2 potential zero stores). The original source structure avoids
// this, likely by using local xor+store patterns that keep zero in volatile regs.
// 48+ variant lab trials with different zero patterns and flag presets all produce
// the same push-ebp-first prologue. Left in scratch pending a breakthrough on
// eliminating the persistent zero register or finding the exact original source shape.
// Final bounded pass: the natural positive resource guards, named destination-top
// accumulator, and typed DirectDrawSurface::Blt are retained; calls/CFG remain
// aligned, but the saved-register/prologue basin is still unresolved.

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

extern "C" int (__stdcall * const GetClientRect)(void* hWnd, tagRECT* rect);
extern "C" int (__stdcall * ClientToScreen)(void* hWnd, void* point);

class IDirectDrawSurface {
public:
    virtual long __stdcall QueryInterface();
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface();
    virtual long __stdcall AddOverlayDirtyRect();
    virtual long __stdcall Blt(tagRECT*, IDirectDrawSurface*, tagRECT*,
                               unsigned long, void*);
};

class TDrawArea {
public:
    char gap_00[0x04];
    void* Wnd;                      // +0x04
    char gap_08[0x34];
    IDirectDrawSurface* DrawSurface; // +0x3C
};

class TDrawSystem {
public:
    void* Inst;                         // +0x00
    void* Wnd;                          // +0x04
    void* Pal;                          // +0x08
    TDrawArea* DrawArea;                // +0x0C
    TDrawArea* PrimaryArea;             // +0x10
    void* DrawAreaList;                 // +0x14
    void* DirDraw;                      // +0x18
    IDirectDrawSurface* PrimarySurface; // +0x1C
    void* Clipper;                      // +0x20
    void* DirDrawPal;                   // +0x24
    unsigned long Flags;                // +0x28
    int ScreenWidth;                    // +0x2C
    int ScreenHeight;                   // +0x30
    int ColorBits;                      // +0x34
    int ErrorCode;                      // +0x38
    int ChangedMode;                    // +0x3C
    char gap_40[0x438];                 // +0x40 to +0x477
    unsigned char DrawType;             // +0x478
    unsigned char ScreenMode;           // +0x479

    void Paint(tagRECT* param_1);
};

void TDrawSystem::Paint(tagRECT* param_1)
{
    tagRECT dest;
    tagRECT src;
    long l;
    long t;
    long r;
    long b;
    long dest_top;

    if (this->DrawType != 1) {
        if (this->PrimarySurface) {
            if (this->DrawArea) {
                if (this->DrawArea->DrawSurface) {
        if (this->ScreenMode == 1) {
        GetClientRect(this->Wnd, &src);
        dest.left = src.left;
        dest.top = src.top;
        dest.right = src.right;
        dest.bottom = src.bottom;
        ClientToScreen(this->Wnd, &dest.left);
        ClientToScreen(this->Wnd, &dest.right);
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
        l = param_1->left;
        t = param_1->top;
        r = param_1->right;
        b = param_1->bottom;

        src.left = l;
        src.top = t;

        if (l < 0) { src.left = 0; l = 0; }
        if (t < 0) { src.top = 0; t = 0; }
        if (r >= this->ScreenWidth) r = this->ScreenWidth - 1;
        if (b >= this->ScreenHeight) b = this->ScreenHeight - 1;

        dest.left += l;
        dest_top = dest.top;
        dest_top += t;
        dest.top = dest_top;
        dest.right = dest.left + r - l + 1;
        dest.bottom = dest_top + b - t + 1;

        src.right = r + 1;
        src.bottom = b + 1;
        }

        this->PrimarySurface->Blt(&dest, this->DrawArea->DrawSurface,
                                  &src, 0x1000000, 0);
                }
            }
        }
    }
}
