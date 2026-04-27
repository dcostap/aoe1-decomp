// VA: 00510CB0 clean_borders (840B)
// tmap.cpp

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D78];
    int field_8D88;
    
    void clean_borders(int a1);
};

void TRIBE_Map::clean_borders(int a1) {
    if (!a1) return;
    
    int width = field_8;
    int height = field_C;
    int maxX = width - 1;
    
    if (maxX > 0) {
        field_8D88 = maxX;
    }
}
