// VA: 004C4F10 transform (151B)
// stat_obj.cpp

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual int method_DC(int a1, int a2);
    char gap8[0x4];
    int field_0C;
    int field_08;
    char gap10[0x14];
    int field_1C;
    char gap20[0x10];
    float field_30;
    char gap34[0x2];
    short field_s26;
    char gap28[0x32];
    int field_5C;
    
    void transform(int param1);
};

void __cdecl sub_004C6C90(RGE_Static_Object* obj, int mode);

void RGE_Static_Object::transform(int param1) {
    float f = (float)(signed short)(*(short*)((char*)field_08 + 0x26));
    if (field_30 != 0.0f) {
        f = f / field_30;
    }
    
    if (field_1C) {
        method_DC(-1, 0);
    }
    
    sub_004C6C90(this, 2);
    
    field_08 = param1;
    
    if (field_1C) {
        method_DC(-1, 0);
    }
}
