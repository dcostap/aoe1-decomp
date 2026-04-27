// VA: 004594B0 set_terrain_passablity (303B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    void set_terrain_passablity(short a1, short a2);
};

void RGE_Map::set_terrain_passablity(short a1, short a2) {
    if (a1 == a2) {
        field_8 = (int)a1;
    }
}
