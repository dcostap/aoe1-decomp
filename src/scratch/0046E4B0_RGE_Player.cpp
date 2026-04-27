// VA: 0046E4B0 RGE_Player ctor (661B)
// player.cpp
// EH frame (/GX)

void __cdecl sub_00471E40(void* ptr, int size);

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap4[0x4];
    int field_08;
    int field_0C;
    char gap10[0x4A];
    short field_4A;
    short field_4C;
    
    RGE_Player(int a1, int a2, int a3, unsigned char a4);
    void init_58_6C();
};

void* rge_base_vfptr = (void*)0x570ED0;

RGE_Player::RGE_Player(int a1, int a2, int a3, unsigned char a4) {
    field_08 = 5;
    field_0C = 10;
    
    init_58_6C();
    
    *(void**)this = rge_base_vfptr;
    field_4A = a4;
    field_4C = a1;
}
