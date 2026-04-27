// VA: 0049BDB0 command_building (225B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void command_building(int a1);
};

void TRIBE_Screen_Game::command_building(int a1) {
    char buf[512];
    field_8 = a1;
    field_10 = (int)buf;
}
