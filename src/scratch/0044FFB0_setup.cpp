// VA: 0044FFB0 setup (438B)
// m_co_obj.cpp

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
    
    void setup(void* src);
};

void __cdecl sub_0044F1E0(void* this_, void* src);

void RGE_Master_Combat_Object::setup(void* src) {
    sub_0044F1E0(this, src);
    field_04 = 0x32;
    
    field_FC = *(int*)((char*)src + 0xFC);
    field_100 = *(char*)((char*)src + 0x100);
}
