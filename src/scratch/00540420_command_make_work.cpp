// VA: 00540420 command_make_work (412B)
// vw_main.cpp

extern int* rge_base_game;

class TRIBE_View_World {
public:
    char gap4[0x100];
    int field_104;
    
    void command_make_work(int a1, int a2);
};

void TRIBE_View_World::command_make_work(int a1, int a2) {
    if (!rge_base_game) return;
    
    field_104 = a1 + a2;
}
