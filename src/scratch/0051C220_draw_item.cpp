// VA: 0051C220 draw_item (442B)
// tpnl_obj.cpp

class TRIBE_Panel_Object {
public:
    char gap4[0x100];
    int field_104;
    char gap108[0x18];
    int field_120;
    
    void draw_item(int idx, int a2);
};

void TRIBE_Panel_Object::draw_item(int idx, int a2) {
    if (!field_104) return;
    
    if (idx == -1) return;
    
    field_120 = idx;
}
