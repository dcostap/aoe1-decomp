// VA: 0044E680 InfluenceMap::incrementValue
// infmap.cpp (259 bytes, 4 params, ret 14h)

class InfluenceMap {
public:
    int gap_00[1];
    int size_x;           // +0x04
    int gap_08[1];
    int origin_x;         // +0x0C
    int origin_y;         // +0x10
    int gap_14[1];
    int* map_data;        // +0x18
    int gap_1C[2];
    unsigned char fill_value; // +0x24

    int incrementValue(int x1, int y1, int x2, int y2, int val);
};

int InfluenceMap::incrementValue(int x1, int y1, int x2, int y2, int val) {
    // Convert world coords to map coords
    int mx1 = x1 - origin_x;
    int my1 = y1 - origin_y;
    int mx2 = x2 - origin_x;
    int my2 = y2 - origin_y;
    
    // Clamp X range
    if (mx1 < 0) mx1 = 0;
    else if (mx1 >= size_x) mx1 = size_x - 1;
    
    if (mx2 < 0) mx2 = 0;
    else if (mx2 >= size_x) mx2 = size_x - 1;
    
    // Clamp Y range
    if (my1 < 0) my1 = 0;
    else if (my1 >= size_x) my1 = size_x - 1;
    
    if (my2 < 0) my2 = 0;
    else if (my2 >= size_x) my2 = size_x - 1;
    
    // Check if range is valid
    if (mx1 > mx2) return 1;
    
    // Iterate Y range
    int width = mx2 - mx1 + 1;
    int row_stride = mx1 * 4;
    int height = my2 - my1 + 1;
    
    // Iterate
    int row_idx = row_stride;
    while (--height) {
        int y = my1;
        while (y <= my2) {
            int* row = map_data;
            int addr = row_stride + (int)row;
            unsigned char cell = *(unsigned char*)(addr + y);
            if (cell >= fill_value) {
                // cell already at max
            } else {
                unsigned char current = *(unsigned char*)(addr + y);
                int new_val = current + (val & 0xFF);
                if (new_val >= fill_value) {
                    *(unsigned char*)(addr + y) = fill_value - 1;
                } else {
                    *(unsigned char*)(addr + y) = (unsigned char)new_val;
                }
            }
            y++;
        }
        row_stride += 4;
        height--;
    }
    
    return 1;
}
