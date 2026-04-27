// VA: 0050E7A0 draw (420B)
// tm_b_obj.cpp

class TRIBE_Minimap_Background_Object {
public:
    char gap4[0x14];
    int field_18;
    char gap1C[0x150];
    unsigned char field_16C;
    
    void draw();
};

void TRIBE_Minimap_Background_Object::draw() {
    if (!field_18) return;
    
    unsigned char flag = field_16C;
    if (flag) {
        field_18 = (int)flag;
    }
}
