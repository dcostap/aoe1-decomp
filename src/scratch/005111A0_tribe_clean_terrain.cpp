// VA: 005111A0 tribe_clean_terrain (1562B)
// tmap.cpp

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D78];
    int field_8D88;
    int field_8D8C;
    
    void tribe_clean_terrain(int a1);
};

void TRIBE_Map::tribe_clean_terrain(int a1) {
    short width = *(short*)((char*)this + 8);
    int mask = -1;
    
    if (a1) {
        field_8D88 = (int)width;
    }
}
