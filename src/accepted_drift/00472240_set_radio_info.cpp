// VA: 00472240 TButtonPanel::set_radio_info(TButtonPanel** param_1, short param_2)
// PDB source: Pnl_btn.cpp lines 207-225
// Default flags
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.
// Frees old radio_buttons array, allocates new one, copies pointers.
//
// Near match. Initial source had only a 4-byte scheduling swap in copy-loop init:
// original `xor eax,eax; mov ecx,ebx`, rebuild `mov ecx,ebx; xor eax,eax`.
// Tried declaration/order splits and a src local; no change.
// Best current source uses explicit byte-offset copy, forcing original init order and
// reducing drift to two SIB bytes: original uses `[edx+eax]` and `[edi+eax]`, rebuild
// encodes equivalent `[eax+edx]` and `[eax+edi]`. Positional/edit diff 2/118.
// Tried integer casts/term-order variants and dst temp; either same SIB drift or wrong
// 112-byte size.
// ACCEPTED_DRIFT: reviewed by Boss. Remaining diff is only equivalent SIB base/index
// encoding in the copy loop: original `[edx+eax]` / `[edi+eax]`, rebuilt `[eax+edx]` /
// `[eax+edi]`. Same registers, effective addresses, flags, memory effects, calls,
// loop control, size, and epilogue.

#include <stdlib.h>

class TButtonPanel {
public:
    virtual ~TButtonPanel() {}
    char pad_04[0x138];
    int buttonTypeValue;              // +0x13C
    char pad_140[0xBC];
    TButtonPanel** radio_buttons;    // +0x1FC
    short num_radio_buttons;         // +0x200

    void set_radio_info(TButtonPanel** buttons, short count);
};

void TButtonPanel::set_radio_info(TButtonPanel** buttons, short count) {
    int old_radio = (int)this->radio_buttons;
    this->buttonTypeValue = 2;
    if (old_radio != 0) {
        free((void*)old_radio);
        this->radio_buttons = 0;
    }
    if (count != 0) {
        int cnt = (int)(short)count;
        this->num_radio_buttons = count;
        this->radio_buttons = (TButtonPanel**)calloc(cnt, 4);
        if (count > 0) {
            int offset = 0;
            int remaining = cnt;
            do {
                *(TButtonPanel**)((char*)this->radio_buttons + offset) = *(TButtonPanel**)((char*)buttons + offset);
                offset += 4;
                remaining--;
            } while (remaining != 0);
        }
    }
}
