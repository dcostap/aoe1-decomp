// VA: 0044FF30 RGE_Master_Combat_Object ctor (119B)
// m_co_obj.cpp
// EH frame (/GX)

class RGE_Master_Combat_Object {
public:
    char gap4[0x4];
    char field_04;
    char gap5[0xF7];
    int field_FC;
    char field_100;
    char gap101[0x107];
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    
    RGE_Master_Combat_Object(int a1, int a2, int a3, int a4, int a5);
};

void __cdecl sub_0044F1E0(void* this_, int a1, int a2, int a3, int a4);

RGE_Master_Combat_Object::RGE_Master_Combat_Object(int a1, int a2, int a3, int a4, int a5) {
    sub_0044F1E0(this, a1, a2, a3, a4);
    field_04 = 0x32;
    field_FC = a5;
    field_100 = 0;
    field_208 = 0;
    field_20C = 0;
    field_210 = 0;
    field_214 = -1;
}
