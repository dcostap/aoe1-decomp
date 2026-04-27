// VA: 0050F8D0 check_tile_for_forest_change (434B)
// tmap.cpp

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D78];
    int field_8D88;
    int field_8D8C;
    
    void check_tile_for_forest_change(short x, short y);
};

void TRIBE_Map::check_tile_for_forest_change(short x, short y) {
    int sx = (signed short)x;
    int sy = (signed short)y;
    int* arr = (int*)field_8D8C;
    
    if (arr) {
        field_8D88 = sx + sy;
    }
}
