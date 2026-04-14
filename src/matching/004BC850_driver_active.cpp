class TSound_Driver {
public:
    unsigned char field_0;
    int driver_active();
};

int TSound_Driver::driver_active() { return this->field_0; }
