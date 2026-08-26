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
// Best current source uses explicit byte-offset copy and a reference alias for the
// destination member. This keeps the original initialization and loop bytes. The
// remaining one-byte drift is the source-load SIB: original `[edx+eax]`, rebuilt
// `[eax+edx]`; the destination store is `[edi+eax]` in both.
//
// BLOCKER: no natural source variant recovered the final source-load SIB byte.
// Integer casts, term order, pointer aliases, array views, reference views,
// register hints, standard headers, and canonical field surfaces were tested.
// Do not use inline assembly or a fake register wrapper.

#include <stdlib.h>

class TDigital;
class TShape;

#ifndef PNL_BTN_SHARED_CONTEXT
class TPanel {
public:
    virtual ~TPanel() {}
    char pad_04[0xF0];
};
#endif /* PNL_BTN_SHARED_CONTEXT */

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel() {}
    enum ButtonType { Radio = 2 };
    char pad_F4[0x48];
    int buttonTypeValue;              // +0x13C
    int drawTypeValue;                // +0x140
    int notifyTypeValue;              // +0x144
    TDigital* sound;                  // +0x148
    TShape* pic[9];                   // +0x14C
    short pic_index[9];               // +0x170
    char pad_182[2];                  // +0x182
    int auto_pic_pos;                 // +0x184
    long pic_x;                       // +0x188
    long pic_y;                       // +0x18C
    int all_hot;                      // +0x190
    int draw_reverse;                 // +0x194
    char* text1[9];                   // +0x198
    char* text2[9];                   // +0x1BC
    long text_x;                      // +0x1E0
    long text_y;                      // +0x1E4
    void* font;                       // +0x1E8
    long font_wid;                    // +0x1EC
    long font_hgt;                    // +0x1F0
    short num_states;                 // +0x1F4
    short cur_state;                  // +0x1F6
    int is_down;                      // +0x1F8
    TButtonPanel** radio_buttons;    // +0x1FC
    short num_radio_buttons;         // +0x200

    void set_radio_info(TButtonPanel** buttons, short count);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_radio_info(TButtonPanel** buttons, short count) {
    int old_radio = (int)this->radio_buttons;
    this->buttonTypeValue = TButtonPanel::Radio;
    if (old_radio != 0) {
        free((void*)old_radio);
        this->radio_buttons = 0;
    }
    if (count != 0) {
        int cnt = (int)(short)count;
        this->num_radio_buttons = count;
        this->radio_buttons = (TButtonPanel**)calloc(cnt, 4);
        if (count > 0) {
            TButtonPanel**& destination = this->radio_buttons;
            int offset = 0;
            int remaining = cnt;
            do {
                *(TButtonPanel**)((char*)destination + offset) =
                    *(TButtonPanel**)((char*)buttons + offset);
                offset += 4;
                --remaining;
            } while (remaining != 0);
        }
    }
}
