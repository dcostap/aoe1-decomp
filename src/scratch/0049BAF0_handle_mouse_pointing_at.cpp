// VA: 0049BAF0 handle_mouse_pointing_at (358B)
// scr_game.cpp

extern void* g_game_info;

class TRIBE_Screen_Game {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x4];
    int field_10;
    
    void handle_mouse_pointing_at();
};

void* g_game_info = (void*)0;

void TRIBE_Screen_Game::handle_mouse_pointing_at() {
    void* info = *(void**)((char*)g_game_info + 0x10);
    if (info) {
        field_8 = (int)info;
        field_10 = 0;
    }
}
