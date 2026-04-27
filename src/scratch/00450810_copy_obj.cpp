// VA: 00450810 copy_obj (481B)
// m_co_obj.cpp

class RGE_Master_Combat_Object {
public:
    char gap4[0xF8];
    int field_FC;
    char field_100;
    char gap101[0x7];
    short field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    int field_11C;
    
    void copy_obj(void* src);
};

void __cdecl sub_0044F760(void* this_, void* src);

void RGE_Master_Combat_Object::copy_obj(void* src) {
    sub_0044F760(this, src);
    
    field_FC = *(int*)((char*)src + 0xFC);
    field_100 = *(char*)((char*)src + 0x100);
    
    field_10C = *(int*)((char*)src + 0x10C);
}
