class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x84];
    int field_88;
    void stop_moving();
};

void RGE_Moving_Object::stop_moving() { this->field_88 = 0; }
