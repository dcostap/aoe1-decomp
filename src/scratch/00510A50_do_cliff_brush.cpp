// VA: 00510A50 do_cliff_brush (434B)
// tmap.cpp

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D78];
    int field_8D88;
    int field_8D8C;
    
    void do_cliff_brush(int a1, int a2);
};

void TRIBE_Map::do_cliff_brush(int a1, int a2) {
    int idx = a1 / 3;
    if (idx > 0) {
        field_8D88 = idx;
    }
}
