// VA: 004564E0 preclean_elevation (985B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    short field_8;
    
    void preclean_elevation();
};

void RGE_Map::preclean_elevation() {
    short width = field_8;
    int mask = -1;
    int calc = mask - (int)width;
    
    if (calc > 0) {
        field_8 = (short)calc;
    }
}
