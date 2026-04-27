// VA: 0051B070 ~TRIBE_Panel_Object dtor (148B)
// tpnl_obj.cpp
// EH frame (/GX)

class TRIBE_Panel_Object {
public:
    int* vtable;
    char gap4[0x1C];
    int field_20;
    char gap24[0x4];
    int field_28;
    
    ~TRIBE_Panel_Object();
};

TRIBE_Panel_Object::~TRIBE_Panel_Object() {
    vtable = (int*)0x576C98;
    if (field_20) {
        field_28 = 0;
    }
}
