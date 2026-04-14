class TSound_Driver {
public:
    virtual ~TSound_Driver();
    char gap_0[0x14];
    int field_18;
    int get_volume();
};

int TSound_Driver::get_volume() { return this->field_18; }
