// VA: 004B7F70 fillTribeText (210B)
// scr_trb.cpp lines 202-233
// Baseline reconstruction: TribeSelectTribeScreen::tribeText is +0x480;
// the text setter is the TTextPanel virtual at +0xE8 and scroll is a direct
// TTextPanel member call.
// Probe 1: replaced raw vtable/helper calls and the explicit range guard with
// the natural virtual switch and direct scroll member surface.

class TTextPanel {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4();
    virtual void set_text(char* text);

    void scroll(int scroll_type, short amount, int param_3);
};

class TribeSelectTribeScreen {
public:
    char gap0[0x480];
    TTextPanel* tribeText;

    void fillTribeText(int tribeIdx);
};

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
