// VA: 00497440 key_down_action (3046B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void key_down_action(int a1);
};

void TRIBE_Screen_Game::key_down_action(int a1) {
    char buf[512];
    field_8 = a1;
    field_10 = (int)buf;
}
