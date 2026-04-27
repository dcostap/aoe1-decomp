// VA: 00458350 load_border_types (679B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void load_border_types(int fd);
};

int __cdecl rge_read(int fd, void* buf, int size);

void RGE_Map::load_border_types(int fd) {
    rge_read(fd, &field_8, 4);
}
