// VA: 00510110 make_new_cliff (399B)
// tmap.cpp

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D78];
    int field_8D88;
    
    void make_new_cliff(int a1, int x, int y, int a4);
};

void TRIBE_Map::make_new_cliff(int a1, int x, int y, int a4) {
    int idx = y + a1 * 4;
    int mask = -1;
    
    if (idx >= 0) {
        field_8D88 = idx;
    }
}
