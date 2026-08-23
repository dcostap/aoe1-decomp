// VA: 00492CC0 TRIBE_Credits_Screen::draw — EXACT MATCH
// Source: scr_cred.cpp lines 337-363
// FLAGS: /nologo /c /O2 /Oy
//
// Key matching insight: TScreenPanel is a base class with a virtual draw(),
// so it contributes a 4-byte vtable at +0x00. The remaining fields follow
// with gap_04[0x1C] (28 bytes) placing field_20 at offset +0x20.
// The Clear call uses (TDrawArea*)(this->field_20) as ECX (this) and
// &this->field_24 as the rect parameter on the stack.

#include "../../include/scr_cred_context.h"

typedef unsigned char uchar;

void TRIBE_Credits_Screen::draw() {
    if (this->mode == 4) {
        uchar* check = (uchar*)*(int*)this->field_20;
        if (check[0x479] == 2 || check[0x478] == 1) {
            ((TDrawArea*)this->field_20)->Clear(&this->field_24, 0);
            return;
        }
    }

    if (this->first_draw != 0) {
        for (int i = 0; i < 7; i++) {
            this->field_204 = this->back_pics[i];
            TScreenPanel::draw();
        }
        this->first_draw = 0;
        this->field_204 = this->back_pics[0];
    }

    TScreenPanel::draw();
}
