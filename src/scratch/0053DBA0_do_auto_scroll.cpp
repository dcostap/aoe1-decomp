// VA: 0053DBA0 do_auto_scroll (773B)
// vw_main.cpp

extern void* rge_base_game;

class TRIBE_View_World {
public:
    char gap4[0x100];
    int field_104;
    
    void do_auto_scroll(int x, int y);
};

void TRIBE_View_World::do_auto_scroll(int x, int y) {
    if (rge_base_game) {
        int mode = *(int*)((char*)rge_base_game + 0x1B0);
        if (mode == 4 || mode == 6) {
            field_104 = x;
        }
    }
}
