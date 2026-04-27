// VA: 004BFA20 RGE_Sprite ctor2 (701B)
// sprite.cpp

class RGE_Sprite {
public:
    char gap4[0x14];
    int field_18;
    char gap1C[0x4];
    int field_20;
    int field_24;
    char gap28[0x20];
    char field_48[0x20];
    char gap68[0x18];
    int field_80;
    
    RGE_Sprite(short a1);
};

void __cdecl sub_004BF880(void* this_, short a1);

RGE_Sprite::RGE_Sprite(short a1) {
    field_18 = 0;
    field_20 = 0;
    field_24 = 0;
    sub_004BF880(this, a1);
}
