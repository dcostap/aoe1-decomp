// VA: 004575C0 do_elevation_brush_stroke (395B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x8DBC];
    int field_8DC0;
    
    void do_elevation_brush_stroke(int x, int y, int z);
};

void RGE_Map::do_elevation_brush_stroke(int x, int y, int z) {
    // Elevation brush stroke
    if (field_8DC0) {
        field_8DC0 = y;
    }
}
