// VA: 00456E90 clean_terrain (1127B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void clean_terrain(int a1);
};

void RGE_Map::clean_terrain(int a1) {
    field_8 = a1;
    field_10 = 0;
}
