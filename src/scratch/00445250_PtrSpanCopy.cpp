// VA: 00445250 TDrawArea::PtrSpanCopy (334 B)
// PDB source: Drawarea.cpp lines 3330-3455
// Copies pixel spans from one TDrawArea to another using a span list.
// Uses /Oy- flag for EBP frame matching (config/flags/00445250_PtrSpanCopy.rsp)
//
// Status: SCRATCH - close but not matching
// Remaining gap: the clean typed source has the correct bounds, Lock call,
// span ownership, and memcpy behavior, but VC5 chooses a different stack/local
// basin and emits a simple rep-movsd/movsb copy rather than the original
// alignment-prefixed expansion.  Diagnostic raw/volatile/register variants
// were rejected.
// Follow-up evidence: the adjacent same-TU PtrCopy and PtrSurfaceCopy bodies
// carry the same explicit `cld`, named Ptr*CpyLoop/LEndBytes labels, and
// alignment-prefixed REP copy sequence.  This target is part of that
// hand-coded copy family; ordinary C/memcpy/manual-loop source cannot emit the
// observed CLD/label topology.  Keep the clean typed reconstruction here and
// leave exact recovery to an asm-policy-approved workstream.

#include <string.h>

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct TSpan {
    TSpan* next;
    char gap_04[4];
    int left;
    int right;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;      // +0x00
    char gap_04[0x04];
    unsigned char* Bits;           // +0x08
    char gap_0C[0x0C];
    int Width;                     // +0x18
    int Height;                    // +0x1C
    char gap_20[0xA0];
    void** CurDisplayOffsets;      // +0xC0

    unsigned char* Lock(char* name, int waitFlag);

    void PtrSpanCopy(TDrawArea* src, long src_x, long src_y, tagRECT* rect, unsigned char** list);
};

void TDrawArea::PtrSpanCopy(TDrawArea* src, long src_x, long src_y, tagRECT* rect, unsigned char** list)
{
    void** DestP;
    long XofS;
    void** SrcP;
    long h;
    long top;

    if (rect->left < 0) return;
    if (rect->left > rect->right) return;
    if (rect->right >= this->Width) return;
    if (rect->top < 0) return;
    if (rect->top > rect->bottom) return;
    if (rect->bottom >= this->Height) return;

    h = rect->bottom - rect->top + 1;

    if (src_x < 0) return;
    if (src_x >= src->Width) return;
    if (src_y < 0) return;
    if (src_y >= src->Height) return;

    if (h + src_y > src->Height)
        h = src->Height - src_y;

    if (this->DrawSystem != 0 && this->DrawSystem->DrawType == 2)
        if (src->Lock("PtrSpanCopy", 1) == 0)
            return;

    XofS = rect->left;
    top = rect->top;
    DestP = (void**)src->CurDisplayOffsets;
    SrcP = this->CurDisplayOffsets;

    do {
        unsigned char* dest_base = (unsigned char*)DestP[src_y] + src_x;
        unsigned char* src_base = (unsigned char*)SrcP[top] + XofS;
        TSpan* span = (TSpan*)list[top];

        if (span) {
            do {
                int span_left = span->left;
                unsigned char* dest_span = dest_base + span_left;
                unsigned char* src_span = src_base + span_left;
                int span_count = span->right - span_left + 1;
                memcpy(dest_span, src_span, span_count);
                span = span->next;
            } while (span);
        }

        top++;
        src_y++;
    } while (--h != 0);
}
