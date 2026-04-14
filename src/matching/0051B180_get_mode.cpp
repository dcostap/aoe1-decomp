class TRIBE_Panel_Object {
public:
    virtual ~TRIBE_Panel_Object();
    char gap_0[0x11C];
    unsigned char field_120;
    unsigned char get_mode();
};

unsigned char TRIBE_Panel_Object::get_mode() { return this->field_120; }
