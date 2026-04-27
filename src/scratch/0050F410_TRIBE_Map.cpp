// VA: 0050F410 TRIBE_Map ctor (805B)
// tmap.cpp
// EH frame (/GX)

class TRIBE_Map {
public:
    char gap4[0x4];
    int field_8;
    int field_C;
    char gap10[0x8D7C];
    int field_8D8C;
    
    TRIBE_Map(int a1, int a2, int a3);
};

TRIBE_Map::TRIBE_Map(int a1, int a2, int a3) {
    field_8 = 0;
    field_C = 0;
    field_8D8C = 0;
}
