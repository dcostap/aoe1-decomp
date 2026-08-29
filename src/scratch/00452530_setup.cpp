// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x4];
    unsigned char field_8;
    char gap9[0x7];
    short field_10;
    
    void setup(int a1, int a2, int a3);
};

void RGE_Master_Static_Object::setup(int a1, int a2, int a3) {
    field_8 = 0x0A;
    field_10 = (short)a1;
}
