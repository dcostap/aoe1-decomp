// VA: 00495AE0 handle_size (2659B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void handle_size(int w, int h);
};

void TRIBE_Screen_Game::handle_size(int w, int h) {
    field_8 = w;
    field_10 = h;
}
