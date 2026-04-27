// VA: 00459A90 set_terrain (649B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void set_terrain(int a1, int a2, int a3);
};

void RGE_Map::set_terrain(int a1, int a2, int a3) {
    unsigned char byteVal = (unsigned char)a1;
    field_8 = byteVal;
    field_10 = a2;
}
