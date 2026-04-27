// VA: 00458820 create_terrain_object (794B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void create_terrain_object(int a1, int a2);
};

void RGE_Map::create_terrain_object(int a1, int a2) {
    field_8 = a1;
    field_10 = a2;
}
