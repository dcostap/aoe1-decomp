// VA: 00498A50 player_changed (2169B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void player_changed();
};

void TRIBE_Screen_Game::player_changed() {
    char buf[512];
    field_8 = 1;
    field_10 = (int)buf;
}
