// VA: 0051B190 draw (3387B)
// tpnl_obj.cpp

class TRIBE_Panel_Object {
public:
    char gap4[0x1C];
    int field_20;
    char gap24[0x4C];
    int field_70;
    char gap74[0x8C];
    int field_100;
    
    void draw();
};

void TRIBE_Panel_Object::draw() {
    if (!field_20) return;
    if (!field_70) return;
    
    field_100 = field_20;
}
