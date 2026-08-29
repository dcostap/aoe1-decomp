// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x4];
    unsigned char field_8;
    char gap9[0x3];
    short field_C;
    
    void setup(int a1, int a2);
};

void RGE_Master_Static_Object::setup(int a1, int a2) {
    field_8 = 0x0A;
    field_C = (short)a1;
}
