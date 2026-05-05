// VA: 00472240 TButtonPanel::set_radio_info(TButtonPanel** param_1, short param_2)
// PDB source: Pnl_btn.cpp lines 207-225
// Default flags
//
// __thiscall: this in ecx, 2 stack params. ret 8 cleanup.
// Frees old radio_buttons array, allocates new one, copies pointers.
//
// 116/120 edit-match bytes, only 4 positional diff bytes.
// Remaining: scheduling swap of xor eax,eax / mov ecx,ebx in copy loop init.
// Original: xor eax,eax; mov ecx,ebx. Rebuild: mov ecx,ebx; xor eax,eax.
// VC5 schedules independent xor/mov in different order. 4 bytes swapped, functionally identical.

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
            int remaining = cnt;
            int i = 0;
            do {
                this->radio_buttons[i] = buttons[i];
                i++;
                remaining--;
            } while (remaining != 0);
        }
    }
}
