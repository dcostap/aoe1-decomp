// VA: 0052DE40 mouse_left_dbl_click_action (278B)
// tvw_main.cpp

class TRIBE_Diamond_Map_View {
public:
    char gap4[0xFC];
    int field_100;

    void mouse_left_dbl_click_action(int x, int y);
};

int __cdecl sub_0052CE90(int x, int y);

void TRIBE_Diamond_Map_View::mouse_left_dbl_click_action(int x, int y) {
    int result = sub_0052CE90(x, y);
    if (result) {
        field_100 = x;
    }
}
