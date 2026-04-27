// VA: 00510430 add_cliff_edge (1317B)
// tmap.cpp

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D78];
    int field_8D88;
    int field_8D8C;
    
    void add_cliff_edge(int direction, int x, int y);
};

void TRIBE_Map::add_cliff_edge(int direction, int x, int y) {
    int* arr = (int*)field_8D8C;
    if (arr) {
        field_8D88 = direction + x + y;
    }
}
