// VA: 00457C50 save_map (403B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void save_map(int fd);
};

int __cdecl rge_write(int fd, const void* buf, int size);

void RGE_Map::save_map(int fd) {
    rge_write(fd, &field_8, 4);
}
