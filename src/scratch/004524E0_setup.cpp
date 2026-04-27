// VA: 004524E0 setup (1563B)
// m_s_obj.cpp

class RGE_Master_Static_Object {
public:
    char gap4[0x4];
    unsigned char field_8;
    char gap9[0x3];
    int field_C;
    
    void setup(int a1, int a2, int a3);
};

void __cdecl sub_00450EC0(int a1, int a2, int a3);

void RGE_Master_Static_Object::setup(int a1, int a2, int a3) {
    sub_00450EC0(a1, a2, a3);
    
    field_8 = 2;
}
