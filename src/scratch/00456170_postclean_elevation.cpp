// VA: 00456170 postclean_elevation (880B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    short field_8;
    
    void postclean_elevation();
};

void RGE_Map::postclean_elevation() {
    short width = field_8;
    int mask = -1;
    int calc = mask - (int)width;
    
    // Post-clean elevation data
    if (calc > 0) {
        field_8 = (short)calc;
    }
}
