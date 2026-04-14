class TRIBE_Panel_Button {
public:
    virtual ~TRIBE_Panel_Button();
    char gap_0[0x2B8];
    int field_2BC;
    int get_garrison_number();
};

int TRIBE_Panel_Button::get_garrison_number() { return this->field_2BC; }
