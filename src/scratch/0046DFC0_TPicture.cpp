// TPicture::~TPicture at 0046DFC0 (Picture.cpp lines 91-109)
// Inventory: 0046DFC0_TPicture
// Status: NOT EXACT MATCH — left in scratch
// Attempt log summary:
//   v1: straightforward struct-based impl; compiled, but TRANSINFO->LineInfo offset came out as +4 (not +0x14 as required).
//   v2: added padding/member reordering to force offset 0x14 — compiler still used +4.
//   v3: switched to manual offset via *(LINEINFO**)((char*)ti + 0x14); this fixed LineInfo offset (now uses +0x14 in code).
//   v4: used manual offsets for AnyTrans too; got correct AnyTrans offset 0 and LineInfo offset 0x14. Code structure matched original for first half (trans block). However Dib handling differs: original has two separate DibFree calls with a conditional branch on OwnMemory==2 (two call sites). Our code merged into one call after condition, saving ~5 code bytes; also epilogue differs slightly. Resulting .text size = 80 bytes vs expected 85. Several cycles of tweaking did not close gap; VC5 codegen differences likely due to optimization merging duplicate calls.
//   Remaining gaps: missing duplicated DibFree call sites; overall size short by 5 bytes; minor instruction ordering/register differences.
//   Leaving in src/scratch per quick-win limits (≤10 tries). Requires either different source shape (perhaps two distinct call blocks via goto) or hand-tuned asm to hit exact bytes.

#include <stddef.h>
class LINEINFO;
extern "C" void __cdecl free(void*);
extern "C" void __cdecl DibFree(void*);

struct TRANSINFO; // incomplete, accessed via manual offsets only

class TPicture {
public:
    void*        Dib;
    void*        BitmapInfo;
    unsigned char* Bits;
    TRANSINFO*   TransInfo;
    int         OwnMemory;
    ~TPicture();
};

TPicture::~TPicture() {
    if (this->OwnMemory == 0) return;

    char* ti = (char*)this->TransInfo;
    if (ti != 0) {
        LINEINFO* li = *(LINEINFO**)(ti + 0x14);
        if (li != 0 && *(int*)ti != 0) {
            free(li);
        }
        free(this->TransInfo);
    }

    if (this->Dib != 0) {
        if (this->OwnMemory == 2) {
            DibFree(this->Dib);
            return;
        }
        DibFree(this->Dib);
    }
}
