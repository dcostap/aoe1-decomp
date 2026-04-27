// VA: 0049B560 draw (707B)
// scr_game.cpp
// EH frame (/GX)

extern unsigned char g_draw_enabled;

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    
    void draw();
};

unsigned char g_draw_enabled = 0;

void TRIBE_Screen_Game::draw() {
    if (!g_draw_enabled) return;
    field_8 = 1;
}
