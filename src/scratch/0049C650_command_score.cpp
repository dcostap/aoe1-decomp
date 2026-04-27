// VA: 0049C650 command_score (189B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x8];
    int field_14;
    
    void command_score(int a1);
};

void TRIBE_Screen_Game::command_score(int a1) {
    field_8 = a1;
    field_14 = 0;
}
