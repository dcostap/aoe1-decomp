// VA: 00450450 setup (557B)
// m_co_obj.cpp

class RGE_Master_Combat_Object {
public:
    char gap4[0x104];
    int field_108;
    char gap10C[0x10];
    int field_11C;
    
    void setup(int a1, int a2, int a3, int a4, int a5);
};

void __cdecl sub_0044F360(void* this_, int a1, int a2, int a3, int a4);

void RGE_Master_Combat_Object::setup(int a1, int a2, int a3, int a4, int a5) {
    sub_0044F360(this, a1, a2, a3, a4);
}
