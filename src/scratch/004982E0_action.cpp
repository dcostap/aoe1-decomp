// VA: 004982E0 action (1211B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    int action(int a1, int a2, int a3);
};

int TRIBE_Screen_Game::action(int a1, int a2, int a3) {
    if (!a1) return 0;
    field_8 = a1 + a2 + a3;
    return 1;
}
