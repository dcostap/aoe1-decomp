// VA: 004C0840 get_size (279B)
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
    
    int get_size();
};

int RGE_Sprite::get_size() {
    if (field_1C) {
        field_80 = field_58;
        return field_58;
    }
    return 0;
}
