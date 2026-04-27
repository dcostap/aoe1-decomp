// VA: 0049B080 reset_score_display (1206B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void reset_score_display();
};

void TRIBE_Screen_Game::reset_score_display() {
    char buf[724];
    field_8 = (int)buf;
}
