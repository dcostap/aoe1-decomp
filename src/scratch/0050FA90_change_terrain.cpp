// VA: 0050FA90 change_terrain (427B)
// tmap.cpp

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D78];
    int field_8D88;
    int field_8D8C;
    
    void change_terrain(short x, short y, int a3);
};

void TRIBE_Map::change_terrain(short x, short y, int a3) {
    int sx = (signed short)x;
    int sy = (signed short)y;
    int* arr = (int*)field_8D8C;
    
    if (arr) {
        field_8D88 = sx + sy + a3;
    }
}
