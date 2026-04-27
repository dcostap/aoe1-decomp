// VA: 004506D0 make_new_obj (201B)
// m_co_obj.cpp
// EH frame (/GX)

class RGE_Master_Combat_Object {
public:
    char gap4[0x4];
    char field_04;
    char gap5[0x9F];
    char field_A4;
    
    void* make_new_obj(int a1, int a2);
};

void* __cdecl operator_new(unsigned size);

void* RGE_Master_Combat_Object::make_new_obj(int a1, int a2) {
    if (!field_A4) return 0;
    
    int objSize = 0x218;
    void* obj = operator_new(objSize);
    return obj;
}
