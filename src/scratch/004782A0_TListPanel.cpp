// VA: 004782A0 TListPanel::TListPanel (Pnl_lst.cpp:26-41, 102B)
// Attempt: explicit pointer arithmetic for field_188 offset to separate traversal

class TTextPanel {
public:
    virtual ~TTextPanel();
    TTextPanel();
    char gap_04[0x7C];
    int field_80;
    char gap_84[0x3C];
    int field_C0;
    char gap_C4[0x2A];
    unsigned char field_EE;
    char gap_EF[0x81];
    int field_170;
    int field_174;
    int field_178;
    int field_17C;
    int field_180;
    int field_184;
    int field_18C;
    int field_190;
    int field_194;
    int field_198;
    int field_19C;
};

class TListPanel : public TTextPanel {
public:
    TListPanel();
};

TListPanel::TListPanel() : TTextPanel() {
    this->field_C0 = 0;
    this->field_18C = 0;
    this->field_194 = 0;
    this->field_198 = 0;
    *(int*)((char*)this + 0x188) = 0;
    this->field_19C = 1;
    this->field_EE = 4;
    this->field_170 = 1;
    this->field_190 = 0x32;
    this->field_80 = 1;
    this->field_184 = 1;
    this->field_180 = 1;
}
