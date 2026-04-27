// VA: 00458C90 place_terrain_object (832B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void place_terrain_object(int a1, int a2, int a3);
};

void RGE_Map::place_terrain_object(int a1, int a2, int a3) {
    field_8 = a1 + a2 + a3;
}
