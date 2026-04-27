// VA: 0053E340 mouse_left_down_action (1139B)
// vw_main.cpp

extern void* rge_base_game;

class TRIBE_View_World {
public:
    char gap4[0x100];
    
    void mouse_left_down_action(int x, int y);
};

int __cdecl sub_00420180(void* this_);

void TRIBE_View_World::mouse_left_down_action(int x, int y) {
    int result = sub_00420180(rge_base_game);
    if (result) return;
    
    // Handle mouse left down
}
