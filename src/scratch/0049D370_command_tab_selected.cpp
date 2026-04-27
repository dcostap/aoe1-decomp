// VA: 0049D370 command_tab_selected (199B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void command_tab_selected(int a1);
};

void TRIBE_Screen_Game::command_tab_selected(int a1) {
    field_8 = a1;
    field_10 = 0;
}
