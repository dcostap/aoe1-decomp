// VA: 0051ADF0 TRIBE_Panel_Object ctor (596B)
// tpnl_obj.cpp
// EH frame (/GX)

class TRIBE_Panel_Object {
public:
    int* vtable;
    char gap4[0x1C];
    int field_20;
    char gap24[0x4C];
    int field_70;
    char gap74[0x8C];
    int field_100;
    int field_104;
    
    TRIBE_Panel_Object();
};

TRIBE_Panel_Object::TRIBE_Panel_Object() {
    vtable = 0;
    field_20 = 0;
    field_70 = 0;
    field_104 = 0;
}
