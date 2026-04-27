// VA: 0053F810 command_place_object (512B)
// vw_main.cpp

extern int* rge_base_game;

class TRIBE_View_World {
public:
    char gap4[0x100];
    int field_104;
    
    void command_place_object(int x, int y, int a3);
};

void TRIBE_View_World::command_place_object(int x, int y, int a3) {
    if (!rge_base_game) return;
    
    field_104 = x + y;
}
