// VA: 0051C3F0 handle_idle (1568B)
// tpnl_obj.cpp

class TRIBE_Panel_Object {
public:
    char gap4[0x68];
    int field_6C;
    char gap70[0x10];
    int field_80;
    
    void handle_idle();
};

void __cdecl sub_00465780(void* this_);

void TRIBE_Panel_Object::handle_idle() {
    sub_00465780(this);
    
    if (field_6C) {
        field_80 = 0x37C;
    }
}
