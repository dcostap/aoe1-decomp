// VA: 00445250 TDrawArea::PtrSpanCopy (334 B)
// PDB source: Drawarea.cpp lines 3330-3455
// Copies pixel spans from one TDrawArea to another using a span list.
// Uses /Oy- flag for EBP frame matching (config/flags/00445250_PtrSpanCopy.rsp)
//
// Status: SCRATCH - close but not matching
// Remaining issues:
// 1. Register allocation: original uses edi for rect*, rebuilt uses esi.
//    Original pushes all 3 preserved regs (ebx, esi, edi) before any param access,
//    rebuilt pushes edi after first param load. All attempts to change variable
//    declaration order/types haven't flipped the allocation.
// 2. Alignment-optimized inner copy: original uses rep movsb/rep movsd with
//    alignment computation (-(int)src & 3). Rebuilt while-loops don't produce
//    rep movs* instructions. The minus_align variant gets sub esp 0Ch but
//    doesn't produce the exact alignment sequence.
// 3. Original caches rect->top in param_1 slot and src_y in param_2 slot, then
//    increments them directly. Rebuilt uses separate stack locals for these.
//
// Tried: top-decl vs deferred locals, order of d/s assignments, memcpy,
//   void** DestP/SrcP patterns, combined || conditions, separate if returns,
//   with/without block scopes, minus_align vs simple loop copy.
// Best edit diff: ~66% with memcpy, ~70% with minus_align.

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
        unsigned char* d = ((unsigned char**)DestP)[src_y] + src_x;
        unsigned char* s = ((unsigned char**)SrcP)[top] + XofS;
        unsigned char* r = list[top];

        if (r) {
            do {
                int a = *(int*)(r + 8);
                int b = *(int*)(r + 12);
                int n = b - a + 1;
                unsigned char* d2 = d + a;
                unsigned char* s2 = s + a;

                {
                    int align = (-(int)(int)s2) & 3;
                    int aligned = n - align;
                    if (aligned > 0) {
                        while (align-- != 0) *d2++ = *s2++;
                        {
                            int dw = aligned >> 2;
                            int rm = aligned & 3;
                            while (dw-- != 0) { *(int*)d2 = *(int*)s2; d2 += 4; s2 += 4; }
                            while (rm-- != 0) *d2++ = *s2++;
                        }
                    } else {
                        while (n-- != 0) *d2++ = *s2++;
                    }
                }

                r = *(unsigned char**)r;
            } while (r);
        }

        top++;
        src_y++;
    } while (--h != 0);
}
