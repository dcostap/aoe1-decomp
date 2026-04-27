// VA: 00496800 handle_game_update (2206B)
// scr_game.cpp
// EH frame (/GX)

extern int g_game_tick;

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void handle_game_update();
};

int g_game_tick = 0;

void TRIBE_Screen_Game::handle_game_update() {
    int x = g_game_tick;
    field_8 = x;
    if (x) {
        field_10 = 0;
    }
}
