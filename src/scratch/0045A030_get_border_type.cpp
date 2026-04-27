// VA: 0045A030 get_border_type (1115B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x4];
    int field_8;
    
    int get_border_type(short x, short y);
};

int RGE_Map::get_border_type(short x, short y) {
    if (x == 0) return 0;
    if (y == 0) return 0;
    
    return field_8;
}
