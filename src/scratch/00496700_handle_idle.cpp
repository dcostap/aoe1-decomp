// VA: 00496700 handle_idle (246B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void handle_idle();
};

int __cdecl color_log(int a1, int a2, int a3);

void TRIBE_Screen_Game::handle_idle() {
    color_log(5, 0x5F, 0x5F);
    field_8 = 0;
}
