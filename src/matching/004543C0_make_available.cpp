class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_0[0x4E];
    unsigned char field_52;
    void make_available(unsigned char v);
};

void RGE_Master_Static_Object::make_available(unsigned char v) { this->field_52 = v; }
