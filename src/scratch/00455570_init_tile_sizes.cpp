// VA: 00455570 init_tile_sizes (584B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x8D92];
    short field_8D96;
    short field_8D98;
    
    void init_tile_sizes();
};

void RGE_Map::init_tile_sizes() {
    field_8D96 = 0x40;
    field_8D98 = 0x20;
}
