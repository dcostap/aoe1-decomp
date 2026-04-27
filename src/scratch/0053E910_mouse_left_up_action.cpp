// VA: 0053E910 mouse_left_up_action (2252B)
// vw_main.cpp

extern void* rge_base_game;

class TRIBE_View_World {
public:
    char gap4[0x100];
    int field_104;
    
    void mouse_left_up_action(int x, int y);
};

void TRIBE_View_World::mouse_left_up_action(int x, int y) {
    if (rge_base_game) {
        int mode = *(int*)((char*)rge_base_game + 0x1B0);
        if (mode == 4 || mode == 6) {
            field_104 = x + y;
        }
    }
}
