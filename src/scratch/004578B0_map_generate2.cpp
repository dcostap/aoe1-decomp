// VA: 004578B0 map_generate2 (266B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x8DBC];
    int field_8DC0;
    
    void map_generate2();
};

extern void* rge_base_game;

void RGE_Map::map_generate2() {
    int* obj = *(int**)field_8DC0;
    if (obj) {
        *(unsigned char*)((char*)obj + 0x1D) = 3;
    }
    
    if (rge_base_game) {
        field_8DC0 = (int)rge_base_game;
    }
}
