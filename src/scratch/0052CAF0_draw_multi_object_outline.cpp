// VA: 0052CAF0 draw_multi_object_outline (1385B)
// tvw_main.cpp

extern void* rge_base_game;

class TRIBE_Diamond_Map_View {
public:
    char gap4[0xFC];
    int field_100;
    char gap104[0x23C];
    int field_340;
    
    void draw_multi_object_outline();
};

void TRIBE_Diamond_Map_View::draw_multi_object_outline() {
    if (!rge_base_game) return;
    
    short val = *(short*)((char*)rge_base_game + 0x3FC);
    if (val == -1) return;
    
    if (field_100) {
        field_340 = field_100;
    }
}
