// VA: 0051BF90 draw_score (614B)
// tpnl_obj.cpp

class TRIBE_Panel_Object {
public:
    char gap4[0x1C];
    int field_20;
    char gap24[0x4C];
    int field_70;
    char gap74[0x20];
    int field_94;
    
    void draw_score();
};

void TRIBE_Panel_Object::draw_score() {
    if (!field_20) return;
    if (!field_70) return;
    
    field_94 = field_20;
}
