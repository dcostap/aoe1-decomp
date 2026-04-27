// VA: 004C1100 RGE_Static_Object ctor (179B)
// stat_obj.cpp lines 132-180
// EH frame (needs /GX)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap4[0xC];
    int field_10;       // +10
    int field_14;       // +14
    char gap18[0x38];
    int field_50;       // +50
    int field_54;       // +54
    int field_58;       // +58
    int field_5C;       // +5C
    int field_60;       // +60
    int field_64;       // +64
    int field_68;       // +68
    int field_6C;       // +6C
    int field_70;       // +70
    int field_74;       // +74
    int field_78;       // +78 (0xFFFFFFFF)
    int field_7C;       // +7C (0xFFFFFFFF)
    float field_80;     // +80 (40A00000h = 5.0f)
    char field_84;      // +84
    char field_85;      // +85
    char field_86;      // +86
    
    RGE_Static_Object(int a1);
};

void __cdecl sub_574530();

RGE_Static_Object::RGE_Static_Object(int a1) {
    // Zero-init from +10 to +70 (range)
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
    
    sub_574530();  // Set vtable
}
