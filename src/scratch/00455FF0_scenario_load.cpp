// VA: 00455FF0 scenario_load (334B)
// map.cpp
// EH frame (/GX)

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void scenario_load(int fd);
};

int __cdecl rge_read(int fd, void* buf, int size);

void RGE_Map::scenario_load(int fd) {
    rge_read(fd, &field_8, 4);
}
