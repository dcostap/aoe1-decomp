// VA: 00496550 handle_paint (425B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x1C];
    int field_20;
    char gap24[0x4];
    int field_28;
    
    void handle_paint();
};

void TRIBE_Screen_Game::handle_paint() {
    if (!field_20) return;
    field_20 = 0;
    field_28 = 1;
}
