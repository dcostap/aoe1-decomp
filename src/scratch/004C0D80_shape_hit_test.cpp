// VA: 004C0D80 shape_hit_test (516B)
// sprite.cpp
// EH frame (/GX)

class RGE_Sprite {
public:
    char gap4[0x18];
    int field_1C;
    char gap20[0x38];
    int field_58;
    
    int shape_hit_test(int x, int y);
};

int RGE_Sprite::shape_hit_test(int x, int y) {
    if (!field_1C) return 0;
    
    // Test if point hits the shape
    if (field_58 > 0) {
        return 1;
    }
    return 0;
}
