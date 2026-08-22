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
// This session: donor/dossier/ABI evidence confirms four calls, vslot+0x14 Blt,
// and the 0x20 RECT window. Declaration-order, direct src-field, full-class,
// standard-header, and API-surface labs stayed nonexact; <windows.h> plus direct
// RECT clipping reached 346 bytes/325 differing bytes and was rolled back.
// Final clean candidate remains the prior 350-byte/238-difference typed source;
// unresolved first hunk is the saved-register/zero-constant basin, not calls or CFG.
// Probe shardD8_443520: flatten the four resource guards into one short-circuit
// condition, matching the original's four common-exit tests without nested
// lifetime blocks.
// Probe orch-443520-a-1: moved the rectangle's left/top fields to direct named
// RECT ownership while retaining right/bottom as local bounds, to test the
// original EBX/EDX color split without decompiler cursor arithmetic.
// Probe orch-443520-a-2: swapped declaration order for the independent right
// and bottom bounds, preserving the canonical field ownership and behavior.
// Probe orch-443520-a-3: used natural pointer truth tests in the resource guard
// to remove explicit zero comparisons before the full-screen zero stores.
// Probe orch-443520-a-4: used paired RECT assignments for the two zero-valued
// coordinates, matching the original's two volatile zero registers naturally.
// Probe orch-443520-a-5: removed the decompiler-shaped destination-top alias
// and kept the arithmetic on the named RECT field directly.
// Probe orch-443520-a-6: kept all clipped bounds in the named source RECT,
// matching the natural API record ownership without separate aliases.
// Probe orch-443520-a-7: restored local right/bottom bounds while testing
// explicit destination assignments for the original EAX/EBP arithmetic roles.
// Probe orch-443520-a-8: restored the source-shaped nested DrawType/resource
// guards, preserving the four common-exit tests while changing block scope.
// Restored the named source-RECT clipped bounds after the local-bound probe;
// it keeps the original right/bottom register roles and the cleaner resync.
// Fresh pass result: direct named RECT ownership improved the positional diff
// from 238 to 227 bytes and kept all four calls and the 0x20 frame aligned.
// The remaining structural blocker is VC5's persistent EBP zero register:
// it emits cmp-against-EBP guards, delays EBX/EDI saves, and adds eight bytes.
// Local-bound and paired-zero assignment variants did not remove that basin.
// Leave this readable source in scratch; the next lead is compiler context or
// a proven original declaration shape that prevents zero-register hoisting.
// 2026-08-17 bounded pass: the original prologue is push EBX/EBP/ESI, then EDI;
// the best clean rebuild remains 350 bytes with 227 differing bytes and four
// aligned calls. An aggregate fullscreen dest = src form removes the EBP-zero
// tests and recovers the XOR/test islands, but saves registers late and stays
// 353 bytes with 311 differing bytes. It was rejected as a metric-only form.
// Const IAT declarations, typed Blt null parameters, function-scope bounds,
// and cached ClientToScreen forms did not produce an exact or better source.

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
    tagRECT src;
    tagRECT dest;

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
        ClientToScreen(this->Wnd, &dest.left);
        ClientToScreen(this->Wnd, &dest.right);
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
        dest.top = dest.top + src.top;
        dest.right = dest.left + src.right - src.left + 1;
        dest.bottom = dest.top + src.bottom - src.top + 1;

        src.right += 1;
        src.bottom += 1;
        }

        this->PrimarySurface->Blt(&dest, this->DrawArea->DrawSurface,
                                  &src, 0x1000000, 0);
    }
    }
}
