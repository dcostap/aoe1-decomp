class TRIBE_Building_Object {
public:
    virtual ~TRIBE_Building_Object();
    char gap_0[0x1CC];
    unsigned char field_1D0;
    void enable_production_queue(unsigned char v);
};

void TRIBE_Building_Object::enable_production_queue(unsigned char v) { this->field_1D0 = v; }
