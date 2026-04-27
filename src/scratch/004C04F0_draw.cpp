// VA: 004C04F0 draw (304B)
// sprite.cpp

class RGE_Sprite {
public:
    char gap4[0x5C];
    short field_60;
    char gap62[0x1E];
    int field_80;
    
    void draw(int frameIdx, int a2, int a3);
};

void RGE_Sprite::draw(int frameIdx, int a2, int a3) {
    if (frameIdx >= (signed short)field_60) {
        frameIdx = 0;
    }
    
    field_80 = frameIdx;
}
