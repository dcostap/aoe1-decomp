// TPicture::~TPicture at 0046DFC0 (Picture.cpp lines 91-109)
// exact basin: manual 0x14 LineInfo offset, plus the final ownership split must really be free-vs-DibFree.

#include <stddef.h>
#ifndef PICTURE_CONTEXT_H
class LINEINFO;
#endif
extern "C" void __cdecl free(void*);
#ifndef PICTURE_CONTEXT_H
extern "C" void __cdecl DibFree(void*);
#endif

#ifndef PICTURE_CONTEXT_H
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
#endif

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
            free(this->Dib);
            return;
        }
        DibFree(this->Dib);
    }
}
