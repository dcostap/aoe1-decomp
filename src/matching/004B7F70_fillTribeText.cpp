// VA: 004B7F70 fillTribeText (210B)
// scr_trb.cpp lines 202-233
// TribeSelectTribeScreen::tribeText is +0x480. The text setter is the proved
// TTextPanel virtual at +0xE8. Scroll is a direct TTextPanel member call.
// The complete inherited surface is in scr_trb_context.h; it uses no slot
// padding or raw vtable access.

#include "../../include/scr_trb_context.h"

void TribeSelectTribeScreen::fillTribeText(int tribeIdx) {
    switch (tribeIdx) {
    case 0:
        this->tribeText->set_text("Assyrian information here.");
        break;
    case 1:
        this->tribeText->set_text("Babylonian information here.");
        break;
    case 2:
        this->tribeText->set_text("Egyptian information here.");
        break;
    case 3:
        this->tribeText->set_text("Greek information here.");
        break;
    case 4:
        this->tribeText->set_text("Hittite information here.");
        break;
    case 5:
        this->tribeText->set_text("Isrealite information here.");
        break;
    case 6:
        this->tribeText->set_text("Minoan information here.");
        break;
    case 7:
        this->tribeText->set_text("Phoenician information here.");
        break;
    case 8:
        this->tribeText->set_text("Sumerian information here.");
        break;
    }

    this->tribeText->scroll(6, 0, 1);
}
