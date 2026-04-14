class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_0[0x82];
    unsigned char field_86;
    void setUnderAttack(unsigned char v);
};

void RGE_Static_Object::setUnderAttack(unsigned char v) { this->field_86 = v; }
