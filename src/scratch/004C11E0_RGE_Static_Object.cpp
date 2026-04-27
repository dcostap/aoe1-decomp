// VA: 004C11E0 RGE_Static_Object ctor (164B)
// stat_obj.cpp lines 182-229
// EH frame (needs /GX)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap4[0xC];
    int field_10;
    int field_14;
    char gap18[0x38];
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    int field_74;
    int field_78;
    int field_7C;
    float field_80;
    char field_84;
    char field_85;
    char field_86;
    
    RGE_Static_Object(int a1, int a2);
};

void __cdecl sub_574530();

RGE_Static_Object::RGE_Static_Object(int a1, int a2) {
    field_10 = 0;
    field_14 = 0;
    field_50 = 0;
    field_54 = 0;
    field_58 = 0;
    field_5C = 0;
    field_60 = 0;
    field_64 = 0;
    field_68 = 0;
    field_6C = 0;
    field_70 = 0;
    field_74 = 0;
    field_78 = -1;
    field_7C = -1;
    field_80 = 5.0f;
    field_84 = 0;
    field_85 = 0;
    field_86 = 0;
    
    sub_574530();
}
