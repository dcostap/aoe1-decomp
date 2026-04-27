// VA: 0049CAF0 command_research (160B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void command_research();
};

void TRIBE_Screen_Game::command_research() {
    char buf[512];
    field_8 = 1;
    field_10 = (int)buf;
}
