// VA: 0046E770 RGE_Player ctor2 (897B)
// player.cpp
// EH frame (/GX)

void __cdecl sub_00471E40(void* ptr, int size);

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap4[0x4];
    int field_08;
    int field_0C;
    char gap10[0x48];
    short field_4A;
    char gap4C[0xB9];
    char field_105;
    
    RGE_Player(int a1, unsigned char a2);
    void init_58_6C();
};

void* rge_base_vfptr = (void*)0x570ED0;

RGE_Player::RGE_Player(int a1, unsigned char a2) {
    field_08 = 5;
    field_0C = 10;
    
    init_58_6C();
    
    field_08 = *(int*)0x57F9F8;
    field_105 = a2;
    *(void**)this = rge_base_vfptr;
}
