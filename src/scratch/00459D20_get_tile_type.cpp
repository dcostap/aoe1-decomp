// VA: 00459D20 get_tile_type (774B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    int get_tile_type(short x, short y);
};

int RGE_Map::get_tile_type(short x, short y) {
    if (x == 0) return 0;
    if (y == 0) return 0;
    
    return field_8;
}
