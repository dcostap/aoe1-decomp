// VA: 004C01A0 do_draw (837B)
// sprite.cpp
// EH frame (/GX)

class RGE_Sprite {
public:
    char gap4[0x18];
    int field_1C;
    char gap20[0x28];
    char field_48;
    char gap49[0x17];
    int field_60;
    
    void do_draw(int a1, int a2, int a3);
};

void RGE_Sprite::do_draw(int a1, int a2, int a3) {
    if (field_1C) {
        field_48 = 1;
        field_60 = a1;
    }
}
