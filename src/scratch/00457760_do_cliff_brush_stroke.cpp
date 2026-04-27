// VA: 00457760 do_cliff_brush_stroke (316B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x8DBC];
    int field_8DC0;
    
    void do_cliff_brush_stroke(int x);
};

void RGE_Map::do_cliff_brush_stroke(int x) {
    int* obj = *(int**)field_8DC0;
    if (obj) {
        *(unsigned char*)((char*)obj + 0x1D) = 3;
        field_8DC0 = x;
    }
}
