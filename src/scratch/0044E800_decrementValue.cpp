// VA: 0044E800 InfluenceMap::decrementValue
// infmap.cpp (242 bytes)

class InfluenceMap {
public:
    int gap_00[1];
    int size_x;           // +0x04
    int field_08;
    int origin_x;         // +0x0C
    int origin_y;         // +0x10
    int field_14;
    int* map_data;        // +0x18
    int gap_1C[2];
    unsigned char fill_value; // +0x24

    int decrementValue(int x1, int y1, int x2, int y2);
};

int InfluenceMap::decrementValue(int x1, int y1, int x2, int y2) {
    int mx1 = x1 - origin_x;
    int my1 = y1 - origin_y;
    int mx2 = x2 - origin_x;
    int my2 = y2 - origin_y;
    
    // Clamp
    if (mx1 < 0) mx1 = 0;
    else if (mx1 >= size_x) mx1 = size_x - 1;
    if (mx2 < 0) mx2 = 0;
    else if (mx2 >= size_x) mx2 = size_x - 1;
    if (my1 < 0) my1 = 0;
    else if (my1 >= size_x) my1 = size_x - 1;
    if (my2 < 0) my2 = 0;
    else if (my2 >= size_x) my2 = size_x - 1;
    
    if (mx1 > mx2) return 1;
    if (my1 > my2) return 1;
    
    // 2D loop over region, decrementing cells
    for (int y = my1; y <= my2; y++) {
        for (int x = mx1; x <= mx2; x++) {
            int* row = map_data;
            unsigned char cell = *(unsigned char*)((int)row + x * 4 + y);
            if (cell > 0) {
                *(unsigned char*)((int)row + x * 4 + y) = cell - 1;
            }
        }
    }
    
    return 1;
}
