// VA: 0052D320 command_place_multi_object (456B)
// tvw_main.cpp

extern int* rge_base_game;
extern int place_mode;

class TRIBE_Diamond_Map_View {
public:
    char gap4[0xFC];
    int field_100;
    
    int command_place_multi_object(int a1, int a2, int a3, int a4, int a5);
};

int TRIBE_Diamond_Map_View::command_place_multi_object(int a1, int a2, int a3, int a4, int a5) {
    if (!place_mode) return 0;
    
    if (rge_base_game) {
        if (field_100) {
            return 1;
        }
    }
    return 0;
}
