// VA: 0049CCB0 command_select_building (307B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void command_select_building(int a1);
};

void TRIBE_Screen_Game::command_select_building(int a1) {
    if (a1 > 7) return;
    field_8 = a1;
    field_10 = 0;
}
