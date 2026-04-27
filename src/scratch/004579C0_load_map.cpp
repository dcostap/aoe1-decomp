// VA: 004579C0 load_map (643B)
// map.cpp
// EH frame (/GX)

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void load_map(int fd);
};

int __cdecl rge_read(int fd, void* buf, int size);

void RGE_Map::load_map(int fd) {
    rge_read(fd, &field_8, 4);
}
