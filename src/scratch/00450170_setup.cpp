// VA: 00450170 setup (730B)
// m_co_obj.cpp

class RGE_Master_Combat_Object {
public:
    char gap4[0x4];
    char field_04;
    char gap5[0xF7];
    int field_FC;
    char field_100;
    char gap101[0x7];
    short field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    
    void setup(int a1, int a2, int a3, int a4);
};

void __cdecl sub_0044F290(void* this_, int a1, int a2, int a3);

void RGE_Master_Combat_Object::setup(int a1, int a2, int a3, int a4) {
    sub_0044F290(this, a1, a2, a3);
    
    field_100 = 0;
    field_108 = 0;
    field_10C = 0;
    field_110 = 0;
    field_114 = 0;
    field_118 = 0;
    field_11C = 0;
}
