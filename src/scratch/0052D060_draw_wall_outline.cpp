// VA: 0052D060 draw_wall_outline (391B)
// tvw_main.cpp

class TRIBE_Diamond_Map_View {
public:
    char gap4[0xFC];
    int field_100;
    char gap104[0x23C];
    int field_340;
    
    void draw_wall_outline(int x, int y, int w, int h);
};

void TRIBE_Diamond_Map_View::draw_wall_outline(int x, int y, int w, int h) {
    int points[4];
    points[0] = x;
    points[1] = y;
    points[2] = w;
    points[3] = h;
    
    if (field_100) {
        field_340 = x + y;
    }
}
