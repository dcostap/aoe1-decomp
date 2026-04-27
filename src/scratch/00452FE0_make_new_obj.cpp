// VA: 00452FE0 make_new_obj (201B)
// m_s_obj.cpp
// EH frame (/GX)

class RGE_Master_Static_Object {
public:
    char gap4[0xA0];
    unsigned char field_A4;
    char gapA5[0x3];
    int field_A8;
    
    void make_new_obj(int a1);
};

void* __cdecl operator_new(unsigned size);

void RGE_Master_Static_Object::make_new_obj(int a1) {
    if (field_A4 == 0) return;
    
    void* buf = operator_new(a1);
    if (buf) {
        field_A8 = (int)buf;
    }
}
