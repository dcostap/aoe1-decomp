// VA: 004C0960 get_frame (514B)
// sprite.cpp
// EH frame (/GX)

class RGE_Sprite {
public:
    char gap4[0x18];
    int field_1C;
    char gap20[0x38];
    int field_58;
    char gap5C[0x24];
    int field_80;
    
    int get_frame(int frameIdx);
};

int RGE_Sprite::get_frame(int frameIdx) {
    if (!field_1C) return 0;
    
    // Get frame data
    if (frameIdx >= 0) {
        field_80 = frameIdx;
    }
    
    return field_58;
}
