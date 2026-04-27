// VA: 004987A0 do_button_action (419B)
// scr_game.cpp

extern void* g_game_info;

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    int do_button_action(int a1);
};

void* g_game_info = (void*)0;

int TRIBE_Screen_Game::do_button_action(int a1) {
    if (!g_game_info) return 0;
    
    a1--;
    if ((unsigned)a1 > 0x20) return 0;
    
    field_8 = a1;
    return 1;
}
