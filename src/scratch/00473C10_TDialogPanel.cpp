class TEasy_Panel {
public:
    void* vftable;
    char gap_04[0x474];

    TEasy_Panel(char* name);
};

class TDialogPanel : public TEasy_Panel {
public:
    int field_478;
    int field_47C;
    int field_480;
    int field_484;
    int field_488;
    int field_48C;

    TDialogPanel(char* name);
};

TDialogPanel::TDialogPanel(char* name) : TEasy_Panel(name) {
    int zero = 0;

    field_480 = 0xB;
    field_484 = 0xB;
    field_488 = 0xB;
    field_478 = zero;
    field_47C = zero;
    field_48C = zero;
    *(volatile void**)this = (void*)0x005710B0;
}
