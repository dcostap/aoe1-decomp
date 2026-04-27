// VA: 00459060 tile_map_coords (754B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x8D92];
    short field_8D96;
    
    void tile_map_coords(short x, short y);
};

void RGE_Map::tile_map_coords(short x, short y) {
    int sx = (signed short)x;
    int sy = (signed short)y;
    int tileW = (signed short)field_8D96;
    
    // Convert tile coords
    if (tileW > 0) {
        field_8D96 = (short)(sx + sy);
    }
}
