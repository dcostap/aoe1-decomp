// 004450C0 TDrawArea::PtrCopy(TDrawArea*, long, long, tagRECT*)
// PDB: Drawarea.cpp:3226-3322, 395 bytes
// __thiscall, void, ret 10h
// FLAGS: /Oy- (EBP frame required; no /GX)
//
// Attempt log:
// v0: First attempt — wrong frame type (/Oy default omitted EBP frame)
// v1-3: memcpy approach — frame 0x10 vs 0x18 (6 locals needed, VC5 kept 4 in registers)
//       memcpy generated rep movsd/rep movsb but without alignment optimization
// v4-6: Manual alignment calc with while-loops — VC5 generated loops, not rep movsb
// v7-10: Various struct layouts and local variable ordering — frame always 0x10
// v11-14: Added more locals, explicit parameter slot reuse — frame fixed at 0x10 still
// v15: All locals declared at function top as plain ints — still 0x10 vs 0x18
// v16: Reconstructed the shared aligned byte/dword copy family with typed
// loops; VC5 emitted scalar loops (443 bytes) and the experiment was rolled
// back.
// v17: Mutating src_rect to carry the row index was a codegen duplicate of the
// clean indexed source; it supplied no parameter-home lead.
// v18: Adding the exact Drawarea.cpp <stdlib.h> + <string.h> header pair was a
// codegen duplicate.
// v19: Restoring the complete donor-backed TDrawArea/TDrawSystem layouts was a
// codegen duplicate, but is retained below as the canonical ownership surface.
// v20: Threshold-shaped byte/dword loops gained exact-block islands but became
// 432 bytes and still scalar; rolled back.
// v21-22: Two intrinsic memcpys at the destination-alignment split reached the
// required 0x18 frame and REP phases, but emitted two generic dword/byte pairs
// (446/449 bytes); the masked variant was rolled back.
// v23: A byte lead loop plus remainder memcpy stayed 449 bytes with worse CFG;
// rolled back. The remaining REP sequence/CLD is shared with PtrSpanCopy and
// PtrSurfaceCopy and is not reproduced by policy-compliant natural C++.
// v24: Fresh direct CurDisplayOffsets member indexing removed the cached array
// locals, but produced 366 bytes/374 differing bytes and weaker block coverage;
// restored the named indexed memcpy source.
// v25: Fresh baseline confirms the clean typed source and the same 363-byte
// codegen basin. The original PDB bands and labels prove a hand-coded aligned
// REP copy family, which is outside this worker's inline-asm policy.
//
// Summary of remaining issues:
// 1. Frame size: ORIG has sub esp,18h (6 stack locals: nLines, self, nWidth, XofS, DestP, SrcP)
//    VC5 only allocates sub esp,10h — keeps 2 more variables in registers
// 2. memcpy alignment: ORIG has full alignment calc (sub ecx,edi; sub ecx,eax; and ecx,3)
//    VC5 generates simpler version (shr ecx,2; rep movsd; and ecx,3; rep movsb)
// 3. Register allocation: ORIG uses ebx=this/ebx=dest_x, edi/esi for srcleft/srctop
//    VC5 allocates differently despite same source structure
// 4. Parameter slot reuse: ORIG reuses [ebp+14h] for src_row, [ebp+10h] for dst_row,
//    [ebp+0Ch] for dest_x. VC5 doesn't match this pattern.

#include <string.h>

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;

struct TDrawSystem {
    void* Inst;
    void* Wnd;
    void* Pal;
    TDrawArea* DrawArea;
    TDrawArea* PrimaryArea;
    void* DrawAreaList;
    void* DirDraw;
    void* PrimarySurface;
    void* Clipper;
    void* DirDrawPal;
    unsigned long Flags;
    int ScreenWidth;
    int ScreenHeight;
    int ColorBits;
    int ErrorCode;
    char gap_3C[0x43C];
    unsigned char DrawType;  // +0x478
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
    int ClipLeft;                        // +0x28
    int ClipTop;                         // +0x2C
    int ClipRight;                       // +0x30
    int ClipBottom;                      // +0x34
    void* DrawDc;                        // +0x38
    void* DrawSurface;                   // +0x3C
    char SurfaceDesc[0x6C];              // +0x40 .. +0xAB
    void* Node;                          // +0xAC
    char* Name;                          // +0xB0
    unsigned char* LastBits;             // +0xB4
    int LastPitch;                       // +0xB8
    void** DisplayOffsets;               // +0xBC
    void** CurDisplayOffsets;            // +0xC0
    void** FloatOffsets;                 // +0xC4
    void* shadow_color_table;            // +0xC8
    void* SpanList;                      // +0xCC
    void* CurSpanList;                   // +0xD0
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
    unsigned char gap_FD[3];             // +0xFD

    unsigned char* Lock(const char* name, int mode);
    void Unlock(const char* name);
    void PtrCopy(TDrawArea* dest, long dest_x, long dest_y, tagRECT* src_rect);
};

void TDrawArea::PtrCopy(TDrawArea* dest, long dest_x, long dest_y, tagRECT* src_rect) {
    int src_left;
    int src_top;
    int nLines;
    int nWidth;
    int XofS;
    void** SrcP;
    void** DestP;
    int src_row;
    int dst_row;

    src_left = src_rect->left;
    if (src_left < 0) goto exit2;
    if (src_left > src_rect->right) goto exit2;
    if (src_rect->right >= this->Width) goto exit2;

    src_top = src_rect->top;
    if (src_top < 0) goto exit2;
    if (src_top > src_rect->bottom) goto exit2;
    if (src_rect->bottom >= this->Height) goto exit2;

    nLines = src_rect->bottom - src_top + 1;
    nWidth = src_rect->right - src_left + 1;

    if (dest_x < 0) goto exit2;
    if (dest_x >= dest->Width) goto exit2;
    if (dest_y < 0) goto exit2;
    if (dest_y >= dest->Height) goto exit2;

    if (nWidth + dest_x > dest->Width) {
        nWidth = dest->Width - dest_x;
    }
    if (nLines + dest_y > dest->Height) {
        nLines = dest->Height - dest_y;
    }

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        if (this->Lock("PtrCopy1", 1) == 0) goto exit2;
        if (dest->Lock("PtrCopy2", 1) == 0) goto exit2;
    }

    XofS = src_left;
    SrcP = this->CurDisplayOffsets;
    DestP = dest->CurDisplayOffsets;
    src_row = src_top;
    dst_row = dest_y;

    do {
        unsigned char* src_ptr = (unsigned char*)SrcP[src_row] + XofS;
        unsigned char* dst_ptr = (unsigned char*)DestP[dst_row] + dest_x;
        memcpy(dst_ptr, src_ptr, nWidth);
        src_row++;
        dst_row++;
    } while (--nLines != 0);

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2) {
        this->Unlock("PtrCopy1");
        dest->Unlock("PtrCopy2");
    }

exit2:
    return;
}
