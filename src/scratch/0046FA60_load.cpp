// VA: 0046FA60 load (475B)
// player.cpp
// EH frame (/GX)

class RGE_Player {
public:
    char gap4[0x1E];
    short field_22;
    char gap24[0x2];
    int* field_24;      // +24
    char gap28[0xBC];
    int field_E4;
    
    void load(int fd);
};

void __cdecl rge_read(int fd, void* buf, int size);
void* __cdecl malloc4(unsigned size);

void RGE_Player::load(int fd) {
    rge_read(fd, &field_22, 2);
    
    if (field_22 > 0) {
        field_24 = (int*)malloc4(4 * field_22);
        for (int i = 0; i < field_22; i++) {
            rge_read(fd, &field_24[i], 4);
        }
    }
}
