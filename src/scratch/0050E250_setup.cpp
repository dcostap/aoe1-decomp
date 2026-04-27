// VA: 0050E250 setup (271B)
// tm_b_obj.cpp

class TRIBE_Minimap_Background_Object {
public:
    char gap4[0x4];
    int field_8;
    
    void setup(int a1, int a2, int a3);
};

int __cdecl sub_0050E0C0(int a1, int a2, int a3, int a4);

void TRIBE_Minimap_Background_Object::setup(int a1, int a2, int a3) {
    sub_0050E0C0(a2, a1, a3, (int)this);
    field_8 = a1;
}
