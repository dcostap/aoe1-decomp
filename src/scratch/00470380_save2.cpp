// VA: 00470380 save2 (261B)
// player.cpp

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap4[0x1E];
    short field_22;
    char gap24[0x2];
    int* field_24;
    char gap28[0x60];
    
    void save(int fd, int a2);
};

int __cdecl color_log(int fd, int a, int b, const void* data, int size);
int __cdecl rge_write(int fd, const void* data, int size);

void RGE_Player::save(int fd, int a2) {
    color_log(fd, 0x4C, 0x4C, 0, 4);
    
    rge_write(fd, &field_22, 2);
    
    for (int i = 0; i < (signed short)field_22; i++) {
        int val = field_24[i];
        if (!val) val = 1;
        rge_write(fd, &val, 4);
    }
}
