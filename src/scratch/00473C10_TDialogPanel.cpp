// TDialogPanel::TDialogPanel(char* name) - call TEasy_Panel base ctor, init dialog fields

class TEasy_Panel {
public:
    TEasy_Panel(char* name);
};

class TDialogPanel : public TEasy_Panel {
public:
    char pad_04[0x474];
    int field_478;         // 0x478 - zeroed
    int field_47C;         // 0x47C - zeroed
    int field_480;         // 0x480 - set to 0xB (11)
    int field_484;         // 0x484 - set to 0xB
    int field_488;         // 0x488 - set to 0xB
    int field_48C;         // 0x48C - zeroed

    TDialogPanel(char* name);
};

TDialogPanel::TDialogPanel(char* name) : TEasy_Panel(name) {
    this->field_480 = 0xB;
    this->field_484 = 0xB;
    this->field_488 = 0xB;
    this->field_478 = 0;
    this->field_47C = 0;
    this->field_48C = 0;
}
