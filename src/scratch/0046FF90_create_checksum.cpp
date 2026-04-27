// VA: 0046FF90 create_checksum (277B)
// player.cpp

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap4[0x18];
    int field_1C;
    char field_20;
    char gap21[0xB];
    int field_2C;
    int field_30;
    short field_4A;
    short field_4C;
    int* field_50;      // +50
    
    void create_checksum();
};

int __cdecl floatToInt(float f);

void RGE_Player::create_checksum() {
    field_20 = 1;
    field_1C = 0;
    
    int total = 0;
    total += *(short*)(*(int*)field_2C + 8);
    total += *(short*)(*(int*)field_30 + 8);
    
    int count = field_4C;
    int checksum = 0;
    for (int i = 0; i < count; i++) {
        checksum += floatToInt(*(float*)((char*)field_50 + i * 4));
    }
}
