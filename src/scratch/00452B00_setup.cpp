// VA: 00452B00 setup (1183B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x4];
    unsigned char field_8;
    char gap9[0x7];
    short field_10;
    char gap12[0xA2];
    int field_B0;
    int field_B4;
    
    void setup(short a1);
};

void RGE_Master_Static_Object::setup(short a1) {
    field_8 = 0x0A;
    field_10 = a1;
    field_B0 = 0;
    field_B4 = 0;
}
