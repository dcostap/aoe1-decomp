// VA: 0049ADA0 reset_clocks (594B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x5B0];
    int field_5B4;
    
    void reset_clocks();
};

void TRIBE_Screen_Game::reset_clocks() {
    int* ptr = (int*)field_5B4;
    if (ptr) {
        field_5B4 = 0;
    }
}
