// VA: 00499520 show_comm (175B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void show_comm(int a1);
};

void TRIBE_Screen_Game::show_comm(int a1) {
    field_8 = a1;
    field_10 = 0;
}
