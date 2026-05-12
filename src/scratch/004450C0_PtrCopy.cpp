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

struct TDrawSystem {
    char gap_00[0x478];
    unsigned char DrawType;  // +0x478
};

struct TDrawArea {
    TDrawSystem* DrawSystem;   // +0x00
    char gap_04[0x14];         // +0x04 to +0x17
    int Width;                 // +0x18
    int Height;                // +0x1C
    char gap_20[0xA0];         // +0x20 to +0xBF
    void** CurDisplayOffsets;  // +0xC0

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
