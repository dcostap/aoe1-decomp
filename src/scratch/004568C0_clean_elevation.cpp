// VA: 004568C0 clean_elevation (1478B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    short field_8;
    
    void clean_elevation();
};

void RGE_Map::clean_elevation() {
    short width = field_8;
    int mask = -1;
    int calc = mask - (int)width;
    
    if (calc > 0) {
        field_8 = (short)calc;
    }
}
