class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_0[0x130];
    int field_134;
    void setActionRange(int v);
};

void RGE_Moving_Object::setActionRange(int v) { this->field_134 = v; }
