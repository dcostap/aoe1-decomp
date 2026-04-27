// VA: 0052D4F0 place_line_of_walls (257B)
// tvw_main.cpp

class TRIBE_Diamond_Map_View {
public:
    char gap4[0xFC];
    int field_100;
    
    void place_line_of_walls(int x1, int y1, int x2, int y2);
};

void __cdecl sub_0052CFD0(int x, int y);

void TRIBE_Diamond_Map_View::place_line_of_walls(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        field_100 = 1;
    } else {
        field_100 = 0;
    }
    
    sub_0052CFD0(x1, y1);
}
