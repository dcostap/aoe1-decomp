// VA: 00455910 new_map (783B)
// map.cpp
// EH frame (/GX)

class RGE_Map {
public:
    char gap4[0x8DBC];
    int field_8DC0;
    int field_8DC4;
    
    void new_map(int a1);
};

void RGE_Map::new_map(int a1) {
    field_8DC0 = a1;
    field_8DC4 = 0;
}
