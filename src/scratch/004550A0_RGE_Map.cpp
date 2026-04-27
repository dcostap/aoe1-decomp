// VA: 004550A0 RGE_Map ctor (902B)
// map.cpp

class RGE_Map {
public:
    int* vtable;
    char gap4[0x8DBC];
    int field_8DC0;
    int field_8DC4;
    
    RGE_Map();
};

RGE_Map::RGE_Map() {
    vtable = (int*)0x570678;
    field_8DC0 = 0;
    field_8DC4 = 0;
}
