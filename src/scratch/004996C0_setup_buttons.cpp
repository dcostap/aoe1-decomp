// VA: 004996C0 setup_buttons (4574B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void setup_buttons();
};

void TRIBE_Screen_Game::setup_buttons() {
    char buf[1076];
    field_8 = (int)buf;
}
