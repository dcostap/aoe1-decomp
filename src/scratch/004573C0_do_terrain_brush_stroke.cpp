// VA: 004573C0 do_terrain_brush_stroke (324B)
// map.cpp

class RGE_Map {
public:
    char gap4[0x8DBC];
    int field_8DC0;
    
    void do_terrain_brush_stroke(int x, int y, int z);
};

void RGE_Map::do_terrain_brush_stroke(int x, int y, int z) {
    // Terrain brush stroke
    if (field_8DC0) {
        field_8DC0 = x;
    }
}
