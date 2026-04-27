// VA: 00493D60 TRIBE_Screen_Game ctor (5859B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    int* vtable;
    char gap4[0x8DBC];
    int field_8DC0;
    int field_8DC4;
    
    TRIBE_Screen_Game();
};

TRIBE_Screen_Game::TRIBE_Screen_Game() {
    vtable = (int*)0x55ED29;
    field_8DC0 = 0;
    field_8DC4 = 0;
}
