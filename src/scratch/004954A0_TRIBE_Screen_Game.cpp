// VA: 004954A0 ~TRIBE_Screen_Game dtor (1271B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    int* vtable;
    char gap4[0x4];
    int field_8;
    
    ~TRIBE_Screen_Game();
};

TRIBE_Screen_Game::~TRIBE_Screen_Game() {
    vtable = (int*)0x55ED48;
    if (field_8) {
        field_8 = 0;
    }
}
