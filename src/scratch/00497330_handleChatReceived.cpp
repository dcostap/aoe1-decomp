// VA: 00497330 handleChatReceived (177B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void handleChatReceived(int a1);
};

void TRIBE_Screen_Game::handleChatReceived(int a1) {
    char buf[256];
    field_8 = a1;
    field_10 = (int)buf;
}
