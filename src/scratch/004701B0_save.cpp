// VA: 004701B0 save (454B)
// player.cpp

class RGE_Player {
public:
    char gap4[0x38];
    int field_3C;       // +3C
    char gap40[0x44];
    int field_84;       // +84
    char gap88[0x78];
    int field_100;      // +100
    
    void save(int fd);
};

int __cdecl color_log(int fd, int a, int b, const void* data, int size);
int __cdecl rge_write(int fd, const void* data, int size);

void RGE_Player::save(int fd) {
    color_log(fd, 0x32, 0x32, 0, 3);
    
    rge_write(fd, &field_3C, 1);  // placeholder, not field_48
    
    short count = *(short*)((char*)field_3C + 0x3C);
    rge_write(fd, &field_84, count);
    
    rge_write(fd, &field_100, 4);
}
