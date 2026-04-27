// VA: 004521E0 setup (755B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x4];
    unsigned char field_8;
    char gap9[0x3];
    short field_C;
    char gapE[0xA0];
    unsigned char field_AE;
    char gapAF[0x3];
    int field_B0;
    int field_B4;
    
    void setup(int* src);
};

void RGE_Master_Static_Object::setup(int* src) {
    field_8 = 0x0A;
    field_AE = *(unsigned char*)((char*)src + 0xA4);
    field_C = *(short*)((char*)src + 0x0C);
    field_B0 = 0;
    field_B4 = 0;
}
