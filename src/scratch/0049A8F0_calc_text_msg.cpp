// VA: 0049A8F0 calc_text_msg (542B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void calc_text_msg();
};

void TRIBE_Screen_Game::calc_text_msg() {
    char buf[3072];
    char str[512];
    
    field_8 = (int)str;
}
