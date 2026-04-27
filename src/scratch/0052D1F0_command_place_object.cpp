// VA: 0052D1F0 command_place_object (304B)
// tvw_main.cpp

extern int* rge_base_game;
extern int place_mode;

class TRIBE_Diamond_Map_View {
public:
    char gap4[0x100];
    
    int command_place_object(int x, int y, int objType);
};

void __cdecl sub_0052CE90(int x, int y);

int TRIBE_Diamond_Map_View::command_place_object(int x, int y, int objType) {
    if (!place_mode) return 0;
    
    if (rge_base_game) {
        int mode = *(int*)((char*)rge_base_game + 0x1B0);
        if (mode == 4 || mode == 6) {
            sub_0052CE90(x, y);
        }
    }
    
    return 1;
}
