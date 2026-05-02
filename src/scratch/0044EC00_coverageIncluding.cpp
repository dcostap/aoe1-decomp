// VA: 0044EC00 InfluenceMap::coverageIncluding
// infmap.cpp (274 bytes)

class InfluenceMap {
public:
    int field_00;         // +0x00
    int size_x;           // +0x04
    int field_08;         // +0x08
    int origin_x;         // +0x0C
    int origin_y;         // +0x10
    int field_14;         // +0x14
    int* map_data;        // +0x18
    int field_1C;         // +0x1C
    int field_20;         // +0x20
    unsigned char fill_value; // +0x24

    int coverageIncluding(int x, int y, int* count);
};

int InfluenceMap::coverageIncluding(int x, int y, int* count) {
    int stack_var = field_1C;
    // This function uses a local struct of 4 ints (16 bytes)
    // and does complex flood-fill like coverage counting
    
    return 0;
}
