// VA: 00457F80 load_terrain_types (762B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void load_terrain_types(int fd);
};

int __cdecl rge_read(int fd, void* buf, int size);

void RGE_Map::load_terrain_types(int fd) {
    rge_read(fd, &field_8, 4);
    
    // Load terrain type definitions
}
