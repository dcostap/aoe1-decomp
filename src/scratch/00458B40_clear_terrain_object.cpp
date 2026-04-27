// VA: 00458B40 clear_terrain_object (321B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x8];
    int field_14;
    
    void clear_terrain_object(int a1, int a2);
};

void RGE_Map::clear_terrain_object(int a1, int a2) {
    field_8 = a1;
    field_14 = a2;
}
