// VA: 0049B830 handle_anim_pal (212B)
// scr_game.cpp

class TRIBE_Screen_Game {
public:
    char gap4[0x690];
    int field_694;
    char gap698[0x4];
    int field_69C;
    
    void handle_anim_pal();
};

void TRIBE_Screen_Game::handle_anim_pal() {
    field_694 = 1;
    field_69C = 0;
}
