class TRIBE_Screen_Sed {
public:
    virtual ~TRIBE_Screen_Sed();
    char gap_0[0x4BC];
    unsigned char field_4C0;
    unsigned char need_to_save();
};

unsigned char TRIBE_Screen_Sed::need_to_save() { return this->field_4C0; }
