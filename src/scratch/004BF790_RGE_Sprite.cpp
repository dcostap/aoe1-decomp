// VA: 004BF790 RGE_Sprite ctor (656B)
// sprite.cpp

class RGE_Sprite {
public:
    char gap4[0x14];
    int field_18;
    char gap1C[0x2C];
    char field_48[0x20];
    
    RGE_Sprite(int a1, int a2, int a3);
};

void __cdecl sub_004C0F90(void* this_, int a1, int a2, int a3);

RGE_Sprite::RGE_Sprite(int a1, int a2, int a3) {
    field_18 = a1;
    sub_004C0F90(field_48, 0x15, a2, a3);
}
