// VA: 005102A0 remove_cliff_edge (339B)
// tmap.cpp

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D78];
    int field_8D88;
    
    void remove_cliff_edge(int direction, int x, int y);
};

void TRIBE_Map::remove_cliff_edge(int direction, int x, int y) {
    if (direction > 3) return;
    
    // Remove cliff edge based on direction
    switch (direction) {
        case 0:
            field_8D88 = 0;
            break;
        case 1:
            field_8D88 = 1;
            break;
        case 2:
            field_8D88 = 2;
            break;
        case 3:
            field_8D88 = 3;
            break;
    }
}
