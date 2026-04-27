// VA: 0052D600 mouse_left_up_action (844B)
// tvw_main.cpp

extern void* rge_base_game;

class TRIBE_Diamond_Map_View {
public:
    char gap4[0xFC];
    int field_100;

    void mouse_left_up_action(int x, int y);
};

void TRIBE_Diamond_Map_View::mouse_left_up_action(int x, int y) {
    if (rge_base_game) {
        int mode = *(int*)((char*)rge_base_game + 0x1B0);
        if (mode == 4 || mode == 6) {
            field_100 = x + y;
        }
    }
}
