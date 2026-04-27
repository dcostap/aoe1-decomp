// VA: 004C0720 shadow_draw (274B)
// sprite.cpp

class RGE_Sprite {
public:
    char gap4[0x5C];
    short field_60;
    char gap62[0x1E];
    int field_80;
    
    void shadow_draw(int a1, int a2, int a3);
};

void RGE_Sprite::shadow_draw(int a1, int a2, int a3) {
    if ((signed short)field_60 != -1) {
        if (a1 >= (signed short)field_60) {
            a1 = 0;
        }
    }
    
    // Draw shadow
    field_80 = a1;
}
