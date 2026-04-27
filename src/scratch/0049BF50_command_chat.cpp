// VA: 0049BF50 command_chat (192B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void command_chat(int a1);
};

void TRIBE_Screen_Game::command_chat(int a1) {
    field_8 = a1;
    field_10 = 0;
}
