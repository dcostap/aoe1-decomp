// VA: 0046EB00 ~RGE_Player dtor (380B)
// player.cpp
// EH frame (/GX)

void __cdecl sub_00462EA0(void* ptr);
void __cdecl sub_0054B660(void* ptr);

class RGE_Player {
public:
    char gap4[0x24];
    void* field_28;
    void* field_2C;
    void* field_30;
    
    virtual ~RGE_Player();
};

RGE_Player::~RGE_Player() {
    if (field_28) {
        sub_00462EA0(field_28);
        sub_0054B660(field_28);
        field_28 = 0;
    }
    if (field_2C) {
        sub_00462EA0(field_2C);
        sub_0054B660(field_2C);
        field_2C = 0;
    }
    if (field_30) {
        sub_00462EA0(field_30);
        sub_0054B660(field_30);
        field_30 = 0;
    }
}
