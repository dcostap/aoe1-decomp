// VA: 004595E0 set_elev (792B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x8DBC];
    int field_8DC0;
    char gap8DC4[0x4];
    int field_8DC8;
    
    void set_elev(int x, int y, int elev);
};

void RGE_Map::set_elev(int x, int y, int elev) {
    field_8DC0 = x;
    field_8DC8 = elev;
}
