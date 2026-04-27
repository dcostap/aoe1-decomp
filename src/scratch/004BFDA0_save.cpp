// VA: 004BFDA0 save (561B)
// sprite.cpp

class RGE_Sprite {
public:
    char gap4[0x38];
    int field_3C;
    char gap40[0x8];
    char field_48[0x20];
    char gap68[0x18];
    int field_80;
    
    void save(int fd);
};

int __cdecl rge_write(int fd, const void* buf, int size);

void RGE_Sprite::save(int fd) {
    int val = -1;
    if (field_3C) {
        val = *(short*)((char*)field_3C + 0x0C);
    }
    
    rge_write(fd, &val, 4);
    rge_write(fd, field_48, 0x15);
}
